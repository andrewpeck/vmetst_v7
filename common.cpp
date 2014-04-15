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
const int		mxbitstream=1000;	// Max # bits in a jtag cycle (1000 in alct_tst, was 200 in vmetst)

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
    { 6,16,16, 0, 0}		// 7 TMB  Spartan6 mez chain	FPGA, PROM, PROM
    { 6, 0, 0, 0, 0}};		// 8 ALCT Slow control chain	User JTAG

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


//------------------------------------------------------------------------------
//	ALCT384 Tests Using TMB+RAT
//------------------------------------------------------------------------------
//	04/12/2012	Initial
//	04/23/2012	Add single cable test
//	05/02/2012	Add ALCT digital serial number readout
//	05/07/2012	Add ADB hit list and CRC error readout
//	05/08/2012	Add single cable test patterns
//	06/20/2012	Add slow control FPGA walking 1
//	06/25/2012	Add fpga bit toggle
//	06/26/2012	Replace walking 1 with walking 0
//	06/27/2012	Add slow control menu
//	06/28/2012	Add slow control DAC
//	07/02/2012	Add slow control ADC
//	07/03/2012	Add wait between ADC conversions
//	07/05/2012	Add ADC difference plots
//	07/06/2012	Add opcode and idreg bang modes
//	07/11/2012	Add jtag verilog output for simulator
//	07/18/2012	Add the rest of the slow control registers
//	10/31/2012	Add test pulse fire
//	01/11/2013	Add full auto tests
//
//------------------------------------------------------------------------------
//	Slow Control: Walking 0 firmware
//
//	Opcode[5:0]
//	0x01	DR[215:0]	Read  IO pins, dr[215:212]=0xE, dr[211:4]=pin[208:1], dr[3:0]=0xB
//	0x02	DR[215:0]	Write IO pins, dr[215:212]=0xX, dr[211:4]=pin[208:1], dr[3:0]=0xX
//
//------------------------------------------------------------------------------
//	Slow Control: Normal-running Firmware
//
//	6-bit Opcodes
//
//	Opcode	Name		Length		Description
//------------------------------------------------------------------------------
//	0x00	rd_id_code		40		Read  Firmware date code
//	0x01	wr_dac_rs		4		Reset Threshold DACs
//	0x03	wr_vga			8		Write Test Pulse variable gain amplifier
//
//	0x08	wr_dac[0]		12		Write Threshold DAC0  
//	0x09	wr_dac[1]		12		Write Threshold DAC1
//	0x0A	wr_dac[2]		12		Write Threshold DAC2
//	0x0B	wr_dac[3]		12		Write Threshold DAC3
//
//	0x10	rd_adc[0]		11		Write channel address and read back ADC0
//	0x11	rd_adc[1]		11		Write channel address and read back ADC1
//	0x12	rd_adc[2] 		11		Write channel address and read back ADC2
//	0x13	rd_adc[3]		11		Write channel address and read back ADC3
//	0x14	rd_adc[4]		11		Write channel address and read back ADC4
//
//	0x20	wr_tp_group		7		Write Test pulse group enables
//	0x21	rd_tp_group		7		Read  Test pulse group enables
//
//	0x22	wr_tp_strip		6		Write Test pulse strip enables
//	0x23	rd_tp_strip		6		Read  Test pulse strip enables
//
//	0x24	wr_standby		42		Write Standby register
//	0x25	rd_standby		42		Read  Standby register
//
//	0x26	wr_vga_pd		1		Write variable gain amplifier power down 1=up,0=dn
//	0x27	rd_vga_pd 		1		Read  variable gain amplifier power down 1=up,0=dn
//
//	Others	bypass			1		Pass  tdi --> tdo
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Common
//------------------------------------------------------------------------------
	FILE			*log_file;
	FILE			*unit;

	const int		mxframe	= 8192;		// Max raw hits frame number, scope adds 512*160/16=5120 frames
	const int		mxtbins	= 32;		// Highest time bin, 0 implies 32
	const int		mxly	= 6;		// # CSC Layers
	const int		mxds	= 8;		// # DiStrips per CFEB
	const int		mxdsabs	= 40;		// # DiStrips per CSC
	const int		mxcfeb	= 5;		// # CFEBs
	const int		mxbitstream=1000;	// Max # bits in a jtag cycle

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

// Common/adc_common/
	double			adc_voltage[14];
	double			v5p0;
	double			v3p3;
	double			v1p5core;
	double			vcore_expect;
	double			vcore_noload;
	double			v1p5tt;
	double			v1p0;
	double			v1p0_expect;
	double			a5p0;
	double			a3p3;
	double			a1p5core;
	double			a1p5tt;
	double			a3p3rat;
	double			a1p8rat;
	double			v3p3rat;
	double			v1p8rat;
	double			vref2;
	double			vzero;
	double			vref;

// Common/adc_common_mez/
	double			adc_voltage_mez[14];
	double			v3p3_mez;
	double			v2p5_mez;
	double			vcore_mez;
	double			v1p8_mez;
	double			v1p2_mez;
	double			tfpga_mez;
	double			tsink_mez;
	double			vch07_mez;
	double			vch08_mez;
	double			vch09_mez;
	double			vch10_mez;
	double			vref2_mez;
	double			vzero_mez;
	double			vref_mez;

// Common/portsf_common/
	const int		setport_mxnwords = 4096;
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
	bool			wlog;
	int				numwrites;
	int				numreads;

// Common/jtag_common/
	FILE			*jtag_file;
	bool			jtaglogmode;

