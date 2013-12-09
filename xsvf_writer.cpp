//-----------------------------------------------------------------------------
//	Xsvf_writer: Subsecton L5000 extracted from full xsvfwriter.cpp
//
// 04/28/2006	Edits Impact xsvf templates
// 04/28/2006	Inserts usercode
// 04/28/2006	Started xsvf player
// 05/01/2006	Add user prom readback
// 05/08/2006	Add crate scan
// 05/11/2006	Add push pop
// 05/12/2006	Add multi-module programming
// 05/15/2006	Add usercode readout to programmer
// 01/20/2010	Port to c++
// 01/23/2010	Mod for VS8
// 01/25/2010	Add block transfers
// 01/26/2010	Bugfix
// 07/11/2011	Mod for tmb auto test
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
	#define _CRT_SECURE_NO_WARNINGS 1
	#include <stdio.h>
	#include <time.h>
	#include <iostream>
	using namespace std;

//------------------------------------------------------------------------------
// Common
//------------------------------------------------------------------------------
//	common/status_common/
	extern FILE*	log_file;
	const int		mx_bitstream=32768;			// Max # bits in a jtag cycle
	FILE			*debug_file;
	bool			wrlog;
	bool			erased;
	int				idevice;
	long			npush;
	unsigned long	npush_total;
	int				npush_peak;
	int				npop_total;
	int				scan_ntmbs;
	int				scan_islot[21+1];
	unsigned long	scan_boot_adr[21+1];
	unsigned short	wr_buf[mx_bitstream];

//------------------------------------------------------------------------------
//	Prototypes
//------------------------------------------------------------------------------
// External
	long int	vme_open	();
	long int	vme_read	(unsigned long &adr, unsigned short &rd_data);
	long int	vme_write	(unsigned long &adr, unsigned short &wr_data);
	long int	vme_bwrite	(unsigned long &adr, unsigned short wr_data[], long &nwords);
	long int	vme_bread	(unsigned long &adr, unsigned short rd_data[], long &nwords);
	long int	vme_close	();
	long int	vme_errs	(const int &print_mode);
	void		pause		(string s);
	void		stop		(string s);
	void		dsn_rd		(unsigned long &vme_dsn_adr, const int &itype, int dsn[]);

	void		vme_jtag_anystate_to_rti(unsigned long &adr, int &ichain);
	void		vme_jtag_write_ir		(unsigned long &adr, int &ichain, int &chip_id, int &opcode);
	void		vme_jtag_write_dr		(unsigned long &adr, int &ichain, int &chip_id, char wr_data[], char rd_data[], int &nbits);
	void		tdi_to_i4				(char  tdi[], long int &i4, const int &nbits, const int &spi);

// Local
	void		vme_push	(unsigned long &boot_adr, unsigned short &wr_data);
	void		vme_pop		(unsigned long &boot_adr, int itdo[]);
	void		shift		(unsigned char array[], int &len);
	void		xsvf_wait	(unsigned long &usec, unsigned long &boot_adr, unsigned short &boot_reg);

//------------------------------------------------------------------------------
	void xsvf_writer(int &islot, string xsvf_file_name, int &nerrors)
