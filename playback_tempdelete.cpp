//------------------------------------------------------------------------------
//
//	TMB2005 Event Playback
//
//		Reads a DDU or raw-hits dump file
//		 Unpacks header frames
//		 Checks buffer status signals
//		 Check LCTs match CLCTs and ALCTs
//		 Extracts TMB trigger settings
//		 Extracts raw CFEB triads
//
//		Injects triads into reference TMB hardware
//		 Compares TMB trigger result CLCTs with raw-hit header CLCTs 
//
//		Expected DDU dump format
//		!DDU Event number is 7400 (hex 1ce8): (a comment line)
//		 db0c d8aa dce8 d0aa
//		 de0f dc9a d9cc d99c
//
//		Expected DMB dump format
//		 !DMB Event number is 7400 (hex 1ce8): (a comment line)
//		 Adr=    0 Data= 0DB0C
//		 Adr=  239 Data= 0D99C
//
//		Multiple events are separate by an empty line followed by a new comment
//
//	10/02/08 Initial
//	10/10/08 Mod comment line
//	11/03/08 Increase commen line length
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
	#include <stdio.h>
	#include <time.h>
	#include <string.h>

//------------------------------------------------------------------------------
// Common
//------------------------------------------------------------------------------
	extern FILE		 *raw_file;
	extern FILE		 *log_file;

	const int		mxframe=8192;		// Max raw hits frame number, scope adds 512*160/16=5120 frames
	const int		mxtbins=32-1;		// Highest time bin
	const int		mxly=6-1;			// # CSC Layers
	const int		mxds=8-1;			// # DiStrips per CFEB
	const int		mxdsabs=40-1;		// # DiStrips per CSC

//------------------------------------------------------------------------------
// Prototypes
//------------------------------------------------------------------------------
	#define			logical(L)	((L)?'T':'F')
	void			pause		(char *s);

	void			decode_raw_hits (
	int				 vf_data[mxframe],
	int				 dmb_wdcnt,
	int				 itriad[mxtbins][mxdsabs][mxly],
	int				 clct0_vme,
	int				 clct1_vme,
	int				 clctc_vme,
	int				 mu0fr0_vme,
	int				 mu0fr1_vme,
	int				 mu1fr0_vme,
	int				 mu1fr1_vme,
	int				 first_event,
	int				 scp_tbins,
	unsigned long	 base_adr,
	unsigned long	 scp_ctrl_adr,
	unsigned long	 scp_rdata_adr
	);

//------------------------------------------------------------------------------
	int main()
