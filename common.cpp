//------------------------------------------------------------------------------
// Common
//------------------------------------------------------------------------------

#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std; 

const int		mxframe	= 8192;		// Max raw hits frame number, scope adds 512*160/16=5120 frames
const int		mxtbins	= 32;		// Highest time bin, 0 implies 32
const int		mxly	= 6;		// # CSC Layers
const int		mxds	= 8;		// # DiStrips per CFEB
const int		mxdsabs	= 40;		// # DiStrips per CSC
const int		mxcfeb	= 5;		// # CFEBs
const int		mxbitstream=200;	// Max # bits in a jtag cycle

//------------------------------------------------------------------------------

FILE			*unit;

FILE			*log_file=NULL;
string			log_file_name;

FILE*			img_file;

FILE*			sum_file=NULL;
string			sum_file_name;

FILE*			scn_file=NULL;
string			scn_file_name;

FILE*			vme_file=NULL;
string			vme_file_name;
string			vme_file_name_default;
char			cid_rev[4+1];
string			sid_rev="byte";

FILE*			dump_file=NULL;
string			dump_file_name;
string			dump_file_name_default;

FILE*			prom_file=NULL;
string			prom_file_name;
string			prom_file_name_default;

FILE*			test_file=NULL;
string			test_file_name;
string			logfolder;
string			jtag_file_name;

FILE*			raw_file=NULL;
string			raw_file_name;
string			raw_file_name_default;

FILE*			ascii_file=NULL;
string			ascii_file_name;
string			ascii_file_name_default;

FILE*			mcs_file=NULL;
string			mcs_file_name;
string			mcs_file_name_default;

FILE*			compare_file=NULL;
string			compare_file_name;
string			compare_file_name_default;

FILE*			ram_file=NULL;
string			ram_file_name;

//------------------------------------------------------------------------------

// Common/decode_readout_common/
int				scp_tbins;
int				scp_playback;
int				fifo_tbins_mini;
int				first_event;
int				itriad[mxtbins][mxdsabs][mxly];
int				clct0_vme;
int				clct1_vme;
int				clctc_vme;
int				mpc0_frame0_vme;
int				mpc0_frame1_vme;
int				mpc1_frame0_vme;
int				mpc1_frame1_vme;
int				nonzero_triads;
int				adjcfeb_dist;
int				mpc_me1a_block;

int				expect_zero_alct;
int				expect_zero_clct;
int				expect_one_alct;
int				expect_one_clct;
int				expect_two_alct;
int				expect_two_clct;
int				expect_dupe_alct;
int				expect_dupe_clct;
int				vme_bx0_emu_en;
bool			first_scn;
//------------------------------------------------------------------------------

// common/log file
//void			sleep			(clock_t msec);
#define			logical(L)	((L)?'T':'F')

// common/xsvf writer
FILE			*xsvf_file;
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

//common/vme_jtag_io_ops

//  VME Chain	Function
//  ---------	------------------------------------
//	0x0	0000	ALCT Slow control User
//	0x1	0001	ALCT Slow control FPGA+PROM
//	0x2	0010	ALCT Mezzanine    User
//	0x3	0011	ALCT Mezzanine    FPGA+PROM		+ Variants for Virtex-E and Spartan-6
//	0x4	01XX	TMB  Mezzanine    FPGA+PROM		+ Variants for Virtex-2 and Virtex-6
//	0x8	10XX	TMB  User         PROMs
//	0xC	1100	FPGA Monitor      For TMB self-test
//	0xD	1101	RAT  Module       FPGA+PROM

const int	mxchain   = 8;									// Chain_id
const int	mxdevices = 5;									// Devices in chain

const int			devices_in_chain[mxchain]={2,2,2,5,1,2,3,3};	// Chain 0,1,2,3,4,5,6,7
const int			bits_per_opcode[mxchain][mxdevices]={
    { 8, 8, 0, 0, 0},		// 0 TMB user prom chain		PROM, PROM
    { 5, 8, 0, 0, 0},		// 1 RAT chain					FPGA, PROM
    { 5, 8, 0, 0, 0},		// 2 ALCT VirtexE  mez chain	FPGA, PROM
    { 6, 8, 8, 8, 8},		// 3 TMB  Virtex2  mez chain	FPGA, PROM, PROM, PROM, PROM
    {10, 0, 0, 0, 0},		// 4 TMB  Virtex6  mez chain	FPGA, PROM, PROM
    { 3, 8, 0, 0, 0},		// 5 ALCT slow control chain	FPGA, PROM
    { 6,16,16, 0, 0},		// 6 ALCT Spartan6 mez chain	FPGA, PROM, PROM
    { 6,16,16, 0, 0}};		// 7 TMB  Spartan6 mez chain	FPGA, PROM, PROM

// Common/adc_common_mez/
double		adc_voltage_mez[14];
double		v3p3_mez;
double		v2p5_mez;
double		vcore_mez;
double		v1p8_mez;
double		v1p2_mez;
double		tfpga_mez;
double		tsink_mez;
double		vch07_mez;
double		vch08_mez;
double		vch09_mez;
double		vch10_mez;
double		vref2_mez;
double		vzero_mez;
double		vref_mez;

// Common/jtag_common/
FILE *jtag_file;
bool	jtaglogmode;

//------------------------------------------------------------------------------
//int	A;


//------------------------------------------------------------------------------
const int	MXCFEB		= 	5;				// Number of CFEBs on CSC
const int	MXLY		=	6;				// Number Layers in CSC
const int	MXHS		=	32;				// Number of 1/2-Strips per layer on 1 CFEB
const int	MXHSX		=	MXCFEB*MXHS;	// Number of 1/2-Strips per layer on 5 CFEBs
const int	MXKEYBX		=	8;				// Number of 1/2-strip key bits on 5 CFEBs
const int	MXPIDB		=	4;				// Pattern ID bits

//	common/portsf_common/
const int				setport_mxnwords = 4096;
unsigned long	xilinx_boot_adr;
unsigned short	xilinx_boot_data;
int				setport_calls;
int				setport_writes;
int				setport_reads;
int				setport_writes_expected;
int				setport_nwords;
int				setport_peak_nwords;
unsigned short	setport_buffer[setport_mxnwords];
int				xsvf_verbosity;
bool				wlog;
int				numwrites;
int				numreads;


// Common/adc_common/
double		adc_voltage[14];
double		v5p0;
double		v3p3;
double		v1p5core;
double		vcore_expect;
double		vcore_noload;
double		v1p5tt;
double		v1p0;
double		v1p0_expect;
double		a5p0;
double		a3p3;
double		a1p5core;
double		a1p5tt;
double		a3p3rat;
double		a1p8rat;
double		v3p3rat;
double		v1p8rat;
double		vref2;
double		vzero;
double		vref;


// Passed to decode_readout from caller
unsigned long	base_adr;
unsigned long	scp_ctrl_adr;
unsigned long	scp_rdata_adr;