//------------------------------------------------------------------------------
//	islot           = VME slot for TMB to program
//	xsvf_file_name  = Input PROM data file
//	nerrors         = Errors
//------------------------------------------------------------------------------
{
// VME calls
	long			status;
	unsigned long	base_adr;
	unsigned long	boot_adr;
	unsigned long	adr;
	unsigned short	rd_data;
	unsigned short	wr_data;
//	long			nbread;

// Local
//	char			line[80];
//	int				nfields;
	int				ilen;

	int				itmb;
	int				itdo[21+1];
	int				scan_nerrors[21+1];
	bool			scan_gosub=false;
	char			s='s';

	int				i;
	int				n;
	int				nwrite;

	int				ibyte;
	int				nbytes;

	int				iadr;
	int				iadr_base;
	int				iblock;
	int				iblock_template;

	int				icomplete;
	int				icmd;
	string			cmd;

	int				length;
	unsigned long	xruntest_time;
	int				xrepeat_times;
	int				xdr_length;

	int				state;
	int				state_previous;
	string			sstate;


	int				iadr_xsdrtdo;
	int				prom_id;

	char			colon=':';
	string			ssize;
	char			cmsg[28+1]="Your mother wears army boots";

// File names
	FILE*			xsvf_file=NULL;
	string			xsvf_file_name_default;

//	FILE*			log_file=NULL;
	string			log_file_name;
	string			log_file_name_default;

// Dynamic arrays
	const int		mx_tdi=8196;
	const int		mx_tdo=8196;
	const int		mx_xsvf_image=13*1024*1024;	// needed for tmb mezzanine proms

	char			*rdf;				rdf = new char [mx_bitstream];
	char			*tck;				tck = new char [mx_bitstream];
	char			*tms;				tms = new char [mx_bitstream];	
	char			*tdi;				tdi = new char [mx_bitstream];
	unsigned char	*tdo2d[mx_bitstream];for (i=0; i<mx_bitstream; i++) tdo2d[i] = new unsigned char [21+1];//char tdo2d[mx_bitstream][21+1]
	char			*tdo;				tdo         = new          char [mx_bitstream];
	unsigned char	*tdoexpected;		tdoexpected = new unsigned char [mx_tdo];
	unsigned char	*tdomask;			tdomask     = new unsigned char [mx_tdo];
	unsigned char	*tdivalue;			tdivalue    = new unsigned char [mx_tdi];
	unsigned char	*xsvf_image;		xsvf_image  = new unsigned char [mx_xsvf_image];

// Local
	int				length_sw;
	int				length_min;

	int				imode;
	int				imode_write    = 0;
	int				imode_verify   = 1;
	int				imode_usercode = 2;
	string			smode[3]={"Write  Mode","Verify Mode","Usercode   "};
	bool			mode_switch;
	long int		usercode;

	int				xendir_state = 0;
	int				xenddr_state = 0;

	double			pct_done;
	double			pct_done_old;
	double			delta;
	clock_t			startClock;
	clock_t			endClock;
	int				iseconds;

	int				opcode;
	int				reg_len;
	int				chip_id;
	long int		idcode;
	int				ichain;

//	unsigned short	id_reg[4];
//	int				id_slot;
//	int				id_ver;
//	int				id_type;
//	int				id_month;
//	int				id_day;
//	int				id_year;
//	int				id_rev;
//	int				id_rev_day;
//	int				id_rev_month;
//	int				id_rev_year;
//	int				id_rev_fpga;
//	int				boot_data;

// VME registers
	const unsigned long	vme_idreg_adr	= 0x000000;
	const unsigned long	vme_prom_adr	= 0x000012;
	const unsigned long	vme_dsn_adr		= 0x000026;

	int				vme_en=1;
	bool			nonzero_tdomask;
	bool			alwaysread;
	unsigned char	rd_bit;
	unsigned char	rd_byte[21+1];
	int				ibit;
	int				nbit;
	int				m;
	int				itms;
	unsigned char	ibread;
	unsigned char	ibexpect;

	int				tmb_global_slot = 26;
	int				tmb_brcst_slot  = 27;
	unsigned short	firmware_normal	= 0xC;
	unsigned short	firmware_debug	= 0xD;

// Debugging
//	wrlog=false;	// disable logging
	wrlog=true;		// enable   logging

//-----------------------------------------------------------------------------
// Program PROMs with XSVF file via TMB Boot Register
//-----------------------------------------------------------------------------
//L5000:
	base_adr = (islot << 19);
	boot_adr = base_adr | 0x070000;

	scan_ntmbs       = 1;
	scan_islot[1]    = islot;
	scan_boot_adr[1] = boot_adr;
	ichain           = 0x0008;	// User PROM chain

// Open files
// L5050:
	startClock = clock();						// start timing

	if (xsvf_file!=NULL) fclose(xsvf_file);
//	if (log_file !=NULL) fclose(log_file );

	xsvf_file  = fopen(xsvf_file_name.c_str(),"rb");
	debug_file = log_file;

	if (xsvf_file==NULL) {pause("Failed to open xsvf input  file"); goto exit;}
	if (wrlog)
	if (log_file ==NULL) {pause("Failed to open log  output file"); goto exit;}


// Determine prom type via JTAG if user prom chain selected
	if (ichain == 0x0008) {
	printf("\n");

	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {				// Loop over TMBs
	for (prom_id=0; prom_id<=1; ++prom_id) {				// Loop over proms

	ichain = 0x0008;										// User PROM chain
	adr    = scan_boot_adr[itmb];
	vme_jtag_anystate_to_rti(adr,ichain);					// Take TAP to RTI

	opcode  = 0xFE;											// IDcode opcode
	reg_len = 32;											// IDcode length
	chip_id = prom_id;										// Loop over PROM chips
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	tdi_to_i4(tdo,idcode,32,0);

	if (idcode==0x05022093) {
	ssize = "256";
	ilen  = 256*1024/8;}
	else if (idcode==0x05023093 || idcode==0x05033093) {
	ssize = "512";
	ilen  = 512*1024/8;}
	else {
	ssize = "unk";
	ilen  = 0;
	}

	opcode  = 0xFD;											// PROM USERcode opcode
	reg_len = 32;											// Usercode length

	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	tdi_to_i4(tdo,usercode,32,0);

	if (wrlog)
	fprintf(log_file,"TMB %2i slot %2i PROM%1i IDcode=%8.8X %sKbit USERcode=%8.8X\n",itmb,scan_islot[itmb],chip_id,idcode,ssize.c_str(),usercode);
	fprintf(stdout,"\tTMB %2i slot %2i PROM%1i IDcode=%8.8X %sKbit USERcode=%8.8X\n",itmb,scan_islot[itmb],chip_id,idcode,ssize.c_str(),usercode);

	if (ilen==0) pause("Can not determine PROM size");
	}	// close prom_id
	printf("\n");
	}	// close itmb
	}	// close userprom chain

// Select JTAG chain in Boot Register
	adr     = boot_adr;
	status  = vme_read (adr,rd_data);				// Get current boot reg
	wr_data = rd_data & 0xFFF8;						// zero tck, tms, tdi
	status  = vme_write(adr,wr_data);

	wr_data = wr_data & 0xFF80 | (ichain << 3);		// Select new chain id
	status  = vme_write(adr,wr_data);

	wr_data = wr_data | (1 << 7);					// Commandeer the jtag chain
	status  = vme_write(adr,wr_data);

// Load xsvf file into memory
	printf("\n\tReading XSVF file into memory\n");

	nbytes = fread(xsvf_image,sizeof(char),mx_xsvf_image,xsvf_file);

	printf("\tBytes read from XSVF file=%9i\n",nbytes); 
	if (nbytes>=mx_xsvf_image) stop("xsvf_writer: image array ovf");
	if (nbytes<=0            ) stop("No xsvf bytes to process.wtf?");

// Init vme stats
	npush        = 0;
	npush_total  = 0;
	npush_peak   = 0;
	npop_total   = 0;
	pct_done_old = 0.0;

	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {
	scan_nerrors[itmb]=0;
	}

// Take TAP controller to TLR, ala Xilinx writer
	nwrite=12;
	for (i=0; i<nwrite; i=i+2) {
	tck[i  ]=0;	tms[i  ]=1;	tdi[i  ]=0;
	tck[i+1]=1;	tms[i+1]=1;	tdi[i+1]=0;
	}

	for (i=0; i<nwrite; ++i) {
	wr_data =	(tdi[i] << 0) |
				(tms[i] << 1) |
				(tck[i] << 2) |
				(ichain << 3) |
				(vme_en << 7);
	vme_push(boot_adr,wr_data);
	}

// Navigate xsvf template
	iadr        = 0;
	icomplete   = 0;
	iblock      = 0;
	iblock_template = 0;
	state       = 0;
	erased      = false;
	mode_switch = false;
	idevice     = -1;
	imode       = imode_verify;	// 0=write proms, 1=verify proms
	length_min  = 0x100;
	length_sw   = 0x100;

	xruntest_time   = 0;		// initial
	xrepeat_times   = 32;		// default
	nonzero_tdomask = false;
	alwaysread      = true;

L5600:
	iadr_base = iadr;
	icmd      = xsvf_image[iadr];

	switch (icmd) {

	case 0x00: cmd = "XCOMPLETE  ";
		icomplete++;
		vme_pop(boot_adr,itdo);			// purge write buffer
		if (wrlog) fprintf(log_file,"%s Xcomplete command encountered\n",cmd.c_str());
		if (icomplete!=1) {
		if (wrlog) fprintf(log_file,"Multiple XCOMPLETEs encountered\n");
		pause("Multiple XCOMPLETEs encountered. Continue anyway? <cr>=yes");
		}
		break;

	case 0x01: cmd = "XTDOMASK   ";
		length=xdr_length;
		n=(length-1)/8+1;
		nonzero_tdomask=false;

		for (i=0; i<n; ++i) {
		iadr++;
		ibyte=xsvf_image[iadr];
		tdomask[i]=ibyte & 0xFF;
		if (tdomask[i]!=0) nonzero_tdomask=true;
		}
		if (wrlog) {
		 fprintf(log_file,"%s length = %8.8X bits TDOmask     = ",cmd.c_str(),length);
		 for (i=0; i<n; ++i) fprintf(log_file,"%2.2X",tdomask[i]);
		 fprintf(log_file,"\n");}
		break;

	case 0x02: cmd = "XSIR       ";
		iadr++;
		ibyte=xsvf_image[iadr];
		length=ibyte & 0xFF;
		n=(length-1)/8+1;
		for (i=0; i<n; ++i) {
		iadr++;
		ibyte=xsvf_image[iadr];
		tdivalue[i]=ibyte & 0xFF;
		}
		if (wrlog) {
		 fprintf(log_file,"%s length = %8.8X bits TDIvalue    = ",cmd.c_str(),length);
		 for (i=0; i<n; ++i) fprintf(log_file,"%2.2X",tdivalue[i]);
		 fprintf(log_file,"\n");}

// Take TAP to Shift-IR, TMS=HHLL, assume we were in RTI before
		nwrite = 8;		// popluate tck[7:0]
		m      = 0;	
		if (state!=1) {	// xsvf left us in TLR, so pre-pend 1 tck with tms=0 to move to RTI
		if (wrlog) fprintf(log_file,"%s WRONG state in XSIR=%2.2X %s, moving to RTI\n",cmd.c_str(),state,sstate.c_str());
		nwrite = 10;	// popluate tck[9:0]
		m      =  2;	
		tck[0]=0;	tms[0]=0;	tdi[0]=0;		// in tlr
		tck[1]=1;	tms[1]=0;	tdi[1]=0;		// enters rti
		state = 1;
		}	// close if state

		tck[m+0]=0;	tms[m+0]=1;	tdi[m+0]=0;		// in rti			we start at tck[0] or tck[2]
		tck[m+1]=1;	tms[m+1]=1;	tdi[m+1]=0;		// enters select-dr

		tck[m+2]=0;	tms[m+2]=1;	tdi[m+2]=0;		// in select-dr
		tck[m+3]=1;	tms[m+3]=1;	tdi[m+3]=0;		// enters select-ir

		tck[m+4]=0;	tms[m+4]=0;	tdi[m+4]=0;		// in select-ir
		tck[m+5]=1;	tms[m+5]=0;	tdi[m+5]=0;		// enters capture-ir

		tck[m+6]=0;	tms[m+6]=0;	tdi[m+6]=0;		// in capture-ir
		tck[m+7]=1;	tms[m+7]=0;	tdi[m+7]=0;		// enters shift-ir	we end at tck[7] or tck[9]

// Shift in TDI value, hold tms low to stay in Shift-IR
		if (length==0) stop("XSIR unexpected 0 length");
		m      = nwrite;						// pointer into tck,tms,tdi next avail adr
		nwrite = nwrite+length*2;				// number bits in tck,tms,tdi
		nbit   = 0;								// number bits stored by this section
		itms   = 0;								// 
		for (i=n-1; i>=0; --i)	{				// loop over tdi bytes
		ibyte=tdivalue[i];						// extract 1 tdi byte
		ibyte=ibyte & 0xFF;
		for (ibit=0; ibit<=7; ++ibit) {			// unpack bits from tdi byte
		nbit++;
		if (nbit<=length*2) {
		if (nbit==length) itms=1;				// tms=1 on last IR bit shifted in
		rd_bit=(ibyte >> ibit) & 0x1;			// extact 1 bit
		tck[m]=0; tms[m]=itms; tdi[m]=rd_bit;	//					we load tck[8] or tck[10]
		m++;
		tck[m]=1; tms[m]=itms; tdi[m]=rd_bit;	//					we load tck[9] or tck[11]
		m++;
		}	// close if  nbit<=
		}	// close for ibit
		}	// close for i

// Take TAP to RTI if xruntest time is non-zero, else to xendir, which is always RTI anyway
		m      = nwrite;
		nwrite = nwrite+4;

		tck[m+0]=0;	tms[m+0]=1;	tdi[m+0]=0;		// in exit-ir from last shift
		tck[m+1]=1;	tms[m+1]=1;	tdi[m+1]=0;		// enter update-ir

		tck[m+2]=0;	tms[m+2]=0;	tdi[m+2]=0;		// in update-ir
		tck[m+3]=1;	tms[m+3]=0;	tdi[m+3]=0;		// enter rti

// Pack JTAG transitions into boot register format
	for (i=0; i<nwrite; ++i) {
	wr_data =	(tdi[i] << 0) |
				(tms[i] << 1) |
				(tck[i] << 2) |
				(ichain << 3) |
				(vme_en << 7);
	vme_push(boot_adr,wr_data);
	}

// Wait xruntest time
	if (xruntest_time>0)
	xsvf_wait(xruntest_time,boot_adr,wr_data);

// Take TAP to last XENDIR state, defaults to RTI
		if (xendir_state!=0) stop("XSIR: Unexpected xendir state !=0");
		break;

	case 0x03: cmd = "XSDR       ";	break;

	case 0x04: cmd = "XRUNTEST   ";
		iadr++;
		ibyte=xsvf_image[iadr];
		xruntest_time=((ibyte & 0xFF) << 24);
		iadr++;
		ibyte=xsvf_image[iadr];
		xruntest_time=xruntest_time | ((ibyte & 0xFF) << 16);
		iadr++;
		ibyte=xsvf_image[iadr];
		xruntest_time=xruntest_time | ((ibyte & 0xFF) << 8);
		iadr++;
		ibyte=xsvf_image[iadr];
		xruntest_time=xruntest_time | (ibyte & 0xFF);
		if (wrlog) fprintf(log_file,"%s time   = %8.8X uSec\n",cmd.c_str(),xruntest_time);
		break;

	case 0x05: cmd = "XUNDEFINED5";	break;
	case 0x06: cmd = "XUNDEFINED6";	break;

	case 0x07: cmd = "XREPEAT    ";
		iadr++;
		ibyte=xsvf_image[iadr];
		xrepeat_times=ibyte & 0xFF;
		if (wrlog) fprintf(log_file,"%s times  = %8.8X\n",cmd.c_str(),xrepeat_times);
		break;

	case 0x08: cmd = "XSDRSIZE   ";
		iadr++;
		ibyte=xsvf_image[iadr];
		xdr_length=((ibyte & 0xFF) << 24);
		iadr++;
		ibyte=xsvf_image[iadr];
		xdr_length=xdr_length | ((ibyte & 0xFF) << 16);
		iadr++;
		ibyte=xsvf_image[iadr];
		xdr_length=xdr_length | ((ibyte & 0xFF) << 8);
		iadr++;
		ibyte=xsvf_image[iadr];
		xdr_length=xdr_length | (ibyte & 0xFF);
		if (wrlog) fprintf(log_file,"%s length = %8.8X\n",cmd.c_str(),xdr_length);
		break;

	case 0x09: cmd = "XSDRTDO    ";
// XSDRTDO, the tdi part
		length=xdr_length;
		if (length>mx_tdi) stop("mx_tdi ovf in xsdrtdo");

		if (length >length_min) {		// its a data block,not a command block
		if (length!=length_sw ) {		// mode switched
		length_sw=length;
		imode=(imode+1)%2;				// new mode 0->1 or 1->0
		mode_switch=true;
		}}

		if (mode_switch || (erased && length>length_min && !mode_switch)) {	// display new mode
		erased      = false;
		mode_switch = false;
		printf("\tStarting %s on device %1i\t\t\n",smode[imode].c_str(),idevice);
		}

		n=(length-1)/8+1;
		iadr_xsdrtdo=iadr;
		for (i=0; i<n; ++i) {
		iadr++;
		ibyte=xsvf_image[iadr];
		if (i>mx_tdi) pause("tdi ovf");
		tdivalue[i]=ibyte & 0xFF;
		}	// close for i
		if (wrlog) {
		 fprintf(log_file,"%s length = %8.8X bits TDIvalue    = ",cmd.c_str(),length);
		 for (i=0; i<n; ++i) fprintf(log_file,"%2.2X",tdivalue[i]);
		 fprintf(log_file,"\n");}

// XSDRTDO, the tdo part
		length=xdr_length;	// length in bits
		if (length > mx_tdo) stop("mx_tdo ovf in xsdrtdo");
		n=(length-1)/8+1;	// length in bytes
		for (i=0; i<n; ++i) {
		iadr++;
		ibyte=xsvf_image[iadr];
		if (i > mx_tdo) pause("tdo ovf");
		tdoexpected[i]=ibyte & 0xFF;
		}	// close for i
		if (wrlog) {
		 fprintf(log_file,"%s length = %8.8X bits TDOexpected = ",cmd.c_str(),length);
		 for (i=0; i<n; ++i) fprintf(log_file,"%2.2X",tdoexpected[i]);
		 fprintf(log_file,"\n");}

// Take TAP to Shift-DR, TMS=HLL, assume we were in RTI before
		if (state==0)
		{
		if (wrlog) fprintf(log_file,"%s WRONG state in XSDR=%2.2X %s, expected to be in RTI\n",cmd.c_str(),state,sstate.c_str());
		pause("Wrong TAP state in XSDR");
		}

		nwrite=6;

		tck[0]=0;	tms[0]=1;	tdi[0]=0;	rdf[0]=0;	// in rti
		tck[1]=1;	tms[1]=1;	tdi[1]=0;	rdf[1]=0;	// enter select-dr

		tck[2]=0;	tms[2]=0;	tdi[2]=0;	rdf[2]=0;	// in select-dr
		tck[3]=1;	tms[3]=0;	tdi[3]=0;	rdf[3]=0;	// enter capture-dr

		tck[4]=0;	tms[4]=0;	tdi[4]=0;	rdf[4]=0;	// in capture-dr
		tck[5]=1;	tms[5]=0;	tdi[5]=0;	rdf[5]=0;	// enters shift-dr

// Shift in TDI value, hold tms low to stay in Shift-DR
		if (length==0) stop("XSDRTDO unexpected 0 length");
		m=nwrite;							// pointer into tck,tms,tdi next available adr
		nwrite=nwrite+length*2;				// number bits in tck,tms,tdi
		if (nwrite>=mx_bitstream) stop("mxbitstream ovf");
		nbit=0;								// number bits stored by this section
		itms=0;	
		for (i=n-1; i>=0; --i) {			// loop over tdi bytes
		ibyte=tdivalue[i];					// extract 1 tdi byte
		for (ibit=0; ibit<=7; ++ibit) {		// unpack bits from tdi byte
		nbit++;
		if (nbit <= length*2) {
		if (nbit == length)itms=1;			// tms=1 on last DR bit shifted in
		rd_bit=(ibyte >> ibit) & 0x1;		// extact 1 bit
		tck[m]=0; tms[m]=itms; tdi[m]=rd_bit;	rdf[m]=1;
		m++;
		tck[m]=1; tms[m]=itms; tdi[m]=rd_bit;	rdf[m]=0;
		m++;
		}	// close if nbit <= length*2
		}	// close for ibit
		}	// close for n

// Take TAP to RTI if xruntest time is non-zero, else to xendir, which is always RTI anyway
		m=nwrite;
		nwrite=nwrite+4;
		if (nwrite >= mx_bitstream) stop("mx_bitstream ovf");

		tck[m+0]=0;	tms[m+0]=1;	tdi[m+0]=0;	rdf[m+0]=0;	// in exit-dr from last shift
		tck[m+1]=1;	tms[m+1]=1;	tdi[m+1]=0;	rdf[m+1]=0;	// enter update-dr

		tck[m+2]=0;	tms[m+2]=0;	tdi[m+2]=0;	rdf[m+2]=0;	// in update-dr
		tck[m+3]=1;	tms[m+3]=0;	tdi[m+3]=0;	rdf[m+3]=0;	// enter rti

// Pack JTAG transitions into boot register format
	ibyte = 0;
	ibit  = 0;

	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {	// clear tdo array for display in case no-read
	rd_byte[itmb]=0;
	for (i=0; i<nwrite; ++i) {
	tdo2d[i][itmb]=0;
	}}

	for (i=0; i<nwrite; ++i) {
	wr_data=	(tdi[i] << 0) |
				(tms[i] << 1) |
				(tck[i] << 2) |
				(ichain << 3) |
				(vme_en << 7);
	vme_push(boot_adr,wr_data);

	if (rdf[i]==1 && (nonzero_tdomask || alwaysread)) {	// tdo readback required
	vme_pop(boot_adr,itdo);								// purge write buffer, read tdo

	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {
	rd_byte[itmb]=rd_byte[itmb] | (itdo[itmb] << ibit);	// pack tdo bits into bytes
	tdo2d[ibyte][itmb]=rd_byte[itmb];					// store now, in case less than 8 bits in the byte
	}	// close itmb
	ibit++;

	if (ibit==8) {										// pack bytes into array
	ibyte++;
	if (ibyte >= mx_bitstream) stop("mx_bitstream ovf");
	ibit=0;

	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {
	rd_byte[itmb]=0;
	}

	}	// close ibit
	}	// close rdf
	}	// close i

// Compare tdo-read to tdo-expected using tdo-mask
	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {

	if (wrlog) {
	fprintf(log_file,"%s length = %8.8X bits TDOread     = ",cmd.c_str(),length);
	for (i=n-1; i>=0; --i) fprintf(log_file,"%2.2X",tdo2d[i][itmb]);
	fprintf(log_file,"  itmb=%2i slot=%2i\n",itmb,scan_islot[itmb]);}

	if (nonzero_tdomask) {	// tdo readback comparison required
	for (i=0; i<n; ++i) {
	ibread   = tdo2d[n-1-i][itmb] & tdomask[i];
	ibexpect = tdoexpected[i]     & tdomask[i];
	if (ibread!=ibexpect) {
	scan_nerrors[itmb]=scan_nerrors[itmb]+1;

	if (wrlog) 
	fprintf(log_file,"TDO error in byte %5i masked(read=%2.2X expect=%2.2X) unmasked(read=%2.2X expect=%2.2X)%9i\n",
	i,ibread,ibexpect,tdo2d[n-1-i][itmb],tdoexpected[i],scan_nerrors[itmb]);

	}	// close ibread
	}	// close i
	}	// close nonzero
	}	// close itmb

// Wait xruntest time
	if (xruntest_time>0)
	xsvf_wait(xruntest_time,boot_adr,wr_data);

// Take TAP to last XENDDR state, defaults to RTI
	if (xenddr_state!=0) stop("XSIR: Unexpected xenddr 0 state");
	break;

	case 0x0A: cmd = "XSETSDRMASK";	break;
	case 0x0B: cmd = "XSDRINC    ";	break;
	case 0x0C: cmd = "XSDRB      ";	break;
	case 0x0D: cmd = "XSDRC      ";	break;
	case 0x0E: cmd = "XSDRE      ";	break;
	case 0x0F: cmd = "XSDRTDOB   ";	break;
	case 0x10: cmd = "XSDRTDOC   ";	break;
	case 0x11: cmd = "XSDRTDOE   ";	break;

	case 0x12: cmd = "XSTATE     ";
		iadr++;
		ibyte=xsvf_image[iadr];
		state_previous=state;
		state=ibyte & 0xFF;
		sstate="???";
		if (state==0) sstate="TLR";
		if (state==1) sstate="RTI";
		if (wrlog) fprintf(log_file,"%s state  = %2.2X %s\n",cmd.c_str(),state,sstate.c_str());

// State 00 take TAP to TLR by setting TMS=1 and toggling TCK 6 times (ala Xilinx xsvfwriter, yes I know only 5 are needed)
		if (state==0)
		{
		nwrite=12;
		for (i=0; i<nwrite; i=i+2) {
		tck[i  ]=0;	tms[i  ]=1;	tdi[i  ]=0;
		tck[i+1]=1;	tms[i+1]=1;	tdi[i+1]=0;
		}	// close for i
		}	// close if state

// State 01 take TAP to RTI by setting TMS-0 and toggling TCK 1 time
		else if (state==1)
		{
		if (state_previous!=0) stop("XSTATE: previous state was not TLR");
		nwrite=2;
		tck[ 0]=0;	tms[ 0]=0;	tdi[ 0]=0;
		tck[ 1]=1;	tms[ 1]=0;	tdi[ 1]=0;
		}

// Undefined state
		else 
		{
		nwrite=0;
		if (wrlog)
		fprintf(log_file,"%s state  = %2.2X %s\n",cmd.c_str(),state,"undefined");
		fprintf(stdout,"\t%s state  = %2.2X %s\n",cmd.c_str(),state,"undefined");
		pause("woe be unto us");
		}

// Pack JTAG transitions into boot register format
	for (i=0; i<nwrite; ++i) {
	wr_data=	(tdi[i] << 0) |
				(tms[i] << 1) |
				(tck[i] << 2) |
				(ichain << 3) |
				(vme_en << 7);
	vme_push(boot_adr,wr_data);
	}
	break;

	case 0x13: cmd = "XENDIR     ";
		iadr++;
		ibyte=xsvf_image[iadr];
		xendir_state=ibyte & 0xFF;
		sstate="???";
		if (xendir_state==0) sstate="RTI";
		if (xendir_state==1) sstate="PIR";
		if (wrlog) fprintf(log_file,"%s state  = %2.2X %s\n",cmd.c_str(),xendir_state,sstate.c_str());
		break;

	case 0x14: cmd = "XENDDR     ";
		iadr++;
		ibyte=xsvf_image[iadr];
		xenddr_state=ibyte & 0xFF;
		sstate="???";
		if (xenddr_state==0) sstate="RTI";
		if (xenddr_state==1) sstate="PDR";
		if (wrlog) fprintf(log_file,"%s state  = %2.2X %s\n",cmd.c_str(),xenddr_state,sstate.c_str());
		break;

	case 0x15: cmd = "XSIR2      ";	break;
	case 0x16: cmd = "XCOMMENT   ";	break;

//	Close switch
	}

// Command case not found
	if (iadr==iadr_base && icomplete==0) {
	if (wrlog) fprintf(log_file,"cmd=%s not implemented\n",cmd.c_str());
		       fprintf(stdout,"\tcmd=%s not implemented\n",cmd.c_str());
	pause("Continue anyway? <cr>=yes");
	}

// Next instruction from xsvf
	iadr++;

	endClock = clock();
	delta    = (float)(endClock-startClock)/(float)CLOCKS_PER_SEC;
	iseconds = int(delta+0.5);
	pct_done=100.*float(iadr)/float(nbytes);

	if (iadr<8 || pct_done>(pct_done_old+0.1))
	printf("\r     ");
	printf("\tProgress: %5.1f%% T=%5i sec errors=",pct_done,iseconds);
	for (itmb=1; itmb<=scan_ntmbs; ++itmb) printf("%6i",scan_nerrors[itmb]);
	printf("\r");

	if (iadr<=nbytes-1)goto L5600;

// Disengage Boot Register from JTAG chain
	adr     = boot_adr;
	wr_data = (0xC << 3);	// idle to empty jtag chain address
	status  = vme_write(adr,wr_data);

// Summary
	printf("\n\n");
	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {
	fprintf(stdout,  "\tTMB %2i slot %2i Errors=%6i\n",itmb,scan_islot[itmb],scan_nerrors[itmb]);
	if (wrlog)
	fprintf(log_file,"\tTMB %2i slot %2i Errors=%6i\n",itmb,scan_islot[itmb],scan_nerrors[itmb]);
	}

	printf("\n");
	printf("\tVME  writes =%10i\n",npush_total);
	printf("\tPeak writes =%10i\n",npush_peak);
	printf("\tVME  reads  =%10i\n",npop_total);
	printf("\n");

// Close files
	if (xsvf_file != NULL) fclose(xsvf_file);
	if (log_file  != NULL) fclose(log_file );

	printf("\n");
	scan_gosub = false;

// Close VME interface
	status = vme_close();
//	goto main_menu;
	goto exit;

//-----------------------------------------------------------------------------
// End of xsvf_writer extract
//-----------------------------------------------------------------------------
exit:
	return;
}