//	Common/TMB_VME_addresses
	unsigned long		base_adr;
	const unsigned long	tmb_global_slot			= 26;
	const unsigned long	tmb_brcst_slot			= 27;
	const unsigned long	tmb_boot_adr			= 0x070000;
	//------------------------------------------------------------------------------
	const unsigned long	vme_idreg_adr			= 0x000000;	// For tmb2005 and bdtest_v5
	const unsigned long	vme_status_adr			= 0x000008;
	const unsigned long	vme_adr0_adr			= 0x00000A;
	const unsigned long	vme_adr1_adr			= 0x00000C;
	const unsigned long	vme_loopbk_adr			= 0x00000E;

	const unsigned long	vme_usr_jtag_adr		= 0x000010;
	const unsigned long	vme_prom_adr			= 0x000012;

	const unsigned long	vme_dddsm_adr			= 0x000014;
	const unsigned long	vme_ddd0_adr			= 0x000016;
	const unsigned long	vme_ddd1_adr			= 0x000018;
	const unsigned long	vme_ddd2_adr			= 0x00001A;
	const unsigned long	vme_dddoe_adr			= 0x00001C;
	const unsigned long	vme_ratctrl_adr			= 0x00001E;

	const unsigned long	vme_step_adr			= 0x000020;
	const unsigned long	vme_led_adr				= 0x000022;
	const unsigned long	vme_adc_adr				= 0x000024;
	const unsigned long	vme_dsn_adr				= 0x000026;
	//------------------------------------------------------------------------------
	const unsigned long	mod_cfg_adr				= 0x000028;	// For tmb2005 normal firmware
	const unsigned long	ccb_cfg_adr				= 0x00002A;
	const unsigned long	ccb_trig_adr			= 0x00002C;
	const unsigned long	ccb_stat0_adr			= 0x00002E;
	const unsigned long	alct_cfg_adr			= 0x000030;
	const unsigned long	alct_inj_adr			= 0x000032;
	const unsigned long	alct0_inj_adr			= 0x000034;
	const unsigned long	alct1_inj_adr			= 0x000036;
	const unsigned long	alct_stat_adr			= 0x000038;
	const unsigned long	alct_alct0_adr			= 0x00003A;
	const unsigned long	alct_alct1_adr			= 0x00003C;
	const unsigned long	alct_fifo_adr			= 0x00003E;
	const unsigned long	dmb_mon_adr				= 0x000040;
	const unsigned long	cfeb_inj_adr			= 0x000042;
	const unsigned long	cfeb_inj_adr_adr		= 0x000044;
	const unsigned long	cfeb_inj_wdata_adr		= 0x000046;
	const unsigned long	cfeb_inj_rdata_adr		= 0x000048;
	const unsigned long	hcm001_adr				= 0x00004A;
	const unsigned long	hcm023_adr				= 0x00004C;
	const unsigned long	hcm045_adr				= 0x00004E;
	const unsigned long	hcm101_adr				= 0x000050;
	const unsigned long	hcm123_adr				= 0x000052;
	const unsigned long	hcm145_adr				= 0x000054;
	const unsigned long	hcm201_adr				= 0x000056;
	const unsigned long	hcm223_adr				= 0x000058;
	const unsigned long	hcm245_adr				= 0x00005A;
	const unsigned long	hcm301_adr				= 0x00005C;
	const unsigned long	hcm323_adr				= 0x00005E;
	const unsigned long	hcm345_adr				= 0x000060;
	const unsigned long	hcm401_adr				= 0x000062;
	const unsigned long	hcm423_adr				= 0x000064;
	const unsigned long	hcm445_adr				= 0x000066;
	const unsigned long	seq_trig_en_adr			= 0x000068;
	const unsigned long	seq_trig_dly0_adr		= 0x00006A;
	const unsigned long	seq_trig_dly1_adr		= 0x00006C;
	const unsigned long	seq_id_adr				= 0x00006E;
	const unsigned long	seq_clct_adr			= 0x000070;
	const unsigned long	seq_fifo_adr			= 0x000072;
	const unsigned long	seq_l1a_adr				= 0x000074;
	const unsigned long	seq_offset0_adr			= 0x000076;
	const unsigned long	seq_clct0_adr			= 0x000078;
	const unsigned long	seq_clct1_adr			= 0x00007A;
	const unsigned long	seq_trig_src_adr		= 0x00007C;
	const unsigned long	dmb_ram_adr				= 0x00007E;
	const unsigned long	dmb_wdata_adr			= 0x000080;
	const unsigned long	dmb_wdcnt_adr			= 0x000082;
	const unsigned long	dmb_rdata_adr			= 0x000084;
	const unsigned long	tmb_trig_adr			= 0x000086;
	const unsigned long	mpc0_frame0_adr			= 0x000088;
	const unsigned long	mpc0_frame1_adr			= 0x00008A;
	const unsigned long	mpc1_frame0_adr			= 0x00008C;
	const unsigned long	mpc1_frame1_adr			= 0x00008E;
	const unsigned long	mpc_inj_adr				= 0x000090;
	const unsigned long	mpc_ram_adr				= 0x000092;
	const unsigned long	mpc_ram_wdata_adr		= 0x000094;
	const unsigned long	mpc_ram_rdata_adr		= 0x000096;
	unsigned long		scp_ctrl_adr			= 0x000098;
	unsigned long		scp_rdata_adr			= 0x00009A;
	const unsigned long	ccb_cmd_adr				= 0x00009C;

	const unsigned long	buf_stat0_adr			= 0x00009E;
	const unsigned long	buf_stat1_adr			= 0x0000A0;
	const unsigned long	buf_stat2_adr			= 0x0000A2;
	const unsigned long	buf_stat3_adr			= 0x0000A4;
	const unsigned long	buf_stat4_adr			= 0x0000A6;
	const unsigned long	alctfifo1_adr			= 0x0000A8;
	const unsigned long	alctfifo2_adr			= 0x0000AA;
	const unsigned long	seqmod_adr				= 0x0000AC;
	const unsigned long	seqsm_adr				= 0x0000AE;
	const unsigned long	seq_clctm_adr			= 0x0000B0;
	const unsigned long	tmbtim_adr				= 0x0000B2;
	const unsigned long	lhc_cycle_adr			= 0x0000B4;
	const unsigned long	rpc_cfg_adr				= 0x0000B6;
	const unsigned long	rpc_rdata_adr			= 0x0000B8;
	const unsigned long	rpc_raw_delay_adr		= 0x0000BA;
	const unsigned long	rpc_inj_adr				= 0x0000BC;
	const unsigned long	rpc_inj_adr_adr			= 0x0000BE;
	const unsigned long	rpc_inj_wdata_adr		= 0x0000C0;
	const unsigned long	rpc_inj_rdata_adr		= 0x0000C2;
	const unsigned long	rpc_tbins_adr			= 0x0000C4;
	const unsigned long	rpc_rpc0_hcm_adr		= 0x0000C6;
	const unsigned long	rpc_rpc1_hcm_adr		= 0x0000C8;
	const unsigned long	bx0_delay_adr			= 0x0000CA;
	const unsigned long	non_trig_adr			= 0x0000CC;
	const unsigned long	scp_trig_adr			= 0x0000CE;
	const unsigned long	cnt_ctrl_adr			= 0x0000D0;
	const unsigned long	cnt_rdata_adr			= 0x0000D2;

	const unsigned long	jtagsm0_adr				= 0x0000D4;
	const unsigned long	jtagsm1_adr				= 0x0000D6;
	const unsigned long	jtagsm2_adr				= 0x0000D8;

	const unsigned long	vmesm0_adr				= 0x0000DA;
	const unsigned long	vmesm1_adr				= 0x0000DC;
	const unsigned long	vmesm2_adr				= 0x0000DE;
	const unsigned long	vmesm3_adr				= 0x0000E0;
	const unsigned long	vmesm4_adr				= 0x0000E2;

	const unsigned long	dddrsm_adr				= 0x0000E4;
	const unsigned long	dddr0_adr				= 0x0000E6;

	const unsigned long	uptimer_adr				= 0x0000E8;
	const unsigned long	bdstatus_adr			= 0x0000EA;

	const unsigned long	bxn_clct_adr			= 0x0000EC;
	const unsigned long	bxn_alct_adr			= 0x0000EE;

	const unsigned long	layer_trig_adr			= 0x0000F0;
	const unsigned long	ise_version_adr			= 0x0000F2;

	const unsigned long	temp0_adr				= 0x0000F4;
	const unsigned long	temp1_adr				= 0x0000F6;
	const unsigned long	temp2_adr				= 0x0000F8;

	const unsigned long	parity_adr				= 0x0000FA;
	const unsigned long	ccb_stat1_adr			= 0x0000FC;
	const unsigned long	bxn_l1a_adr				= 0x0000FE;
	const unsigned long	l1a_lookback_adr		= 0x000100;
	const unsigned long	seq_debug_adr			= 0x000102;

	const unsigned long	alct_sync_ctrl_adr		= 0x000104;	// ALCT sync mode control
	const unsigned long	alct_sync_txdata_1st	= 0x000106;	// ALCT sync mode transmit data, 1st in time
	const unsigned long	alct_sync_txdata_2nd	= 0x000108;	// ALCT sync mode transmit data, 2nd in time

	const unsigned long	seq_offset1_adr			= 0x00010A;
	const unsigned long	miniscope_adr			= 0x00010C;

	const unsigned long	phaser0_adr				= 0x00010E;
	const unsigned long	phaser1_adr				= 0x000110;
	const unsigned long	phaser2_adr				= 0x000112;
	const unsigned long	phaser3_adr				= 0x000114;
	const unsigned long	phaser4_adr				= 0x000116;
	const unsigned long	phaser5_adr				= 0x000118;
	const unsigned long	phaser6_adr				= 0x00011A;

	const unsigned long	delay0_int_adr			= 0x00011C;
	const unsigned long	delay1_int_adr			= 0x00011E;

	const unsigned long	sync_err_ctrl_adr		= 0x000120;	// Synchronization Error Control

	const unsigned long	cfeb_badbits_ctrl_adr	= 0x000122;	// CFEB  Bad Bit Control/Status
	const unsigned long	cfeb_badbits_timer_adr	= 0x000124;	// CFEB  Bad Bit Check Interval

	const unsigned long	cfeb0_badbits_ly01_adr	= 0x000126;	// CFEB0 Bad Bit Array
	const unsigned long	cfeb0_badbits_ly23_adr	= 0x000128;	// CFEB0 Bad Bit Array
	const unsigned long	cfeb0_badbits_ly45_adr	= 0x00012A;	// CFEB0 Bad Bit Array

	const unsigned long	cfeb1_badbits_ly01_adr	= 0x00012C;	// CFEB1 Bad Bit Array
	const unsigned long	cfeb1_badbits_ly23_adr	= 0x00012E;	// CFEB1 Bad Bit Array
	const unsigned long	cfeb1_badbits_ly45_adr	= 0x000130;	// CFEB1 Bad Bit Array

	const unsigned long	cfeb2_badbits_ly01_adr	= 0x000132;	// CFEB2 Bad Bit Array
	const unsigned long	cfeb2_badbits_ly23_adr	= 0x000134;	// CFEB2 Bad Bit Array
	const unsigned long	cfeb2_badbits_ly45_adr	= 0x000136;	// CFEB2 Bad Bit Array

	const unsigned long	cfeb3_badbits_ly01_adr	= 0x000138;	// CFEB3 Bad Bit Array
	const unsigned long	cfeb3_badbits_ly23_adr	= 0x00013A;	// CFEB3 Bad Bit Array
	const unsigned long	cfeb3_badbits_ly45_adr	= 0x00013C;	// CFEB3 Bad Bit Array

	const unsigned long	cfeb4_badbits_ly01_adr	= 0x00013E;	// CFEB4 Bad Bit Array
	const unsigned long	cfeb4_badbits_ly23_adr	= 0x000140;	// CFEB4 Bad Bit Array
	const unsigned long	cfeb4_badbits_ly45_adr	= 0x000142;	// CFEB4 Bad Bit Array

	const unsigned long	last_vme_adr			= 0x00011E;	// Last valid address instantiated
	//------------------------------------------------------------------------------
	const unsigned long	vme_gpio_adr			= 0x000028;	// For bdtestv3
	const unsigned long	vme_cfg_adr				= 0x00002A;

	const unsigned long	cfeb0a_adr				= 0x00002C;	// Repeats 2C-48 for CFEBs1-4
	const unsigned long	cfeb0b_adr				= 0x00002E;
	const unsigned long	cfeb0c_adr				= 0x000030;
	const unsigned long	cfeb_offset_adr			= 0x000006;

	const unsigned long	alct_rxa_adr			= 0x00004A;
	const unsigned long	alct_rxb_adr			= 0x00004C;
	const unsigned long	alct_rxc_adr			= 0x00004E;
	const unsigned long	alct_rxd_adr			= 0x000050;

	const unsigned long	dmb_rxa_adr				= 0x000052;
	const unsigned long	dmb_rxb_adr				= 0x000054;
	const unsigned long	dmb_rxc_adr				= 0x000056;
	const unsigned long	dmb_rxd_adr				= 0x000058;

	const unsigned long	mpc_rxa_adr				= 0x00005A;
	const unsigned long	mpc_rxb_adr				= 0x00005C;

	const unsigned long	rpc_rxa_adr				= 0x00005E;
	const unsigned long	rpc_rxb_adr				= 0x000060;
	const unsigned long	rpc_rxc_adr				= 0x000062;
	const unsigned long	rpc_rxd_adr				= 0x000064;
	const unsigned long	rpc_rxe_adr				= 0x000066;
	const unsigned long	rpc_rxf_adr				= 0x000068;

	const unsigned long	ccb_rxa_adr				= 0x00006A;
	const unsigned long	ccb_rxb_adr				= 0x00006C;
	const unsigned long	ccb_rxc_adr				= 0x00006E;
	const unsigned long	ccb_rxd_adr				= 0x000070;

	const unsigned long	alct_txa_adr			= 0x000072;
	const unsigned long	alct_txb_adr			= 0x000074;

	const unsigned long	rpc_txa_adr				= 0x000076;
	const unsigned long	rpc_txb_adr				= 0x000078;

	const unsigned long	dmb_txa_adr				= 0x00007A;
	const unsigned long	dmb_txb_adr				= 0x00007C;
	const unsigned long	dmb_txc_adr				= 0x00007E;
	const unsigned long	dmb_txd_adr				= 0x000080;

	const unsigned long	mpc_txa_adr				= 0x000082;
	const unsigned long	mpc_txb_adr				= 0x000084;

	const unsigned long	ccb_txa_adr				= 0x000086;
	const unsigned long	ccb_txb_adr				= 0x000088;

	const unsigned long	heater_adr				= 0x00008A;	// Last bdtestv3 address instantiated

