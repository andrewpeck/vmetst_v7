//------------------------------------------------------------------------------
// Common
//------------------------------------------------------------------------------

#include <stdio.h>
#include <iostream>
#include <time.h>
#include "common.h"
using namespace std; 

//------------------------------------------------------------------------------

FILE			*unit;

FILE			*log_file=NULL;
std::string			log_file_name;

FILE*			img_file;

FILE*			sum_file=NULL;
std::string			sum_file_name;

FILE*			scn_file=NULL;
std::string			scn_file_name;

FILE*			vme_file=NULL;
std::string			vme_file_name;
std::string			vme_file_name_default;
char			cid_rev[4+1];
std::string			sid_rev="byte";

FILE*			dump_file=NULL;
std::string			dump_file_name;
std::string			dump_file_name_default;

FILE*			prom_file=NULL;
std::string			prom_file_name;
std::string			prom_file_name_default;

FILE*			test_file=NULL;
std::string			test_file_name;
std::string			logfolder;
std::string			jtag_file_name;

FILE*			raw_file=NULL;
std::string			raw_file_name;
std::string			raw_file_name_default;

FILE*			ascii_file=NULL;
std::string			ascii_file_name;
std::string			ascii_file_name_default;

FILE*			mcs_file=NULL;
std::string			mcs_file_name;
std::string			mcs_file_name_default;

FILE*			compare_file=NULL;
std::string			compare_file_name;
std::string			compare_file_name_default;

FILE*			ram_file=NULL;
std::string			ram_file_name;

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
//	common/portsf_common/
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

// ALCT single cable test
//int				itest;
int				itest_first;
int				itest_last;
//int				ipass;
int				ipf;
//int				npasses;
int				ipattern;
int				npatterns;

int				adb_wr_ch;
long			adb_rd_ch;
long			adb_rd_data;
long			scsi_rd_data;
int				scsi_wr_data;

long			alct_fpga;
long			alct_fmonthday;
long			alct_fmonth;
long			alct_fday;
long			alct_fyear;
long			alct_todd;
long			alct_teven;
long			alct_crc_err;
long			adb_hit;
long			adb_hit_expect;

std::string			salct_fpga;
std::string			sok;

bool			iprint;
bool			ifail;
bool			adb_auto;
bool			adb_passed[24];

int				alct_npassed[alct_ntests+1];
int				alct_nfailed[alct_ntests+1];
int				alct_nskipped[alct_ntests+1];
int				alct_npassed_sc[alct_ntests+1];

// Slow control walking 0 test
long			sc_begin;
long			sc_end;
int				ipin;
int				ones;
int				zeros;
char			ipin_state[208+1];	// FPGA pins 1-208
int				ipin_driven[208+1];
int				ipin_shorted[208+1];
int				ipin_skip[208+1];
std::string			ipin_name[208+1];
int				nshorted;
int				iexpect;

// Slow control normal firmware
__int64			i64;
long			sc_id_reg[2];
long			sc_rd_standby[2];
long			sc_wr_standby[2];
long			sc_wr_tp_group;
long			sc_rd_tp_group;
long			sc_wr_tp_strip;
long			sc_rd_tp_strip;
long			sc_wr_vga_pd;
long			sc_rd_vga_pd;
long			sc_id_chip;
long			sc_id_version;
long			sc_id_day;
long			sc_id_month;
long			sc_id_year;

int				vga_data;
int				vga_len;
bool			vga_ramp;
//bool			bans;
int				istep;
int				npulses;
int				ipulse;

int				idac;
int				ithr;
int				dac_bit;
int				dac_adr;
int				dac_data;
int				dac_word;
double			vdac;
double			err;

bool			dac_ramp;
//bool			debug;

int				iadc;
int				adc_ch;
int				adc_word;
int				iadc_driven;
int				adc_ch_driven;
int				adc_value[24][256];
int				opcode0=0;

int				bad_thr[24];
//int				nerrors;
int				ncycles;
//int				icycle;
int				ndone;