//-----------------------------------------------------------------------------
// Shift tdi or tdo byte array 1 bit left
//-----------------------------------------------------------------------------
	void shift(unsigned char array[], int &len)
{
	unsigned char	carry;
	unsigned char	ibyte;
	int				i;

	carry = 0;
	for (i=len-1; i>=1; --i) {
	ibyte   =  array[i];
	array[i]= (ibyte << 1) | (carry << 0);
	carry   = (ibyte >> 7) & 0x1;	// msb this byte, carries to lsb next byte
	}
	array[0]=carry;
	return;
}

//-----------------------------------------------------------------------------
// Wait the specified number of microseconds by pulsing jtag tck
//-----------------------------------------------------------------------------
	void xsvf_wait (unsigned long &usec, unsigned long &boot_adr, unsigned short &boot_reg)
{
// common/status_common/
// Local
	static bool		first_entry=true;
	static double	tck_per_usec;
	long			nbwrite;
	unsigned short	wr_data;
	long			status;
	int				tck_lo;
	int				tck_hi;
	int				i;
	int				n;
	int				ncycles;
	int				pulse_tck[2];
	bool			wrlog_saved;
	double			delta;
	clock_t			startClock;
	clock_t			endClock;

// On first entry calibrate CPU speed
	if (wrlog) fprintf(debug_file,"WAIT: %10i microseconds\n",usec);

	if (first_entry) {
	first_entry=false;

	printf("\r\n\tCalibrating tck write-speed for 2 seconds\n");
	n=4096;
	for (i=0; i<n; ++i) {
	wr_buf[i]=boot_reg;
	}

	startClock = clock();								// start timing
	ncycles = 320;
	nbwrite = n;

	for (i=0; i<ncycles; ++i) {
	status=vme_bwrite(boot_adr,wr_buf,nbwrite);
	}

	endClock = clock();									// stop timing
	delta    = (float)(endClock-startClock)/(float)CLOCKS_PER_SEC;
	if (delta < 1.0e-06) delta=1.0e-01;					// do not allow divide by 0
	tck_per_usec=0.5*float(n*ncycles)/(delta*1.0e06);	// tcks per microsecond, takes 2 pushes per tck period
	printf("\tTCK/uSec=%8.6f deltaT=%6.4f for cycles=%6i\n",tck_per_usec,delta,n*ncycles);

	tck_per_usec=tck_per_usec*0.9725;					// correction for actual Bit3 timing
	}	// close if(first

// Wait for microseconds using calibrated TCK speed
	wrlog_saved = wrlog;	// turn off logging
	wrlog      = false;

	if (usec>1000000) {
	erased=true;
	idevice++;
	printf("\r\tErasing device%2i %6i seconds\t\t\t\n",idevice,usec/1000000);
	startClock = clock();			// start timing
	}

	tck_lo = boot_reg & 0xFFFB;		// tck=0
	tck_hi = boot_reg | 0x0004;		// tck=1

	pulse_tck[0] = tck_lo;
	pulse_tck[1] = tck_hi;

	n=1+int(float(usec)*tck_per_usec+0.5);

	for (i=0; i<n; ++i) {
	vme_push(boot_adr,wr_data=pulse_tck[0]);
	vme_push(boot_adr,wr_data=pulse_tck[1]);
	}

	if (usec>1000000) {
	endClock = clock();							// stop timing
	delta    = (float)(endClock-startClock)/(float)CLOCKS_PER_SEC;
	if (wrlog)
	fprintf(debug_file,"Erase elapsed time   %5.2f\n",delta);
	fprintf(stdout,  "\tErase elapsed time   %5.2f\n",delta);
	}

// Restore logging state
	wrlog=wrlog_saved;
	return;
}
//-----------------------------------------------------------------------------
// Push JTAG data onto VME write-stack
//-----------------------------------------------------------------------------
	void vme_push(unsigned long &boot_adr, unsigned short &wr_data)
{
//	common/status_common/
// Local
	long			status;
	int				itdi;
	int				itms;
	int				itck;
	int				ichain;
	int				ivme_en;
	int				npush_thresh=4095;
	long			nbwrite;

// Push data onto stack
	wr_buf[npush]=wr_data;						// push
	npush++;									// words in write buffer
	npush_total++;								// total words written to vme
	if (npush>npush_peak) npush_peak=npush;		// largest vme buffer

// Display data if logging enabled
	if (wrlog) { 
	itdi    = (wr_data >> 0) & 0x1;
	itms    = (wr_data >> 1) & 0x1;
	itck    = (wr_data >> 2) & 0x1;
	ichain  = (wr_data >> 3) & 0xF;
	ivme_en = (wr_data >> 7) & 0x1;

	fprintf(debug_file,"vme_push:%10i tck=%1i tms=%1i tdi=%1i ichain=%2X vme_en=%2i wr_data=%4.4X\n",
	npush_total,itck,itms,itdi,ichain,ivme_en,wr_data);
	}

// Write buffer to vme when full
	if (npush==npush_thresh) {
	nbwrite=npush;
	status=vme_bwrite(boot_adr,wr_buf,nbwrite);
	npush=0;
	}
	return;
}

//-----------------------------------------------------------------------------
// Pop JTAG data off VME read-stack
//-----------------------------------------------------------------------------
	void vme_pop (unsigned long &boot_adr, int itdo[])
{
//	common/status_common/
// Local
	long			status;
	unsigned short	rd_data;
//	unsigned short	wr_data;
	unsigned long	adr;
	int				itmb;

// Write partial buffer to vme if its not empty
	if (npush>0) {
	status=vme_bwrite(boot_adr,wr_buf,npush);	// block writes dont work here, dunno why
	npush=0;
	}

// Read tdo
	npop_total++;

	for (itmb=1; itmb<=scan_ntmbs; ++itmb) {
	adr       = scan_boot_adr[itmb];
	status    = vme_read(adr,rd_data);
	itdo[itmb]= (rd_data >> 15) & 0x1;
	if (wrlog) 
	fprintf(debug_file,"vme_pop: %10i boot=%4.4X tdo=%1i itmb=%2i slot=%2i\n",npop_total,rd_data,itdo[itmb],itmb,scan_islot[itmb]);
	}
	return;
}
//-----------------------------------------------------------------------------
// End of xsvfwriter source code
//-----------------------------------------------------------------------------