//------------------------------------------------------------------------------
//	Prototypes
//------------------------------------------------------------------------------
	#define			logical(L)		((L)?'T':'F')
	#define			yesno(L)		((L)?'y':'n')
	void			pause			(string s);
	void			stop			(string s);
	void			sleep			(clock_t msec);
	bool			pass_fail		(string prompt);

	void			ddd_wr			(unsigned long &base_adr, const int &ddd_chip, const int &ddd_channel, const int &ddd_delay);
	int				ddd_rd			(unsigned long &base_adr, const int &ddd_chip, const int &ddd_channel);
	void			dsn_rd			(unsigned long &vme_dsn_adr, const int &itype, int dsn[]);
	void			dsn_rd_alct		(unsigned long &adr, int &ichain, int &chip_id, int &opcode_rd, int &opcode_wr, int &reg_len, const int &itype, int dsn[]);
	void			idcode_decode	(long &idcode, string &sdevice_type, string &sdevice_name, string &sdevice_version, string &sdevice_size);
	void			dow_crc			(int in[7], int &crc);

	void			phaser_wr		(unsigned long &base_adr, const string phaser_bank, const int &phaser_delay, const int &phaser_delta);
	int				phaser_rd		(unsigned long &base_adr, const string phaser_bank, const int &phaser_delta);
	void			posneg_wr		(unsigned long &base_adr, const string phaser_bank, const int &posneg);
	int				posneg_rd		(unsigned long &base_adr, const string phaser_bank);
	int				dddstr_rd		(unsigned long &base_adr, const string ddd_delay);
	int				cfebbx_rd		(unsigned long &base_adr, const string nbx_delay);

	void			adc_read		(unsigned long &base_adr);
	void			adc_read_alct	(unsigned long &adr, int &ichain, int &chip_id, int &opcode_rd, int &opcode_wr, int &reg_len);
	void			aok				(string msg_string);
	void			aokf			(string msg_string, const int itest, const int status);	
	void			ck				(string data_string, int data_read, int data_expect);
	int				cks				(string data_string, int data_read, int data_expect);
	void			tok				(string msg_string, double fdata_read, double fdata_expect, double tolerance, int &status);
	int				count0s			(char tdo[], int &nbits);
	int				count1s			(char tdo[], int &nbits);

	void			inquire			(string prompt, const int &minv, const int &maxv, const int &radix, int &now);
	void			inquir2			(string prompt, const int &minv, const int &maxv, const int &radix, int &num, int &now);
	void			inquirl			(string prompt, const int &minv, const int &maxv, const int &radix, long int &now);
	void			inquirb			(string prompt, bool &now);

	long int		vme_open		();
	long int		vme_read		(unsigned long &adr, unsigned short &rd_data);
	long int		vme_write		(unsigned long &adr, unsigned short &wr_data);
	long int		vme_sysreset	();
	long int		vme_close		();
	long int		vme_errs		(const int &print_mode);

	void			i4_to_tdi		(long int &i4, char  tdi[], const int &nbits, const int &spi);
	void			tdi_to_i4		(char  tdi[], long int &i4, const int &nbits, const int &spi);
	void			bit_to_array	(const int &idata, int iarray[], const int &n);

	int				xsvfExecute		();
	void			setPort			(short int p, short int val);
	unsigned char	readTDOBit		();

	void			vme_jtag_anystate_to_rti(unsigned long &adr, int &ichain);
	void			vme_jtag_write_ir		(unsigned long &adr, int &ichain, int &chip_id, int &opcode);
	void			vme_jtag_write_dr		(unsigned long &adr, int &ichain, int &chip_id, char wr_data[], char rd_data[], int &nbits);
	bool			vme_jtag_cable_detect	(unsigned long &base_adr);