double			adc_error[24][256];
double			adc_expect;
int				yaxis;
int				yvalue;
char			ichar;

double			vref_sc;
double			vlsb_sc;

double			vadc_offset;
double			vadc_scaled;
double			vadc;
double			vadc_base[5][14];

std::string			adc_ch_name[5][14]=
{
    "ADC0 Ch0 Vthr23",
    "ADC0 Ch1 Vthr22",
    "ADC0 Ch2 Vthr21",
    "ADC0 Ch3 Vthr20",
    "ADC0 Ch4 Vthr19",
    "ADC0 Ch5 Vthr18",
    "ADC0 Ch6 Vthr17",
    "ADC0 Ch7 Vthr16",
    "ADC0 Ch8 Vthr15",
    "ADC0 Ch9 Vthr14",
    "ADC0 ChA Vthr13",
    "ADC0 ChB Vzero ",
    "ADC0 ChC Vhalf ",
    "ADC0 ChD Vfull ",

    "ADC1 Ch0 Vthr12",
    "ADC1 Ch1 Vthr11",
    "ADC1 Ch2 Vthr10",
    "ADC1 Ch3 Vthr9 ",
    "ADC1 Ch4 Vthr8 ",
    "ADC1 Ch5 Vthr7 ",
    "ADC1 Ch6 Vthr6 ",
    "ADC1 Ch7 Vthr5 ",
    "ADC1 Ch8 Vthr4 ",
    "ADC1 Ch9 Vthr3 ",
    "ADC1 ChA Vthr2 ",
    "ADC1 ChB Vzero ",
    "ADC1 ChC Vhalf ",
    "ADC1 ChD Vfull ",

    "ADC2 Ch0 Vthr1 ",
    "ADC2 Ch1 Vthr0 ",
    "ADC2 Ch2 +1.8A ",
    "ADC2 Ch3 +3.3A ",
    "ADC2 Ch4 +5.5A1",
    "ADC2 Ch5 +5.5A2",
    "ADC2 Ch6 +1.8V ",
    "ADC2 Ch7 +3.3V ",
    "ADC2 Ch8 +5.5V1",
    "ADC2 Ch9 +5.5V2",
    "ADC2 ChA Temp  ",
    "ADC2 ChB Vhalf ",
    "ADC2 ChC Vzero ",
    "ADC2 ChD Vfull ",

    "ADC3 Ch0 Vthr  ",
    "ADC3 Ch1 Vthr  ",
    "ADC3 Ch2 Vthr  ",
    "ADC3 Ch3 Vthr  ",
    "ADC3 Ch4 Vthr  ",
    "ADC3 Ch5 Vthr  ",
    "ADC3 Ch6 Vthr  ",
    "ADC3 Ch7 Vthr  ",
    "ADC3 Ch8 Vthr  ",
    "ADC3 Ch9 Vthr  ",
    "ADC3 ChA Vthr  ",
    "ADC3 ChB Vzero ",
    "ADC3 ChC Vhalf ",
    "ADC3 ChD Vfull ",

    "ADC4 Ch0 Vthr  ",
    "ADC4 Ch1 Vthr  ",
    "ADC4 Ch2 Vthr  ",
    "ADC4 Ch3 Vthr  ",
    "ADC4 Ch4 Vthr  ",
    "ADC4 Ch5 Vthr  ",
    "ADC4 Ch6 Vthr  ",
    "ADC4 Ch7 Vthr  ",
    "ADC4 Ch8 Vthr  ",
    "ADC4 Ch9 Vthr  ",
    "ADC4 ChA Vthr  ",
    "ADC4 ChB Vzero ",
    "ADC4 ChC Vhalf ",
    "ADC4 ChD Vfull "
};

