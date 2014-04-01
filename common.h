//------------------------------------------------------------------------------
// Common
//------------------------------------------------------------------------------
#ifndef COMMON_H
#define COMMON_H
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

extern FILE			*unit;

extern FILE			*log_file;
extern string			log_file_name;

extern FILE*			img_file;

extern FILE*			sum_file;
extern string			sum_file_name;

extern FILE*			scn_file;
extern string			scn_file_name;

extern FILE*			vme_file;
extern string			vme_file_name;
extern string			vme_file_name_default;
extern char			cid_rev[4+1];
extern string			sid_rev;

extern FILE*			dump_file;
extern string			dump_file_name;
extern string			dump_file_name_default;

extern FILE*			prom_file;
extern string			prom_file_name;
extern string			prom_file_name_default;

extern FILE*			test_file;
extern string			test_file_name;
extern string			logfolder;
extern string			jtag_file_name;

extern FILE*			raw_file;
extern string			raw_file_name;
extern string			raw_file_name_default;

extern FILE*			ascii_file;
extern string			ascii_file_name;
extern string			ascii_file_name_default;

extern FILE*			mcs_file;
extern string			mcs_file_name;
extern string			mcs_file_name_default;

extern FILE*			compare_file;
extern string			compare_file_name;
extern string			compare_file_name_default;

extern FILE*			ram_file;
extern string			ram_file_name;

//------------------------------------------------------------------------------

// Common/decode_readout_common/
extern int				scp_tbins;
extern int				scp_playback;
extern int				fifo_tbins_mini;
extern int				first_event;
extern int				itriad[mxtbins][mxdsabs][mxly];
extern int				clct0_vme;
extern int				clct1_vme;
extern int				clctc_vme;
extern int				mpc0_frame0_vme;
extern int				mpc0_frame1_vme;
extern int				mpc1_frame0_vme;
extern int				mpc1_frame1_vme;
extern int				nonzero_triads;
extern int				adjcfeb_dist;
extern int				mpc_me1a_block;

extern int				expect_zero_alct;
extern int				expect_zero_clct;
extern int				expect_one_alct;
extern int				expect_one_clct;
extern int				expect_two_alct;
extern int				expect_two_clct;
extern int				expect_dupe_alct;
extern int				expect_dupe_clct;
extern int				vme_bx0_emu_en;
extern bool			first_scn;
//------------------------------------------------------------------------------


// common/log file
void			sleep			(clock_t msec);
#define			logical(L)	((L)?'T':'F')
#define			yesno(L)		((L)?'y':'n')

// common/xsvf writer
extern	FILE			*xsvf_file;
const int		mx_bitstream=32768;			// Max # bits in a jtag cycle
extern FILE			*debug_file;
extern bool			wrlog;
extern bool			erased;
extern int				idevice;
extern long			npush;
extern unsigned long	npush_total;
extern int				npush_peak;
extern int				npop_total;
extern int				scan_ntmbs;
extern int				scan_islot[21+1];
extern unsigned long	scan_boot_adr[21+1];
extern unsigned short	wr_buf[mx_bitstream];

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
extern double		adc_voltage_mez[14];
extern double		v3p3_mez;
extern double		v2p5_mez;
extern double		vcore_mez;
extern double		v1p8_mez;
extern double		v1p2_mez;
extern double		tfpga_mez;
extern double		tsink_mez;
extern double		vch07_mez;
extern double		vch08_mez;
extern double		vch09_mez;
extern double		vch10_mez;
extern double		vref2_mez;
extern double		vzero_mez;
extern double		vref_mez;

// Common/jtag_common/
extern FILE *jtag_file;
extern bool	jtaglogmode;

//------------------------------------------------------------------------------
//extern int	A;


//------------------------------------------------------------------------------
const int	MXCFEB		= 	5;				// Number of CFEBs on CSC
const int	MXLY		=	6;				// Number Layers in CSC
const int	MXHS		=	32;				// Number of 1/2-Strips per layer on 1 CFEB
const int	MXHSX		=	MXCFEB*MXHS;	// Number of 1/2-Strips per layer on 5 CFEBs
const int	MXKEYBX		=	8;				// Number of 1/2-strip key bits on 5 CFEBs
const int	MXPIDB		=	4;				// Pattern ID bits

//	common/portsf_common/
const int				setport_mxnwords = 4096;
extern unsigned long	xilinx_boot_adr;
extern unsigned short	xilinx_boot_data;
extern int				setport_calls;
extern int				setport_writes;
extern int				setport_reads;
extern int				setport_writes_expected;
extern int				setport_nwords;
extern int				setport_peak_nwords;
extern unsigned short	setport_buffer[setport_mxnwords];
extern int				xsvf_verbosity;
extern bool				wlog;
extern int				numwrites;
extern int				numreads;


// Common/adc_common/
extern double		adc_voltage[14];
extern double		v5p0;
extern double		v3p3;
extern double		v1p5core;
extern double		vcore_expect;
extern double		vcore_noload;
extern double		v1p5tt;
extern double		v1p0;
extern double		v1p0_expect;
extern double		a5p0;
extern double		a3p3;
extern double		a1p5core;
extern double		a1p5tt;
extern double		a3p3rat;
extern double		a1p8rat;
extern double		v3p3rat;
extern double		v1p8rat;
extern double		vref2;
extern double		vzero;
extern double		vref;


// Passed to decode_readout from caller
extern unsigned long	base_adr;
extern unsigned long	scp_ctrl_adr;
extern unsigned long	scp_rdata_adr;
#endif