//------------------------------------------------------------------------------
// File scope declarations
//------------------------------------------------------------------------------
// JTAG stream
	char			tdi[mxbitstream]={0};
	char			tdo[mxbitstream]={0};

// VME calls
	long			status;
//	unsigned long	base_adr;
	unsigned long	boot_adr;
	unsigned long	adr;
	unsigned short	rd_data;
	unsigned short	wr_data;

//------------------------------------------------------------------------------
// Event counters
//------------------------------------------------------------------------------
	const int		mxcounter = 79;
	int				cnt_lsb;
	int				cnt_msb;
	int				cnt_full;
	int				cnt[mxcounter];
	string			scnt[mxcounter];

//------------------------------------------------------------------------------
// Local
//------------------------------------------------------------------------------
	int				islot;
	int				islot_old;
	int				newslot;
	int				geo_adr;

// ID reg
	int				id_rev;
	int				id_rev_day;
	int				id_rev_month;
	int				id_rev_year;
	int				id_rev_fpga;

	int				id_slot;
	int				id_ver;
	int				id_type;
	int				id_month;
	int				id_day;
	int				id_year;

	int				id_reg[4];
	int				id_reg_save[4];

// Firmware
	unsigned short	tmb_firmware_type;
	unsigned short	tmb_firmware_series;
	unsigned short	tmb_firmware_normal		  = 0xC;
	unsigned short	tmb_firmware_debug		  = 0xD;
	unsigned short	tmb_firmware_series_etype = 0xE;

	unsigned short	ise_version;
	unsigned short	ise_sub;
	unsigned short	ise_sp;

	char			timestr[9];
	char			datestr[9];

	string			tmb_type;
	string			tmb_fpga_series;
	string			tmb_firmware_name;
	string			scomputer_name;

// Menu
	char			line[80];
	int				ifunc;
	int				i,j,k,n;

// Peek/poke
	char			rwe;
	unsigned long	newadr;
	unsigned long	newdata;

	int				nbang;
	int				ibang;
	bool			bang_read  = false;
	bool			bang_write = false;

// Debug
	bool			debug_loop;
	bool			debug_step;
	bool			debug_beep;

// ALCT single cable test
	int				itest;
	int				itest_first;
	int				itest_last;
	int				ipass;
	int				ipf;
	int				npasses;
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

	string			salct_fpga;
	string			sok;

	bool			iprint;
	bool			ifail;
	bool			adb_auto;
	bool			adb_passed[24];

	const int		alct_ntests=90;
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
	string			ipin_name[208+1];
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
	bool			bans;
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
	bool			debug;

	int				iadc;
	int				adc_ch;
	int				adc_adr;
	int				adc_word;
	int				adc_data[4][14+1];
	int				iadc_driven;
	int				adc_ch_driven;
	int				adc_value[24][256];
	int				opcode0=0;

	int				bad_thr[24];
	int				nerrors;
	int				ncycles;
	int				icycle;
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

	string			adc_ch_name[5][14]=
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

	string			adc_ch_unit[5][14]=
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

// Trigger tests
	int				dmb_thresh_pretrig;
	int				hit_thresh_pretrig;
	int				hit_thresh_postdrift;
	int				pid_thresh_pretrig;
	int				pid_thresh_postdrift;
	int				lyr_thresh_pretrig;

	int				triad_persist;
	int				drift_delay;
	int				clct_sep;
	int				active_feb_src;
	int				active_feb_list;

	bool			layer_mode;
	int				layer_trig_en;

	int				fifo_mode;
	int				fifo_tbins;
	int				fifo_pretrig;

	int				fifo_tbins_rpc;
	int				fifo_pretrig_rpc;
	int				rpc_decouple;

	int				alct_bx0_en;
	int				alct_delay;
	int				clct_width;

	int				tmb_allow_clct;
	int				tmb_allow_alct;
	int				tmb_allow_match;

	int				tmb_allow_alct_ro;
	int				tmb_allow_clct_ro;
	int				tmb_allow_match_ro;

	int				inj_delay_rat;
	int				rpc_tbins_test;
	int				rpc_exists;

	bool			rrhd;
	bool			cprr;
	bool			cprr_ignore;
	bool			rat_injector_sync=false;
	bool			rat_injector_enable=true;
	bool			rpcs_in_rdout;
	bool			pause_on_fail;
	int				vme_bx0_emu_en_default=1;

	int				nclcts_inject=1;
	int				nalcts_inject=1;
	int				mcl;

	const int		mxclcts=8;
	int				clct_pat_inject[mxclcts];
	int				clct_pid_inject[mxclcts];
	int				clct_key_inject[mxclcts];
	int				clct_hit_inject[mxclcts];
	bool			clct_blanked[mxclcts];
	int				clct_hit_inject_clip[mxclcts];
	bool			loop_keys[mxclcts];
	bool			loop_pids[mxclcts];
	int				iclct;

	int				triad_1st_tbin[6]={0,0,0,0,0,0};
	int				l1a_delay=119;	// hits 0th l1a window bx
	int				rat_sync_mode;
	int				rat_injector_delay;

	int				irpc;
	int				ibxn;

	int				rpc_pad;
	int				rpc_inj_bxn;
	int				rpc_inj_image[256][2];
	int				rpc_inj_wen;
	int				rpc_inj_ren;
	int				rpc_inj_rwadr;
	int				rpc_inj_data;