std::string			adc_ch_unit[5][14]=
{
    "V",	// ADC0 Ch0 Vthr23
    "V",	// ADC0 Ch1 Vthr22
    "V",	// ADC0 Ch2 Vthr21
    "V",	// ADC0 Ch3 Vthr20
    "V",	// ADC0 Ch4 Vthr19
    "V",	// ADC0 Ch5 Vthr18
    "V",	// ADC0 Ch6 Vthr17
    "V",	// ADC0 Ch7 Vthr16
    "V",	// ADC0 Ch8 Vthr15
    "V",	// ADC0 Ch9 Vthr14
    "V",	// ADC0 ChA Vthr13
    "V",	// ADC0 ChB Vzero
    "V",	// ADC0 ChC Vhalf
    "V",	// ADC0 ChD Vfull

    "V",	// ADC1 Ch0 Vthr12
    "V",	// ADC1 Ch1 Vthr11
    "V",	// ADC1 Ch2 Vthr10
    "V",	// ADC1 Ch3 Vthr9
    "V",	// ADC1 Ch4 Vthr8
    "V",	// ADC1 Ch5 Vthr7
    "V",	// ADC1 Ch6 Vthr6
    "V",	// ADC1 Ch7 Vthr5
    "V",	// ADC1 Ch8 Vthr4
    "V",	// ADC1 Ch9 Vthr3
    "V",	// ADC1 ChA Vthr2
    "V",	// ADC1 ChB Vzero
    "V",	// ADC1 ChC Vhalf
    "V",	// ADC1 ChD Vfull

    "V",	// ADC2 Ch0 Vthr1
    "V",	// ADC2 Ch1 Vthr0
    "A",	// ADC2 Ch2 +1.8A
    "A",	// ADC2 Ch3 +3.3A
    "A",	// ADC2 Ch4 +5.5A1
    "A",	// ADC2 Ch5 +5.5A2
    "V",	// ADC2 Ch6 +1.8V
    "V",	// ADC2 Ch7 +3.3V
    "V",	// ADC2 Ch8 +5.5V1
    "V",	// ADC2 Ch9 +5.5V2
    "C",	// ADC2 ChA Temp
    "V",	// ADC2 ChB Vzero
    "V",	// ADC2 ChC Vhalf
    "V",	// ADC2 ChD Vfull

    "V",	// ADC3 Ch0 Vthr
    "V",	// ADC3 Ch1 Vthr
    "V",	// ADC3 Ch2 Vthr
    "V",	// ADC3 Ch3 Vthr
    "V",	// ADC3 Ch4 Vthr
    "V",	// ADC3 Ch5 Vthr
    "V",	// ADC3 Ch6 Vthr
    "V",	// ADC3 Ch7 Vthr
    "V",	// ADC3 Ch8 Vthr
    "V",	// ADC3 Ch9 Vthr
    "V",	// ADC3 ChA Vthr
    "V",	// ADC3 ChB Vzero
    "V",	// ADC3 ChC Vhalf
    "V",	// ADC3 ChD Vfull

    "V",	// ADC4 Ch0 Vthr
    "V",	// ADC4 Ch1 Vthr
    "V",	// ADC4 Ch2 Vthr
    "V",	// ADC4 Ch3 Vthr
    "V",	// ADC4 Ch4 Vthr
    "V",	// ADC4 Ch5 Vthr
    "V",	// ADC4 Ch6 Vthr
    "V",	// ADC4 Ch7 Vthr
    "V",	// ADC4 Ch8 Vthr
    "V",	// ADC4 Ch9 Vthr
    "V",	// ADC4 ChA Temp
    "V",	// ADC4 ChB Vzero
    "V",	// ADC4 ChC Vhalf
    "V"		// ADC4 ChD Vfull
};