//------------------------------------------------------------------------------
{
// Decode_raw_hits argument list
	int				vf_data[mxframe];
	int				dmb_wdcnt;
	int				itriad[mxtbins][mxdsabs][mxly];
	int				clct0_vme;
	int				clct1_vme;
	int				clctc_vme;
	int				mu0fr0_vme;
	int				mu0fr1_vme;
	int				mu1fr0_vme;
	int				mu1fr1_vme;
	int				first_event=true;
	int				scp_tbins;
	unsigned long	base_adr;
	unsigned long	scp_ctrl_adr;
	unsigned long	scp_rdata_adr;

// Local
	const char		LF=10;				//Line feed 
	const int		mxcomment=256;
	char			comment[mxcomment];
	int				diff;
	int				i;
	int				iadr;
	int				idata;
/*
c Parameters
	parameter	mxframe=4096		!Max raw hits frame number
	parameter	mxtbins=32-1		!Highest time bin
	parameter	mxly=6-1			!# CSC Layers
	parameter	mxds=8-1			!# DiStrips per CFEB
	parameter	mxcfeb=5-1			!# CFEBs
	parameter	mxdsabs=40-1		!# DiStrips per CSC
	parameter	mxkey=160-1			!# Key wire groups on CSC

c Argument list
	implicit none

	integer*4	vf_data(0:mxframe)
	integer*4	dmb_wdcnt
	integer*4	itriad(0:mxtbins,0:mxdsabs,0:mxly)
	integer*4	clct0_vme
	integer*4	clct1_vme
	integer*4	clctc_vme
	integer*4	mu0fr0_vme
	integer*4	mu0fr1_vme
	integer*4	mu1fr0_vme
	integer*4	mu1fr1_vme
	logical		first_event/.true./

c Files
	character	ddu_file*64
	character	ddu_file_default*11

c Local
	character	comment*80
	integer		n
	integer		i
	integer		iadr
	integer		last_event/.false./
*/

//------------------------------------------------------------------------------
// Inquire files
//------------------------------------------------------------------------------
	char line[81];
//	char raw_file_name[] = "rawhits_dump.txt";
	char raw_file_name[] = "badevents.txt";
	char log_file_name[] = "playback_log.txt";
	int  playback_tmb    = false;

	printf("TMB2005 Raw Hits Playback\n\n");

	printf("DMB raw hits dump or DDU intput file? <cr>=%s: ",raw_file_name);
	gets(line);
	if(line[0]!=0) {sscanf(line,"%s",&raw_file_name);}

	printf("Playback output log file?             <cr>=%s: ",log_file_name);
	gets(line);
	if(line[0]!=0) {sscanf(line,"%s",&log_file_name);}

	printf("Playback in reference TMB?  (y/n)     <cr>=%c: ",'N');
	gets(line);
	if((line[0]=='Y')|(line[0]=='y')) playback_tmb=true;

	printf("\n");
	printf("raw_file_name =%s\n",raw_file_name);
	printf("log_file_name =%s\n",log_file_name);
	printf("playback_tmb  =%c\n",logical(playback_tmb));
	pause ("hit <cr> to start");

//------------------------------------------------------------------------------
// Open files
//------------------------------------------------------------------------------
	raw_file = fopen (raw_file_name,"r");

	if(raw_file != NULL)  printf("Opened %s\n",raw_file_name);
	if(raw_file == NULL) {printf("Failed to open %s\n",raw_file_name); pause("Oh Noes!"); goto exit;}

	log_file = fopen (log_file_name,"w");

	if(log_file != NULL)  printf("Opened %s\n",log_file_name);
	if(log_file == NULL) {printf("Failed to open %s\n",log_file_name); pause("Oh Noes!"); goto exit;}

// Put date into verify file for kix
	char timestr[9];
	char datestr[9];

    _strtime(timestr);
    _strdate(datestr);

    fprintf(stdout,  "Playback Started: %s %s\n",datestr,timestr);
    fprintf(log_file,"Playback Started: %s %s\n",datestr,timestr);

//------------------------------------------------------------------------------
// Read comment line, col(1-4)= !DDU for ddu format, !RAW for raw hits format
//------------------------------------------------------------------------------
read_comment:

	fgets(comment,mxcomment,raw_file);

	if(feof(raw_file)) {
	pause ("End of raw hits file. Exiting.");
	goto exit;
	}

	fprintf(stdout,  "\n%s",comment);
	fprintf(log_file,"\n%s",comment);


	if(comment[0] != '!') {
	pause ("Comment line missing. Oh noes! Exiting.");
	goto exit;
	}

	diff=strnicmp(comment,"!DDU",4);
	if(diff == NULL) {
	printf("%s\n","File is !DDU format"); 
	goto read_ddu;
	}

	diff=strnicmp(comment,"!DMB",4);
	if(diff == NULL) {
	printf("%s\n","File is !DMB format"); 
	goto read_dmb;
	}

	pause ("File type !DDU or !DMB not found on line 1, wtf?");
	goto exit;

//------------------------------------------------------------------------------
// Read DMB raw-hits format dump, 1 address/word per line: Adr=    0 Data= 0DB0C
//------------------------------------------------------------------------------
read_dmb:
	dmb_wdcnt=0;
	iadr=99;

	for (i=0; i<=mxframe; ++i) {
	if(feof(raw_file)) goto decode;
	fgets(line,81,raw_file);							// fprintf(log_file,"debug: %i\t%s",i,line);
	if(line[0]==LF) goto decode;						// hit new event
	sscanf(line,"%*4s%5i%*7s%5x%*[^\n]",&iadr,&idata);	// get adr and data, skip comments
	fprintf(log_file,"read: %5i %6.5X\n",iadr,idata);

	if(iadr != i) {
	fprintf(log_file,"iadr !=i fault: iadr=%i i=%i\n",iadr,i);
	fprintf(stderr,  "iadr !=i fault: iadr=%i i=%i\n",iadr,i);
	pause ("iadr !=i fault. Exiting");
	goto exit;
	}

	vf_data[i]=idata;
	dmb_wdcnt=dmb_wdcnt+1;
	}

	pause ("DMB input ovf, increase mxframe. Oh Noes! Exiting.");
	goto exit;

//------------------------------------------------------------------------------
// Read DDU-format data, 4 words per line: db0c d8aa dce8 d0aa
//------------------------------------------------------------------------------
read_ddu:
	dmb_wdcnt=0;

	for (i=0; i<=mxframe/4; i=i+4) {
	if(feof(raw_file)) goto decode;
	fgets(line,81,raw_file);							// fprintf(log_file,"debug: %i\t%s",i,line);
	if(line[0]==LF) goto decode;						// hit new event COME BACK TO THIS LATER
	sscanf(line,"%4x%4x%4x%4x%*[^\n]",&vf_data[i],&vf_data[i+1],&vf_data[i+2],&vf_data[i+3]);
	fprintf(log_file,"read: %5i %6.5X %6.5X %6.5X %6.5X\n",i,vf_data[i],vf_data[i+1],vf_data[i+2],vf_data[i+3]);
	dmb_wdcnt=dmb_wdcnt+4;
	}

	pause ("DDU input ovf, increase mxframe. Oh Noes! Exiting.");
	goto exit;

//------------------------------------------------------------------------------
// Decode raw hits dump
//------------------------------------------------------------------------------
decode:
	printf("TMB frames read=%i\n",dmb_wdcnt);

// Signals not used in playback
	mu1fr1_vme=0;
	mu1fr0_vme=0;
	mu0fr1_vme=0;
	mu0fr0_vme=0;
	clctc_vme =0;
	clct1_vme =0;
	clct0_vme =0;

	scp_rdata_adr=0;
	scp_ctrl_adr =0;
	base_adr     =0;
	scp_tbins    =0;

// Call decode
	decode_raw_hits(vf_data,dmb_wdcnt,
	 itriad,clct0_vme,clct1_vme,clctc_vme,
	 mu0fr0_vme,mu0fr1_vme,mu1fr0_vme,mu1fr1_vme,first_event,
	 scp_tbins,base_adr,scp_ctrl_adr,scp_rdata_adr);

	goto read_comment;
/*
//------------------------------------------------------------------------------
//	tmb_readout_decode
//
//	Reads DDU text dump of TMB data, unpacks header and triads
//
//	DDU input file must be edited to conform to the following format
//
// DDU dump format
//	!Event number is 7400 (hex 1ce8):
//	db0c d8aa dce8 d0aa
//	de0f dc9a d9cc d99c
//
//	!Event number is 7401 (hex 1ce8):
//	db0c d8aa dce8 d0aa
//	de0f dc9a d9cc d99c
//
//	08/26/08 Port from fort
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
	#include <stdio.h>
	#include <time.h>

//------------------------------------------------------------------------------
// Prototypes
//------------------------------------------------------------------------------
	void inquire(char *prompt, char *filename);
	void pause  (char *s);

//------------------------------------------------------------------------------
	int main()
//------------------------------------------------------------------------------
{
	const int	mxframe=4096;		//Max raw hits frame number
	const int	mxtbins=32-1;		//Highest time bin
	const int	mxly=6-1;			//# CSC Layers
	const int	mxds=8-1;			//# DiStrips per CFEB
	const int	mxcfeb=5-1;			//# CFEBs
	const int	mxdsabs=40-1;		//# DiStrips per CSC
	const int	mxkey=160-1;		//# Key wire groups on CSC

// Argument list
	int			vf_data[mxframe];
	int			dmb_wdcnt;
	int			itriad[mxtbins][mxdsabs][mxly];
	int			clct0_vme;
	int			clct1_vme;
	int			clctc_vme;
	int			mu0fr0_vme;
	int			mu0fr1_vme;
	int			mu1fr0_vme;
	int			mu1fr1_vme;
	int			first_event=true;

// Local
	char		comment[80];
	int			n;
	int			i;
	int			last_event=false;

// Inquire input file
	char ddu_file_default[] = "ddu7400.txt";
	char out_file_default[] = "ddu7400_unpacked.txt";
	char ddu_file[80];
	char out_file[80];

//	write(6,'(5x,a,a,a,$)')'ddu file:  <cr=',ddu_file_default,'> '
	printf ( "ddu file: <cr=%s>",ddu_file_default);
/*
	read(5,'(q,a)') n,ddu_file
	if(n.le.0) ddu_file=ddu_file_default

	close (unit=1)
	open  (unit=1,file=ddu_file,status='old')

// Open files
---
	FILE *infile;
	FILE *outfile;

	infile  = fopen (ddu_file,"r");
	outfile = fopen (out_file,"w");

	if(infile   == NULL) pause ("Input file failed to open, oh noes!");
	if(infile   != NULL) printf("Opened %s\n",old_fmt_file);
	if(outfile  != NULL) printf("Opened %s\n",new_fmt_file);
	if(verifile != NULL) printf("Opened %s\n",ver_fmt_file);

// Put date into verify file for kix
    _strtime(timestr);
    _strdate(datestr);

    printf (         "Started: %s %s\n",datestr,timestr);
    fprintf(verifile,"Started: %s %s\n",datestr,timestr);
    fprintf(verifile,"Input  file: %s\n",old_fmt_file);
    fprintf(verifile,"Output file: %s\n",new_fmt_file);
---
// Skip comment line
10	continue
	read(1,'(a)') comment
	write(6,'(5x,a)') comment(1:32)
	write(2,'(   a)') comment

	if(comment(1:1).ne.'//') then
	write(6,'(5x,a)') 'comment line missing'
	go to 1000
	endif

// Read DDU data, 4 words per line
	dmb_wdcnt=0

	do i=0,mxframe/4,4
	read(1,'(q,z4,1x,z4,1x,z4,1x,z4)',end=50) n,
	1 vf_data(i),vf_data(i+1),vf_data(i+2),vf_data(i+3)
	if(n.le.0) go to 100
	dmb_wdcnt=dmb_wdcnt+4
	end do
	stop 'input ovf'
50	last_event=.true.

// Done reading 1 event
100	continue
	write(6,'(5x,a,i5)') 'TMB frames read=',dmb_wdcnt

// Decode raw hits dump
	call decode_raw_hits(vf_data,dmb_wdcnt,itriad,
	1 clct0_vme,clct1_vme,clctc_vme,
	1 mu0fr0_vme,mu0fr1_vme,mu1fr0_vme,mu1fr1_vme,
	1 first_event)
	if(.not.last_event)go to 10

1000	continue
	close (unit=1)
	close (unit=2)
//------------------------------------------------------------------------------
// Zip zop your face is ripped to shreds
//------------------------------------------------------------------------------
*/
exit:
	if (raw_file!=NULL) fclose (raw_file);
	if (log_file!=NULL) fclose (log_file);

    return 0;
}
//------------------------------------------------------------------------------
// The bitter end
//------------------------------------------------------------------------------