// Scope
	bool			rdscope;
	int				scp_arm;
	int				scp_readout;
	int				scp_raw_decode;
	int				scp_silent;
	int				scp_raw_data[512*160/16];
	int				scp_auto;
	int				scp_nowrite;

// Misc
	int				boot_decode[16];
	unsigned short	boot_data;
	int				boot;
	long			mez_trig_reg;

// Pattern cells
	int				icell;
	int				ihit;
	int				ihitp;

	int				nhits;
	int				layer;

	int				ikey;
	int				ikeylp;
	int				ikey_min;
	int				ikey_max;
	int				ikey_sep;

	int				ipid;
	int				ipidlp;
	int				ipid_min;
	int				ipid_max;

	int				icfeb;
	int				icfebg;
	int				key;
	int				ihs[6][160];
	int				nstag;

	int				idistrip;
	int				idslocal;
	int				itbin;
	int				itbin0;
	int				ihstrip;
	int				iram;
	int				pat_ram[32][3][5]={0};
	int				wen;
	int				ren;
	int				wadr;
	int				febsel;
	int				icfeblp;
	int				ibit;
	int				wr_data_mem;
	int				rd_data_mem;

	string			marker="AOXOMOXOA";

//------------------------------------------------------------------------------
	int				alct_data;
	int				alct_tdo;
	int				alct_lsbs;
	int				alct_expect;
	int				alct_err;
	int				alct_id;
	int				alct_id_expect;
	int				ireg;
	int				alct_injector_delay=14;	// experimental

	string			rat_chip_type[2]={"FPGA","PROM"};
	long int		rat_user1[7];
	long int		rat_user2[1];
	int				rat_ctrl_data;

// RAT USER1 status register
	char			rs[224];
	long int		rs_begin;
	long int		rs_version;
	long int		rs_monthday;
	long int		rs_year;

	long int		rs_syncmode;
	long int		rs_posneg;
	long int		rs_loop;

	long int		rs_rpc_en;
	long int		rs_clk_active;

	long int		rs_locked_tmb;
	long int		rs_locked_rpc0;
	long int		rs_locked_rpc1;
	long int		rs_locklost_tmb;
	long int		rs_locklost_rpc0;
	long int		rs_locklost_rpc1;

	long int		rs_txok;
	long int		rs_rxok;

	long int		rs_ntcrit;
	long int		rs_rpc_free;

	long int		rs_dsn;
	long int		rs_dddoe_wr;
	long int		rs_ddd_wr;
	long int		rs_ddd_auto;
	long int		rs_ddd_start;
	long int		rs_ddd_busy;
	long int		rs_ddd_verify_ok;

	long int		rs_rpc0_parity_ok;
	long int		rs_rpc1_parity_ok;
	long int		rs_rpc0_cnt_perr;
	long int		rs_rpc1_cnt_perr;
	long int		rs_last_opcode;

	long int		rw_rpc_en;
	long int		rw_ddd_start;
	long int		rw_ddd_wr;
	long int		rw_dddoe_wr;
	long int		rw_perr_reset;
	long int		rw_parity_odd;
	long int		rw_perr_ignore;
	long int		rw_rpc_future;

	long int		rs_rpc0_pdata;
	long int		rs_rpc1_pdata;

	long int		rs_unused;
	long int		rs_end;

// ALCT jtag opcodes
	int				IDRead;
	int				HCMaskRead;
	int				HCMaskWrite;
	int				RdTrig;
	int				WrTrig;
	int				RdCfg;
	int				WrCfg;
	int				Wdly;
	int				Rdly;
	int				CollMaskRead;
	int				CollMaskWrite;
	int				ParamRegRead;
	int				ParamRegWrite;
	int				InputEnable;
	int				InputDisable;
	int				YRwrite;
	int				OSread;
	int				SNread;
	int				SNwrite0;
	int				SNwrite1;
	int				SNreset;
	int				Bypass;

	string			alct_chip_type[2]={"FPGA","PROM"};
	string			tmb_chip_type[5] ={"FPGA","PROM","PROM","PROM","PROM"};
	long int		alct_cfgreg[3];
	long int		alct_idreg[2];
	char			rsa[69];
	int				alct_sn[2];
	int				alct_dsn_crc;
	int				alct_dsn_mfg;
	int				alct_dsn;
	int				ilen;
	int				ival;
	int				ivalarray[69];

	int				alct0_rd;
	int				alct1_rd;
	int				alct0_prev;
	int				alct1_prev;

	long int		din;
	long int		crc;
	long int		tmb_crc_lsb;
	long int		tmb_crc_msb;
	long int		tmb_crc;
	bool			crc_match;

	long int		rsa_trig_mode;
	long int		rsa_ext_trig_en;
	long int		rsa_pretrig_halt;
	long int		rsa_inject;
	long int		rsa_inject_mode;
	long int		rsa_inject_mask;
	long int		rsa_nph_thresh;
	long int		rsa_nph_pattern;
	long int		rsa_drift_delay;
	long int		rsa_fifo_tbins;
	long int		rsa_fifo_pretrig;
	long int		rsa_fifo_mode;
	long int		rsa_fifo_lastlct;
	long int		rsa_l1a_delay;
	long int		rsa_l1a_window;
	long int		rsa_l1a_offset;
	long int		rsa_l1a_internal;
	long int		rsa_board_id;
	long int		rsa_bxn_offset;
	long int		rsa_ccb_enable;
	long int		rsa_alct_jtag_ds;
	long int		rsa_alct_tmode;
	long int		rsa_alct_amode;
	long int		rsa_alct_maskall;
	long int		rsa_trig_info_en;
	long int		rsa_sn_select;

	long int		rsa_chip_id;
	long int		rsa_version;
	long int		rsa_year;
	long int		rsa_day;
	long int		rsa_month;

	char			rsd[84];
	long int		alct_user1[3];
	long int		alct_user2[2];
	long int		rsd_begin;
	long int		rsd_version;
	long int		rsd_monthday;
	long int		rsd_year;
	long int		rsd_mc_done;
	long int		rsd_sc_done;
	long int		rsd_clock_lock;
	long int		rsd_clock_en;
	long int		rsd_cmd_align;
	long int		rsd_cmd_sync_mode;
	long int		rsd_sync_mode;
	long int		rsd_sync_rx_1st_ok;
	long int		rsd_sync_rx_2nd_ok;
	long int		rsd_alct_rx_1st;
	long int		rsd_alct_rx_2nd;
	long int		rsd_cmd_l1a_en;
	long int		rsd_cmd_trig_en;
	long int		rsd_tx_en0;
	long int		rsd_tx_en1;
	long int		rsd_cmd_dummy;
	long int		rsd_free0;
	long int		rsd_end;

	int				err_alct_fifo_clr;
	int				err_alct_lct0;
	int				err_alct_lct1;
	int				err_alct_fifo_busy;
	int				err_alct_fifo_ndone;
	int				err_alct_raw_nwords;
	int				err_firmware_crc;
	int				err_alct_crc;
	int				err_lct;
	int				err_sum;
	int				err_lct_cmp;
	int				alct0_keya;
	int				alct1_keya;
	int				alct0_keyb;
	int				alct1_keyb;
	int				ievent;
	int				itrig_src;

	int				rpc_data[38];
	int				rpc_data_1st[38];
	int				rpc_data_2nd[38];
	int				rpc_delay_default;
	int				bad_1st;
	int				bad_2nd;
	int				rpc_bad[16];
	int				nbad;
	double			pctbad;

	bool			rpc_err;
	int				loopbk;
	int				itx;
	int				ijtag_src;

	int				rpc_rx[4];
	int				rpc_bxn[4];
	int				rpc_word[4];

	int				rpc_rbxn[4];
	int				rpc_rdata[4];
	int				rpc0_rdata_expect[19];
	int				rpc1_rdata_expect[19];
	int				rpc2_rdata_expect[19];
	int				rpc3_rdata_expect[19];
	int				irat;

	bool			dmb_err;
	int				mpc_err;
	int				ccb_data[64];
	int				ccb_err;
	int				reg_err;
	int				vme_cfg;
	int				vme_data;
	int				irx;

	string			vstat_5p0v;
	string			vstat_3p3v;
	string			vstat_1p8v;
	string			vstat_1p5v;
	string			tcrit;
	string			ok[2]={"BAD","OK "};
	string			sidcode_good;
	string			rat_user1_string;

	long int		i4;
	int				adr_mode;
	int				loopstate;

	int				sel_boot_jtag;
	int				sel_boot_nojtag;
	int				sel_step_alct;
	int				sel_step_cfeb;
	int				sel_loopbk;