double			adc_ch_scale[5][14]=
{
    1.0,	// ADC0 Ch0 Vthr23
    1.0,	// ADC0 Ch1 Vthr22
    1.0,	// ADC0 Ch2 Vthr21
    1.0,	// ADC0 Ch3 Vthr20
    1.0,	// ADC0 Ch4 Vthr19
    1.0,	// ADC0 Ch5 Vthr18
    1.0,	// ADC0 Ch6 Vthr17
    1.0,	// ADC0 Ch7 Vthr16
    1.0,	// ADC0 Ch8 Vthr15
    1.0,	// ADC0 Ch9 Vthr14
    1.0,	// ADC0 ChA Vthr13
    1.0,	// ADC0 ChB Vzero 
    1.0,	// ADC0 ChC Vhalf 
    1.0,	// ADC0 ChD Vfull 

    1.0,	// ADC1 Ch0 Vthr12
    1.0,	// ADC1 Ch1 Vthr11
    1.0,	// ADC1 Ch2 Vthr10
    1.0,	// ADC1 Ch3 Vthr9 
    1.0,	// ADC1 Ch4 Vthr8 
    1.0,	// ADC1 Ch5 Vthr7 
    1.0,	// ADC1 Ch6 Vthr6 
    1.0,	// ADC1 Ch7 Vthr5 
    1.0,	// ADC1 Ch8 Vthr4 
    1.0,	// ADC1 Ch9 Vthr3 
    1.0,	// ADC1 ChA Vthr2 
    1.0,	// ADC1 ChB Vzero 
    1.0,	// ADC1 ChC Vhalf 
    1.0,	// ADC1 ChD Vfull 

    1.0,	// ADC2 Ch0 Vthr1
    1.0,	// ADC2 Ch1 Vthr0
    2.5,	// ADC2 Ch2 +1.8A
    2.5,	// ADC2 Ch3 +3.3A
    2.5,	// ADC2 Ch4 +5.5A1
    2.5,	// ADC2 Ch5 +5.5A2
    4.9,	// ADC2 Ch6 +1.8V
    4.9,	// ADC2 Ch7 +3.3V
    4.9,	// ADC2 Ch8 +5.5V1
    4.9,	// ADC2 Ch9 +5.5V2
    100.,	// ADC2 ChA Temp
    1.0,	// ADC2 ChB Vzero
    1.0,	// ADC2 ChC Vhalf
    1.0,	// ADC2 ChD Vfull

    1.0,	// ADC3 Ch0 Vthr
    1.0,	// ADC3 Ch1 Vthr
    1.0,	// ADC3 Ch2 Vthr
    1.0,	// ADC3 Ch3 Vthr
    1.0,	// ADC3 Ch4 Vthr
    1.0,	// ADC3 Ch5 Vthr
    1.0,	// ADC3 Ch6 Vthr
    1.0,	// ADC3 Ch7 Vthr
    1.0,	// ADC3 Ch8 Vthr
    1.0,	// ADC3 Ch9 Vthr
    1.0,	// ADC3 ChA Vthr
    1.0,	// ADC3 ChB Vzero 
    1.0,	// ADC3 ChC Vhalf 
    1.0,	// ADC3 ChD Vfull

    1.0,	// ADC4 Ch0 Vthr
    1.0,	// ADC4 Ch1 Vthr
    1.0,	// ADC4 Ch2 Vthr
    1.0,	// ADC4 Ch3 Vthr
    1.0,	// ADC4 Ch4 Vthr
    1.0,	// ADC4 Ch5 Vthr
    1.0,	// ADC4 Ch6 Vthr
    1.0,	// ADC4 Ch7 Vthr
    1.0,	// ADC4 Ch8 Vthr
    1.0,	// ADC4 Ch9 Vthr
    1.0,	// ADC4 ChA Vthr
    1.0,	// ADC4 ChB Vzero 
    1.0,	// ADC4 ChC Vhalf 
    1.0		// ADC4 ChD Vfull
};


//int				opcode;
int				opcode_rd;
int				opcode_wr;

//--------------------------------------------------------------------------------
//	Count 0s in a bit array
//--------------------------------------------------------------------------------
int count0s(char tdo[], int &nbits)
{
    int zeros;
    int i;
    zeros=0;

    for (i=0; i<nbits; ++i) if (tdo[i]==0) zeros++;

    return zeros;
}

//--------------------------------------------------------------------------------
//	Count 1s in a bit array
//--------------------------------------------------------------------------------
	int count1s(char tdo[], int &nbits)
{
	int ones;
	int i;
	ones=0;

	for (i=0; i<nbits; ++i) if (tdo[i]==1) ones++;

	return ones;
}