//	unsigned long	adc_adr;
	int				smb_adr;
	int				smb_cmd;
	int				smb_data;
	int				smb_data_tmb;
	int				smb_data_rat;

	int				opcode;
	int				opcode_rd;
	int				opcode_wr;
	int				reg_len;
	int				chip_id;
	int				nchips;
	long int		idcode;
	long int		usercode;
	int				user_idcode[2];
	int				ichain;
	int				idcode_v;
	int				idcode_f;
	int				idcode_a;
	int				idcode_c;

	string			sdevice_type;
	string			sdevice_name;
	string			sdevice_version;
	string			sdevice_size;

	const int		vme_mx_adr=254;
	int				vme_readback[vme_mx_adr];
	char			bell=7;

	int				icrc;
	int				itype;
	int				ichip;
	int				dsn_tmb[8];
	int				dsn_mez[8];
	int				dsn[8];
	string			dsn_chip[3]     ={"TMB ","TMEZ","RAT "};
	string			dsn_chip_alct[2]={"ALCT","AMEZ"};
	string			icrc_ok;

	int				dmb_wdcnt;
	int				dmb_busy;
	int				dmb_rdata;
	int				dmb_rdata_lsb;
	int				dmb_rdata_msb;

	int				cfeb_base;
	int				cfeb_data;
	int				cfeb_err;
	int				cfeb_id;
	int				cfeb_id_expect;

	int				iver;
	char			cfver[2+1];
	string			sfver;

	int				idsn;
	char			cdsn[7+1];
	char			cdsnfull[32+1];
	string			sdsn;

//	const int		mxframe=4096;		// Max raw hits frame number
	int				vf_data[mxframe];
	int				iframe;
	int				ilayer;

	int				adr_e0b;
	int				r_nheaders;
	int				r_ncfebs;
	int				r_fifo_tbins;
	int				nsamples;

	int				read_pat[mxtbins][mxly][mxdsabs];
	int				rdcid;
	int				rdtbin;
	int				hits8;
	int				hits1;
	int				ids;
	int				ids_abs;
	int				jcfeb;
	char			x[]="          ";
	bool			display_cfeb;

	int				cfeb_rxdata_1st[24];
	int				cfeb_rxdata_2nd[24];
	int				cfeb_rxdata_1st_remap[24];
	int				cfeb_rxdata_2nd_remap[24];
	int				cfeb_sync_rxdata_1st;
	int				cfeb_sync_rxdata_2nd;

	int				pat_expect;
	int				clct_bxn_expect;

	int				clct_key_expect[mxclcts];
	int				clct_pid_expect[mxclcts];
	int				clct_hit_expect[mxclcts];

	int				m0def;
	int				m1def;
	int				muon0[256];
	int				muon1[256];
	int				nfdef;
	int				nframes;
	int				mpc_ram_wrdata[4];

	int				mpc_accept0;
	int				mpc_accept1;
	int				mpc_reserved0;
	int				mpc_reserved1;
	int				mpc_delay;
	int				wr_marker;

	char			cid[1];
	char			cidc[8];
	char			cich[1];
	char			cvcore[5];
	string			sid;
	string			sidc;
	string			sich;
	string			svcore;

	int				iflocal;
	int				ifhsink;
	char			cflocal[3+1];
	char			cfhsink[3+1];
	string			sflocal;
	string			sfhsink;

	int				ccb_rx_bank0;
	int				ccb_rx_bank1;
	int				ccb_rx_bank2;
	int				ccb_rx_bank3;

	unsigned short	ccb_rxa;
	unsigned short	ccb_rxb;
	unsigned short	ccb_rxc;
	unsigned short	ccb_rxd;

	unsigned short	dmb_rxa;
	unsigned short	dmb_rxb;
	unsigned short	dmb_rxc;
	unsigned short	dmb_rxd;

	int				wr_pat;
	int				wr_pat_vlad;
	int				wr_pat_ck;

	unsigned short	mpc_rxa;
	unsigned short	mpc_rxb;
	int				mpc_rx_bank0;
	int				mpc_rx_bank1;

	unsigned short	rpc_rxa;
	unsigned short	rpc_rxb;
	unsigned short	rpc_rxc;
	unsigned short	rpc_rxd;
	unsigned short	rpc_rxe;
	unsigned short	rpc_rxf;

	int				rpc_rxh[38];
	int				rpc_clock;
	int				rd_ddd0;
	int				rpc_smbrx;
	int				rpc_rx_bank0;
	int				rpc_rx_bank1;
	int				rpc_rx3126;
	int				rpc_rxh0902;
	int				rpc_dsn;
	int				rpc_done;

	int				smb_clk;
	int				tck_rpc;
	int				tms_rpc;
	int				tdi_rpc;
	int				tdo_rpc;
	int				rpc_sync;
	int				rpc_posneg;
	int				rpc_loop_tm;
	int				sel_rpc_chain;

	int				jtag_alct;
	int				alct_tx_lo;
	int				adb_pulse_async;
	int				nhard_reset_alct;
	int				alct_tx_hi;
	int				alct_loop;
	int				alct_rxoe;
	int				alct_txoe;
	int				alct_clock_en;
	int				alct_clock;
	int				rpc_free_tx0;
	int				nhard_reset_rpc;

	int				ipass_full_auto;
	double			amptol;
	double			ttol;
	int				isource;

	int				clct_sm;
	int				read_sm;
	string			sclct_sm[6];
	string			sread_sm[22];

//	int				hit_thresh_pretrig_temp;
//	int				hit_thresh_postdrift_temp;

	int				fmm_state;
	string			sfmm_state[5]={"Startup","Resync ","Stop   ","WaitBXO","Run    "};

	bool			rdraw;
	int				nbxn0;
	int				ntrig;

	int				nperbank;
	int				ibank;
	int				alct_1st_bank[3];
	int				alct_2nd_bank[3];
	int				ifs;

	int				alct_raw_busy;
	int				alct_raw_done;
	int				alct_raw_nwords;
	int				alct_raw_data;

	int				alct0_raw_lsb;
	int				alct0_raw_msb;
	int				alct0_raw;

	int				alct1_raw_lsb;
	int				alct1_raw_msb;
	int				alct1_raw;

	string			dmb_chip[4]={"U28","U29","U30","U31"};
	string			rpc_chip[2]={"U42","U43"};

	int				prom_clk[2];
	int				prom_oe[2];
	int				prom_nce[2];
	int				iprom;
	int				jprom;
	int				prom_data;
	int				prom_src;
	int				prom_adr;

	int				wr_buf_ready;
	int				buf_stalled;
	int				buf_q_full;
	int				buf_q_empty;
	int				buf_q_ovf_err;
	int				buf_q_udf_err;
	int				buf_q_adr_err;
	int				buf_display;
	int				wr_buf_adr;
	int				buf_fence_dist;
	int				buf_fence_cnt;
	int				buf_fence_cnt_peak;
	int				buf_free_space;

	int				queue_full;
	int				queue_empty;
	int				queue_ovf;
	int				queue_udf;

	int				seqdeb_adr;
	int				seqdeb_rd_mux;
	unsigned long	deb_adr_diff;
	unsigned long	deb_wr_buf_adr;
	unsigned long	deb_buf_push_adr;
	unsigned long	deb_buf_pop_adr;
	unsigned long	deb_buf_push_data;
	unsigned long	deb_buf_pop_data;

	int				push_l1a_bxn_win;
	int				push_l1a_cnt_win;
	int				push_l1a_match_win;
	int				push_l1a_push_me;
	int				push_l1a_notmb;
	int				push_tmb_nol1a;
	int				push_wr_buf_avail;

	int				pop_l1a_bxn_win;
	int				pop_l1a_cnt_win;
	int				pop_l1a_match_win;
	int				pop_l1a_push_me;
	int				pop_l1a_notmb;
	int				pop_tmb_nol1a;
	int				pop_wr_buf_avail;

	int				crc_err;
	int				crc_err_old;

	int				rat_window_width;
	int				rat_window_open;
	int				rat_window_close;
	int				rat_window_center;
	int				rat_window_nbad[16];
	int				err_bit;
	int				rat_board_id;
	int				irtest;
	int				imode;

	const int		mxadcerr=32;
	int				adc_err[mxadcerr+1];

	char			cbid[4+1];
	string			sbid;
	int				lenv;
    char            alct_logfolder[81];
	char			tmb_logfolder[81];
	char			rat_logfolder[81];

	int				islot_dut;
	int				islot_ref;
	unsigned long	base_adr_ref;
	unsigned long	boot_adr_ref;
	unsigned long	base_adr_dut;
	unsigned long	boot_adr_dut;
	unsigned long	base_adr_global;
	unsigned long	boot_adr_global;
	unsigned long	base_adr_chk;
	unsigned long	boot_adr_chk;
	unsigned long	adr_ww1;

	bool			tmb_ref_exists;
	bool			tmb_ref_skip;
	int				tmb_board_id;
	int				tmb_firmware_type_ref;
	int				statid[10];

	const int		tmb_ntests=60;
	int				tmb_npassed[tmb_ntests+1];
	int				tmb_nfailed[tmb_ntests+1];
	int				tmb_nskipped[tmb_ntests+1];

	int				tmb_npass=0;
	int				tmb_nfail=0;
	int				tmb_nskip=0;

	const int		rat_ntests=19;
	int				rat_npassed[rat_ntests+1];
	int				rat_nfailed[rat_ntests+1];
	int				rat_nskipped[rat_ntests+1];

	int				rat_npass;
	int				rat_nfail;
	int				rat_nskip;

	double			diff;
	double			vtol;
	char			ckey;

	int				geo_adr_rd;
	int				geo_parity;
	int				parity;

	int				radix;
	char			csize[3+1];
	string			ssize;
	char			czsize[4+1];
	string			szsize;
	char			cprom[1+1];
	string			sprom;

	unsigned char	outbuf[16];
	char			colon=':';

	string			log_file_name;
	FILE*			img_file;

	char			cid_rev[4+1];
	string			sid_rev="byte";

	string			logfolder;
	string			jtag_file_name;

	int				rec_len;
	int				rec_type;
	int				adr_hi_byte;
	int				adr_lo_byte;
	int				segment;
	int				cksum;
	int				nwords;

	int				ibyte;
	int				filler;
	int				nwrite;
	int				iadr_previous;

	int				nwrites;
	int				iadr;
	int				cmp_data;
	int				cmp_adr;

	int				jtag_data;
	int				jtag_tck;
	int				jtag_tms;
	int				jtag_tdi;
	int				jtag_sel;

	int				alct_begin_marker;
	int				alct_end_marker;
	int				alct_end_header;
	int				alct_unass;
	int				alct_type;
	int				alct_month;
	int				alct_day;
	int				alct_year;
	int				alct_version;
	int				imonth;
	int				iday;
	int				iyear;

	int				wdcnt;
	int				prom_wdcnt;
	int				prom_cksum;
	int				njtag_frames;

	string			sresult_cksum;
	string			sresult_wdcnt;
	bool			first_prom_pass;

	int				uptime;
	int				uptime_hr;
	int				uptime_min;
	int				uptime_sec;

	int				bd_status_ok;
	int				bd_vstat_5p0v;
	int				bd_vstat_3p3v;
	int				bd_vstat_1p8v;
	int				bd_vstat_1p5v;
	int				bd_t_crit;

	int				iadr_rd;
	int				rd_data_rd;
	int				nmiss;
	int				nadrs;
	int				nadrs_written;
	int				nadrs_read;
	int				blue_flash;

	int				alct_bx0_delay;
	int				clct_bx0_delay;

	bool			compare_prom_file;
	bool			fire_injector=false;
	bool			err_check=true;
	bool			skip_loopback_series=false;

	unsigned short	wr_fire_l1a;

	int				l1a_lookback;
	int				hdr_wr_continuous;
	int				lookback_triad_hits[2048]={0};

	int				first_nonzero_bx;
	int				last_nonzero_bx;
	int				first_bx;
	int				last_bx;
	int				max_triads;
	double			scale;
	int				tck;

 	int				xsvf_file_size;
	string			xsvf_file_name;
	string			xsvf_tmb_user_default="userproms.xsvf";
	struct			_stat buf;
	int				stat_result;

	clock_t			startClock;
	clock_t			endClock;
	unsigned char	ucTdoBit;
	short int		TMS=1;

// Auto tests
	int				alct_board_id;
	int				mez_board_id;
	char			calct_board_id[3+1];
	char			cmez_board_id[4+1];

	string			salct_board_id;
	string			smez_board_id;

	FILE*			test_file=NULL;
    string          logfolder;
	string			test_file_name;

	int				alct_npass=0;
	int				alct_nfail=0;
	int				alct_nskip=0;

	int				adc_err_mez[14];
	int				adc_err_base[14];
	int				abs_err;
	int				max_err;

	int				itest_sc;
	bool			bfail;

	double			tfpga_mez_f;
	double			tsink_mez_f;

	int				idac_table;
	const int		ndac_table=25;
	int				dac_table[ndac_table]={0,1,2,3,4,5,6,7,8,12,15,16,24,31,32,48,63,64,96,127,128,160,192,224,255};

	string			spass_fail[2]={"PASS","FAIL <=="};
	string			spaces[20]=
					{
					"",						// 0
					" ",					// 1
					"  ",					// 2
					"   ",					// 3
					"    ",					// 4
					"     ",				// 5
					"      ",				// 6
					"       ",				// 7
					"        ",				// 8
					"         ",			// 9
					"          ",			// 10
					"           ",			// 11
					"            ",			// 12
					"             ",		// 13
					"              ",		// 14
					"               ",		// 15
					"                ",		// 16
					"                 ",	// 17
					"                  ",	// 18
					"                   "	// 19
					};

// DDD
	int				ddd_read[16]={0};
	int				ddd_enable[16];
	int				ddd_delay;
	int				ddd_chip;
	int				ddd_channel;
	int				ddd_busy;
	int				ddd_verify_ok;
	int				ddd0_delay;
	int				ddd_error;
	int				dddr_error;
	int				dddr_busy;
	int				dddr_verify_ok;
	int				dddr_linktmb;


// ALCT id register
	long int		rsa_ver;
	long int		rsa_wgn;
	long int		rsa_bf;
	long int		rsa_np;
	long int		rsa_mr;
	long int		rsa_ke;
	long int		rsa_rl;
	long int		rsa_pb;
	long int		rsa_sp6;
	long int		rsa_seu;
	long int		rsa_res1;
    
// Window centers from an alct_rxd Teven|Todd scan by posneg and ToF
	int				window_center_rxd[2][16]=
	{
		1,  3,  5,  7,  9, 11, 13, 15, 18, 20, 21, 23,  0,  0,  0,  0,
		1,  3,  5,  7, 10, 11, 13, 16, 18, 20, 22, 24,  0,  0,  0,  0
	};


// Digital phase shifters
	const int		dps_max   = 25;		//  0-255 spans 25ns, 0-to-25 with delta=10 spans (250/256)*25ns, close enough to 100%
	const int		dps_delta = 10;		//  approximate steps per ns

	int				alct_sync_rxdata_dly;
	int				alct_sync_rxdata_pre;
	int				alct_sync_1st_err[dps_max+1];
	int				alct_sync_2nd_err[dps_max+1];
	int				alct_sync_1st_err_ff[dps_max+1];
	int				alct_sync_2nd_err_ff[dps_max+1];

	int				alct_tx_default;
	int				alct_rx_default;

	int				alct_tx_bad[16];
	int				alct_rx_bad[16];

	int				alct_1st_demux;
	int				alct_2nd_demux;
	int				alct_demux_err;

	int				alct_rxd_bad[dps_max+1][28];
	int				alct_txd_bad[dps_max+1][28];
	int				alct_rxd_txd_depth[dps_max+1][dps_max+1][16];

	int				good_spot;
	int				good_spots[dps_max+1][2][dps_max+1][2][16];
	int				good_depth[dps_max+1][2][dps_max+1][2][16];
	int				good_spots_tof[16];
	int				good_spots_pos_tof[2][2][16];

	int				ngood;
	int				ngood_max;
	int				ngood_edge;
	int				ngood_center;
	int				ngood_depths;
	int				ngood_spots;
	int				good_depths;
	int				depth_code;
	int				posneg_code;
	int				window_center[2][16];
	int				window_width[2][16];

	int				maxv;
	int				minv;

	int				newcenter;
	bool			alct_tof_scan;
	bool			alct_rxd_scan_done=false;

	int				alct_demux_rd[8];
	int				alct_sync_rxdata_1st;
	int				alct_sync_rxdata_2nd;
	int				alct_sync_expect_1st;
	int				alct_sync_expect_2nd;
	int				alct_walking1_err[28][2][28];
	int				alct_walking1_hit[28][2][28][2];

	int				alct_sync_clr_err;
	int				alct_sync_tx_random;
	int				pipe_depth;
	int				msec;
	int				ibad;
	char			symbol;

	int				alct_rxd_posneg,	alct_rxd_posneg_min,	alct_rxd_posneg_max,	alct_rxd_posneg_default;
	int				alct_txd_posneg,	alct_txd_posneg_min,	alct_txd_posneg_max,	alct_txd_posneg_default;
	int				alct_tof_delay,		alct_tof_delay_min,		alct_tof_delay_max;
	int				alct_rxd_delay;
	int				alct_txd_delay;
	int				alct_rxd_int_delay;
	int				alct_txd_int_delay;

	int				alct_tof_default={0};			// Reference TMB values
	int				alct_rxd_default={9};
	int				alct_txd_default={1};

	int				cfeb_tof_delay_min;
	int				cfeb_tof_delay_max;
	int				cfeb_rxd_posneg_min;
	int				cfeb_rxd_posneg_max;

	int				cfeb_tof_delay_default={0};		// Reference TMB values
	int				cfeb_rxd_delay_default[5]={0,0,0,0,0};
	int				cfeb_rxd_posneg_default[5]={0,0,0,0,0};
	int				cfeb_txc_delay_default[5]={0,0,0,0,0};
	int				cfeb_nbx_delay_default[5]={0,0,0,0,0};
	int				cfeb_delay_is[5];

//					                              0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
	int				alct_rxd_posneg_table[26]   ={1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1};
	int				alct_txd_posneg_table[26]   ={1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
	int				alct_txd_int_delay_table[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
	int				alct_rxd_int_delay_table[26]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	string			scfeb;
	char			ccfeb[1];

	int				cfeb_tof_delay;
	int				cfeb_rxd_posneg;
	int				cfeb_rxd_delay;
	int				cfeb_nbx_delay;
	int				cfeb_rxd_bad[dps_max+1][24];
	int				cfeb_sync_1st_err[dps_max+1];
	int				cfeb_sync_2nd_err[dps_max+1];
	int				cfeb_1st_expect;
	int				cfeb_2nd_expect;
	bool			cfeb_rxd_scan_done=false;

	int				seq_cmd_bit[4];
	int				alct_1st_expect;
	int				alct_2nd_expect;
	int				ibit_1st_expected;
	int				ibit_2nd_expected;
	int				ibit_1st_received;
	int				ibit_2nd_received;
	int				nx;
	double			avgbad;
	char			dash1[2]={'-','1'};
	char			passfail[2]={'P','F'};
	bool			sc_version_new;
	bool			sc_version_old;

	int				bxn_offset_pretrig;
	int				bxn_offset_signed;
	int				bx0_match;
	int				bxn_offset_at_match;
	int				nmatches;
	string			bx0_match_state;
