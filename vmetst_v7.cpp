//------------------------------------------------------------------------------
//	TMB2005 Tests
//------------------------------------------------------------------------------
//	11/20/01 Initial
//	12/18/01 Added digital serial
//	01/03/02 Added PHOS4 state machine, shifted addresses by 10
//	01/08/02 Changed ALCT addresses for normal TMB, added broadcast adr to crate scan
//	01/17/02 Added CCB PHOS4 programming
//	03/18/02 Added loop-forever mode to alct transmitter test
//	03/19/02 Changed PHOS4 init
//	03/21/02 Added alct trigger
//	03/27/02 Added clct trigger
//	03/27/02 Added walking muon + raw hits readout
//	04/04/02 New VME addresses
//	04/30/02 Mods to trigger tests
//	06/07/02 New VME registers
//	06/10/02 MPC tests
//	06/25/02 New TMB register bits
//	07/26/02 Auto test added
//	01/16/03 Added ALCT hard reset test
//	01/17/03 Mods to allow sh105 to be 1-2 or 2-3
//	01/24/03 Add scope readout
//	03/14/03 Mods for v2 buffer-version, new scope, new ttc
//	04/16/03 Changed data delay devices chip register bits
//	05/08/03 Mod for scope64
//	05/14/03 Mod for scope96, test bend patterns
//	05/21/03 Add use prom readout
//	05/29/03 Mod alct+clct trigger +readout to match alct+clct trigger section
//	09/10/03 Add date code to scope traces
//	09/11/03 Add mpc_accept section
//	10/03/03 Ported from v2
//	11/20/03 Mods for 3d3444 and new loop-back backplane
//	12/01/03 Mods for RPC loop-back
//	12/04/03 Mod for RAT dsn
//	03/15/04 Mod for tmb2003a beam-test firmware with RAT
//	03/16/04 Move rat registers to match beam-test addresses
//	03/24/04 Copy from tmb2003a
//	04/15/04 Mod for rat dsn in regisger 1e for bdtest
//	04/19/04 Add alct raw hits ram readout
//	05/24/04 Mods for new RAT registers
//	05/25/04 Add scope128
//	05/28/04 Add alct injector delay scan to test tmb matching and mpc data
//	06/02/04 Add RAT jtag chain readout, mod rpc delay scan to put back defaults
//	07/27/04 Updates to RPC loopback for production boards
//	08/03/04 Add counter readout
//	08/04/04 Mod for new ALCTboard firmware
//	08/06/04 Add new counters
//	08/10/04 Add ALCT jtag readout
//	08/23/04 Add support for ALCT debug firmware
//	08/27/04 Change from ext_inject to ext_trig for alct debugging
//	10/06/04 Add new alct jtag command register bits
//	01/06/05 Add loops to RAT 80MHz tests
//	04/29/05 Ported from tmb2004 v4 
//	06/02/05 RPC lookback mods, ALCT loopback mods
//	06/06/05 Add tmb loopback tests
//	08/02/05 Mod boot reg bit 11 to disable fpga VME after hard reset, then undid mod, alas.
//	08/26/05 Mod rat test for RAT2005 RPC SCSI connector pin assignments
//	09/01/05 Add RAT full auto
//	09/07/05 Add RAT user2 jtag chain to write rpc enables
//	09/15/05 Add 3D3444 verification loop test
//	09/22/05 Add scope snap and store
//	10/12/05 Add jtag src select to 1200 series
//	11/30/05 New RAT jtag registers
//	12/22/05 Add RAT opcode writer
//	01/13/06 Update RAT jtag registers
//	01/18/06 Add perr counter readout
//	01/18/06 Add rpc data to rat jtag user1
//	02/03/06 Add heater address
//	02/06/06 New autotest
//	02/10/06 Change default slot to 26, which is also tmbs global slot for cms
//	02/13/06 Move adc code in full auto, change cfeb prompts to match connectors, add jtag tests
//	02/17/06 Mod rat autotest
//	02/21/06 More rat autotest mods
//	02/22/06 Move rat ddd tests into rpc0/1 test loop to minimize cable switching
//	03/01/06 Add new PROM idcodes for xc18v512
//	03/02/06 Add SH107 check to tmb auto
//	03/03/06 Add program Xilinx proms section
//	03/09/06 Add check for u76 bus-hold IC and clock lock status in autotest
//	03/15/06 Add SH95 note
//	03/16/06 Mod u76 test to check tdo
//	03/23/06 Add vme error print suppression
//	04/10/06 Add jtag sm registers
//	05/23/06 Increase +3.3VA tolerance
//	05/30/06 Mod to autotest: pass boards that have 512K proms
//	07/14/06 Add vme prom utilities
//	08/02/06 Mod for new xc18v04 idcodes
//	08/23/06 Add new vme registers for rat prom state machine
//	10/16/06 New scope channels, mods to trigger test parameter input
//	11/14/06 Add playback
//	04/03/07 Add tbins to trigger test 16 sub 7
//	04/30/07 Mod fmm_state to add resync state
//	05/21/07 Port from v5 version, adapt to 2-clct 9-pattern logic
//	05/29/07 Add 2nd CLCT to pattern injector tests
//	05/30/07 Add secondary bend pattern hits
//	07/02/07 Shift key layer from ly3 to ly2
//	08/13/07 Add buffer reset counter
//	09/10/07 New VME counters + header mods
//	11/05/07 New VME counters
//	12/19/07 Add buffer status to sequencer state display
//	04/24/08 New header format
//	04/29/08 Replace event counters
//	07/28/08 Replace scope readout with cpp version, didnt work
//	09/25/08 Replace scope128 with scope160
//	11/05/08 Port to c++ from fortran
//	11/10/08 Add readout decoding
//	11/12/08 Add ADC readout
//	11/13/08 Add DSN readout
//	11/14/08 Add L1A header-only event trigger test
//	11/26/08 Mod parity error readout
//	12/10/08 Add l1a lookback scan histo
//	12/11/08 Convert more sections from fort to c
//	01/12/09 Add alct loopback tests
//	02/24/09 Add 2 alct ecc counters 5,6, shifts all other counters up by 2
//	02/27/09 Fix ecc test
//	03/09/09 Update counters add ecc vs ecc timing scan
//	04/07/09 Add alct posneg for interstage
//	05/07/09 Add miniscope
//	06/02/09 Mod for muonic timing
//	06/04/09 More muonic timing mods
//	06/12/09 Switch to digital phase shifting for alct rxd txd
//	06/15/09 Updates to digital phase shifting
//	06/16/09 Remove digital phase shift, revert to ddd muonic
//	06/29/09 Put back digital phase shift, wtf
//	08/19/09 Add cfeb digital phase shift scan
//	10/31/09 Translate tmb auto test from fortran
//	11/13/09 Bug fixs for tmb auto test
//	11/16/09 Add pre-determined posneg alct-rx-tx scans
//	01/11/10 Add cfeb bad bits testing
//	01/26/10 Change vme_io_wxp for D16 block writes
//	01/26/10 Replace xsvfwriter submodule
//	01/29/10 Add clct generated vs found display output
//	02/11/10 Add type b csc mods
//	03/01/10 Fix 0 alct + 1 clct trigger test
//	03/25/10 Take out secondary patterns, add multiple clct injects
//	03/29/10 Mod inqs for multiple clct injects
//	03/31/10 Reverse pattern array indices for c++ convention
//	04/02/10 Add csc emulator
//	04/29/10 Add bx0 emulator for sync_err checking
//	05/17/10 Add playback event dump to display header and raw hits
//	05/25/10 Add programmable bx offsets to clct pattern injector
//	06/15/10 Add string include to enable string concatenation
//	07/01/10 Mod pattern injector RAM access
//	07/08/10 Revert pattern injector RAM access, was causing over-writes
//	09/07/10 Convert to vs2008, break up main routine into separate functions
//	01/05/11 Add sysreset
//	06/02/11 Add write test to check for bus contention
//	06/10/11 Add virtex6 fpga recognition
//	04/04/12 Add spartan-6 mezzanine ADC
//	05/15/12 Add idcode decoding
//	05/22/12 Mod auto tests for Spartan-6
//	05/23/12 Add Spartan-6 configuration status registers
//------------------------------------------------------------------------------
//	Headers
//------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------------------------------
//	Common
//------------------------------------------------------------------------------
FILE			*log_file;
FILE			*xsvf_file;
FILE			*unit;

const int		mxframe	= 8192;		// Max raw hits frame number, scope adds 512*160/16=5120 frames
const int		mxtbins	= 32;		// Highest time bin, 0 implies 32
const int		mxly	= 6;		// # CSC Layers
const int		mxds	= 8;		// # DiStrips per CFEB
const int		mxdsabs	= 40;		// # DiStrips per CSC
const int		mxcfeb	= 5;		// # CFEBs
const int		mxbitstream=200;	// Max # bits in a jtag cycle

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


const unsigned long	adr_alct_startup_delay	= 0x000144;	// ALCT startup delay milliseconds for Spartan-6
const unsigned long	adr_alct_startup_status	= 0x000146;	// ALCT startup delay machine status

const unsigned long	adr_virtex6_snap12_qpll	= 0x000148;	// Virtex-6 SNAP12 Serial interface + QPLL
const unsigned long	adr_virtex6_gtx_rx_all	= 0x00014A;	// Virtex-6 GTX  common control
const unsigned long	adr_virtex6_gtx_rx0		= 0x00014C;	// Virtex-6 GTX0 control and status
const unsigned long	adr_virtex6_gtx_rx1		= 0x00014E;	// Virtex-6 GTX1 control and status
const unsigned long	adr_virtex6_gtx_rx2		= 0x000150;	// Virtex-6 GTX2 control and status
const unsigned long	adr_virtex6_gtx_rx3		= 0x000152;	// Virtex-6 GTX3 control and status
const unsigned long	adr_virtex6_gtx_rx4		= 0x000154;	// Virtex-6 GTX4 control and status
const unsigned long	adr_virtex6_gtx_rx5		= 0x000156;	// Virtex-6 GTX5 control and status
const unsigned long	adr_virtex6_gtx_rx6		= 0x000158;	// Virtex-6 GTX6 control and status
const unsigned long	adr_virtex6_sysmon		= 0x00015A;	// Virtex-6 Sysmon ADC

const unsigned long	last_vme_adr			= 0x00015C;	// Last valid address instantiated
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

void			lct_quality		(int &ACC, int &A, int &C, int &A4, int &C4, int &P, int &CPAT, int &Q);
int				flip_pid		(int pid);
void			crc22a			(long int &din, long int &crc, int reset);

void			ddd_wr			(unsigned long &base_adr, const int &ddd_chip, const int &ddd_channel, const int &ddd_delay);
int				ddd_rd			(unsigned long &base_adr, const int &ddd_chip, const int &ddd_channel);
void			dsn_rd			(unsigned long &vme_dsn_adr, const int &itype, int dsn[]);
void			idcode_decode	(long &idcode, string &sdevice_type, string &sdevice_name, string &sdevice_version, string &sdevice_size);

void			phaser_wr		(unsigned long &base_adr, const string phaser_bank, const int &phaser_delay, const int &phaser_delta);
int				phaser_rd		(unsigned long &base_adr, const string phaser_bank, const int &phaser_delta);
void			posneg_wr		(unsigned long &base_adr, const string phaser_bank, const int &posneg);
int				posneg_rd		(unsigned long &base_adr, const string phaser_bank);
int				dddstr_rd		(unsigned long &base_adr, const string ddd_delay);
int				cfebbx_rd		(unsigned long &base_adr, const string nbx_delay);

void			decode_readout	(int vf_data[], int &dmb_wdcnt, bool &err_check);
void			smb_write		(unsigned long &adc_adr, int &smb_adr, int &smb_cmd,       int &smb_data);
void			smb_read		(unsigned long &adc_adr, int &smb_adr, int &smb_data_tmb,  int &smb_data_rat);

void			lfsr_rng		(const int &reset, __int64 &lfsr);
void			dow_crc			(int in[7], int &crc);
void			adc_read		(unsigned long &base_adr);
void			adc_read_mez	(unsigned long &base_adr);
void			aok				(string msg_string);
void			aokf			(string msg_string, const int itest, const int status);	
void			ck				(string data_string, int data_read, int data_expect);
int				cks				(string data_string, int data_read, int data_expect);
void			tok				(string msg_string, double fdata_read, double fdata_expect, double tolerance, int &status);
void			inquire			(string prompt, const int &minv, const int &maxv, const int &radix, int &now);
void			inquir2			(string prompt, const int &minv, const int &maxv, const int &radix, int &num, int &now);
void			inquirl			(string prompt, const int &minv, const int &maxv, const int &radix, long int &now);
void			inquirb			(string prompt, bool &now);
void			xsvf_writer		(int &islot, string xsvf_file_name, int &nerrors);

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

// Scope160c
void			scope160c
(
 unsigned long	 base_adr,
 unsigned long	 scp_ctrl_adr,
 unsigned long	 scp_rdata_adr,
 int				 scp_arm,
 int				 scp_readout,
 int				 scp_raw_decode,
 int				 scp_silent,
 int				 scp_playback,
 int				 scp_raw_data[512*160/16]
 );

// Pattern_finder
void pattern_finder
(
 int hs[6][160],			// inputs

 int &csc_type, 
 int &clct_sep, 
 int &adjcfeb_dist,
 int	&layer_trig_en,
 int	cfeb_en[5],

 int &hit_thresh_pretrig,
 int &pid_thresh_pretrig,
 int &dmb_thresh_pretrig,
 int &lyr_thresh_pretrig,

 int cfeb_active[5],		// outputs
 int &nlayers_hit,
 int	&layer_trig,

 int &hs_key_1st,
 int &hs_pid_1st,
 int &hs_hit_1st,

 int &hs_key_2nd,
 int &hs_pid_2nd,
 int &hs_hit_2nd
 );

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
const int		mxcounter = 86;
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

bool			biv;
bool			civ;

// Spartan-6 JTAG registers
bool			s6_stat_en;

const int		SPARTAN6_STAT    = 0x08;	// 16 bits
const int		SPARTAN6_BOOTSTS = 0x20;	// 16 bits
const int		SPARTAN6_SEU_OPT = 0x1D;	// 16 bits

long			s6_stat;
long			s6_bootsts;
long			s6_seu_opt;

int				s6_SWWD_strikeout;
int				s6_IN_PWRDN;
int				s6_DONE;
int				s6_INIT_B;
int				s6_MODE;
int				s6_HSWAPEN;
int				s6_PART_SECURED;
int				s6_DEC_ERROR;
int				s6_GHIGH_B;
int				s6_GWE;
int				s6_GTS_CFG_B;
int				s6_DCM_LOCK;
int				s6_ID_ERROR;
int				s6_CRC_ERROR;

int				s6_STRIKE_CNT;
int				s6_CRC_ERROR_1;
int				s6_ID_ERROR_1;
int				s6_WTO_ERROR_1;
int				s6_RESERVED_8;
int				s6_FALLBACK_1;
int				s6_VALID_1;
int				s6_CRC_ERROR_0;
int				s6_ID_ERROR_0;
int				s6_WTO_ERROR_0;
int				s6_RESERVED;
int				s6_FALLBACK_0;
int				s6_VALID_0;

int				s6_RESERVED_15;
int				s6_RESERVED_14;
int				s6_SEU_FREQ;
int				s6_SEU_RUN_ON_ERR;
int				s6_GLUT_MASK;
int				s6_SEU_ENABLE;

// Firmware
unsigned short	firmware_type;
unsigned short	firmware_series;
unsigned short	firmware_normal			=0xC;
unsigned short	firmware_debug			=0xD;
unsigned short	firmware_series_etype	=0xE;

unsigned short	ise_version;
unsigned short	ise_sub;
unsigned short	ise_sp;

char			timestr[9];
char			datestr[9];

string			tmb_type;
string			fpga_series;
string			firmware_name;
string			scomputer_name;

// CSC type
int				csc_me1ab;
int				stagger_hs_csc;
int				reverse_hs_csc;
int				reverse_hs_me1a;
int				reverse_hs_me1b;
int				csc_type;
string			flags_ok;

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

// Parity
int				perr_cfeb;
int				perr_rpc;
int				perr_mini;
int				perr_en;
int				perr;

int				perr_cfeb_ff;
int				perr_rpc_ff;
int				perr_mini_ff;
int				perr_reset_vme;
int				perr_free;
int				perr_ff;

int				perr_adr;
int				perr_mux;
int				perr_ram_cfeb0[6];
int				perr_ram_cfeb1[6];
int				perr_ram_cfeb2[6];
int				perr_ram_cfeb3[6];
int				perr_ram_cfeb4[6];
int				perr_ram_rpc[5];
int				perr_ram_mini[2];

// CCB
int				ttc_cmd;
int				ccb_cmd;
int				ccb_clock40_enable;
int				ccb_ttcrx_ready;
int				ccb_qpll_locked;
int				ccb_reserved;
int				ccb_bcntres;
int				ccb_bx0;

int				ccb_ttcrx_lock_never;
int				ccb_ttcrx_lost_ever;
int				ccb_qpll_lock_never;
int				ccb_qpll_lost_ever;

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

int				autostart;
int				ich;
char			cch;
double			rnd;

string			ddd_name[16]={
	"ALCT  tx clock",
	"ALCT  rx clock",
	"DMB   tx clock",
	"RPC   tx clock",
	"TMB1  rx clock",
	"MPC   rx clock",
	"DCC   tx clock",
	"CFEB0 tx clock",
	"CFEB1 tx clock",
	"CFEB2 tx clock",
	"CFEB3 tx clock",
	"CFEB4 tx clock",
	"RPC0  rx clock",
	"RPC1  rx clock",
	"RAT2  rx clock",
	"RAT3  rx clock"};

string			ddd_name_rat[4]={
	"RPC0  rx clock",
	"RPC1  rx clock",
	"Not used      ",
	"Not used      "};

string			ddd_tp[3][4]={
	"TP53-1 ATX  ",
	"TP53-2 ARX  ",
	"TP53-3 DMB  ",
	"TP53-4 RPC  ",
	"TP53-6 TMB1 ",
	"TP53-7 MPC  ",
	"TP53-8 DCC  ",
	"TP54-1 CFEB0",
	"TP54-2 CFEB1",
	"TP54-3 CFEB2",
	"TP54-4 CFEB3",
	"TP54-5 CFEB4"};
// Debug
bool			debug_loop;
bool			debug_step;
bool			debug_beep;

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
int				ipass;

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
//	CLCT Bend Pattern Images, key layer 2
//------------------------------------------------------------------------------
int	pattern_image[11][6][11]// pid,layer,cell
={
	//      0 1 2 3 4 5 6 7 8 9 A
	0,0,0,0,0,0,0,0,0,0,0,	// ly0 Pattern 0, empty
	0,0,0,0,0,0,0,0,0,0,0,	// ly1
	0,0,0,0,0,0,0,0,0,0,0,	// ly2
	0,0,0,0,0,0,0,0,0,0,0,	// ly3
	0,0,0,0,0,0,0,0,0,0,0,	// ly4
	0,0,0,0,0,0,0,0,0,0,0,	// ly5

	0,0,0,0,0,0,0,0,0,0,0,	// ly0 Pattern 1, empty
	0,0,0,0,0,0,0,0,0,0,0,	// ly1
	0,0,0,0,0,0,0,0,0,0,0,	// ly2
	0,0,0,0,0,0,0,0,0,0,0,	// ly3
	0,0,0,0,0,0,0,0,0,0,0,	// ly4
	0,0,0,0,0,0,0,0,0,0,0,	// ly5

	0,0,0,0,0,0,0,0,2,2,1,	// ly0 Pattern 2, 0=no hit, 1=primary hit, 2=secondary hit
	0,0,0,0,0,0,2,1,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,1,2,2,0,0,0,0,0,	// ly3
	0,1,2,2,0,0,0,0,0,0,0,	// ly4
	1,2,2,0,0,0,0,0,0,0,0,	// ly5

	1,2,2,0,0,0,0,0,0,0,0,	// ly0 Pattern 3
	0,0,0,1,2,0,0,0,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,0,0,2,2,1,0,0,0,	// ly3
	0,0,0,0,0,0,0,2,2,1,0,	// ly4
	0,0,0,0,0,0,0,0,2,2,1,	// ly5

	0,0,0,0,0,0,0,2,2,1,0,	// ly0 Pattern 4
	0,0,0,0,0,0,2,1,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,1,2,0,0,0,0,0,0,	// ly3
	0,1,2,2,0,0,0,0,0,0,0,	// ly4
	0,1,2,2,0,0,0,0,0,0,0,	// ly5

	0,1,2,2,0,0,0,0,0,0,0,	// ly0 Pattern 5
	0,0,0,1,2,0,0,0,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,0,0,0,2,1,0,0,0,	// ly3
	0,0,0,0,0,0,0,2,2,1,0,	// ly4
	0,0,0,0,0,0,0,2,2,1,0,	// ly5

	0,0,0,0,0,0,2,2,1,0,0,	// ly0 Pattern 6
	0,0,0,0,0,2,1,0,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,0,1,2,0,0,0,0,0,	// ly3
	0,0,0,1,2,0,0,0,0,0,0,	// ly4
	0,0,1,2,2,0,0,0,0,0,0,	// ly5

	0,0,1,2,2,0,0,0,0,0,0,	// ly0 Pattern 7
	0,0,0,0,1,2,0,0,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,0,0,2,1,0,0,0,0,	// ly3
	0,0,0,0,0,0,2,1,0,0,0,	// ly4
	0,0,0,0,0,0,2,2,1,0,0,	// ly5

	0,0,0,0,0,2,2,1,0,0,0,	// ly0 Pattern 8
	0,0,0,0,0,2,1,0,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,0,1,2,0,0,0,0,0,	// ly3
	0,0,0,1,2,2,0,0,0,0,0,	// ly4
	0,0,0,1,2,2,0,0,0,0,0,	// ly5

	0,0,0,1,2,2,0,0,0,0,0,	// ly0 Pattern 9
	0,0,0,0,1,2,0,0,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,0,0,2,1,0,0,0,0,	// ly3
	0,0,0,0,0,2,2,1,0,0,0,	// ly4
	0,0,0,0,0,2,2,1,0,0,0,	// ly5

	0,0,0,0,2,1,2,0,0,0,0,	// ly0 Pattern A
	0,0,0,0,0,1,0,0,0,0,0,	// ly1
	0,0,0,0,0,1,0,0,0,0,0,	// ly2
	0,0,0,0,0,1,0,0,0,0,0,	// ly3
	0,0,0,0,2,1,2,0,0,0,0,	// ly4
	0,0,0,0,2,1,2,0,0,0,0	// ly5
};

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

// RAT USER2 control register
char			wso[32];
long int		ws_rpc_en;
long int		ws_ddd_start;
long int		ws_ddd_wr;
long int		ws_dddoe_wr;
long int		ws_perr_reset;
long int		ws_parity_odd;
long int		ws_perr_ignore;
long int		ws_rpc_future;

// Backplane status register
char			bs[192];

long int		back_user1[6];
long int		bs_begin;
long int		bs_version;
long int		bs_monthday;
long int		bs_year;
long int		bs_endD;
long int		bs_endE;

int				p2a_gnd_c[25+1];
int				p2b_gnd_c[11+1];
int				p2b_vtt_c[10+1];
int				p3a_gnd_c[25+1];
int				p3a_gnd_f[25+1];
int				p3a_vcc_a[24+1];
int				p3b_gnd_c[25+1];
int				p3b_gnd_f[25+1];
int				p3b_vcc_a[25+1];

int				p2a_gnd_c_ok;
int				p2b_gnd_c_ok;
int				p2b_vtt_c_ok;
int				p3a_gnd_c_ok;
int				p3a_gnd_f_ok;
int				p3a_vcc_a_ok;
int				p3b_gnd_c_ok;
int				p3b_gnd_f_ok;
int				p3b_vcc_a_ok;

int				p2a_ok;
int				p2b_ok;
int				p3a_ok;
int				p3b_ok;

int				all_ok;
int				bs_free;

bool			markers_ok;
int				ibplsync;

int				p2a_gnd_c_bad;
int				p2b_gnd_c_bad;
int				p2b_vtt_c_bad;
int				p3a_gnd_c_bad;
int				p3a_gnd_f_bad;
int				p3a_vcc_a_bad;
int				p3b_gnd_c_bad;
int				p3b_gnd_f_bad;
int				p3b_vcc_a_bad;

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

string			alct_chip_type[3]={"FPGA","PROM","PROM"};
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
int				npasses;
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

unsigned long	adc_adr;
int				smb_adr;
int				smb_cmd;
int				smb_data;
int				smb_data_tmb;
int				smb_data_rat;

double			t_local_c_tmb;
double			t_local_f_tmb;
double			t_remote_c_tmb;
double			t_remote_f_tmb;	
double			tcrit_local_c_tmb;
double			tcrit_local_f_tmb;
double			tcrit_remote_c_tmb;
double			tcrit_remote_f_tmb;

double			t_local_c_rat;
double			t_local_f_rat;
double			t_remote_c_rat;
double			t_remote_f_rat;	
double			tcrit_local_c_rat;
double			tcrit_local_f_rat;
double			tcrit_remote_c_rat;
double			tcrit_remote_f_rat;

int				opcode;
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
string			dsn_chip[3]={"TMB","Mez","RAT"};
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
string			sdsn;

int				nlayers_hit;
int				scint_veto;
int				adc_data;

int				alct0_inj_rd;
int				alct1_inj_rd;
int				alct0_inj_wr;
int				alct1_inj_wr;

int				alct0_vpf_inj;
int				alct0_qual_inj;
int				alct0_amu_inj;
int				alct0_key_inj;
int				alct0_bxn_inj;

int				alct1_vpf_inj;
int				alct1_qual_inj;
int				alct1_amu_inj;
int				alct1_key_inj;
int				alct1_bxn_inj;

int				alct0_vpf;
int				alct0_qual;
int				alct0_amu;
int				alct0_key;
int				alct0_bxn;

int				alct1_vpf;
int				alct1_qual;
int				alct1_amu;
int				alct1_key;
int				alct1_bxn;

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
char			cv2p5_mez[5];
char			cv1p8_mez[5];
char			cv1p2_mez[5];
char			ctfpga_mez[5];
char			ctsink_mez[5];

string			sid;
string			sidc;
string			sich;
string			svcore;
string			sv2p5_mez;
string			sv1p8_mez;
string			sv1p2_mez;
string			stfpga_mez;
string			stsink_mez;

int				tadc_ok;
int				tfpga_ok;
int				tsink_ok;
int				v2p5_mez_ok;
int				v1p8_mez_ok;
int				v1p2_mez_ok;

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

int				hit_thresh_pretrig_temp;
int				hit_thresh_postdrift_temp;

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
int				adc_err_mez[mxadcerr+1];

char			cbid[4+1];
string			sbid;
int				lenv;
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
int				firmware_type_ref;
int				statid[10];

const int		tmb_ntests=60;
int				tmb_npassed[tmb_ntests+1];
int				tmb_nfailed[tmb_ntests+1];
int				tmb_nskipped[tmb_ntests+1];
int				itest;

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

int				nerrors;
int				nwrites;
int				iadr;
int				cmp_data;
int				cmp_adr;

int				jtag_data;
int				jtag_tck;
int				jtag_tms;
int				jtag_tdi;
int				jtag_sel;

int				lock_tmb_clock0;
int				lock_tmb_clock0d;
int				lock_tmb_clock1;
int				lock_alct_rxclock;
int				lock_alct_rxclockd;
int				lock_mpc_clock;
int				lock_dcc_clock;
int				lock_rpc_rxalt1;

int				jsm_prom_start_vme;
int				jsm_sreset;
int				jsm_autostart;
int				jsm_sel;
int				jsm_busy;
int				jsm_aborted;
int				jsm_header_ok;
int				jsm_chain_ok;
int				jsm_tckcnt_ok;
int				jsm_wdcnt_ok;
int				jsm_cksum_ok;
int				jsm_end_ok;
int				jsm_tck_fpga_ok;
int				jsm_cksum;
int				jsm_vme_ready;
int				jsm_throttle;
int				jsm_jtag_oe;
int				jsm_ok;
int				jsm_unass0;
int				jsm_wdcnt;
int				jsm_tck_fpga;

int				jsm_prom_sm_vec;
int				jsm_format_sm_vec;
int				jsm_jtag_sm_vec;

string			jsm_prom_state;
string			jsm_format_state;
string			jsm_jtag_state;

int				jsm_trailer_adr;
int				jsm_data_valid;
int				jsm_flag_word;
int				jsm_flag_bit;
int				jsm_data;
string			sjsm_frame_type;

int				L;
int				vsm_start;
int				vsm_sreset;
int				vsm_autostart;
int				vsm_busy;
int				vsm_aborted;
int				vsm_cksum_ok;
int				vsm_wdcnt_ok;
int				vsm_ok;
int				vsm_pathok;
int				vsm_jtag_auto;
int				vsm_vme_ready;
int				vsm_unass0;
int				vsm_throttle;
int				vsm_wdcnt;
int				vsm_cksum;
int				vsm_fmt_err;
int				vsm_fmt_err0;
int				vsm_fmt_err1;
int				vsm_fmt_err2;
int				vsm_fmt_err3;
int				vsm_fmt_err4;
int				vsm_path;
int				vsm_nvme_writes;
string			svsm_frame_type;
string			vstr;

const int		mxmodified=1000;
int				nmodified;
int				store_adr[mxmodified];
int				store_data[mxmodified];
int				adr_mod5;

int				vsm_data;
int				vsm_begin_marker;
int				clct_type;
int				vsm_month;
int				vsm_day;
int				vsm_year;
int				vsm_version;
int				vsm_option0;
int				vsm_option1;
int				vsm_option2;
int				vsm_option3;
int				vsm_option4;
int				vsm_end_header;
int				vsm_end_prom_marker;
int				vsm_end_data_marker;
int				vmesm4_data;

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

// Miniscope
int				mini_read_enable;
int				mini_test;
int				mini_tbins_word;
int				fifo_pretrig_mini;
int				csc_id;

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
bool			debug;

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

int				bxn_offset_pretrig;
int				bxn_offset_signed;
int				bx0_match;
int				bxn_offset_at_match;
int				nmatches;
string			bx0_match_state;

// Window centers from an alct_rxd Teven|Todd scan by posneg and ToF
int				window_center_rxd[2][16]=
{
	1,  3,  5,  7,  9, 11, 13, 15, 18, 20, 21, 23,  0,  0,  0,  0,
	1,  3,  5,  7, 10, 11, 13, 16, 18, 20, 22, 24,  0,  0,  0,  0
};

// Board testing
int				id_month_expect;
int				id_day_expect;
int				id_year_expect;
int				id_rev_fpga_expect;

int				id_rev_month_expect;
int				id_rev_day_expect;
int				id_rev_year_expect;
bool			ledtest[7];
double			a1p5core_expect;

// CFEB bad bits
int				cfeb_badbits_reset;
int				cfeb_badbits_block;
int				cfeb_badbits_found;
int				cfeb_badbits_blocked;
int				cfeb_badbits_nbx;
int				cfeb_badbits[mxcfeb][mxly];
int				bcb_read_enable;
int				ibadbit;
int				adr_offset;
int				icycle;
int				nbx;
int				idslp;
int				ilayerlp;
int				iword;
int				iword_expect;

// Hot channel mask
int				hcm_adr;
int				hcm_data;
int				hcm_data0;
int				hcm_data1;
int				hot_channel_mask[mxcfeb][mxly][mxds];

// Pattern_finder
int				cfeb_en[5]={1,1,1,1,1};

int				hs_key_1st_emu;
int				hs_pid_1st_emu;
int				hs_hit_1st_emu;

int				hs_key_2nd_emu;
int				hs_pid_2nd_emu;
int				hs_hit_2nd_emu;

int				nlayers_hit_emu;
int				layer_trig_emu;
int				cfeb_active_emu[5];

bool			emulator_pretrig;
bool			emulator_latch_clct0;
bool			emulator_latch_clct1;
bool			send_emulator_to_tmb;

int				clct0_vpf_emu;
int				clct0_hit_emu;
int				clct0_pid_emu;
int				clct0_key_emu;
int				clct0_cfeb_emu;
int				clctc_sync_emu;

int				clct1_vpf_emu;
int				clct1_hit_emu;
int				clct1_pid_emu;
int				clct1_key_emu;
int				clct1_cfeb_emu;

int				clct0_vpf_vme;
int				clct0_hit_vme;
int				clct0_pid_vme;
int				clct0_key_vme;
int				clct0_cfeb_vme;

int				clct1_vpf_vme;
int				clct1_hit_vme;
int				clct1_pid_vme;
int				clct1_key_vme;
int				clct1_cfeb_vme;

int				clctc_bxn_vme;
int				clctc_sync_vme;

int				nspan;
int				pspan;
int				busy_min;
int				busy_max;
bool			clct0_is_on_me1a;
int				key_inj;
int				busy_key_inj[160];

int				clct_hit_inj_expect[2];
int				clct_key_inj_expect[2];
int				clct_pid_inj_expect[2];
int				clct_pat_inj_expect[2];

bool			injector_clct0_over;
bool			injector_clct1_over;
bool			injector_pretrig;
bool			injector_latch_clct0;
bool			injector_latch_clct1;

int				clct0_vpf_vme_expect;
int				clct0_hit_vme_expect;
int				clct0_pid_vme_expect;
int				clct0_key_vme_expect;
int				clct0_cfeb_vme_expect;
int				clctc_sync_vme_expect;

int				clct1_vpf_vme_expect;
int				clct1_hit_vme_expect;
int				clct1_pid_vme_expect;
int				clct1_key_vme_expect;
int				clct1_cfeb_vme_expect;

int				clct0_vpf_tmb;
int				clct0_hit_tmb;
int				clct0_pid_tmb;
int				clct0_key_tmb;
int				clct0_cfeb_tmb;

int				clct1_vpf_tmb;
int				clct1_hit_tmb;
int				clct1_pid_tmb;
int				clct1_key_tmb;
int				clct1_cfeb_tmb;

int				clctc_bxn_tmb;
int				clctc_sync_err_tmb;

int				key0;
int				key1;

bool			kill_me1a_clcts;
bool			clct0_exists;
bool			clct1_exists;
bool			clct0_cfeb4;
bool			clct1_cfeb4;
bool			kill_clct0;
bool			kill_clct1;
bool			kill_trig;
bool			bans;

bool			clct_noalct_lost;
bool			alct_only_trig;

bool			clct_keep;
bool			alct_keep;

bool			clct_keep_ro;
bool			alct_keep_ro;

bool			clct_discard;
bool			alct_discard;

bool			clct_match;
bool			clct_noalct;
bool			alct_noclct;
bool			alct_pulse;

bool			trig_pulse;
bool			trig_keep;
bool			non_trig_keep;
bool			alct_only;

bool			clct_match_tr;
bool			alct_noclct_tr;
bool			clct_noalct_tr;
bool			clct_match_ro;
bool			alct_noclct_ro;
bool			clct_noalct_ro;

bool			tmb_trig_pulse;
bool			tmb_trig_keep_ff;
bool			tmb_non_trig_keep_ff;

bool			tmb_match;
bool			tmb_alct_only;
bool			tmb_clct_only;

bool			tmb_match_ro_ff;
bool			tmb_alct_only_ro_ff;
bool			tmb_clct_only_ro_ff;

bool			tmb_alct_discard;
bool			tmb_clct_discard;

int				tmb_alct0;
int				tmb_alct1;
int				alct0_pipe;
int				alct1_pipe;
int				alct0_real;
int				alct1_real;

int				keep_clct;
int				clct0_real;
int				clct0_pipe;
int				clct1_real;
int				clct1_pipe;
int				clctc_real;
int				clctc_pipe;

bool			tmb_match_ro;
bool			tmb_alct_only_ro;
bool			tmb_clct_only_ro;

bool			tmb_trig_keep;
bool			tmb_non_trig_keep;

int				tmb_no_alct_emu;
int				tmb_no_clct_emu;
int				tmb_one_alct_emu;
int				tmb_one_clct_emu;
int				tmb_two_alct_emu;
int				tmb_two_clct_emu;
int				tmb_dupe_alct_emu;
int				tmb_dupe_clct_emu;

int				alct_dummy;
int				clct_dummy;
int				clctc_dummy;
int				clct_bxn_insert_emu;

int				clct0_emu;
int				clct1_emu;
int				clctc_emu;

int				alct0_emu;
int				alct1_emu;

int				lct0_vpf_emu;
int				lct1_vpf_emu;

int				alct0_vpf_emu;
int				alct0_valid_emu;
int				alct0_quality_emu;
int				alct0_amu_emu;
int				alct0_key_emu;
int				alct0_bxn_emu;

int				alct1_vpf_emu;
int				alct1_valid_emu;
int				alct1_quality_emu;
int				alct1_amu_emu;
int				alct1_key_emu;
int				alct1_bxn_emu;

int				clct0_valid_emu;
int				clct0_bend_emu;

int				clct1_valid_emu;
int				clct1_bend_emu;

int				clct_bxn_emu;
int				clct_sync_err_emu;

int				alct0_hit_emu;
int				alct1_hit_emu;

int				clct0_cpat_emu;
int				clct1_cpat_emu;

int				ACC;
int				A;
int				C;
int				A4;
int				C4;
int				P;
int				CPAT;
int				Q;

int				lct0_quality_emu;
int				lct1_quality_emu;
int				tmb_rank_err_emu;

int				alct_bx0_emu;
int				clct_bx0_emu;

int				csc_id_emu;

int				trig_mpc_emu;
int				trig_mpc0_emu;
int				trig_mpc1_emu;

int				mpc0_frame0_emu;
int				mpc0_frame1_emu;
int				mpc1_frame0_emu;
int				mpc1_frame1_emu;

int				mpc0_frame0_pulse;
int				mpc0_frame1_pulse;
int				mpc1_frame0_pulse;
int				mpc1_frame1_pulse;

int				mpc_alct0_key_expect;
int				mpc_clct0_pid_expect;
int				mpc_lct0_qual_expect;
int				mpc_lct0_vpf_expect;

int				mpc_clct0_key_expect;
int				mpc_clct0_bend_expect;
int				mpc_sync_err0_expect;
int				mpc_alct0_bxn_expect;
int				mpc_bx0_clct_expect;
int				mpc_csc_id0_expect;

int				mpc_alct1_key_expect;
int				mpc_clct1_pid_expect;
int				mpc_lct1_qual_expect;
int				mpc_lct1_vpf_expect;

int				mpc_clct1_key_expect;
int				mpc_clct1_bend_expect;
int				mpc_sync_err1_expect;
int				mpc_alct1_bxn_expect;
int				mpc_bx0_alct_expect;
int				mpc_csc_id1_expect;

int				mpc_alct0_key_vme;
int				mpc_clct0_pid_vme;
int				mpc_lct0_qual_vme;
int				mpc_lct0_vpf_vme;

int				mpc_clct0_key_vme;
int				mpc_clct0_bend_vme;
int				mpc_sync_err0_vme;
int				mpc_alct0_bxn_vme;
int				mpc_bx0_clct_vme;
int				mpc_csc_id0_vme;

int				mpc_alct1_key_vme;
int				mpc_clct1_pid_vme;
int				mpc_lct1_qual_vme;
int				mpc_lct1_vpf_vme;

int				mpc_clct1_key_vme;
int				mpc_clct1_bend_vme;
int				mpc_sync_err1_vme;
int				mpc_alct1_bxn_vme;
int				mpc_bx0_alct_vme;
int				mpc_csc_id1_vme;

int				lct0_vme;
int				lct1_vme;

int				ihs_min;
int				ihs_max;
int				ihs_hit;
int				ihs_ds;

int				sync_err_reset;
int				clct_bx0_sync_err_en;
int				alct_ecc_rx_err_en;
int				alct_ecc_tx_err_en;
int				bx0_match_err_en;
int				clock_lock_lost_err_en;
int				sync_err_blanks_mpc_en;
int				sync_err_stops_pretrig_en;
int				sync_err_stops_readout_en;
int				sync_err; 
int				clct_bx0_sync_err; 
int				alct_ecc_rx_err_ff; 
int				alct_ecc_tx_err_ff; 
int				bx0_match_err_ff; 
int				clock_lock_lost_err_ff; 
int				sync_err_force; 

int				clock_lost_lost_clct;
int				clct_bx0_sync_err_clct;

const char		LF=10;	//Line feed 
const int		mxcomment=256;
char			comment[mxcomment];
int				idata;
int				adrddu;

bool			load_clct_injector_image;
int				dscfeb[mxcfeb];

int				mask_all;
int				mask_cfeb;
int				inj_trig;
int				inj_busy;
bool			engage_pattern_finder;

int				wr_data_lsb;
int				wr_data_msb;
int				rd_data_lsb;
int				rd_data_msb;
int				l1a_lookback_data;

// Virtex-6 SNAP12 GTX receivers and QPLL
int				qpll_nrst;
int				qpll_lock;
int				qpll_err;

int				r12_sclk;
int				r12_sdat;
int				r12_fok;

int				gtx_rx_enable_all;
int				gtx_rx_reset_all;
int				gtx_rx_reset_err_cnt_all;
int				gtx_rx_en_prbs_test_all;
int				gtx_rx_start_all;
int				gtx_rx_fc_all;
int				gtx_rx_valid_all;
int				gtx_rx_match_all;
int				gtx_rx_sync_done_all;
int				gtx_rx_pol_swap_all;
int				gtx_rx_err_all;

int				idcfeb;
int				gtx_rx_enable[7];
int				gtx_rx_reset[7];
int				gtx_rx_reset_err_cnt[7];
int				gtx_rx_en_prbs_test[7];
int				gtx_rx_start[7];
int				gtx_rx_fc[7];
int				gtx_rx_valid[7];
int				gtx_rx_match[7];
int				gtx_rx_sync_done[7];
int				gtx_rx_pol_swap[7];
int				gtx_rx_err[7];

int				adc_valid;
double			sysmon_temp_c;
double			sysmon_temp_f;
double			sysmon_vccint;
double			sysmon_vccaux;
double			sysmon_vref;
double			sysmon_vzero;

//------------------------------------------------------------------------------
int main()
{
	//------------------------------------------------------------------------------
	//	Debug print mode
	//------------------------------------------------------------------------------
	//	#define debug_print 1	// comment this line to turn off debug print

#ifdef debug_print
#define dprintf fprintf
#else
#define dprintf  //
#endif

	//------------------------------------------------------------------------------
	// String inits
	//------------------------------------------------------------------------------
	sclct_sm[0] = "Startup ";	// Startup waiting for initial debris to clear
	sclct_sm[1] = "Idle    ";	// Idling, waiting for pretrig
	sclct_sm[2] = "Pretrig ";	// Pretriggered, pushed event into pretrigger pipeline
	sclct_sm[3] = "Throttle";	// Reduce trigger rate
	sclct_sm[4] = "Flush   ";	// Flushing event, throttling trigger rate
	sclct_sm[5] = "Halt	   ";	// Halted, waiting for un-halt from VME\

	sread_sm[ 0] = "Xstartup";	// Startup wait for buffer status to update after a reset
	sread_sm[ 1] = "Xckstack";	// Idling, waiting for stack data
	sread_sm[ 2] = "Xdmb    ";	// Begin send to dmb
	sread_sm[ 3] = "Xheader ";	// Send header to DMB
	sread_sm[ 4] = "Xe0b    ";	// Send EOB marker
	sread_sm[ 5] = "Xdump   ";	// Send fifo dump to DMB
	sread_sm[ 6] = "Xb04    ";	// Send B04 Begin RPC marker
	sread_sm[ 7] = "Xrpc    ";	// Send RPC Pad data
	sread_sm[ 8] = "Xe04    ";	// Send E04 End of RPC marker
	sread_sm[ 9] = "Xb05    ";	// Send B05 frame to begin scope
	sread_sm[10] = "Xscope  ";	// Send scope frames
	sread_sm[11] = "Xe05    ";	// Send E05 frame to end scope
	sread_sm[12] = "Xe0c    ";	// Send E0C marker to DMB
	sread_sm[13] = "Xmod40  ";	// Send 2 words to make word count multiple of 4
	sread_sm[14] = "Xmod41  ";	// Send 2 words to make word count multiple of 4
	sread_sm[15] = "Xe0f    ";	// Send E0F frame
	sread_sm[16] = "Xcrc0   ";	// Send crc frames
	sread_sm[17] = "Xcrc1   ";	// Send crc frames
	sread_sm[18] = "Xlast   ";	// Send last frame with word count
	sread_sm[19] = "Xpop    ";	// Pop data off stack, go back to idle
	sread_sm[20] = "Xhalt   ";	// Halted, wait for resume

	scnt[ 0]="ALCT: alct0 vpf received";
	scnt[ 1]="ALCT: alct1 vpf received";
	scnt[ 2]="ALCT: alct data structure error";

	scnt[ 3]="ALCT: trigger path ECC  1-bit error corrected";
	scnt[ 4]="ALCT: trigger path ECC  2-bit error not corrected";
	scnt[ 5]="ALCT: trigger path ECC >2-bit error not corrected";
	scnt[ 6]="ALCT: trigger path ECC>=2-bit error, ALCT discarded";

	scnt[ 7]="ALCT: alct replied ECC  1-bit error corrected";
	scnt[ 8]="ALCT: alct replied ECC  2-bit error not corrected";
	scnt[ 9]="ALCT: alct replied ECC >2-bit error not corrected";

	scnt[10]="ALCT: raw hits readout";
	scnt[11]="ALCT: raw hits readout CRC error";
	scnt[12]="ALCT: alct sent bx0 to TMB";

	scnt[13]="CLCT: Pre-trigger on any   CFEB";
	scnt[14]="CLCT: Pre-trigger includes CFEB0";
	scnt[15]="CLCT: Pre-trigger includes CFEB1";
	scnt[16]="CLCT: Pre-trigger includes CFEB2";
	scnt[17]="CLCT: Pre-trigger includes CFEB3";
	scnt[18]="CLCT: Pre-trigger includes CFEB4";

	scnt[19]="CLCT: Pre-trigger is on ME1A cfeb4 only";
	scnt[20]="CLCT: Pre-trigger is on ME1B cfeb0-3 only";

	scnt[21]="CLCT: Pretrig discarded, no wrbuf available";
	scnt[22]="CLCT: Pretrig discarded, no alct in window";
	scnt[23]="CLCT: CLCTs discarded,clct0 had invalid pattern";

	scnt[24]="CLCT: CLCT0 failed pid_thresh_postdrift";
	scnt[25]="CLCT: CLCT1 failed pid_thresh_postdrift";

	scnt[26]="CLCT: Bx pre-trigger machine waited for triads";

	scnt[27]="CLCT: clct0 sent to TMB matching section";
	scnt[28]="CLCT: clct1 sent to TMB matching section";

	scnt[29]="TMB:  TMB matching accepted a match,alct,clct";
	scnt[30]="TMB:  CLCT*ALCT matched trigger";
	scnt[31]="TMB:  ALCT-only trigger";
	scnt[32]="TMB:  CLCT-only trigger";

	scnt[33]="TMB:  TMB matching rejected event";
	scnt[34]="TMB:  TMB matching rejected event, queued read";
	scnt[35]="TMB:  TMB matching discarded an ALCT pair";	
	scnt[36]="TMB:  TMB matching discarded a  CLCT pair";	
	scnt[37]="TMB:  TMB matching discarded CLCT0 from ME1A";	
	scnt[38]="TMB:  TMB matching discarded CLCT1 from ME1A";	

	scnt[39]="TMB:  Matching found no  ALCT";	
	scnt[40]="TMB:  Matching found no  CLCT";
	scnt[41]="TMB:  Matching found One ALCT";
	scnt[42]="TMB:  Matching found One CLCT";	
	scnt[43]="TMB:  Matching found Two ALCTs";	
	scnt[44]="TMB:  Matching found Two CLCTs";

	scnt[45]="TMB:  ALCT0 copied into ALCT1 to make 2nd LCT";
	scnt[46]="TMB:  CLCT0 copied into CLCT1 to make 2nd LCT";
	scnt[47]="TMB:  LCT1 has higher quality than LCT0, error";	

	scnt[48]="TMB:  Transmitted LCT0 to MPC";	
	scnt[49]="TMB:  Transmitted LCT1 to MPC";	

	scnt[50]="TMB:  MPC accepted LCT0";	
	scnt[51]="TMB:  MPC accepted LCT1";		
	scnt[52]="TMB:  MPC rejected both LCT0 & LCT1";		

	scnt[53]="L1A:  L1A received";	
	scnt[54]="L1A:  L1A received, TMB in L1A window";	
	scnt[55]="L1A:  L1A received,  no TMB in window";
	scnt[56]="L1A:  TMB triggered, no L1A in window";	
	scnt[57]="L1A:  TMB readouts completed";
	scnt[58]="L1A:  TMB readouts lost by L1A window priority";

	scnt[59]="STAT: CLCT Triads skipped";	
	scnt[60]="STAT: Raw hits buffer had to be reset";	
	scnt[61]="STAT: TTC Resyncs received";	
	scnt[62]="STAT: TTC Sync error bxn!=offset at bx0";	
	scnt[63]="STAT: Parity error in raw hits RAM";	

	scnt[64]="HDR:  Pre-trigger counter";
	scnt[65]="HDR:  CLCT counter";
	scnt[66]="HDR:  TMB trigger counter";
	scnt[67]="HDR:  ALCTs received counter";
	scnt[68]="HDR:  L1As received from ccb counter";
	scnt[69]="HDR:  Readout counter";
	scnt[70]="HDR:  Orbit counter";

	scnt[71]="ERR:  Expected all zeros if alct0_vpf is 0";
	scnt[72]="ERR:  Expected all zeros if alct1_vpf is 0";
	scnt[73]="ERR:  Expected alct0_vpf=1   if alct1_vpf is 1";
	scnt[74]="ERR:  Expected non-zero bits if alct0_vpf is 1";
	scnt[75]="ERR:  Expected non-zero bits if alct1_vpf is 1";
	scnt[76]="ERR:  Expected alct0!=alct1  if alct0_vpf is 1";

	scnt[77]="CCB:  CCB ttcrx lost lock";
	scnt[78]="CCB:  CCB qpll  lost lock";

	scnt[79]="CCB:  gtx_rx_err_count0";
	scnt[80]="CCB:  gtx_rx_err_count1";
	scnt[81]="CCB:  gtx_rx_err_count2";
	scnt[82]="CCB:  gtx_rx_err_count3";
	scnt[83]="CCB:  gtx_rx_err_count4";
	scnt[84]="CCB:  gtx_rx_err_count5";
	scnt[85]="CCB:  gtx_rx_err_count6";

	//------------------------------------------------------------------------------
	//	Open Files
	//------------------------------------------------------------------------------
	// Log file
	log_file_name = "vmetst_log.txt";
	log_file      = fopen(log_file_name.c_str(),"w");
	//	setbuf(log_file, NULL);	// stops buffering, but is 3x slower

	if (log_file  != NULL)  dprintf(stdout,"Opened      %s\n",log_file_name.c_str());
	if (log_file  == NULL) {fprintf(stdout,"Failed to open %s\n",log_file_name.c_str()); pause("WTF?");}

	// Summary files
	sum_file_name = "vmetst_sum.txt";
	sum_file      = fopen(sum_file_name.c_str(),"w");
	//	setbuf(sum_file, NULL);	// stops buffering

	scn_file_name = "vmetst_scn.txt";
	scn_file      = fopen(scn_file_name.c_str(),"w");

	if (sum_file  != NULL)  dprintf(stdout,"Opened      %s\n",sum_file_name.c_str());
	if (sum_file  == NULL) {fprintf(stdout,"Failed to open %s\n",sum_file_name.c_str()); pause("WTF?");}

	if (scn_file  != NULL)  dprintf(stdout,"Opened      %s\n",scn_file_name.c_str());
	if (scn_file  == NULL) {fprintf(stdout,"Failed to open %s\n",scn_file_name.c_str()); pause("WTF?");}

	// Put date into log files
	_strtime(timestr);
	_strdate(datestr);

	dprintf(stdout,  "Started:    %s %s\n",datestr,timestr);
	fprintf(log_file,"Started:    %s %s\n",datestr,timestr);
	fprintf(sum_file,"Started:    %s %s\n",datestr,timestr);
	fprintf(scn_file,"Started:    %s %s\n",datestr,timestr);

	//------------------------------------------------------------------------------
	//	Open VME Interface 
	//------------------------------------------------------------------------------
	bool vme_opened=false;

	status    = vme_open();					// Connect to Bit3 VME controller
	islot     = tmb_global_slot;			// TMB VME slot address
	base_adr  = islot << 19;				// VME base address  for this slot
	boot_adr  = base_adr | tmb_boot_adr;	// VME boot register for this slot
	vme_opened= (status==0);

	//------------------------------------------------------------------------------
	// Get computer name
	//------------------------------------------------------------------------------
	const int		infoBuflen=32;
	char			infoBuf[infoBuflen];
	unsigned long	bufCharCount;

	bufCharCount = infoBuflen;								// Initial length
	GetComputerName(infoBuf,&bufCharCount);					// Returns actual length
	if (bufCharCount>=infoBuflen) infoBuf[infoBuflen-1]=0;	// Manually null terminate
	scomputer_name = string(infoBuf);

	//------------------------------------------------------------------------------
	//	Get firmware type code
	//------------------------------------------------------------------------------
begin:
	adr    = base_adr;
	status = vme_read(adr,rd_data);
	firmware_type   = (rd_data >> 0) & 0xF;
	firmware_series = (rd_data >> 4) & 0xF;
	geo_adr         = (rd_data >> 8) & 0x1F;

	tmb_type = "TMB2XXX";				//any non-tmb2005 board
	if (firmware_series == firmware_series_etype) tmb_type= "TMB2005";

	// Decode id_rev
	adr    = base_adr+6;
	status = vme_read(adr,rd_data);
	id_rev			= rd_data;
	id_rev_day		= (id_rev >>  0) & 0x001F;
	id_rev_month	= (id_rev >>  5) & 0x000F;
	id_rev_year		= (id_rev >>  9) & 0x000F;
	id_rev_fpga		= (id_rev >> 13) & 0x0007;
	id_rev_fpga		=  id_rev_fpga+2;

	// Get FPGA series
	fpga_series="Unknown";
	if (id_rev_fpga==3) fpga_series="XC6SLX150";
	if (id_rev_fpga==4) fpga_series="XC2V4000";
	if (id_rev_fpga==5) id_rev_fpga=6;
	if (id_rev_fpga==6) fpga_series="XC6VLX195T";

	if (id_rev_fpga==3) id_rev_year=id_rev_year+10;	// Spartan-6 exception

	// Get compiler version
	adr    = base_adr + ise_version_adr;	// Recent TMBs have ISE register
	status = vme_read(adr,rd_data);
	ise_version=(rd_data >> 8) & 0xFF;
	ise_sub    =(rd_data >> 4) & 0xF;
	ise_sp     =(rd_data >> 0) & 0xF;

	if (ise_version<8 && ise_version!=4){	// Old TMBs were all FND4.2sp3 and do not have an ISE register
		ise_version = 0x4;
		ise_sub     = 0x2;
		ise_sp      = 0x3;
	}

	if ((firmware_type == firmware_debug)	// Debug TMBs with Virtex2 are all ISE8.2sp3 and do not have an ISE register
			&& ( fpga_series   == "XC2V4000"))  {
		ise_version = 0x8;
		ise_sub     = 0x2;
		ise_sp      = 0x3;
	}
	if ((firmware_type == firmware_debug)	// Debug TMBs with Spartan6 are all ISE13.3sp0 and do not have an ISE register
			&&   (fpga_series  == "XC6SLX150")) {
		ise_version = 0x13;
		ise_sub     = 0x3;
		ise_sp       =0x0;
	}

	// Determine firmware type
	firmware_name = "TMB200x type unknown...beware";							// Unknown TMB type

	if      (id_rev_fpga==3||id_rev_fpga==4||id_rev_fpga==6) {
		if	    (firmware_type==firmware_debug ) firmware_name = "Debug Loopback";	// Debug TMB type
		else if (firmware_type==firmware_normal) firmware_name = "Normal        ";	// Normal TMB type
	}

	// Display tmb type
	fprintf(log_file,"Firmware    %s\n",firmware_name.c_str());
	fprintf(log_file,"RevCode     %4.4X=%2.2i/%2.2i/%2.2i series %1i\n",id_rev,id_rev_month,id_rev_day,id_rev_year,id_rev_fpga);
	fprintf(log_file,"ISE Version %2.2X.%1X SP%1.1X\n",ise_version,ise_sub,ise_sp);
	fprintf(log_file,"TMB Slot    [%2.2i] adr=%6.6X\n",islot,base_adr);

	// Determine CSC type for Normal firmware versions
	if (firmware_type!=firmware_normal) goto main_menu;

	adr    = base_adr + non_trig_adr;
	status = vme_read(adr,rd_data);

	csc_me1ab		= (rd_data >>  5) & 0x1;		// R	1=ME1A or ME1B CSC type
	stagger_hs_csc	= (rd_data >>  6) & 0x1;		// R	1=Staggered CSC, 0=non-staggered
	reverse_hs_csc	= (rd_data >>  7) & 0x1;		// R	1=Reverse staggered CSC, non-me1
	reverse_hs_me1a	= (rd_data >>  8) & 0x1;		// R	1=reverse me1a hstrips prior to pattern sorting
	reverse_hs_me1b	= (rd_data >>  9) & 0x1;		// R	1=reverse me1b hstrips prior to pattern sorting
	csc_type		= (rd_data >> 12) & 0xF;		// R	Firmware compile type

	// Check reversal flags agree with csc_type for normal firmware
	flags_ok="ERR";

	if (csc_type==0xA) {
		if ((csc_me1ab       == 0)	&&
				(stagger_hs_csc  == 1)	&&
				(reverse_hs_csc	 == 0)	&&
				(reverse_hs_me1a == 0)	&&
				(reverse_hs_me1b == 0))
			flags_ok="OK";
	}
	else if (csc_type==0xB) {
		if ((csc_me1ab       ==0)	&&
				(stagger_hs_csc	 ==1)	&&
				(reverse_hs_csc	 ==1)	&&
				(reverse_hs_me1a ==0)	&&
				(reverse_hs_me1b ==0))
			flags_ok="OK";
	}
	else if (csc_type==0xC) {
		if ((csc_me1ab       ==1)	&&
				(stagger_hs_csc  ==0)	&&
				(reverse_hs_csc  ==0)	&&
				(reverse_hs_me1a ==1)	&&
				(reverse_hs_me1b ==0))
			flags_ok="OK";
	}
	else if (csc_type==0xD) {
		if ((csc_me1ab       ==1)	&&
				(stagger_hs_csc  ==0)	&&
				(reverse_hs_csc  ==0)	&&
				(reverse_hs_me1a ==0)	&&
				(reverse_hs_me1b ==1))
			flags_ok="OK";
	}
	else {
		fprintf(stdout,  "Unknown     CSC Type=%X flags_ok=%s\n",csc_type,flags_ok.c_str());
		fprintf(log_file,"Unknown     CSC Type=%X flags_ok=%s\n",csc_type,flags_ok.c_str());
	}
	dprintf(stdout,  "Determined  CSC Type=%X flags_ok=%s\n",csc_type,flags_ok.c_str());
	fprintf(log_file,"Determined  CSC Type=%X flags_ok=%s\n",csc_type,flags_ok.c_str());
	fprintf(log_file,"C++ Compile %s\n\n",__TIMESTAMP__);

	//------------------------------------------------------------------------------
	//	Main Menu
	//------------------------------------------------------------------------------
main_menu:
	printf("\tTMB Test Menu Host %s\n",scomputer_name.c_str());
	printf("\tTMB Type      %s\n",tmb_type.c_str());
	printf("\tFirmware      %s\n",firmware_name.c_str());
	printf("\tRevCode       %4.4X=%2.2i/%2.2i/%2.2i\n",id_rev,id_rev_month,id_rev_day,id_rev_year);
	printf("\tFPGA Series   %s\n",fpga_series.c_str());
	printf("\tISE  Version  %2.2X.%1X SP%1.1X\n",ise_version,ise_sub,ise_sp);
	if (firmware_type==firmware_normal)
		printf("\tCSC  Type     %1X reversal flags=%s\n",csc_type,flags_ok.c_str());
	printf("\tJTAG Cable    %s\n",vme_jtag_cable_detect(base_adr)?"Connected":"Disconnected");
	printf("\tC++  Compiled %s\n\n",__TIMESTAMP__);

	printf("\t1:   TMB Slot    [%2.2i] adr=%6.6X\n",islot,base_adr);
	printf("\t2:   Read ID Register\n");
	printf("\t3:   Read Boot Register\n");
	printf("\t4:   Peek/Poke Address\n");
	printf("\t5:   Read Trigger/Error/Discard counters\n");
	printf("\t6:   Read/Write 3D3444 Delays with State Machine\n");
	printf("\t7:   Hard Reset TMB\n");
	printf("\t8:   Hard Reset ALCT\n");
	printf("\t9:   Read DMB Raw Hits RAM\n");
	printf("\t10:  Walking 1 Tests\n");
	printf("\t11:  Read ADC+Status Register\n");
	printf("\t12:  Read FPGA and User PROM IDcodes+RAT\n");
	printf("\t13:  Read Hardware Serial Numbers\n");
	printf("\t14:  Crate Scan\n");
	printf("\t15:  Read Loopback Backplane JTAG Chain\n");
	printf("\t16:  Trigger Tests\n");
	printf("\t17:  MPC Tests\n");
	printf("\t18:  TMB Automatic full test: Loop-back backplane\n");
	printf("\t19:  RAT Tests\n");
	printf("\t20:  TTC Command/FMM Status\n");
	printf("\t21:  Sequencer State/Seq Debug/Buffer Queue/L1A Queue\n");
	printf("\t22:  MPC Accept\n");
	printf("\t23:  ALCT+CFEB Loopback Tests\n");
	printf("\t24:  Boot Register Test\n");
	printf("\t25:  RAT Automatic full test: Requires TMB+backplane\n");
	printf("\t26:  Scope snapshot of current system\n");
	printf("\t27:  Trim Vcore or Vtt\n");
	printf("\t28:  TMB Unjam, try to clear a jammed TMB\n");
	printf("\t29:  Program Xilinx PROMs\n");
	printf("\t30:  JTAG PROM file utilities\n");
	printf("\t31:  VME  PROM file utilities\n");
	printf("\t32:  Check U76 JTAG Bus-Hold circuit\n");
	printf("\t33:  VME register dump/compare\n");
	printf("\t34:  Load VME registers from dump file\n");
	printf("\t35:  Playback event dump to display header and raw hits\n");
	printf("\t36:  Playback event dump into TMB, compare result\n");
	printf("\t37:  Read/Write Phaser Delays\n");
	printf("\t38:  Fire VME sysreset\n");
	printf("\t39:  VME bus contention test\n");
	printf("\t40:  GTX Optical Receiver Status\n");
	printf("\t<cr> Exit\n");
	printf("       > ");

	gets(line);
	if (line[0]==NULL) goto exit;
	sscanf(line,"%i",&ifunc);

	i=abs(ifunc);
	if (i== 1) {void L100();	L100();		goto begin;    }
	if (i== 2) {void L200();	L200();		goto main_menu;}
	if (i== 3) {void L300();	L300();		goto main_menu;}
	if (i== 4) {void L400();	L400();		goto main_menu;}
	if (i== 5) {void L500();	L500();		goto main_menu;}
	if (i== 6) {void L600();	L600();		goto main_menu;}
	if (i== 7) {void L700();	L700();		goto begin;    }
	if (i== 8) {void L800();	L800();		goto main_menu;}
	if (i== 9) {void L900();	L900();		goto main_menu;}
	if (i==10) {void L1000();	L1000();	goto main_menu;}
	if (i==11) {void L1100();	L1100();	goto main_menu;}
	if (i==12) {void L1200();	L1200();	goto main_menu;}
	if (i==13) {void L1300();	L1300();	goto main_menu;}
	if (i==14) {void L1400();	L1400();	goto main_menu;}
	if (i==15) {void L1500();	L1500();	goto main_menu;}
	if (i==16) {void L1600();	L1600();	goto main_menu;}
	if (i==17) {void L1700();	L1700();	goto main_menu;}
	if (i==18) {void L1800();	L1800();	goto main_menu;}
	if (i==19) {void L1900();	L1900();	goto main_menu;}
	if (i==20) {void L2000();	L2000();	goto main_menu;}
	if (i==21) {void L2100();	L2100();	goto main_menu;}
	if (i==22) {void L2200();	L2200();	goto main_menu;}
	if (i==23) {void L2300();	L2300();	goto main_menu;}
	if (i==24) {void L2400();	L2400();	goto main_menu;}
	if (i==25) {void L2500();	L2500();	goto main_menu;}
	if (i==26) {void L2600();	L2600();	goto main_menu;}
	if (i==27) {void L2700();	L2700();	goto main_menu;}
	if (i==28) {void L2800();	L2800();	goto main_menu;}
	if (i==29) {void L2900();	L2900();	goto main_menu;}
	if (i==30) {void L3000();	L3000();	goto main_menu;}
	if (i==31) {void L3100();	L3100();	goto main_menu;}
	if (i==32) {void L3200();	L3200();	goto main_menu;}
	if (i==33) {void L3300();	L3300();	goto main_menu;}
	if (i==34) {void L3400();	L3400();	goto main_menu;}
	if (i==35) {void L3500();	L3500();	goto main_menu;}
	if (i==36) {void L3600();	L3600();	goto main_menu;}
	if (i==37) {void L3700();	L3700();	goto main_menu;}
	if (i==38) {void L3800();	L3800();	goto main_menu;}
	if (i==39) {void L3900();	L3900();	goto main_menu;}
	if (i==40) {void L4000();	L4000();	goto main_menu;}
	goto main_menu;

	//------------------------------------------------------------------------------
	// 	Exit main: Close VME Interface
	//------------------------------------------------------------------------------
exit:
	if (vme_opened    ) status = vme_close();	// Close VME
	if (log_file!=NULL) fclose(log_file);		// Close log file
	if (sum_file!=NULL) fclose(sum_file);		// Close sum file
	if (scn_file!=NULL) fclose(scn_file);		// Close scn file

	printf("\tSic transit gloria mundi");		// Say goodbye
	gets(line);

	return 0;
}
//------------------------------------------------------------------------------
//	Change TMB Slot
//------------------------------------------------------------------------------
void L100() {
L100:
	printf("\tOld slot=%2.2i New slot[0-31]=",islot);

	gets(line);
	if (line[0]==NULL) goto L100;
	sscanf(line,"%i",&newslot);
	if ((newslot>31) || (newslot<0)) goto L100;

	islot    = newslot;
	base_adr = (islot << 19);
	boot_adr = base_adr | tmb_boot_adr;

	return;
}
//------------------------------------------------------------------------------
//	Read ID Register
//------------------------------------------------------------------------------
void L200() {
	//L200:

	if (ifunc < 0) goto L250;	// Bang mode
	for (i=0; i<=3; ++i) {
		adr    = base_adr + vme_idreg_adr + 2*i;
		status = vme_read(adr,rd_data);
		printf("\tadr=%6.6X read=%4.4X\n",adr,rd_data);
		id_reg[i]=rd_data;
	}

	id_slot = (id_reg[0] >> 8) & 0x00FF;
	id_ver  = (id_reg[0] >> 4) & 0x000F;
	id_type = (id_reg[0] >> 0) & 0x000F;
	id_month= (id_reg[1] >> 8) & 0x00FF;
	id_day  = (id_reg[1] >> 0) & 0x00FF;
	id_year =  id_reg[2];
	id_rev  =  id_reg[3];

	// Decode id_rev
	id_rev_day		= (id_rev >>  0) & 0x001F;
	id_rev_month	= (id_rev >>  5) & 0x000F;
	id_rev_year		= (id_rev >>  9) & 0x000F;
	id_rev_fpga		= (id_rev >> 13) & 0x0007;
	id_rev_fpga		= id_rev_fpga+2;
	if (id_rev_fpga==5) id_rev_fpga=6;

	printf("\n");
	printf("\tid_slot=%2.2X=%2.2d\n",id_slot,id_slot);
	printf("\tid_rev =%1X\n",  id_ver );
	printf("\tid_type=%1X\n",  id_type);
	printf("\tid_date=%2.2X/%2.2X/%4.4X\n",id_month,id_day,id_year);
	printf("\tid_rev =%4.4X=%2.2i/%2.2i/%2.2i series %1i\n",id_rev,id_rev_month,id_rev_day,id_rev_year,id_rev_fpga);

	printf("\n\t<cr> to continue:");
	gets(line);

	return;

	// Bang mode reads id reg and compares to previous reads
L250:
	nbang=10000;

	for (ibang=1; ibang<=nbang; ++ibang) {
		if (ibang%10000==0) printf("ibang=%i\n",ibang);

		for (i=0; i<=3; ++i) {
			adr    = base_adr + vme_idreg_adr + 2*i;
			status = vme_read(adr,rd_data);
			id_reg[i]=rd_data;

			// Compare id reg to previous read
			if ((ibang != 1) && (id_reg[i] != id_reg_save[i])) {
				printf("id bang fail: ibang=%7i i=%1i read=%4.4X expect=%4.4X\n",ibang,i,id_reg[i],id_reg_save[i]);
			}	// close if ibang
			id_reg_save[i]=id_reg[i];
		}	// close i
	}	// close ibang
	goto L250;
}

//------------------------------------------------------------------------------
//	Read Boot Register
//------------------------------------------------------------------------------
void L300() {
L300:

	status = vme_read(boot_adr,rd_data);	// Get current boot reg
	if (ifunc < 0) goto L300;				// Bang mode

	printf("\tBoot=%4.4X Adr=%6.6X\n",rd_data,boot_adr);

	for (i=0; i<=15; ++i) {
		boot_decode[i]=(rd_data >> i) & 0x1;
	}

	i=0;
	printf("\n");
	printf("\t[%2.2i]%2i  R/W jtag_vme1  (tdi) vme tdi\n",				i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W jtag_vme2  (tms) vme tms\n",				i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W jtag_vme3  (tck) vme tck\n",				i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W sel_vme0    00XX ALCT JTAG Chain\n",		i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W sel_vme1    01XX TMB Mezzanine FPGA\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W sel_vme2    10XX TMB User PROMs JTAG\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W sel_vme3    11XX TMB FPGA User JTAG\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W vme/usr_en  1=JTAG sourced by Boot\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W HardRstAlct 1=Hard reset to ALCT FPGA\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W HardRstTmb  1=Hard reset to TMB FPGA\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W /EnResetAlct0=Allow TMB reset ALCT\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W /FpgaVmeEn  1=Allow TMB to issue VME\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W /MezClockEn 0=Enable TMB mez clock\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R/W HardResetRpc1=Hard reset to RAT\n",		i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R   vme_ready   1=FPGA vme logic ready\n",	i,boot_decode[i]); i++;
	printf("\t[%2.2i]%2i  R   jtag_vme0   (tdo) vme tdo\n",				i,boot_decode[i]); i++;

	printf("\n\t<cr> to continue:");
	gets(line);

	return;
}
//------------------------------------------------------------------------------
//	Peek/Poke an arbitrary address
//------------------------------------------------------------------------------
void L400() {
L400:

	bang_read =false;
	bang_write=false;

	printf("\tPeek/Poke(hex): read=r,adr | write=w,adr,wrdata | inc adr=<cr> | e=exit\n");
	adr=base_adr;

L420:
	rd_data=0xFFFF;		// clear out previous read, bit 3 doesn't update rd_data if no dtack
	status = vme_read(adr,rd_data);
	if (bang_read) goto L420;

	printf("\tadr=%6.6X data=%4.4X r/w/e,adr,wrdata=",adr,rd_data);
	gets(line);
	n=strlen(line);
	dprintf(stdout,"length=%i\n",n);

	// <cr> = increment address
	if (line[0]==NULL) {
		adr=adr+2;
		goto L420;
	}

	// Parse input string into adr and wr_data
	if (n < 1) goto L400;

	sscanf(line,"%c,%X,%X",&rwe,&newadr,&newdata);
	dprintf(stdout,"rwe=%c newadr=%6.6X newdata=%4.4X\n",rwe,newadr,newdata);

	// e=exit
	if ((rwe=='e') || (rwe=='E')) return;
	if ((rwe=='R') || (rwe=='W')) printf("\tBang mode....\n");

	//	Check adr is even and 24 bits or less and data is 16 bits or less
	if ((newadr >> 24) != 0) {
		printf("dumbass: address exceeds 24 bits\n");
		goto L420;
	}
	if ((newadr & 0x1) != 0) {
		printf("dumbass: address must be even\n");
		goto L420;
	}

	// If address is for slot 0, assume it is relative to current base address
	if (newadr < 0x080000)newadr=newadr | base_adr;

	/// r = read data at new address
	if (rwe=='R')bang_read=true;
	if ((rwe=='r') || (rwe=='R')) {	
		adr=newadr;
		goto L420;
	}

	// w = write data at address
	if (rwe=='W')bang_write=true;
	if ((rwe=='w') || (rwe=='W')) {

		if ((newdata >> 16) != 0) {
			printf("dumbass: write data exceeds 16 bits\n");
			goto L420;
		}

		adr=newadr;
		wr_data=(unsigned short)newdata;
L480:	
		status = vme_write(adr,wr_data);
		if (bang_write) goto L480;
		goto L420;
	}
	goto L400;
}
//------------------------------------------------------------------------------
//	Read Trigger/Error/Discard counters + HCM
//------------------------------------------------------------------------------
void L500() {
	//L500:

	// Take snapshot of current counter state
	adr = base_adr+cnt_ctrl_adr;
	wr_data=0x0022;	//snap
	status = vme_write(adr,wr_data);
	wr_data=0x0020;	//unsnap
	status = vme_write(adr,wr_data);

	// Read counters
	for (i=0; i<mxcounter; ++i) {
		for (j=0; j<=1; ++j) {
			adr = base_adr+cnt_ctrl_adr;
			wr_data=(i << 9) | 0x0020 | (j << 8);
			status = vme_write(adr,wr_data);
			adr = base_adr+cnt_rdata_adr;
			status = vme_read(adr,rd_data);

			// Combine lsbs+msbs
			if (j==0)			// Even addresses contain counter LSBs
				cnt_lsb=rd_data;
			else {				// Odd addresses contain counter MSBs
				cnt_msb=rd_data;
				cnt_full=cnt_lsb | (cnt_msb << 16);
				cnt[i]=cnt_full;	// Assembled counter MSB,LSB
			}
		}}	//close j,i

	// Read parity status
	adr = base_adr+parity_adr;
	status = vme_read(adr,rd_data);
	dprintf(stdout,"adr=%6.6X rd_data=%4.4X\n",adr,rd_data);

	perr_adr		= (rd_data >>  0) & 0xF;
	perr_en			= (rd_data >>  4) & 0x1;
	perr			= (rd_data >>  5) & 0x1;
	perr_ff			= (rd_data >>  6) & 0x1;
	perr_reset_vme	= (rd_data >>  7) & 0x1;
	perr_free		= (rd_data >>  8) & 0x3;

	for (perr_adr=0; perr_adr<=10; perr_adr++) {
		wr_data = perr_adr;
		status  = vme_write(adr,wr_data);
		status  = vme_read (adr,rd_data);
		dprintf(stdout,"perr_data=%4.4X\n",rd_data);

		perr_mux= (rd_data >> 10) & 0x3F;

		if (perr_adr==0x0) {for (i=0; i<=5; ++i)	perr_ram_cfeb0[i] = (perr_mux >> i) & 0x1;}
		if (perr_adr==0x1) {for (i=0; i<=5; ++i)	perr_ram_cfeb1[i] = (perr_mux >> i) & 0x1;}
		if (perr_adr==0x2) {for (i=0; i<=5; ++i)	perr_ram_cfeb2[i] = (perr_mux >> i) & 0x1;}
		if (perr_adr==0x3) {for (i=0; i<=5; ++i)	perr_ram_cfeb3[i] = (perr_mux >> i) & 0x1;}
		if (perr_adr==0x4) {for (i=0; i<=5; ++i)	perr_ram_cfeb4[i] = (perr_mux >> i) & 0x1;}

		if (perr_adr==0x5) {for (i=0; i<=4; ++i)	perr_ram_rpc[i]   = (perr_mux >> i) & 0x1;}
		if (perr_adr==0x6) {for (i=0; i<=1; ++i)	perr_ram_mini[i]  = (perr_mux >> i) & 0x1;}

		if (perr_adr==0x7) {						perr_cfeb         = (perr_mux >> 0) & 0x1F;}
		if (perr_adr==0x8) {						perr_cfeb_ff      = (perr_mux >> 0) & 0x1F;}
		if (perr_adr==0x9) {						perr_rpc          = (perr_mux >> 0) & 0x1; perr_rpc_ff = (perr_mux >> 1) & 0x1;}
		if (perr_adr==0xA) {						perr_mini         = (perr_mux >> 0) & 0x1; perr_mini_ff= (perr_mux >> 1) & 0x1;}
	}

	// Read CCB status register 0
	adr = base_adr+ccb_stat0_adr;
	status = vme_read(adr,rd_data);

	ccb_cmd				= (rd_data >>  0) & 0xFF;		// R	CCB command word
	ccb_clock40_enable	= (rd_data >>  8) & 0x1;		// R	Enable 40MHz clock
	ccb_ttcrx_ready		= (rd_data >>  9) & 0x1;		// R	ccb_ttcrx_ready
	ccb_qpll_locked		= (rd_data >> 10) & 0x1;		// R	ccb_qpll_locked
	ccb_reserved		= (rd_data >> 11) & 0x7;		// R	Unassigned
	ccb_bcntres			= (rd_data >> 14) & 0x1;		// R	Bunch crossing counter reset, backplane
	ccb_bx0				= (rd_data >> 15) & 0x1;		// R	Bunch crossing 0 from backplane

	// Read CCB status register 1
	adr = base_adr+ccb_stat1_adr;
	status = vme_read(adr,rd_data);

	ccb_ttcrx_lock_never= (rd_data >> 0) & 0x1;			// Lock never achieved
	ccb_ttcrx_lost_ever	= (rd_data >> 1) & 0x1;			// Lock was lost at least once
	ccb_qpll_lock_never	= (rd_data >> 2) & 0x1;			// Lock never achieved
	ccb_qpll_lost_ever	= (rd_data >> 3) & 0x1;			// Lock was lost at least once

	// Read Sync error registers
	adr     = base_adr+sync_err_ctrl_adr;
	status  = vme_read(adr,rd_data);
	sync_err_reset            = (rd_data >>  0) & 0x1;
	clct_bx0_sync_err_en      = (rd_data >>  1) & 0x1;
	alct_ecc_rx_err_en        = (rd_data >>  2) & 0x1;
	alct_ecc_tx_err_en        = (rd_data >>  3) & 0x1;
	bx0_match_err_en          = (rd_data >>  4) & 0x1;
	clock_lock_lost_err_en    = (rd_data >>  5) & 0x1;
	sync_err_blanks_mpc_en    = (rd_data >>  6) & 0x1;
	sync_err_stops_pretrig_en = (rd_data >>  7) & 0x1;
	sync_err_stops_readout_en = (rd_data >>  8) & 0x1;
	sync_err                  = (rd_data >>  9) & 0x1; 
	clct_bx0_sync_err         = (rd_data >> 10) & 0x1; 
	alct_ecc_rx_err_ff        = (rd_data >> 11) & 0x1; 
	alct_ecc_tx_err_ff        = (rd_data >> 12) & 0x1; 
	bx0_match_err_ff          = (rd_data >> 13) & 0x1; 
	clock_lock_lost_err_ff    = (rd_data >> 14) & 0x1; 
	sync_err_force            = (rd_data >> 15) & 0x1;

	adr    = seq_clctm_adr+base_adr;
	status = vme_read(adr,rd_data);
	clock_lost_lost_clct   = (rd_data >> 14) & 0x1;
	clct_bx0_sync_err_clct = (rd_data >> 15) & 0x1;

	// Read Hot Channel Mask 15 registers, 2 layers each, 3 adrs per cfeb
	for (iadr =0; iadr<30; iadr=iadr+2) {

		hcm_adr = hcm001_adr + iadr;
		icfeb   = iadr/6;
		ilayer  = iadr%6;
		adr     = base_adr+hcm_adr;
		status  = vme_read(adr,rd_data);

		hcm_data0 = (rd_data >> 0); 
		hcm_data1 = (rd_data >> 8); 

		for (ids=0; ids<=7; ++ids) {
			hot_channel_mask[icfeb][ilayer+0][ids] = (hcm_data0 >> ids) & 0x1;
			hot_channel_mask[icfeb][ilayer+1][ids] = (hcm_data1 >> ids) & 0x1;
		}}

	// Read buffer status
	adr    = buf_stat0_adr+base_adr;
	status = vme_read(adr,rd_data);

	wr_buf_ready	= (rd_data >>  0) & 0x1;		// Write buffer is ready
	buf_stalled		= (rd_data >>  1) & 0x1;		// Buffer write pointer hit a fence and stalled
	buf_q_full		= (rd_data >>  2) & 0x1;		// All raw hits ram in use, ram writing must stop
	buf_q_empty		= (rd_data >>  3) & 0x1;		// No fences remain on buffer stack
	buf_q_ovf_err	= (rd_data >>  4) & 0x1;		// Tried to push when stack full
	buf_q_udf_err	= (rd_data >>  5) & 0x1;		// Tried to pop when stack empty
	buf_q_adr_err	= (rd_data >>  6) & 0x1;		// Fence adr popped from stack doesnt match rls adr
	buf_display		= (rd_data >>  8) & 0xFF;		// Buffer fraction in use display

	adr    = buf_stat1_adr+base_adr;
	status = vme_read(adr,rd_data);
	wr_buf_adr = (rd_data >> 0) & 0x7FF;			// Current ddress of header write buffer

	adr    = buf_stat2_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_dist = (rd_data >> 0) & 0x7FF;		// Distance to 1st fence address
	buf_free_space  = int(100.*float(buf_fence_dist)/2047.);

	adr    = buf_stat3_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_cnt = (rd_data >> 0) & 0x7FF;			// Number of fences in fence RAM currently

	adr    = buf_stat4_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_cnt_peak=(rd_data >> 0) & 0xFFF;		// Peak number of fences in fence RAM

	// Get current FMM state
	adr    = base_adr+ccb_cmd_adr;
	status = vme_read(adr,rd_data);
	fmm_state = (rd_data >> 4) & 0x0007;

	// Get current Sequencer state and L1A queue status
	adr     = base_adr+seqsm_adr;
	status  = vme_read(adr,rd_data);
	clct_sm = (rd_data >> 0) & 0x7;
	read_sm = (rd_data >> 3) & 0x1F;

	queue_full = (rd_data >>  8) & 0x1;
	queue_empty= (rd_data >>  9) & 0x1;
	queue_ovf  = (rd_data >> 10) & 0x1;
	queue_udf  = (rd_data >> 11) & 0x1;

	// Dislay counters
	//	unit = log_file;
	unit = stdout;
	if (unit!=stdout) printf("\tWriting counters to log file!\n");

	for (i=0; i<mxcounter; ++i) {
		fprintf(unit,"\t%2.2i %10i %s\n",i,cnt[i],scnt[i].c_str());
	}

	// Display parity
	fprintf(unit,"\n");
	fprintf(unit,"\tperr_cfeb     %2.2X\n",perr_cfeb);
	fprintf(unit,"\tperr_rpc      %2.2X\n",perr_rpc);
	fprintf(unit,"\tperr_mini     %2.2X\n",perr_mini);
	fprintf(unit,"\tperr_en       %2.2X\n",perr_en);
	fprintf(unit,"\tperr          %2.2X\n",perr);
	fprintf(unit,"\tperr_cfeb_ff  %2.2X\n",perr_cfeb_ff);
	fprintf(unit,"\tperr_rpc_ff   %2.2X\n",perr_rpc_ff);
	fprintf(unit,"\tperr_mini_ff  %2.2X\n",perr_mini_ff);
	fprintf(unit,"\tperr_ff       %2.2X\n",perr_ff);
	fprintf(unit,"\n");

	// Display parity ram
	fprintf(unit,"\tperr_ram_cfeb0[5:0]="); for (i=5; i>=0; --i) fprintf(unit,"%1i",perr_ram_cfeb0[i]); fprintf(unit,"\n");
	fprintf(unit,"\tperr_ram_cfeb1[5:0]="); for (i=5; i>=0; --i) fprintf(unit,"%1i",perr_ram_cfeb1[i]); fprintf(unit,"\n");
	fprintf(unit,"\tperr_ram_cfeb2[5:0]="); for (i=5; i>=0; --i) fprintf(unit,"%1i",perr_ram_cfeb2[i]); fprintf(unit,"\n");
	fprintf(unit,"\tperr_ram_cfeb3[5:0]="); for (i=5; i>=0; --i) fprintf(unit,"%1i",perr_ram_cfeb3[i]); fprintf(unit,"\n");
	fprintf(unit,"\tperr_ram_cfeb4[5:0]="); for (i=5; i>=0; --i) fprintf(unit,"%1i",perr_ram_cfeb4[i]); fprintf(unit,"\n");
	fprintf(unit,"\tperr_ram_rpc  [4:0]="); for (i=4; i>=0; --i) fprintf(unit,"%1i",perr_ram_rpc[i]);   fprintf(unit,"\n");
	fprintf(unit,"\tperr_ram_mini [1:0]="); for (i=1; i>=0; --i) fprintf(unit,"%1i",perr_ram_mini[i]);  fprintf(unit,"\n");

	// Display CCB lock
	fprintf(unit,"\n");
	fprintf(unit,"\tccb_cmd             %2.2X\n",	ccb_cmd);
	fprintf(unit,"\tccb_clock40_enable   %1X\n",	ccb_clock40_enable);
	fprintf(unit,"\tccb_ttcrx_ready      %1X\n",	ccb_ttcrx_ready);
	fprintf(unit,"\tccb_qpll_locked      %1X\n",	ccb_qpll_locked);
	fprintf(unit,"\tccb_reserved         %1X\n",	ccb_reserved);
	fprintf(unit,"\tccb_bcntres          %1X\n",	ccb_bcntres);
	fprintf(unit,"\tccb_bx0              %1X\n",	ccb_bx0);

	fprintf(unit,"\n");
	fprintf(unit,"\tccb_ttcrx_lock_never %1X\n",	ccb_ttcrx_lock_never);
	fprintf(unit,"\tccb_ttcrx_lost_ever  %1X\n",	ccb_ttcrx_lost_ever);
	fprintf(unit,"\tccb_qpll_lock_never  %1X\n",	ccb_qpll_lock_never);
	fprintf(unit,"\tccb_qpll_lost_ever   %1X\n",	ccb_qpll_lost_ever);

	// Display sync error registers
	fprintf(unit,"\n");
	fprintf(unit,"\tTMB2005E Sync Status\n");
	fprintf(unit,"\tsync_err_reset            = %1i\n",sync_err_reset);
	fprintf(unit,"\tclct_bx0_sync_err_en      = %1i\n",clct_bx0_sync_err_en);
	fprintf(unit,"\talct_ecc_rx_err_en        = %1i\n",alct_ecc_rx_err_en);
	fprintf(unit,"\talct_ecc_tx_err_en        = %1i\n",alct_ecc_tx_err_en);
	fprintf(unit,"\tbx0_match_err_en          = %1i\n",bx0_match_err_en);
	fprintf(unit,"\tclock_lock_lost_err_en    = %1i\n",clock_lock_lost_err_en);

	fprintf(unit,"\tsync_err_blanks_mpc_en    = %1i\n",sync_err_blanks_mpc_en);
	fprintf(unit,"\tsync_err_stops_pretrig_en = %1i\n",sync_err_stops_pretrig_en);
	fprintf(unit,"\tsync_err_stops_readout_en = %1i\n",sync_err_stops_readout_en);

	fprintf(unit,"\tsync_err                  = %1i\n",sync_err);
	fprintf(unit,"\tclct_bx0_sync_err         = %1i\n",clct_bx0_sync_err);
	fprintf(unit,"\talct_ecc_rx_err_ff        = %1i\n",alct_ecc_rx_err_ff);
	fprintf(unit,"\talct_ecc_tx_err_ff        = %1i\n",alct_ecc_tx_err_ff);
	fprintf(unit,"\tbx0_match_err_ff          = %1i\n",bx0_match_err_ff);
	fprintf(unit,"\tclock_lock_lost_err_ff    = %1i\n",clock_lock_lost_err_ff);

	fprintf(unit,"\tsync_err_force            = %1i\n",sync_err_force);

	fprintf(unit,"\tclock_lost_lost_clct      = %1i\n",clock_lost_lost_clct);
	fprintf(unit,"\tclct_bx0_sync_err_clct    = %1i\n",clct_bx0_sync_err_clct);

	// Display buffer state
	fprintf(unit,"\n\tRaw hits buffer:\n");
	fprintf(unit,"\twr_buf_ready   %4i\n",wr_buf_ready);
	fprintf(unit,"\tbuf_stalled    %4i\n",buf_stalled);
	fprintf(unit,"\tbuf_q_full     %4i\n",buf_q_full);
	fprintf(unit,"\tbuf_q_empty    %4i\n",buf_q_empty);
	fprintf(unit,"\tbuf_q_ovf_err  %4i\n",buf_q_ovf_err);
	fprintf(unit,"\tbuf_q_udf_err  %4i\n",buf_q_udf_err);
	fprintf(unit,"\tbuf_q_adr_err  %4i\n",buf_q_adr_err);
	fprintf(unit,"\tbuf_display    %4i\n",buf_display);
	fprintf(unit,"\twr_buf_adr     %4i\n",wr_buf_adr);
	fprintf(unit,"\tbuf_fence_dist %4i\n",buf_fence_dist);
	fprintf(unit,"\tbuf_fence_cnt  %4i\n",buf_fence_cnt);
	fprintf(unit,"\tbuf_fence_peak %4i\n",buf_fence_cnt_peak);
	fprintf(unit,"\tbuf_free_space %4i\n",buf_free_space);

	fprintf(unit,"\n\tTrigger status:\n");
	fprintf(unit,"\tFMM state      %4i %s\n",fmm_state,sfmm_state[fmm_state%5].c_str());
	fprintf(unit,"\tclct_sm  state %4i %s\n",clct_sm,sclct_sm[clct_sm%6].c_str());
	fprintf(unit,"\tread_sm  state %4i %s\n",read_sm,sread_sm[read_sm%21].c_str());

	fprintf(unit,"\n\tReadout queue:\n");
	fprintf(unit,"\tqueue_full     %4i\n",queue_full);
	fprintf(unit,"\tqueue_empty    %4i\n",queue_empty);
	fprintf(unit,"\tqueue_ovf      %4i\n",queue_ovf);
	fprintf(unit,"\tqueue_udf      %4i\n",queue_udf);

	// Display Hot Channel Mask  cfeb and ids column markers
	fprintf(unit,"\n");
	fprintf(unit,"\tHot Channel Mask\n");

	fprintf(unit,"\tCfeb-");
	for (icfeb=0; icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|"); // display cfeb columms
		for (ids=0;   ids   < mxds;   ++ids  )   fprintf(unit,"%1.1i",icfeb);}
	fprintf(unit,"|\n");

	fprintf(unit,"\tDs---");
	for (icfeb=0; icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|",x);	// display ids columns
		for (ids=0;   ids   < mxds;   ++ids  )   fprintf(unit,"%1.1i",ids%10);}
	fprintf(unit,"|\n");
	fprintf(unit,"\t     ----------------------------------------------\n");

	// Display HCM masked distrip triads
	for (ilayer=0; ilayer <= mxly-1;         ++ilayer)        {
		fprintf(unit,"\tLy%1i  ",ilayer);

		for (ids_abs=0;ids_abs<=39;++ids_abs) {
			if (ids_abs%8==0) {fprintf(unit,"|");}
			ids   = ids_abs%8;
			icfeb = ids_abs/8;
			fprintf(unit,"%1.1x",hot_channel_mask[icfeb][ilayer][ids]);
		}	// close for ids_abs
		fprintf(unit,"|\n");
	}	// close ilayer
	fprintf(unit,"\n");

	// Clear bx0 Sync error
	inquirb("\tClear bx0 sync error   [y|n]? cr=%3c", bans=false);

	if (bans) {
		printf("\tFiring resync now boss\n");
		adr     = ccb_cfg_adr+base_adr;			// Turn off CCB backplane inputs
		status  = vme_read(adr,rd_data);
		wr_data = rd_data | 0x8001;				// ccb_ignore_rx + enable bx0 emulator
		status  = vme_write(adr,wr_data);

		adr     = base_adr+ccb_cmd_adr;			// Turn off ccb_cmd_strobe, disconnect ccb backplane
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);

		ttc_cmd = 3;							// ttc_resync
		adr     = base_adr+ccb_cmd_adr;			// Turn off ccb_cmd_strobe, disconnect ccb backplane
		wr_data = 0x0003 | (ttc_cmd << 8);
		status  = vme_write(adr,wr_data);
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);
	}

	// Clear sync error flip flop
	inquirb("\tClear sync error FF    [y|n]? cr=%3c", bans=false);

	if (bans) {
		printf("\tClearing sync ff now boss\n");

		adr     = base_adr+sync_err_ctrl_adr;
		status  = vme_read(adr,rd_data);
		wr_data = rd_data |  1;		// assert clear
		status  = vme_write(adr,wr_data);
		wr_data = rd_data & ~0x1;	// deassert
		status  = vme_write(adr,wr_data);
	}

	// Clear ALL counters
	inquirb("\tClear ALL counters     [y|n]? cr=%3c", bans=false);

	if (bans) {
		printf("\tClearing it now boss\n");
		adr     = base_adr+ccb_cfg_adr;
		status  = vme_read(adr,rd_data);
		wr_data = rd_data & ~(1 << 12);			// Clear 2A[12] vme_evcntres
		status  = vme_write(adr,wr_data);
		wr_data = rd_data | (1 << 12);			// Set   2A[12] vme_evcntres
		status  = vme_write(adr,wr_data);
		wr_data = rd_data & ~(1 << 12);			// Clear 2A[12] vme_evcntres
		status  = vme_write(adr,wr_data);
	}

	// Clear VME counters
	inquirb("\tClear VME counters     [y|n]? cr=%3c", bans=false);

	if (bans) {
		printf("\tClearing it now boss\n");
		adr    = base_adr+cnt_ctrl_adr;
		wr_data= 0x0021;	// Clear
		status = vme_write(adr,wr_data);
		wr_data= 0x0020;	// Unclear
		status = vme_write(adr,wr_data);
	}

	// Clear parity errors
	inquirb("\tClear Parity errors?   [y|n]? cr=%3c", bans=false);

	if (bans) {
		printf("\tClearing it now boss\n");
		adr    = base_adr+parity_adr;
		status = vme_read(adr,rd_data);	// Get current parity register
		wr_data= rd_data & ~(1 << 7);	// Clears old perr_reset_vme bit 6 to turn off oneshot
		status = vme_write(adr,wr_data);
		wr_data= wr_data |  (1 << 7);	// Fires oneshot to clear perr
		status = vme_write(adr,wr_data);
		wr_data= wr_data & ~(1 << 7);	// Unclear turns off oneshot
		status = vme_write(adr,wr_data);
	}

	// Clear Header counters
	inquirb("\tClear Header counters  [y|n]? cr=%3c", bans=false);

	if (bans) {
		printf("\tClearing it now boss\n");

		adr     = base_adr+cnt_ctrl_adr;
		wr_data = 0x00A0;				// Enable ttc_resync clears header counters
		status  = vme_write(adr,wr_data);

		adr     = base_adr+ccb_cmd_adr;	// Turn off ccb_cmd_strobe, disconnect ccb backplane
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);

		ttc_cmd = 3;		// ttc_resync
		wr_data = 0x0003 | (ttc_cmd << 8);
		status  = vme_write(adr,wr_data);
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);

		ttc_cmd=1;			// bx0
		wr_data = 0x0003 | (ttc_cmd << 8);
		status  = vme_write(adr,wr_data);
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);
	}
	return;
}
//------------------------------------------------------------------------------
//	Read/Write 3D3444 Delay using State Machine:
//------------------------------------------------------------------------------
void L600() {
L600:

	ddd_error = 0;
	dddr_error= 0;
	ipass     = 0;
	srand(1);

	// Get current TMB+RAT delay values
	for (i=0; i<=3; ++i) {	// 0,1,2=tmb 3=rat
		if (i<=2) adr=base_adr+vme_ddd0_adr+2*i;
		if (i==3) adr=base_adr+dddr0_adr;
		status=vme_read(adr,rd_data);
		ddd_read[i*4  ] = (rd_data >>  0) & 0xF;
		ddd_read[i*4+1] = (rd_data >>  4) & 0xF;
		ddd_read[i*4+2] = (rd_data >>  8) & 0xF;
		ddd_read[i*4+3] = (rd_data >> 12) & 0xF;
	}

	// Get current delay channel enables
	adr    = base_adr+vme_dddoe_adr;
	status = vme_read(adr,rd_data);
	for (i=0; i<=11; ++i) {
		ddd_enable[i]=(rd_data >> i) & 0x1;
	}

	adr    = base_adr+dddrsm_adr;	// oe[11:8]
	status = vme_read(adr,rd_data);
	for (i=0; i<=3; ++i) {			// 12 to 15
		ddd_enable[i+12]=(rd_data >> (i+8)) & 0x1;
	}

	// Display current delay values
	printf("\n\tCurrent 3D3444 Delay Settings\n");
	for (i=0; i<=15; ++i) {
		printf("\tCh%1X  " ,i);
		printf("%2isteps  ",ddd_read[i]);
		printf("%2ins  "   ,ddd_read[i]*2);
		printf("%s"        ,ddd_name[i].c_str());
		printf(" En=%1i\n" ,ddd_enable[i]);
	}

	// Display machine status
	adr      = base_adr+vme_dddsm_adr;
	status   = vme_read(adr,rd_data);
	ddd_busy =    (rd_data >> 6) & 0x1;
	ddd_verify_ok=(rd_data >> 7) & 0x1;

	adr       = base_adr+dddrsm_adr;
	status    = vme_read(adr,rd_data);
	dddr_busy =    (rd_data >> 6) & 0x1;
	dddr_verify_ok=(rd_data >> 7) & 0x1;

	printf("\tTMB: busy=%1i verify_ok=%1i\n",ddd_busy,ddd_verify_ok);
	printf("\tRAT: busy=%1i verify_ok=%1i\n",dddr_busy,dddr_verify_ok);

	// Get new value
L610:
	ddd_delay=0;
	printf("\n\tEnter Channel,Delay <cr>=exit,ch w=write current, L=loop: ");
	gets(line);
	n=strlen(line);
	sscanf(line,"%c,%X",&cch,&ddd_delay);

	if (line[0] == NULL) return;
	debug_loop=false;
	if ((cch=='l') || (cch=='L')) debug_loop=true;
	if ((cch=='w') || (cch=='W')) goto L630;		// Skip update if write current
	if (debug_loop) goto L630;						// Skip update in loop mode
	sscanf(line,"%X",&ich);							// Convert character to integer
	if ((ich >= 0) && (ich <= 15) && (ddd_delay >= 0) && (ddd_delay <= 15)) goto L620;
	printf("\tDumbass...value out of range\n");
	goto L610;

	// Write new value to 3D3444 data registers
L620:	
	printf("\tWriting to 3D3444s");
	ddd_read[ich]=ddd_delay;
	for (i=0; i<=3; ++i) {
		if (i <= 2) adr=base_adr+vme_ddd0_adr+2*i;
		if (i == 3) adr=base_adr+dddr0_adr;
		wr_data=(ddd_read[i*4+0] <<  0) |
			(ddd_read[i*4+1] <<  4) |
			(ddd_read[i*4+2] <<  8) |
			(ddd_read[i*4+3] << 12);
		status  = vme_write(adr,wr_data);
	}

	// Start DDD state machine, fires TMB and RAT machines in parallel
L630:
	adr	    = base_adr+vme_dddsm_adr;
	status  = vme_read(adr,rd_data);
	autostart    = rd_data & 0x0020;				// Get current autostart state
	dddr_linktmb = (1 << 12);						// Link rat machine to tmb
	wr_data	= 0x0000 | autostart | dddr_linktmb;	// Stop machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0001 | autostart | dddr_linktmb;	// Start machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0000 | autostart | dddr_linktmb;	// Unstart machine
	status	= vme_write(adr,wr_data);

	// Wait for it to finish
L640:
	status  =  vme_read(adr,rd_data);
	ddd_busy      = (rd_data >> 6) & 0x1;
	ddd_verify_ok = (rd_data >> 7) & 0x1;

	adr    = base_adr+dddrsm_adr;
	status = vme_read(adr,rd_data);
	dddr_busy      = (rd_data >> 6) & 0x1;
	dddr_verify_ok = (rd_data >> 7) & 0x1;

	if ((ifunc > 0) && !debug_loop) printf(".");
	if (ddd_busy == 1) goto L640;

	if (debug_loop) {
		if (ddd_verify_ok  != 1) ddd_error++;
		if (dddr_verify_ok != 1) dddr_error++;
		ipass++;
		if (ipass%10000==0)
			printf("\tpass=%10i TMB verify errs=%i  RAT verify errs=%1i\n",ipass,ddd_error,dddr_error);
		goto L630;
	}

	// Bang mode write random delays and checks verify bits
	if (ifunc < 0)
	{
		adr     = base_adr+vme_dddoe_adr;	// Random TMB channel enables
		rnd     = rand()/(float(RAND_MAX)+1); 
		wr_data = int(4096*rnd) & 0x0FFF;
		status  = vme_write(adr,wr_data);

		adr     = base_adr+dddrsm_adr;		// Random RAT channel enables	oe[11:8]
		rnd     = rand()/(float(RAND_MAX)+1); 
		wr_data = int(16*rnd) & 0xF;
		status  = vme_read(adr,rd_data);
		rd_data = rd_data & 0xF0FF;
		rd_data = rd_data | (wr_data << 8);
		wr_data = rd_data;
		status  = vme_write(adr,wr_data);

		for (i=0; i<=15; ++i) {				// Fill delay registers with random data
			rnd     = rand()/(float(RAND_MAX)+1); 
			wr_data = int(16*rnd) & 0xF;
			ddd_read[i]=wr_data;
		}

		for (i=0; i<=3; ++i) {				// Write registers to TMB
			if (i <= 2) adr=base_adr+vme_ddd0_adr+2*i;
			if (i == 3) adr=base_adr+dddr0_adr;
			wr_data=(ddd_read[i*4  ] <<  0) | 
				(ddd_read[i*4+1] <<  4) | 
				(ddd_read[i*4+2] <<  8) | 
				(ddd_read[i*4+3] << 12);
			status=vme_write(adr,wr_data);
		}

		if (ddd_verify_ok  != 1)ddd_error++;
		if (dddr_verify_ok != 1)dddr_error++;
		ipass++;

		if (ipass%10000==0) {
			printf("\r");
			printf("\tpass=%10i TMB verify errs=%i  RAT verify errs=%1i\n",ipass,ddd_error,dddr_error);
			//	adr     = base_adr+dddrsm_adr;
			//	status  = vme_read(adr,rd_data);				 // Get current rx delay + phase
			//	printf("dly/phase=%1X\n",((rd_data >> 13) & 0x7));
			//	wr_data = rd_data+0x2000;						// Increment
			//	status  = vme_write(adr,wr_data);
			//	dddr_error = 0;
		}	// Close passes

		goto L630;
	} // close ifunc

	// Result summary
	printf("\tTMB: busy=%1i verify_ok=%1i\n",ddd_busy,ddd_verify_ok);
	printf("\tRAT: busy=%1i verify_ok=%1i\n",dddr_busy,dddr_verify_ok);

	if ((ddd_verify_ok==0) || (dddr_verify_ok==0))printf("\n\tVerify FAILED!!!!!!!!!!\n");
	goto L600;
}
//------------------------------------------------------------------------------
//	Hard Reset TMB
//------------------------------------------------------------------------------
void L700() {
L700:
	status  = vme_read(boot_adr,rd_data);			// Get current boot reg
	wr_data = rd_data | 0x0200;						// Turn on  TMB hard reset
	status  = vme_write(boot_adr,wr_data);			// Assert   TMB hard reset

	wr_data = rd_data & ~0x0200;					// Turn off TMB hard reset
	status  = vme_write(boot_adr,wr_data);			// Restore boot reg

	if      (fpga_series=="XC2V4000"  ) sleep(150);	// Wait for TMB to reload
	else if (fpga_series=="XC6SLX150" ) sleep(250);
	else if (fpga_series=="XC6VLX195T") sleep(4000);
	else							    sleep(150);

	if (ifunc <0 ) goto L700;						// Bang mode
	return;											// Get latest firmware type
}
//------------------------------------------------------------------------------
//	Hard Reset ALCT
//------------------------------------------------------------------------------
void L800() {
L800:

	status  = vme_read(boot_adr,rd_data);			// Get current boot reg
	wr_data = rd_data | 0x0100;						// Turn on  ALCT hard reset
	status  = vme_write(boot_adr,wr_data);			// Assert   ALCT hard reset

	wr_data = rd_data & ~0x0100;					// Turn off ACLT hard reset
	status  = vme_write(boot_adr,wr_data);			// Restore boot reg
	sleep(150);										// Wait for ALCT to reload
	if (ifunc < 0) goto L800;						// Bang mode
	return;
}
//------------------------------------------------------------------------------
//	Read DMB Raw Hits RAM from tmb2004a logic
//------------------------------------------------------------------------------
void L900() {
L900:

	if (firmware_type != firmware_normal) {
		pause("TMB has wrong firmware type for this operation");
		return;
	}

	// Get DMB RAM word count and busy bit
	adr    = dmb_wdcnt_adr+base_adr;
	status = vme_read(adr,rd_data);

	dmb_wdcnt = rd_data & 0x0FFF;
	dmb_busy  = (rd_data >> 14) & 0x0001;

	printf("\tword count = %4i\n",dmb_wdcnt);
	printf("\tbusy       = %4i\n",dmb_busy);
	printf("\tword count = %4i\n",dmb_wdcnt);
	printf("\tbusy       = %4i\n",dmb_busy);

	if (dmb_busy != 0) {
		pause ("Can not read RAM: dmb reports busy");
		goto L910;
	}

	if (dmb_wdcnt <= 0) {
		pause("Can not read RAM: dmb reports word count <=0");
		goto L910;
	}

	// Write RAM read address to TMB
	for (i=0; i<=(dmb_wdcnt-1); ++i) { 
		adr     = dmb_ram_adr+base_adr;
		wr_data = i & 0xFFFF;
		status  = vme_write(adr,wr_data);

		// Read RAM data from TMB
		adr    = dmb_rdata_adr+base_adr;
		status = vme_read(adr,rd_data);			// read lsbs
		dmb_rdata_lsb = rd_data;

		adr    = dmb_wdcnt_adr+base_adr;
		status = vme_read(adr,rd_data);			// read msbs
		dmb_rdata_msb = (rd_data >> 12) & 0x3;	// rdata msbs
		dmb_rdata     = dmb_rdata_lsb | (dmb_rdata_msb << 16);

		fprintf(log_file,"Adr=%4i Data=%5.5X\n",dmb_rdata);
		fprintf(stdout,  "Adr=%4i Data=%5.5X\n",dmb_rdata);
		//	if (i%16 != 0) pause("next");
	}	// close for i

	//	Clear RAM address, reset for next event
L910:
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	// reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Bang mode
	if (ifunc < 0) goto L900;
	return;
}
//------------------------------------------------------------------------------
//	Walking 1 Test Sub-Menu
//------------------------------------------------------------------------------
void L1000() {
L1000:

	if (firmware_type!=firmware_debug) {
		pause("TMB has wrong firmware type for this operation");
		return;
	}

	// Display menu
	printf("\n");
	printf("\tTMB Walking 1 Test Submenu:\n");
	printf("\t0:   CFEB0\n");
	printf("\t1:   CFEB1\n");
	printf("\t2:   CFEB2\n");
	printf("\t3:   CFEB3\n");
	printf("\t4:   CFEB4\n");
	printf("\t5:   ALCTscsi (-5 walk forever)\n");
	printf("\t6:   ALCTtrans\n");
	printf("\t7:   RPC\n");
	printf("\t8:   DMB (-8 walk 1 forever)\n");
	printf("\t9:   MPC (-9 walk 1 forever)\n");
	printf("\t10:  CCB\n");
	printf("\t11:  VME\n");
	printf("\t<cr> Exit\n");
	printf("       > ");

	gets(line);
	if (line[0]==NULL) return;
	sscanf(line,"%i",&ifunc);

	i=abs(ifunc);
	if (i== 0) goto L10100;
	if (i== 1) goto L10100;
	if (i== 2) goto L10100;
	if (i== 3) goto L10100;
	if (i== 4) goto L10100;
	if (i== 5) goto L10500;
	if (i== 6) goto L10600;
	if (i== 7) goto L10700;
	if (i== 8) goto L10800;
	if (i== 9) goto L10900;
	if (i==10) goto L11000;
	if (i==11) goto L11100;
	goto L1000;

	//------------------------------------------------------------------------------
	//	CFEB Walking 1 Tests:
	//------------------------------------------------------------------------------
L10100:
	icfeb = ifunc;
	printf("\tI trust you connected a 25pr cable from ALCTtx to CFEB%i1\n",icfeb);

L10110:
	sel_boot_jtag  = 0x0080;
	sel_step_alct  = 0x1D10;
	sel_step_cfeb  = 0x1D10 | (1 << (icfeb+5));
	cfeb_id_expect = 0xC0 | icfeb;
	alct_id_expect = 0xA0;

	// Set CCB inputs high by driving CCB ouputs to loopback backplane
	wr_data = 0;								// bits 15:0
	wr_data = (-wr_data-1) & 0x0FFFF;			// invert
	adr     = ccb_txa_adr+base_adr;
	status  = vme_write(adr,wr_data);

	// Loop over passes
	for (ipass=1; ipass<=1000; ++ipass) {
		cfeb_err = 0;

		// Turn off CFEB clock drivers
		wr_data	= sel_step_alct;
		adr		= vme_step_adr+base_adr;
		status	= vme_write(adr,wr_data);

		// Put ALCT into loopback mode, enable CFEBs, and ALCT SCSI
		sel_loopbk =0x0A9F;							// NB loopbk bits are different for normal tmb firmware TMB2005
		adr		= vme_loopbk_adr+base_adr;
		wr_data = sel_loopbk;
		status	= vme_write(adr,wr_data);

		// Send walking 1s to ALCT transmitter
		for (i=0; i<=23; ++i) {	//L10120
			status	= vme_write(adr=tmb_boot_adr+base_adr, wr_data=sel_boot_jtag);
			status	= vme_write(adr=alct_txa_adr+base_adr, wr_data=0);
			status	= vme_write(adr=alct_txb_adr+base_adr, wr_data=0);
			status	= vme_write(adr=vme_step_adr+base_adr, wr_data=sel_step_alct);

			if ((i>=0) && (i<=4)) {
				wr_data= (1 << i) | sel_boot_jtag;
				adr	= tmb_boot_adr+base_adr;
				status	= vme_write(adr,wr_data);}

			else if ((i>=5) && (i<=17)) {
				wr_data= (1 << (i-5));
				adr	= alct_txa_adr+base_adr;
				status	= vme_write(adr,wr_data);}

			else if (i==18) {
				wr_data= (1 << 8) | sel_boot_jtag;
				adr	= tmb_boot_adr+base_adr;
				status	= vme_write(adr,wr_data);}

			else if (i==20) {
				wr_data= (1 << (i-20)) | sel_step_alct;
				adr	= vme_step_adr+base_adr;
				status	= vme_write(adr,wr_data);}

			else if ((i>=19) | (i<=23)) {
				wr_data= (1 << (i-19));
				if (i==21) wr_data = (1 << (23-19));	// exchange bits 21 & 23
				if (i==23) wr_data = (1 << (21-19));	// exchange bits 21 & 23
				adr	= alct_txb_adr+base_adr;
				status	= vme_write(adr,wr_data);		
			}	// close if i>=0

			// Read back CFEB data registers
			cfeb_data = 0;
			cfeb_base = base_adr+icfeb*cfeb_offset_adr;

			adr	    = cfeb0a_adr+cfeb_base;
			status	= vme_read(adr,rd_data);

			cfeb_id   = (rd_data >> 8) & 0xFF;
			rd_data   = rd_data & 0xFF;
			cfeb_data = cfeb_data | rd_data;

			if (cfeb_id!=cfeb_id_expect) printf("\tWrong CFEB id: expect=%8.8X read=%8.8X\n",cfeb_id_expect,cfeb_id);

			adr	     = cfeb0b_adr+cfeb_base;
			status   = vme_read(adr,rd_data);
			cfeb_id  = (rd_data >> 8) & 0xFF;
			rd_data  = rd_data & 0xFF;
			cfeb_data= cfeb_data | (rd_data << 8);

			if (cfeb_id!=cfeb_id_expect) printf("\tWrong CFEB id: expect=%8.8X read=%8.8X\n",cfeb_id_expect,cfeb_id);

			adr	   = cfeb0c_adr+cfeb_base;
			status = vme_read(adr,rd_data);

			cfeb_id   = (rd_data >> 8) & 0xFF;
			rd_data   = rd_data & 0xFF;
			cfeb_data = cfeb_data | (rd_data << 16);

			if (cfeb_id!=cfeb_id_expect) printf("\tWrong CFEB id: expect=%8.8X read=%8.8X\n",cfeb_id_expect,cfeb_id);

			// Un-invert the inverted ALCT bits...thanks a lot, Vlad
			cfeb_data = cfeb_data^ 0x4EAAAA;

			// Compare CFEB read data to ALCT write data
			if (cfeb_data!=(1 <<i)) {
				cfeb_err++;
				printf("\tFailed CFEB%1i bit=%2i wr=%6.6X rd=%6.6X\n",icfeb,i,(1<<i),cfeb_data);
				pause("<cr>");
			}

			// Close CFEB bit loop
		}	// L10120

		// Test CFEB transmit clock bit: Take ALCT out of loop-back mode
		wr_data = 0x0A9D;	// TMB2005
		adr		= vme_loopbk_adr+base_adr;
		status	= vme_write(adr,wr_data);

		// Turn on CFEB clock driver 
		wr_data	= sel_step_cfeb | (1 << (icfeb+5));
		adr		= vme_step_adr+base_adr;	
		status	= vme_write(adr,wr_data);

		// Write a 1 to CFEB clock driver
		wr_data	= sel_step_cfeb | (1 << (icfeb+5)) | 0x0008;
		adr		= vme_step_adr+base_adr;
		status	= vme_write(adr,wr_data);

		// Read ALCT receiver
		adr		= alct_rxa_adr+base_adr;
		status	= vme_read(adr,rd_data);
		alct_id = (rd_data >> 8) & 0xFF;
		rd_data = rd_data & 0xFF;

		if (alct_id!=alct_id_expect) printf("\tWrong ALCT id: expect=%8.8X read=%8.8X\n",alct_id_expect,cfeb_id);

		// Check if ALCT read a 1, un-invert it...thanks a lot, Vlad
		rd_data = ((rd_data >> 3) & 0x0001) ^ 0x0001;
		if (rd_data!=1) {
			cfeb_err++;
			printf("\tFailed CFEB%1i clock bit wr=1 rd=%6.6X\n",icfeb,rd_data);
			pause ("<cr>");
		}

		// Write a 0 to CFEB clock driver
		wr_data	= sel_step_cfeb | (1 << (icfeb+5)) | 0x0000;
		adr		= vme_step_adr+base_adr;	
		status	= vme_write(adr,wr_data);

		// Read ALCT receiver
		adr		= alct_rxa_adr+base_adr;
		status	= vme_read(adr,rd_data);
		alct_id = (rd_data >> 8) & 0xFF;
		rd_data = rd_data & 0xFF;

		// Check if ALCT read a 0, un-invert it...thanks a lot, Vlad
		rd_data = ((rd_data >> 3) & 0x0001) ^ 0x0001;
		if (rd_data!=0) {
			cfeb_err++;
			printf("\tFailed CFEB%1i clock bit wr=0 rd=%6.6X\n",icfeb,rd_data);
			pause ("<cr>");
		}

		// Close pass loop
	}	// close ipass 10130
	if (cfeb_err!=0) goto L10110;

	// CFEB passes
	printf("\t\t%cCFEB%1i passed rx walking 1\n",bell,icfeb);
	goto L1000;

	//------------------------------------------------------------------------------
	//	ALCT SCSI Walking 1 Tests:
	//------------------------------------------------------------------------------
L10500:
	printf("\tI trust you connected a 25pr cable from ALCTtx to ALCTrx\n");

L10510:
	sel_boot_jtag = 0x0080;
	sel_step_alct = 0x1D10;
	sel_step_cfeb = 0x1D10 | (1 << (icfeb+5));

	for (ipass=1; ipass<=1000; ++ipass) {	// 10530
		alct_err = 0;

		// Put ALCT into loopback mode, enable CFEBs, and ALCT SCSI
		wr_data = 0x000F;
		adr		= vme_loopbk_adr+base_adr;
		status	= vme_write(adr,wr_data);

		// Send walking 1s to ALCT transmitter
		for (i=0; i<=24; ++i) {	// 10520
			status	= vme_write(adr=tmb_boot_adr+base_adr, wr_data=sel_boot_jtag);
			status	= vme_write(adr=alct_txa_adr+base_adr, wr_data=0);
			status	= vme_write(adr=alct_txb_adr+base_adr, wr_data=0);
			status	= vme_write(adr=vme_step_adr+base_adr, wr_data=sel_step_alct);

			if (i>=0 && i<=4)
			{
				wr_data= (1 << i) | sel_boot_jtag;
				adr	= tmb_boot_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (i>=5 && i<=17)
			{
				wr_data= (1 << (i-5));
				adr	= alct_txa_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (i==18)
			{
				wr_data= (1 << 8) | sel_boot_jtag;
				adr	= tmb_boot_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (i==20)
			{
				wr_data= 0x0001 | sel_step_alct;
				adr	= vme_step_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (i>=19 || i<=24)
			{
				wr_data = (1<<( i-19));
				if (i==21) wr_data = (1<<(23-19));		// exchange bits 21 & 23
				if (i==23) wr_data = (1<<(21-19));		// exchange bits 21 & 23
				if (i==24) wr_data = (1<<(20-19));		// exchange bits 20 & 24
				adr	= alct_txb_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}		
			else
			{
				stop("dumbass");
			}

			// Read back ALCT data registers
			alct_data=0;

			for (ireg=0; ireg<=3; ++ireg)
			{
				adr		  = base_adr+alct_rxa_adr+2*ireg;
				status	  = vme_read(adr,rd_data);
				alct_id   = (rd_data >> 8) & 0xFF;
				rd_data   = rd_data & 0xFF;
				alct_data = alct_data | (rd_data << (ireg*8));

				alct_id_expect = 0xA0 | ireg;
				if (alct_id!=alct_id_expect) printf("\tWrong ALCT id alct_id=%8.8X alct_id_expect=%8.8X\n",alct_id,alct_id_expect);
			}

			// Un-invert the inverted ALCT bits...thanks a lot, Vlad
			alct_data = alct_data^0x01BFFFF0;
			alct_data = (alct_data >> 4);	// rx4 is the ALCT lsb

			// Compare ALCT read data to ALCT write data
			if (alct_data!=(1<<i))
			{
				alct_err++;
				if (ifunc>=0) {printf("\tFailed ALCT bit=%2i wr=%8.8X rd=%8.8X\n",(1<<i),alct_data); pause("<cr> to resume");}
			}

			// Close loops
		}	// 10520	close ALCT bit
	}	// 10530	close test repeat loop
	if (alct_err!=0) goto L10510;

	// ALCT passes
	printf("\t\tALCT SCSI passed walking 1\n");
	if (ifunc<=0) goto L10500;
	goto L1000;


	//------------------------------------------------------------------------------
	//	ALCT Transition Module Walking 1 Tests:
	//------------------------------------------------------------------------------
L10600:
	sel_boot_jtag = 0x0080;
	sel_step_alct = 0x1D10;

	// Put ALCT into normal mode, and enable ALCT transition module (disable SCSI)
	wr_data = 0x000F;	// TMB2005
	adr		= vme_loopbk_adr + base_adr;
	status	= vme_write(adr,wr_data);

	// Loop over 29 receive bits, only do full tx test with bit 0
	for (irx=0; irx<=28; ++irx)	// 10620
	{

		// Loop over 23 tx bits
		j=23;
		if (irx==0) j=0;

		for (i=j; i<=23; ++i)
		{
			printf("\t\t ALCT Transition testing bit alct_tx%2.2i with alct_rx%2.2i%c\n",i,irx,bell);

L10610:
			alct_err=0;

			for (ipass=1; ipass<=5000; ++ipass) {
				for (itx  =0; itx  <=1;    ++itx  ) {

					// Clear previous data on ALCT outputs
					wr_data = 0;
					status	= vme_write(adr=tmb_boot_adr+base_adr, wr_data=sel_boot_jtag);
					status	= vme_write(adr=alct_txa_adr+base_adr, wr_data=wr_data);
					status	= vme_write(adr=alct_txb_adr+base_adr, wr_data=wr_data);
					status	= vme_write(adr=vme_step_adr+base_adr, wr_data=sel_step_alct);

					// Toggle tx bit and send to ALCT output registers
					if (i>=0 && i<=4)
					{
						wr_data= (itx<<i) | sel_boot_jtag;
						adr	= tmb_boot_adr + base_adr;
						status	= vme_write(adr,wr_data);
					}
					else if (i>=5 && i<=17)
					{
						wr_data= (itx << (i-5));
						adr	= alct_txa_adr + base_adr;
						status	= vme_write(adr,wr_data);
					}
					else if (i==18)	// inverted data
					{
						wr_data= ((itx^1)<<8) | sel_boot_jtag;
						adr	= tmb_boot_adr + base_adr;
						status	= vme_write(adr,wr_data);
					}
					else if (i>=19 || i<=24)
					{
						wr_data= (itx<<(i-19));
						adr	= alct_txb_adr + base_adr;
						status	= vme_write(adr,wr_data);
					}
					else
					{
						stop("dumbass");
					}

					// Read ALCT input registers
					alct_data=0;

					adr		= base_adr+tmb_boot_adr;
					status	= vme_read(adr,rd_data);
					alct_data = alct_data | ((rd_data>>15) & 0x1); // rx0 is TDO

					for (ireg=0; ireg<=3; ++ireg)
					{
						adr		  = base_adr+alct_rxa_adr+2*ireg;
						status	  = vme_read(adr,rd_data);
						rd_data   = rd_data & 0xFF;
						alct_data = alct_data | (rd_data << (ireg*8));
					}
					rd_data   = (alct_data>>irx) & 0x1;

					// Check that transmitted bit is received OK, can't check if others are 0, because they float
					if (rd_data!=itx) alct_err=1;
					if (itx!=0 && itx!=1) pause("wtf!");
					printf("ALCT error i=%i3 itx=%i3 rd_data=%4.4X\n",i,itx,rd_data);

					// Close loops
				}	// close for itx
				if (alct_err!=0) goto L10610;
			}	// close ipass
		}	// close i
	}	// close irx 10620

	// ALCT passes
	printf("\t\tALCT Transition Module passed walking 1%c\n",bell);
	goto L1000;

	//------------------------------------------------------------------------------
	//	RPC Walking 1 Tests:
	//------------------------------------------------------------------------------
L10700:
	printf("\t\t Check for 40MHz   at TP441-8\n");
	printf("\t\t Check for 80MHz   at TP441-7\n");
	printf("\t\t Check for Logic 0 at TP441-6\n");
	printf("\t\t Toggling rpc_tx0  at TP441-5\n");

	// Get current loop back register state
	adr		= base_adr+vme_loopbk_adr;
	status	= vme_read(adr,rd_data);
	loopbk	= rd_data;
	loopbk	= loopbk & 0xFFDF;	//  rpc_tx=0

	for (i=0; i<=35; ++i)
	{
		printf("\t\t RPC testing bit rpc_rx%2.2i%c\n",i,bell);

L10710:
		rpc_err=0;

		for (ipass=1; ipass<=5000; ++ipass) {
			for (itx  =0; itx  <=1;    ++itx  ) {

				// Toggle rpc_tx0
				wr_data = (loopbk^(itx<<5)) & 0x0000FFFF;
				adr		= vme_loopbk_adr + base_adr;
				status	= vme_write(adr,wr_data);

				// Read RPC read registers
				adr		= base_adr+rpc_rxa_adr;
				status	= vme_read(adr,rd_data);
				bit_to_array(rd_data ,&rpc_data[ 0], 16);

				adr		= base_adr+rpc_rxb_adr;
				status	= vme_read(adr,rd_data);
				bit_to_array(rd_data, &rpc_data[16], 16);

				adr		= base_adr+vme_loopbk_adr;
				status	= vme_read(adr,rd_data);
				rd_data = (rd_data>>12) & 0x000F;
				bit_to_array(rd_data, &rpc_data[32],  4);

				// Check that transmitted bit is received OK, can't check if others are 0, because they float
				if (rpc_data[i]!=itx) rpc_err=1;
				printf("\tRPC error i=%3.3i itx=%3.3itx rpc_data=",i,itx); for(k=0; k<=35; ++k) printf("%1i",rpc_data[k]); printf("\n");

				// Close loops
			}	// close for itx
			if (rpc_err!=0) goto L10710;
		}	// close for ipass
	}	// close for i

	// RPC passes
	printf("\t\tRPC passed walking 1%c\n",bell);
	goto L1000;

	//------------------------------------------------------------------------------
	//	DMB Walking 1 Tests:
	//------------------------------------------------------------------------------
L10800:
	if (ifunc<0) goto L10830;	// bang mode

	printf("\t\t Check for Logic 0 at R110 dmb_loop\n");
	printf("\t\t Check for Logic 0 at R31  /dmb_oe\n");
	printf("\t\t Check for DMB clock at TP302-4 and P2B A8\n");

	// Loop over 4 receive bits, only do full test with bit 0
	for (irx=0; irx<=3; ++irx)	//  10820
	{

		// Loop over 43 tx bits. 44th bit is dmb_fifo_clock, loop on rxbit 42 if irx>0
		j=42;
		if (irx==0) j=0;

		for (i=j; i<=42; ++i)
		{
			printf("\t\t DMB testing bit dmb_tx%2i with dmb_rx%2i%c\n",i,irx,bell);

L10810:
			dmb_err=0;

			for (ipass=1; ipass<=5000; ++ipass) {
				for (itx  =0; itx  <=1;    ++itx  ) {

					// Clear previous data on DMB outputs
					wr_data = 0;
					status	= vme_write(adr=dmb_txa_adr+base_adr,wr_data);
					status	= vme_write(adr=dmb_txb_adr+base_adr,wr_data);
					status	= vme_write(adr=dmb_txc_adr+base_adr,wr_data);

					// Toggle tx bit and send to DMB output registers
					wr_data= (itx<<(i%16)) & 0xFFFF;
					adr		= base_adr+dmb_txa_adr+2*(i/16);
					status	= vme_write(adr,wr_data);

					// Read DMB input register
					adr		= base_adr+dmb_rxa_adr;
					status	= vme_read(adr,rd_data);
					rd_data = (rd_data>>irx) & 0x1;

					// Check that transmitted bit is received OK, can't check if others are 0, because they float
					if (rd_data!=itx) dmb_err=1;
					printf("DMB error i=%i3 itx=%i3 rd_data=4.4X\n",i,itx,rd_data);

					// Close loops
				}	// close for itx
				if (dmb_err!=0) goto L10810;
			}	// close for ipass
		}	// close for i
	}	// close for irx 10820

	// DMB passes
	printf("\t\tDMB passed walking 1%c\n",bell);
	printf("\t\t<cr>=exit, else send walking 1 forever: ");

	gets(line);
	if (line[0]==NULL) goto L1000;

	printf("Started DMB walking 1 forever, check for shorts\n");

	// DMB transmits walking 1 forever to check for shorts
L10830:
	for (i=0; i<=42; ++i) {

		// Clear previous data on DMB outputs
		wr_data = 0;
		status	= vme_write(adr=dmb_txa_adr+base_adr,wr_data);
		status	= vme_write(adr=dmb_txb_adr+base_adr,wr_data);
		status	= vme_write(adr=dmb_txc_adr+base_adr,wr_data);

		// Walking 1 tx bit
		wr_data= (1<<(i%16)) & 0xFFFF;
		adr		= base_adr+dmb_txa_adr+2*(i/16);
		status	= vme_write(adr,wr_data);
	}	// close for i
	goto L10830;

	//------------------------------------------------------------------------------
	//	MPC Walking 1 Tests:
	//------------------------------------------------------------------------------
L10900:
	if (ifunc<0) goto L10930;

	// Receive  data on mpc_in0
	irx=0;

	// Loop over 32 tx bits
	for (i=0; i<=31; ++i )
	{
		printf("\t\t MPC testing bit mpc_tx%2.2i with mpc_rx%2.2i%c\n",i,irx,bell);

L10910:
		mpc_err=0;

		for (ipass=1; ipass<=5000; ++ipass) {
			for (itx  =0; itx  <=1;    ++itx  ) {

				// Clear previous data on MPC outputs
				wr_data = 0;
				status	= vme_write(adr=mpc_txa_adr+base_adr,wr_data);
				status	= vme_write(adr=mpc_txb_adr+base_adr,wr_data);

				// Toggle tx bit and send to MPC output registers
				wr_data = (itx<<(i%16)) & 0xFFFF;
				adr		= base_adr+mpc_txa_adr+2*(i/16);
				status	= vme_write(adr,wr_data);

				// Read MPC input register ccb_rx34
				adr		= base_adr+ccb_rxc_adr;
				status	= vme_read(adr,rd_data);
				rd_data = (rd_data>>2) & 0x1;

				// Check that transmitted bit is received OK, can't check if others are 0, because they float
				if (rd_data!=itx) mpc_err=1;
				printf("DMB error i=%2.2i itx=%2.2i rd_data=%4.4X\n",i,itx,rd_data);

				// Close loops
			}	// close for itx
			if (mpc_err!=0) goto L10910;
		}	// close for ipass
	}	// close for i

	// MPC passes
	printf("\t\tMPC passed walking 1%c\n",bell);
	printf("\t\t<cr>=exit, else send walking 1 forever: ");

	gets(line);
	if (line[0]==NULL) goto L1000;

	printf("Started MPC walking 1 forever, check for shorts\n");

	// MPC transmits walking 1 forever to check for shorts
L10930:
	for (i=0; i<=31; ++i)
	{
		// Clear previous data on DMB outputs
		wr_data = 0;
		status	= vme_write(adr=mpc_txa_adr+base_adr,wr_data);
		status	= vme_write(adr=mpc_txb_adr+base_adr,wr_data);

		// Walking 1 tx bit
		wr_data=  (1<<(i%16)) & 0xFFFF;
		adr		= base_adr+mpc_txa_adr+2*(i/16);
		status	= vme_write(adr,wr_data);
	}	// close for i
	goto L10930;

	//------------------------------------------------------------------------------
	//	CCB Walking 1 Tests:
	//------------------------------------------------------------------------------
L11000:
	// Put CCB into loopback mode
	wr_data = 0x080F;	// TMB2005
	adr		= vme_loopbk_adr + base_adr;
	status	= vme_write(adr,wr_data);

	// Loop over 51 receive bits, only do full tx test with bit 0
	for (irx=0; irx<=50; ++irx)	// 11020
	{

		// Loop over 27 tx bits, loop on first rxbit if irx>0
		j=26;
		if (irx!=0) j=0;

		for (i=0; i<=j; ++i)
		{
			printf("\t\t CCB testing bit ccb_tx%2.2i with ccb_rx%2.2i%c\n",i,irx,bell);

L11010:
			ccb_err=0;

			for (ipass=1; ipass<=5000; ++ipass) {
				for (itx  =0; itx  <=1;    ++itx  ) {

					// Clear previous data on CCB outputs
					wr_data = 0;
					status	= vme_write(adr=ccb_txa_adr+base_adr,wr_data);
					status	= vme_write(adr=ccb_txb_adr+base_adr,wr_data);

					// Toggle tx bit and send to CCB output registers
					wr_data = (itx<<(i%16)) & 0xFFFF;
					adr		= base_adr+ccb_txa_adr+2*(i/16);
					status	= vme_write(adr,wr_data);

					// Read CCB input registers
					for (ireg=0; ireg<=3; ++ireg) {
						adr		= base_adr+ccb_rxa_adr+2*ireg;
						status	= vme_read(adr,rd_data);
						rd_data = rd_data & 0xFFFF;
						bit_to_array(rd_data, &ccb_data[ireg*16], 16);
					}

					// Check that transmitted bit is received OK, can't check if others are 0, because they float
					if (ccb_data[irx]!=itx) ccb_err=1;

					// Close loops
				}	// close itx
				if (ccb_err!=0) goto L11010;
			}	// close for ipass
		}	// close for i
	}	// close for irx 11020

	// CCB passes
	printf("\t\tCCB passed walking 1%c\n",bell);
	goto L1000;

	//------------------------------------------------------------------------------
	//	VME Walking 1 Tests:
	//------------------------------------------------------------------------------
L11100:
	// Boot register 
	reg_err=0;

	for (i=0; i<15; ++i)
	{
		wr_data = (1<<i);
		status	= vme_write (boot_adr,wr_data);	//  Write walking 1
		status	= vme_read  (base_adr,rd_data);	//  Read base to purge bit3 buffers
		status	= vme_read  (boot_adr,rd_data);	//  Read boot
		rd_data = rd_data & 0x3FFF;				//  Remove read-only bits
		wr_data = wr_data & 0x3FFF;

		if (rd_data!=wr_data) 
		{
			reg_err++;
			printf("\t\tFailed Boot bit i=%2.2i wr_data=%4.4X rd_data=%4.4X\n",i,wr_data,rd_data);
		}	// close if
	}	// close for i

	if (reg_err==0) printf("\t\tBoot Register passed walking 1%c\n",bell);
	if (reg_err!=0) {
		if (ifunc<0) goto L11100;
		pause("<cr> to resume");
	}

	// Data register
	reg_err = 0;
	status	= vme_read(adr=vme_ddd0_adr+base_adr,rd_data);			//  Get current
	vme_cfg = rd_data;

	for (i=0; i<=15; ++i)
	{
		wr_data = (1<<i);
		status	= vme_write (adr=vme_ddd0_adr+base_adr,wr_data);		//  Write walking 1
		status	= vme_read  (adr=base_adr             ,rd_data);		//  Read base to purge bit3 buffers
		status	= vme_read  (adr=vme_ddd0_adr+base_adr,rd_data);		//  Read cfg

		if (rd_data!=wr_data) {
			reg_err++;
			printf("\t\tFailed vme Data bit=%2i wr=%8.8X rd=%8.8X\n",i,wr_data,rd_data);
		}
	}	// close for i

	status = vme_write(adr=vme_ddd0_adr+base_adr,wr_data=vme_cfg);	//  Restore cfg

	if (reg_err==0) printf("\t\tVME Data Register passed walking 1%c\n",bell);
	if (reg_err!=0) pause("reg_err!=0");

	// VME address register
	reg_err=0;

	for (i=1; i<=23; ++i)
	{
		adr     = (1<<i);										//  Walking 1 address
		status  = vme_read(adr,rd_data);						//  Read ww1 address
		sleep(100);
		status	= vme_read(adr,rd_data);						//  Read ww1 address again
		sleep(100);	
		status	 = vme_read(adr=vme_adr0_adr+base_adr,rd_data);	//  Read adr lsbs
		vme_data = rd_data;
		status	 = vme_read(adr,rd_data);						//  Read ww1 address again
		sleep(100);												//  Wait for bus-timeout
		status	 = vme_read(adr=vme_adr1_adr+base_adr,rd_data);	//  Read adr msb
		vme_data = vme_data | ((rd_data&0xFF)<<16);
		adr_mode = (rd_data>>8) & 0xFF;

		printf("\t\tAddress %6.6X\r",adr);

		if (vme_data!=adr || adr_mode!=0x3D) {
			reg_err++;
			printf("\t\tFailed Address bit=%2i wr=%8.8X rd=%8.8X mode=%8.8X\n",i,adr,vme_data,adr_mode);
		}

	}	// close for i

	if (reg_err==0) printf("\t\tAddress Register passed walking 1%c\n",bell);
	pause("<cr> to resume");

	return;
}
//------------------------------------------------------------------------------
//	Read TMB ADC+Status
//------------------------------------------------------------------------------
void L1100() {
	//L1100:

	//	Read voltage discriminators
	adr    = vme_adc_adr+base_adr;
	status = vme_read(adr,rd_data);

	vstat_5p0v = ok[(rd_data >> 0) & 0x1];
	vstat_3p3v = ok[(rd_data >> 1) & 0x1];
	vstat_1p8v = ok[(rd_data >> 2) & 0x1];
	vstat_1p5v = ok[(rd_data >> 3) & 0x1];
	tcrit      = ok[(rd_data >> 4) & 0x1];

	fprintf(stdout,"\tTMB2005E Comparators\n");
	fprintf(stdout,"\t5.0V TMB  status=%s\n",vstat_5p0v.c_str());
	fprintf(stdout,"\t3.3V TMB  status=%s\n",vstat_3p3v.c_str());
	fprintf(stdout,"\t1.8V RAT  status=%s\n",vstat_1p8v.c_str());
	fprintf(stdout,"\t1.5V TMB  status=%s\n",vstat_1p5v.c_str());
	fprintf(stdout,"\tTcrit     status=%s\n",tcrit.c_str());

L1115:
	// Get current ADC values
	adc_read(base_adr);											// Returns data via common block
	adc_read_mez(base_adr);

	// Read Virtex-6 Sysmon
	// Adr
	//	0		Temperature		Degrees C = ((ADCcode � 503.975)/1024) - 273.15
	//	1		VccINT			Volts	  = (ADC Code / 1024) x 3V
	//	2		VccAUX			Volts	  = (ADC Code / 1024) x 3V
	//	4		Vref  1.25V		Volts	  = (ADC Code / 1024) x 3V
	//	5		Vzero 0.00V		Volts	  = (ADC Code / 1024) x 3V

	if (fpga_series=="XC6VLX195T")
	{
		adr     = adr_virtex6_sysmon+base_adr;
		wr_data = 0;							// Adr 0 Temperature
		status  = vme_write(adr,wr_data);
		status  = vme_read (adr,rd_data);
		adc_valid     = (rd_data >> 5) & 0x1;
		adc_data      = (rd_data >> 6) & 0x3FF;
		sysmon_temp_c = ((float(adc_data) * 503.975)/1024.0) - 273.15;
		sysmon_temp_f = sysmon_temp_c*(9./5.)+32.0;

		wr_data = 1;							// Adr 1 Vccint
		status  = vme_write(adr,wr_data);
		status  = vme_read (adr,rd_data);
		adc_valid     = (rd_data >> 5) & 0x1;
		adc_data      = (rd_data >> 6) & 0x3FF;
		sysmon_vccint = (float(adc_data)/1024.0)*3.0;

		wr_data = 2;							// Adr 2 Vccaux
		status  = vme_write(adr,wr_data);
		status  = vme_read (adr,rd_data);
		adc_valid     = (rd_data >> 5) & 0x1;
		adc_data      = (rd_data >> 6) & 0x3FF;
		sysmon_vccaux = (float(adc_data)/1024.0)*3.0;

		wr_data = 4;							// Adr 4 Vref
		status  = vme_write(adr,wr_data);
		status  = vme_read (adr,rd_data);
		adc_valid     = (rd_data >> 5) & 0x1;
		adc_data      = (rd_data >> 6) & 0x3FF;
		sysmon_vref   = (float(adc_data)/1024.0)*3.0;

		wr_data = 5;							// Adr 5 Vzero
		status  = vme_write(adr,wr_data);
		status  = vme_read (adr,rd_data);
		adc_valid     = (rd_data >> 5) & 0x1;
		adc_data      = (rd_data >> 6) & 0x3FF;
		sysmon_vzero  = (float(adc_data)/1024.0)*3.0;
	}

	// Read Spartan-6 FPGA Status registers
	s6_stat_en=false;

	if (fpga_series=="XC6SLX150" && s6_stat_en)
	{
		ichain  = 0x24;
		chip_id = 0;
		nchips  = 3;
		adr     = boot_adr;

		opcode  = SPARTAN6_STAT;									// Opcode
		reg_len = 16;												// Data length
		vme_jtag_anystate_to_rti(adr,ichain);						// Take TAP to RTI
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);				// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);		// Write 0's read idcode
		tdi_to_i4(tdo,s6_stat,32,0);								// Deserialize

		opcode  = SPARTAN6_BOOTSTS;									// Opcode
		reg_len = 16;												// Data length
		vme_jtag_anystate_to_rti(adr,ichain);						// Take TAP to RTI
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);				// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);		// Write 0's read idcode
		tdi_to_i4(tdo,s6_bootsts,32,0);								// Deserialize

		opcode  = SPARTAN6_SEU_OPT;									// Opcode
		reg_len = 16;												// Data length
		vme_jtag_anystate_to_rti(adr,ichain);						// Take TAP to RTI
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);				// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);		// Write 0's read idcode
		tdi_to_i4(tdo,s6_seu_opt,32,0);								// Deserialize

		s6_SWWD_strikeout	= (s6_stat >> 15) & 0x1;		// [15]		Indicates error to configure
		s6_IN_PWRDN			= (s6_stat >> 14) & 0x1;		// [14]		SUSPEND status
		s6_DONE				= (s6_stat >> 13) & 0x1;		// [13]		DONEIN input from DONE pin
		s6_INIT_B			= (s6_stat >> 12) & 0x1;		// [12]		Value of INIT_B
		s6_MODE				= (s6_stat >>  9) & 0x7;		// [11:9]	Value of MODE pins (0, M1,M0)
		s6_HSWAPEN			= (s6_stat >>  8) & 0x1;		// [8]		HSWAPEN status
		s6_PART_SECURED		= (s6_stat >>  7) & 0x1;		// [7]		Decryption security: 0=not set, 1=set
		s6_DEC_ERROR		= (s6_stat >>  6) & 0x1;		// [6]		FDRI write attempted before or after decryption operation: 0: No DEC_ERROR, 1: DEC_ERROR.
		s6_GHIGH_B			= (s6_stat >>  5) & 0x1;		// [5]		Status of GHIGH
		s6_GWE				= (s6_stat >>  4) & 0x1;		// [4]		Status of Global Write Enable
		s6_GTS_CFG_B		= (s6_stat >>  3) & 0x1;		// [3]		Status of Global 3-State
		s6_DCM_LOCK			= (s6_stat >>  2) & 0x1;		// [2]		DCMs and PLLs are locked
		s6_ID_ERROR			= (s6_stat >>  1) & 0x1;		// [1]		IDCODE not validated while trying to write FDRI
		s6_CRC_ERROR		= (s6_stat >>  0) & 0x1;		// [0]		CRC error

		s6_STRIKE_CNT		= (s6_bootsts >> 12) & 0xF;		// [15:12]	Strike count
		s6_CRC_ERROR_1		= (s6_bootsts >> 11) & 0x1;		// [11]		CRC error
		s6_ID_ERROR_1		= (s6_bootsts >> 10) & 0x1;		// [10]		IDCODE not validated while trying to write FDRI
		s6_WTO_ERROR_1		= (s6_bootsts >>  9) & 0x1;		// [9]		Watchdog time-out error
		s6_RESERVED_8		= (s6_bootsts >>  8) & 0x1;		// [8]		Reserved
		s6_FALLBACK_1		= (s6_bootsts >>  7) & 0x1;		// [7]		1: Fallback to 00 address, 0: Normal configuration
		s6_VALID_1			= (s6_bootsts >>  6) & 0x1;		// [6]		Status Valid
		s6_CRC_ERROR_0		= (s6_bootsts >>  5) & 0x1;		// [5]		CRC error
		s6_ID_ERROR_0		= (s6_bootsts >>  4) & 0x1;		// [4]		IDCODE not validated while trying to write FDRI
		s6_WTO_ERROR_0		= (s6_bootsts >>  3) & 0x1;		// [3]		Watchdog time-out error
		s6_RESERVED			= (s6_bootsts >>  2) & 0x1;		// [2]		Reserved
		s6_FALLBACK_0		= (s6_bootsts >>  1) & 0x1;		// [1]		1: Fallback to golden bit stream address, 0: Normal configuration
		s6_VALID_0			= (s6_bootsts >>  0) & 0x1;		// [0]		Status Valid

		s6_RESERVED_15		= (s6_seu_opt >> 15) & 0x1;		// [15]		Reserved, default 1
		s6_RESERVED_14		= (s6_seu_opt >> 14) & 0x1;		// [14]		Reserved, default 0
		s6_SEU_FREQ			= (s6_seu_opt >>  4) & 0x3FF;	// [13:4]	Bus_clk frequency during SEU detection, default 10x1be
		s6_SEU_RUN_ON_ERR	= (s6_seu_opt >>  3) & 0x1;		// [3]		If SEU_ERR is detected, keep running? 0: Halt. 1: Keep running, default=0
		s6_GLUT_MASK		= (s6_seu_opt >>  2) & 0x1;		// [1]		Mask out LUTRAM/SRL readback, 0: Unmask, 1: Mask out LUTRAM/SRL, default 1
		s6_SEU_ENABLE		= (s6_seu_opt >>  1) & 0x1;		// [0]		Enable SEU Detection. 0: Disable. 1: Enable. default 0
	}

	// Simulate RAT depending on SH921
	if (v3p3rat > 2.8) {	// SH921 set 2-3 sends RAT 3.3V to ADC
		v3p3rat = v3p3rat;		// use 3.3v sent from RAT
		a1p8rat = 0.0;}			// then we don't know core current
	else {					// SH921 set 1-2 sends RAT 1.8V core current to ADC
		v3p3rat = v3p3;			// simulate RAT 3.3 cuz we don't have other info
		a1p8rat = a1p8rat;
	}
	a3p3rat = 0;

	// Read LM84 temperature from TMB
	smb_adr  = 0x2A;		// float,float state TMB LM84 chip address
	smb_cmd  = 0x00;		// Local temperature command
	smb_data = 0xFF;		// Null write data
	adc_adr  = base_adr+vme_adc_adr;
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data
	t_local_c_tmb = float(smb_data_tmb);
	t_local_f_tmb = t_local_c_tmb*(9./5.)+32.0;

	smb_cmd   = 0x01;		// Remote temperature command
	smb_data  = 0xFF;		// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	
	t_remote_c_tmb = float(smb_data_tmb);
	t_remote_f_tmb = t_remote_c_tmb*(9./5.)+32.0;

	smb_cmd  = 0x05;		// Local tcrit
	smb_data = 0xFF;		// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	
	tcrit_local_c_tmb = float(smb_data_tmb);
	tcrit_local_f_tmb = tcrit_local_c_tmb*(9./5.)+32.0;

	smb_cmd  = 0x07;		// Remote tcrit
	smb_data = 0xFF;		// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	
	tcrit_remote_c_tmb = float(smb_data_tmb);
	tcrit_remote_f_tmb = tcrit_remote_c_tmb*(9./5.)+32.0;

	// Read LM84 temperature from RAT
	smb_adr  = 0x18;		// gnd,gnd state RAT LM84 chip address
	smb_cmd  = 0x00;		// Local temperature command
	smb_data = 0xFF;		// Null write data
	adc_adr  = base_adr+vme_adc_adr;
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data
	t_local_c_rat = float(smb_data_rat);
	t_local_f_rat = t_local_c_rat*(9./5.)+32.0;

	smb_cmd  = 0x01;		// Remote temperature command
	smb_data = 0xFF;		// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	
	t_remote_c_rat = float(smb_data_rat);
	t_remote_f_rat = t_remote_c_rat*(9./5.)+32.0;

	smb_cmd  = 0x05;		// Local tcrit
	smb_data = 0xFF;		// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	
	tcrit_local_c_rat = float(smb_data_rat);
	tcrit_local_f_rat = tcrit_local_c_rat*(9./5.)+32.0;

	smb_cmd  = 0x07;		// Remote tcrit
	smb_data = 0xFF;		// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	
	tcrit_remote_c_rat = float(smb_data_rat);
	tcrit_remote_f_rat = tcrit_remote_c_rat*(9./5.)+32.0;

	// Read trigger live-time counter
	adr		= uptimer_adr+base_adr;
	status	= vme_read(adr,rd_data);

	uptime     = int(float(rd_data)*1.4598114);	// Orbit counter [29:14] 3564bx/orbit*25ns/bx=89.1us x 16384=1.4589114 seconds per tick
	uptime_hr  = uptime/3600;					// hours
	uptime_min = (uptime/60)%60;				// minutes 0-59
	uptime_sec = uptime%60;						// seconds 0-59

	// Read board status register
	adr    = bdstatus_adr+base_adr;
	status = vme_read(adr,rd_data);

	bd_status_ok	= (rd_data >>  0) & 0x1;
	bd_vstat_5p0v	= (rd_data >>  1) & 0x1;
	bd_vstat_3p3v	= (rd_data >>  2) & 0x1;
	bd_vstat_1p8v	= (rd_data >>  3) & 0x1;
	bd_vstat_1p5v	= (rd_data >>  4) & 0x1;
	bd_t_crit		= (rd_data >>  5) & 0x1;
	vsm_ok			= (rd_data >>  6) & 0x1;
	vsm_aborted		= (rd_data >>  7) & 0x1;
	vsm_cksum_ok	= (rd_data >>  8) & 0x1;
	vsm_wdcnt_ok	= (rd_data >>  9) & 0x1;
	jsm_ok			= (rd_data >> 10) & 0x1;
	jsm_aborted		= (rd_data >> 11) & 0x1;
	jsm_cksum_ok	= (rd_data >> 12) & 0x1;
	jsm_wdcnt_ok	= (rd_data >> 13) & 0x1;
	jsm_tck_fpga_ok	= (rd_data >> 14) & 0x1;
	jsm_tckcnt_ok	= (rd_data >> 15) & 0x1;

	// Read Sync error registers
	adr     = base_adr+sync_err_ctrl_adr;
	status  = vme_read(adr,rd_data);
	sync_err_reset            = (rd_data >>  0) & 0x1;
	clct_bx0_sync_err_en      = (rd_data >>  1) & 0x1;
	alct_ecc_rx_err_en        = (rd_data >>  2) & 0x1;
	alct_ecc_tx_err_en        = (rd_data >>  3) & 0x1;
	bx0_match_err_en          = (rd_data >>  4) & 0x1;
	clock_lock_lost_err_en    = (rd_data >>  5) & 0x1;
	sync_err_blanks_mpc_en    = (rd_data >>  6) & 0x1;
	sync_err_stops_pretrig_en = (rd_data >>  7) & 0x1;
	sync_err_stops_readout_en = (rd_data >>  8) & 0x1;
	sync_err                  = (rd_data >>  9) & 0x1; 
	clct_bx0_sync_err         = (rd_data >> 10) & 0x1; 
	alct_ecc_rx_err_ff        = (rd_data >> 11) & 0x1; 
	alct_ecc_tx_err_ff        = (rd_data >> 12) & 0x1; 
	bx0_match_err_ff          = (rd_data >> 13) & 0x1; 
	clock_lock_lost_err_ff    = (rd_data >> 14) & 0x1; 
	sync_err_force            = (rd_data >> 15) & 0x1;

	adr    = seq_clctm_adr+base_adr;
	status = vme_read(adr,rd_data);
	clock_lost_lost_clct   = (rd_data >> 14) & 0x1;
	clct_bx0_sync_err_clct = (rd_data >> 15) & 0x1;

	// Bang mode
	if (ifunc<0) goto L1115;

	// Display TMB base board ADC
	fprintf(stdout,"\n");
	fprintf(stdout,"\tTMB2005E ADC\n");
	fprintf(stdout,"\t+5.0 TMB      %5.3f V  %8.3f A\n",v5p0,		a5p0);
	fprintf(stdout,"\t+3.3 TMB      %5.3f V  %8.3f A\n",v3p3,		a3p3);
	fprintf(stdout,"\t+1.5 TMBcore  %5.3f V  %8.3f A\n",v1p5core,	a1p5core);
	fprintf(stdout,"\t+1.5 GTLtt    %5.3f V  %8.3f A\n",v1p5tt,		a1p5tt);
	fprintf(stdout,"\t+1.0 GTLref   %5.3f V  %8.3f A\n",v1p0,		0.0);
	fprintf(stdout,"\t+3.3 RAT      %5.3f V  %8.3f A\n",v3p3,		a3p3rat);	// v3p3rat depends on sh921 setting
	fprintf(stdout,"\t+1.8 RATcore  %5.3f V  %8.3f A\n",v1p8rat,	a1p8rat);	// a1p8rat depends on sh921 setting
	fprintf(stdout,"\t+vref/2       %5.3f V  %8.3f A\n",vref2,		0.0);
	fprintf(stdout,"\t+vzero        %5.3f V  %8.3f A\n",vzero,		0.0);
	fprintf(stdout,"\t+vref         %5.3f V  %8.3f A\n",vref,		0.0);

	// Display Spartan-6 mezzanine ADC
	if (fpga_series=="XC6SLX150")
	{
		fprintf(stdout,"\n");
		fprintf(stdout,"\tSpartan6 ADC\n");
		fprintf(stdout,"\t+3.3 Vcc      %5.3f V\n",v3p3_mez);
		fprintf(stdout,"\t+2.5 Vccaux   %5.3f V\n",v2p5_mez);
		fprintf(stdout,"\t+1.5 Vcore    %5.3f V\n",vcore_mez);
		fprintf(stdout,"\t+1.8 Vccprom  %5.3f V\n",v1p8_mez);
		fprintf(stdout,"\t+1.2 Vccint   %5.3f V\n",v1p2_mez);
		fprintf(stdout,"\t+Tfpga       %6.3f C  %5.1f F\n",tfpga_mez,(32.+tfpga_mez*9.0/5.0));
		fprintf(stdout,"\t+Tsink       %6.3f C  %5.1f F\n",tsink_mez,(32.+tsink_mez*9.0/5.0));
		fprintf(stdout,"\t+vref/2       %5.3f V\n",vref2_mez);
		fprintf(stdout,"\t+vzero        %5.3f V\n",vzero_mez);
		fprintf(stdout,"\t+vref         %5.3f V\n",vref_mez);
	}

	// Display Virtex-6 Sysmon ADC
	if (fpga_series=="XC6VLX195T")
	{
		fprintf(stdout,"\n");
		fprintf(stdout,"\tVirtex6 Sysmon ADC\n");
		fprintf(stdout,"\t+2.5  Vccaux   %5.3f V\n",sysmon_vccaux);
		fprintf(stdout,"\t+1.0  Vccint   %5.3f V\n",sysmon_vccint);
		fprintf(stdout,"\t+1.25 Vref     %5.3f V\n",sysmon_vref);
		fprintf(stdout,"\t+0.0  Vzero    %5.3f V\n",sysmon_vzero);
		fprintf(stdout,"\t+Tfpga        %6.3f C  %5.1f F\n",sysmon_temp_c,sysmon_temp_f);
	}

	// Display Temperatures
	fprintf(stdout,"\n");
	fprintf(stdout,"\tTMB2005E Temperature IC\n");
	fprintf(stdout,"\tT tmb pcb  %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_local_f_tmb,t_local_c_tmb,tcrit_local_f_tmb,tcrit_local_c_tmb);
	fprintf(stdout,"\tT tmb fpga %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_remote_f_tmb,t_remote_c_tmb,tcrit_remote_f_tmb,tcrit_remote_c_tmb);

	fprintf(stdout,"\n");
	fprintf(stdout,"\tRAT2005E Temperature IC\n");
	fprintf(stdout,"\tT rat pcb  %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_local_f_rat,t_local_c_rat,tcrit_local_f_rat,tcrit_local_c_rat);
	fprintf(stdout,"\tT rat xstr %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_remote_f_rat,t_remote_c_rat,tcrit_remote_f_rat,tcrit_remote_c_rat);

	fprintf(stdout,"\n");
	fprintf(stdout,"\tTMB2005E Uptime\n");
	fprintf(stdout,"\t%3.3ihr %2.2imin %2.2isec. uptimer=%5i\n",uptime_hr,uptime_min,uptime_sec,uptime);

	// Display auto PROM status
	fprintf(stdout,"\n");
	fprintf(stdout,"\tTMB2005E Board Status\n");
	fprintf(stdout,"\tbd_status: ok=%1i\n",bd_status_ok);
	fprintf(stdout,"\tbd_status: 5.0v=%1i 3.3v=%1i 1.8v=%1i 1.5v=%1i tcrit=%1i\n",bd_vstat_5p0v,bd_vstat_3p3v,bd_vstat_1p8v,bd_vstat_1p5v,bd_t_crit);
	fprintf(stdout,"\tvsm:       ok=%1i aborted=%1i cksum_ok=%1i wdcnt_ok=%1i\n",vsm_ok,vsm_aborted,vsm_cksum_ok,vsm_wdcnt_ok);
	fprintf(stdout,"\tjsm:       ok=%1i aborted=%1i cksum_ok=%1i wdcnt_ok=%1i tckcnt_ok=%1i tck_fpga_ok=%1i\n",jsm_ok,jsm_aborted,jsm_cksum_ok,jsm_wdcnt_ok,jsm_tckcnt_ok,jsm_tck_fpga_ok);

	// Display Sync status
	fprintf(stdout,"\n");
	fprintf(stdout,"\tTMB2005E Sync Status\n");
	fprintf(stdout,"\tsync_err_reset            = %1i\n",sync_err_reset);
	fprintf(stdout,"\tclct_bx0_sync_err_en      = %1i\n",clct_bx0_sync_err_en);
	fprintf(stdout,"\talct_ecc_rx_err_en        = %1i\n",alct_ecc_rx_err_en);
	fprintf(stdout,"\talct_ecc_tx_err_en        = %1i\n",alct_ecc_tx_err_en);
	fprintf(stdout,"\tbx0_match_err_en          = %1i\n",bx0_match_err_en);
	fprintf(stdout,"\tclock_lock_lost_err_en    = %1i\n",clock_lock_lost_err_en);

	fprintf(stdout,"\tsync_err_blanks_mpc_en    = %1i\n",sync_err_blanks_mpc_en);
	fprintf(stdout,"\tsync_err_stops_pretrig_en = %1i\n",sync_err_stops_pretrig_en);
	fprintf(stdout,"\tsync_err_stops_readout_en = %1i\n",sync_err_stops_readout_en);

	fprintf(stdout,"\tsync_err                  = %1i\n",sync_err);
	fprintf(stdout,"\tclct_bx0_sync_err         = %1i\n",clct_bx0_sync_err);
	fprintf(stdout,"\talct_ecc_rx_err_ff        = %1i\n",alct_ecc_rx_err_ff);
	fprintf(stdout,"\talct_ecc_tx_err_ff        = %1i\n",alct_ecc_tx_err_ff);
	fprintf(stdout,"\tbx0_match_err_ff          = %1i\n",bx0_match_err_ff);
	fprintf(stdout,"\tclock_lock_lost_err_ff    = %1i\n",clock_lock_lost_err_ff);

	fprintf(stdout,"\tsync_err_force            = %1i\n",sync_err_force);

	fprintf(stdout,"\tclock_lost_lost_clct      = %1i\n",clock_lost_lost_clct);
	fprintf(stdout,"\tclct_bx0_sync_err_clct    = %1i\n",clct_bx0_sync_err_clct);


	// Display Spartan-6 FPGA Status registers
	if (fpga_series=="XC6SLX150" && s6_stat_en)
	{
		fprintf(stdout,"\n");
		fprintf(stdout,"\tSpartan6 STAT register\n");
		fprintf(stdout,"\tSWWD_strikeout = %3X \t Indicates error to configure   \n",s6_SWWD_strikeout);
		fprintf(stdout,"\tIN_PWRDN       = %3X \t SUSPEND status                 \n",s6_IN_PWRDN      );
		fprintf(stdout,"\tDONE           = %3X \t DONEIN input from DONE pin     \n",s6_DONE          );
		fprintf(stdout,"\tINIT_B         = %3X \t Value of INIT_B                \n",s6_INIT_B        );
		fprintf(stdout,"\tMODE           = %3X \t Value of MODE pins (0, M1,M0)  \n",s6_MODE          );
		fprintf(stdout,"\tHSWAPEN        = %3X \t HSWAPEN status                 \n",s6_HSWAPEN       );
		fprintf(stdout,"\tPART_SECURED   = %3X \t Decryption security 0=not set  \n",s6_PART_SECURED  );
		fprintf(stdout,"\tDEC_ERROR      = %3X \t FDRI decryption operation 0=err\n",s6_DEC_ERROR     );
		fprintf(stdout,"\tGHIGH_B        = %3X \t Status of GHIGH                \n",s6_GHIGH_B       );
		fprintf(stdout,"\tGWE            = %3X \t Status of Global Write Enable  \n",s6_GWE           );
		fprintf(stdout,"\tGTS_CFG_B      = %3X \t Status of Global 3-State       \n",s6_GTS_CFG_B     );
		fprintf(stdout,"\tDCM_LOCK       = %3X \t DCMs and PLLs are locked       \n",s6_DCM_LOCK      );
		fprintf(stdout,"\tID_ERROR       = %3X \t IDCODE not validated write FDRI\n",s6_ID_ERROR      );
		fprintf(stdout,"\tCRC_ERROR      = %3X \t CRC error                      \n",s6_CRC_ERROR     );

		fprintf(stdout,"\n");
		fprintf(stdout,"\tSpartan6 BOOTSTS register\n");
		fprintf(stdout,"\tSTRIKE_CNT     = %3X \t Strike count                   \n",s6_STRIKE_CNT    );
		fprintf(stdout,"\tCRC_ERROR_1    = %3X \t CRC error                      \n",s6_CRC_ERROR_1   );
		fprintf(stdout,"\tID_ERROR_1     = %3X \t IDCODE not validated write FDRI\n",s6_ID_ERROR_1    );
		fprintf(stdout,"\tWTO_ERROR_1    = %3X \t Watchdog time-out error        \n",s6_WTO_ERROR_1   );
		fprintf(stdout,"\tRESERVED_8     = %3X \t Reserved                       \n",s6_RESERVED_8    );
		fprintf(stdout,"\tFALLBACK_1     = %3X \t 1=Fallback to address 00       \n",s6_FALLBACK_1    );
		fprintf(stdout,"\tVALID_1        = %3X \t Status Valid                   \n",s6_VALID_1       );
		fprintf(stdout,"\tCRC_ERROR_0    = %3X \t CRC error                      \n",s6_CRC_ERROR_0   );
		fprintf(stdout,"\tID_ERROR_0     = %3X \t IDCODE not validated write FDRI\n",s6_ID_ERROR_0    );
		fprintf(stdout,"\tWTO_ERROR_0    = %3X \t Watchdog time-out error        \n",s6_WTO_ERROR_0   );
		fprintf(stdout,"\tRESERVED       = %3X \t Reserved                       \n",s6_RESERVED      );
		fprintf(stdout,"\tFALLBACK_0     = %3X \t 1=Fallback to golden stream adr\n",s6_FALLBACK_0    );
		fprintf(stdout,"\tVALID_0        = %3X \t Status Valid                   \n",s6_VALID_0       );

		fprintf(stdout,"\n");
		fprintf(stdout,"\tSpartan6 SEU_OPT register\n");
		fprintf(stdout,"\tRESERVED_15    = %3X \t Reserved, default 1            \n",s6_RESERVED_15   );
		fprintf(stdout,"\tRESERVED_14    = %3X \t Reserved, default 0            \n",s6_RESERVED_14   );
		fprintf(stdout,"\tSEU_FREQ       = %3X \t Bus_clk frequency SEU detection\n",s6_SEU_FREQ      );
		fprintf(stdout,"\tSEU_RUN_ON_ERR = %3X \t On SEU_ERR 0=Halt 1=Continue   \n",s6_SEU_RUN_ON_ERR);
		fprintf(stdout,"\tGLUT_MASK      = %3X \t Mask out LUTRAM/SRL readback   \n",s6_GLUT_MASK     );
		fprintf(stdout,"\tSEU_ENABLE     = %3X \t Enable SEU Detection 0=dis,1=en\n",s6_SEU_ENABLE    );
	}

	printf("\n\t<cr> to continue:");
	gets(line);
	return;
}
//------------------------------------------------------------------------------
//	Read FPGA and User PROM ID codes
//------------------------------------------------------------------------------
void L1200() {
L1200:

	//--
	// TMB Mezzanine FPGA and PROM Chain
	//--
	if      (id_rev_fpga==3) {ichain=0x24; nchips=3;}		// Spartan6 TMB Mezzanine pgm jtag chain
	else if (id_rev_fpga==6) {ichain=0x14; nchips=1;}		// Virtex6  TMB Mezzanine pgm jtag chain
	else                     {ichain=0x04; nchips=5;}		// Virtex2  TMB Mezzanine pgm jtag chain

	adr=boot_adr;
	vme_jtag_anystate_to_rti(adr,ichain);					// Take TAP to RTI

	// Read TMB FPGA and PROM IDcodes
	for (chip_id=0; chip_id<nchips; ++chip_id)
	{
		if  (chip_id==0) opcode = 0x09;							// FPGA IDcode opcode
		if  (chip_id>=1) opcode = 0xFE;							// PROM IDcode opcode
		reg_len = 32;											// IDcode length

		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(tdo,idcode,32,0);								// Deserialize
		idcode_decode (idcode, sdevice_type, sdevice_name, sdevice_version, sdevice_size);

		// Read FPGA/PROM USERCodes
		if  (chip_id==0) opcode = 0x08;							// FPGA USERcode opcode
		if  (chip_id>=1) opcode = 0xFD;							// PROM USERcode opcode
		reg_len = 32;											// USERcode length

		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],usercode,32,0);						// Deserialize

		fprintf(stdout,"\tTMB  Mez  Device=%1i IDcode=%8.8X %s Name=%s\tVer=%s\tSize=%s USERcode=%8.8X\n",
				chip_id, idcode, sdevice_type.c_str(), sdevice_name.c_str(), sdevice_version.c_str(), sdevice_size.c_str(),usercode);

		// Close for chip_id
	}	
	fprintf(stdout,"\n");

	//--
	// TMB User PROM Chain
	//--
	ichain = 0x0008;										// User PROM chain
	nchips = 2;
	adr    = boot_adr;
	vme_jtag_anystate_to_rti(adr,ichain);					// Take TAP to RTI

	// Read User PROM IDcodes XC18V256/XC18V512 (8-bit opcode)
	for (chip_id=0; chip_id<nchips; ++chip_id)
	{
		opcode  = 0xFE;											// IDcode opcode
		reg_len = 32;											// IDcode length

		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(tdo,idcode,32,0);								// Deserialize
		idcode_decode (idcode, sdevice_type, sdevice_name, sdevice_version, sdevice_size);

		// Read PROM USERCodes
		opcode  = 0xFD;											// PROM USERcode opcode
		reg_len = 32;											// USERcode length

		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],usercode,32,0);						// Deserialize

		fprintf(stdout,"\tTMB  User Device=%1i IDcode=%8.8X %s Name=%s\tVer=%s\tSize=%s USERcode=%8.8X\n",
				chip_id, idcode, sdevice_type.c_str(), sdevice_name.c_str(), sdevice_version.c_str(), sdevice_size.c_str(),usercode);

		// Close for chip_id
	}	
	fprintf(stdout,"\n");

	//--
	// RAT FPGA and PROM Chain
	//--
	ichain = 0x000D;										// RAT jtag chain
	nchips = 2;
	adr    = boot_adr;
	vme_jtag_anystate_to_rti(adr,ichain);					// Take TAP to RTI

	// Read Spartan IIE FPGA (5 bit opcode) and PROM (8 bit opcode) IDcodes 
	for (chip_id=0; chip_id<nchips; ++chip_id) 
	{
		if  (chip_id==0) opcode = 0x09;							// FPGA IDcode opcode
		if  (chip_id>=1) opcode = 0xFE;							// PROM IDcode opcode
		reg_len = 32;											// IDcode length

		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(tdo,idcode,32,0);								// Deserialize
		idcode_decode (idcode, sdevice_type, sdevice_name, sdevice_version, sdevice_size);

		// Read FPGA/PROM USERCodes
		if  (chip_id==0) opcode = 0x08;							// FPGA USERcode opcode
		if  (chip_id>=1) opcode = 0xFD;							// PROM USERcode opcode
		reg_len = 32;											// USERcode length

		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],usercode,32,0);						// Deserialize

		fprintf(stdout,"\tRAT  Modu Device=%1i IDcode=%8.8X %s Name=%s\tVer=%s\tSize=%s USERcode=%8.8X\n",
				chip_id, idcode, sdevice_type.c_str(), sdevice_name.c_str(), sdevice_version.c_str(), sdevice_size.c_str(),usercode);

		// Close for chip_id
	}	
	fprintf(stdout,"\n");
	if (ifunc>0) {printf("\t<cr> to continue:"); gets(line);}

	// Read User PROM data:
	// Enable 1 prom disable the other, they share the onboard led bus
	for (iprom=0; iprom<=1; ++iprom)
	{
		jprom = (iprom+1)%2;

		prom_clk[iprom] = 0;	// enable this one
		prom_oe[iprom]  = 1;
		prom_nce[iprom] = 0;

		prom_clk[jprom] = 0;	// disble this one
		prom_oe[jprom]  = 0;
		prom_nce[jprom] = 1;
		prom_src = 1;

		adr     = vme_prom_adr+base_adr;
		wr_data = 
			(prom_src    << 14) |
			(prom_nce[1] << 13) |
			(prom_oe[1]  << 12) |
			(prom_clk[1] << 11) |
			(prom_nce[0] << 10) |
			(prom_oe[0]  <<  9) |
			(prom_clk[0] <<  8);

		status = vme_write(adr,wr_data);

		// Read data from selected PROM
		for (prom_adr=0; prom_adr<=15; ++ prom_adr) {
			status = vme_read(adr,rd_data);
			prom_data = rd_data & 0xFF;
			fprintf(stdout,  "\tPROM%1i Adr=%4.4X Data=%2.2X\n",iprom,prom_adr,prom_data);
			fprintf(log_file,"\tPROM%1i Adr=%4.4X Data=%2.2X\n",iprom,prom_adr,prom_data);

			// Toggle clock to advance address
			prom_clk[iprom] = 1;
			wr_data = 
				(prom_src    << 14) |
				(prom_nce[1] << 13) | 
				(prom_oe[1]  << 12) |
				(prom_clk[1] << 11) | 
				(prom_nce[0] << 10) | 
				(prom_oe[0]  <<  9) | 
				(prom_clk[0] <<  8);

			status = vme_write(adr,wr_data);

			prom_clk[iprom] = 0;
			wr_data = 
				(prom_src    << 14) |
				(prom_nce[1] << 13) | 
				(prom_oe[1]  << 12) |
				(prom_clk[1] << 11) | 
				(prom_nce[0] << 10) |
				(prom_oe[0]  <<  9) | 
				(prom_clk[0] <<  8);

			status = vme_write(adr,wr_data);
		}	// close for prom_adr

		// Turn PROMs off
		prom_clk[iprom] = 0;	// disble this one
		prom_oe[iprom]  = 0;
		prom_nce[iprom] = 1;
		prom_src = 0;

		wr_data = 
			(prom_src    << 14) |
			(prom_nce[1] << 13) |
			(prom_oe[1]  << 12) |
			(prom_clk[1] << 11) |
			(prom_nce[0] << 10) |
			(prom_oe[0]  <<  9) | 
			(prom_clk[0] <<  8);

		status = vme_write(adr,wr_data);

		printf("\n");
	}	// close for prom_adr

	// Bang mode 
	if (ifunc>0) {printf("\t<cr> to continue:"); gets(line);}
	if (ifunc<0) goto L1200;
	return;
}
//------------------------------------------------------------------------------
//	Read Hardware Serial Numbers
//------------------------------------------------------------------------------
void L1300() {
	//L1300:

	// Set posneg=0, enable rat dsn
	adr    = vme_ratctrl_adr+base_adr;
	status = vme_read(adr,rd_data);
	rat_ctrl_data = rd_data;

	wr_data = rd_data & 0xFFFD;		// [0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en
	wr_data = wr_data | 0x0010;		// enable dsn bit
	status  = vme_write(adr,wr_data);

	// Enable RAT
	adr    = vme_loopbk_adr+base_adr;
	status = vme_read(adr,rd_data);
	loopstate = rd_data;

	wr_data = rd_data | 0x000C;		//  set front/rear=0 to enable RAT
	status  = vme_write(adr,wr_data);

	// Loop over dsn chips
	if (ifunc<0) goto bang_dsn;

	for (itype=0; itype<=2; ++itype) {
		adr = base_adr+vme_dsn_adr;
		dsn_rd(adr,itype,dsn);

		// Check CRC
		dow_crc(dsn,icrc);
		icrc_ok="ERR!";

		if (icrc==dsn[7] && icrc!=0) icrc_ok = "OK  ";
		fprintf(stdout,"\tDigital Serial for %s CRC=%2.2X DSN=%",dsn_chip[itype].c_str(),dsn[7]);
		for (i=5; i>0; i--) fprintf(stdout,"%2.2X",dsn[i]);
		fprintf(stdout," MFG=%2.2X %s\n",dsn[0],icrc_ok.c_str());

	}	// close itype

	// Put posneg back
	adr     = vme_ratctrl_adr+base_adr;
	wr_data = rat_ctrl_data;
	//	adr	    = rpc_txb_adr+base_adr;
	status  = vme_write(adr,wr_data);

	// Put loop state back
	adr     = vme_loopbk_adr+base_adr;
	wr_data = loopstate;
	status  = vme_write(adr,wr_data);
	pause("<cr> to continue:");
	return;						

	// Bang mode
bang_dsn:

	while (true) {
		for (itype=0; itype<=1; ++itype) {
			dsn_rd(adr,itype,dsn);
		}
		sleep(100);
	}
}
//------------------------------------------------------------------------------
//	Crate Scan looks in all slots for TMB modules
//------------------------------------------------------------------------------
void L1400() {
	//L1400:

	status = vme_errs(1);	// turn off bus-timeout error messages
	islot_old = islot;

	// Loop over crate slots
	for (islot=0; islot<=31; ++islot)
	{

		// Read ID registers
		for (i=0; i<=3; ++i) {
			adr    = (islot << 19) + vme_idreg_adr + 2*i;
			status = vme_read(adr,rd_data);
			id_reg[i] = rd_data;
		}

		// Read boot register
		adr    = (islot << 19) + tmb_boot_adr;
		status = vme_read(adr,rd_data);
		boot_data = rd_data;

		// Decode ID registers
		id_slot = (id_reg[0] >> 8) & 0x00FF;
		id_ver  = (id_reg[0] >> 4) & 0x000F;
		id_type = (id_reg[0] >> 0) & 0x000F;
		id_month= (id_reg[1] >> 8) & 0x00FF;
		id_day  = (id_reg[1] >> 0) & 0x00FF;
		id_year =  id_reg[2];
		id_rev  =  id_reg[3];

		// See if it looks like a TMB
		if ((id_slot!=islot) && (islot!=tmb_global_slot) && (islot!=tmb_brcst_slot)) continue;	// Not a TMB
		if ((id_type!=firmware_normal) && (id_type!=firmware_debug)) continue;					// Not a TMB

		// Read Digital Serial numbers
		adr = (islot << 19)+vme_dsn_adr;
		dsn_rd(adr,0,dsn_tmb);
		dsn_rd(adr,1,dsn_mez);

		// Display found modules
		printf("\tSlot %2i type%1X v%2.2X/%2.2X/%4.4X ver%1X rev%4.4X boot%4.4X",islot,id_type,id_month,id_day,id_year,id_ver,id_rev,boot_data);
		printf(" sn" ); for(i=6; i>=1; --i) printf("%2.2X",dsn_tmb[i]);
		printf(" mez"); for(i=6; i>=1; --i) printf("%2.2X",dsn_mez[i]);
		printf("\n");

	}	// close for islot
	// Done
	islot  = islot_old;
	status = vme_errs(0);	// turn bus-timeout messages back on

	pause("<cr>=continue");
	return;
}
//------------------------------------------------------------------------------
//	Read Loopback Backplane JTAG Chain
//------------------------------------------------------------------------------
void L1500() {
	//L1500:

	printf("\tMake sure you removed the JTAG cable\n");

	// Select RAT JTAG chain from TMB boot register, backplane uses RAT JTAG signals
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Read FPGA/PROM IDcodes (8 bit opcode)
	for (chip_id=0; chip_id<=1; ++chip_id) {	// FPGA,PROM chip
		if (chip_id == 0) opcode = 0x09;			// FPGA IDcode opcode
		if (chip_id == 1) opcode = 0xFE;			// PROM IDcode opcode
		reg_len = 32;								// IDcode length

		vme_jtag_write_ir (adr,ichain ,chip_id, opcode);			// Set opcode
		vme_jtag_write_dr( adr,ichain, chip_id, tdi, tdo, reg_len);	// Write 0's read idcode
		tdi_to_i4 (&tdo[0], idcode, 32, 0);

		sidcode_good = "BAD ID CODE";
		if ((chip_id == 0) && (idcode == 0x20A10093)) sidcode_good = "OK";
		if ((chip_id == 1) && (idcode == 0x05034093)) sidcode_good = "OK";

		printf("\tBackplane %s device %1i IDcode  =%8.8X %s\n",rat_chip_type[chip_id].c_str(),chip_id,idcode,sidcode_good.c_str());
	} // close for chip_id

	// Read FPGA/PROM USERCodes (8 bit opcode)
	for (chip_id=0; chip_id<=1; ++ chip_id) {	// FPGA,PROM chip
		if (chip_id == 0) opcode = 0x08;			// FPGA USERcode opcode
		if (chip_id == 1) opcode = 0xFD;			// PROM USERcode opcode
		reg_len = 32;								// IDcode length

		vme_jtag_write_ir (adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr (adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],idcode,32,0);
		printf("\tBackplane %s device %1i USERcode=%8.8X\n",rat_chip_type[chip_id].c_str(),chip_id,idcode);
	} // close for chip_id

	// Read Backplane USER1 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x02;								// FPGA USER1 opcode
	reg_len = 192;								// USER1 register length

	vme_jtag_write_ir (adr, ichain, chip_id, opcode);				// Set opcode
	vme_jtag_write_dr (adr, ichain, chip_id, tdi, tdo, reg_len);	// Write 0's read idcode
	//	for (i=1; i<=192; ++i) printf("%1i",tdo[i]); printf("\n");

	// Decode Backplane USER1 register
	for (i=0; i<reg_len; ++i) bs[i]=tdo[i];

	tdi_to_i4 (&tdo[  0], back_user1[0], 32, 0);
	tdi_to_i4 (&tdo[ 32], back_user1[1], 32, 0);
	tdi_to_i4 (&tdo[ 64], back_user1[2], 32, 0);
	tdi_to_i4 (&tdo[ 96], back_user1[3], 32, 0);
	tdi_to_i4 (&tdo[128], back_user1[4], 32, 0);
	tdi_to_i4 (&tdo[160], back_user1[5], 32, 0);

	printf("\tBackplane USER1="); for (i=5; i>=0; --i) printf("%8.8X",back_user1[i]); printf("\n");

	tdi_to_i4 (&bs[ 0], bs_begin,    4,  0);
	tdi_to_i4 (&bs[ 4], bs_version,  4,  0);
	tdi_to_i4 (&bs[ 8], bs_monthday, 16, 0);
	tdi_to_i4 (&bs[24], bs_year,     16, 0);

	for (i=1; i<=25; ++i) {
		p2a_gnd_c[i]= bs[i+39];		// p2a_gnd_c[25:1]=bs[64:40]
	}

	p2b_gnd_c[1]	= bs[65];
	p2b_gnd_c[3]	= bs[66];
	p2b_gnd_c[5]	= bs[67];
	p2b_gnd_c[7]	= bs[68];
	p2b_gnd_c[9]	= bs[69];
	p2b_gnd_c[11]	= bs[70];

	p2b_vtt_c[4]	= bs[71];
	p2b_vtt_c[6]	= bs[72];
	p2b_vtt_c[8]	= bs[73];
	p2b_vtt_c[10]	= bs[74];

	for (i=1; i<=25; ++i) {
		p3a_gnd_c[i]	= bs[i+74];	// p3a_gnd_c[25:1]=bs[99:75]
	}

	p3a_gnd_f[1]	= bs[100];
	p3a_gnd_f[3]	= bs[101];
	p3a_gnd_f[5]	= bs[102];
	p3a_gnd_f[7]	= bs[103];
	p3a_gnd_f[9]	= bs[104];
	p3a_gnd_f[11]	= bs[105];
	p3a_gnd_f[13]	= bs[106];
	p3a_gnd_f[15]	= bs[107];
	p3a_gnd_f[17]	= bs[108];
	p3a_gnd_f[19]	= bs[109];
	p3a_gnd_f[21]	= bs[110];
	p3a_gnd_f[23]	= bs[111];
	p3a_gnd_f[25]	= bs[112];

	p3a_vcc_a[16]	= bs[113];
	p3a_vcc_a[18]	= bs[114];
	p3a_vcc_a[20]	= bs[115];
	p3a_vcc_a[22]	= bs[116];	
	p3a_vcc_a[24]	= bs[117];

	for (i=1; i<=25; ++i) {
		p3b_gnd_c[i]	= bs[i+117];	// p3b_gnd_c[25:1]=bs[142:118]
	}

	p3b_gnd_f[1]	= bs[143];
	p3b_gnd_f[3]	= bs[144];
	p3b_gnd_f[5]	= bs[145];
	p3b_gnd_f[7]	= bs[146];
	p3b_gnd_f[9]	= bs[147];
	p3b_gnd_f[11]	= bs[148];
	p3b_gnd_f[13]	= bs[149];
	p3b_gnd_f[15]	= bs[150];
	p3b_gnd_f[17]	= bs[151];
	p3b_gnd_f[19]	= bs[152];
	p3b_gnd_f[21]	= bs[153];
	p3b_gnd_f[23]	= bs[154];
	p3b_gnd_f[25]	= bs[155];

	p3b_vcc_a[1]	= bs[156];
	p3b_vcc_a[3]	= bs[157];
	p3b_vcc_a[5]	= bs[158];
	p3b_vcc_a[7]	= bs[159];
	p3b_vcc_a[9]	= bs[160];
	p3b_vcc_a[11]	= bs[161];
	p3b_vcc_a[13]	= bs[162];
	p3b_vcc_a[15]	= bs[163];
	p3b_vcc_a[17]	= bs[164];
	p3b_vcc_a[19]	= bs[165];
	p3b_vcc_a[21]	= bs[166];
	p3b_vcc_a[23]	= bs[167];
	p3b_vcc_a[25]	= bs[168];

	p2a_gnd_c_ok	= bs[169];
	p2b_gnd_c_ok	= bs[170];
	p2b_vtt_c_ok	= bs[171];
	p3a_gnd_c_ok	= bs[172];
	p3a_gnd_f_ok	= bs[173];
	p3a_vcc_a_ok	= bs[174];
	p3b_gnd_c_ok	= bs[175];
	p3b_gnd_f_ok	= bs[176];
	p3b_vcc_a_ok	= bs[177];

	p2a_ok			= bs[178];
	p2b_ok			= bs[179];
	p3a_ok			= bs[180];
	p3b_ok			= bs[181];

	all_ok			= bs[182];
	bs_free			= bs[183];

	tdi_to_i4 (&bs[184], bs_endD, 4, 0);
	tdi_to_i4 (&bs[188], bs_endE, 4, 0);

	printf("\n");
	printf("\tbs_begin      %1.1X\n",bs_begin);
	printf("\tbs_version    %1.1X\n",bs_version);
	printf("\tbs_monthday   %4.4X\n",bs_monthday);
	printf("\tbs_year       %4.4X\n",bs_year);
	printf("\n");

	for (i= 1; i<=25; ++i  ) printf("\tp2a_gnd_c[%2i]=%1i\n",i,p2a_gnd_c[i]); printf("\n");
	for (i= 1; i<=11; i=i+2) printf("\tp2b_gnd_c[%2i]=%1i\n",i,p2b_gnd_c[i]); printf("\n");
	for (i= 4; i<=10; i=i+2) printf("\tp2b_vtt_c[%2i]=%1i\n",i,p2b_vtt_c[i]); printf("\n");
	for (i= 1; i<=25; ++i  ) printf("\tp3a_gnd_c[%2i]=%1i\n",i,p3a_gnd_c[i]); printf("\n");
	for (i= 1; i<=25; i=i+2) printf("\tp3a_gnd_f[%2i]=%1i\n",i,p3a_gnd_f[i]); printf("\n");
	for (i=16; i<=24; i=i+2) printf("\tp3a_vcc_a[%2i]=%1i\n",i,p3a_vcc_a[i]); printf("\n");
	for (i= 1; i<=25; ++i  ) printf("\tp3b_gnd_c[%2i]=%1i\n",i,p3b_gnd_c[i]); printf("\n");
	for (i= 1; i<=25; i=i+2) printf("\tp3b_gnd_f[%2i]=%1i\n",i,p3b_gnd_f[i]); printf("\n");
	for (i= 1; i<=25; i=i+2) printf("\tp3b_vcc_a[%2i]=%1i\n",i,p3b_vcc_a[i]); printf("\n");

	printf("\tp2a_gnd_c_ok = %1i\n",p2a_gnd_c_ok);
	printf("\tp2b_gnd_c_ok = %1i\n",p2b_gnd_c_ok);
	printf("\tp2b_vtt_c_ok = %1i\n",p2b_vtt_c_ok);
	printf("\tp3a_gnd_c_ok = %1i\n",p3a_gnd_c_ok);
	printf("\tp3a_gnd_f_ok = %1i\n",p3a_gnd_f_ok);
	printf("\tp3a_vcc_a_ok = %1i\n",p3a_vcc_a_ok);
	printf("\tp3b_gnd_c_ok = %1i\n",p3b_gnd_c_ok);
	printf("\tp3b_gnd_f_ok = %1i\n",p3b_gnd_f_ok);
	printf("\tp3b_vcc_a_ok = %1i\n",p3b_vcc_a_ok);
	printf("\n");

	printf("\tp2a_ok = %1i\n",p2a_ok);
	printf("\tp2b_ok = %1i\n",p2b_ok);
	printf("\tp3a_ok = %1i\n",p3a_ok);
	printf("\tp3b_ok = %1i\n",p3b_ok);
	printf("\n");

	printf("\tall_ok = %1i\n",all_ok);
	printf("\tbsfree = %1i\n",bs_free);
	printf("\n");

	printf("\tbs_endD        %1.1X\n",bs_endD);
	printf("\tbs_endE        %1.1X\n",bs_endE);

	pause ("continue");
	return;
}
//------------------------------------------------------------------------------
//	Trigger Test Sub-Menu
//------------------------------------------------------------------------------
void L1600() {
L1600:
	// Check firmware type
	if (firmware_type != firmware_normal) {
		printf("\n\tTMB has wrong firmware type for this operation\n");
		printf("\tContinue anyway? <cr>=n ");
		gets(line);
		if (line[0]==NULL) return;
	}

	// Check for jtag cable
	if (vme_jtag_cable_detect(base_adr)) {
		printf("\n\tJTAG cable is still connected, board status tests will fail.\n");
		printf("\tContinue anyway? <cr>=n ");
		gets(line);
		if (line[0]==NULL) return;
	}

	// Get VME slot number, used for csc id
	adr    = base_adr+vme_idreg_adr;
	status = vme_read(adr,rd_data);
	id_slot= (rd_data >> 8) & 0x00FF;

	printf("\t   TMB Trigger Test Menu for TMB in physical slot%3i\n\n",id_slot);
	printf("\t 1:  Inject ALCT\n");
	printf("\t 2:  Inject CLCT\n");
	printf("\t 3:  Inject ALCT+CLCT\n");
	printf("\t 4:  Inject ALCT+CLCT + readout\n");
	printf("\t 5:  Fire ext_trig + L1A to ALCT + readout ALCT RAM\n");
	printf("\t 6:  Fire CLCT ext trig linked with ALCT ext trig\n");
	printf("\t 7:  Fire CLCT pattern injector, check CLCT0\n");
	printf("\t 8:  External Trigger ALCT+CLCT\n");
	printf("\t 9:  External Trigger ALCT\n");
	printf("\t10:  External Trigger CLCT\n");
	printf("\t11:  Ext Trig ALCT+CLCT with GTL pulser\n");
	printf("\t12:  Ext Trig ALCT+CLCT with GTL pulser check CRC\n");
	printf("\t13:  Check bxn reset and increment\n");
	printf("\t14:  Fire L1A-only event. check readout\n");
	printf("\t15:  Fire VME trigger + readout\n");
	printf("\t<cr> Exit\n");
	printf("       > ");

	gets(line);
	if (line[0]==NULL) return;
	sscanf(line,"%i",&ifunc);
	i=abs(ifunc);

	if (i== 1) goto L16100;
	if (i== 2) goto L16200;
	if (i== 3) goto L16300;
	if (i== 4) goto L16400;
	if (i== 5) goto L16500;
	if (i== 6) goto L16600;
	if (i== 7) goto L16700;
	if (i== 8) goto L16800;
	if (i== 9) goto L16900;
	if (i==10) goto L96000;
	if (i==11) goto L96100;
	if (i==12) goto L96200;
	if (i==13) goto L96300;
	if (i==14) goto L96400;
	if (i==15) goto L96500;
	goto L1600;

	//------------------------------------------------------------------------------
	//	Inject ALCT
	//------------------------------------------------------------------------------
L16100:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, turn on L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x003D;
	status  = vme_write(adr,wr_data);

	// Enable sequencer trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0004;
	//	wr_data = wr_data | (114<<8);
	status = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, disable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5); // post-rat firmware
	status  = vme_write(adr,wr_data);

	// Turn off CLCT cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0FFF;
	status  = vme_write(adr,wr_data);

	// Select ALCT pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_data = rd_data & 0xFF00;
	wr_data = rd_data | 0x0002;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;			// start_trigger
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Clear previous inject
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFD;
	status  = vme_write(adr,wr_data);

	// Fire ALCT injector
	wr_data = wr_data | 0x0002;	// Fire ALCT inject
	status  = vme_write(adr,wr_data);

	// Clear previous inject
	wr_data = rd_data & 0xFFFD;		
	status  = vme_write(adr,wr_data);

	// Check for blue flash
	adr    = base_adr+vme_led_adr;
	status = vme_read(adr,rd_data);
	blue_flash = rd_data & 0x1;

	if (ifunc>0) {
		if (blue_flash==0) printf("\tNO BLUE FLASH. Rats =:-(\n");
		if (blue_flash==1) printf("\tBlue flash. Cool\n");
	}

	// Check scintillator veto is set
	adr    = base_adr+seqmod_adr;
	status = vme_read(adr,rd_data);
	scint_veto = (rd_data>>13) & 0x1;
	if (scint_veto!=1) pause("scint veto failed to set");

	// Clear scintillator veto
	wr_data = rd_data | (1<<12);
	status  = vme_write(adr,wr_data);
	wr_data = wr_data ^ (1<<12);
	status  = vme_write(adr,wr_data);
	status  = vme_read(adr,rd_data);
	scint_veto = (rd_data>>12) & 0x1;
	if (scint_veto!=0) pause("scint veto failed to clear");

	// Read ALCT data wot triggered
	adr    = alct_alct0_adr+base_adr;
	status = vme_read(adr,rd_data);
	alct0_inj_rd = rd_data;

	adr    = alct_alct1_adr+base_adr;
	status = vme_read(adr,rd_data);
	alct1_inj_rd = rd_data;

	// Read injector generated ALCT data
	adr    = alct0_inj_adr+base_adr;
	status = vme_read(adr,rd_data);
	alct0_inj_wr = rd_data;

	adr    = alct1_inj_adr+base_adr;
	status = vme_read(adr,rd_data);
	alct1_inj_wr = rd_data;

	// Compare injected ALCT readback with generated ALCT
	ck("alct0_inj  ",alct0_inj_wr,alct0_inj_rd);
	ck("alct1_inj  ",alct1_inj_wr,alct1_inj_rd);

	// Decompose injected ALCT
	alct0_vpf	= (alct0_inj_rd >> 0) & 0x0001;	// Valid pattern flag
	alct0_qual	= (alct0_inj_rd >> 1) & 0x0003;	// Pattern quality
	alct0_amu	= (alct0_inj_rd >> 3) & 0x0001;	// Accelerator muon
	alct0_key	= (alct0_inj_rd >> 4) & 0x007F;	// Wire group ID number
	alct0_bxn	= (alct0_inj_rd >>11) & 0x0003;	// Bunch crossing number

	alct1_vpf	= (alct1_inj_rd >> 0) & 0x0001;	// Valid pattern flag
	alct1_qual	= (alct1_inj_rd >> 1) & 0x0003;	// Pattern quality
	alct1_amu	= (alct1_inj_rd >> 3) & 0x0001;	// Accelerator muon
	alct1_key	= (alct1_inj_rd >> 4) & 0x007F;	// Wire group ID number
	alct1_bxn	= (alct1_inj_rd >>11) & 0x0003;	// Bunch crossing number

	// Display ALCTs found
	if (ifunc>0) {
		printf("\tExpect:ALCT0:Key7 Q3 Bxn1 ALCT1:Key61 Q2 Bxn1\n");

		printf("\tALCT0: ");
		printf("vpf =%1i ",	alct0_vpf );
		printf("qual=%1i ", alct0_qual);
		printf("amu =%1i ", alct0_amu );
		printf("key =%3i ", alct0_key );
		printf("bxn =%1i ", alct0_bxn );
		printf("\n");

		printf("\tALCT1: ");
		printf("vpf =%1i ",	alct1_vpf );
		printf("qual=%1i ", alct1_qual);
		printf("amu =%1i ", alct1_amu );
		printf("key =%3i ", alct1_key );
		printf("bxn =%1i ", alct1_bxn );
		printf("\n");
	}

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	if (ifunc<0) goto L16100;
	goto L1600;

	//------------------------------------------------------------------------------
	//	Inject CLCT
	//------------------------------------------------------------------------------
L16200:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, turn on L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x003D;
	status  = vme_write(adr,wr_data);

	// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (114 << 8);
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, disable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CLCT cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;	// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;	// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0FFF;
	status  = vme_write(adr,wr_data);

	// Select pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_data = rd_data & 0xFF00;
	wr_data = rd_data | 0x0001;
	status  = vme_write(adr,wr_data);

	// Clear previous ALCT inject
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFD;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;			// start_trigger
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Clear previous  CLCT inject
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x7FFF;
	status  = vme_write(adr,wr_data);

	// Fire CLCT Injector
	wr_data = wr_data | 0x8000;
	status  = vme_write(adr,wr_data);

	// Clear previous inject	
	wr_data = rd_data & 0x7FFF;	
	status  = vme_write(adr,wr_data);

	// Check scintillator veto is set
	adr    = base_adr+seqmod_adr;
	status = vme_read(adr,rd_data);
	scint_veto = (rd_data >> 13) & 0x0001;
	if (scint_veto!=1) pause ("scint veto failed to set");

	// Clear scintillator veto
	wr_data = rd_data | (1 << 12);
	status  = vme_write(adr,wr_data);
	wr_data = wr_data ^ (1 << 12);
	status  = vme_write(adr,wr_data);
	status  = vme_read (adr,rd_data);
	scint_veto = (rd_data >> 12) & 0x1;
	if (scint_veto!=0) pause ("scint veto failed to clear");

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Bang mode
	if (ifunc<0) goto L16200;
	goto L1600;

	//------------------------------------------------------------------------------
	//	Inject ALCT+CLCT
	//------------------------------------------------------------------------------
L16300:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, turn on L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x003D;
	status  = vme_write(adr,wr_data);

	// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (114<<8);
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0005;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | 0x0003;
	status  = vme_write(adr,wr_data);

	// Turn off CLCT cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0FFF;
	status  = vme_write(adr,wr_data);

	// Select pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_data = rd_data & 0xFF00;
	wr_data = rd_data | 0x0001;
	status  = vme_write(adr,wr_data);

	// Clear previous ALCT inject
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFD;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;			// start_trigger
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Clear previous  CLCT inject
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x7FFF;
	status  = vme_write(adr,wr_data);

	// Fire CLCT Injector
	wr_data = wr_data | 0x8000;
	status  = vme_write(adr,wr_data);

	// Clear previous inject	
	wr_data = rd_data & 0x7FFF;
	status  = vme_write(adr,wr_data);

	// Check scintillator veto is set
	adr    = base_adr+seqmod_adr;
	status = vme_read(adr,rd_data);
	scint_veto = (rd_data>>13) & 0x1;
	if (scint_veto!=1) pause("scint veto failed to set");

	// Clear scintillator veto
	wr_data = rd_data | (1<<12);
	status  = vme_write(adr,wr_data);
	wr_data = wr_data ^ (1<<12);
	status  = vme_write(adr,wr_data);
	status  = vme_read(adr,rd_data);
	scint_veto = (rd_data>>12) & 0x1;
	if (scint_veto!=0) pause("scint veto failed to clear");

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	if (ifunc>0) goto L16300;
	goto L1600;

	//------------------------------------------------------------------------------
	//	Inject ALCT+CLCT then readout raw hits
	//------------------------------------------------------------------------------
L16400:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, turn on L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x003D;
	status  = vme_write(adr,wr_data);

	// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (l1a_delay << 8);
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0005;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | 0x0003;
	status  = vme_write(adr,wr_data);

	// Turn off CLCT cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer, set l1a window width
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x00FF;
	wr_data = wr_data | 0x0300;		// l1a window width
	status  = vme_write(adr,wr_data);

	// Take RAT out of sync mode
	adr     = vme_ratctrl_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFE;
	status  = vme_write(adr,wr_data);

	// Enable RPC injector
	adr     = rpc_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF80;	// clear out old bits
	wr_data = wr_data | 0x0001;	// rpc_mask_all 1=enable inputs from RPC

	if (rat_injector_sync) wr_data=wr_data | 0x0002;	// 1=enable RAT board injector
	else                   wr_data=wr_data | 0x0004;	// 1=enable RPC RAM internal injector

	rat_injector_delay=6;
	wr_data = wr_data | (rat_injector_delay << 3); // delay CLCT injector to wait for RAT
	status  = vme_write(adr,wr_data);

	// Select pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_data = rd_data & 0xFF00;
	wr_data = rd_data | 0x0001;
	status  = vme_write(adr,wr_data);

	// Clear previous ALCT inject
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFD;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;			// start_trigger
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Clear DMB RAM write-address
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	//reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Fire CLCT+ALCT Injectors
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x8000;	// fire injector
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0x7FFF;	// unfire
	status  = vme_write(adr,wr_data);

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Get DMB RAM word count and busy bit
	adr       = dmb_wdcnt_adr+base_adr;
	status    = vme_read(adr,rd_data);
	dmb_wdcnt = rd_data & 0x0FFF;
	dmb_busy  = (rd_data >> 14) & 0x0001;

	printf("\tdmb word count = %4i\n",dmb_wdcnt);
	printf("\tdmb busy       = %4i\n",dmb_busy);

	if (dmb_busy!=0) {
		pause ("Can not read RAM: dmb reports busy");
		goto L1600;
	}

	if (dmb_wdcnt<=0) {
		pause ("Can not read RAM: dmb reports word count <=0");
		goto L1600;
	}

	pause("<cr> to process dump");

	// Write RAM read address to TMB
	for (iadr=0; iadr<=dmb_wdcnt-1; ++iadr) {
		adr     = dmb_ram_adr+base_adr;
		wr_data = iadr & 0xFFFF;
		status  = vme_write(adr,wr_data);

		// Read RAM data from TMB
		adr    = dmb_rdata_adr+base_adr;
		status = vme_read(adr,rd_data);			// read lsbs
		dmb_rdata_lsb=rd_data;

		adr    = dmb_wdcnt_adr+base_adr;
		status = vme_read(adr,rd_data);			// read msbs
		dmb_rdata_msb = (rd_data >> 12) & 0x3;	// rdata msbs

		dmb_rdata = dmb_rdata_lsb | (dmb_rdata_msb << 16);

		fprintf(stdout,  "\tAdr=%4i Data=%5.5X\n",iadr,dmb_rdata);
		fprintf(log_file,"\tAdr=%4i Data=%5.5X\n",iadr,dmb_rdata);\

	}	// close iadr

	// Clear RAM address for next event
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	// reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Bang mode
	if (ifunc<0) {
		sleep (150);
		goto L16400;
	}

	goto L1600;

	//------------------------------------------------------------------------------
	//	Fire L1A to ALCT for timing-in clock + read
	//------------------------------------------------------------------------------
L16500:
	fprintf(log_file,"ALCT test started\n");

	// Turn off CCB inputs to zero alct_adb_sync and ext_trig
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;			// Clear previous l1a
	wr_data = wr_data | 0x1;			// Turn off CCB backplane
	status  = vme_write(adr,wr_data);

	// Enable ALCT cable ports
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x000C;			// alct_rxoe=txoe=1
	status  = vme_write(adr,wr_data);

	// Clear last event
	adr     = alctfifo1_adr+base_adr;
	wr_data = 1;						// reset word counter
	status  = vme_write(adr,wr_data);
	wr_data = 0;						// enable word counter
	status  = vme_write(adr,wr_data);

	// Make sure alct fifo went unbusy
	adr    = alct_fifo_adr+base_adr;
	status = vme_read(adr,rd_data);
	alct_raw_busy = (rd_data >> 0) & 0x0001;
	alct_raw_done = (rd_data >> 1) & 0x0001;
	if (alct_raw_busy==1) pause("alct fifo failed to clear");

	// Fire ext_trig to ALCT board
L16510:
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);	// get current state
	wr_data = rd_data & 0xFFF0;			// clear bits[3:0] alct ext trig
	wr_data = wr_data | 0x0004;			// fire alct ext trig
	//	wr_data = wr_data | 0x0008;			// or fire alct ext inject
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0xFFF0;			// clear bits[3:0] alct ext trig
	status  = vme_write(adr,wr_data);

	// Read ALCT trigger words
	adr    = alct_alct0_adr+base_adr;
	status = vme_read(adr,rd_data);		// get current state
	alct0_rd = rd_data;

	adr    = alct_alct1_adr+base_adr;
	status = vme_read(adr,rd_data);		// get current state
	alct1_rd = rd_data;

	if (ifunc>0)
	{
		fprintf(stdout,"\tALCT0=%4.4X\n",alct0_rd);
		fprintf(stdout,"\tALCT1=%4.4X\n",alct1_rd);
		fprintf(log_file,"ALCT0=%4.4X\n",alct0_rd);
		fprintf(log_file,"ALCT1=%4.4X\n",alct1_rd);
		if (alct0_rd==alct0_prev) printf("\tALCT LCT0 unchanged\n");
		if (alct1_rd==alct1_prev) printf("\tALCT LCT1 unchanged\n");
	}
	alct0_prev = alct0_rd;
	alct1_prev = alct1_rd;

	// Fire CCB L1A oneshot to ALCT
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;			// Clear previous l1a
	wr_data = wr_data | 0x1;			// Turn off CCB backplane
	wr_data = wr_data | 0x0040;			// Fire ccb L1A oneshot
	status  = vme_write(adr,wr_data);
	wr_data = wr_data & 0xFFBF;			// Clear previous l1a	
	status  = vme_write(adr,wr_data);
	if (ifunc<0) goto L16510;

	// Check alct fifo status
	for (i=1; i<=100; ++i)				// cheap readout delay 
	{
		adr    = alct_fifo_adr+base_adr;
		status = vme_read(adr,rd_data);
		alct_raw_busy = (rd_data >> 0) & 0x0001;
		alct_raw_done = (rd_data >> 1) & 0x0001;
		if (alct_raw_busy==0) goto L16520;
	}
	pause("alct fifo stuck busy");

L16520:
	printf("\tALCT L1A alct_raw_done waits=%5i\n",i);
	if (alct_raw_done!=1) pause("alct fifo not done");

	// Get alct word count
	adr    = alct_fifo_adr+base_adr;	// alct word count
	status = vme_read(adr,rd_data);
	alct_raw_nwords = (rd_data >> 2) & 0x07FF;
	fprintf(stdout,"\talct_raw_nwords=%5i\n",alct_raw_nwords);
	fprintf(log_file,"alct_raw_nwords=%5i\n",alct_raw_nwords);

	// Read alct fifo data
	for (i=0; i<=max(alct_raw_nwords-1,0); ++i) {
		//	for (i=1; i<=alct_raw_nwords; ++i) {
		adr     = alctfifo1_adr+base_adr;
		wr_data = (i<<1);					// ram read address
		status  = vme_write(adr,wr_data);

		adr     = alctfifo2_adr+base_adr;	// alct raw data lsbs
		status  = vme_read(adr,rd_data);
		alct_raw_data = rd_data;
		dprintf(stdout,"adr=4i alct raw lsbs=%4.4X\n",rd_data);

		adr     = alct_fifo_adr+base_adr;	// alct raw data msbs
		status  = vme_read(adr,rd_data);
		dprintf(stdout,"adr=4i alct raw msbs=%4.4X\n",rd_data);
		rd_data = (rd_data>>13) & 0x0003;
		alct_raw_data = alct_raw_data | (rd_data<<16);

		if (i<mxframe) vf_data[i] = alct_raw_data;
		if (i<=3 || i>=alct_raw_nwords-4)
			fprintf(stdout,  "\t%5i %5.5X\n",i,alct_raw_data);
		fprintf(log_file,"\t%5i %5.5X\n",i,alct_raw_data);
	}

	// calculate CRC for data stream
	dmb_wdcnt = alct_raw_nwords;
	if (dmb_wdcnt<5) {
		printf("Raw hits dump too short for crc calc dmb_wdcnt=%i\n",dmb_wdcnt);
		pause("<cr> to resume");
		goto L1600;
	}

	for (iframe=0; iframe<=dmb_wdcnt-1-4; ++iframe)	// dont include last 4 frames
	{
		din = vf_data[iframe];
		if (iframe==0) crc22a(din,crc,1);				// reset crc
		else           crc22a(din,crc,0);
	}

	// compare our computed CRC to what TMB computed
	tmb_crc_lsb = vf_data[dmb_wdcnt-1-3] & 0x07FF;	// 11 crc bits per frame
	tmb_crc_msb = vf_data[dmb_wdcnt-1-2] & 0x07FF;	// 11 crc bits per frame
	tmb_crc     = tmb_crc_lsb | (tmb_crc_msb<<11);	// full 22 bit crc
	crc_match   = crc==tmb_crc;

	fprintf(stdout,"\tcalc_crc=%6.6X alct_crc=%6.6X match=%c\n",crc,tmb_crc,crc_match,logical(crc_match));
	fprintf(log_file,"calc_crc=%6.6X alct_crc=%6.6X match=%c\n",crc,tmb_crc,crc_match,logical(crc_match));

	if (!crc_match) pause("ALCT crc error, WTF!");
	goto L1600;

	//------------------------------------------------------------------------------
	//	Fire CLCT ext trig linked with ALCT ext trig
	//------------------------------------------------------------------------------
L16600:
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFEF;			// Clear previous trigger
	status  = vme_write(adr,wr_data);
	wr_data = wr_data | 0x0030;			// Fire CLCT ext trig linked with ALCT ext trig
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0xFFEF;			// Clear previous trigger	
	status  = vme_write(adr,wr_data);

	if (ifunc>0) goto L16600;
	goto L1600;

	//------------------------------------------------------------------------------
	//	Inject walking CLCT muon check CLCT0 1/2strip
	//------------------------------------------------------------------------------
L16700:
	first_event = true;
	first_scn   = true;

	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Get csc_id
	adr    = base_adr+seq_id_adr;
	status = vme_read(adr,rd_data);
	csc_id = (rd_data >> 5) & 0x1F;

	// Get current thresholds
	adr    = seq_clct_adr+base_adr;
	status = vme_read(adr,rd_data);
	triad_persist		= (rd_data >>  0) & 0xF;	// 4 bits
	hit_thresh_pretrig	= (rd_data >>  4) & 0x7;	// 3 bits
	dmb_thresh_pretrig	= (rd_data >>  7) & 0x7;	// 3 bits
	hit_thresh_postdrift= (rd_data >> 10) & 0x7;	// 3 bits
	drift_delay			= (rd_data >> 13) & 0x3;	// 2 bits

	adr    = temp0_adr+base_adr;
	status = vme_read(adr,rd_data);
	pid_thresh_pretrig  = (rd_data >> 2) & 0xF;		// 4 bits
	pid_thresh_postdrift= (rd_data >> 6) & 0xF;		// 4 bits

	adr    = layer_trig_adr+base_adr;
	status = vme_read(adr,rd_data);
	lyr_thresh_pretrig = (rd_data >> 1) & 0xF;		// 4 bits

	// Get current adjacent cfeb separation
	adr    = temp0_adr+base_adr;
	status = vme_read(adr,rd_data);
	adjcfeb_dist=(rd_data >> 10) & 0x3F;

	// Get current CLCT separation
	adr    = temp1_adr+base_adr;
	status = vme_read(adr,rd_data);
	clct_sep = (rd_data >> 8) & 0xFF;

	// Get current active_feb_list source
	adr    = seqmod_adr+base_adr;
	status = vme_read(adr,rd_data);
	active_feb_src=(rd_data >> 14) & 0x1;

	// Get current cfeb tbins
	adr    = base_adr+seq_fifo_adr;
	status = vme_read(adr,rd_data);

	fifo_mode		= (rd_data >>  0) & 0x07;	// 3 bits
	fifo_tbins		= (rd_data >>  3) & 0x1F;	// 5 bits
	fifo_pretrig	= (rd_data >>  8) & 0x1F;	// 5 bits
	bcb_read_enable = (rd_data >> 15) & 0x1;	// 1 bit
	bcb_read_enable = 1;	//! set to 1 manually until it becomes the default
	if (fifo_tbins==0) fifo_tbins=32;

	// Get current match parameters
	adr    = base_adr+tmbtim_adr;
	status = vme_read(adr,rd_data);

	alct_delay		= (rd_data >> 0) & 0xF;		// 4 bits
	clct_width		= (rd_data >> 4) & 0xF;		// 4 bits

	// Get current tmb_match mode
	adr    = base_adr+tmb_trig_adr;
	status = vme_read(adr,rd_data);

	tmb_allow_alct	= (rd_data >> 2) & 0x1;		// 1 bit
	tmb_allow_clct	= (rd_data >> 3) & 0x1;		// 1 bit
	tmb_allow_match	= (rd_data >> 4) & 0x1;		// 1 bit

	// Get current tmb_match mode for ME1AB
	adr    = base_adr+non_trig_adr;
	status = vme_read(adr,rd_data);

	tmb_allow_alct_ro   = (rd_data >> 0) & 0x1;	// 1=Allow ALCT-only non-triggering readout
	tmb_allow_clct_ro   = (rd_data >> 1) & 0x1;	// 1=Allow CLCT-only non-triggering readout
	tmb_allow_match_ro  = (rd_data >> 2) & 0x1;	// 1=Allow ALCT*CLCT non-triggering readout
	mpc_me1a_block      = (rd_data >> 3) & 0x1;	// Block ME1A LCTs from MPC, still queue for readout

	// Get current alct injector delay
	adr    = base_adr+alct_inj_adr;
	status = vme_read(adr,rd_data);
	alct_injector_delay=(rd_data >> 5) & 0x1F;	// 5 bits

	// Get current alct bx0 enable
	adr    = base_adr+bx0_delay_adr;
	status = vme_read(adr,rd_data);
	alct_bx0_en=(rd_data >> 8) & 0x1;			// 1 bit

	// Get current rat injector delay and data=address mode
	adr    = base_adr+rpc_inj_adr;
	status = vme_read(adr,rd_data);
	inj_delay_rat  = (rd_data >>  3) & 0xF;		// 4 bits
	rpc_tbins_test = (rd_data >> 15) & 0x1;		// 1bit

	// Get current RPC readout list
	adr    = base_adr+rpc_cfg_adr;
	status = vme_read(adr,rd_data);
	rpc_exists=(rd_data >> 0) & 0x3;			// 2 bits

	// Get current RPC tbins
	adr    = base_adr+rpc_tbins_adr;
	status = vme_read(adr,rd_data);

	fifo_tbins_rpc	= (rd_data >> 0) & 0x1F;	// 5 bits
	fifo_pretrig_rpc= (rd_data >> 5) & 0x1F;	// 5 bits
	rpc_decouple	= (rd_data >>10) & 0x1F;	// 5 bits
	if (fifo_tbins_rpc==0) fifo_tbins_rpc=32;

	// Get scope-in-readout
	adr    = base_adr+scp_ctrl_adr;
	status = vme_read(adr,rd_data);
	scp_auto   =(rd_data >> 3) & 0x1;			// 1 bit
	scp_nowrite=(rd_data >> 4) & 0x1;			// 1 bit
	scp_tbins  =(rd_data >> 5) & 0x7;			// 3 bits

	// Get miniscope-in-readout
	adr    = base_adr+miniscope_adr;
	status = vme_read(adr,rd_data);
	mini_read_enable	=(rd_data >> 0) & 0x1;	// 1 bit
	mini_test			=(rd_data >> 1) & 0x1;	// 1 bit
	mini_tbins_word		=(rd_data >> 2) & 0x1;	// 1 bit
	fifo_tbins_mini		=(rd_data >> 3) & 0x1F;	// 5 bits
	fifo_pretrig_mini	=(rd_data >> 8) & 0x1F;	// 5 bits

	// Get L1A delay
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	l1a_delay = (rd_data >> 8) & 0xFF;

	if (first_event)l1a_delay=119;				// hits 0th l1a window bx, override TMB default

	// Get L1A lookback
	adr    = base_adr+l1a_lookback_adr;
	status = vme_read(adr,rd_data);
	l1a_lookback = (rd_data & 0x07FF);

	// Get sync error forced
	adr    = base_adr+sync_err_ctrl_adr;
	status = vme_read(adr,rd_data);
	sync_err_force = (rd_data>>15) & 0x1;

	// Inquire
	cprr           = true;
	cprr_ignore    = false;
	layer_mode     = false;
	pause_on_fail  = false;
	rpcs_in_rdout  = true;
	rrhd           = true;
	mcl            = mxclcts-1;
	vme_bx0_emu_en = vme_bx0_emu_en_default;
	send_emulator_to_tmb     = true;
	load_clct_injector_image = false;

	for (iclct=0; iclct<mxclcts; ++iclct)
	{
		clct_key_inject[iclct] = -1;
		clct_pid_inject[iclct] = 0xA;
		clct_hit_inject[iclct] = 0;
		clct_blanked[iclct]    = false;
		loop_keys[iclct]       = false;
		loop_pids[iclct]       = false;
		clct_hit_inject_clip[iclct] = 0;
	}

	inquirb("\tCheck Pattern RAM readback [y|n]? cr=%3c", cprr);
	inquire("\tBX0 emulator enable             ? cr=%3i", minv= 0, maxv=  1, radix=10, vme_bx0_emu_en);
	inquire("\tBX0 sync error force            ? cr=%3i", minv= 0, maxv=  1, radix=10, sync_err_force);
	inquire("\tCSC ID                          ? cr=%3i", minv= 0, maxv= 31, radix=10, csc_id);
	inquirb("\tLayer-trigger mode         [y|n]? cr=%3c", layer_mode);

	if (layer_mode)
		inquire("\tLyr_thresh_pretrig              ? cr=%3i", minv= 0, maxv= 7, radix=10, lyr_thresh_pretrig);

	inquire("\tHit_thresh_pretrig              ? cr=%3i", minv= 0, maxv=  7, radix=10, hit_thresh_pretrig);
	inquire("\tPid_thresh_pretrig              ? cr=%3X", minv= 0, maxv= 15, radix=16, pid_thresh_pretrig);
	inquire("\tDmb_thresh_pretrig              ? cr=%3i", minv= 0, maxv=  7, radix=10, dmb_thresh_pretrig);
	inquire("\tHit_thresh_postdrift            ? cr=%3i", minv= 0, maxv=  7, radix=10, hit_thresh_postdrift);
	inquire("\tPid_thresh_postdrift            ? cr=%3X", minv= 0, maxv= 15, radix=16, pid_thresh_postdrift);
	inquire("\tAdjacent cfeb distance          ? cr=%3i", minv= 0, maxv= 63, radix=10, adjcfeb_dist);
	inquire("\tActive_feb_list 0|1=pre|tmb     ? cr=%3i", minv= 0, maxv=  1, radix=10, active_feb_src);
	inquire("\tTriad persistence               ? cr=%3i", minv= 0, maxv= 15, radix=10, triad_persist);
	inquire("\tDrift delay                     ? cr=%3i", minv= 0, maxv=  3, radix=10, drift_delay);
	inquire("\tAlct*clct match window          ? cr=%3i", minv= 0, maxv= 15, radix=10, clct_width);
	inquire("\tAlct Delay                      ? cr=%3i", minv= 0, maxv= 15, radix=10, alct_delay);
	inquire("\tAlct Injector_delay nom=13      ? cr=%3i", minv= 0, maxv= 15, radix=10, alct_injector_delay);
	inquire("\tAlct Enable alct_bx0            ? cr=%3i", minv= 0, maxv=  2, radix=10, alct_bx0_en);
	inquirb("\tClct Send emulator to tmb  [y|n]? cr=%3c", send_emulator_to_tmb);
	inquire("\tClct Mpc_me1a_block             ? cr=%3i", minv= 0, maxv=mcl, radix=10, mpc_me1a_block);
	inquire("\tClct Separation (blanking)      ? cr=%3i", minv= 0, maxv=255, radix=10, clct_sep);
	inquirb("\tClct Load InjectorRAM image[y|n]? cr=%3c", load_clct_injector_image);
	inquire("\tAlct Inject 0,1,2 alcts         ? cr=%3i", minv= 0, maxv=  2, radix=10, nalcts_inject);
	inquire("\tClct Inject 1 or 2 clcts        ? cr=%3i", minv= 0, maxv=mcl, radix=10, nclcts_inject);

	for (iclct=0; iclct<nclcts_inject; ++iclct)
	{
		if (nclcts_inject>=mxclcts) stop("nclcts_inject>=mxclct");
		if (iclct==0) {
			clct_hit_inject[iclct] = 6;
			inquir2("\tClct%1i Key half-strip0-159 -1=all? cr=%3i", minv=-1, maxv=159, radix=10, iclct,clct_key_inject[iclct]);
			inquir2("\tClct%1i Pattern ID   2-A    -1=all? cr=%3X", minv=-1, maxv=0xA, radix=16, iclct,clct_pid_inject[iclct]);
			inquir2("\tClct%1i Pattern Hits 0-6          ? cr=%3i", minv= 0, maxv=6,   radix=10, iclct,clct_hit_inject[iclct]);
		}
		if (iclct==1) {
			clct_hit_inject[iclct] = 5;
			inquir2("\tClct%1i Key half-strip159-0 -1=all? cr=%3i", minv=-1, maxv=159, radix=10, iclct,clct_key_inject[iclct]);
			inquir2("\tClct%1i Pattern ID   2-A    -1=all? cr=%3X", minv=-1, maxv=0xA, radix=16, iclct,clct_pid_inject[iclct]);
			inquir2("\tClct%1i Pattern Hits 0-6          ? cr=%3i", minv= 0, maxv=6,   radix=10, iclct,clct_hit_inject[iclct]);
		}
		if (iclct>=2) {
			clct_hit_inject[iclct] = 4;
			inquir2("\tClct%1i Key half-strip0-159       ? cr=%3i", minv=-1, maxv=159, radix=10, iclct,clct_key_inject[iclct]);
			inquir2("\tClct%1i Pattern ID   2-A          ? cr=%3X", minv=-1, maxv=0xA, radix=16, iclct,clct_pid_inject[iclct]);
			inquir2("\tClct%1i Pattern Hits 0-6          ? cr=%3i", minv= 0, maxv=6,   radix=10, iclct,clct_hit_inject[iclct]);
		}
	}	// close for iclct

	printf ("\tClct Triad 1st tbin ly5:ly0     ? cr=000000 ");
	gets(line);
	n=strlen(line);
	sscanf(line,"%1i,%1i,%1i,%1i,%1i,%1i",&i,&i,&i,&i,&i,&i);
	if (n!=0) {
		for (i=0; i<=5; ++i) {
			triad_1st_tbin[i]=0;
		}}

	inquire("\tAllow TMB alct*clct match       ? cr=%3i", minv= 0, maxv=  1, radix=10, tmb_allow_match);
	inquire("\tAllow TMB alct-only             ? cr=%3i", minv= 0, maxv=  1, radix=10, tmb_allow_alct);
	inquire("\tAllow TMB clct-only             ? cr=%3i", minv= 0, maxv=  1, radix=10, tmb_allow_clct);
	inquire("\tAllow TMB alct*clct match_ro    ? cr=%3i", minv= 0, maxv=  1, radix=10, tmb_allow_match_ro);
	inquire("\tAllow TMB alct-only_ro          ? cr=%3i", minv= 0, maxv=  1, radix=10, tmb_allow_alct_ro);
	inquire("\tAllow TMB clct-only_ro          ? cr=%3i", minv= 0, maxv=  1, radix=10, tmb_allow_clct_ro);
	inquirb("\tCFEB Read out raw hits dump[y|n]? cr=%3c", rrhd);
	inquire("\tCFEB Tbins                      ? cr=%3i", minv= 0, maxv= 31, radix=10, fifo_tbins);
	inquire("\tCFEB Tbins before pretrig       ? cr=%3i", minv= 0, maxv= 31, radix=10, fifo_pretrig);
	inquire("\tCFEB FIFO mode                  ? cr=%3i", minv= 0, maxv=  7, radix=10, fifo_mode);
	inquire("\tCFEB Blockedbits readout enable ? cr=%3i", minv= 0, maxv=  1, radix=10, bcb_read_enable);
	inquire("\tL1A  Delay                      ? cr=%3i", minv= 0, maxv=256, radix=10, l1a_delay);
	inquire("\tL1A  Lookback                   ? cr=%3i", minv= 0, maxv=256, radix=10, l1a_lookback);

	printf ("\tRPC Injector rat,tmb,sync,none  ? (r/t/s/n)");
	gets(line);
	n=strlen(line);
	sscanf(line,"%c",&i);
	rat_injector_sync   = false;
	rat_injector_enable = true;
	rat_sync_mode=0;
	if ((n!=0) && (i=='r' || i=='R')) rat_injector_sync   = true;
	if ((n!=0) && (i=='n' || i=='N')) rat_injector_enable = false;
	if ((n!=0) && (i=='s' || i=='S')) rat_sync_mode       = 1;

	inquire("\tRAT injector delay              ? cr=%3i", minv= 0, maxv=256, radix=10, inj_delay_rat);
	inquire("\tRPC data=address mode           ? cr=%3i", minv= 0, maxv=  1, radix=10, rpc_tbins_test);
	inquirb("\tRPCs in readout            [y|n]? cr=%3c", rpcs_in_rdout);

	printf ("\tRPC list to readout             ? cr= %1i%1i",(rpc_exists>>1)&0x1,rpc_exists&0x1);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i,%i",&i,&j);
	if (n!=0) rpc_exists= (j<<1) | i; 

	inquire("\tRPC TBins Decouple              ? cr=%3i", minv= 0, maxv=  1, radix=10, rpc_decouple);
	inquire("\tRPC Tbins                       ? cr=%3i", minv= 0, maxv= 31, radix=10, fifo_tbins_rpc);
	inquire("\tRPC Tbins before pretrig        ? cr=%3i", minv= 0, maxv= 31, radix=10, fifo_pretrig_rpc);
	inquire("\tRPC Scope in readout            ? cr=%3i", minv= 0, maxv=  1, radix=10, scp_auto);
	inquire("\tScope tbins/64                  ? cr=%3i", minv= 0, maxv= 31, radix=10, scp_tbins);
	inquire("\tScope nowrite                   ? cr=%3i", minv= 0, maxv=  1, radix=10, scp_nowrite);	// nowrite=1 uses tmb scope ram initial test pattern
	inquire("\tMiniscope in readout            ? cr=%3i", minv= 0, maxv= 31, radix=10, mini_read_enable);

	if (mini_read_enable==1) {
		inquire("\tMiniscope test mode             ? cr=%3i", minv= 0, maxv= 31, radix=10, mini_test);
		inquire("\tMiniscope 1st word=tbins        ? cr=%3i", minv= 0, maxv= 31, radix=10, mini_tbins_word);
		inquire("\tMiniscope tbins                 ? cr=%3i", minv= 0, maxv= 31, radix=10, fifo_tbins_mini);
		inquire("\tMiniscope tbins pretrig         ? cr=%3i", minv= 0, maxv= 31, radix=10, fifo_pretrig_mini);
	}
	inquirb("\tPause on fail              [y|n]? cr=%3c", pause_on_fail);

	// Turn off CFEB cable inputs
L16705:
	adr       = cfeb_inj_adr+base_adr;
	mask_all  = 0x00;	// 5'b00000 disables cfeb inputs
	febsel    = 0x00;	// Injector RAM select
	mask_cfeb = 0x00;	// Injector RAMs to fire
	inj_trig  = 0;		// Injector fire bit       
	wr_data   = (mask_all  << 0)  |
		(febsel    << 5)  |
		(mask_cfeb << 10) |
		(inj_trig  << 15);
	status    = vme_write(adr,wr_data);

	// Turn off GTX optical receiver inputs
	adr     = adr_virtex6_gtx_rx_all+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFE;		// Turn of enable_all bt
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);

	alct_injector_delay=13;

	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0005;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;					// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;					// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Reset bad bits
	adr     = cfeb_badbits_ctrl_adr+base_adr;	// CFEB  Bad Bit Control/Status
	status  = vme_read(adr,rd_data);			// read current
	rd_data = rd_data & 0xFFE0;					// clean out old reset bits
	wr_data = rd_data | 0x001F;					// assert reset[4:0]
	status  = vme_write(adr,wr_data);			// write reset
	wr_data = rd_data;							// retrieve original register contents
	status  = vme_write(adr,wr_data);			// restore register with resets off

	// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (l1a_delay << 8);
	status  = vme_write(adr,wr_data);

	// Set csc_id
	adr    = base_adr+seq_id_adr;
	status = vme_read(adr,rd_data);
	wr_data = rd_data & ~(0x1F << 5);			// clear old csc_id
	wr_data = wr_data | (csc_id << 5);			// new csc_id
	status  = vme_write(adr,wr_data);

	// Set L1A lookback
	adr     = base_adr+l1a_lookback_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & ~0x07FF;
	wr_data = wr_data | (l1a_lookback << 0);
	status  = vme_write(adr,wr_data);

	// Turn off CCB backplane inputs, turn on L1A emulator, do this after turning off cfeb and alct cable inputs
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x0000;
	wr_data = wr_data | 0x0001;	// ccb_ignore_rx
	wr_data = wr_data | 0x0004;	// ccb_int_l1a_en
	wr_data = wr_data | 0x0008;	// ccb_status_oe_vme
	wr_data = wr_data | 0x0010;	// alct_status_en
	wr_data = wr_data | 0x0020;	// clct_status_en
	wr_data = wr_data | (vme_bx0_emu_en << 15);	// bx0 emualtor
	status  = vme_write(adr,wr_data);

	vme_bx0_emu_en_default = vme_bx0_emu_en;	// update default so u dont have to keep entering

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | (alct_delay << 0);
	wr_data = wr_data | (clct_width << 4);
	status  = vme_write(adr,wr_data);

	// Set tmb_match mode
	adr     = base_adr+tmb_trig_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE7;		// clear bits 4,3
	wr_data = wr_data | (tmb_allow_alct  << 2);
	wr_data = wr_data | (tmb_allow_clct  << 3);
	wr_data = wr_data | (tmb_allow_match << 4);
	status  = vme_write(adr,wr_data);

	// Set tmb_match mode for ME1AB
	adr     = base_adr+non_trig_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | (tmb_allow_alct_ro  << 0);	// 1=Allow ALCT-only non-triggering readout
	wr_data = wr_data | (tmb_allow_clct_ro  << 1);	// 1=Allow CLCT-only non-triggering readout
	wr_data = wr_data | (tmb_allow_match_ro << 2);	// 1=Allow ALCT*CLCT non-triggering readout
	wr_data = wr_data | (mpc_me1a_block     << 3);	// Block ME1A LCTs from MPC, still queue for readout
	status  = vme_write(adr,wr_data);

	// Set alct bx0 enable
	adr     = base_adr+bx0_delay_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & ~(1 << 8);
	wr_data = wr_data | (alct_bx0_en << 8);
	status  = vme_write(adr,wr_data);

	// Turn on layer trigger mode if its selected
	layer_trig_en=0;
	if (layer_mode) layer_trig_en=1;
	adr     = layer_trig_adr+base_adr;
	wr_data = layer_trig_en | (lyr_thresh_pretrig << 1);
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer, set l1a window width
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x00FF;
	wr_data = wr_data | 0x0300;			//  l1a window width
	status  = vme_write(adr,wr_data);

	// Set fifo tbins
	adr     = base_adr+seq_fifo_adr;
	status  = vme_read(adr,rd_data);	// get current
	wr_data = rd_data & 0xF000;			// clear lower bits

	wr_data=wr_data
		| ((fifo_mode       & 0x7 ) <<  0)	// [2:0]
		| ((fifo_tbins      & 0x1F) <<  3)	// [7:3]
		| ((fifo_pretrig    & 0x1F) <<  8)	// [12:8]
		| ((bcb_read_enable & 0x1 ) << 15);	// [15]

	status = vme_write(adr,wr_data);

	// Set pid_thresh_pretrig, pid_thresh_postdrift
	adr    = temp0_adr+base_adr;
	status = vme_read(adr,rd_data);

	wr_data=rd_data & 0xFC03;
	wr_data=wr_data | (pid_thresh_pretrig   << 2);	// 4 bits
	wr_data=wr_data | (pid_thresh_postdrift << 6);	// 4 bits

	status = vme_write(adr,wr_data);

	// Set adjcfeb_dist
	adr     = temp0_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;			// adjcfeb_dist[5:0] is in [15:10]
	wr_data = wr_data | (adjcfeb_dist << 10);
	status  = vme_write(adr,wr_data);

	// Set CLCT separation
	adr     = temp1_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x00FF;
	wr_data = wr_data | (clct_sep << 8);
	status  = vme_write(adr,wr_data);

	// Set active_feb_list source
	adr     = seqmod_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & ~(1 << 14);
	wr_data = wr_data | (active_feb_src << 14);
	status  = vme_write(adr,wr_data);

	// Set RAT out of sync mode
	adr     = vme_ratctrl_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFE;
	wr_data = wr_data | rat_sync_mode;
	status  = vme_write(adr,wr_data);

	// Set miniscope
	adr     = base_adr+miniscope_adr;
	wr_data = 0;
	wr_data = wr_data | (mini_read_enable  << 0);	// 1 bit
	wr_data = wr_data | (mini_test         << 1);	// 1 bit
	wr_data = wr_data | (mini_tbins_word   << 2);	// 1 bit
	wr_data = wr_data | (fifo_tbins_mini   << 3);	// 5 bits
	wr_data = wr_data | (fifo_pretrig_mini << 8);	// 5 bits
	status  = vme_write(adr,wr_data);

	// Include RPCs in readout
	adr     = rpc_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFEC;						//  Turn off bits4,1,0
	wr_data = wr_data | (rpc_exists & 0x3);			//  Turn on existing RPCs
	if (rpcs_in_rdout) wr_data=wr_data | (1 << 4);	//  Turn on bit 4 to enable
	status  = vme_write(adr,wr_data);

	// Set RPC tbins
	adr     = base_adr+rpc_tbins_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xF800;						// Clear out old values
	wr_data = wr_data | (fifo_tbins_rpc		<<  0);	// 5 bits
	wr_data = wr_data | (fifo_pretrig_rpc	<<  5);	// 5 bits
	wr_data = wr_data | (rpc_decouple		<< 10);	// 5 bits
	status  = vme_write(adr,wr_data);

	// Enable RPC injector
	adr     = rpc_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF80;					// Clear out old bits
	wr_data = wr_data | 0x0001;					// rpc_mask_all 1=enable inputs from RPC
	if (rat_injector_enable) {
		if (rat_injector_sync  ) {
			wr_data = wr_data | 0x0002; }				// 1=enable RAT board injector
		else {
			wr_data = wr_data & 0xFFFE;					// Turn off bit[0], masks RPC signals from RAT
			wr_data = wr_data | 0x0004;					// 1=enable TMBs RPC RAM internal injector
			printf("\tUsing TMBs RPC Injector RAM, RAT disconnected.\n");
		}}

	//	rat_injector_delay=7;
	wr_data = wr_data | (inj_delay_rat  <<  3);	// delay CLCT injector to wait for RAT
	wr_data = wr_data | (rpc_tbins_test << 15);	// Data=daddress mode
	status  = vme_write(adr,wr_data);

	// Load RPC injector RAM
	if (rat_injector_enable && !rat_injector_sync) {

		adr     = rpc_inj_adr+base_adr;				// Get current injector control
		status  = vme_read(adr,rd_data);
		wr_data = rd_data & 0x807F;					// Clear injector data, set inj_sel=0 to point to pad rams
		status  = vme_write(adr,wr_data);

		for (irpc=0; irpc<=1;   ++irpc) {			// Create rpc pad+bxn image
			for (ibxn=0; ibxn<=255; ++ibxn) {

				if (ibxn <= 255) {
					if (irpc==0) rpc_pad=ibxn | (0xAB << 8);	// rpc0 pads AB00-ABFF
					if (irpc==1) rpc_pad=ibxn | (0xCD << 8);	// rpc1 pads CD00-CDFF
					rpc_inj_bxn=7-ibxn;
					rpc_inj_image[ibxn][irpc]=rpc_pad | (rpc_inj_bxn << 16);}
				else {
					rpc_inj_image[ibxn][irpc]=0;				// zero the rest of the ram
				}	// close if ibxn
			}	// close do ibxn
		}	// close do irpc

		for (irpc=0; irpc<=1;   ++ irpc) {
			for (ibxn=0; ibxn<=255; ++ ibxn) {
				dprintf(stdout,"rpc_inj_image writing%2i%2i%6.5X\n",ibxn,irpc,rpc_inj_image[ibxn][irpc]);
				adr     = rpc_inj_wdata_adr+base_adr;		// pad data to write to ram
				wr_data = rpc_inj_image[ibxn][irpc] & 0x0000FFFF;
				status  = vme_write(adr,wr_data);

				adr     = rpc_inj_adr+base_adr;				// get current injector control
				status  = vme_read(adr,rd_data);
				wr_data = rd_data & 0x807F;					// clear bxn data
				rpc_inj_bxn=(rpc_inj_image[ibxn][irpc] >> 16) & 0x7;
				wr_data = wr_data | (rpc_inj_bxn << 8);		// new bxn
				wr_data = wr_data | (1           << 7);		// set inj_sel=1
				status  = vme_write(adr,wr_data);

				adr     = rpc_inj_adr_adr+base_adr;			// ram write strobes
				rpc_inj_wen   = (1 << irpc);				// select this ram
				rpc_inj_ren   = 0;
				rpc_inj_rwadr = ibxn;						// at this address
				wr_data = rpc_inj_wen | (rpc_inj_ren << 4) | (rpc_inj_rwadr << 8) | (rpc_tbins_test << 15);		// set wen=1
				status  = vme_write(adr,wr_data);
				rpc_inj_wen=0;
				wr_data = rpc_inj_wen | (rpc_inj_ren << 4) | (rpc_inj_rwadr << 8) | (rpc_tbins_test << 15);		// set wen=0
				status  = vme_write(adr,wr_data);
			}	// close for ibxn
		}	// close for irpc
	}	// if (rat_injector_enable

	// Verify RPC injector RAM
	if (rat_injector_enable & !rat_injector_sync) {

		for (irpc=0; irpc<=1; ++irpc) {
			for (ibxn=0; ibxn<=7; ++ibxn) {
				adr = rpc_inj_adr_adr+base_adr;			// ram read strobes
				rpc_inj_wen   = 0;						// select this ram
				rpc_inj_ren   = (1 << irpc);
				rpc_inj_rwadr = ibxn;					// at this address
				wr_data = rpc_inj_wen | (rpc_inj_ren << 4) | (rpc_inj_rwadr << 8) | (rpc_tbins_test << 15);		// set ren=1
				status  = vme_write(adr,wr_data);

				adr    = rpc_inj_rdata_adr+base_adr;	// read pad data
				status = vme_read(adr,rd_data);
				rpc_inj_data=rd_data;

				adr    = rpc_inj_adr+base_adr;			// read bxn data
				status = vme_read(adr,rd_data);
				rpc_inj_bxn = (rd_data >> 11) & 0x7;
				rpc_inj_data = rpc_inj_data | (rpc_inj_bxn << 16);

				adr = rpc_inj_adr_adr+base_adr;			// ram read strobes
				rpc_inj_ren=0;
				wr_data = rpc_inj_wen | (rpc_inj_ren << 4) | (rpc_inj_rwadr << 8) | (rpc_tbins_test << 15);		// set ren=0
				status  = vme_write(adr,wr_data);

				fprintf(log_file,"rpc_inj_data reading%2i%2i%6.5X\n",ibxn,irpc,rpc_inj_data);

				if (rpc_inj_data != rpc_inj_image[ibxn][irpc]) {
					fprintf(log_file,"RPC injector RAM error at adr=%2.2i expect=%5.5X read=%5.5X\n",rpc_inj_rwadr,rpc_inj_image[ibxn][irpc],rpc_inj_data);
					fprintf(stdout,  "RPC injector RAM error at adr=%2.2i expect=%5.5X read=%5.5X\n",rpc_inj_rwadr,rpc_inj_image[ibxn][irpc],rpc_inj_data);
				}

			}	// close for ibxn
		}	// close for irpc
	}	// if (rat_injector_enable

	// Select clct pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0001;
	//	if (!layer_mode) wr_data=wr_data |0x0001;	//  TURN OFF PATTERN TRIGGER IN LAYER MODE TEMPORARY!!!
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	adr     = base_adr+ccb_cmd_adr;

	ttc_cmd = 3;			// ttc_resync
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 6;			// start_trigger
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data =0x0001;
	status  = vme_write(adr,wr_data);

	// Force a sync error if requested
	adr     = base_adr+sync_err_ctrl_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & ~(1<<15);		// clear old
	wr_data = rd_data |  (sync_err_force<<15);
	status  = vme_write(adr,wr_data);	// set new

	// Clear sync error if bx0 emulator is turned on
	if (vme_bx0_emu_en==1)
	{
		adr     = base_adr+sync_err_ctrl_adr;
		status  = vme_read(adr,rd_data);
		wr_data = rd_data |  0x1;	// assert clear
		status  = vme_write(adr,wr_data);
		wr_data = rd_data & ~0x1;	// deassert
		status  = vme_write(adr,wr_data);

		status  = vme_read(adr,rd_data);
		sync_err             = (rd_data >>  9) & 0x1; 
		clct_bx0_sync_err    = (rd_data >> 10) & 0x1; 
		alct_ecc_rx_err_ff   = (rd_data >> 11) & 0x1; 
		alct_ecc_tx_err_ff   = (rd_data >> 12) & 0x1; 
		bx0_match_err_ff     = (rd_data >> 13) & 0x1; 
		sync_err_force       = (rd_data >> 15) & 0x1;

		if (sync_err==0 && sync_err_force==1) printf("ERR: TMB failed to force sync_err, sync_err=%1i sync_err_force=%1i\n",sync_err,sync_err_force);
		if (sync_err==1 && vme_bx0_emu_en==1) printf("ERR: TMB failed to clear sync_err, sync_err=%1i vme_bx0_emu_en=%1i\n",sync_err,vme_bx0_emu_en);
	}

	// Loop key and pid modes
	for (iclct=0; iclct<nclcts_inject; ++iclct)
	{
		if (clct_key_inject[0]==-1) loop_keys[iclct]=true;
		else                        loop_keys[iclct]=false;

		if (clct_pid_inject[0]==-1) loop_pids[iclct]=true;
		else                        loop_pids[iclct]=false;
	}

	// CLCT: Key hs range to span in event loop
	iclct=0;

	if (loop_keys[iclct])				// clct0 hits all keys 0 to 159
	{
		ikey_min = 0;
		ikey_max = 159;
	}	
	else								// hit only 1 key
	{
		ikey_min = clct_key_inject[iclct];
		ikey_max = clct_key_inject[iclct];
	}

	// CLCT: Pattern ID range to span in event loop
	if (loop_pids[iclct])				// do all pattern IDs
	{
		ipid_min = 2;
		ipid_max = 10;
	}				
	else								// just do 1 pid
	{
		ipid_min = clct_pid_inject[iclct];
		ipid_max = clct_pid_inject[iclct];
	}

	if (loop_pids[iclct]) {				// do all pattern IDs
		if (hit_thresh_pretrig   > 3) printf("hit_thresh_pretrig   too high to trigger edge keys\n");
		if (hit_thresh_postdrift > 3) printf("hit_thresh_postdrift too high to trigger edge keys\n");
	}

	// Loop over trigger events: clct0 keys and clct0 pids
	for (ikeylp=ikey_min; ikeylp<=ikey_max; ++ikeylp)
	{
		for (ipidlp=ipid_min; ipidlp<=ipid_max; ++ipidlp)
		{

			// Clear clct 1/2-strip image for this event
			for (layer=0; layer<=5; ++layer) {
				for (key=0;   key<=159; ++key  ) {
					ihs[layer][key]=0;
				}}

			// Loop over clcts to inject for this event
			ipid  = 0;
			ikey  = 0;
			icfeb = 0;

			for (iclct=0; iclct<nclcts_inject; ++iclct)
			{
				// Construct current key and pid for this clct
				ikey = clct_key_inject[iclct];
				ipid = clct_pid_inject[iclct];
				clct_blanked[iclct] = false;

				if (iclct==0 && loop_keys[iclct]) {
					ipid = ipidlp;
					ikey = ikeylp;
				}

				if (iclct==1) {
					if (loop_keys[1]) ikey = 159-ikeylp;		// clct1 uses clct0 159-key if clct0 is looping over keys
					if (loop_pids[1]) ipid = flip_pid(ipidlp);	// clct1 uses clct0 flipped pid if clct0 is looping over pids
				}

				clct_key_inject[iclct] = ikey;
				clct_pid_inject[iclct] = ipid;

				fprintf(log_file,"dbg: clct_key_inject[%1i]=%3i\n",iclct,clct_key_inject[iclct]);
				fprintf(log_file,"dbg: clct_pid_inject[%1i]=%3X\n",iclct,clct_pid_inject[iclct]);

				if (iclct==1 && loop_keys[1]) {
					ikey_sep = abs(clct_key_inject[0]-clct_key_inject[1]);
					if (ikey_sep<=1) {
						clct_blanked[1]    = true;
					}
					fprintf(log_file,"dbg: key=%3.3i clct1 key separation ikey_sep=%3i clct_blanked[1]=%c\n",ikeylp,ikey_sep,logical(clct_blanked[1]));
				}
				if (clct_blanked[iclct]) continue;	// skip this clct if its blanked 

				// Insert pattern image for this clcts key and pid + stagger hits 
				ihitp = 0;
				icfeb = ikey/32;
				clct_hit_expect[iclct] = 0;
				clct_key_expect[iclct] = ikey;
				clct_pid_expect[iclct] = ipid;

				for (layer=0; layer<=5;  ++layer) {
					for (icell=0; icell<=10; ++icell) {

						key=ikey+icell-5;								// ikey -5,-4,-3,-2,-1,0,+1,+2,+3,+4,+5 cell hits
						if (stagger_hs_csc==1 && (layer%2)!=0  ) key++; // Type A stagger odd layers if key is on ly2
						if (stagger_hs_csc==1 && reverse_hs_csc) key--;	// Tybe B shift 1hs beco csc is facing backwards

						ids     = key/4;								// Distrip for this key
						ihs_min = ids*4;								// First hs on this ds
						ihs_max = ihs_min+3;							// Last  hs on this ds
						ihs_hit = 0;									// Number of hs hits on this ds must be 0 or 1, comparators can only encode 1 of 4 hs

						for (ihs_ds=ihs_min; ihs_ds<=ihs_max; ++ihs_ds){// Loop over the 4 hs on this ds
							if (ihs_ds>=0 && ihs_ds<=159) {					// Bugfix 12/13/2010
								if (ihs[layer][ihs_ds]==1) ihs_hit++;			// Hs that were already set on this ds
							}}
						ihit  = pattern_image[ipid][layer][icell];		// Extract pattern hits

						if (ihit==1   ) ihitp++;						// Count primary pattern hits
						if (ihit==1 && ihs_hit>=1) printf("ERRx: Hs collision at ikey=%3i ly=%1i icell=%2i\n",ikey,layer,icell);	
						if (ihs_hit>=1) ihit = 0;						// Do not hit same distrip twice, comparators can only encode 1 of 4 hs
						if (ihitp>clct_hit_inject[iclct]) ihit = 0;		// Limit clct[n] hs hits to user-set

						if (key>=0 && key<=159 && ihit==1) {			// Set hs hit
							ihs[layer][key]=1; 
							clct_hit_expect[iclct]++;
						}

					}	// close icell
				}	// close layer

				fprintf(log_file,"CLCT%1i: Key=%3i Pattern=%2X primary hits=%2i expected hits=%2i\n",iclct,ikey,ipid,ihitp,clct_hit_expect[iclct]);

				if (ihitp!=6) {
					printf("CLCT%1i: Key=%3i Pattern=%2X primary hits=%2i expected hits=%2i\n",iclct,ikey,ipid,ihitp,clct_hit_expect[iclct]);
					pause("clct error in primary hit count, expected 6 hits.");
				}

				// Close loops for this event
			}	// close for iclct

			// Display 1/2-strip image
			img_file=log_file;
			//	img_file=sum_file;

			fprintf(img_file,"1/2-Strip Image:\n");
			for (layer=0; layer<=5; ++layer) {
				nstag=((layer+1)%2)*stagger_hs_csc;				// stagger even layers
				fprintf(img_file,"%1i: ",layer);				// layer number
				for (i=1; i<=nstag; ++i) fprintf(img_file," ");	// insert 1 or 2 spaces for staggering
				fprintf(img_file,"|");
				for (icfebg=0; icfebg<=4; ++icfebg) {			// cfeb groups horizontally
					for (i=0; i<=31; ++i) fprintf(img_file,"%1i",ihs[layer][i+32*icfebg]);
					fprintf(img_file,"|");}
				fprintf(img_file,"\n");
			}

			// Clear triad image
			for (layer=0;    layer    < mxly;    ++layer   ) {
				for (idistrip=0; idistrip < mxdsabs; ++idistrip) {
					for (itbin=0;    itbin    < mxtbins;  ++itbin  ) {
						itriad[itbin][idistrip][layer]=0;
					}}}

			// Convert key 1/2-strips to triads
			itbin0=0;	// first tbin, default is 0

			for (layer=0; layer<=5; ++layer) {
				itbin0=triad_1st_tbin[layer];
				for (key=0; key<=159; ++key) {

					idistrip=key/4;
					ihstrip =key%4;

					if (ihs[layer][key]==1) {
						itriad[itbin0+0][idistrip][layer] = 1;
						itriad[itbin0+1][idistrip][layer] = ihstrip/2 & 0x0001;
						itriad[itbin0+2][idistrip][layer] = ihstrip   & 0x0001;
					}	// close if ihs
				}	// close for key
			}	// close for layer

			// Load CLCT injector pattern RAM triads from an image file, format="0  0 |00000000|00000000|00000000|00000000|00000000|"
			if (load_clct_injector_image)
			{
				ram_file_name = "clct_injector_ram_image.txt";			// Open RAM imagae file
				fprintf(log_file,"\nOpening CLCT injector RAM image file %s\n",ram_file_name.c_str());
				fprintf(stdout,"\n\tOpening CLCT injector RAM image file %s\n",ram_file_name.c_str());

				ram_file      = fopen(ram_file_name.c_str(),"r");
				if (ram_file==NULL) {pause("Unable to open CLCT injector RAM image file"); return;}

				fgets(line,81,ram_file);								// Skip comment lines
				fgets(line,81,ram_file);
				fgets(line,81,ram_file);

				for (itbin=0; itbin<mxtbins; ++itbin)
				{
					if  (feof(ram_file)) break;								// Hit end of file
					fgets(line,81,ram_file);								// Get a new line
					sscanf(line,     "%1i%3i |%8X|%8X|%8X|%8X|%8X|",            &layer,&itbin,&dscfeb[0],&dscfeb[1],&dscfeb[2],&dscfeb[3],&dscfeb[4]);
					fprintf(log_file,"%1i%3i |%8.8X|%8.8X|%8.8X|%8.8X|%8.8X|\n", layer, itbin, dscfeb[0], dscfeb[1], dscfeb[2], dscfeb[3], dscfeb[4]);

					if (layer<0 || layer>5       ) stop("layer out of range in clct injector image file");
					if (itbin<0 || itbin>=mxtbins) stop("itbin out of range in clct injector image file");

					for (icfeblp =0; icfeblp <=4;   ++icfeblp) {
						for (idistrip=0; idistrip<=39; ++idistrip) {
							icfeblp = idistrip/8;
							ids     = idistrip%8;
							ibit    = (dscfeb[icfeblp] >> 4*(7-ids)) & 0x1;
							itriad[itbin][idistrip][layer] = ibit;
						}}

				}	// close for itbin
				fclose(ram_file);
			}	// close if load

			// Check for multiple hstrip hits that could not be conveted to triads, cfeb hardware can only fire one hs per ds
			for (layer=0; layer<=5; ++layer) {
				for (key=0; key<=159; key=key+4) {			// distrip steps
					nhits=0;
					for (i=0; i<=3; ++i) {						// count hs bits hit
						nhits=nhits+ihs[layer][key+i];
					}
					if (nhits>1) {
						printf("Multi triad hits=%1i at ly=%1i key=%1i unable to encode all hs hits\n",nhits,layer,key);
						pause (" "); }
				}
			}

			// Display Triads
			fprintf(log_file,"\nbegin triad for key%3.3i",ikeylp); 
			for(i=0;i<nclcts_inject;++i) fprintf(log_file,"  clct%1i: key%3.3i hit%1i pid%1X",i,clct_key_expect[i],clct_hit_expect[i],clct_pid_expect[i]); 
			fprintf(log_file,"\n");

			for (layer=0; layer<=5; ++layer) {
				for (itbin=0; itbin<=2; ++itbin) {

					for (icfebg  =0; icfebg  <=4; ++icfebg  ) {
						for (idistrip=0; idistrip<=7; ++idistrip) {
							fprintf(log_file,"%1i",itriad[itbin][idistrip+8*icfebg][layer]); }
						fprintf(log_file," ");}
					fprintf(log_file,"\n");
				}
				fprintf(log_file,"\n");
			}

			// Pack triads into pattern RAM
			wr_data=0;

			for (layer=0; layer<=5; layer=layer+2) {
				iram=layer/2;
				for (itbin=0; itbin<=31; ++itbin) {
					for (idistrip=0; idistrip<=39; ++idistrip) {
						icfeblp=idistrip/8;
						idslocal=idistrip%8;
						if (idslocal==0) wr_data=0; 		// clear for each cfeb

						ibit=itriad[itbin][idistrip][layer];
						wr_data=wr_data | (ibit << idslocal);

						ibit=itriad[itbin][idistrip][layer+1];
						wr_data=wr_data | (ibit << (idslocal+8));

						pat_ram[itbin][iram][icfeblp]=wr_data;
						dprintf(log_file,"pat_ram tbin=%2i ram=%1i wr_data=%4.4X\n",itbin,iram,wr_data);
					}
				}
			}

			// Write muon data to Injector
			adr     = l1a_lookback_adr+base_adr;
			status  = vme_read(adr,rd_data);				// Read lookback register
			l1a_lookback_data = rd_data & ~(0x3 << 11);		// Clear out injector RAM data [17:16] in [12:11]

			for (icfeblp=0; icfeblp<=4;  ++icfeblp) {
				for (iram   =0; iram   <=2;  ++iram   ) {
					for (itbin  =0; itbin  <=31; ++itbin  ) {

						wr_data_mem = pat_ram[itbin][iram][icfeblp];	// RAM data to write at this cfeb and tbin
						wr_data_lsb = (wr_data_mem >>  0) & 0x0FFFF;	// RAM write data [15:0]
						wr_data_msb = (wr_data_mem >> 16) & 0x3;		// RAM write data [17:16];
						wadr        = itbin;

						adr    = cfeb_inj_adr+base_adr;					// Select injector RAM
						status = vme_read(adr,rd_data);					// Get current data

						wr_data = rd_data & 0xFC1F;						// Zero   CFEB select
						febsel  = (1 << icfeblp);						// Select CFEB
						wr_data = wr_data | (febsel << 5) | 0x7C00;		// Set febsel, enable injectors
						status  = vme_write(adr,wr_data);				// Select CFEB

						adr     = cfeb_inj_adr_adr+base_adr;
						ren     = 0;
						wen     = 0;
						wr_data = wen | (ren << 3) | (wadr << 6);
						status  = vme_write(adr,wr_data);				// Set RAM Address + No write

						adr     = cfeb_inj_wdata_adr+base_adr;
						wr_data = wr_data_lsb;
						status  = vme_write(adr,wr_data);				// Store RAM Data lsb [15:0]

						adr     = l1a_lookback_adr+base_adr;
						wr_data = l1a_lookback_data | (wr_data_msb << 11);
						status  = vme_write(adr,wr_data);				// Store RAM Data msb [17:16]

						adr     = cfeb_inj_adr_adr+base_adr;
						wen     = (1 << iram);
						wr_data = wen | (ren << 3) | (wadr << 6);
						status  = vme_write(adr,wr_data);				// Set RAM Address + Assert write

						wen     = 0;
						wr_data = wen | (ren << 3) | (wadr << 6);
						status  = vme_write(adr,wr_data);				// Set RAM Address + No write

						ren     = (1 << iram);
						wr_data = wen | (ren << 3) | (wadr << 6);
						status  = vme_write(adr,wr_data);				// Set RAM Address + Read enable

						adr     = cfeb_inj_rdata_adr+base_adr;
						status  = vme_read(adr,rd_data);				// Read RAM data lsbs [15:0]
						rd_data_lsb = rd_data;

						adr     = l1a_lookback_adr+base_adr;
						status  = vme_read(adr,rd_data);				// Read RAM data msbs [17:16]
						rd_data_msb = (rd_data >> 13) & 0x3;
						rd_data_mem = rd_data_lsb | (rd_data_msb << 16); 

						if (cprr && !cprr_ignore && (rd_data_mem != wr_data_mem)){
							printf("\tInjector Verify Err: cfeb%1i key%3i RAM%2i Tbin%2i wr=%5.5X rd=%5.5X\n",icfeblp,ikey,iram,itbin,wr_data_mem,rd_data_mem);
							printf("\tSkip, Continue <cr> ");
							gets(line);
							n=strlen(line);
							sscanf(line,"%c",&i);
							if (n==1 && (i=='S' || i=='s')) cprr_ignore=true;
						}

					}	// close itbin
				}	// close iram
			}	// close icfebl

			// Set ALCT first muon to inject:
			if (nalcts_inject >= 1) {
				alct0_vpf_inj	= 1;			//  Valid pattern flag
				alct0_qual_inj	= 3;			//  Pattern quality
				alct0_amu_inj	= 0;			//  Accelerator muon
				alct0_key_inj	= (ikey+5)%128;	//  Wire group ID number (just some offset wrt clct key for now)
				alct0_bxn_inj	= 1;			//  Bunch crossing number
			}
			else {							//  No 1st alct muon
				alct0_vpf_inj	= 0;			//  Valid pattern flag
				alct0_qual_inj	= 0;			//  Pattern quality
				alct0_amu_inj	= 0;			//  Accelerator muon
				alct0_key_inj	= 0;			//  Wire group ID number (just some offset wrt clct key for now)
				alct0_bxn_inj	= 0;			//  Bunch crossing number
			}

			alct0_inj_wr	= (alct0_vpf_inj  <<  0);
			alct0_inj_wr	= (alct0_qual_inj <<  1) | alct0_inj_wr;
			alct0_inj_wr	= (alct0_amu_inj  <<  3) | alct0_inj_wr;
			alct0_inj_wr	= (alct0_key_inj  <<  4) | alct0_inj_wr;
			alct0_inj_wr	= (alct0_bxn_inj  << 11) | alct0_inj_wr;

			wr_data = alct0_inj_wr;
			adr     = alct0_inj_adr+base_adr;
			status  = vme_write(adr,wr_data);

			fprintf(log_file,"alct0_inj_wr=%4.4X\n",alct0_inj_wr);

			// Set ALCT second muon to inject:
			if (nalcts_inject == 2) {
				alct1_vpf_inj	= 1;			//  Valid pattern flag
				alct1_qual_inj	= 2;			//  Pattern quality
				alct1_amu_inj	= 0;			//  Accelerator muon
				alct1_key_inj	= (ikey+9)%128;	//  Wire group ID number (just some offset wrt clct key for now)
				alct1_bxn_inj	= 3;			//  Bunch crossing number
			}
			else {						//  No 2nd alct muon
				alct1_vpf_inj	= 0;			//  Valid pattern flag
				alct1_qual_inj	= 0;			//  Pattern quality
				alct1_amu_inj	= 0;			//  Accelerator muon
				alct1_key_inj	= 0;			//  Wire group ID number
				alct1_bxn_inj	= 0;			//  Bunch crossing number
			}

			alct1_inj_wr	= (alct1_vpf_inj  <<  0);
			alct1_inj_wr	= (alct1_qual_inj <<  1) | alct1_inj_wr;
			alct1_inj_wr	= (alct1_amu_inj  <<  3) | alct1_inj_wr;
			alct1_inj_wr	= (alct1_key_inj  <<  4) | alct1_inj_wr;
			alct1_inj_wr	= (alct1_bxn_inj  << 11) | alct1_inj_wr;

			wr_data = alct1_inj_wr;	
			adr     = alct1_inj_adr+base_adr;
			status  = vme_write(adr,wr_data);

			fprintf(log_file,"alct1_inj_wr=%4.4X\n",alct1_inj_wr);

			// Lower pattern threshold temporarily so edge key 1/2-strips will trigger, set it back later
			if (loop_keys[0] && (ikey<=4 || ikey>=154))
			{
				hit_thresh_pretrig_temp   = clct_hit_expect[0];
				hit_thresh_postdrift_temp = clct_hit_expect[0];

				if (nclcts_inject==2) {
					hit_thresh_pretrig_temp   = min(clct_hit_expect[0],clct_hit_expect[1]);
					hit_thresh_postdrift_temp = min(clct_hit_expect[0],clct_hit_expect[1]);}
			}
			else
			{
				hit_thresh_pretrig_temp   = hit_thresh_pretrig;
				hit_thresh_postdrift_temp = hit_thresh_postdrift;
			}

			adr    = seq_clct_adr+base_adr;
			status = vme_read(adr,rd_data);

			wr_data = rd_data & 0x8000;	// clear hit_thresh,nph_pattern,drift
			wr_data = wr_data | (triad_persist             <<  0);
			wr_data = wr_data | (hit_thresh_pretrig_temp   <<  4);
			wr_data = wr_data | (dmb_thresh_pretrig        <<  7);
			wr_data = wr_data | (hit_thresh_postdrift_temp << 10);
			wr_data = wr_data | (drift_delay               << 13);
			status  = vme_write(adr,wr_data);

			// Clear previous event aff, clct, mpc registers
			adr     = seqmod_adr+base_adr;
			status  = vme_read(adr,rd_data);
			wr_data = rd_data |  (1<<15);		// clear   = set bit 15
			status  = vme_write(adr,wr_data);
			wr_data = rd_data & ~(1<<15);		// unclear = clr bit 15
			status  = vme_write(adr,wr_data);

			// Set scope-in-readout
			adr     = base_adr+scp_ctrl_adr;
			status  = vme_read(adr,rd_data);
			wr_data = rd_data & 0xFF07;	 // clear bits 3,4,5,6,7
			wr_data = wr_data | (scp_auto    << 3);
			wr_data = wr_data | (scp_nowrite << 4);
			wr_data = wr_data | (scp_tbins   << 5);
			status  = vme_write(adr,wr_data);

			// Arm scope trigger
			scp_arm        = true;
			scp_readout    = false;
			scp_raw_decode = false;
			scp_silent     = false;
			scp_playback   = false;
			if (rdscope)
				scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

			// Fire CLCT+ALCT Injectors
			adr     = cfeb_inj_adr+base_adr;
			status  = vme_read(adr,rd_data);
			wr_data = rd_data | 0x8000;		// fire injector
			status  = vme_write(adr,wr_data);
			wr_data = rd_data & 0x7FFF;		// unfire
			status  = vme_write(adr,wr_data);

			// Wait for injector to complete
			for (i=0; i<=10; ++i) {
				adr      = cfeb_inj_adr+base_adr;
				status   = vme_read(adr,rd_data);
				inj_busy = (rd_data >> 15) & 0x1;
				if (inj_busy==0) break;
				if (i==10) pause("CFEB injector RAM failed to go unbusy after 10 VME reads");
			}

			// CLCTemu: Predict expected clct pattern-finder results for these 1/2-strip hits
			engage_pattern_finder=true;

			if (engage_pattern_finder)
			{
				pattern_finder
					(
					 ihs,				// inputs

					 csc_type, 
					 clct_sep, 
					 adjcfeb_dist,
					 layer_trig_en,
					 cfeb_en,

					 hit_thresh_pretrig,
					 pid_thresh_pretrig,
					 dmb_thresh_pretrig,
					 lyr_thresh_pretrig,

					 cfeb_active_emu,	// outputs
					 nlayers_hit_emu,
					 layer_trig_emu,

					 hs_key_1st_emu,	
					 hs_pid_1st_emu,
					 hs_hit_1st_emu,

					 hs_key_2nd_emu,
					 hs_pid_2nd_emu,
					 hs_hit_2nd_emu
						 );
			}
			else
			{
				hs_key_1st_emu = 0;
				hs_pid_1st_emu = 0;
				hs_hit_1st_emu = 0;

				hs_key_2nd_emu = 0;
				hs_pid_2nd_emu = 0;
				hs_hit_2nd_emu = 0;

				nlayers_hit_emu = 0;
				layer_trig_emu = 0;

				cfeb_active_emu[0]=0;
				cfeb_active_emu[1]=0;
				cfeb_active_emu[2]=0;
				cfeb_active_emu[3]=0;
				cfeb_active_emu[4]=0;
			}

			fprintf(log_file,"\n");
			fprintf(log_file,"CLCTemu hs_key_1st_emu=%3i hs_pid_1st_emu =%1X hs_hit_1st_emu=%1i\n",hs_key_1st_emu, hs_pid_1st_emu, hs_hit_1st_emu);
			fprintf(log_file,"CLCTemu hs_key_2nd_emu=%3i hs_pid_2nd_emu =%1X hs_hit_2nd_emu=%1i\n",hs_key_2nd_emu, hs_pid_2nd_emu, hs_hit_2nd_emu);
			fprintf(log_file,"CLCTemu layer_trig_emu=%3i nlayers_hit_emu=%1i\n",layer_trig_emu, nlayers_hit_emu);
			fprintf(log_file,"CLCTemu cfeb_active_emu[4:0]=");for(i=4;i>=0;--i)fprintf(log_file,"%1i",cfeb_active_emu[i]); fprintf(log_file,"\n");
			fprintf(log_file,"\n");

			// CLCTemu: Latch pattern finder emulator results
			emulator_pretrig     = (hs_hit_1st_emu>=hit_thresh_pretrig_temp   && hs_pid_1st_emu>=pid_thresh_pretrig  );
			emulator_latch_clct0 = (hs_hit_1st_emu>=hit_thresh_postdrift_temp && hs_pid_1st_emu>=pid_thresh_postdrift) && emulator_pretrig;
			emulator_latch_clct1 = (hs_hit_2nd_emu>=hit_thresh_postdrift_temp && hs_pid_2nd_emu>=pid_thresh_postdrift) && emulator_latch_clct0;

			if (emulator_latch_clct0) {
				clct0_vpf_emu	= 1;						//  Valid pattern flag
				clct0_hit_emu	= hs_hit_1st_emu;			//  Hits on pattern
				clct0_pid_emu	= hs_pid_1st_emu;			//  Pattern number
				clct0_key_emu	= hs_key_1st_emu;			//  1/2-strip ID number
				clct0_cfeb_emu	= hs_key_1st_emu>>5;		//  CFEB ID
				clctc_sync_emu  = ~vme_bx0_emu_en & 0x1;}	//	Sync error
			else {
				clct0_vpf_emu	= 0;
				clct0_hit_emu	= 0;
				clct0_pid_emu	= 0;
				clct0_key_emu	= 0;
				clct0_cfeb_emu	= 0;
				clctc_sync_emu	= 0;}

			if (emulator_latch_clct1) {
				clct1_vpf_emu	= 1;						//  Valid pattern flag
				clct1_hit_emu	= hs_hit_2nd_emu;			//  Hits on pattern
				clct1_pid_emu	= hs_pid_2nd_emu;			//  Pattern number
				clct1_key_emu	= hs_key_2nd_emu;			//  1/2-strip ID number
				clct1_cfeb_emu	= hs_key_2nd_emu>>5;}		//  CFEB ID
			else {
				clct1_vpf_emu	= 0;
				clct1_hit_emu	= 0;
				clct1_pid_emu	= 0;
				clct1_key_emu	= 0;
				clct1_cfeb_emu	= 0;}

			// CLCTvme: Get VME latched CLCT words
			adr    = seq_clct0_adr+base_adr;
			status = vme_read(adr,rd_data);
			clct0_vme = rd_data;

			adr    = seq_clct1_adr+base_adr;
			status = vme_read(adr,rd_data);
			clct1_vme = rd_data;

			adr    = seq_clctm_adr+base_adr;
			status = vme_read(adr,rd_data);
			clctc_vme = (rd_data >> 0) & 0x0007;

			fprintf(log_file,"clct0_vme=%6.6X\n",clct0_vme);
			fprintf(log_file,"clct1_vme=%6.6X\n",clct1_vme);
			fprintf(log_file,"clctm_vme=%6.6X\n",rd_data);

			// CLCTvme: Get VME clct bxn stored at pretrigger
			adr    = bxn_clct_adr+base_adr;
			status = vme_read(adr,rd_data);
			clct_bxn_expect = rd_data & 0x3;
			fprintf(log_file,"CLCT pretrigger bxn=%4.4Xh truncated=%4.4Xh\n",rd_data,clct_bxn_expect);

			// CLCTvme: Get VME  number of layers hit
			adr    = layer_trig_adr+base_adr;
			status = vme_read(adr,rd_data);
			nlayers_hit = (rd_data >> 4) & 0x7;

			fprintf(log_file,"nlayers_hit=%1i\n",nlayers_hit);

			// CLCTvme: Get VME active CFEB list
			adr    = seq_clctm_adr+base_adr;
			status = vme_read(adr,rd_data);
			active_feb_list = (rd_data >> 3) & 0x1F;

			// CLCTvme: Decompose VME CLCTs
			clct0_vpf_vme	= (clct0_vme >>  0) & 0x0001;	//  Valid pattern flag
			clct0_hit_vme	= (clct0_vme >>  1) & 0x0007;	//  Hits on pattern
			clct0_pid_vme	= (clct0_vme >>  4) & 0x000F;	//  Pattern number
			clct0_key_vme	= (clct0_vme >>  8) & 0x00FF;	//  1/2-strip ID number
			clct0_cfeb_vme	= (clct0_vme >> 13) & 0x0007;	//  CFEB ID

			clct1_vpf_vme	= (clct1_vme >>  0) & 0x0001;	//  Valid pattern flag
			clct1_hit_vme	= (clct1_vme >>  1) & 0x0007;	//  Hits on pattern
			clct1_pid_vme	= (clct1_vme >>  4) & 0x000F;	//  Pattern number
			clct1_key_vme	= (clct1_vme >>  8) & 0x00FF;	//  1/2-strip ID number
			clct1_cfeb_vme	= (clct1_vme >> 13) & 0x0007;	//  CFEB ID

			clctc_bxn_vme	= (clctc_vme >>  0) & 0x0003;	//  Bunch crossing number
			clctc_sync_vme	= (clctc_vme >>  2) & 0x0001;	//  Sync error

			// CLCTemu+vme: Compare VME CLCTs to emulator CLCTs
			ck("clct0_vpf  read vme.expect emulator", clct0_vpf_vme,	clct0_vpf_emu );
			ck("clct0_hit  read vme.expect emulator", clct0_hit_vme,	clct0_hit_emu );
			ck("clct0_pid  read vme.expect emulator", clct0_pid_vme,	clct0_pid_emu );
			ck("clct0_key  read vme.expect emulator", clct0_key_vme,	clct0_key_emu );
			ck("clct0_cfeb read vme.expect emulator", clct0_cfeb_vme,	clct0_cfeb_emu);

			ck("clct1_vpf  read vme.expect emulator", clct1_vpf_vme,	clct1_vpf_emu );
			ck("clct1_hit  read vme.expect emulator", clct1_hit_vme,	clct1_hit_emu );
			ck("clct1_pid  read vme.expect emulator", clct1_pid_vme,	clct1_pid_emu );
			ck("clct1_key  read vme.expect emulator", clct1_key_vme,	clct1_key_emu );
			ck("clct1_cfeb read vme.expect emulator", clct1_cfeb_vme,	clct1_cfeb_emu);

			ck("clctc_sync read vme.expect emulator", clctc_sync_vme,	clctc_sync_emu);

			// CLCTinj: Predict number of hits on injected CLCTs due to staggering losses at CSC edges
			for (i=0; i<nclcts_inject; ++i)
			{
				clct_hit_inject_clip[i]=clct_hit_inject[i];			// no edge clipping

				if ((csc_type==0xA && clct_key_inject[i]==159) ||	// Normal   CSC
						(csc_type==0xB && clct_key_inject[i]==0  ))		// Reversed CSC
				{
					if (clct_hit_inject[i]==6) clct_hit_inject_clip[i]=clct_hit_inject[i]-3;	// hit ly0,1,2,3,4,5 clipped ly1,3,5	
					if (clct_hit_inject[i]==5) clct_hit_inject_clip[i]=clct_hit_inject[i]-2;	// hit ly0,1,2,3,4   clipped ly1,3	
					if (clct_hit_inject[i]==4) clct_hit_inject_clip[i]=clct_hit_inject[i]-2;	// hit ly0,1,2,3     clipped ly1,3	
					if (clct_hit_inject[i]==3) clct_hit_inject_clip[i]=clct_hit_inject[i]-1;	// hit ly0,1,2       clipped ly1	
					if (clct_hit_inject[i]==2) clct_hit_inject_clip[i]=clct_hit_inject[i]-1;	// hit ly0,1         clipped ly1	
					if (clct_hit_inject[i]==1) clct_hit_inject_clip[i]=clct_hit_inject[i]-0;	// hit ly0           clipped none	
					fprintf(log_file,"clct_hit_inject[%1i] clipped from %1i hits to %1i hits at csc edge due to staggering\n",i,clct_hit_inject[i],clct_hit_inject_clip[i]);
				}
				fprintf(log_file,"clct_hit_inject[%1i]=%1i clct_hit_inject_clip[%1i]=%1i\n",i,clct_hit_inject[i],i,clct_hit_inject_clip[i]);
			}	// close for i

			// CLCTinj: Find expected clct0 from the injector
			clct_hit_inj_expect[0] = 0;
			clct_key_inj_expect[0] = 0;
			clct_pid_inj_expect[0] = 0;
			clct_pat_inj_expect[0] = 0;

			for (i=0; i<nclcts_inject; ++i) {
				clct_pat_inject[i] = (clct_hit_inject_clip[i]<<4) | clct_pid_inject[i];

				if ((clct_pat_inject[i] >  clct_pat_inj_expect[0]) ||		// found a better pattern
						((clct_pat_inject[i] == clct_pat_inj_expect[0]) &&		// found an equal pattern 
						 (clct_key_inject[i] <  clct_key_inj_expect[0])))		// take the equal pattern at the lower key hs
				{
					clct_hit_inj_expect[0] = clct_hit_inject_clip[i];
					clct_key_inj_expect[0] = clct_key_inject[i];
					clct_pid_inj_expect[0] = clct_pid_inject[i];
					clct_pat_inj_expect[0] = clct_pat_inject[i];
				}
			}

			fprintf(log_file,"clct_hit_inj_expect[0]=%3i\n",clct_hit_inj_expect[0]);
			fprintf(log_file,"clct_key_inj_expect[0]=%3i\n",clct_key_inj_expect[0]);
			fprintf(log_file,"clct_pid_inj_expect[0]=%3X\n",clct_pid_inj_expect[0]);
			fprintf(log_file,"clct_pat_inj_expect[0]=%3X\n",clct_pat_inj_expect[0]);

			// CLCTinj: Create key 1/2-strip blanking region around clct0 from injector
			nspan = clct_sep;
			pspan = clct_sep;

			key_inj = clct_key_inj_expect[0];
			clct0_is_on_me1a = (key_inj>=128);

			if (csc_type==0xA || csc_type==0xB)		// CSC Type A or B limit busy list to range 0-159
			{
				busy_max = (key_inj <= 159-pspan) ? key_inj+pspan : 159;	// Limit busy list to range 0-159
				busy_min = (key_inj >= nspan    ) ? key_inj-nspan : 0;
			}

			else if (csc_type==0xC || csc_type==0xD)					// CSC Type C or D delimiters for excluding 2nd clct span ME1B hs0-127  ME1A hs128-159
			{
				if (clct0_is_on_me1a) {		// CLCT0 is on ME1A cfeb4, limit blanking region to 128-159
					busy_max = (key_inj <= 159-pspan) ? key_inj+pspan : 159;
					busy_min = (key_inj >= 128+nspan) ? key_inj-nspan : 128;
				}
				else {						// CLCT0 is on ME1B cfeb0-cfeb3, limit blanking region to 0-127
					busy_max = (key_inj <= 127-pspan) ? key_inj+pspan : 127;
					busy_min = (key_inj >=     nspan) ? key_inj-nspan : 0;
				}
			}

			for (i=0; i<160; ++i) {
				busy_key_inj[i] = (i>=busy_min && i<=busy_max);
			}

			fprintf(log_file,"busy_key_inj="); for (i=0; i<160; ++i) fprintf(log_file,"%1i",busy_key_inj[i]); fprintf(log_file,"\n");

			// CLCTinj: Find expected clct1 from the injector
			clct_hit_inj_expect[1] = 0;
			clct_key_inj_expect[1] = 0;
			clct_pid_inj_expect[1] = 0;
			clct_pat_inj_expect[1] = 0;

			for (i=0; i<nclcts_inject; ++i) {
				if (nclcts_inject<=1) break;
				if (clct_blanked[i] ) continue;

				if ((clct_pat_inject[i] >  clct_pat_inj_expect[1]) ||		// found a better pattern
						((clct_pat_inject[i] == clct_pat_inj_expect[1]) &&		// found an equal pattern 
						 (clct_key_inject[i] <  clct_key_inj_expect[1])))		// take the equal pattern at the lower key hs
				{
					key_inj = clct_key_inject[i];
					fprintf(log_file,"dbg: key_inj=%3i\n",key_inj);
					fprintf(log_file,"dbg: busy_key[key_inj]=%3i\n",busy_key_inj[key_inj]);

					if (busy_key_inj[key_inj]==0)							// accept only non-busy keys far enough away from clct0
					{
						clct_hit_inj_expect[1] = clct_hit_inject_clip[i];
						clct_key_inj_expect[1] = clct_key_inject[i];
						clct_pid_inj_expect[1] = clct_pid_inject[i];
						clct_pat_inj_expect[1] = clct_pat_inject[i];
					}
				}
			}

			fprintf(log_file,"clct_hit_inj_expect[1]=%3i\n",clct_hit_inj_expect[1]);
			fprintf(log_file,"clct_key_inj_expect[1]=%3i\n",clct_key_inj_expect[1]);
			fprintf(log_file,"clct_pid_inj_expect[1]=%3X\n",clct_pid_inj_expect[1]);
			fprintf(log_file,"clct_pat_inj_expect[1]=%3X\n",clct_pat_inj_expect[1]);

			// CLCTinj: Predict pre-trigger and post-drift behavior for injected CLCTs
			injector_clct0_over  = false;	// clct0 over thresholds
			injector_clct1_over  = false;	// clct1 over thresholds
			injector_pretrig     = false;	// tmb should pretrigger
			injector_latch_clct0 = false;	// tmb should latch clct0
			injector_latch_clct1 = false;	// tmb should latch clct1

			if (nclcts_inject>=1)
			{
				injector_clct0_over  = (clct_hit_inj_expect[0]>=hit_thresh_pretrig_temp   && clct_pid_inj_expect[0]>=pid_thresh_pretrig);
				injector_clct1_over  = (clct_hit_inj_expect[1]>=hit_thresh_pretrig_temp   && clct_pid_inj_expect[1]>=pid_thresh_pretrig);
				injector_pretrig     = injector_clct0_over;
				injector_latch_clct0 = injector_pretrig && injector_clct0_over;
				injector_latch_clct1 = injector_pretrig && injector_clct1_over;
			}

			fprintf(log_file,"injector_clct0_over =%c\n",logical(injector_clct0_over ));
			fprintf(log_file,"injector_clct1_over =%c\n",logical(injector_clct1_over ));
			fprintf(log_file,"injector_pretrig    =%c\n",logical(injector_pretrig    ));
			fprintf(log_file,"injector_latch_clct0=%c\n",logical(injector_latch_clct0));
			fprintf(log_file,"injector_latch_clct1=%c\n",logical(injector_latch_clct1));

			// CLCTinj: Latch pattern finder emulator results
			clct0_vpf_vme_expect = 0;
			clct0_hit_vme_expect = 0;
			clct0_pid_vme_expect = 0;
			clct0_key_vme_expect = 0;
			clct0_cfeb_vme_expect= 0;
			clctc_sync_vme_expect= 0;

			clct1_vpf_vme_expect = 0;
			clct1_hit_vme_expect = 0;
			clct1_pid_vme_expect = 0;
			clct1_key_vme_expect = 0;
			clct1_cfeb_vme_expect= 0;

			if (injector_latch_clct0) {
				clct0_vpf_vme_expect = 1;
				clct0_hit_vme_expect = clct_hit_inj_expect[0];
				clct0_pid_vme_expect = clct_pid_inj_expect[0];
				clct0_key_vme_expect = clct_key_inj_expect[0];
				clct0_cfeb_vme_expect= clct_key_inj_expect[0]/32;
				clctc_sync_vme_expect= ~vme_bx0_emu_en & 0x1;
			}

			if (injector_latch_clct1) {
				clct1_vpf_vme_expect = 1;
				clct1_hit_vme_expect = clct_hit_inj_expect[1];
				clct1_pid_vme_expect = clct_pid_inj_expect[1];
				clct1_key_vme_expect = clct_key_inj_expect[1];
				clct1_cfeb_vme_expect= clct_key_inj_expect[1]/32;
			}

			// CLCTinj: Construct expected VME CLCTs from injected CLCTs
			key0 = clct0_key_vme_expect;
			key1 = clct1_key_vme_expect;

			if (injector_latch_clct0) {
				if (key0 <= 127 && reverse_hs_me1b == 1) {clct0_key_vme_expect  = 127- key0;		clct0_pid_vme_expect=flip_pid(clct0_pid_vme_expect);}
				if (key0 >= 128 && reverse_hs_me1a == 1) {clct0_key_vme_expect  = 159-(key0-128);	clct0_pid_vme_expect=flip_pid(clct0_pid_vme_expect);}
				if (reverse_hs_csc==1)					 {clct0_key_vme_expect  = 159- key0;		clct0_pid_vme_expect=flip_pid(clct0_pid_vme_expect);}
				clct0_cfeb_vme_expect = clct0_key_vme_expect/32;
			}

			if (injector_latch_clct1) {
				if (key1 <= 127 && reverse_hs_me1b == 1) {clct1_key_vme_expect  = 127- key1;		clct1_pid_vme_expect=flip_pid(clct1_pid_vme_expect);}
				if (key1 >= 128 && reverse_hs_me1a == 1) {clct1_key_vme_expect  = 159-(key1-128);	clct1_pid_vme_expect=flip_pid(clct1_pid_vme_expect);}
				if (reverse_hs_csc==1)					 {clct1_key_vme_expect  = 159- key1;		clct1_pid_vme_expect=flip_pid(clct1_pid_vme_expect);}
				clct1_cfeb_vme_expect = clct1_key_vme_expect/32;
			}

			// CLCTinj: Layer mode expects pattern 1 in 1st clct and no 2nd clct
			if (layer_mode)
			{
				clct0_vpf_vme_expect = 1;
				clct0_hit_vme_expect = clct0_hit_vme_expect;
				clct0_pid_vme_expect = 1;
				clct0_key_vme_expect = 0;
				clct0_cfeb_vme_expect= clct0_key_vme_expect/32;

				clct1_vpf_vme_expect = 0;
				clct1_hit_vme_expect = 0;
				clct1_pid_vme_expect = 0;
				clct1_key_vme_expect = 0;
				clct1_cfeb_vme_expect= 0;
			}

			// CLCTinj+vme: Compare VME CLCTs to expected VME CLCTs from injector
			ck("clct0_vpf  read vme.expect injected", clct0_vpf_vme,	clct0_vpf_vme_expect );
			ck("clct0_hit  read vme.expect injected", clct0_hit_vme,	clct0_hit_vme_expect );
			ck("clct0_pid  read vme.expect injected", clct0_pid_vme,	clct0_pid_vme_expect );
			ck("clct0_key  read vme.expect injected", clct0_key_vme,	clct0_key_vme_expect );
			ck("clct0_cfeb read vme.expect injected", clct0_cfeb_vme,	clct0_cfeb_vme_expect);
			ck("clctc_bxn  read vme.expect injected", clctc_bxn_vme,	clct_bxn_expect      );

			ck("clct1_vpf  read vme.expect injected", clct1_vpf_vme,	clct1_vpf_vme_expect );
			ck("clct1_hit  read vme.expect injected", clct1_hit_vme,	clct1_hit_vme_expect );
			ck("clct1_pid  read vme.expect injected", clct1_pid_vme,	clct1_pid_vme_expect );
			ck("clct1_key  read vme.expect injected", clct1_key_vme,	clct1_key_vme_expect );
			ck("clct1_cfeb read vme.expect injected", clct1_cfeb_vme,	clct1_cfeb_vme_expect);

			ck("clctc_sync read vme.expect injected", clctc_sync_vme,	clctc_sync_vme_expect);

			// TMBemu: Take either the CLCT injector or emulator result for the TMB stage
			if (send_emulator_to_tmb) {
				fprintf(log_file,"CLCT: Sending emulator CLCTs to TMB checking\n");
				clct0_vpf_tmb  = clct0_vpf_emu;
				clct0_hit_tmb  = clct0_hit_emu;
				clct0_pid_tmb  = clct0_pid_emu;
				clct0_key_tmb  = clct0_key_emu;
				clct0_cfeb_tmb = clct0_cfeb_emu;

				clct1_vpf_tmb  = clct1_vpf_emu;
				clct1_hit_tmb  = clct1_hit_emu;
				clct1_pid_tmb  = clct1_pid_emu;
				clct1_key_tmb  = clct1_key_emu;
				clct1_cfeb_tmb = clct1_cfeb_emu;

				clctc_bxn_tmb      = clctc_bxn_vme;
				clctc_sync_err_tmb = ~vme_bx0_emu_en & 0x1;
			}
			else {
				fprintf(log_file,"CLCT: Sending injector CLCTs to TMB checking\n");
				clct0_vpf_tmb  = clct0_vpf_vme_expect;
				clct0_hit_tmb  = clct0_hit_vme_expect;
				clct0_pid_tmb  = clct0_pid_vme_expect;
				clct0_key_tmb  = clct0_key_vme_expect;
				clct0_cfeb_tmb = clct0_cfeb_vme_expect;

				clct1_vpf_tmb  = clct1_vpf_vme_expect;
				clct1_hit_tmb  = clct1_hit_vme_expect;
				clct1_pid_tmb  = clct1_pid_vme_expect;
				clct1_key_tmb  = clct1_key_vme_expect;
				clct1_cfeb_tmb = clct1_cfeb_vme_expect;

				clctc_bxn_tmb      = clct_bxn_expect;
				clctc_sync_err_tmb = ~vme_bx0_emu_en & 0x1;
			}

			// TMBemu: Pseudo pipes for emulator
			clct0_pipe = (clct0_vpf_tmb << 0) |
				(clct0_hit_tmb << 1) |
				(clct0_pid_tmb << 4) |
				(clct0_key_tmb << 8);

			clct1_pipe = (clct1_vpf_tmb << 0) |
				(clct1_hit_tmb << 1) |
				(clct1_pid_tmb << 4) |
				(clct1_key_tmb << 8);

			clctc_pipe = (clctc_bxn_tmb      << 0) |
				(clctc_sync_err_tmb << 2);

			alct0_pipe = alct0_inj_wr;
			alct1_pipe = alct1_inj_wr;

			// TMBemu: Predict expected clct and alct duplication
			expect_zero_alct = 0;
			expect_zero_clct = 0;
			expect_one_alct  = 0;
			expect_one_clct  = 0;
			expect_two_alct  = 0;
			expect_two_clct  = 0;
			expect_dupe_alct = 0;
			expect_dupe_clct = 0;

			if (clct0_vpf_tmb==0 && clct1_vpf_tmb==0) expect_zero_clct = 1;
			if (clct0_vpf_tmb==1 && clct1_vpf_tmb==0) expect_one_clct  = 1;
			if (clct0_vpf_tmb==1 && clct1_vpf_tmb==1) expect_two_clct  = 1;
			if (clct0_vpf_tmb==0 && clct1_vpf_tmb==1) pause("clct ranking error, wtf!?");

			if (nalcts_inject==0) expect_zero_alct = 1;
			if (nalcts_inject==1) expect_one_alct  = 1;
			if (nalcts_inject==2) expect_two_alct  = 1;

			if (expect_one_clct==1 && nalcts_inject==2) expect_dupe_clct = 1;
			if (expect_two_clct==1 && nalcts_inject==1) expect_dupe_alct = 1;

			fprintf(log_file,"\n");
			fprintf(log_file,"Setting expect_zero_alct = %c\n",logical(expect_zero_alct));
			fprintf(log_file,"Setting expect_zero_clct = %c\n",logical(expect_zero_clct));
			fprintf(log_file,"Setting expect_one_alct  = %c\n",logical(expect_one_alct));
			fprintf(log_file,"Setting expect_one_clct  = %c\n",logical(expect_one_clct));
			fprintf(log_file,"Setting expect_two_alct  = %c\n",logical(expect_two_alct));
			fprintf(log_file,"Setting expect_two_clct  = %c\n",logical(expect_two_clct));
			fprintf(log_file,"Setting expect_dupe_alct = %c\n",logical(expect_dupe_alct));
			fprintf(log_file,"Setting expect_dupe_clct = %c\n",logical(expect_dupe_clct));

			// TMBemu: Event trigger disposition
			clct_noalct_lost= false;
			alct_only_trig  = (expect_zero_clct==1);

			clct_match      = (!expect_zero_clct && !expect_zero_alct);
			clct_noalct     = (!expect_zero_clct &&  expect_zero_alct);
			alct_noclct     = ( expect_zero_clct && !expect_zero_alct);
			alct_pulse      = (!expect_zero_alct);

			clct_keep		=((clct_match && tmb_allow_match   ) || (clct_noalct &&  tmb_allow_clct    && !clct_noalct_lost));
			alct_keep		= (clct_match && tmb_allow_match   ) || (alct_noclct &&  tmb_allow_alct);

			clct_keep_ro	= (clct_match && tmb_allow_match_ro) || (clct_noalct &&  tmb_allow_clct_ro && !clct_noalct_lost);
			alct_keep_ro	= (clct_match && tmb_allow_match_ro) || (alct_noclct &&  tmb_allow_alct_ro);

			clct_discard	= (clct_match && !tmb_allow_match  ) || (clct_noalct && !tmb_allow_clct) || clct_noalct_lost;
			alct_discard	=  alct_pulse && !alct_keep;

			trig_pulse		= clct_match || clct_noalct || clct_noalct_lost || alct_only_trig;	// Event pulse

			trig_keep		= (clct_keep    || alct_keep);										// Keep event for trigger and readout
			non_trig_keep	= (clct_keep_ro || alct_keep_ro);									// Keep non-triggering event for readout only

			alct_only		= (alct_noclct && tmb_allow_alct) && !clct_keep;					// An alct-only trigger

			clct_match_tr	= clct_match  && trig_keep;		// ALCT and CLCT matched in time, nontriggering event
			alct_noclct_tr	= alct_noclct && trig_keep;		// Only ALCT triggered, nontriggering event
			clct_noalct_tr	= clct_noalct && trig_keep;		// Only CLCT triggered, nontriggering event

			clct_match_ro	= clct_match  && non_trig_keep;	// ALCT and CLCT matched in time, nontriggering event
			alct_noclct_ro	= alct_noclct && non_trig_keep;	// Only ALCT triggered, nontriggering event
			clct_noalct_ro	= clct_noalct && non_trig_keep;	// Only CLCT triggered, nontriggering event

			alct_only_trig  = (alct_noclct && tmb_allow_alct) || (alct_noclct_ro && tmb_allow_alct_ro);// ALCT-only triggers are allowed

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: clct_match     = %c\n",logical(clct_match    ));
			fprintf(log_file,"TMBemu: clct_noalct    = %c\n",logical(clct_noalct   ));
			fprintf(log_file,"TMBemu: alct_noclct    = %c\n",logical(alct_noclct   ));
			fprintf(log_file,"TMBemu: alct_pulse     = %c\n",logical(alct_pulse    ));
			fprintf(log_file,"TMBemu: clct_keep      = %c\n",logical(clct_keep     ));
			fprintf(log_file,"TMBemu: alct_keep      = %c\n",logical(alct_keep     ));
			fprintf(log_file,"TMBemu: clct_keep_ro   = %c\n",logical(clct_keep_ro  ));
			fprintf(log_file,"TMBemu: alct_keep_ro   = %c\n",logical(alct_keep_ro  ));
			fprintf(log_file,"TMBemu: clct_discard   = %c\n",logical(clct_discard  ));
			fprintf(log_file,"TMBemu: alct_discard   = %c\n",logical(alct_discard  ));
			fprintf(log_file,"TMBemu: trig_pulse     = %c\n",logical(trig_pulse    ));
			fprintf(log_file,"TMBemu: trig_keep      = %c\n",logical(trig_keep     ));
			fprintf(log_file,"TMBemu: non_trig_keep  = %c\n",logical(non_trig_keep ));
			fprintf(log_file,"TMBemu: alct_only      = %c\n",logical(alct_only     ));
			fprintf(log_file,"TMBemu: clct_match_tr  = %c\n",logical(clct_match_tr ));
			fprintf(log_file,"TMBemu: alct_noclct_tr = %c\n",logical(alct_noclct_tr));
			fprintf(log_file,"TMBemu: clct_noalct_tr = %c\n",logical(clct_noalct_tr));
			fprintf(log_file,"TMBemu: clct_match_ro  = %c\n",logical(clct_match_ro ));
			fprintf(log_file,"TMBemu: alct_noclct_ro = %c\n",logical(alct_noclct_ro));
			fprintf(log_file,"TMBemu: clct_noalct_ro = %c\n",logical(clct_noalct_ro));
			fprintf(log_file,"TMBemu: alct_only_trig = %c\n",logical(alct_only_trig));

			// TMBemu: Latch clct match results for TMB and MPC pathways
			tmb_trig_pulse		= trig_pulse;							// ALCT or CLCT or both triggered
			tmb_trig_keep_ff	= trig_keep;							// ALCT or CLCT or both triggered, and trigger is allowed
			tmb_non_trig_keep_ff= non_trig_keep;						// Event did not trigger but is kept for readout

			tmb_match			= clct_match_tr  && tmb_allow_match;	// ALCT and CLCT matched in time
			tmb_alct_only		= alct_noclct_tr && tmb_allow_alct;		// Only ALCT triggered
			tmb_clct_only		= clct_noalct_tr && tmb_allow_clct;		// Only CLCT triggered

			tmb_match_ro_ff		= clct_match_ro  && tmb_allow_match_ro;	// ALCT and CLCT matched in time, nontriggering event
			tmb_alct_only_ro_ff	= alct_noclct_ro && tmb_allow_alct_ro;	// Only ALCT triggered, nontriggering event
			tmb_clct_only_ro_ff	= clct_noalct_ro && tmb_allow_clct_ro;	// Only CLCT triggered, nontriggering event

			tmb_alct_discard	= alct_discard;							// ALCT was not used for LCT
			tmb_clct_discard	= clct_discard;							// CLCT was not used for LCT

			tmb_alct0			= alct0_pipe;							// Copy of ALCT for header
			tmb_alct1			= alct1_pipe;

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: tmb_trig_pulse       = %c\n",logical(tmb_trig_pulse      ));
			fprintf(log_file,"TMBemu: tmb_trig_keep_ff     = %c\n",logical(tmb_trig_keep_ff    ));
			fprintf(log_file,"TMBemu: tmb_non_trig_keep_ff = %c\n",logical(tmb_non_trig_keep_ff));
			fprintf(log_file,"TMBemu: tmb_match            = %c\n",logical(tmb_match           ));
			fprintf(log_file,"TMBemu: tmb_alct_only        = %c\n",logical(tmb_alct_only       ));
			fprintf(log_file,"TMBemu: tmb_clct_only        = %c\n",logical(tmb_clct_only       ));
			fprintf(log_file,"TMBemu: tmb_match_ro_ff      = %c\n",logical(tmb_match_ro_ff     ));
			fprintf(log_file,"TMBemu: tmb_alct_only_ro_ff  = %c\n",logical(tmb_alct_only_ro_ff ));
			fprintf(log_file,"TMBemu: tmb_clct_only_ro_ff  = %c\n",logical(tmb_clct_only_ro_ff ));
			fprintf(log_file,"TMBemu: tmb_alct_discard     = %c\n",logical(tmb_alct_discard    ));
			fprintf(log_file,"TMBemu: tmb_clct_discard     = %c\n",logical(tmb_clct_discard    ));
			fprintf(log_file,"TMBemu: tmb_alct0            = %4.4X\n",tmb_alct0);
			fprintf(log_file,"TMBemu: tmb_alct1            = %4.4X\n",tmb_alct1);

			// TMBemu: Kill CLCTs from ME1A, TMB firmware handles this incorrectly as of 4/6/2010
			kill_me1a_clcts = (mpc_me1a_block==1 && csc_me1ab==1);

			clct0_exists = clct0_vpf_tmb==1;
			clct1_exists = clct1_vpf_tmb==1;

			clct0_cfeb4  = clct0_cfeb_tmb==4;				// CLCT0 is on CFEB4 hence ME1A
			clct1_cfeb4  = clct1_cfeb_tmb==4;				// CLCT1 is on CFEB4 hence ME1A

			kill_clct0   = clct0_cfeb4 && kill_me1a_clcts;	// Delete CLCT0 from ME1A
			kill_clct1   = clct1_cfeb4 && kill_me1a_clcts;	// Delete CLCT1 from ME1A

			kill_trig    = ((kill_clct0 && clct0_exists) && (kill_clct1 && clct1_exists))	// Kill both clcts
				||             ((kill_clct0 && clct0_exists) && !clct1_exists)
				||             ((kill_clct1 && clct1_exists) && !clct0_exists);

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: clct0_exists         = %c\n",logical(clct0_exists));
			fprintf(log_file,"TMBemu: clct1_exists         = %c\n",logical(clct1_exists));
			fprintf(log_file,"TMBemu: clct0_cfeb4          = %c\n",logical(clct0_cfeb4 ));
			fprintf(log_file,"TMBemu: clct1_cfeb4          = %c\n",logical(clct1_cfeb4 ));
			fprintf(log_file,"TMBemu: kill_clct0           = %c\n",logical(kill_clct0  ));
			fprintf(log_file,"TMBemu: kill_clct1           = %c\n",logical(kill_clct1  ));
			fprintf(log_file,"TMBemu: kill_trig            = %c\n",logical(kill_trig   ));

			// TMBemu: Had to wait for kill signal to go valid
			tmb_match_ro     = tmb_match_ro_ff     & kill_trig;	// ALCT and CLCT matched in time, nontriggering event
			tmb_alct_only_ro = tmb_alct_only_ro_ff & kill_trig;	// Only ALCT triggered, nontriggering event
			tmb_clct_only_ro = tmb_clct_only_ro_ff & kill_trig;	// Only CLCT triggered, nontriggering event

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: tmb_match_ro         = %c\n",logical(tmb_match_ro    ));
			fprintf(log_file,"TMBemu: tmb_alct_only_ro     = %c\n",logical(tmb_alct_only_ro));
			fprintf(log_file,"TMBemu: tmb_clct_only_ro     = %c\n",logical(tmb_clct_only_ro));

			// TMBemu: Post FF mod trig_keep for me1a
			tmb_trig_keep     = tmb_trig_keep_ff && (!kill_trig || tmb_alct_only);
			tmb_non_trig_keep = tmb_non_trig_keep_ff && !tmb_trig_keep;

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: tmb_trig_keep        = %c\n",logical(tmb_trig_keep    ));
			fprintf(log_file,"TMBemu: tmb_non_trig_keep    = %c\n",logical(tmb_non_trig_keep));

			// TMBemu: Pipelined CLCTs, aligned in time with trig_pulse
			keep_clct  = trig_pulse && (trig_keep || non_trig_keep);

			clct0_real = clct0_pipe * keep_clct;
			clct1_real = clct1_pipe * keep_clct;
			clctc_real = clctc_pipe * keep_clct;

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: keep_clct            = %c\n",logical(keep_clct));
			fprintf(log_file,"TMBemu: clct0_real           = %c\n",logical(clct0_real   ));
			fprintf(log_file,"TMBemu: clct1_real           = %c\n",logical(clct1_real   ));
			fprintf(log_file,"TMBemu: clctc_real           = %c\n",logical(clctc_real   ));

			// TMBemu: Latch pipelined ALCTs, aligned in time with CLCTs because CLCTs are delayed 1bx in the SRLs
			alct0_real = alct0_pipe;
			alct1_real = alct1_pipe;

			// TMBemu: Fill in missing ALCT if CLCT has 2 muons, missing CLCT if ALCT has 2 muons
			alct0_vpf_emu = (alct0_real >> 0) & 0x1;			// Extract valid pattern flags
			alct1_vpf_emu = (alct1_real >> 0) & 0x1;
			clct0_vpf_emu = (clct0_real >> 0) & 0x1;
			clct1_vpf_emu = (clct1_real >> 0) & 0x1;

			clct_bxn_insert_emu	= clctc_real & 0x3;		// CLCT bunch crossing number for events missing alct

			tmb_no_alct_emu  = !alct0_vpf_emu;
			tmb_no_clct_emu  = !clct0_vpf_emu;

			tmb_one_alct_emu = alct0_vpf_emu && !alct1_vpf_emu;
			tmb_one_clct_emu = clct0_vpf_emu && !clct1_vpf_emu;

			tmb_two_alct_emu = alct0_vpf_emu && alct1_vpf_emu;
			tmb_two_clct_emu = clct0_vpf_emu && clct1_vpf_emu;

			tmb_dupe_alct_emu = tmb_one_alct_emu && tmb_two_clct_emu;	// Duplicate alct if there are 2 clcts
			tmb_dupe_clct_emu = tmb_one_clct_emu && tmb_two_alct_emu;	// Duplicate clct if there are 2 alcts

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: tmb_no_alct_emu      = %c\n",logical(tmb_no_alct_emu  ));
			fprintf(log_file,"TMBemu: tmb_no_clct_emu      = %c\n",logical(tmb_no_clct_emu  ));
			fprintf(log_file,"TMBemu: tmb_one_alct_emu     = %c\n",logical(tmb_one_alct_emu ));
			fprintf(log_file,"TMBemu: tmb_one_clct_emu     = %c\n",logical(tmb_one_clct_emu ));
			fprintf(log_file,"TMBemu: tmb_two_alct_emu     = %c\n",logical(tmb_two_alct_emu ));
			fprintf(log_file,"TMBemu: tmb_two_clct_emu     = %c\n",logical(tmb_two_clct_emu ));
			fprintf(log_file,"TMBemu: tmb_dupe_alct_emu    = %c\n",logical(tmb_dupe_alct_emu));
			fprintf(log_file,"TMBemu: tmb_dupe_clct_emu    = %c\n",logical(tmb_dupe_clct_emu));

			// TMBemu: Duplicate alct and clct
			alct_dummy  = (clct_bxn_insert_emu << 11);					// Insert clct bxn for clct-only events
			clct_dummy  = 0;											// Blank  clct for alct-only events
			clctc_dummy = 0;											// Blank  clct common for alct-only events

			if       (tmb_no_clct_emu  ) {clct0_emu = clct_dummy;  clct1_emu = clct_dummy;  clctc_emu = clctc_dummy;}	// clct0 and clct1 do not exist, use dummy clct	
			else if  (tmb_dupe_clct_emu) {clct0_emu = clct0_real;  clct1_emu = clct0_real;  clctc_emu = clctc_real; }	// clct0 exists, but clct1 does not exist, copy clct0 into clct1
			else                         {clct0_emu = clct0_real;  clct1_emu = clct1_real;  clctc_emu = clctc_real; }	// clct0 and clct1 exist, so use them

			if      (tmb_no_alct_emu  ) {alct0_emu = alct_dummy;  alct1_emu = alct_dummy;} // alct0 and alct1 do not exist, use dummy alct
			else if (tmb_dupe_alct_emu) {alct0_emu = alct0_real;  alct1_emu = alct0_real;} // alct0 exists, but alct1 does not exist, copy alct0 into alct1
			else                        {alct0_emu = alct0_real;  alct1_emu = alct1_real;} // alct0 and alct1 exist, so use them

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: clct0_emu            = %2.2X\n",clct0_emu);
			fprintf(log_file,"TMBemu: clct1_emu            = %2.2X\n",clct1_emu);
			fprintf(log_file,"TMBemu: alct0_emu            = %2.2X\n",alct0_emu);
			fprintf(log_file,"TMBemu: alct1_emu            = %2.2X\n",alct1_emu);

			// TMBemu: LCT valid pattern flags
			lct0_vpf_emu	= alct0_vpf_emu || clct0_vpf_emu;	// First muon exists
			lct1_vpf_emu	= alct1_vpf_emu || clct1_vpf_emu;	// Second muon exists

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: lct0_vpf_emu         = %1.1X\n",lct0_vpf_emu);
			fprintf(log_file,"TMBemu: lct1_vpf_emu         = %1.1\n",lct1_vpf_emu);

			// TMBemu: Decompose ALCT muons
			alct0_valid_emu		= (alct0_emu >>  0) & 0x1;		// Valid pattern flag
			alct0_quality_emu	= (alct0_emu >>  1) & 0x3;		// Pattern quality
			alct0_amu_emu		= (alct0_emu >>  3) & 0x1;		// Accelerator muon
			alct0_key_emu		= (alct0_emu >>  4) & 0x7F;		// Key Wire Group
			alct0_bxn_emu		= (alct0_emu >> 11) & 0x1;		// Bunch crossing number

			alct1_valid_emu		= (alct1_emu >>  0) & 0x1;		// Valid pattern flag
			alct1_quality_emu	= (alct1_emu >>  1) & 0x3;		// Pattern quality
			alct1_amu_emu		= (alct1_emu >>  3) & 0x1;		// Accelerator muon
			alct1_key_emu		= (alct1_emu >>  4) & 0x7F;		// Key Wire Group
			alct1_bxn_emu		= (alct1_emu >> 11) & 0x1;		// Bunch crossing number

			alct_bx0_emu		= alct0_bxn_emu==0;

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: alct0_valid_emu      = %1.1X\n",alct0_valid_emu);
			fprintf(log_file,"TMBemu: alct0_quality_emu    = %1.1X\n",alct0_quality_emu);
			fprintf(log_file,"TMBemu: alct0_amu_emu        = %1.1X\n",alct0_amu_emu);
			fprintf(log_file,"TMBemu: alct0_key_emu        = %2.2X\n",alct0_key_emu);
			fprintf(log_file,"TMBemu: alct0_bxn_emu        = %2.2X\n",alct0_bxn_emu);
			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: alct1_valid_emu      = %1.1X\n",alct1_valid_emu);
			fprintf(log_file,"TMBemu: alct1_quality_emu    = %1.1X\n",alct1_quality_emu);
			fprintf(log_file,"TMBemu: alct1_amu_emu        = %1.1X\n",alct1_amu_emu);
			fprintf(log_file,"TMBemu: alct1_key_emu        = %2.2X\n",alct1_key_emu);
			fprintf(log_file,"TMBemu: alct1_bxn_emu        = %2.2X\n",alct1_bxn_emu);
			fprintf(log_file,"TMBemu: alct_bx0_emu         = %1.1X\n",alct_bx0_emu);

			// TMBemu: Decompose CLCT muons
			clct0_valid_emu		= (clct0_emu >>  0) & 0x1;		// Valid pattern flag
			clct0_hit_emu		= (clct0_emu >>  1) & 0x7;		// Hits on pattern 0-6
			clct0_pid_emu		= (clct0_emu >>  4) & 0xF;		// Pattern shape 0-A
			clct0_key_emu		= (clct0_emu >>  8) & 0x1F;		// 1/2-strip ID number
			clct0_cfeb_emu		= (clct0_emu >> 13) & 0x7;		// Key CFEB ID

			clct_bxn_emu		= (clctc_emu >>  0) & 0x3;		// Bunch crossing number
			clct_sync_err_emu	= (clctc_emu >>  2) & 0x1;		// Bx0 disagreed with bxn counter

			clct1_valid_emu		= (clct1_emu >>  0) & 0x1;		// Valid pattern flag
			clct1_hit_emu		= (clct1_emu >>  1) & 0x7;		// Hits on pattern 0-6
			clct1_pid_emu		= (clct1_emu >>  4) & 0xF;		// Pattern shape 0-A
			clct1_key_emu		= (clct1_emu >>  8) & 0x1F;		// 1/2-strip ID number
			clct1_cfeb_emu		= (clct1_emu >> 13) & 0x7;		// Key CFEB ID

			clct0_bend_emu = (clct0_pid_emu >> 0) & 0x1;
			clct1_bend_emu = (clct1_pid_emu >> 0) & 0x1;

			csc_id_emu     = csc_id;
			clct_bx0_emu   = clct_bxn_emu==0;

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: clct0_valid_emu     = %1.1X\n",clct0_valid_emu);
			fprintf(log_file,"TMBemu: clct0_hit_emu       = %1.1X\n",clct0_hit_emu);
			fprintf(log_file,"TMBemu: clct0_pid_emu       = %1.1X\n",clct0_pid_emu);
			fprintf(log_file,"TMBemu: clct0_key_emu       = %2.2X\n",clct0_key_emu);
			fprintf(log_file,"TMBemu: clct0_cfeb_emu      = %1.1X\n",clct0_cfeb_emu);
			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: clct1_valid_emu     = %1.1X\n",clct1_valid_emu);
			fprintf(log_file,"TMBemu: clct1_hit_emu       = %1.1X\n",clct1_hit_emu);
			fprintf(log_file,"TMBemu: clct1_pid_emu       = %1.1X\n",clct1_pid_emu);
			fprintf(log_file,"TMBemu: clct1_key_emu       = %2.2X\n",clct1_key_emu);
			fprintf(log_file,"TMBemu: clct1_cfeb_emu      = %1.1X\n",clct1_cfeb_emu);
			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: clct0_bend_emu      = %1.1X\n",clct0_bend_emu);
			fprintf(log_file,"TMBemu: clct1_bend_emu      = %1.1X\n",clct1_bend_emu);
			fprintf(log_file,"TMBemu: clct_bxn_emu        = %1.1X\n",clct_bxn_emu);
			fprintf(log_file,"TMBemu: clct_bx0_emu        = %1.1X\n",clct_bx0_emu);
			fprintf(log_file,"TMBemu: csc_id_emu          = %1.1X\n",csc_id_emu);
			fprintf(log_file,"TMBemu: clct_sync_err_emu   = %1.1X\n",clct_sync_err_emu);
			fprintf(log_file,"\n");

			// LCT Quality
			alct0_hit_emu  = alct0_quality_emu + 3;				// Convert alct quality to number of hits
			alct1_hit_emu  = alct1_quality_emu + 3;

			clct0_cpat_emu = (clct0_hit_emu >= 2);
			clct1_cpat_emu = (clct1_hit_emu >= 2);

			ACC  = alct0_amu_emu;				// In	ALCT accelerator muon bit
			A    = alct0_valid_emu;				// In	bit: ALCT was found
			C    = clct0_valid_emu;				// In	bit: CLCT was found
			A4   = alct0_hit_emu>>2 & 0x1;		// In	bit (N_A>=4), where N_A=number of ALCT layers
			C4   = clct0_hit_emu>>2 & 0x1;		// In	bit (N_C>=4), where N_C=number of CLCT layers
			P    = clct0_pid_emu;				// In	4-bit CLCT pattern number that is presently 1 for n-layer triggers, 2-10 for current patterns, 11-15 "for future expansion".
			CPAT = clct0_cpat_emu;				// In	bit for cathode .pattern trigger., i.e. (P>=2 && P<=10) at present

			lct_quality (ACC, A, C, A4, C4, P, CPAT, Q);

			lct0_quality_emu = Q;

			ACC  = alct1_amu_emu;				// In	ALCT accelerator muon bit
			A    = alct1_valid_emu;				// In	bit: ALCT was found
			C    = clct1_valid_emu;				// In	bit: CLCT was found
			A4   = alct1_hit_emu>>2 & 0x1;		// In	bit (N_A>=4), where N_A=number of ALCT layers
			C4   = clct1_hit_emu>>2 & 0x1;		// In	bit (N_C>=4), where N_C=number of CLCT layers
			P    = clct1_pid_emu;				// In	4-bit CLCT pattern number that is presently 1 for n-layer triggers, 2-10 for current patterns, 11-15 "for future expansion".
			CPAT = clct1_cpat_emu;				// In	bit for cathode .pattern trigger., i.e. (P>=2 && P<=10) at present

			lct_quality (ACC, A, C, A4, C4, P, CPAT, Q);

			lct1_quality_emu = Q;

			// TMB is supposed to rank LCTs, but doesn't yet, this is a bug, should be after the mpc0_frame0_pulse section below
			tmb_rank_err_emu = (lct0_quality_emu*lct0_vpf_emu) < (lct1_quality_emu * lct1_vpf_emu);

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: tmb_rank_err_emu  = %4.1X\n",tmb_rank_err_emu);

			// TMBemu: Format MPC output words
			mpc0_frame0_emu =
				(alct0_key_emu    <<  0)	|
				(clct0_pid_emu    <<  7)	|
				(lct0_quality_emu << 11)	|
				(lct0_vpf_emu     << 15);

			mpc0_frame1_emu =
				(clct0_cfeb_emu<<5) | clct0_key_emu|
				(clct0_bend_emu       <<  8)	|
				(clct_sync_err_emu    <<  9)	|
				((alct0_bxn_emu & 0x1) << 10)	|
				((clct_bx0_emu  & 0x1) << 11)	|	// bx0 gets replaced after mpc_tx_delay, keep here to mollify xst
				((csc_id_emu    & 0xF) << 12);

			mpc1_frame0_emu =
				(alct1_key_emu    <<  0)	|
				(clct1_pid_emu    <<  7)	|
				(lct1_quality_emu << 11)	|
				(lct1_vpf_emu     << 15);

			mpc1_frame1_emu =
				(clct1_cfeb_emu<<5) | clct1_key_emu|
				(clct1_bend_emu       <<  8)	|
				(clct_sync_err_emu    <<  9)	|
				((alct1_bxn_emu & 0x1) << 10)	|
				((alct_bx0_emu  & 0x1) << 11)	|	// bx0 gets replaced after mpc_tx_delay, keep here to mollify xst
				((csc_id_emu    & 0xF) << 12);

			// TMBemu: Construct MPC output words for MPC, blanked if no muons present, except bx0 [inserted after mpc_tx_delay]
			trig_mpc_emu  = tmb_trig_pulse && tmb_trig_keep;				// Trigger this event
			trig_mpc0_emu = trig_mpc_emu && lct0_vpf_emu && !kill_clct0;	// LCT 0 is valid, send to mpc
			trig_mpc1_emu = trig_mpc_emu && lct1_vpf_emu && !kill_clct1;	// LCT 1 is valid, send to mpc

			mpc0_frame0_pulse = (trig_mpc0_emu) ? mpc0_frame0_emu : 0;
			mpc0_frame1_pulse = (trig_mpc0_emu) ? mpc0_frame1_emu : 0;
			mpc1_frame0_pulse = (trig_mpc1_emu) ? mpc1_frame0_emu : 0;
			mpc1_frame1_pulse = (trig_mpc1_emu) ? mpc1_frame1_emu : 0;

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: trig_mpc_emu         = %1.1X\n",trig_mpc_emu );
			fprintf(log_file,"TMBemu: trig_mpc0_emu        = %1.1X\n",trig_mpc0_emu);
			fprintf(log_file,"TMBemu: trig_mpc1_emu        = %1.1X\n",trig_mpc1_emu);

			fprintf(log_file,"\n");
			fprintf(log_file,"TMBemu: mpc0_frame0_pulse    = %4.4X\n",mpc0_frame0_pulse);
			fprintf(log_file,"TMBemu: mpc0_frame1_pulse    = %4.4X\n",mpc0_frame1_pulse);
			fprintf(log_file,"TMBemu: mpc1_frame0_pulse    = %4.4X\n",mpc1_frame0_pulse);
			fprintf(log_file,"TMBemu: mpc1_frame1_pulse    = %4.4X\n",mpc1_frame1_pulse);
			fprintf(log_file,"\n");

			// Read latched MPC data
			adr    = mpc0_frame0_adr+base_adr;
			status = vme_read(adr,rd_data);
			mpc0_frame0_vme = rd_data;

			adr    = mpc0_frame1_adr+base_adr;
			status = vme_read(adr,rd_data);
			mpc0_frame1_vme = rd_data;

			adr    = mpc1_frame0_adr+base_adr;
			status = vme_read(adr,rd_data);
			mpc1_frame0_vme = rd_data;

			adr    = mpc1_frame1_adr+base_adr;
			status = vme_read(adr,rd_data);
			mpc1_frame1_vme = rd_data;

			fprintf(log_file,"VME:    mpc0_frame0_vme      = %4.4X\n",mpc0_frame0_vme);
			fprintf(log_file,"VME:    mpc0_frame1_vme      = %4.4X\n",mpc0_frame1_vme);
			fprintf(log_file,"VME:    mpc1_frame0_vme      = %4.4X\n",mpc1_frame0_vme);
			fprintf(log_file,"VME:    mpc1_frame1_vme      = %4.4X\n",mpc1_frame1_vme);

			// TMBemu: Decompose expected MPC frames
			mpc_alct0_key_expect	=	(mpc0_frame0_pulse >>  0) & 0x007F;
			mpc_clct0_pid_expect	=	(mpc0_frame0_pulse >>  7) & 0x000F;
			mpc_lct0_qual_expect	=	(mpc0_frame0_pulse >> 11) & 0x000F;
			mpc_lct0_vpf_expect		=	(mpc0_frame0_pulse >> 15) & 0x0001;

			mpc_clct0_key_expect	=	(mpc0_frame1_pulse >>  0) & 0x00FF;
			mpc_clct0_bend_expect	=	(mpc0_frame1_pulse >>  8) & 0x0001;
			mpc_sync_err0_expect	=	(mpc0_frame1_pulse >>  9) & 0x0001;
			mpc_alct0_bxn_expect	=	(mpc0_frame1_pulse >> 10) & 0x0001;
			mpc_bx0_clct_expect		=	(mpc0_frame1_pulse >> 11) & 0x0001;
			mpc_csc_id0_expect		=	(mpc0_frame1_pulse >> 12) & 0x000F;

			mpc_alct1_key_expect	=	(mpc1_frame0_pulse >>  0) & 0x007F;
			mpc_clct1_pid_expect	=	(mpc1_frame0_pulse >>  7) & 0x000F;
			mpc_lct1_qual_expect	=	(mpc1_frame0_pulse >> 11) & 0x000F;
			mpc_lct1_vpf_expect		=	(mpc1_frame0_pulse >> 15) & 0x0001;

			mpc_clct1_key_expect	=	(mpc1_frame1_pulse >>  0) & 0x00FF;
			mpc_clct1_bend_expect	=	(mpc1_frame1_pulse >>  8) & 0x0001;
			mpc_sync_err1_expect	=	(mpc1_frame1_pulse >>  9) & 0x0001;
			mpc_alct1_bxn_expect	=	(mpc1_frame1_pulse >> 10) & 0x0001;
			mpc_bx0_alct_expect		=	(mpc1_frame1_pulse >> 11) & 0x0001;
			mpc_csc_id1_expect		=	(mpc1_frame1_pulse >> 12) & 0x000F;

			// Decompose MPC frames latched by VME
			mpc_alct0_key_vme		=	(mpc0_frame0_vme >>  0) & 0x007F;
			mpc_clct0_pid_vme		=	(mpc0_frame0_vme >>  7) & 0x000F;
			mpc_lct0_qual_vme		=	(mpc0_frame0_vme >> 11) & 0x000F;
			mpc_lct0_vpf_vme		=	(mpc0_frame0_vme >> 15) & 0x0001;

			mpc_clct0_key_vme		=	(mpc0_frame1_vme >>  0) & 0x00FF;
			mpc_clct0_bend_vme		=	(mpc0_frame1_vme >>  8) & 0x0001;
			mpc_sync_err0_vme		=	(mpc0_frame1_vme >>  9) & 0x0001;
			mpc_alct0_bxn_vme		=	(mpc0_frame1_vme >> 10) & 0x0001;
			mpc_bx0_clct_vme		=	(mpc0_frame1_vme >> 11) & 0x0001;
			mpc_csc_id0_vme			=	(mpc0_frame1_vme >> 12) & 0x000F;

			mpc_alct1_key_vme		=	(mpc1_frame0_vme >>  0) & 0x007F;
			mpc_clct1_pid_vme		=	(mpc1_frame0_vme >>  7) & 0x000F;
			mpc_lct1_qual_vme		=	(mpc1_frame0_vme >> 11) & 0x000F;
			mpc_lct1_vpf_vme		=	(mpc1_frame0_vme >> 15) & 0x0001;

			mpc_clct1_key_vme		=	(mpc1_frame1_vme >>  0) & 0x00FF;
			mpc_clct1_bend_vme		=	(mpc1_frame1_vme >>  8) & 0x0001;
			mpc_sync_err1_vme		=	(mpc1_frame1_vme >>  9) & 0x0001;
			mpc_alct1_bxn_vme		=	(mpc1_frame1_vme >> 10) & 0x0001;
			mpc_bx0_alct_vme		=	(mpc1_frame1_vme >> 11) & 0x0001;
			mpc_csc_id1_vme			=	(mpc1_frame1_vme >> 12) & 0x000F;

			// Compare expected to found MPC frames
			ck("mpc: mpc_alct0_key  read vme.expect tmbemu ",mpc_alct0_key_vme	,mpc_alct0_key_expect);	
			ck("mpc: mpc_clct0_pid  read vme.expect tmbemu ",mpc_clct0_pid_vme	,mpc_clct0_pid_expect);
			ck("mpc: mpc_lct0_qual  read vme.expect tmbemu ",mpc_lct0_qual_vme	,mpc_lct0_qual_expect);
			ck("mpc: mpc_lct0_vpf   read vme.expect tmbemu ",mpc_lct0_vpf_vme	,mpc_lct0_vpf_expect);

			ck("mpc: mpc_clct0_key  read vme.expect tmbemu ",mpc_clct0_key_vme	,mpc_clct0_key_expect);
			ck("mpc: mpc_clct0_bend read vme.expect tmbemu ",mpc_clct0_bend_vme	,mpc_clct0_bend_expect);
			ck("mpc: mpc_sync_err0  read vme.expect tmbemu ",mpc_sync_err0_vme	,mpc_sync_err0_expect);
			ck("mpc: mpc_alct0_bxn  read vme.expect tmbemu ",mpc_alct0_bxn_vme	,mpc_alct0_bxn_expect);
			ck("mpc: mpc_bx0_clct   read vme.expect tmbemu ",mpc_bx0_clct_vme	,0);
			ck("mpc: mpc_csc_id0    read vme.expect tmbemu ",mpc_csc_id0_vme	,mpc_csc_id0_expect);

			ck("mpc: mpc_alct1_key  read vme.expect tmbemu ",mpc_alct1_key_vme	,mpc_alct1_key_expect);
			ck("mpc: mpc_clct1_pid  read vme.expect tmbemu ",mpc_clct1_pid_vme	,mpc_clct1_pid_expect);
			ck("mpc: mpc_lct1_qual  read vme.expect tmbemu ",mpc_lct1_qual_vme	,mpc_lct1_qual_expect);
			ck("mpc: mpc_lct1_vpf   read vme.expect tmbemu ",mpc_lct1_vpf_vme	,mpc_lct1_vpf_expect);

			ck("mpc: mpc_clct1_key  read vme.expect tmbemu ",mpc_clct1_key_vme	,mpc_clct1_key_expect);
			ck("mpc: mpc_clct1_bend read vme.expect tmbemu ",mpc_clct1_bend_vme	,mpc_clct1_bend_expect);
			ck("mpc: mpc_sync_err1  read vme.expect tmbemu ",mpc_sync_err1_vme	,mpc_sync_err1_expect);
			ck("mpc: mpc_alct1_bxn  read vme.expect tmbemu ",mpc_alct1_bxn_vme	,mpc_alct1_bxn_expect);
			ck("mpc: mpc_bx0_alct   read vme.expect tmbemu ",mpc_bx0_alct_vme	,0);
			ck("mpc: mpc_csc_id1    read vme.expect tmbemu ",mpc_csc_id1_vme	,mpc_csc_id1_expect);

			// LCTs for display
			lct0_vme = (mpc0_frame1_vme<<16) | mpc0_frame0_vme;
			lct1_vme = (mpc1_frame1_vme<<16) | mpc1_frame0_vme;

			// Marker state indicats CLCTs found by TMB match injected CLCTs for display
			marker = "ER";

			if (clct0_vpf_vme == clct0_vpf_vme_expect &&
					clct0_hit_vme == clct0_hit_vme_expect &&
					clct0_pid_vme == clct0_pid_vme_expect &&
					clct0_key_vme == clct0_key_vme_expect &&
					clct1_vpf_vme == clct1_vpf_vme_expect &&
					clct1_hit_vme == clct1_hit_vme_expect &&
					clct1_pid_vme == clct1_pid_vme_expect &&
					clct1_key_vme == clct1_key_vme_expect)
				marker = "OK";

			// Display CLCTs
			fprintf(stdout,"Key=%3i %s ",ikeylp,marker.c_str());
			fprintf(stdout,"clct0: vpf=%1i nhit=%1i pid=%1X key=%3i  ",clct0_vpf_tmb, clct0_hit_tmb, clct0_pid_tmb, clct0_key_tmb);
			fprintf(stdout,"clct1: vpf=%1i nhit=%1i pid=%1X key=%3i  ",clct1_vpf_tmb, clct1_hit_tmb, clct1_pid_tmb, clct1_key_tmb);
			fprintf(stdout,"lct0=%8.8X ", lct0_vme);
			fprintf(stdout,"lct1=%8.8X\n",lct1_vme);

			// Log write CLCT0 and CLCT1
			fprintf(log_file,"CFEB%1i Key=%3i %s ",icfeb,ikeylp,marker.c_str());
			fprintf(log_file,"clct0: vpf=%1i nhit=%1i pid=%1X key=%3i cfeb=%1i bxn=%1i  ",clct0_vpf_tmb, clct0_hit_tmb,  clct0_pid_tmb, clct0_key_tmb, clct0_cfeb_tmb, clctc_bxn_tmb);
			fprintf(log_file,"clct1: vpf=%1i nhit=%1i pid=%1X key=%3i cfeb=%1i bxn=%1i  ",clct1_vpf_tmb, clct1_hit_tmb,  clct1_pid_tmb, clct1_key_tmb, clct1_cfeb_tmb, clctc_bxn_tmb);
			fprintf(log_file,"alct0: vpf=%1i qual=%1X amu=%1i key=%3i bxn=%1i   ",        alct0_vpf_inj, alct0_qual_inj, alct0_amu_inj, alct0_key_inj, alct0_bxn_inj);
			fprintf(log_file,"alct1: vpf=%1i qual=%1X amu=%1i key=%3i bxn=%1i   ",        alct1_vpf_inj, alct1_qual_inj, alct1_amu_inj, alct1_key_inj, alct1_bxn_inj);
			fprintf(log_file,"lct0=%8.8X ", lct0_vme);
			fprintf(log_file,"lct1=%8.8X\n",lct1_vme);

			// Summary write CLCT0 and CLCT1
			fprintf(sum_file,"CFEB%1i Key=%3i %s ",icfeb,ikeylp,marker.c_str());
			fprintf(sum_file,"clct0: vpf=%1i nhit=%1i pid=%1X key=%3i cfeb=%1i bxn=%1i  ",clct0_vpf_tmb, clct0_hit_tmb,  clct0_pid_tmb, clct0_key_tmb, clct0_cfeb_tmb, clctc_bxn_tmb);
			fprintf(sum_file,"clct1: vpf=%1i nhit=%1i pid=%1X key=%3i cfeb=%1i bxn=%1i  ",clct1_vpf_tmb, clct1_hit_tmb,  clct1_pid_tmb, clct1_key_tmb, clct1_cfeb_tmb, clctc_bxn_tmb);
			fprintf(sum_file,"alct0: vpf=%1i qual=%1X amu=%1i key=%3i bxn=%1i   ",        alct0_vpf_inj, alct0_qual_inj, alct0_amu_inj, alct0_key_inj, alct0_bxn_inj);
			fprintf(sum_file,"alct1: vpf=%1i qual=%1X amu=%1i key=%3i bxn=%1i   ",        alct1_vpf_inj, alct1_qual_inj, alct1_amu_inj, alct1_key_inj, alct1_bxn_inj);
			fprintf(sum_file,"lct0=%8.8X ", lct0_vme);
			fprintf(sum_file,"lct1=%8.8X\n",lct1_vme);

			// Display CLCT keys generated vs found
			if (first_scn) {	// Display column heading, show 1/2 strip numbers 0-159
				fprintf(scn_file,"CLCT_sep=%3i",clct_sep);
				fprintf(scn_file,"                         ");
				fprintf(scn_file,"<------------------------------ CLCT key 1/2strips found by TMB ------------------------------->\n");

				fprintf(scn_file,"     "); for (i=0; i<=159; ++i) {symbol=' '; if (i%32<14||i%32>18) fprintf(scn_file,"%c",symbol); if (i%32==14) fprintf(scn_file,"CFEB%1i",i/32);}  fprintf(scn_file,"\n");
				fprintf(scn_file,"     "); for (i=0; i<=159; ++i) {symbol='-'; if (i%32==0||i%32==31) symbol='|'; fprintf(scn_file,"%c",symbol);}  fprintf(scn_file,"\n");
				fprintf(scn_file,"     "); for (i=0; i<=159; ++i) {symbol=' '; if (i>=100) symbol='0'+(i/100)%10; fprintf(scn_file,"%c",symbol);}  fprintf(scn_file,"\n");
				fprintf(scn_file,"     "); for (i=0; i<=159; ++i) {symbol=' '; if (i>= 10) symbol='0'+(i/10 )%10; fprintf(scn_file,"%c",symbol);}  fprintf(scn_file,"\n");
				fprintf(scn_file,"     "); for (i=0; i<=159; ++i) {symbol=' '; if (i>=  0) symbol='0'+(i/1  )%10; fprintf(scn_file,"%c",symbol);}  fprintf(scn_file,"\n");
				first_scn=false;
			}

			symbol=' ';															// display row heading
			if (ikey%32==0||ikey%32==31) symbol='-';
			fprintf(scn_file,"%c%c%3i",symbol,symbol,ikey);

			for (i=0; i<=159; ++i) {
				symbol=' '; 
				if ((1 << (i/32) & active_feb_list)!=0)symbol='.';					// cfeb is in the active feb list

				if (clct0_vpf_tmb==1 && clct0_key_tmb==i) symbol='0'+clct0_hit_tmb;	// clct0 hits 0-6
				if (clct1_vpf_tmb==1 && clct1_key_tmb==i) symbol='A'+clct1_hit_tmb;	// clct1 hits A-G
				if (clct0_vpf_tmb==1 && clct0_key_tmb==i  &&
						clct1_vpf_tmb==1 && clct1_key_tmb==i) symbol='X';				// clct0 and clct1 on the same key, should not happen

				fprintf(scn_file,"%c",symbol);
			} 
			fprintf(scn_file,"\n");										// cr on current ikey line

			if (ikey==159) {											// partial column headings again after last row
				fprintf(scn_file,"     "); for (i=0; i<=159; ++i) {symbol=' '; if (i>=  0) symbol='0'+(i/1  )%10; fprintf(scn_file,"%c",symbol);}  fprintf(scn_file,"\n");
			}

			// Get DMB RAM word count and busy bit
			if (!rrhd) goto L16708;

			adr    = dmb_wdcnt_adr+base_adr;
			status = vme_read(adr,rd_data);
			dmb_wdcnt = rd_data & 0x0FFF;
			dmb_busy  = (rd_data >> 14) & 0x0001;

			fprintf(log_file,"Raw Hits Dump: ikey=%3i\n",ikey);
			fprintf(log_file,"word count = %4i\n",dmb_wdcnt);
			fprintf(log_file,"busy       = %4i\n",dmb_busy);

			if (dmb_busy) {
				fprintf(log_file,"Can not read RAM: dmb reports busy\n");
				fprintf(stdout,  "Can not read RAM: dmb reports busy\n");
				goto L16708;
			}

			if (dmb_wdcnt <= 0) {
				fprintf(log_file,"Can not read RAM: dmb reports word count <=0\n");
				fprintf(stdout,  "Can not read RAM: dmb reports word count <=0\n");
				goto L16708;
			}

			// Write RAM read address to TMB
			for (i=0; i<=dmb_wdcnt-1; ++i) {
				adr     = dmb_ram_adr+base_adr;
				wr_data = i & 0xffff;
				status  = vme_write(adr,wr_data);

				// Read RAM data from TMB
				adr    = dmb_rdata_adr+base_adr;
				status = vme_read(adr,rd_data);				// read lsbs
				dmb_rdata_lsb = rd_data;

				adr    = dmb_wdcnt_adr+base_adr;
				status = vme_read(adr,rd_data);				// read msbs
				dmb_rdata_msb = (rd_data >> 12) & 0x3;		// rdata msbs
				dmb_rdata     = dmb_rdata_lsb | (dmb_rdata_msb << 16);

				vf_data[i]=dmb_rdata;
				fprintf(log_file,"Adr=%5i Data=%6.5X\n",i,dmb_rdata);
			} // close i

			// Clear RAM address for next event
			adr     = dmb_ram_adr+base_adr;
			wr_data = 0x2000;	// reset RAM write address
			status  = vme_write(adr,wr_data);
			wr_data = 0x0000;	// unreset
			status  = vme_write(adr,wr_data);

			// Decode raw hits dump, variables passed by common block struct
			decode_readout(vf_data,dmb_wdcnt,err_check=true);

			dprintf(stdout,"Non-zero triad bits=%i\n",nonzero_triads);

			// Take snapshot of current counter state
L16708:
			adr = base_adr+cnt_ctrl_adr;
			wr_data=0x0022;	//snap
			status = vme_write(adr,wr_data);
			wr_data=0x0020;	//unsnap
			status = vme_write(adr,wr_data);

			// Read counters
			for (i=0; i<mxcounter; ++i) {
				for (j=0; j<=1; ++j) {
					adr = base_adr+cnt_ctrl_adr;
					wr_data=(i << 9) | 0x0020 | (j << 8);
					status = vme_write(adr,wr_data);
					adr = base_adr+cnt_rdata_adr;
					status = vme_read(adr,rd_data);

					// Combine lsbs+msbs
					if (j==0)			// Even addresses contain counter LSBs
						cnt_lsb=rd_data;
					else {				// Odd addresses contain counter MSBs
						cnt_msb=rd_data;
						cnt_full=cnt_lsb | (cnt_msb << 16);
						cnt[i]=cnt_full;	// Assembled counter MSB,LSB
					}
				}}	//close j,i

			// Dislay counters
			for (i=0; i<mxcounter; ++i) {
				fprintf(log_file,"\t%2.2i %10i %s\n",i,cnt[i],scnt[i].c_str());
			}

			// Read back embedded scope data
			scp_arm        = false;
			scp_readout    = true;
			scp_raw_decode = false;
			scp_silent     = true;
			scp_playback   = false;
			if (rdscope && scp_auto==0)
				scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

			// Close big key-stepping loops
			if (pause_on_fail) pause("<cr> to resume");
		}	// L16709 continue
	}	// L16710 continue
	//	}	// L16730 continue

	// Set pattern thresholds back to default
	adr    = seq_clct_adr+base_adr;
	status = vme_read(adr,rd_data);

	hit_thresh_pretrig_temp   = hit_thresh_pretrig;
	hit_thresh_postdrift_temp = hit_thresh_postdrift;

	wr_data = rd_data & 0x8000;		// clear hit_thresh,nph_pattern,drift
	wr_data = wr_data | (triad_persist             <<  0);
	wr_data = wr_data | (hit_thresh_pretrig_temp   <<  4);
	wr_data = wr_data | (dmb_thresh_pretrig        <<  7);
	wr_data = wr_data | (hit_thresh_postdrift_temp << 10);
	wr_data = wr_data | (drift_delay               << 13);
	status  = vme_write(adr,wr_data);

	// Bang mode
	if (ifunc < 0)
	{
		sleep(1500);
		goto L16705;
	}
	goto L1600;

	//------------------------------------------------------------------------------
	//	External Trigger ALCT+CLCT
	//------------------------------------------------------------------------------
L16800:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, enable L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0005;
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Select sequencer to take clct ext or alct ext trig
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0060;		// Select alct or clct ext trig mode
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Fire pseudo-CCB external clct trigger linked to alct
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0014;		// fire clct ext trig
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0xFFE7;		// unfire
	status  = vme_write(adr,wr_data);

	// Read back trigger register to see what triggered
	adr     = seq_trig_src_adr+base_adr;
	status  = vme_read(adr,rd_data);

	if (rd_data!=0x0020) printf("\tTrigger source error rd_data=%4.4X\n",rd_data);

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope && scp_auto==0)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Loop mode
	if (ifunc<0) {
		//	sleep (1500);
		goto L16800;
	}

	goto L1600;

	//------------------------------------------------------------------------------
	//	External Trigger ALCT
	//------------------------------------------------------------------------------
L16900:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, enable L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0005;
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Select sequencer to take clct ext or alct ext trig
	adr      = seq_trig_en_adr+base_adr;
	status   = vme_read(adr,rd_data);
	wr_data  = rd_data & 0xFF00;
	wr_data  = wr_data | 0x0060;	// Select alct or clct ext trig mode
	status   = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Fire pseudo-CCB external trigger alct
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x000C;		// fire alct ext trig
	//	wr_data = rd_data | 0x0014;		// fire clct ext trig !!!!TEMPORARY !!!!!!
	status = vme_write(adr,wr_data);
	wr_data = rd_data | 0xFFF3;	// unfire
	status = vme_write(adr,wr_data);

	// Read back trigger register to see what triggered
	adr    = seq_trig_src_adr+base_adr;
	status = vme_read(adr,rd_data);

	if (rd_data!=0x0040) printf("\tTrigger source error rd_data=%4.4X\n",rd_data);

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope && scp_auto==0)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Loop mode
	if (ifunc<0) {
		//	sleep (1500);
		goto L16900;
	}
	goto L1600;

	//------------------------------------------------------------------------------
	//	External Trigger CLCT
	//------------------------------------------------------------------------------
L96000:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, enable L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0005;
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;	// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;	// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Select sequencer to take clct ext, turn on all cfebs
	adr     = seq_trig_en_adr+base_adr;
	wr_data = 0x0220;
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Fire pseudo-CCB external trigger clct
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	//	wr_data = rd_data | 0x000C;		// fire alct ext trig
	wr_data = rd_data | 0x0014;		// fire clct ext trig
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0xFFE3;		// unfire
	status  = vme_write(adr,wr_data);

	// Read back trigger register to see what triggered
	adr    = seq_trig_src_adr+base_adr;
	status = vme_read(adr,rd_data);

	if (rd_data!=0x0020) printf("\tTrigger source error rd_data=%4.4X\n",rd_data);

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope && scp_auto==0)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Loop mode
	if (ifunc<0) {
		//	sleep(1500);
		goto L96000;
	}
	goto L1600;

	//------------------------------------------------------------------------------
	//	External Trigger ALCT+CLCT with GTL pulser
	//------------------------------------------------------------------------------
L96100:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0005;
	status  = vme_write(adr,wr_data);

	// Enable GTL ccb_clct_ext_trig
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0040;
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Select sequencer to take clct ext or alct ext trig
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0060;	// Select alct or clct ext trig mode
	status  = vme_write(adr,wr_data);

	// Turn on sequencer internal L1A
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x1000;
	status  = vme_write(adr,wr_data);

	// Fire CCB external clct trigger with pulse generator
	pause("Connect GTL pulse generator to P2A D10, monitor TP382-6");

	// Set start_trigger state for FMM
	adr     = base_adr+ccb_cmd_adr;

	ttc_cmd = 6;			// start_trigger
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data =0x0001;
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope && scp_auto==0)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	goto L1600;

	//------------------------------------------------------------------------------
	//	External Trigger ALCT+CLCT with GTL pulser, check CRC
	//------------------------------------------------------------------------------
L96200:
	first_event = true;

	if (ifunc<0) {
		rdscope = false;
		rdraw   = false;
	}
	else {
		rdscope = true;
		rdraw   = true;
	}

	// Turn off CCB backplane inputs
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0005;
	status  = vme_write(adr,wr_data);

	// Enable GTL ccb_clct_ext_trig
	adr     = ccb_trig_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0040;
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Select sequencer to take clct ext or alct ext trig
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0060;		// Select alct or clct ext trig mode
	status  = vme_write(adr,wr_data);

	// Turn on sequencer internal L1A
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x1000;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	adr     = base_adr+ccb_cmd_adr;

	ttc_cmd = 6;			// start_trigger
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data =0x0001;
	status  = vme_write(adr,wr_data);

	// Fire CCB external clct trigger with pulse generator
	pause("Connect GTL pulse generator to P2A D10, monitor TP382-6");

	// Event loop option
	//L96210:

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Get DMB RAM word count and busy bit
	if (!rdraw) goto L96220;

	adr       = dmb_wdcnt_adr+base_adr;
	status    = vme_read(adr,rd_data);
	dmb_wdcnt = rd_data & 0x0FFF;
	dmb_busy  = (rd_data>>14) & 0x0001;

	fprintf(log_file,"\tword count = %4i\n",dmb_wdcnt);
	fprintf(log_file,"\tbusy       = %4i\n",dmb_busy );

	if (dmb_busy==1) {
		fprintf(log_file,"\tCan not read RAM: dmb reports busy\n");
		goto L96211;
	}
	if (dmb_wdcnt<=0) {
		fprintf(log_file,"\tCan not read RAM: dmb reports word count <=0");
		goto L96211;
	}

	// Write RAM read address to TMB
L96211:
	for (i=0; i<=dmb_wdcnt-1; ++i) {
		adr     = dmb_ram_adr+base_adr;
		wr_data = i & 0xFFFF;
		status  = vme_write(adr,wr_data);

		// Read RAM data from TMB
		adr    = dmb_rdata_adr+base_adr;
		status = vme_read(adr,rd_data);			// read lsbs
		dmb_rdata_lsb = rd_data;

		adr    = dmb_wdcnt_adr+base_adr;
		status = vme_read(adr,rd_data);			// read msbs

		dmb_rdata_msb = (rd_data>>12) & 0x3;	// rdata msbs
		dmb_rdata     = dmb_rdata_lsb | (dmb_rdata_msb<<16);

		vf_data[i]=dmb_rdata;
		fprintf(log_file,"\tAdr=%4i Data=%5.5X\n",i,dmb_rdata);
	}	// close for i

	// Clear RAM address for next event
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	// reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Read back embedded scope data
L96220:
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope && scp_auto==0)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Decode raw hits dump
	decode_readout(vf_data,dmb_wdcnt,err_check=false);

	goto L1600;

	//------------------------------------------------------------------------------
	//	Test BXN Counter
	//------------------------------------------------------------------------------
L96300:
	if (ifunc<0) rdscope = false;
	else         rdscope = true;

	// Turn off CCB backplane inputs, turn on L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x003D;
	status  = vme_write(adr,wr_data);

	// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (114<<8);
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0005;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | 0x0003;
	status  = vme_write(adr,wr_data);

	// Turn off CLCT cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;	// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;	// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0FFF;
	status  = vme_write(adr,wr_data);

	// Select pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_data = rd_data & 0xFF00;
	wr_data = rd_data | 0x0001;
	status  = vme_write(adr,wr_data);

	// Clear previous ALCT inject
	adr=alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFD;
	status  = vme_write(adr,wr_data);

	// Set l1reset, which takes FMM to stop trigger
	ttc_cmd = 3;		// l1reset
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data =0x0001;
	status  = vme_write(adr,wr_data);

	// Check FMM machine is in stop_trigger state after l1reset
	adr     = base_adr+ccb_cmd_adr;
	status	= vme_read(adr,rd_data);
	fmm_state = (rd_data >> 4) & 0x0007;

	if (fmm_state!=2) pause("FMM failed to go to stop_trigger");

	// Set FMM start_trigger (wait for bx0) after l1reset
	ttc_cmd=6;		// start_trigger

	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Check FMM machine is waiting for bx0 after start trigger
	adr     = base_adr+ccb_cmd_adr;
	status	= vme_read(adr,rd_data);
	fmm_state = (rd_data>>4) & 0x0007;

	if (fmm_state!=3) pause("FMM failed to go to fmm_wait_bx0");

	// Set FMM to start_trigger by sending bx0
	ttc_cmd = 1;
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Check FMM machine is in start_trigger state
	adr     = base_adr+ccb_cmd_adr;
	status	= vme_read(adr,rd_data);
	fmm_state = (rd_data>>4) & 0x0007;

	if (fmm_state!=4) pause("FMM failed to go to start_trigger");

	// Send some triggers, expect bxn stays at 0 1st pass, rarely 0 2nd pass
	ntrig = 100;

	for (ipass=1; ipass<=2; ++ipass)
	{
		nbxn0 = 0;

		for (i=1; i<=ntrig; ++i)
		{

			// Clear previous  CLCT inject
			adr     = cfeb_inj_adr+base_adr;
			status  = vme_read(adr,rd_data);
			wr_data = rd_data & 0x7FFF;
			status  = vme_write(adr,wr_data);

			// Fire CLCT Injector
			wr_data = wr_data | 0x8000;
			status  = vme_write(adr,wr_data);

			// Clear previous inject	
			wr_data = rd_data & 0x7FFF;	
			status  = vme_write(adr,wr_data);

			// Read back latched CLCT bxn
			adr    = seq_clctm_adr+base_adr;
			status = vme_read(adr,rd_data);
			clctc_vme = (rd_data >> 0) & 0x0007;

			// Check bxn is always 0
			clctc_bxn_vme  =  clctc_vme & 0x0003;		// Bunch crossing number

			if (clctc_bxn_vme==0) nbxn0++;
			fprintf(log_file,"\tPass %5i bxn=%5i\n",ipass,clctc_bxn_vme);
		} // close for ntrig

		fprintf(log_file,"\tBXN was 0 %4i/%4i times\n",nbxn0,ntrig);

		// Set FMM bxn after l1reset to resume bxn counting
		ttc_cmd = 1;		// bx0
		adr     = base_adr+ccb_cmd_adr;
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);
		wr_data = 0x0003 | (ttc_cmd<<8);
		status  = vme_write(adr,wr_data);
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);

		// Close loops
	}	// close for  ipass

	if (ifunc>0) goto L96300;
	goto L1600;

	//------------------------------------------------------------------------------
	//	Fire L1A-only event check short  or long header readout
	//------------------------------------------------------------------------------
L96400:
	// Get current fifo_mode, l1a_lookback, hdr_wr_continuous, scope
	adr    = base_adr+seq_fifo_adr;
	status = vme_read(adr,rd_data);

	fifo_mode		= (rd_data >> 0) & 0x07;	// 3 bits
	fifo_tbins		= (rd_data >> 3) & 0x1F;	// 5 bits
	fifo_pretrig	= (rd_data >> 8) & 0x1F;	// 5 bits
	if (fifo_tbins==0) fifo_tbins=32;

	adr    = base_adr+l1a_lookback_adr;
	status = vme_read(adr,rd_data);
	l1a_lookback = (rd_data & 0x07FF);

	adr    = base_adr+seqmod_adr;
	status = vme_read(adr,rd_data);
	hdr_wr_continuous = (rd_data >> 5) & 0x1;

	adr    = base_adr+scp_ctrl_adr;
	status = vme_read(adr,rd_data);
	scp_auto   =(rd_data >> 3) & 0x1;			// 1 bit
	scp_nowrite=(rd_data >> 4) & 0x1;			// 1 bit
	scp_tbins  =(rd_data >> 5) & 0x7;			// 3 bits

	// Display CLCT fifo mode reminder
	printf("\n");
	printf("\tfifo_mode=0:  Dump=No    Header=Full \n");
	printf("\tfifo_mode=1:  Dump=Full  Header=Full \n");
	printf("\tfifo_mode=2:  Dump=Local Header=Full \n");
	printf("\tfifo_mode=3:  Dump=No    Header=Short\n");
	printf("\tfifo_mode=4:  Dump=No    Header=No   \n");
	printf("\n");

	// Inquire
	printf("\tFifo_mode           ? cr=%3i",fifo_mode);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) fifo_mode=i;

	printf("\tTbins               ? cr=%3i",fifo_tbins);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) fifo_tbins=i;

	printf("\tTbins before pretrig? cr=%3i",fifo_pretrig);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) fifo_pretrig=i;

	printf("\tL1A_lookback        ? cr=%3i",l1a_lookback);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) l1a_lookback=i;

	printf("\tHdr_wr_continuous   ? cr=%3i",hdr_wr_continuous);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) hdr_wr_continuous=i;

	printf("\tFire CLCT injectors ? cr=%3i",fire_injector);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) fire_injector=true;

	printf("\tScope tbins/64      ? cr=%3i",scp_tbins);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) scp_tbins=i; 

	// Non-inquire defaults
	alct_injector_delay	= 14;
	l1a_delay			= 119;
	alct_delay			= 4;
	clct_width			= 3;
	tmb_allow_clct		= 1;
	tmb_allow_match		= 1;
	pid_thresh_pretrig	= 0;
	pid_thresh_postdrift= 0;
	adjcfeb_dist		= 5;
	clct_sep			= 10;
	active_feb_src		= 0;
	rat_sync_mode		= 0;

	triad_persist		= 6;
	dmb_thresh_pretrig	= 1;
	hit_thresh_pretrig	= 1;
	hit_thresh_postdrift= 1;
	drift_delay			= 2;

	// Turn off CFEB cable inputs
L96405:
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;		// mask_all=5'b00000
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);

	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0005;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;			// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;			// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (l1a_delay << 8);
	status  = vme_write(adr,wr_data);

	// Set L1A lookback
	adr     = base_adr+l1a_lookback_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & ~0x07FF;
	wr_data = wr_data | (l1a_lookback << 0);
	status  = vme_write(adr,wr_data);

	// Set readout machine to respond to unexpected L1As
	adr    = seqmod_adr+base_adr;
	status = vme_read(adr,rd_data);		// current ccb reg state

	wr_data = (rd_data | 0x0200);		// turn on l1a_allow_notmb bit 9
	status  = vme_write(adr,wr_data);

	// Set new hdr_wr_continuous
	adr    = base_adr+seqmod_adr;
	status = vme_read(adr,rd_data);
	wr_data = rd_data & ~0x0020;
	wr_data = wr_data | (hdr_wr_continuous << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CCB backplane inputs, turn on L1A emulator, do this after turning off cfeb and alct cable inputs
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x0000;
	wr_data = wr_data | 0x0001;	// ccb_ignore_rx
	//	wr_data = wr_data | 0x0004;	// ccb_int_l1a_en
	wr_data = wr_data | 0x0008;	// ccb_status_oe_vme
	wr_data = wr_data | 0x0010;	// alct_status_en
	wr_data = wr_data | 0x0020;	// clct_status_en
	status  = vme_write(adr,wr_data);

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | (alct_delay << 0);
	wr_data = wr_data | (clct_width << 4);
	status  = vme_write(adr,wr_data);

	// Set tmb_match mode
	adr     = base_adr+tmb_trig_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE7;		// clear bits 4,3
	wr_data = wr_data | (tmb_allow_clct  << 3);
	wr_data = wr_data | (tmb_allow_match << 4);
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer, set l1a window width
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x00FF;
	wr_data = wr_data | 0x0300;			//  l1a window width
	status  = vme_write(adr,wr_data);

	// Set fifo tbins
	adr     = base_adr+seq_fifo_adr;
	status  = vme_read(adr,rd_data);	// get current
	wr_data = rd_data & 0xF000;			// clear lower bits

	wr_data=wr_data
		| ((fifo_mode    & 0x07) << 0)		// [2:0]
		| ((fifo_tbins   & 0x1F) << 3)		// [7:3]
		| ((fifo_pretrig & 0x1F) << 8);		// [12:8]

	status = vme_write(adr,wr_data);

	// Set pid_thresh_pretrig, pid_thresh_postdrift
	adr    = temp0_adr+base_adr;
	status = vme_read(adr,rd_data);

	wr_data=rd_data & 0xFC03;
	wr_data=wr_data | (pid_thresh_pretrig   << 2);	// 4 bits
	wr_data=wr_data | (pid_thresh_postdrift << 6);	// 4 bits

	status = vme_write(adr,wr_data);

	// Set adjcfeb_dist
	adr     = temp0_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;			// adjcfeb_dist[5:0] is in [15:10]
	wr_data = wr_data | (adjcfeb_dist << 10);
	status  = vme_write(adr,wr_data);

	// Set CLCT separation
	adr     = temp1_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x00FF;
	wr_data = wr_data | (clct_sep << 8);
	status  = vme_write(adr,wr_data);

	// Set active_feb_list source
	adr     = seqmod_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & ~(1 << 14);
	wr_data = wr_data | (active_feb_src << 14);
	status  = vme_write(adr,wr_data);

	// Set RAT out of sync mode
	adr     = vme_ratctrl_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFE;
	wr_data = wr_data | rat_sync_mode;
	status  = vme_write(adr,wr_data);

	// Select clct pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0001;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	adr     = base_adr+ccb_cmd_adr;

	ttc_cmd = 3;			// l1reset
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 6;			// start_trigger
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data =0x0001;
	status  = vme_write(adr,wr_data);

	// Lower pattern threshold temporarily so edge key 1/2-strips will trigger, set it back later
	adr    = seq_clct_adr+base_adr;
	status = vme_read(adr,rd_data);

	wr_data = rd_data & 0x8000;	// clear hit_thresh,nph_pattern,drift
	wr_data = wr_data | (triad_persist             <<  0);
	wr_data = wr_data | (hit_thresh_pretrig        <<  4);
	wr_data = wr_data | (dmb_thresh_pretrig        <<  7);
	wr_data = wr_data | (hit_thresh_postdrift      << 10);
	wr_data = wr_data | (drift_delay               << 13);
	status  = vme_write(adr,wr_data);

	// Set scope-in-readout
	adr     = base_adr+scp_ctrl_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF07;	 // clear bits 3,4,5,6,7
	wr_data = wr_data | (scp_auto    << 3);
	wr_data = wr_data | (scp_nowrite << 4);
	wr_data = wr_data | (scp_tbins   << 5);
	status  = vme_write(adr,wr_data);

	// Arm scope trigger
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;
	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Prepare to fire L1A
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);		// current ccb reg state

	wr_data = (rd_data & ~0x0040);			// turn off l1a oneshot bit 6 in case it was on
	status  = vme_write(adr,wr_data);

	wr_fire_l1a = (rd_data | 0x0040);		// ready to fire bit 6 l1a oneshot;

	// Fire CLCT+ALCT Injectors
	fprintf(log_file,"\nFiring injectors for L1A-only event\n");

	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x8000;				// fire injector
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0x7FFF;				// unfire
	status  = vme_write(adr,wr_data);

	// Fire L1A
	adr     = ccb_cfg_adr+base_adr;
	wr_data = wr_fire_l1a;
	status  = vme_write(adr,wr_data);		// fire L1A

	status  = vme_read(adr,rd_data);		// current ccb reg state
	wr_data = (rd_data & ~0x0040);			// turn off l1a oneshot
	status  = vme_write(adr,wr_data);

	// Wait for DMB readout to complete
	sleep(1);

	// Get DMB RAM word count and busy bit
	adr    = dmb_wdcnt_adr+base_adr;
	status = vme_read(adr,rd_data);
	dmb_wdcnt = rd_data & 0x0FFF;
	dmb_busy  = (rd_data >> 14) & 0x0001;

	fprintf(log_file,"Raw Hits Dump: L1A-only event\n");
	fprintf(log_file,"word count = %4i\n",dmb_wdcnt);
	fprintf(log_file,"busy       = %4i\n",dmb_busy);

	if (dmb_busy) {
		fprintf(log_file,"Can not read RAM: dmb reports busy\n");
		fprintf(stdout,  "Can not read RAM: dmb reports busy\n");
		goto L96708;
	}

	if (dmb_wdcnt <= 0) {
		fprintf(log_file,"Can not read RAM: dmb reports word count <=0\n");
		fprintf(stdout,  "Can not read RAM: dmb reports word count <=0\n");
		goto L96708;
	}

	// Write RAM read address to TMB
	for (i=0; i<=dmb_wdcnt-1; ++i) {
		adr     = dmb_ram_adr+base_adr;
		wr_data = i & 0xffff;
		status  = vme_write(adr,wr_data);

		// Read RAM data from TMB
		adr    = dmb_rdata_adr+base_adr;
		status = vme_read(adr,rd_data);				// read lsbs
		dmb_rdata_lsb = rd_data;

		adr    = dmb_wdcnt_adr+base_adr;
		status = vme_read(adr,rd_data);				// read msbs
		dmb_rdata_msb = (rd_data >> 12) & 0x3;		// rdata msbs
		dmb_rdata     = dmb_rdata_lsb | (dmb_rdata_msb << 16);

		vf_data[i]=dmb_rdata;
		fprintf(log_file,"Adr=%5i Data=%6.5X\n",i,dmb_rdata);
	} // close i

	// Clear RAM address for next event
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	// reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Decode raw hits dump, variables passed by common block struct
	decode_readout(vf_data,dmb_wdcnt,err_check=false);

	// Scanning for non-zero triads
	fprintf(log_file,"l1a_lookback=%4i\n",l1a_lookback);
	fprintf(stdout,"\tl1a_lookback=%4i  ",l1a_lookback);
	fprintf(stdout,"Non-zero triad bits=%4i ",nonzero_triads);
	lookback_triad_hits[l1a_lookback%2048]=nonzero_triads;
	if (ifunc<0) l1a_lookback++;

	// Read sequencer Debug register
	for (seqdeb_adr=0; seqdeb_adr<=1; ++seqdeb_adr) {
		adr     = seq_debug_adr+base_adr;
		wr_data = seqdeb_adr;
		status  = vme_write(adr,wr_data);	// write sub adr
		status  = vme_read (adr,rd_data);	// read data
		seqdeb_rd_mux = (rd_data >> 4);		// Extract mux data

		switch (seqdeb_adr) {
			case 0x0: deb_wr_buf_adr	= seqdeb_rd_mux; break;	// [10:0]	Buffer write address at last pretrig
			case 0x1: deb_buf_push_adr	= seqdeb_rd_mux; break;	// [10:0]	Queue push address at last push
		}}
	deb_adr_diff = abs(long(deb_buf_push_adr-deb_wr_buf_adr));

	printf("push_adr-pretrig_adr=%8.4X\n",deb_adr_diff);

	// Take snapshot of current counter state
L96708:
	adr = base_adr+cnt_ctrl_adr;
	wr_data=0x0022;	//snap
	status = vme_write(adr,wr_data);
	wr_data=0x0020;	//unsnap
	status = vme_write(adr,wr_data);

	// Read counters
	for (i=0; i<mxcounter; ++i) {
		for (j=0; j<=1; ++j) {
			adr = base_adr+cnt_ctrl_adr;
			wr_data=(i << 9) | 0x0020 | (j << 8);
			status = vme_write(adr,wr_data);
			adr = base_adr+cnt_rdata_adr;
			status = vme_read(adr,rd_data);

			// Combine lsbs+msbs
			if (j==0)			// Even addresses contain counter LSBs
				cnt_lsb=rd_data;
			else {				// Odd addresses contain counter MSBs
				cnt_msb=rd_data;
				cnt_full=cnt_lsb | (cnt_msb << 16);
				cnt[i]=cnt_full;	// Assembled counter MSB,LSB
			}
		}}	//close j,i

	// Dislay counters
	for (i=0; i<mxcounter; ++i) {
		fprintf(log_file,"\t%2.2i %10i %s\n",i,cnt[i],scnt[i].c_str());
	}

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;
	if (rdscope && scp_auto==0)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Bang mode
	if (ifunc >= 0) goto L1600;

	sleep(1);

	// End of bang scan, look for nonzero triads
	//	if (l1a_lookback < 2048) goto L96405;	// Full range of lookbacks
	if (l1a_lookback <  800) goto L96405;	// Shorten cuz we know its in range of 600 to 700

	first_nonzero_bx = 0;
	last_nonzero_bx  = 0;
	max_triads       = 0;

	for (i=0; i<=2047; ++i) {
		if (lookback_triad_hits[i] !=0) {
			if (first_nonzero_bx==0) first_nonzero_bx=i;
			if (lookback_triad_hits[i] > max_triads) max_triads=lookback_triad_hits[i];
			last_nonzero_bx = i;
		}}

	if (first_nonzero_bx!=0) {
		printf("\n");
		printf("\tfirst nonzero triad at l1a_lookback = %i\n",first_nonzero_bx);
		printf("\tlast  nonzero triad at l1a_lookback = %i\n",last_nonzero_bx);
		printf("\tpeak triad bits                     = %i\n",max_triads);
		printf("\n");
		pause ("<cr> to finish display");
	}
	else {
		printf("\tOh noes! I can has no triads =:-(.\n");
		goto L1600;
	}

	// Display lookback values that have nonzero triads
	first_bx = _cpp_max(first_nonzero_bx-10,0);
	last_bx  = _cpp_min(last_nonzero_bx+10,2047);
	scale    = 50./float(max_triads);

	for (i=first_bx; i<= last_bx; ++i) {
		printf("lookback%4ibx %3i triads|",i,lookback_triad_hits[i]);
		if (lookback_triad_hits[i]>0) for (j=0; j<=lookback_triad_hits[i]*scale; ++j) printf("x");
		printf("\n");
	}

	// Done
	goto L1600;

	//------------------------------------------------------------------------------
	//	Forced CLCT trigger and readout
	//------------------------------------------------------------------------------
L96500:
	icfeb=1;
	display_cfeb=true;

	// Get current cfeb tbins
	adr    = base_adr+seq_fifo_adr;
	status = vme_read(adr,rd_data);

	fifo_mode		= (rd_data >> 0) & 0x07;	// 3 bits
	fifo_tbins		= (rd_data >> 3) & 0x1F;	// 5 bits
	fifo_pretrig	= (rd_data >> 8) & 0x1F;	// 5 bits
	if (fifo_tbins==0) fifo_tbins=32;

	// Turn off CCB backplane inputs, turn on L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x003D;
	status  = vme_write(adr,wr_data);

	// Enable l1a on sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (l1a_delay << 8);
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0005;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | 0x0003;
	status  = vme_write(adr,wr_data);

	// Turn on all CFEB inputs so we can check for crosstalk
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	wr_data = wr_data | 0x001F;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer, set l1a window width
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x00FF;
	wr_data = wr_data | 0x0300;		// l1a window width
	status  = vme_write(adr,wr_data);

	// Turn off CLCT pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	status  = vme_write(adr,wr_data);

	// Clear previous ALCT inject
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFD;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;			// start_trigger
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Clear DMB RAM write-address
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	//reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Fire VME trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data	= wr_data | (1 << 7);	// fire vme trigger
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0xFF00;		// unfire vme trigger
	status  = vme_write(adr,wr_data);

	// Wait for TMB to read out to DMB
	sleep(1);

	// Get DMB RAM word count and busy bit
	adr       = dmb_wdcnt_adr+base_adr;
	status    = vme_read(adr,rd_data);
	dmb_wdcnt = rd_data & 0x0FFF;
	dmb_busy  = (rd_data >> 14) & 0x0001;

	printf("\tdmb word count = %4i\n",dmb_wdcnt);
	printf("\tdmb busy       = %4i\n",dmb_busy);

	if (dmb_busy  != 0) pause ("Can not read RAM: dmb reports busy");
	if (dmb_wdcnt <= 0) pause ("Can not read RAM: dmb reports word count <=0");

	pause("<cr> to process dump");

	// Write RAM read address to TMB
	for (iadr=0; iadr<=dmb_wdcnt-1; ++iadr) {
		adr     = dmb_ram_adr+base_adr;
		wr_data = iadr & 0xFFFF;
		status  = vme_write(adr,wr_data);

		// Read RAM data from TMB
		adr    = dmb_rdata_adr+base_adr;
		status = vme_read(adr,rd_data);			// read lsbs
		dmb_rdata_lsb=rd_data;

		adr    = dmb_wdcnt_adr+base_adr;
		status = vme_read(adr,rd_data);			// read msbs
		dmb_rdata_msb = (rd_data >> 12) & 0x3;	// rdata msbs

		dmb_rdata = dmb_rdata_lsb | (dmb_rdata_msb << 16);
		vf_data[iadr]=dmb_rdata;

		dprintf(log_file,"Adr=%4i Data=%5.5X\n",iadr,dmb_rdata);
	}	// close iadr

	// Clear RAM address for next event
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	// reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Point to start of CFEB data
	iframe     = 5;
	r_nheaders = vf_data[iframe] & 0x3F;					// Number of header words
	adr_e0b    = r_nheaders;

	fprintf(log_file,"r_nheaders=%i\n",r_nheaders);
	if (adr_e0b <=0) pause ("Unreasonable nheaders");

	iframe=19;
	r_ncfebs=			(vf_data[iframe] >>  0) & 0x7;		// Number of CFEBs read out
	r_fifo_tbins=		(vf_data[iframe] >>  3) & 0x1F;		// Number of time bins per CFEB in dump

	fprintf(log_file,"r_fifo_tbins=%i\n",r_fifo_tbins);
	if (r_fifo_tbins<=0) pause ("Unreasonable ntbins");

	// Copy triad bits to a holding array
	iframe = adr_e0b+1;										// First raw hits frame for cfeb0
	//	iframe = iframe + icfeb*(r_fifo_tbins*6);				// First frame for icfeb

	for (jcfeb  = 0; jcfeb  <= r_ncfebs-1;     ++jcfeb ) {	// Loop over all cfebs so we can see crosstalk
		for (itbin  = 0; itbin  <= r_fifo_tbins-1; ++itbin ) {	// Loop over time bins
			for (ilayer = 0; ilayer <= mxly-1;         ++ilayer) {	// Loop over layers

				rdcid  = (vf_data[iframe] >> 12) & 0x7;					// CFEB ID in the dump
				rdtbin = (vf_data[iframe] >>  8) & 0xF;					// Tbin number in the dump
				hits8  =  vf_data[iframe]        & 0xFF;				// 8 triad block

				for (ids=0; ids< mxds; ++ids) {							// Loop over hits per block
					hits1=(hits8 >> ids) & 0x1;								// Extract 1 hit
					ids_abs=ids+jcfeb*8;									// Absolute distrip id
					read_pat[itbin][ilayer][ids_abs]=hits1;					// hit this distrip
					if (hits1 != 0) nonzero_triads++;						// Count nonzero triads
					dprintf(log_file,"iframe=%4i vf_data=%5.5X hits8=%i jcfeb=%i itbin=%i ids_abs=%i hits1=%i\n",iframe,vf_data[iframe],hits8,jcfeb,itbin,ids_abs,hits1);
				}														// Close ids
				iframe++;												// Next frame
			}														// Close for ilayer
		}														// Close for itbin
	}														// Close for jcfeb

	// Display cfeb and ids column markers
	if (display_cfeb) {
		fprintf(log_file,"\n");
		fprintf(log_file,"     Raw Hits Triads\n");

		fprintf(log_file,"Cfeb-");
		for (jcfeb=0; jcfeb < mxcfeb; ++jcfeb) { fprintf(log_file,"%|"); // display cfeb columms
			for (ids=0;   ids   < mxds;   ++ids  )   fprintf(log_file,"%1.1i",jcfeb);}
		fprintf(log_file,"|\n");

		fprintf(log_file,"Ds---");
		for (jcfeb=0; jcfeb < mxcfeb; ++jcfeb) { fprintf(log_file,"%|",x);	// display ids columns
			for (ids=0;   ids   < mxds;   ++ids  )   fprintf(log_file,"%1.1i",ids%10);}
		fprintf(log_file,"|\n");
		fprintf(log_file,"Ly Tb\n");

		// Display CFEB raw hits
		for (ilayer=0; ilayer <= mxly-1;         ++ilayer)        {
			for (itbin=0;  itbin  <= r_fifo_tbins-1; ++itbin ) { fprintf(log_file,"%1i %2i ",ilayer,itbin);

				for (ids_abs=0;ids_abs<=39;++ids_abs) {
					if (ids_abs%8==0) {fprintf(log_file,"|");}
					fprintf(log_file,"%1.1i",read_pat[itbin][ilayer][ids_abs]);
				}	// close for ids_abs
				fprintf(log_file,"|\n");
			}	// close itbin
			fprintf(log_file,"\n");
		}	// close ilayer

	}	// close display cfeb
	goto L1600;
}
//------------------------------------------------------------------------------
//	MPC Test Sub-Menu
//------------------------------------------------------------------------------
void L1700() {
L1700:

	if (firmware_type != firmware_normal) {
		printf("\n\tTMB has wrong firmware type for this operation\n");
		printf("\tContinue anyway? <cr>=n ");
		gets(line);
		if (line[0]==NULL) return;
	}

	// Turn off CCB backplane inputs, enable L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0005;
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0001;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;	// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;	// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Display submenu
	printf("\t   MPC Test Menu\n");
	printf("\t 1:  Test Injector RAM\n");
	printf("\t 2:  MPC Injector\n");
	printf("\t 3:  MPC Accept\n");
	printf("\t 4:  MPC Injector Counter\n");
	printf("\t 5:  Fire alct_bx0 to MPC\n");
	printf("\t 6:  Fire clct_bx0 to MPCg\n");
	printf("\t<cr> Exit\n");
	printf("       > ");

	gets(line);
	if (line[0]==NULL) return;
	sscanf(line,"%i",&ifunc);
	i=abs(ifunc);

	if (i== 1) goto L17100;
	if (i== 2) goto L17200;
	if (i== 3) goto L17300;
	if (i== 4) goto L17400;
	if (i== 5) goto L17500;
	if (i== 6) goto L17600;
	goto L1700;

	//------------------------------------------------------------------------------
	//	Test MPC Injector RAM
	//------------------------------------------------------------------------------
L17100:
	nwrites=0;
	nerrors=0;

	// Write random pattern to all RAM banks
	srand(1);
	for (iram=0; iram<=3;   ++iram) {
		for (iadr=0; iadr<=255; ++iadr) {

			// Write ram data register
			adr	    = mpc_ram_wdata_adr+base_adr;
			rnd     = rand()/(float(RAND_MAX)+1); 
			wr_data = int(65536*rnd) & 0x0000FFFF;
			status  = vme_write(adr,wr_data);

			// Write ram address
			adr     = mpc_ram_adr+base_adr;
			wr_data = (iadr << 8);
			status  = vme_write(adr,wr_data);

			// Assert write enable
			wr_data = wr_data| (1 << iram);
			status  = vme_write(adr,wr_data);

			// De-Assert write enable
			wr_data = wr_data & 0xFF00;
			status  = vme_write(adr,wr_data);
		}	// close iadr
	}	// close iram

	// Read back random pattern
	srand(1);
	for (iram=0; iram<=3;   ++iram) {
		for (iadr=0; iadr<=255; ++iadr) {

			// Write ram address + assert read enable
			adr     = mpc_ram_adr+base_adr;
			wr_data = (iadr << 8) | (1 << (iram+4));
			status  = vme_write(adr,wr_data);

			// Read RAM data
			adr    = mpc_ram_rdata_adr+base_adr;
			status = vme_read(adr,rd_data);

			rnd     = rand()/(float(RAND_MAX)+1); 
			wr_data = int(65536*rnd) & 0x0000FFFF;
			nwrites++;
			if (rd_data != wr_data) {
				nerrors++;
				printf("Error iram=%1i adr=%3i wr=%4.4X rd=%4.4X\n",iram,iadr,wr_data,rd_data);
			}	// close if
		}	// close iadr
	}	// close iram

	printf("Nwrites=%6i Nerrors=%6i\n",nwrites,nerrors);
	pause("<cr> to continue");
	goto L1700;

	//------------------------------------------------------------------------------
	//	MPC Injector
	//------------------------------------------------------------------------------
L17200:
	// Get muon data to transmit to MPC and number of 25ns frames
	nfdef=1;
	m0def=0xBBBBAAAA;
	m1def=0xDDDDCCCC;

	printf("\tNumber frames[03:00] <cr=%3.3i> ",nfdef);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&nframes);

	if (n<=0) nframes=nfdef;
	if (nframes>255) goto L17200;

	for (i=0; i<=nframes-1; ++i) {
		printf("Frame %3i Muon0[31:0] hex <cr=%8.8X> ",m0def);
		gets(line);
		n=strlen(line);
		sscanf(line,"%X",&muon0[i]);
		if (n<=0) muon0[i]=m0def;

		printf("Frame %3i Muon1[31:0] hex <cr=%8.8X> ",m1def);
		gets(line);
		n=strlen(line);
		sscanf(line,"%X",&muon1[i]);
		if (n<=0) muon1[i]=m1def;
	}	// close nframes


	// Write muon data to all RAM banks
	for (iadr=0; iadr<=nframes-1; ++iadr) {

		mpc_ram_wrdata[0]=(muon0[iadr] >>  0) & 0x0000FFFF;		// muon0[15:00]
		mpc_ram_wrdata[1]=(muon0[iadr] >> 16) & 0x0000FFFF;		// muon0[31:16]
		mpc_ram_wrdata[2]=(muon1[iadr] >>  0) & 0x0000FFFF;		// muon1[15:00]
		mpc_ram_wrdata[3]=(muon1[iadr] >> 16) & 0x0000FFFF;		// muon1[31:16]

		for (iram=0; iram<=3; ++iram) {

			// Write ram data register
			adr	    = mpc_ram_wdata_adr+base_adr;
			wr_data = mpc_ram_wrdata[iram];
			status  = vme_write(adr,wr_data);

			// Write ram address
			adr     = mpc_ram_adr+base_adr;
			wr_data = (iadr << 8);
			status  = vme_write(adr,wr_data);

			// Assert write enable
			wr_data = wr_data | (1 << iram);
			status  = vme_write(adr,wr_data);

			// De-Assert write enable
			wr_data = wr_data & 0xFF00;
			status  = vme_write(adr,wr_data);
		}	// close iram
	}	// close iadr

	// Read back RAM banks and compare
	for (iadr=0; iadr<=nframes-1; ++iadr) {

		mpc_ram_wrdata[0]=(muon0[iadr] >>  0) & 0x0000FFFF;		// muon0[15:00]
		mpc_ram_wrdata[1]=(muon0[iadr] >> 16) & 0x0000FFFF;		// muon0[31:16]
		mpc_ram_wrdata[2]=(muon1[iadr] >>  0) & 0x0000FFFF;		// muon1[15:00]
		mpc_ram_wrdata[3]=(muon1[iadr] >> 16) & 0x0000FFFF;		// muon1[31:16]

		for (iram=0; iram<=3; ++iram) {

			// Write ram address + assert read enable
			adr     = mpc_ram_adr+base_adr;
			wr_data = (iadr << 8) | (1 << (iram+4));
			status  = vme_write(adr,wr_data);

			// Read RAM data
			adr    = mpc_ram_rdata_adr+base_adr;
			status = vme_read(adr,rd_data);

			// Verify RAM
			wr_data=mpc_ram_wrdata[iram];
			if (rd_data!=wr_data) printf("Error  frame %3i iram=%1i adr=%3i wr=%4.4X rd=%4.4X\n",iadr,iram,iadr,wr_data,rd_data);
			else				  printf("Verify frame %3i iram=%1i adr=%3i wr=%4.4X rd=%4.4X\n",iadr,iram,iadr,wr_data,rd_data);
		}	// close iram
	}	// close iadr

	// Fire MPC Injector
L17210:
	adr     = mpc_inj_adr+base_adr;
	wr_data = 0;					// [08]=0 UnFire injector
	wr_data = wr_data | nframes;	// [07:00]=nframes
	status  = vme_write(adr,wr_data);

	wr_data = wr_data | (1 << 8);	// [08]=1 Fire injector
	status  = vme_write(adr,wr_data);

	wr_data = wr_data & 0xFEFF;		// [08]=0 UnFire injector
	status  = vme_write(adr,wr_data);

	if (ifunc < 0) goto L17210;
	goto L1700;

	//------------------------------------------------------------------------------
	//	MPC Accept
	//------------------------------------------------------------------------------
L17300:
	//	Set up loop back
	pause ("Connect _mpc_rx[0] P3A-A9 to _mpc_tx[0] P3A-A1:");

	// Walk a 1 bit deeper in time
L17310:
	nframes=256;
	for (itbin=0; itbin<=nframes-1; ++itbin) {

		// Write muon data to all RAM banks
		for (iadr=0; iadr<=nframes-1; ++iadr) {

			wr_data  =0;
			wr_marker=0;

			if (iadr==itbin)wr_data  =1;
			if (iadr==0    )wr_marker=1;

			mpc_ram_wrdata[0]=wr_data;		// muon0[15:00]
			mpc_ram_wrdata[1]=wr_marker;	// muon0[31:16]
			mpc_ram_wrdata[2]=0;			// muon1[15:00]
			mpc_ram_wrdata[3]=0;			// muon1[31:16]

			for (iram=0; iram<=3; ++iram) {

				// Write ram data register
				adr	    = mpc_ram_wdata_adr+base_adr;
				wr_data = mpc_ram_wrdata[iram];
				status  = vme_write(adr,wr_data);

				// Write ram address
				adr     = mpc_ram_adr+base_adr;
				wr_data = (iadr << 8);
				status  = vme_write(adr,wr_data);

				// Assert write enable
				wr_data = wr_data | (1 << iram);
				status  = vme_write(adr,wr_data);

				// De-Assert write enable
				wr_data = wr_data & 0xFF00;
				status  = vme_write(adr,wr_data);
			}	//	close iram
		}	//	close iadr

		// Fire MPC Injector
		adr     = mpc_inj_adr+base_adr;
		wr_data = 0;					// [08]=0 UnFire injector
		wr_data = wr_data | 255;		// [07:00]=nframes
		status  = vme_write(adr,wr_data);

		wr_data = wr_data | (1 << 8);	// [08]=1 Fire injector
		status  = vme_write(adr,wr_data);

		wr_data = wr_data | nframes;	// [07:00]=nframes
		status  = vme_write(adr,wr_data);

		// Read back all mpc_accept tbins
		for (iadr=0; iadr<=nframes-1; ++iadr) {

			// Write mpc_accept RAM address
			adr     = mpc_ram_adr+base_adr;
			wr_data = (iadr << 8);
			status  = vme_write(adr,wr_data);

			// Read mpc_accept bits
			adr    = mpc_inj_adr+base_adr;
			status = vme_read(adr,rd_data);
			mpc_accept0	  = (rd_data >>  9) & 0x1;
			mpc_accept1   = (rd_data >> 10) & 0x1;
			mpc_reserved0 = (rd_data >> 11) & 0x1;
			mpc_reserved1 = (rd_data >> 12) & 0x1;

			// Compare to walking 1
			if (ifunc>0) printf("\t%5i%5i  %1i%1i%1i%1i\n",itbin,iadr,mpc_accept0,mpc_accept1,mpc_reserved0,mpc_reserved1); 

		}	//	close iadr
	}	//	close itbin

	// Bang mode
	if (ifunc<0) goto L17310;
	goto L1700;

	//------------------------------------------------------------------------------
	//	Test MPC Injector Counter
	//------------------------------------------------------------------------------
L17400:
	nfdef=1;

	printf("\tNumber frames[03:00] <cr=%3.3i> ",nfdef);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&nframes);

	if (n<=0) nframes=nfdef;
	if (nframes>255) goto L17400;

	if (n<=0) nframes=nfdef;

	// Load muon image for full injector cycle, counts 0,1,2,3 at 80MHz on mpc_tx[0]
	for (iadr=0; iadr<=255; ++iadr) {
		muon0[iadr]=(2*iadr  ) | ((2*iadr)  << 16);	// muon0[15:00],muon0[31:16]
		muon1[iadr]=(2*iadr+1) | ((2*iadr+1) <<16);	// muon1[15:00],muon1[31:16]
	}

	// Write muon data to all RAM banks
	for (iadr=0; iadr<=nframes-1; ++iadr) {
		mpc_ram_wrdata[0]=(muon0[iadr] >>  0) & 0x0000FFFF;	// muon0[15:00]
		mpc_ram_wrdata[1]=(muon0[iadr] >> 16) & 0x0000FFFF;	// muon0[31:16]
		mpc_ram_wrdata[2]=(muon1[iadr] >>  0) & 0x0000FFFF;	// muon1[15:00]
		mpc_ram_wrdata[3]=(muon1[iadr] >> 16) & 0x0000FFFF;	// muon1[31:16]

		for (iram=0; iram<=3; ++iram) {
			// Write ram data register
			adr	    = mpc_ram_wdata_adr+base_adr;
			wr_data = mpc_ram_wrdata[iram];
			status  = vme_write(adr,wr_data);

			// Write ram address
			adr     = mpc_ram_adr+base_adr;
			wr_data = (iadr << 8);
			status  = vme_write(adr,wr_data);

			// Assert write enable
			wr_data = wr_data | (1 << iram);
			status  = vme_write(adr,wr_data);

			// De-Assert write enable
			wr_data = wr_data & 0xFF00;
			status  = vme_write(adr,wr_data);
		}	// close iadr
	}	// close iram

	// Read back RAM banks and compare
	for (iadr=0; iadr<=nframes-1; ++iadr) {

		mpc_ram_wrdata[0]=(muon0[iadr] >>  0) & 0x0000FFFF;	// muon0[15:00]
		mpc_ram_wrdata[1]=(muon0[iadr] >> 16) & 0x0000FFFF;	// muon0[31:16]
		mpc_ram_wrdata[2]=(muon1[iadr] >>  0) & 0x0000FFFF;	// muon1[15:00]
		mpc_ram_wrdata[3]=(muon1[iadr] >> 16) & 0x0000FFFF;	// muon1[31:16]

		for (iram=0; iram<=3; ++iram) {

			// Write ram address + assert read enable
			adr     = mpc_ram_adr+base_adr;
			wr_data = (iadr << 8) | (1 << (iram+4));
			status  = vme_write(adr,wr_data);

			// Read RAM data
			adr    = mpc_ram_rdata_adr+base_adr;
			status = vme_read(adr,rd_data);

			// Verify RAM
			wr_data = mpc_ram_wrdata[iram];
			if (rd_data!=wr_data) printf("Error  frame %3i iram=%1i adr=%3i wr=%4.4X rd=%4.4X\n",iadr,iram,iadr,wr_data,rd_data);
			else				  printf("Verify frame %3i iram=%1i adr=%3i wr=%4.4X rd=%4.4X\n",iadr,iram,iadr,wr_data,rd_data);

		}	// close iram
	}	// close iadr

	// Fire MPC Injector
L17410:
	adr     = mpc_inj_adr+base_adr;
	wr_data = 0;						// [08]=0 UnFire injector
	wr_data = wr_data | nframes;		// [07:00]=nframes
	status  = vme_write(adr,wr_data);

	wr_data = wr_data| (1 << 8);		// [08]=1 Fire injector
	status  = vme_write(adr,wr_data);

	wr_data = wr_data & 0xFEFF;			// [08]=0 UnFire injector
	status  = vme_write(adr,wr_data);

	if (ifunc<0) goto L17410;
	goto L1700;

	// Fire alct_bx0 Injector
L17500:
	adr     = alct_inj_adr+base_adr;	// turn off alct_rx inputs
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0001;
	status  = vme_write(adr,wr_data);

	adr    = bx0_delay_adr+base_adr	;	// get current bx0 delays
	status = vme_read(adr,rd_data);
	alct_bx0_delay=(rd_data >> 0) & 0x000F;
	clct_bx0_delay=(rd_data >> 4) & 0x000F;

	printf("\talct_bx0_delay=%2i ",alct_bx0_delay);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) alct_bx0_delay=i;

L17510:
	adr     = mpc_inj_adr+base_adr;
	wr_data = 0;						// [14]=0 UnFire injector
	wr_data = wr_data | (1 << 14);		//  [14]=1 Fire injector
	status = vme_write(adr,wr_data);

	wr_data = wr_data & 0xBFFF;			// [14]=0 UnFire injector
	status  = vme_write(adr,wr_data);

	if (ifunc<0) goto L17510;
	goto L1700;

	// Fire clct_bx0 Injector
L17600:
	adr    = bx0_delay_adr+base_adr;
	status = vme_read(adr,rd_data);
	alct_bx0_delay=(rd_data >> 0) & 0x000F;
	clct_bx0_delay=(rd_data >> 4) & 0x000F;

	printf("\tclct_bx0_delay=%2i ",clct_bx0_delay);
	gets(line);
	n=strlen(line);
	sscanf(line,"%i",&i);
	if (n!=0) clct_bx0_delay=i;

L17610:
	adr     = mpc_inj_adr+base_adr;
	wr_data = 0;						// [15]=0 UnFire injector
	wr_data = wr_data | (1 << 15);		// [15]=1 Fire injector
	status  = vme_write(adr,wr_data);

	wr_data = wr_data & 0x7FFF;			// [15]=0 UnFire injector
	status  = vme_write(adr,wr_data);

	// Bang mode
	if (ifunc<0) goto L17610;
	goto L1700;
}
//------------------------------------------------------------------------------
//	Full Auto Test:
//	Test TMB in right-hand backplane slot
//------------------------------------------------------------------------------
//	vme_loopbk_adr=E assigments for TMB2005
//
//  0	cfeb_oe
//  1	alct_loop
//  2	alct_rxoe
//  3	alct_txoe
//
//  4	rpc_loop
//  5	rpc_loop_tmb
//  6	loop_dummy
//  7	dmb_loop
//
//  8	_dmb_oe
//  9	gtl_loop
// 10	_gtl_oe
// 11	_ccb_status_oe

//------------------------------------------------------------------------------
//	TMB Full Auto Test:
//	Determine VME slots to use, check for reference TMB
//------------------------------------------------------------------------------
void L1800() {
L1800:

	debug_loop    = false;
	debug_step    = false;
	debug_beep    = false;
	pause_on_fail = true;

	printf("\tTMB Tests Started on host %s\n",scomputer_name.c_str());

	if ((scomputer_name.compare("X34"  )==0)	// We be on my old PC, use slots 5,6
			||  (scomputer_name.compare("P8P67")==0)) {	// We be on my new PC, use slots 5,6
		islot_ref = 27;								// Loopback board left  slot
		islot_dut = 6;}								// Loopback board right slot
	else {										// We be on your PC, use slots 7,8
		islot_ref = 27;
		islot_dut = 8;
	}

	if (fpga_series=="XC6VLX195T") {			// We must be in a Wiener crate beco Virtex6 uses too much power for my crate
		islot_ref = 27;
		islot_dut = 8;
	}

	// Base addresses for both TMBs
	base_adr_ref    = (islot_ref << 19);
	boot_adr_ref    = base_adr_ref | 0x070000;

	base_adr_dut    = (islot_dut << 19);
	boot_adr_dut    = base_adr_dut | 0x070000;

	base_adr        = base_adr_dut;
	boot_adr        = boot_adr_dut;

	base_adr_global = (tmb_global_slot << 19);
	boot_adr_global = base_adr_global | 0x070000;

	// Check for log file environment variable
	lenv = 81;
	lenv = ExpandEnvironmentStrings("%TMB_LogFolder%",tmb_logfolder,lenv);
	logfolder = string(tmb_logfolder);

	if (lenv==0 || logfolder.compare("%TMB_LogFolder%")==0) {
		printf("\n");
		printf("\tSystem Environment Variable TMB_LogFolder not defined.\n");
		printf("\tSuggest you set TMB_LogFolder=D:\\TMB2005\\Testlogs\\ in System Properties/Advanced\n");
		printf("\tChanges take effect after reboot or user logoff/logon\n");
		printf("\n");}
	else {
		printf("\tEnvironment variable TMB_LogFolder=%s\n",tmb_logfolder);
	}

	// Explain TMB types expected
	if (fpga_series=="XC6SLX150")	// Spartan-6 FPGA
	{
		id_month_expect = 0x0005;		// hex      date codes for TMB test firmware
		id_day_expect   = 0x0024;
		id_year_expect  = 0x2012;

		id_rev_month_expect = 05;		// decimal  date codes for TMB test firmware
		id_rev_day_expect   = 24;
		id_rev_year_expect  = 12;
		id_rev_fpga_expect	= 03;
	}
	else							// Virtex-2 FPGA
	{
		id_month_expect = 0x0011;		// hex      date codes for TMB test firmware
		id_day_expect   = 0x0019;
		id_year_expect  = 0x2009;

		id_rev_month_expect = 11;		// decimal  date codes for TMB test firmware
		id_rev_day_expect   = 19;
		id_rev_year_expect  =  9;
		id_rev_fpga_expect	= 04;
	}


	if (fpga_series=="XC6VLX195T") id_rev_fpga_expect=6;

	printf("\tExpect Referece TMB in slot=%2i with Debug firmware and Hex SH62=LCL, SW2/1=VME Adr=27=0x1B\n",islot_dut-1);
	printf("\tExpect Test     TMB in slot=%2i with Debug firmware and Hex SH62=GEO, SW2/1=VME Adr=26=0x1A\n",islot_dut);
	printf("\tExpect Test     TMB to have SH105 set to 2-3 else FPGA may not load from PROMs\n");
	printf("\tExpect Debug    Firmware version=%2.2X/%2.2X/%4.4X\n",id_month_expect,id_day_expect,id_year_expect);

	// Check for reference TMB in left slot
	tmb_ref_exists = false;
	tmb_ref_skip   = false;

	adr    = base_adr_ref+vme_idreg_adr;				// Try to read LCL Adr=27 id register
	status = vme_read(adr,rd_data);
	if (status!=0) goto L1801;							// Tisn't there, ref board is prolly not set to LCL and Adr=27

	adr    = base_adr_ref+vme_dsn_adr;
	itype  = 0;
	dsn_rd(adr,itype,dsn);
	dow_crc(dsn,icrc);

	if (icrc==dsn[7] && icrc!=0) tmb_ref_exists=true;	// ref board exists

	// Read ref boot register expected in slot 27
	boot = 0;
	if (tmb_ref_exists) {
		adr    = (27 << 19)+tmb_boot_adr;
		rd_data= -1;	
		status = vme_read(adr,rd_data);
		boot   = rd_data;
		printf("\tReference TMB boot data =%4.4X\n",boot);
		boot = rd_data & 0x4000;	// usually c000, but high bit is tdo, unpredictable
	}

L1801:
	if (tmb_ref_exists)
	{
		printf("\tTMB Reference Board   in slot %2i-LCL dsn=",islot_ref);
		for (i=5; i>0; i--) printf("%2.2X",dsn[i]);
		printf("\n");

		if (boot!=0x4000 || status!=0) {
			pause("\tYou must set SW2/1 LCL VME Adr=27 on Reference TMB");
			printf("\tTMB will not pass\n");
			printf("\tContinue anyway? <Y/N cr=no> ");

			gets(line);
			n=strlen(line);
			i=line[0];
			if ((n==0) || ((i!='Y') && (i!='y'))) return;
			tmb_ref_skip = true;
		}}

	else {
		printf("\tTMB Reference Board NOT found in slot %2i-LCL or wrong firmware type\n",islot_ref);
		printf("\tDid you set SH62=LCL, SW2/1=VME Adr=27=0x1B?\n");
		printf("\tCFEB tests will be skipped\n");
		printf("\tTMB will not pass\n");
		printf("\tContinue anyway? <Y/N cr=no> ");

		gets(line);
		n=strlen(line);
		i=line[0];
		if ((n==0) || ((i!='Y') && (i!='y'))) return;
		tmb_ref_skip = true;
	}

	// Check reference TMB firmware is DEBUG version
	adr    = base_adr_ref;
	status = vme_read(adr,rd_data);
	firmware_type_ref = rd_data & 0xF;

	if (firmware_type_ref!=firmware_debug) {
		tmb_ref_exists = false;
		printf("\n\tReference TMB has wrong firmware type %1.1X\n",firmware_type_ref);
		if (!tmb_ref_skip) goto L1801;
	}

	// Check if DUT board exists, get its DSN
	adr    = base_adr_dut+vme_idreg_adr;				// Try to read GEO id register
	status = vme_read(adr,rd_data);

	if (status!=0) {									// Tisn't there, dut board missing or dead
		printf("\tStarting tests on TMB in slot %2i-GEO: idreg not readable\n",islot_dut);
		pause("Check SH105 is set to 2-3 to prevent CCB hard reset");
		goto L18012;
	}

	// Get dut board DSN
	adr   = base_adr_dut+vme_dsn_adr;
	itype = 0;
	dsn_rd(adr,itype,dsn);
	dow_crc(dsn,icrc);

	printf("\tStarting tests on TMB in slot %2i-GEO dsn=",islot_dut);
	for (i=5; i>0; i--) printf("%2.2X",dsn[i]);
	printf("\n");

	//------------------------------------------------------------------------------
	//	TMB Full Auto Test:
	//	Get board ID + Digital Serial Number
	//------------------------------------------------------------------------------
L18012:
	for (i=1; i<=tmb_ntests; ++i) {
		tmb_npassed[i]  = 0;
		tmb_nfailed[i]  = 0;
		tmb_nskipped[i] = 0;
	}

	printf("\n");
	printf("\tExpected TMB settings:\n");
	printf("\tSH95  2-3  [prevents CCB Boot Reg clear]\n");
	printf("\tSH105 2-3  [prevents CCB hard reset    ]\n");
	printf("\tSH501 CCB  [selects  CCB clock source  ]\n");
	printf("\tSH62  GEO  [selects  SW1/2 VME address ]\n");
	printf("\tSW1/2 0x1A [selects  Global slot 26d   ]\n");
	printf("\n");
	printf("\tEnter TMB Board ID Number [5xxx]: ");

	gets(line);
	n = strlen(line);
	sscanf(line,"%i",&i);

	if (n> 0) tmb_board_id = i;
	if (n<=0) tmb_board_id = 5000;

	if (tmb_board_id==5000)
		printf("\tUsing default board ID 5000\n");

	if (tmb_board_id>5600 || tmb_board_id<2001) {
		pause("\tBoard ID must be 2001-5600");
		goto L1800;
	}

	//------------------------------------------------------------------------------
	//	TMB Full Auto Test:
	//	Reset TMBs to get all registers to default
	//------------------------------------------------------------------------------
	wr_data = 0x0200;
	status  = vme_write(boot_adr_dut,wr_data);	// Assert hard reset
	status  = vme_write(boot_adr_ref,wr_data);	// Assert hard reset

	wr_data = 0x0000;
	status  = vme_write(boot_adr_dut,wr_data);	// De-assert hard reset
	if (id_rev_fpga==3) sleep(95);				// Spartan-6 takes longer than Virtex-2
	status  = vme_write(boot_adr_ref,wr_data);	// De-assert hard reset

	sleep(500);									//	Wait for TMBs to reload, mSecs

	//------------------------------------------------------------------------------
	//	TMB Full Auto Test:
	//	Open log file
	//------------------------------------------------------------------------------
	// Get dsn for dut
	adr   = base_adr_dut+vme_dsn_adr;
	itype = 0;
	dsn_rd(adr,itype,dsn);
	dow_crc(dsn,icrc);

	// Check dut dsn
	if (icrc==0 || icrc!=dsn[7]) {						// Board has issues already
		printf("\n");
		printf("\tTest TMB has bad Digital Serial dsn="); for (i=5; i>0; i--) {printf("%2.2X",dsn[i]);} printf("\n");
		printf("\tPerhaps you did not set SH62=GEO and SW2/1=1A or board is not in slot %2i\n ",islot_dut);
		printf("\tContinue anyway? [y/n]<cr>=y ");

		gets(line);
		n = strlen(line);
		i = line[0];

		if (n==1 && (i=='n' || i=='N')) {
			printf("\n\tTest cancelled\n");
			return;
		}}

	// Dut dsn is ok
	idsn = 0;
	for (i=1;i<=4;++i) idsn=idsn|(dsn[i]<<(8*(i-1)));	// Convert dsn to integer, 2 hex digits at a time, skip [0]=mfg
	sprintf(cdsn,"%7.7X",idsn);							// Convert dsn to character

	if (icrc!=dsn[7]|| icrc==0) sdsn="BadDSNf";			// dsn gave bad  crc
	else                        sdsn=string(cdsn);		// dsn gave good crc

	sprintf(cbid,"%4.4i",tmb_board_id);					// Convert board id to string
	sbid=string(cbid);

	// Look for a previous test file version in current folder
	for (iver=1; iver<=99; ++iver) {

		sprintf(cfver,"%2.2i",iver);						// Convert version number to string
		sfver=string(cfver);

		// Check if file exists
		test_file_name = logfolder;
		test_file_name = test_file_name+"tmb_"+sbid+"_loop_"+sdsn+"_"+sfver+".txt";

		test_file = fopen(test_file_name.c_str(),"r");	// Check if this version already exists
		if (test_file==NULL) goto L1802;				// No, so we use this version number
		fclose(test_file);								// Yes, so close it, proceed to next version number
	}	// close for iver

	// Already have 99 versions of this test file, kinda excessive, you should delete the older versions
	pause("Log file version > 99, why? Delete old versions, then restart test.");
	return;

	// Open TMB test log file
L1802:
	if (test_file!=NULL) fclose(test_file);
	test_file = fopen(test_file_name.c_str(),"w");

	if (test_file!=NULL) {printf("\tOpened file  %s\n",test_file_name.c_str());}
	else                 {printf("\tFailed to open %s\n",test_file_name.c_str()); pause("\tPerhaps folder does not exist"); return;}

	// Insert the date
	_strtime(timestr);
	_strdate(datestr);

	fprintf(test_file,"\tStarting tests on TMB %s in slot %2i-GEO dsn=%s\n",sbid.c_str(),islot_dut,sdsn.c_str());
	fprintf(test_file,"\tTMB AutoTest started %s %s\n",datestr,timestr);
	fprintf(test_file,"\tLogfile %s\n\n",test_file_name.c_str());

	fprintf(stdout,   "\tStarting tests on TMB %s in slot %2i-GEO dsn=%s\n",sbid.c_str(),islot_dut,sdsn.c_str());
	fprintf(stdout,   "\tTMB AutoTest started %s %s\n",datestr,timestr);
	fprintf(stdout,   "\tLogfile %s\n\n",test_file_name.c_str());

	// Auto passes
	ipass_full_auto=0;
L1805:
	ipass_full_auto++;

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Test boot register
	//------------------------------------------------------------------------------
L18010:
	itest = 1;

	for (ipass=0; ipass<=1; ++ipass) {	// L18015

		if (ipass==0) {
			boot_adr_chk = boot_adr;			// pass 0 use geo boot adr
			base_adr_chk = base_adr;}
		else {
			boot_adr_chk = boot_adr_global;		// pass 1 use global
			base_adr_chk = base_adr_global;
		}

		reg_err = 0;

		// Get current boot contents
		adr    = boot_adr_chk;	
		status = vme_read(adr,rd_data);
		boot_data = rd_data;

		// Walking 1 test 
		for (ibit=0; ibit<=15; ++ibit) {
			wr_data = (1 << ibit);
			status	= vme_write (boot_adr_chk, wr_data);	// Write walking 1
			status	= vme_read  (base_adr_ref, rd_data);	// Read reference tmb to purge bit3 buffers, not needed if dataway display is off
			status	= vme_read  (boot_adr_chk, rd_data);	// Read boot
			rd_data = rd_data & 0x3FFF;						// Remove read-only bits
			wr_data = wr_data & 0x3FFF;

			if (rd_data!=wr_data) reg_err++;

			if ((reg_err!=0 || debug_step) && !debug_loop) {
				if (ipass==0) printf("\tFailed on boot geo address");
				if (ipass==1) printf("\tFailed on boot global address");

				fprintf(test_file,"\tFailed Boot bit=%2.2i wr=%8.8X rd=%8.8X\n",ibit,wr_data,rd_data);
				fprintf(stdout,   "\tFailed Boot bit=%2.2i wr=%8.8X rd=%8.8X\n",ibit,wr_data,rd_data);
				fprintf(stdout,   "\tDid you set SH62=GEO, SW2/1=1A ?\n");
				tmb_nfailed[itest]=1;

				printf("\tSkip, Loop, Debug, Continue, Exit[s,l,d,c,e] ? ");
				gets(line);
				n = strlen(line);
				i = line[0];

				if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
				if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L18020;}
				if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
				if (n==1 && (i=='D' || i=='d'))  debug_step = true;
			} // close if reg_err
		} // close ibit

		if (debug_loop) goto L18010;

		// Restore boot contents
		adr     = boot_adr;
		wr_data = boot_data;
		status	= vme_write(adr,wr_data);
	}	// Close ipass L18015

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("VME Boot Register data",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Test Hard Reset TMB via boot register
	//------------------------------------------------------------------------------
L18020:
	itest = 2;

	adr     = boot_adr_dut;
	wr_data = 0x0200;
	status  = vme_write(boot_adr_dut,wr_data);		// Assert hard reset
	status  = vme_write(boot_adr_ref,wr_data);		// Reset ref to keep LEDs in sync

	status  = vme_read(adr,rd_data);				// Check for fpga not ready
	rd_data = rd_data & 0x7FFF;						// Remove tdo
	status  = cks("Hard reset TMB fpga not ready",rd_data,0x0200);
	if (status!=0) tmb_nfailed[itest]=1;

	wr_data = 0x0000;
	status  = vme_write(boot_adr_dut,wr_data);		// De-assert hard reset
	status  = vme_write(boot_adr_ref,wr_data);		// De-assert hard reset
	sleep(500);										// Wait for TMB to reload

	status  = vme_read(adr,rd_data);				// Check for fpga ready
	rd_data = rd_data & 0x7FFF;						// Remove tdo
	status  = cks("Hard reset TMB fpga ready",rd_data,0x4000);
	if (status!=0) tmb_nfailed[itest]=1;

	// Check for SH107 set to 2-3 to disable tmb self reset
	adr     = vme_step_adr+base_adr;
	status  = vme_read(adr,rd_data);				// Get current step word
	wr_data = rd_data & 0xEFFF;						// Assert self reset bit, 0=reset
	status  = vme_write(adr,wr_data);				// Send it
	sleep(500);										// Wait for TMB to reload

	status  = vme_read(adr,rd_data);								// Read back step word
	rd_data = rd_data & 0x1000;										// Isolate tmb hard reset
	status  = cks("Self reset TMB fpga not ready",rd_data,0x0000);	// expect it to stay 0, if tmb did hard reset, it would come back as 1
	if (status!=0) {
		tmb_nfailed[itest]=1;
		pause ("\tMove SH107 Self Reset to 2-3 and restart");
		return;
	}

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("Hard reset TMB boot",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	VME address register
	//------------------------------------------------------------------------------
	//L18030:
	itest   = 3;
	reg_err = 0;
	status  = vme_errs(1);					// Turn off bus-timeout error messages

	for (i=1; i<=23; ++i) {
		adr     = (1 << i);						// Walking 1 address
		status  = vme_read(adr,rd_data);		// Read ww1 address
		sleep(10);
		status	 = vme_read(adr,rd_data);		// Read ww1 address again
		sleep(10);
		adr_ww1  = vme_adr0_adr+base_adr;
		status	 = vme_read(adr_ww1,rd_data);	// Read adr lsbs
		vme_data = rd_data;
		status	 = vme_read(adr,rd_data);		// Read ww1 address again
		sleep(10);
		adr_ww1  = vme_adr1_adr+base_adr;
		status	 = vme_read(adr_ww1,rd_data);	// Read adr msb
		vme_data = vme_data | ((rd_data & 0xFF) << 16);
		adr_mode = (rd_data >> 8) & 0xFF;
		printf("\tAdress: %6.6X\r",adr);

		if (vme_data!=adr || adr_mode!=0x3D) {
			reg_err++;
			fprintf(test_file,"\tFailed Address bit=%2i wr=%8.8X rd=%8.8X mode=%8.8X\n",i,adr,vme_data,adr_mode);
			fprintf(stdout,   "\tFailed Address bit=%2i wr=%8.8X rd=%8.8X mode=%8.8X\n",i,adr,vme_data,adr_mode);
		} // cllose if vme_data
	} // close do i

	if (reg_err!=0           ) tmb_nfailed[itest]=1;
	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
	aokf("VME FPGA address register",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");
	status = vme_errs(0);	// turn on bus-timeout error messages

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	VME FPGA Data register
	//------------------------------------------------------------------------------
	//L18040:
	itest = 4;

	for (ipass=0; ipass<=1; ++ipass) {	// L18045
		if (ipass==0) {
			boot_adr_chk = boot_adr;			// pass 0 use geo boot adr
			base_adr_chk = base_adr;}
		else {
			boot_adr_chk = boot_adr_global;		// pass 1 use global
			base_adr_chk = base_adr_global;
		}

		reg_err = 0;
		status	= vme_read(adr=(vme_ddd0_adr+base_adr_chk),rd_data);	// Get current
		vme_cfg = rd_data;

		for (i=0; i<=15; ++i) {
			wr_data= (1 << i);
			status	= vme_write(adr=(vme_ddd0_adr+base_adr_chk),wr_data);	// Write walking 1
			status	= vme_read (adr=base_adr_chk               ,rd_data);	// Read base to purge bit3 buffers
			status	= vme_read (adr=(vme_ddd0_adr+base_adr_chk),rd_data);	// Read walking 1

			if (rd_data!=wr_data) {
				if (ipass==0) printf("\tFailed on boot geo address\n");
				if (ipass==1) printf("\tFailed on boot global address\n");

				reg_err++;
				fprintf(test_file,"\tFailed vme Data bit=%2i wr=%8.8X rd=%8.8X\n",i,wr_data,rd_data);
				fprintf(stdout,   "\tFailed vme Data bit=%2i wr=%8.8X rd=%8.8X\n",i,wr_data,rd_data);

			} // close if rd_data
		} // close do i
		if (reg_err!=0) tmb_nfailed[itest]=1;

		wr_data = vme_cfg;
		status  = vme_write(adr=(vme_ddd0_adr+base_adr_chk),wr_data);	// Restore data reg
		wr_data = 0x001A;
		status  = vme_write(adr=(vme_cfg_adr+base_adr_chk),wr_data);	// Turn on cylons

	} // close 18045

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
	aokf("VME FPGA data register",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	ID Register
	//------------------------------------------------------------------------------
	//L18050:
	itest = 5;

	for (i=0; i<=3; ++i) {
		adr    = base_adr+vme_idreg_adr+2*i;
		status = vme_read(adr,rd_data);
		id_reg[i] = rd_data;
	}

	id_slot = (id_reg[0] >> 8) & 0x00FF;
	id_ver  = (id_reg[0] >> 4) & 0x000F;
	id_type = (id_reg[0] >> 0) & 0x000F;
	id_month= (id_reg[1] >> 8) & 0x00FF;
	id_day  = (id_reg[1] >> 0) & 0x00FF;
	id_year = id_reg[2];
	id_rev  = id_reg[3];

	id_rev_day   = (id_rev >>  0) & 0x001F;
	id_rev_month = (id_rev >>  5) & 0x000F;
	id_rev_year  = (id_rev >>  9) & 0x000F;
	id_rev_fpga  = (id_rev >> 13) & 0x0007;
	id_rev_fpga  =  id_rev_fpga+2;

	if (id_rev_fpga==3) id_rev_year=id_rev_year+10;	// Spartan-6 exception
	if (id_rev_fpga==5) id_rev_fpga=6;				// Virtex-6 exception

	fprintf(test_file,"\tid_slot=%2.2X\n",id_slot);
	fprintf(test_file,"\tid_rev =%2.1X\n",id_ver);
	fprintf(test_file,"\tid_type=%2.1X\n",id_type);
	fprintf(test_file,"\tid_date=%2.2X/%2.2X/%4.4X\n",id_month,id_day,id_year);
	fprintf(test_file,"\tid_rev =%4.4X=%2.2i/%2.2i/%2.2i series\n",id_rev,id_rev_month,id_rev_day,id_rev_year,id_rev_fpga);

	statid[ 1]=cks("ID Register slot     ",id_slot,	     islot_dut);
	statid[ 2]=cks("ID Register version  ",id_ver,	     0x000E);
	statid[ 3]=cks("ID Register type     ",id_type,	     0x000D);
	statid[ 4]=cks("ID Register month    ",id_month,     id_month_expect);	// NB date is bchex
	statid[ 5]=cks("ID Register day      ",id_day,	     id_day_expect  );	// NB date is bchex
	statid[ 6]=cks("ID Register year     ",id_year,	     id_year_expect );	// NB date is bchex

	statid[ 7]=cks("ID Register rev_month",id_rev_month, id_rev_month_expect);	// NB date is decimal
	statid[ 8]=cks("ID Register rev_day  ",id_rev_day,   id_rev_day_expect);	// NB date is decimal
	statid[ 9]=cks("ID Register rev_year ",id_rev_year,  id_rev_year_expect);	// NB date is decimal
	statid[10]=cks("ID Register rev_fpga ",id_rev_fpga,  id_rev_fpga_expect);	// Virtex2 or Virtex6

	for (i=1; i<=10; ++i) {
		if (statid[i]!=0) tmb_nfailed[itest]=1;
	}

	// Check Geographic Address parity
	adr    = base_adr+vme_status_adr;
	status = vme_read(adr,rd_data);

	geo_adr_rd = rd_data & 0x1F;
	geo_parity = (rd_data >> 5) & 0x1;

	parity = 0;
	for (ibit=0; ibit<=4; ++ibit) {
		parity = parity ^ (geo_adr_rd >> ibit) & 0x1;
	}
	parity = parity ^ 0x1;	//make it odd

	if (geo_parity!=parity) {
		tmb_nfailed[itest]=1;
		printf("\tBad geo parity: geo_adr_rd=%2.2X geo_parity=%1X parity=%1X\n",geo_adr_rd,geo_parity,parity);
	}

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
	aokf("ID Register",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Internal JTAG chains
	//------------------------------------------------------------------------------
L18055:
	//itest=6,7
	reg_err = 0;

	// Put boot register back to power-up state
	adr     = boot_adr;
	wr_data = 0;
	status	= vme_write(adr,wr_data);

	// Loop over Chain sources Usr,Boot
	for (ijtag_src=0; ijtag_src<=1; ++ijtag_src) {	// 0=Usr source, 1=boot source

		if (ijtag_src==0) itest=6;
		if (ijtag_src==1) itest=7;

		// Loop over tx bits
		ichain = 0x000C;								// FPGA chain 1100

		for (ipass=1; ipass<=100; ++ipass) {
			for (itx=0;   itx<=4;     ++itx  ) {

				// Send walking 1 to jtag chain
				wr_pat  = (1 << itx);							// Step through tdi,tms,tck,sel0,sel1
				wr_data = (1 << itx) | (ichain << 3) | (1<<7);	// Select FPGA JTAG chain

				if (ijtag_src==0) adr = vme_usr_jtag_adr+base_adr;
				if (ijtag_src==1) adr = boot_adr;
				status = vme_write(adr,wr_data);

				// Copy tdi to tdo through gp_io0
				adr     = vme_gpio_adr+base_adr;
				status  = vme_read(adr,rd_data);
				wr_data = (rd_data >> 1) & 0x1;					// get tdi on gp_io1
				status  = vme_write(adr,wr_data);				// send it back out on gp_io0

				// Read FPGA chain
				adr     = vme_gpio_adr+base_adr;
				status  = vme_read(adr,rd_data);
				rd_data = rd_data & 0xF;

				pat_expect = 0;
				if (itx <= 2) pat_expect = (wr_pat << 1);
				if (itx == 0) pat_expect = 3;					// cuz you just wrote gp_io0=gp_io1 
				if (itx >= 3) pat_expect = 0xF;					// sel[1:0]=0 selects FPGA chain, else see pullups to 1

				if (itx==0 && rd_data==0xF && !debug_loop) {
					pause ("\tDisconnect JTAG cable.If its disconnected, TMB has JTAG errors");
				}

				if (rd_data!=pat_expect) reg_err++;

				if ((reg_err!=0 || debug_step) && !debug_loop) {

					tmb_nfailed[itest] = 1;
					if (ijtag_src == 0) printf("\tFailed on USR  JTAG bit\n");
					if (ijtag_src == 1) printf("\tFailed on BOOT JTAG bit\n");

					fprintf(stdout,   "\tFailed JTAG bit=%2i wr=%8.8X rd=%8.8X src=%1i itx=%1i\n",itx, pat_expect, rd_data, ijtag_src, itx);
					fprintf(test_file,"\tFailed JTAG bit=%2i wr=%8.8X rd=%8.8X src=%1i itx=%1i\n",itx, pat_expect, rd_data, ijtag_src, itx);

					printf("\tSkip, Loop, Debug, Continue, Exit[s,l,d,c,e] ? ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
					if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L18056;}
					if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					if (n==1 && (i=='D' || i=='d'))  debug_step = true;
				}	// close if reg_err!=0

				// Close loops
			} // close itx
			if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
			if (debug_loop) goto L18055;
		} // close ipass

		if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	

		if (ijtag_src==0) aokf("USR  JTAG Chain",itest,tmb_npassed[itest]);
		if (ijtag_src==1) aokf("Boot JTAG Chain",itest,tmb_npassed[itest]);
		if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	} // ijtag_src

	// Put boot register back to power-up state, makes FPGA the jtag chain source
L18056:
	adr     = boot_adr;
	wr_data = 0;
	status	= vme_write(adr,wr_data);

	if (id_rev_fpga==6) {
		fprintf(stdout,   "\t    U76 bus hold test skipped for Virtex6            FAIL\n");
		fprintf(test_file,"\t    U76 bus hold test skipped for Virtex6            FAIL\n");
		goto skip_u76;}

	// Write a pattern to U76
	for (i=0; i<=2; ++i) {						// loop over tdi,tms,tck
		pat_expect = (1 << i);						// walking 1 in jtag signals
		adr     = base_adr+vme_usr_jtag_adr;
		ichain  = 0x000C;							// FPGA chain 1100
		wr_data = (ichain << 3) | pat_expect;		// boot[7]=chain en=0, boot[6:0]=sel[3:0],jtag[2:0]
		status	= vme_write(adr,wr_data);

		// Read back U76 before hard reset
		adr     = vme_gpio_adr+base_adr;
		status  = vme_read(adr,rd_data);
		rd_data = (rd_data >> 1) & 0x7;				// gpio has tck,tms,tdi,tdo, so shift off the tdo
		status  = cks("U76 bus hold test before hard reset",rd_data,pat_expect);

		// Hard-reset TMB
		wr_data = 0x0200;
		status  = vme_write(boot_adr_ref,wr_data);	// Assert hard reset
		status  = vme_write(boot_adr_dut,wr_data);	// Assert hard reset
		wr_data = 0x0000;
		status  = vme_write(boot_adr_ref,wr_data);	// De-assert hard reset
		status  = vme_write(boot_adr_dut,wr_data);	// De-assert hard reset

		//	sleep(300);									// Wait for TMBs to reload, mSecs (Virtex2 takes 100ms)
		sleep(500);									// Wait for TMBs to reload, mSecs (Virtex6 takes 400ms)

		// Read back U76 after hard reset
		adr     = vme_gpio_adr+base_adr;
		status  = vme_read(adr,rd_data);
		rd_data = (rd_data >> 1) & 0x7;				// gpio has tck,tms,tdi,tdo, so shift off the tdo
		status  = cks("U76 bus hold test after  hard reset",rd_data,pat_expect);

		if (status!=0) {
			printf("\tU76 did not retain jtag data. Fails.\n");
			printf("\tU76 is probably an SN74LVC2244ADW device.\n");
			printf("\tIf so, replace it with SN74LVCH244ADW.\n");
			pause ("\tFailed. <cr> to continue anyway");
		}

	} // close i for U76 check
skip_u76:
	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Mezzanine FPGA and PROMs ID Codes
	//------------------------------------------------------------------------------
	//	itest 8,9,10,11,12
	fprintf(test_file,"\n");

	// Select FPGA Mezzanine FPGA programming JTAG chain from TMB boot register
	if      (id_rev_fpga==3) {ichain=0x24; nchips=3;}	// Spartan6 TMB Mezzanine pgm jtag chain
	else if (id_rev_fpga==6) {ichain=0x14; nchips=3;}	// Virtex6  TMB Mezzanine pgm jtag chain
	else                     {ichain=0x04; nchips=5;}	// Virtex2  TMB Mezzanine pgm jtag chain

	adr    = boot_adr;								// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI

	// Read Mezzanine FPGA and PROM IDcodes
	for (chip_id=0; chip_id<nchips; ++chip_id) {
		itest = chip_id+8;
		if (chip_id == 0) opcode = 0x09;				// FPGA IDcode opcode, expect v0A30093
		if (chip_id >=1 ) opcode = 0xFE;				// PROM IDcode opcode
		reg_len = 32;									// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		// Interpret ID code
		tdi_to_i4(&tdo[0],idcode,32,0);

		sprintf(cid, "%1i",  chip_id);					// Convert chip_id to string
		sprintf(cidc,"%8.8X",idcode);					// Convert idcode  to string
		sid  = string(cid);
		sidc = string(cidc);

		idcode_decode (idcode, sdevice_type, sdevice_name, sdevice_version, sdevice_size);

		fprintf(test_file,"\tTMB  Mez  Device=%1i IDcode=%8.8X %s Name=%s\tVer=%s\tSize=%s\n",
				chip_id, idcode, sdevice_type.c_str(), sdevice_name.c_str(), sdevice_version.c_str(), sdevice_size.c_str());

		biv = idcode==0x3401D093;
		civ = idcode==0x4401D093;

		if (chip_id==0)
		{
			if      (id_rev_fpga==3 && biv) status=cks(string("FPGAmez ID Code ").append(sid),idcode,0x3401D093);	// Spartan6
			else if (id_rev_fpga==3 && civ) status=cks(string("FPGAmez ID Code ").append(sid),idcode,0x4401D093);	// Spartan6
			else if (id_rev_fpga==6)        status=cks(string("FPGAmez ID Code ").append(sid),idcode,0x2424C093);	// Virtex6
			else                            status=cks(string("FPGAmez ID Code ").append(sid),idcode,0x11050093);	// Virtex2
			if (status != 0          ) tmb_nfailed[itest]=1;
			if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
			aokf(string("FPGAmez ID Code ").append(sid).append(string(" ")).append(sidc).append(string(" ")).append(ssize),itest,tmb_npassed[itest]);
			if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");
		}
		else
		{				//0xV5036093		// whacks leading digit, converts 5036093 to 5026093
			idcode = idcode & 0x0FFEFFFF;		// newer proms have idcode X5036093 older proms have 05026093,05036093 is the typical idcode

			if      (id_rev_fpga==3 && chip_id==1) status=cks(string("PROMmez ID Code ").append(sid),idcode,0x05049093);	// Spartan6 xcf32
			else if (id_rev_fpga==3 && chip_id==2) status=cks(string("PROMmez ID Code ").append(sid),idcode,0x05047093);	// Spartan6 xcf08
			else if (id_rev_fpga==6)               status=cks(string("PROMmez ID Code ").append(sid),idcode,0x05049093);	// Virtex6
			else                                   status=cks(string("PROMmez ID Code ").append(sid),idcode,0x05026093);	// Virtex2

			if (status!=0            ) tmb_nfailed[itest]=1;
			if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
			aokf(string("PROMmez ID Code ").append(sid).append(string(" ")).append(sidc).append(string(" ")).append(ssize),itest,tmb_npassed[itest]);
			if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");
		}	// close if chip_id
	}	// close chip_id

	// Spartan-6 tests 11,12 are copied from 9,10 because S6 has only 2 PROMs
	if (fpga_series=="XC6SLX150")
	{
		tmb_npassed[11] = tmb_npassed[9];
		tmb_npassed[12] = tmb_npassed[10];	

		tmb_nfailed[11] = tmb_nfailed[9];
		tmb_nfailed[12] = tmb_nfailed[10];

		tmb_nskipped[11]= tmb_nskipped[9];
		tmb_nskipped[12]= tmb_nskipped[10];
	}

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	User PROM ID codes
	//------------------------------------------------------------------------------
	//L18060:
	// itest 13,14
	ichain = 0x0008;								// User PROM chain
	adr    = boot_adr;								// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI
	opcode  = 0xFE;									// IDcode opcode
	reg_len = 32;									// IDcode length

	for (chip_id=0; chip_id<=1; ++ chip_id) {
		itest = chip_id+13;										// Loop over PROM chips
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		tdi_to_i4(&tdo[0],idcode,32,0);
		user_idcode[chip_id]=idcode;

		sprintf(cid, "%1i",  chip_id);					// Convert chip_id to string
		sprintf(cidc,"%8.8X",idcode);					// Convert idcode  to string
		sid  = string(cid);
		sidc = string(cidc);

		// User proms may have idcode 05022093 for 256KB, and either 05023093 or 05033093 for 512KB
		idcode_decode (idcode, sdevice_type, sdevice_name, sdevice_version, sdevice_size);

		fprintf(test_file,"\tTMB  Base Device=%1i IDcode=%8.8X %s Name=%s\tVer=%s\tSize=%s\n",
				chip_id, idcode, sdevice_type.c_str(), sdevice_name.c_str(), sdevice_version.c_str(), sdevice_size.c_str());

		idcode = idcode & 0xFFFEEFFF;					// blank 23 or 33 case

		status = cks(string("PROMusr ID Code ").append(sid).append(string(" ")).append(sdevice_size),idcode,0x05022093);		// xc18v256 idcode
		if (status!=0) tmb_nfailed[itest]=1;

		// Require both PROMs to have same idcode
		bool require_identical_proms=false;

		if (require_identical_proms) {
			if (chip_id==1) {
				if (user_idcode[0]!=user_idcode[1]) {
					tmb_nfailed[itest]=1;
					fprintf(stdout,   "\tUser PROM IDcode Mismatch: U80=%8.8X U81=%8.8X\n",user_idcode[0],user_idcode[1]);
					fprintf(test_file,"\tUser PROM IDcode Mismatch: U80=%8.8X U81=%8.8X\n",user_idcode[0],user_idcode[1]);
				}	//  close user_idcode
			}	//  close chip_id

			// Temporarily fail boards that have 256k proms
			if (user_idcode[chip_id]!=0x05022093) {
				tmb_nfailed[itest]=1;
				printf("\tThis TMB probably has 512KB PROMs\n");
				printf("\tSet it aside for now\n");
				printf("\tAttach post-it stating 512KB\n");
				pause ("\t<cr> to continue");
				return;
			}

			// close if require_identical_proms
		}
		if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
		aokf(string("PROMusr ID Code ").append(sid).append(string(" ")).append(sidc).append(string(" ")).append(ssize),itest,tmb_npassed[itest]);
		if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

		//  close chip_id
	}

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	User PROM Data Path
	//------------------------------------------------------------------------------
	first_prom_pass = true;
L18065:
	// tests 15,16
	// Enable 1 prom disable the other, they share the onboard led bus
	for (iprom=0; iprom<=1; ++iprom) {
		itest = iprom+15;
		jprom = (iprom+1)%2;

		prom_clk[iprom] = 0;	// enable this one
		prom_oe[iprom]  = 1;
		prom_nce[iprom] = 0;

		prom_clk[jprom] = 0;	// disble this one
		prom_oe[jprom]  = 0;
		prom_nce[jprom] = 1;
		prom_src = 1;

		adr = vme_prom_adr+base_adr;
		wr_data = 
			(prom_src    << 14) |
			(prom_nce[1] << 13) |
			(prom_oe[1]  << 12) |
			(prom_clk[1] << 11) |
			(prom_nce[0] << 10) |
			(prom_oe[0]  <<  9) | 
			(prom_clk[0] <<  8);
		status = vme_write(adr,wr_data);

		fprintf(test_file,"\n");

		// Read data from selected PROM
		for (prom_adr=0; prom_adr<=9; ++prom_adr) {

			status = vme_read(adr,rd_data);
			prom_data = rd_data & 0xFF;
			fprintf(test_file,"\tPROM%1i adr=%2.2X data=%4.4X\n",iprom,prom_adr,prom_data);

			pat_expect = 0xFF;
			if (iprom==0 && prom_adr==0) pat_expect = 0xAB;
			if (iprom==1 && prom_adr==0) pat_expect = 0xCD;
			if (iprom==0 && prom_adr==9) pat_expect = 0xEE;
			if (iprom==1 && prom_adr==9) pat_expect = 0xBB;
			if (prom_adr >=1 && prom_adr <=8) pat_expect = (1 << (prom_adr-1));

			// If data is wrong, try to program the PROMs
			if (prom_data!=pat_expect && first_prom_pass) {
				first_prom_pass = false;
				fprintf(stdout,   "\n");
				fprintf(stdout,   "\tUserProm data error\n");
				fprintf(stdout,   "\tTry re-writing PROMs with Impact\n");
				fprintf(stdout,   "\tWrite prom0_walking1.mcs, prom1_walking1.mcs to jtag chain 8\n");

				inquirb("\tDo you want to try the experimental in-line programmer? [y|n]? cr=%3c", bans=true);
				if (bans)
				{
					nerrors         = -1;
					fprintf(stdout,   "\tProgramming Xilinx User PROMs...\n");
					fprintf(test_file,"\tProgramming Xilinx User PROMs...\n");
					xsvf_writer(islot_dut,"userproms_walking1.xsvf",nerrors);
					fprintf(stdout,   "\tProgramming response code %5i\n",nerrors);
					fprintf(test_file,"\tProgramming response code %5i\n",nerrors);
					fprintf(stdout,   "\tResuming TMB testing\n");
					goto L18065;
				}	// close if bans
			}	// close if (prom_data

			// If data is still wrong we bad
			if (prom_data!=pat_expect) {
				tmb_nfailed[itest]=1;
				fprintf(stdout,   "\tPROM%1i Adr=%4.4X Data=%2.2X Expect=%2.2X\n",iprom,prom_adr,prom_data,pat_expect);
				fprintf(test_file,"\tPROM%1i Adr=%4.4X Data=%2.2X Expect=%2.2X\n",iprom,prom_adr,prom_data,pat_expect);
			}

			// Toggle clock to advance address
			prom_clk[iprom]=1;
			wr_data = 
				(prom_src    << 14) |
				(prom_nce[1] << 13) |
				(prom_oe[1]  << 12) |
				(prom_clk[1] << 11) |
				(prom_nce[0] << 10) |
				(prom_oe[0]  <<  9) | 
				(prom_clk[0] <<  8);
			status = vme_write(adr,wr_data);

			prom_clk[iprom]=0;
			wr_data = 
				(prom_src    << 14) |
				(prom_nce[1] << 13) |
				(prom_oe[1]  << 12) |
				(prom_clk[1] << 11) |
				(prom_nce[0] << 10) |
				(prom_oe[0]  <<  9) | 
				(prom_clk[0] <<  8);
			status = vme_write(adr,wr_data);

			// close prom_adr
		}

		// Turn PROMs off
		prom_clk[iprom] = 0;	// disble this one
		prom_oe[iprom]  = 0;
		prom_nce[iprom] = 1;
		prom_src = 0;

		wr_data = 
			(prom_src    << 14) |
			(prom_nce[1] << 13) |
			(prom_oe[1]  << 12) |
			(prom_clk[1] << 11) |
			(prom_nce[0] << 10) |
			(prom_oe[0]  <<  9) | 
			(prom_clk[0] <<  8);
		status = vme_write(adr,wr_data);

		if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
		if (iprom == 0) aokf("PROM 0 Data Path",itest,tmb_npassed[itest]);
		if (iprom == 1) aokf("PROM 1 Data Path",itest,tmb_npassed[itest]);
		if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

		// close for iprom
	}

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Hardware Serial Numbers
	//------------------------------------------------------------------------------
	//L18070:
	// itest=17,18
	fprintf(test_file,"\n");

	adr = base_adr+vme_dsn_adr;
	for (itype=0; itype<=1; ++itype) {
		itest=itype+17;
		dsn_rd(adr,itype,dsn);
		dow_crc(dsn,icrc);

		idsn = 0;
		for (i=1;i<=4;++i) idsn=idsn|(dsn[i]<<(8*(i-1)));	// Convert dsn to integer, 2 hex digits at a time, skip [0]=mfg
		sprintf(cdsn,"%8.8X",idsn);							// Convert dsn to character

		if (icrc!=dsn[7]|| icrc==0) sdsn="BadDSNf";			// dsn gave bad  crc
		else                        sdsn=string(cdsn);		// dsn gave good crc

		if (!(icrc==dsn[7] && icrc!=0)) tmb_nfailed[itest]=1;
		if (tmb_nfailed[itest]==0     ) tmb_npassed[itest]=1;	

		if (itype==0) fprintf(test_file,"\tDigital Serial TMB %8.8X",idsn);
		if (itype==1) fprintf(test_file,"\tDigital Serial Mez %8.8X",idsn);

		if (itype==0) aokf(string("Digital Serial TMB ").append(sdsn),itest,tmb_npassed[itest]);
		if (itype==1) aokf(string("Digital Serial Mez ").append(sdsn),itest,tmb_npassed[itest]);

		if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");
	} // close itype

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Voltage Discriminators
	//------------------------------------------------------------------------------
	//L18080:
	itest=19;

	// Initialze looback registers
	//	sel_loopbk = 0x0A9A;	// NB loopbk bits are different for normal tmb firmware
	sel_loopbk = 0x0A9E;	// NB loopbk bits are different for normal tmb firmware TMB2005
	adr        = vme_loopbk_adr+base_adr;
	wr_data    = sel_loopbk;
	status	   = vme_write(adr,wr_data);

	//	Partially, stress ccb gtl drivers for current measurements. Loopback regulator can't handle full load
	//	wr_data = 0xFEFF;						// All bits 0, except 8, tmb reset
	wr_data = 0x00FF;						// 1/2 bits 0
	wr_data = (~wr_data) & 0x0FFFF;			// invert
	adr     = ccb_txa_adr+base_adr;
	status	= vme_write(adr,wr_data);
	wr_data = 0xFFFF;						// bits 17:16
	wr_data = (~wr_data) & 0x0000F;			// invert
	adr     = ccb_txb_adr+base_adr;
	status	= vme_write(adr,wr_data);

	//	Read voltage discriminators
	adr    = vme_adc_adr+base_adr;
	status = vme_read(adr,rd_data);

	vstat_5p0v = ok[(rd_data >> 0) & 0x1];	// returns BAD or OK
	vstat_3p3v = ok[(rd_data >> 1) & 0x1];
	vstat_1p8v = ok[(rd_data >> 2) & 0x1];
	vstat_1p5v = ok[(rd_data >> 3) & 0x1];
	tcrit      = ok[(rd_data >> 4) & 0x1];

	fprintf(test_file,"\n");
	fprintf(test_file,"\tTMB Voltage Comparators:\n");
	fprintf(test_file,"\t5.0V TMB  status=%s\n",vstat_5p0v.c_str());
	fprintf(test_file,"\t3.3V TMB  status=%s\n",vstat_3p3v.c_str());
	fprintf(test_file,"\t1.8V RAT  status=%s\n",vstat_1p8v.c_str());
	fprintf(test_file,"\t1.5V TMB  status=%s\n",vstat_1p5v.c_str());
	fprintf(test_file,"\tTcrit     status=%s\n",tcrit.c_str());

	statid[1] = cks("5.0V  Status bit",(int)vstat_5p0v[0],(int)'O');
	statid[2] = cks("3.3V  Status bit",(int)vstat_3p3v[0],(int)'O');
	statid[3] = cks("1.8V  Status bit",(int)vstat_1p8v[0],(int)'O');
	statid[4] = cks("1.5V  Status bit",(int)vstat_1p5v[0],(int)'O');
	statid[5] = cks("Tcrit Status bit",(int)tcrit[0]     ,(int)'O');

	for (i=1; i<=5; ++i) {
		if (statid[i]!=0) tmb_nfailed[itest]=1;
	}

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
	aokf("Voltage Comparators",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	ADC+Status
	//------------------------------------------------------------------------------
	// itest=20,21,22

	// Read ADCs
	adc_read(base_adr);	// returns data via common block
	adc_read_mez(base_adr);

	// Read LM84 temperature from TMB, don't read RAT beco this board is in the loopback backplane and has no RAT
	smb_adr  = 0x2A;	// float,float state LM84 chip address
	smb_cmd  = 0x00;	// Local temperature command
	smb_data = 0xFF;	// Null write data
	adc_adr  = base_adr+vme_adc_adr;

	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data

	t_local_c_tmb = float(smb_data_tmb);
	t_local_f_tmb = t_local_c_tmb*(9./5.)+32.;

	smb_cmd  = 0x01;	// Remote temperature command
	smb_data = 0xFF;	// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	

	t_remote_c_tmb = float(smb_data_tmb);
	t_remote_f_tmb = t_remote_c_tmb*(9./5.)+32.;

	smb_cmd  = 0x05;	// Local tcrit
	smb_data = 0xFF;	// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	

	tcrit_local_c_tmb = float(smb_data_tmb);
	tcrit_local_f_tmb = tcrit_local_c_tmb*(9./5.)+32.;

	smb_cmd  = 0x07;	// Remote tcrit
	smb_data = 0xFF;	// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	

	tcrit_remote_c_tmb = float(smb_data_tmb);
	tcrit_remote_f_tmb = tcrit_remote_c_tmb*(9./5.)+32.;

	// Display TMB base board ADC
	fprintf(test_file,"\n");
	fprintf(test_file,"\tTMB2005E ADC\n");
	fprintf(test_file,"\t+5.0 TMB      %5.3f V  %8.3f A\n",v5p0,		a5p0);
	fprintf(test_file,"\t+3.3 TMB      %5.3f V  %8.3f A\n",v3p3,		a3p3);
	fprintf(test_file,"\t+1.5 TMBcore  %5.3f V  %8.3f A\n",v1p5core,	a1p5core);
	fprintf(test_file,"\t+1.5 GTLtt    %5.3f V  %8.3f A\n",v1p5tt,		a1p5tt);
	fprintf(test_file,"\t+1.0 GTLref   %5.3f V  %8.3f A\n",v1p0,		0.0);
	fprintf(test_file,"\t+3.3 RAT      %5.3f V  %8.3f A\n",v3p3,		a3p3rat);	// v3p3rat depends on sh921 setting
	fprintf(test_file,"\t+1.8 RATcore  %5.3f V  %8.3f A\n",v1p8rat,		a1p8rat);	// a1p8rat depends on sh921 setting
	fprintf(test_file,"\t+vref/2       %5.3f V  %8.3f A\n",vref2,		0.0);
	fprintf(test_file,"\t+vzero        %5.3f V  %8.3f A\n",vzero,		0.0);
	fprintf(test_file,"\t+vref         %5.3f V  %8.3f A\n",vref,		0.0);

	// Display Spartan-6 mezzanine ADC
	if (fpga_series=="XC6SLX150")
	{
		fprintf(test_file,"\n");
		fprintf(test_file,"\tSpartan6 ADC\n");
		fprintf(test_file,"\t+3.3 Vcc      %5.3f V\n",v3p3_mez);
		fprintf(test_file,"\t+2.5 Vccaux   %5.3f V\n",v2p5_mez);
		fprintf(test_file,"\t+1.5 Vcore    %5.3f V\n",vcore_mez);
		fprintf(test_file,"\t+1.8 Vccprom  %5.3f V\n",v1p8_mez);
		fprintf(test_file,"\t+1.2 Vccint   %5.3f V\n",v1p2_mez);
		fprintf(test_file,"\t+Tfpga       %6.3f C  %5.1f F\n",tfpga_mez,(32.+tfpga_mez*9.0/5.0));
		fprintf(test_file,"\t+Tsink       %6.3f C  %5.1f F\n",tsink_mez,(32.+tsink_mez*9.0/5.0));
		fprintf(test_file,"\t+vref/2       %5.3f V\n",vref2_mez);
		fprintf(test_file,"\t+vzero        %5.3f V\n",vzero_mez);
		fprintf(test_file,"\t+vref         %5.3f V\n",vref_mez);
	}

	// Display TMB temperature ADC
	fprintf(test_file,"\n");
	fprintf(test_file,"\tTMB2005E Temperature IC\n");
	fprintf(test_file,"\tT tmb pcb  %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_local_f_tmb,t_local_c_tmb,tcrit_local_f_tmb,tcrit_local_c_tmb);
	fprintf(test_file,"\tT tmb fpga %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_remote_f_tmb,t_remote_c_tmb,tcrit_remote_f_tmb,tcrit_remote_c_tmb);
	fprintf(test_file,"\n");

	for (i=1; i<=mxadcerr; ++i) {
		adc_err[i]     = 0;
		adc_err_mez[i] = 0;
	}

	// Check Currents
	itest=20;
	amptol=0.16;

	if      (fpga_series=="XC6SLX150" ) a1p5core_expect = 0.335;	// Spartan-6 Core current
	else if (fpga_series=="XC6VLX195T") a1p5core_expect = 3.00;		// Virtex-6  Core current
	else                                a1p5core_expect = 0.870;	// Virtex-6  Core current

	tok("+5.0a TMB      ", a5p0,     0.275,				amptol,     adc_err[10]);
	tok("+3.3a TMB      ", a3p3,     1.055,				amptol*4.5, adc_err[11]);	// large tolerance, dunno why
	tok("+1.5a TMB Core ", a1p5core, a1p5core_expect,	amptol,     adc_err[12]);
	tok("+1.5a TT       ", a1p5tt,   0.030,				amptol*12., adc_err[13]);	// Small current, large uncertainty
	tok("+1.8a RAT Core ", a1p8rat,  7.490,				amptol,     adc_err[14]);	// loop backplane sends 1.5v

	if (a1p5tt==0.0) {
		fprintf(stdout,   "\tERR: +1.5a TT stuck at 0 amps!\n");
		fprintf(test_file,"\tERR: +1.5a TT stuck at 0 amps!\n");
		adc_err[13]=1;
	}

	for (i=10; i<=14; ++i) {
		if (adc_err[i]!=0) tmb_nfailed[itest]=1;
	}

	if (tmb_nfailed[itest]==0)tmb_npassed[itest]=1;	
	aokf("ADC Currents",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	// Check Voltages 
L180021:
	itest=21;
	vcore_noload=1.525;							// Puts Vcore=1.500 at 2.5amp load, midrange of 1.425-to-1.575
	vcore_expect=vcore_noload-a1p5core*0.010;	// Expect Vcore-Acore*.010ohms. At Acore nom=0.870A, Vcore=1.516
	v1p0_expect =1.005;							// Expect 1.005+- a little

	fprintf(test_file,"\tVcore=%5.3f expect=%5.3f NoLoad=%5.3f Acore=%5.3f\n",v1p5core,vcore_expect,vcore_noload,a1p5core);

	tok("+5.0v TMB      ", v5p0,     5.000,        .0250, adc_err[1]);
	tok("+3.3V TMB      ", v3p3,     3.260,        .0250, adc_err[2]);
	tok("+1.5V Core     ", v1p5core, vcore_expect, .0015, adc_err[3]);	// expect 1.516 pretty close
	tok("+1.5V TT       ", v1p5tt,   1.493,        .0250, adc_err[4]);
	tok("+1.0v TT       ", v1p0,     v1p0_expect,  .0030, adc_err[5]);
	tok("+1.8V RAT Core ", v1p8rat,  1.805,        .0250, adc_err[6]);
	tok("+vref/2        ", vref2,    2.048,        .0010, adc_err[7]);
	tok("+vzero         ", vzero,    0.0,          .0010, adc_err[8]);
	tok("+vref          ", vref,     4.095,        .0010, adc_err[9]);

	if (fpga_series=="XC6SLX150")	// Spartan 6 Mezzanine ADC
	{
		tok("+3.3V   S6 Mez ", v3p3_mez,	3.260,		 .0250,		adc_err_mez[ 0]);
		tok("+2.5V   S6 Mez ", v2p5_mez,	2.500,		 .0250,		adc_err_mez[ 1]);
		tok("+1.5V   S6 Mez ", vcore_mez,	vcore_expect,.0250,		adc_err_mez[ 2]);
		tok("+1.8V   S6 Mez ", v1p8_mez,	1.800,		 .0200,		adc_err_mez[ 3]);
		tok("+1.2V   S6 Mez ", v1p2_mez,	1.200,		 .0200,		adc_err_mez[ 4]);
		tok("+Ch07   S6 Mez ", vch07_mez,	0.0,		 .0030,		adc_err_mez[ 7]);
		tok("+Ch08   S6 Mez ", vch08_mez,	0.0,		 .0030,		adc_err_mez[ 8]);
		tok("+Ch09   S6 Mez ", vch09_mez,	0.0,		 .00100,	adc_err_mez[ 9]);
		tok("+Ch10   S6 Mez ", vch10_mez,	0.0,		 .0010,		adc_err_mez[10]);
		tok("+vref/2 S6 Mez ", vref2_mez,	1.250,		 .0010,		adc_err_mez[11]);
		tok("+vzero  S6 Mez ", vzero_mez,	0.0,		 .0010,		adc_err_mez[12]);
		tok("+vref   S6 Mez ", vref_mez,	2.499,		 .0010,		adc_err_mez[13]);
	}

	// Offer to trim Vtt
	if (adc_err[5]==0) fprintf(test_file,"\tVtt   is in range, skipping trim. Read= %5.3f Expect=%5.3f\n",v1p0,v1p0_expect);
	if (adc_err[5]!=0) {	// Vtt
		printf("\n\tVtt out of range. Read= %5.3f Expect=%5.3f\n",v1p0,v1p0_expect);
		printf("\tTrim now, Skip or Exit (T,S,E) <cr=S>? ");

		gets(line);
		n = strlen(line);
		i = line[0];

		if (n==0 || (i=='E' || i=='e')) goto tmb_auto_done;
		if (n==0 || (i=='S' || i=='s')) {
			tmb_nskipped[itest]=1;
			goto L18082;
		}

		// Trimming Vtt
		printf("\tAdjust GTLP 1.0Vref R412.\n");
		printf("\tPress D when done\n");

L18081:
		adc_read(base_adr);								// Returns data via common block

		printf("\tVtt=%5.3f Target=%5.3f\r",v1p0,v1p0_expect);
		diff = (v1p0-v1p0_expect);
		vtol = 0.001;

		if      (abs(diff) <= vtol)	{Beep(600,250);}	// Just right
		else if (diff       > vtol)	{Beep(800,250);}	// Too high
		else						{Beep(400,250);}	// Too low

		if (!_kbhit()) goto L18081;						// Check for keyboard hit
		ckey = _getch();								// Read key
		printf("\n\tKey pressed=%c\n",ckey);
		if (ckey=='D' || ckey=='d') goto L180021;		// Did press D
		goto L18081;									// Did not press D

	} // close if adc_err[5]

	// Offer to trim Vcore
L18082:
	if (adc_err[3]==0 && adc_err[12]==0) fprintf(test_file,"\tVcore is in range, skipping trim. Read= %5.3f Expect=%5.3f\n\n",v1p5core,vcore_expect);

	if (adc_err[3]!=0 && adc_err[12]==0) {			// Vcore
		printf("\tVcore=%5.3f Target=%5.3f NoLoad=%5.3f Acore=%5.3f\n",v1p5core,vcore_expect,vcore_noload,a1p5core);
		printf("\tTrim now, Skip or Exit (T,S,E) <cr=S>? ");

		gets(line);
		n = strlen(line);
		i = line[0];

		if (n==0 || (i=='E' || i=='e')) goto tmb_auto_done;
		if (n==0 || (i=='S' || i=='s')) {
			tmb_nskipped[itest]=1;
			goto L18084;
		}

		// Trimming Vcore
		printf("\tAdjust +Vcore R683.\n");
		printf("\tPress D when done\n");

L18083:
		adc_read(base_adr);								// Returns data via common block

		printf("\tVcore=%5.3f Target=%5.3f\r",v1p5core,vcore_expect);
		diff = (v1p5core-vcore_expect);
		vtol = 0.001;

		if      (abs(diff) <= vtol)	{Beep(600,250);}	// Just right
		else if (diff       > vtol)	{Beep(800,250);}	// Too high
		else						{Beep(400,250);}	// Too low

		if (!_kbhit()) goto L18083;						// Check for keyboard hit
		ckey = _getch();								// Read key
		printf("\n\tKey pressed=%c\n",ckey);
		if (ckey=='D' || ckey=='d') goto L180021;		// Did press D
		goto L18083;

	} // close if adc_err[3]

L18084:
	for (i=1; i<= 9; ++i) {if (adc_err[i]    !=0) tmb_nfailed[itest]=1;}
	for (i=0; i<=13; ++i) {if (adc_err_mez[i]!=0) tmb_nfailed[itest]=1;}

	sprintf(cvcore,"%5.3f",v1p5core);
	svcore = string(cvcore);

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
	aokf(string("ADC Voltages  Vcore  =").append(svcore),itest,tmb_npassed[itest]);

	if (fpga_series=="XC6SLX150")
	{
		sprintf(cv2p5_mez,"%5.3f",v2p5_mez);
		sprintf(cv1p8_mez,"%5.3f",v1p8_mez);
		sprintf(cv1p2_mez,"%5.3f",v1p2_mez);

		sv2p5_mez = string(cv2p5_mez);
		sv1p8_mez = string(cv1p8_mez);
		sv1p2_mez = string(cv1p2_mez);

		v2p5_mez_ok = (adc_err_mez[1]==0) ? 1:0;
		v1p8_mez_ok = (adc_err_mez[3]==0) ? 1:0;
		v1p2_mez_ok = (adc_err_mez[4]==0) ? 1:0;

		aokf(string("ADC Voltages  S6 2.5V=").append(sv2p5_mez),itest,v2p5_mez_ok);
		aokf(string("ADC Voltages  S6 1.8V=").append(sv1p8_mez),itest,v1p8_mez_ok);
		aokf(string("ADC Voltages  S6 1.2V=").append(sv1p2_mez),itest,v1p2_mez_ok);
	}
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	// Check Temperatures
	itest=22;

	ttol=0.35;
	tok("T tmb pcb      ",t_local_f_tmb,   77.0, ttol, adc_err[15]);
	tok("T fpga chip    ",t_remote_f_tmb, 104.0, ttol, adc_err[16]);

	if (fpga_series=="XC6SLX150")
	{
		tfpga_mez =  32.0+(9.0/5.0)*tfpga_mez;
		tsink_mez =  32.0+(9.0/5.0)*tsink_mez;

		tok("+tfpga  S6 Mez ", tfpga_mez,	78.0,		 .2000,		adc_err_mez[ 5]);
		tok("+tsink  S6 Mez	", tsink_mez,	78.0,		 .2000,		adc_err_mez[ 6]);
	}

	for (i=15; i<=16; ++i) {if (adc_err[i]    !=0) tmb_nfailed[itest]=1;}
	for (i=5;  i<=6;  ++i) {if (adc_err_mez[i]!=0) tmb_nfailed[itest]=1;}
	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	

	tadc_ok = (adc_err[15]==0 && adc_err[16]==0) ? 1:0;
	aokf("ADC Temperatures",itest,tadc_ok);

	if (fpga_series=="XC6SLX150")
	{
		sprintf(ctfpga_mez,"%5.2f",tfpga_mez);
		sprintf(ctsink_mez,"%5.2f",tsink_mez);

		stfpga_mez = string(ctfpga_mez);
		stsink_mez = string(ctsink_mez);

		tfpga_ok = (adc_err_mez[5]==0) ? 1:0;
		tsink_ok = (adc_err_mez[6]==0) ? 1:0;

		aokf(string("ADC Temperatures S6 Tfpga=").append(stfpga_mez),itest,tfpga_ok);
		aokf(string("ADC Temperatures S6 Tsink=").append(stsink_mez),itest,tsink_ok);
	}

	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//	Unstress ccb gtl drivers
	wr_data = 0x0000;						// All bits 0
	wr_data = (~wr_data) & 0x0FFFF;			// invert
	adr     = ccb_txa_adr+base_adr;
	status	= vme_write(adr,wr_data);
	wr_data = 0xFFFF;						// bits 17:16
	wr_data = (~wr_data) & 0x0000F;			// invert
	adr     = ccb_txb_adr+base_adr;
	status	= vme_write(adr,wr_data);

	//	TMB2005E with heater-code firmware test results
	//	Unit	+5.0a	+3.3a	+1.8a	+1.5aCore	+1.05aTT	+3.3Arat	Tchip	Tpcb
	//	TMB5013	0.275	0.775	7.490	0.870		0.030		-			104F	77F

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	3D3444 Verify
	//------------------------------------------------------------------------------
L18085:
	// itest=23,24,25
	// Turn off step mode
	sel_step_alct = 0x1FE0;
	wr_data = sel_step_alct;
	adr     = vme_step_adr+base_adr;
	status  = vme_write(adr,wr_data);

	for (ichip=0; ichip<=2; ++ichip) {
		itest = ichip+23;

		for (ipass=1;     ipass<=10; ++ipass) {
			for (ich=0;       ich<=3;    ++ich  ) {
				for (ddd_delay=0; ddd_delay<=12; ddd_delay=ddd_delay+4) {

					wr_data = (ddd_delay << (ich*4));
					adr	    = base_adr+vme_ddd0_adr+2*ichip;
					status  = vme_write(adr,wr_data);

					// Start DDD state machine
					adr	    = base_adr+vme_dddsm_adr;
					status  = vme_read(adr,rd_data);
					autostart = rd_data & 0x0020;	// get current autostart state
					wr_data	= 0x0000 | autostart;	// stop machine
					status	= vme_write(adr,wr_data);
					wr_data = 0x0001 | autostart;	// start machine
					status	= vme_write(adr,wr_data);
					wr_data = 0x0000 | autostart;	// unstart machine
					status	= vme_write(adr,wr_data);

					// Wait for it to finish
					for (i=1; i<=1000; ++i) {
						status   = vme_read(adr,rd_data);
						ddd_busy = (rd_data >> 6) & 0x1;
						ddd_verify_ok = (rd_data >> 7) & 0x1;
						if (ddd_busy==0) goto L18086;
					}
					tmb_nfailed[itest]=1;
					fprintf(stdout,   "\t3d3444 state machine timeout ich=%2i ddd_delay=%3i\n",ich,ddd_delay);
					fprintf(test_file,"\t3d3444 state machine timeout ich=%2i ddd_delay=%3i\n",ich,ddd_delay);

L18086:
					if (ddd_verify_ok!=1 && !(debug_loop || debug_step)) {
						tmb_nfailed[itest]=1;
						fprintf(stdout,   "\t3d3444 verify failed ich=%2i ddd_delay=%3i\n",ich,ddd_delay);
						fprintf(test_file,"\t3d3444 verify failed ich=%2i ddd_delay=%3i\n",ich,ddd_delay);
						printf("\tSkip, Loop, Debug, Continue, Exit[s,l,d,c,e] ? ");

						gets(line);
						n = strlen(line);
						i = line[0];

						if (n==1 && (i=='E' || i=='e')) goto tmb_auto_done;
						if (n==1 && (i=='L' || i=='l')) debug_loop = true;
						if (n==1 && (i=='D' || i=='d')) debug_step = true;
						if (n==1 && (i=='S' || i=='s')) goto L18090;
					} // close if ddd_verify

					if (debug_loop || debug_step) goto L18085;

				}	// close ddd_delay
			}	// close ich					// no keys left, advance channel
		}	// close ipass

		if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;

		sprintf(cid,"%1i",ichip);
		sid = string(cid);

		aokf(string("3D3444 Chip ").append(sid).append(string(" Verify")),itest,tmb_npassed[itest]);
		if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	}	// close ichip

	// Check clock lock status, tack onto last itest
	adr	   = base_adr+vme_dddsm_adr;
	status = vme_read(adr,rd_data);

	lock_tmb_clock0    = (rd_data >>  8) & 0x1;
	lock_tmb_clock0d   = (rd_data >>  9) & 0x1;
	lock_tmb_clock1    = (rd_data >> 10) & 0x1;
	lock_alct_rxclock  = (rd_data >> 11) & 0x1;
	lock_alct_rxclockd = (rd_data >> 12) & 0x1;
	lock_mpc_clock     = (rd_data >> 13) & 0x1;
	lock_dcc_clock     = (rd_data >> 14) & 0x1;
	lock_rpc_rxalt1    = (rd_data >> 15) & 0x1;

	fprintf(test_file,"\tlock_tmb_clock0   = %1i\n",lock_tmb_clock0);
	fprintf(test_file,"\tlock_tmb_clock0d  = %1i\n",lock_tmb_clock0d);
	fprintf(test_file,"\tlock_tmb_clock1   = %1i\n",lock_tmb_clock1);
	fprintf(test_file,"\tlock_alct_rxclock = %1i\n",lock_alct_rxclock);
	fprintf(test_file,"\tlock_alct_rxclockd= %1i\n",lock_alct_rxclockd);
	fprintf(test_file,"\tlock_mpc_clock    = %1i\n",lock_mpc_clock);
	fprintf(test_file,"\tlock_dcc_clock    = %1i\n",lock_dcc_clock);
	fprintf(test_file,"\tlock_rpc_rxalt1   = %1i\n",lock_rpc_rxalt1);

	rd_data = rd_data & 0x7F00;		// blank non-locking bits, ignore rpc_done
	status  = cks("DCM clock lock status",rd_data,0x7F00);

	if (status!=0) {
		tmb_nfailed[itest]=1;
		printf("\tlock_tmb_clock0   = %1i\n",lock_tmb_clock0);
		printf("\tlock_tmb_clock0d  = %1i\n",lock_tmb_clock0d);
		printf("\tlock_tmb_clock1   = %1i\n",lock_tmb_clock1);
		printf("\tlock_alct_rxclock = %1i\n",lock_alct_rxclock);
		printf("\tlock_alct_rxclockd= %1i\n",lock_alct_rxclockd);
		printf("\tlock_mpc_clock    = %1i\n",lock_mpc_clock);
		printf("\tlock_dcc_clock    = %1i\n",lock_dcc_clock);
		printf("\tlock_rpc_rxalt1   = %1i\n",lock_rpc_rxalt1);
	}

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;	
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Backplane Loopback Series
	//------------------------------------------------------------------------------
L18090:
	if (skip_loopback_series) {
		printf("\tSkip Backplane Loopback Series? s=skip <cr>=do it: ");
		gets(line);
		n = strlen(line);
		i = line[0];

		if (n==1 && (i=='s' || i=='S')) goto L18150;
	}

	debug_loop = false;
	debug_step = false;

	// Initialze looback registers
	//	sel_loopbk = 0x0A9A;	// NB loopbk bits are different for normal tmb firmware
	sel_loopbk = 0x0A9E;	// NB loopbk bits are different for normal tmb firmware TMB2005
	adr        = vme_loopbk_adr+base_adr;
	wr_data    = sel_loopbk;
	status	   = vme_write(adr,wr_data);

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	GTL CCB+MPC Backplane Loopback
	//------------------------------------------------------------------------------
	// Loop over tx bits
L18100:
	itest=26;

	for (ipass=1; ipass<=100; ++ipass) {
		for (itx=0;   itx<=17;    ++itx  ) {

			// Transmit walking 1 to CCB drivers, inverted for GTLP
			wr_data = (1 << itx);					// bits 15:0
			wr_data = (~wr_data) & 0x0FFFF;			// invert
			adr     = ccb_txa_adr+base_adr;
			status	= vme_write(adr,wr_data);

			wr_data = ((1 << itx) >> 16);			// bits 17:16
			wr_data = (~wr_data) & 0x0000F;			// invert
			adr     = ccb_txb_adr+base_adr;
			status	= vme_write(adr,wr_data);

			// Read CCB input registers
			status	= vme_read(adr=ccb_rxa_adr+base_adr,ccb_rxa);
			status	= vme_read(adr=ccb_rxb_adr+base_adr,ccb_rxb);
			status	= vme_read(adr=ccb_rxc_adr+base_adr,ccb_rxc);
			status	= vme_read(adr=ccb_rxd_adr+base_adr,ccb_rxd);

			// Read MPC input registers
			status	= vme_read(adr=mpc_rxa_adr+base_adr,mpc_rxa);
			status	= vme_read(adr=mpc_rxb_adr+base_adr,mpc_rxb);

			// Decode received data
			ccb_rx_bank0 = (ccb_rxa >> 0) | ((ccb_rxb & 0x0003) << 16);	// ccb_rx[17: 0] 18 bits
			ccb_rx_bank1 = (ccb_rxb >> 2) | ((ccb_rxc & 0x000F) << 14);	// ccb_rx[35:18] 18 bits
			ccb_rx_bank2 = (ccb_rxc >> 4) | ((ccb_rxd & 0x0007) << 12);	// ccb_rx[50:36] 15 bits
			ccb_rx_bank3 = (ccb_rxd >> 3) & 0x1FFFF;					// ccb_tx[26:18]  9 bits

			ccb_rx_bank0 = (~ccb_rx_bank0) & 0x3FFFF;	// un-invert
			ccb_rx_bank1 = (~ccb_rx_bank1) & 0x3FFFF;
			ccb_rx_bank2 = (~ccb_rx_bank2) & 0x07FFF;
			ccb_rx_bank3 = (~ccb_rx_bank3) & 0x001FF;

			mpc_rx_bank0 = (~mpc_rxa) & 0x0FFFF;		// un-invert	mpc_tx[15: 0]
			mpc_rx_bank1 = (~mpc_rxb) & 0x0FFFF;		// un-invert	mpc_tx[31:16]

			// Check rx vs tx
			wr_pat = (1 << itx);
			ccb_err = 0;

			if (wr_pat!=ccb_rx_bank0          ) ccb_err = ccb_err | 0x11;
			if (wr_pat!=ccb_rx_bank1          ) ccb_err = ccb_err | 0x12;
			if (wr_pat!=ccb_rx_bank2 && itx<15) ccb_err = ccb_err | 0x14;
			if (wr_pat!=ccb_rx_bank3 && itx< 9) ccb_err = ccb_err | 0x18;
			if (wr_pat!=mpc_rx_bank0 && itx<16) ccb_err = ccb_err | 0x2100;
			if (wr_pat!=mpc_rx_bank1 && itx<16) ccb_err = ccb_err | 0x2200;

			if ((ccb_err!=0 && !debug_loop) || debug_step) {
				tmb_nfailed[itest]=1;

				fprintf(stdout,   "\tError: CCB Backplane Loopback: bit%2i bank%4.4X\n",itx,ccb_err);
				fprintf(stdout,   "\tccb read=%8.8X %8.8X %8.8X %8.8X \n",ccb_rx_bank0,ccb_rx_bank1,ccb_rx_bank2,ccb_rx_bank3);
				fprintf(stdout,   "\tmpc read=%8.8X %8.8X \n",mpc_rx_bank0,mpc_rx_bank1);
				fprintf(stdout,   "\texpect  =%8.8X \n",wr_pat);

				fprintf(test_file,"\tError: CCB Backplane Loopback: bit%2i bank%4.4X\n",itx,ccb_err);
				fprintf(test_file,"\tccb read=%8.8X %8.8X %8.8X %8.8X \n",ccb_rx_bank0,ccb_rx_bank1,ccb_rx_bank2,ccb_rx_bank3);
				fprintf(test_file,"\tmpc read=%8.8X %8.8X \n",mpc_rx_bank0,mpc_rx_bank1);
				fprintf(test_file,"\texpect  =%8.8X \n",wr_pat);

				if (itx==8) {
					printf("\tI told you to set SH105 2-3!\n");
					printf("\tSet it, and restart tests\n");
				}

				printf("\tSkip, Loop, Debug, Continue, Exit [s,l,d,c,e] ? ");

				gets(line);
				n = strlen(line);
				i = line[0];

				if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
				if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L18110;}
				if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
				if (n==1 && (i=='D' || i=='d'))  debug_step = true;
			} // close if ccb_err

			// Close test loops
		} // close for itx
	} // close for ipass
	if (debug_loop) goto L18100;

	// Set all GTLP signals high to reduce power and de-assert adb_pulse_async
	wr_data = 0xFFFF;
	adr     = ccb_txa_adr+base_adr;
	status	= vme_write(adr,wr_data);
	adr     = ccb_txb_adr+base_adr;
	status	= vme_write(adr,wr_data);

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("CCB  Backplane Loopback",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

L18110:
	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	DMB Backplane Loopback
	//------------------------------------------------------------------------------
	// Loop over tx bits
L18120:
	itest=27;

	for (ipass=1; ipass<=100; ++ipass) {
		for (ibank=0; ibank<=3;   ++ibank) {

			if (ibank==0 || ibank==1) nperbank=8;
			if (ibank==2 || ibank==3) nperbank=6;

			for (itx=0; itx<=nperbank-1; ++itx) {
				wr_pat = (1 << itx);

				// Transmit walking 1 to DMB drivers
				for (i=0; i<=3; ++i) {
					adr     = dmb_txa_adr+i*2+base_adr;
					wr_data = 0;
					if (ibank==i) wr_data=wr_pat;	
					status	= vme_write(adr,wr_data);
				}

				ibit=0;
				if (ibank==3) ibit=(wr_pat >> 5) & 0x0001;	// dmb clock step bit
				sel_step_alct = 0x1910 | (ibit << 1);
				adr     = vme_step_adr+base_adr;
				wr_data = sel_step_alct;
				status  = vme_write(adr,wr_data);

				// Read DMB input registers
				status	= vme_read(adr=(dmb_rxa_adr+base_adr),dmb_rxa);
				status	= vme_read(adr=(dmb_rxb_adr+base_adr),dmb_rxb);
				status	= vme_read(adr=(dmb_rxc_adr+base_adr),dmb_rxc);
				status	= vme_read(adr=(dmb_rxd_adr+base_adr),dmb_rxd);

				// Downshift rx data from tx registers
				dmb_rxa = (dmb_rxa >> 8);
				dmb_rxb = (dmb_rxb >> 8);
				dmb_rxc = (dmb_rxc >> 8);
				dmb_rxd = (dmb_rxd >> 8);

				// Check rx vs tx
				dmb_err=false;

				if (ibank==0) dmb_err = dmb_rxa!=wr_pat || dmb_rxb!=0 || dmb_rxc!=0 || dmb_rxd!=0;
				if (ibank==1) dmb_err = dmb_rxb!=wr_pat || dmb_rxa!=0 || dmb_rxc!=0 || dmb_rxd!=0;
				if (ibank==2) dmb_err = dmb_rxc!=wr_pat || dmb_rxa!=0 || dmb_rxb!=0 || dmb_rxd!=0;
				if (ibank==3) dmb_err = dmb_rxd!=wr_pat || dmb_rxa!=0 || dmb_rxb!=0 || dmb_rxc!=0;

				if ((dmb_err && !debug_loop) || debug_step) {
					tmb_nfailed[itest]=1;

					fprintf(test_file,"\tError: DMB Backplane Loopback: bit=%2i bank=%1i %s\n",itx,ibank,dmb_chip[ibank].c_str());
					fprintf(test_file,"\tdmb read = %8.8X %8.8X %8.8X %8.8X\n",dmb_rxa,dmb_rxb,dmb_rxc,dmb_rxd);
					fprintf(test_file,"\texpect   = %8.8X\n",wr_pat);

					fprintf(stdout   ,"\tError: DMB Backplane Loopback: bit=%2i bank=%1i %s\n",itx,ibank,dmb_chip[ibank].c_str());
					fprintf(stdout   ,"\tdmb read = %8.8X %8.8X %8.8X %8.8X\n",dmb_rxa,dmb_rxb,dmb_rxc,dmb_rxd);
					fprintf(stdout   ,"\texpect   = %8.8X\n",wr_pat);

					printf("\tSkip, Loop, Debug, Continue, Exit [s,l,d,c,e] ? ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
					if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1;goto L18130;}
					if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					if (n==1 && (i=='D' || i=='d'))  debug_step = true;
				} // close if dmb_err

			}	// close itx
		}	// close ibank
	}	// close ipass

	if (debug_loop) goto L18120;

	if (tmb_nfailed[itest]==0)tmb_npassed[itest]=1;
	aokf("DMB  Backplane Loopback",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	RPC Backplane Loopback
	//------------------------------------------------------------------------------
	// Loop over tx bits
L18130:
	itest=28;

	sel_boot_jtag   = 0x0180;
	sel_boot_nojtag = 0x0100;
	sel_rpc_chain   = 0x00E8;

	for (ipass=1; ipass<=100; ++ipass) {
		for (ibank=0; ibank<=1;   ++ibank) {

			if (ibank==0) nperbank = 8;
			if (ibank==1) nperbank = 16;

			for (itx=0; itx<=nperbank-1; ++itx) {

				wr_pat = (1 << itx);

				// Transmit walking 1 to RPC driver bank 0 U42A-->U42B
				wr_data = 0;
				if (ibank==0) wr_data = wr_pat;

				tck_rpc     = (wr_data >> 7) & 0x0001;	// rpc_tx7
				tms_rpc     = (wr_data >> 6) & 0x0001;	// rpc_tx6
				tdi_rpc     = (wr_data >> 5) & 0x0001;	// rpc_tx5
				rpc_clock   = (wr_data >> 4) & 0x0001;	// rpc_tx4	step[2]
				rpc_sync    = (wr_data >> 3) & 0x0001;	// rpc_tx3
				rpc_posneg  = (wr_data >> 2) & 0x0001;	// rpc_tx2
				rpc_loop_tm = (wr_data >> 1) & 0x0001;	// rpc_tx1
				smb_clk     = (wr_data >> 0) & 0x0001;	// rpc_tx0
				smb_data    = 0;

				adr      = vme_ratctrl_adr+base_adr;		// clear rat control bits
				wr_data  = 0;
				status   = vme_write(adr,wr_data);

				adr      = vme_adc_adr+base_adr;			// rpc_tx0 (smb_clk)
				status   = vme_read(adr,rd_data);
				adc_data = rd_data;

				wr_data  = adc_data & 0xF9FF | (smb_data << 10);
				wr_data  = wr_data | (smb_clk << 9);
				status   = vme_write(adr,wr_data);

				adr      =rpc_txb_adr+base_adr;				// rpc_tx[3:1]
				wr_data  = (rpc_sync    << 0) |
					(rpc_posneg  << 1) |
					(rpc_loop_tm << 2);
				status   = vme_write(adr,wr_data);

				adr      = vme_step_adr+base_adr;			// rpc_tx4 (rpc_clock)
				wr_data  = 0x1910 | (rpc_clock << 2);
				status   = vme_write(adr,wr_data);

				adr      = tmb_boot_adr + base_adr;			// rpc_tx[7:5]
				status   = vme_read(adr,boot_data);
				boot_data= boot_data & 0xFF00;
				wr_data  = boot_data | sel_boot_jtag | sel_rpc_chain;
				wr_data  = wr_data | tdi_rpc | (tms_rpc << 1) | (tck_rpc << 2);
				status   = vme_write(adr,wr_data);

				// Transmit walking 1 to RPC driver bank 1 U43-->U44. rpc_txa maps to rpc_rx[25:10] pins
				adr     = rpc_txa_adr+base_adr;
				wr_data = 0;
				if (ibank==1) wr_data=wr_pat;
				status	= vme_write(adr,wr_data);

				// Read RPC input registers
				status	= vme_read(adr=(rpc_rxa_adr+base_adr ),rpc_rxa);	// rpc_rx[15:0]
				status	= vme_read(adr=(rpc_rxb_adr+base_adr ),rpc_rxb);	// rpc_rx[34:19]
				status	= vme_read(adr=(rpc_rxc_adr+base_adr ),rpc_rxc);	// rpc_rx[38],rpc_rx[37:35],rpc_rx[18:16]
				status	= vme_read(adr=(tmb_boot_adr+base_adr),boot_data);	// tdo_rpc (rpc_rx[39])

				dprintf(stdout,"\trpc_rxa=%4.4X\n",rpc_rxa);
				dprintf(stdout,"\trpc_rxb=%4.4X\n",rpc_rxb);
				dprintf(stdout,"\trpc_rxc=%4.4X\n",rpc_rxc);
				dprintf(stdout,"\tboot   =%4.4X\n",boot_data);

				// Construct bank 0 receive data
				//tdo_rpc		= (boot_data >> 15) & 0x0001;
				tdo_rpc		= tck_rpc;				// tdo_rpc is not looped back, so let it pass
				rpc_smbrx	= (rpc_rxc >> 6) & 0x0001;
				rpc_rx3126	= (rpc_rxb >> 7) & 0x003F;

				rpc_rx_bank0= (tdo_rpc   << 7) |		// received rpc_tx7
					(rpc_smbrx << 6) |		// received rpc_tx6
					rpc_rx3126;				// received rpc_tx[5:0]

				// Construct bank 1 receive data
				rpc_rxh[36]	= (rpc_rxc >> 4 ) & 0x1;
				rpc_rxh[37]	= (rpc_rxc >> 5 ) & 0x1;
				rpc_rxh[32]	= (rpc_rxb >> 13) & 0x1;
				rpc_rxh[33]	= (rpc_rxb >> 14) & 0x1;
				rpc_rxh[34]	= (rpc_rxb >> 15) & 0x1;
				rpc_rxh[35]	= (rpc_rxc >> 3 ) & 0x1;
				rpc_rxh[0]	= (rpc_rxa >> 0 ) & 0x1;
				rpc_rxh[1]	= (rpc_rxa >> 1 ) & 0x1;
				rpc_rxh0902	= (rpc_rxa >> 2 ) & 0xFF;

				rpc_rx_bank1 = (rpc_rxh[36] << 0) |
					(rpc_rxh[37] << 1) |
					(rpc_rxh[32] << 2) |
					(rpc_rxh[33] << 3) |
					(rpc_rxh[34] << 4) |
					(rpc_rxh[35] << 5) |
					(rpc_rxh[0]  << 6) |
					(rpc_rxh[1]  << 7) |
					(rpc_rxh0902 << 8);

				// Check rx vs tx
				rpc_err=false;

				if (ibank==0) rpc_err = rpc_rx_bank0!=wr_pat || rpc_rx_bank1!=0;
				if (ibank==1) rpc_err = rpc_rx_bank1!=wr_pat || rpc_rx_bank0!=0;

				if ((rpc_err!=0 && !debug_loop) || debug_step) {
					tmb_nfailed[itest]=1;

					fprintf(test_file,"\tError: RPC Backplane Loopback: bit=%2i bank=%1i %s\n",itx,ibank,rpc_chip[ibank].c_str());
					fprintf(test_file,"\trpc read=%8.8X %8.8X\n",rpc_rx_bank1,rpc_rx_bank0);
					fprintf(test_file,"\texpect  =%8.8X\n",wr_pat);

					fprintf(stdout,   "\tError: RPC Backplane Loopback: bit=%2i bank=%1i %s\n",itx,ibank,rpc_chip[ibank].c_str());
					fprintf(stdout,   "\trpc read=%8.8X %8.8X\n",rpc_rx_bank1,rpc_rx_bank0);
					fprintf(stdout,   "\texpect  =%8.8X\n",wr_pat);

					printf("\tSkip, Loop, Debug, Continue, Exit[s,l,d,c,e] ? ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
					if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L18140;}
					if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					if (n==1 && (i=='D' || i=='d'))  debug_step = true;

				}  // close if prc_err
			}  // itx
		}  // ibank
	}  // ipass

	if (debug_loop) goto L18130;

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("RPC  Backplane Loopback",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	ALCT Backplane Loopback
	//------------------------------------------------------------------------------
	//	tx[0]		jtag_alct[1]	->	alct_rx[0]=jtag_alct[0]=tdo_alct
	//	tx[4:1]		jtag_alct[5:2]	->	alct_rx[4:1]
	//	tx[16:5]	alct_tx[16:5]	->	alct_rx[16:5]
	//	tx[17]		adb_pulse_async	->	alct_rx[17]
	//	tx[18]		/hard_reset_alct->	alct_rx[18]
	//	tx[19]		alct_tx[19]		->	alct_rx[19]
	//	tx[20]		alct_tx[20]		->	alct_rx[23]
	//	tx[23:21]	alct_tx[23:21]	->	alct_rx[26:24]
	//	tx[24]		alct_loop		->	alct_rx[27]
	//	tx[25]		alct_txoe		->	alct_rx[22]
	//	tx[26]		alct_clock_en	->	alct_rx[20]
	//	tx[27]		alct_clock		->	alct_rx[21]
	//	tx[28]		alct_rxoe		->	alct_rx[28]
	//	tx[29]		rpc_free_tx0	->	alct_rx[29] rpc_done
	//	tx[30]		/hard_reset_rpc	->	alct_rx[30] rpc_dsn
	//	tx[31]		smb_data		->	alct_rx[31] no read back
	//		
	// Put ALCT into normal mode, and enable ALCT transition module (disable SCSI)
L18140:
	itest=29;

	sel_boot_jtag  = 0x0180;
	sel_boot_nojtag= 0x0100;
	sel_step_alct  = 0x1910;
	//	sel_loopbk     = 0x0A90;	// NB loopbk bits are different for normal tmb firmware
	sel_loopbk     = 0x0A9C;	// NB loopbk bits are different for normal tmb firmware TMB2005

	adr     = vme_loopbk_adr+base_adr;
	wr_data = sel_loopbk;
	status  = vme_write(adr,wr_data);

	// Loop over alct tx bits
	for (ijtag_src=0; ijtag_src<=1; ++ijtag_src) {	// 0=use boot reg jtag, 1=fpga user jtag
		for (ipass=1;     ipass<=100;   ++ipass    ) {
			for (itx=0;       itx<=32;      ++itx      ) {	// 32 wraps back to 0 to clear alct data for next stage

				wr_pat =(1 << itx);

				jtag_alct        = (wr_pat >>  0) & 0x001F;	// tx[4:0]
				alct_tx_lo       = (wr_pat >>  5) & 0x0FFF;	// tx[16:5]
				adb_pulse_async  = (wr_pat >> 17) & 0x0001;	// tx[17]
				nhard_reset_alct = (wr_pat >> 18) & 0x0001;	// tx[18]
				alct_tx_hi       = (wr_pat >> 19) & 0x001F;	// tx[23:19]
				alct_loop        = (wr_pat >> 24) & 0x0001;	// tx[24]
				alct_txoe        = (wr_pat >> 25) & 0x0001;	// tx[25]
				alct_clock_en    = (wr_pat >> 26) & 0x0001;	// tx[26]
				alct_clock       = (wr_pat >> 27) & 0x0001;	// tx[27]
				alct_rxoe        = (wr_pat >> 28) & 0x0001;	// tx[28]
				rpc_free_tx0     = (wr_pat >> 29) & 0x0001;	// tx[29]
				nhard_reset_rpc  = (wr_pat >> 30) & 0x0001;	// tx[30]
				smb_data         = (wr_pat >> 31) & 0x0001;	// tx[31]

				// Invert hard reset
				nhard_reset_alct = (~nhard_reset_alct) & 0x0001;
				nhard_reset_rpc  = (~nhard_reset_rpc ) & 0x0001;

				// Send to ALCT output registers
				adr		= tmb_boot_adr+base_adr;
				if (ijtag_src==0) wr_data = sel_boot_jtag   & 0xFEFF;		// blank alct_hard_reset bit
				if (ijtag_src==1) wr_data = sel_boot_nojtag & 0xFEFF;
				wr_data = wr_data | (nhard_reset_alct << 8);				// alct_tx[18]
				wr_data = wr_data | (nhard_reset_rpc << 13);				// alct_tx[30]
				wr_data	= wr_data | jtag_alct;								// alct_tx[4:0] if ijtag_src=0
				status	= vme_write(adr,wr_data);

				adr		= vme_usr_jtag_adr+base_adr;
				wr_data	= jtag_alct;										// alct_tx[4:0] if jtag_src=1
				status	= vme_write(adr,wr_data);

				adr		= alct_txa_adr+base_adr;							// alct_tx[17:5]<=alct_txa[12:0]
				wr_data	= alct_tx_lo;										// alct_tx[16:5]
				status	= vme_write(adr,wr_data);

				adr		= alct_txb_adr+base_adr;							// alct_tx[23:19]<=alct_txb[4:0]
				wr_data	= alct_tx_hi;										// alct_tx[23:19]
				status	= vme_write(adr,wr_data);

				adr		= ccb_txa_adr+base_adr;
				wr_data	= (adb_pulse_async << 13);							// alct_tx[17]
				wr_data	= (~wr_data) & 0x0FFFF;
				status	= vme_write(adr,wr_data);

				adr		= vme_loopbk_adr+base_adr;
				wr_data	= sel_loopbk & 0xFFF1;
				wr_data	= wr_data | (alct_loop << 1);						// alct_tx[24]
				wr_data	= wr_data | (alct_txoe << 3);						// alct_tx[25]
				wr_data = wr_data | (alct_rxoe << 2);						// alct_tx[28]
				status	= vme_write(adr,wr_data);

				adr		= vme_step_adr+base_adr;
				wr_data	= sel_step_alct | (alct_clock_en << 10) | alct_clock;// alct_tx[27:26]
				status	= vme_write(adr,wr_data);

				adr		= rpc_txb_adr+base_adr;
				wr_data	= (rpc_free_tx0 << 3);								// alct_tx[29]
				status	= vme_write(adr,wr_data);

				adr		= vme_adc_adr+base_adr;
				status	= vme_read(adr,rd_data);
				adc_data= rd_data;
				wr_data	= adc_data & 0xF9FF | (smb_data << 10);				// alct_tx[31]
				status	= vme_write(adr,wr_data);

				// Read ALCT input registers
				alct_data=0;

				if (ijtag_src==0) adr = tmb_boot_adr+base_adr;
				if (ijtag_src==1) adr = vme_usr_jtag_adr+base_adr;
				status	  = vme_read(adr,rd_data);
				alct_data = alct_data | ((rd_data >> 15) & 0x1);			// alct_rx[0] is TDO

				for (ireg=0; ireg<=3; ++ireg) {
					adr		= base_adr+alct_rxa_adr+2*ireg;						// alct_rxa[7:0]<={alct_rx[7:1],0}
				status	= vme_read(adr,rd_data);							// alct_rxb[7:0]<=alct_rx[15:8]
				rd_data = rd_data & 0xFF;									// alct_rxc[7:0]<=alct_rx[23:16]
				alct_data = alct_data | (rd_data << (ireg*8));				// alct_rxd[7:0]<=alct_rx[28:24]
				}

				// ALCT_rx[29]=rpc_done
				adr     = vme_gpio_adr+base_adr;
				status  = vme_read(adr,rd_data);
				rpc_done  = (rd_data >> 4) & 0x1;							// rpc_done=gp_io[4]
				alct_data = alct_data | (rpc_done << 29);

				// ALCT_rx[30]=rpc_dsn
				adr	    = rpc_rxc_adr+base_adr;
				status  = vme_read(adr,rd_data);
				rpc_dsn   = (rd_data >> 7) & 0x0001;
				alct_data = alct_data | (rpc_dsn << 30);

				// ALCT_rx[31]=smb_data can not read back, so simulate it
				alct_data = alct_data | (smb_data << 31);

				// Check rx vs tx
				alct_err = 0;
				if (wr_pat!=alct_data) alct_err=alct_err | 0x11;

				if ((alct_err!=0 && !debug_loop) || debug_step) {
					tmb_nfailed[itest]=1;

					fprintf(test_file,"\tError: ALCT Backplane Loopback: ijtag_src=%1i itx=%3i bank=%4.4X\n",ijtag_src,itx,alct_err);
					fprintf(test_file,"\talct read=%8.8X\n",alct_data);
					fprintf(test_file,"\texpect   =%8.8X\n",wr_pat);

					fprintf(stdout,   "\tError: ALCT Backplane Loopback: ijtag_src=%1i itx=%3i bank=%4.4X\n",ijtag_src,itx,alct_err);
					fprintf(stdout,   "\talct read=%8.8X\n",alct_data);
					fprintf(stdout,   "\texpect   =%8.8X\n",wr_pat);

					printf("\tSkip, Loop, Debug, Continue, Exit[s,l,d,c,e] ? ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
					if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L18145;}
					if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					if (n==1 && (i=='D' || i=='d'))  debug_step = true;

				}	// close if alct_err

			}	// itx
		}	// ipass
	}	// ijtag_src

	if (debug_loop) goto L18140;

	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("ALCT Backplane Loopback",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");


	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Loopback backplane status report: Backplane PROMs
	//------------------------------------------------------------------------------
	//	itest=30,31

	// Select RAT JTAG chain from TMB boot register, backplane uses RAT JTAG signals
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Read FPGA/PROM IDcodes (8 bit opcode)
	for (chip_id=0; chip_id<=1; ++chip_id) {
		itest = chip_id+30;
		if (chip_id==0) opcode = 0x09;				// FPGA IDcode opcode
		if (chip_id==1) opcode = 0xFE;				// PROM IDcode opcode
		reg_len = 32;								// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		// Check ID codes
		tdi_to_i4(&tdo[0],idcode,32,0);

		sprintf(cid, "%1i",  chip_id);				// Convert chip_id to string
		sprintf(cidc,"%8.8X",idcode);				// Convert idcode  to string
		sid  = string(cid);
		sidc = string(cidc);

		if (chip_id==0) {
			status=cks(string("FPGAback ID Code ").append(sid),idcode,0x20A10093);

			if (status!=0            ) tmb_nfailed[itest]=1;
			if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
			aokf(string("FPGAback ID Code ").append(sid).append(string(" ")).append(sidc),itest,tmb_npassed[itest]);
			if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");
		}
		else {
			status = cks(string("PROMback ID Code ").append(sid),idcode,0x05034093);

			if (status!=0            ) tmb_nfailed[itest]=1;
			if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
			aokf(string("PROMback ID Code ").append(sid).append(string(" ")).append(sidc),itest,tmb_npassed[itest]);
			if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");
		} // close if status

	} // close chip_id

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Loopback backplane status report: Backplane USER1
	//------------------------------------------------------------------------------
	itest=32;	

	// Read Backplane USER1 register (5 bit opcode)
	for (ibplsync=1; ibplsync<=10; ++ibplsync) {
		chip_id = 0;
		opcode  = 0x02;									// FPGA USER1 opcode
		reg_len = 192;									// USER1 register length
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		//	for (i=0; i<=191; ++i) printf("%1i",tdo[i]); printf("\n");

		// Decode Backplane USER1 register
		for (i=0; i<reg_len; ++i) {
			bs[i]=tdo[i];
		}

		tdi_to_i4(&tdo[  0],back_user1[0],32,0);
		tdi_to_i4(&tdo[ 32],back_user1[1],32,0);
		tdi_to_i4(&tdo[ 64],back_user1[2],32,0);
		tdi_to_i4(&tdo[ 96],back_user1[3],32,0);
		tdi_to_i4(&tdo[128],back_user1[4],32,0);
		tdi_to_i4(&tdo[160],back_user1[5],32,0);

		fprintf(test_file,"\tBackplane USER1=");
		for (i=5; i>=0; --i) fprintf(test_file,"%8.8X",back_user1[i]);
		fprintf(test_file,"\n");

		tdi_to_i4(&bs[  0],bs_begin,    4,0);
		tdi_to_i4(&bs[  4],bs_version,  4,0);
		tdi_to_i4(&bs[  8],bs_monthday,16,0);
		tdi_to_i4(&bs[ 24],bs_year,    16,0);
		tdi_to_i4(&bs[184],bs_endD,     4,0);
		tdi_to_i4(&bs[188],bs_endE,     4,0);

		// Check data integrity
		markers_ok = false;

		if (bs_begin   == 0xB &&
				bs_version == 0xD && 
				bs_endD    == 0xD && 
				bs_endE    == 0xE) markers_ok = true;

		if (markers_ok) goto L18141;
	}	// close ibplsync

	tmb_nfailed[itest]=1;
	fprintf(test_file,"\tFailed to synchronize to backplane after %4i attempts\n",ibplsync);
	fprintf(stdout,   "\tFailed to synchronize to backplane after %4i attempts\n",ibplsync);

L18141:
	fprintf(test_file,"\tSynchronized to backplane on attempt %2i     OK\n",ibplsync);
	fprintf(test_file,"\tBackplane sync attempts=%4i\n",ibplsync);

	if  (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("Synchronized to backplane FPGA",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Loopback backplane status report: Backplane USER1
	//------------------------------------------------------------------------------
	//	itest=33-41

	// Decode data from backplane fpga
	for (i=1; i<=25; ++i) {
		p2a_gnd_c[i]= bs[i+39];		// p2a_gnd_c(25:1)=bs(64:40)
	}

	p2b_gnd_c[1]	= bs[65];
	p2b_gnd_c[3]	= bs[66];
	p2b_gnd_c[5]	= bs[67];
	p2b_gnd_c[7]	= bs[68];
	p2b_gnd_c[9]	= bs[69];
	p2b_gnd_c[11]	= bs[70];

	p2b_vtt_c[4]	= bs[71];
	p2b_vtt_c[6]	= bs[72];
	p2b_vtt_c[8]	= bs[73];
	p2b_vtt_c[10]	= bs[74];

	for (i=1; i<=25; ++i) {
		p3a_gnd_c[i]	= bs[i+74];	// p3a_gnd_c(25:1)=bs(99:75)
	}

	p3a_gnd_f[1]	= bs[100];
	p3a_gnd_f[3]	= bs[101];
	p3a_gnd_f[5]	= bs[102];
	p3a_gnd_f[7]	= bs[103];
	p3a_gnd_f[9]	= bs[104];
	p3a_gnd_f[11]	= bs[105];
	p3a_gnd_f[13]	= bs[106];
	p3a_gnd_f[15]	= bs[107];
	p3a_gnd_f[17]	= bs[108];
	p3a_gnd_f[19]	= bs[109];
	p3a_gnd_f[21]	= bs[110];
	p3a_gnd_f[23]	= bs[111];
	p3a_gnd_f[25]	= bs[112];

	p3a_vcc_a[16]	= bs[113];
	p3a_vcc_a[18]	= bs[114];
	p3a_vcc_a[20]	= bs[115];
	p3a_vcc_a[22]	= bs[116];	
	p3a_vcc_a[24]	= bs[117];

	for (i=1; i<=25; ++i) {
		p3b_gnd_c[i]	= bs[i+117];	// p3b_gnd_c(25:1)=bs(142:118)
	}

	p3b_gnd_f[1]	= bs[143];
	p3b_gnd_f[3]	= bs[144];
	p3b_gnd_f[5]	= bs[145];
	p3b_gnd_f[7]	= bs[146];
	p3b_gnd_f[9]	= bs[147];
	p3b_gnd_f[11]	= bs[148];
	p3b_gnd_f[13]	= bs[149];
	p3b_gnd_f[15]	= bs[150];
	p3b_gnd_f[17]	= bs[151];
	p3b_gnd_f[19]	= bs[152];
	p3b_gnd_f[21]	= bs[153];
	p3b_gnd_f[23]	= bs[154];
	p3b_gnd_f[25]	= bs[155];

	p3b_vcc_a[1]	= bs[156];
	p3b_vcc_a[3]	= bs[157];
	p3b_vcc_a[5]	= bs[158];
	p3b_vcc_a[7]	= bs[159];
	p3b_vcc_a[9]	= bs[160];
	p3b_vcc_a[11]	= bs[161];
	p3b_vcc_a[13]	= bs[162];
	p3b_vcc_a[15]	= bs[163];
	p3b_vcc_a[17]	= bs[164];
	p3b_vcc_a[19]	= bs[165];
	p3b_vcc_a[21]	= bs[166];
	p3b_vcc_a[23]	= bs[167];
	p3b_vcc_a[25]	= bs[168];

	p2a_gnd_c_ok	= bs[169];
	p2b_gnd_c_ok	= bs[170];
	p2b_vtt_c_ok	= bs[171];
	p3a_gnd_c_ok	= bs[172];
	p3a_gnd_f_ok	= bs[173];
	p3a_vcc_a_ok	= bs[174];
	p3b_gnd_c_ok	= bs[175];
	p3b_gnd_f_ok	= bs[176];
	p3b_vcc_a_ok	= bs[177];

	p2a_ok			= bs[178];
	p2b_ok			= bs[179];
	p3a_ok			= bs[180];
	p3b_ok			= bs[181];

	all_ok			= bs[182];
	bs_free			= bs[183];

	// Record backplane decode in log file
	fprintf(test_file,"\tbs_begin      %1.1X\n",bs_begin);
	fprintf(test_file,"\tbs_version    %1.1X\n",bs_version);
	fprintf(test_file,"\tbs_monthday   %4.4X\n",bs_monthday);
	fprintf(test_file,"\tbs_year       %4.4X\n",bs_year);
	fprintf(test_file,"\n");

	for (i= 1; i<=25; ++i  ) fprintf(test_file,"\tp2a_gnd_c[%2i]=%1i\n",i,p2a_gnd_c[i]); fprintf(test_file,"\n");
	for (i= 1; i<=11; i=i+2) fprintf(test_file,"\tp2b_gnd_c[%2i]=%1i\n",i,p2b_gnd_c[i]); fprintf(test_file,"\n");
	for (i= 4; i<=10; i=i+2) fprintf(test_file,"\tp2b_vtt_c[%2i]=%1i\n",i,p2b_vtt_c[i]); fprintf(test_file,"\n");
	for (i= 1; i<=25; ++i  ) fprintf(test_file,"\tp3a_gnd_c[%2i]=%1i\n",i,p3a_gnd_c[i]); fprintf(test_file,"\n");
	for (i= 1; i<=25; i=i+2) fprintf(test_file,"\tp3a_gnd_f[%2i]=%1i\n",i,p3a_gnd_f[i]); fprintf(test_file,"\n");
	for (i=16; i<=24; i=i+2) fprintf(test_file,"\tp3a_vcc_a[%2i]=%1i\n",i,p3a_vcc_a[i]); fprintf(test_file,"\n");
	for (i= 1; i<=25; ++i  ) fprintf(test_file,"\tp3b_gnd_c[%2i]=%1i\n",i,p3b_gnd_c[i]); fprintf(test_file,"\n");
	for (i= 1; i<=25; i=i+2) fprintf(test_file,"\tp3b_gnd_f[%2i]=%1i\n",i,p3b_gnd_f[i]); fprintf(test_file,"\n");
	for (i= 1; i<=25; i=i+2) fprintf(test_file,"\tp3b_vcc_a[%2i]=%1i\n",i,p3b_vcc_a[i]); fprintf(test_file,"\n");

	fprintf(test_file,"\tp2a_gnd_c="); for(i=25;i>=1; i=i-1) {fprintf(test_file,"%1i",p2a_gnd_c[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp2b_gnd_c="); for(i=11;i>=1; i=i-2) {fprintf(test_file,"%1i",p2b_gnd_c[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp2b_vtt_c="); for(i=10;i>=4; i=i-2) {fprintf(test_file,"%1i",p2b_vtt_c[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp3a_gnd_c="); for(i=25;i>=1; i=i-1) {fprintf(test_file,"%1i",p3a_gnd_c[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp3a_gnd_f="); for(i=25;i>=1; i=i-2) {fprintf(test_file,"%1i",p3a_gnd_f[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp3a_vcc_a="); for(i=24;i>=16;i=i-2) {fprintf(test_file,"%1i",p3a_vcc_a[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp3b_gnd_c="); for(i=25;i>=1; i=i-1) {fprintf(test_file,"%1i",p3b_gnd_c[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp3b_gnd_f="); for(i=25;i>=1; i=i-2) {fprintf(test_file,"%1i",p3b_gnd_f[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\tp3b_vcc_a="); for(i=25;i>=1; i=i-2) {fprintf(test_file,"%1i",p3b_vcc_a[i]);} fprintf(test_file,"\n");
	fprintf(test_file,"\n");

	fprintf(test_file,"\tp2a_gnd_c_ok = %1i\n",p2a_gnd_c_ok);
	fprintf(test_file,"\tp2b_gnd_c_ok = %1i\n",p2b_gnd_c_ok);
	fprintf(test_file,"\tp2b_vtt_c_ok = %1i\n",p2b_vtt_c_ok);
	fprintf(test_file,"\tp3a_gnd_c_ok = %1i\n",p3a_gnd_c_ok);
	fprintf(test_file,"\tp3a_gnd_f_ok = %1i\n",p3a_gnd_f_ok);
	fprintf(test_file,"\tp3a_vcc_a_ok = %1i\n",p3a_vcc_a_ok);
	fprintf(test_file,"\tp3b_gnd_c_ok = %1i\n",p3b_gnd_c_ok);
	fprintf(test_file,"\tp3b_gnd_f_ok = %1i\n",p3b_gnd_f_ok);
	fprintf(test_file,"\tp3b_vcc_a_ok = %1i\n",p3b_vcc_a_ok);
	fprintf(test_file,"\n");

	fprintf(test_file,"\tp2a_ok = %1i\n",p2a_ok);
	fprintf(test_file,"\tp2b_ok = %1i\n",p2b_ok);
	fprintf(test_file,"\tp3a_ok = %1i\n",p3a_ok);
	fprintf(test_file,"\tp3b_ok = %1i\n",p3b_ok);
	fprintf(test_file,"\n");

	fprintf(test_file,"\tall_ok = %1i\n",all_ok);
	fprintf(test_file,"\tbsfree = %1i\n",bs_free);
	fprintf(test_file,"\n");

	fprintf(test_file,"\tbs_endD        %1.1X\n",bs_endD);
	fprintf(test_file,"\tbs_endE        %1.1X\n",bs_endE);

	// Check backplane signals
	p2a_gnd_c_bad = 0;
	for (i=1; i<=25; ++i) {
		if  (p2a_gnd_c[i]!=0) {
			p2a_gnd_c_bad++;
			printf("\tErr: p2a_gnd_c[%2i]=%1i\n",i,p2a_gnd_c[i]);
		}}

	status = cks("p2a_gnd_c",p2a_gnd_c_bad,0);
	itest=33;

	if (status!=0            ) tmb_nfailed[itest]=1;
	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P2A Gnd Column C[25:1]",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p2b_gnd_c_bad = 0;
	for (i=1; i<=11; i=i+2) {
		if (p2b_gnd_c[i]!=0   ) {
			p2b_gnd_c_bad++;
			printf("\tErr: p2b_gnd_c[%2i]=%1i\n",i,p2b_gnd_c[i]);
		}}

	status=cks("p2b_gnd_c",p2b_gnd_c_bad,0);
	itest=34;

	if  (status!=0            ) tmb_nfailed[itest]=1;
	if  (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P2B Gnd Column C[11:1]odds",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p2b_vtt_c_bad = 0;
	for (i=4; i<=10; i=i+2) {
		if  (p2b_vtt_c[i]!=1  ) {
			p2b_vtt_c_bad++;
			printf("\tErr: p2b_vtt_c[%2i]=%1i\n",i,p2b_vtt_c[i]);
		}}

	status=cks("p2b_vtt_c",p2b_vtt_c_bad,0);
	itest=35;

	if  (status!=0            ) tmb_nfailed[itest]=1;
	if  (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P2B Vtt Column C[10:4]evens",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p3a_gnd_c_bad = 0;
	for (i=1; i<=25; ++i) {
		if  (p3a_gnd_c[i]!=0 && (i<12 || i>14)) {		// looks like and should be or:  if (p3a_gnd_c[i].ne.0.and.i.lt.12.and.i.gt.14)then
			p3a_gnd_c_bad++;
			printf("\tErr: p3a_gnd_c[%2i]=%1i\n",i,p3a_gnd_c[i]);
		}}

	status=cks("p3a_gnd_c",p3a_gnd_c_bad,0);
	itest=36;

	if  (status!=0            ) tmb_nfailed[itest]=1;
	if  (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P3A Gnd Column C[25:1]",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p3a_gnd_f_bad = 0;
	for (i=1; i<=25; i=i+2) {
		if  (p3a_gnd_f[i]!=0 && i!=13) {
			p3a_gnd_f_bad++;
			printf("\tErr: p3a_gnd_f[%2i]=%1i\n",i,p3a_gnd_f[i]);
		}}

	status=cks("p3a_gnd_f",p3a_gnd_f_bad,0);
	itest=37;

	if  (status!=0            ) tmb_nfailed[itest]=1;
	if  (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P3A Gnd Column F[25:1]odds",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p3a_vcc_a_bad = 0;
	for (i=16; i<=24; i=i+2) {
		if  (p3a_vcc_a[i]!=1   ) {
			p3a_vcc_a_bad++;
			printf("\tErr: p3a_vcc_a[%2i]=%1i\n",i,p3a_vcc_a[i]);
		}}

	status=cks("p3a_vcc_a",p3a_vcc_a_bad,0);
	itest=38;

	if (status!=0            ) tmb_nfailed[itest]=1;
	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P3A Vcc Column A[24:16]evens",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p3b_gnd_c_bad = 0;
	for (i=1; i<=25; ++i) {
		if (p3b_gnd_c[i]!=0 && (i<12 || i>14)) {	// another bad line if (p3b_gnd_c[i].ne.0.and.i.lt.12.and.i.gt.14)then
			p3b_gnd_c_bad++;
			printf("\tErr: p3b_gnd_c[%2i]=%1i\n",i,p3b_gnd_c[i]);
		}}

	status=cks("p3b_gnd_c",p3b_gnd_c_bad,0);
	itest=39;

	if  (status!=0            ) tmb_nfailed[itest]=1;
	if  (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P3B Gnd Column C[25:1]",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p3b_gnd_f_bad = 0;
	for (i=1; i<=25; i=i+2) {
		if  (p3b_gnd_f[i]!=0 && i!=13) {
			p3b_gnd_f_bad++;
			printf("\tErr: p3b_gnd_f[%2i]=%1i\n",i,p3b_gnd_f[i]);
		}}

	status=cks("p3b_gnd_f",p3b_gnd_f_bad,0);
	itest=40;

	if  (status!=0            )tmb_nfailed[itest]=1;
	if  (tmb_nfailed[itest]==0)tmb_npassed[itest]=1;
	aokf("P3B Gnd Column F[25:1]odds",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	p3b_vcc_a_bad = 0;
	for (i=1; i<=25; i=i+2) {
		if  (p3b_vcc_a[i]!=1 && i!=13) {
			p3b_vcc_a_bad++;
			printf("\tErr: p3b_vcc_a[%2i]=%1i\n",i,p3b_vcc_a[i]);
		}}

	status=cks("p3b_vcc_a",p3b_vcc_a_bad,0);
	itest=41;

	if  (status!=0            ) tmb_nfailed[itest]=1;
	if  (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("P3B Vcc Column A[25:1]odds",itest,tmb_npassed[itest]);
	if  (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	fprintf(test_file,"\n");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Burn-in loop for self-contained tests
	//------------------------------------------------------------------------------
	if (ifunc<0) {
		printf("\tBurn-in Pass %52i\n",ipass_full_auto);
		goto L1805;
	}

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	ALCT Hard Reset
	//------------------------------------------------------------------------------
	itest=42;
	// Set CCB inputs high by driving CCB ouputs to loopback backplane
L18145:
	debug_loop = false;
	debug_step = false;
	debug_beep = false;

	wr_data = 0;								// bits 15:0
	wr_data = (~wr_data) & 0x0FFFF;				// invert
	adr     = ccb_txa_adr+base_adr;
	status	= vme_write(adr,wr_data);

	wr_data = 0;								// bits 17:16
	wr_data = (~wr_data) & 0x0000F;				// invert
	adr     = ccb_txb_adr+base_adr;
	status	= vme_write(adr,wr_data);

	printf("\tALCT Hard Reset Test:\n");
	printf("\tMove shunt SH105 ccb hard reset enable to 1-2:  e=exit <cr>=run");

	gets(line);
	n = strlen(line);
	i = line[0];

	if (n==1 && (i=='E' || i=='e')) goto tmb_auto_done;
	if (n==1 && (i=='s' || i=='S')) goto L18160;
	if (n==1 && (i=='L' || i=='l')) debug_loop = true;
	if (n==1 && (i=='D' || i=='d')) debug_step = true;

	debug_beep = false;
	if (debug_loop) debug_beep = true;

	// Clear ALCT loopback bits [4:0]
	jtag_alct = 0;
	adr		= tmb_boot_adr+base_adr;
	wr_data = sel_boot_jtag & 0xFEFF;			// blank alct_hard_reset bit and jtag bits
	wr_data	= wr_data | jtag_alct;				// alct_tx[4:0]
	status	= vme_write(adr,wr_data);

	// Clear ALCT loopback bits [28]
	alct_loop = 0;								// alct_tx[24]
	alct_txoe = 0;								// alct_tx[25]
	alct_rxoe = 0;								// alct_tx[28]

	adr		= vme_loopbk_adr+base_adr;
	wr_data	= sel_loopbk & 0xFFF1;
	wr_data	= wr_data | (alct_loop << 1);		// alct_tx[24]
	wr_data	= wr_data | (alct_txoe << 3);		// alct_tx[25]
	wr_data = wr_data | (alct_rxoe << 2);		// alct_tx[28]
	status	= vme_write(adr,wr_data);

	// Clear ALCT loopback bits [26]
	alct_clock_en = 0;
	alct_clock    = 0;

	adr		= vme_step_adr+base_adr;
	wr_data	= sel_step_alct | (alct_clock_en << 10) | alct_clock; // alct_tx[27:26]
	status	= vme_write(adr,wr_data);

L18146:	
	sel_loopbk = 0x0A90;	// NB loopbk bits are different for normal tmb firmware
	alct_txoe  = 0;
	alct_rxoe  = 0;

	adr		= vme_loopbk_adr + base_adr;
	status  = vme_read(adr,rd_data);			// get current
	wr_data	= sel_loopbk;
	wr_data = wr_data | (alct_txoe << 3);
	wr_data = wr_data | (alct_rxoe << 2);
	status	= vme_write(adr,wr_data);

	// Loop over alct tx bits
	for (ipass=1;   ipass<=100; ++ipass  ) {
		for (isource=0; isource<=2; ++isource) {
			for (itx=1;     itx>=0;     --itx    ) {
				wr_pat = (((itx+1)& 0x1) << 18);			// invert

				// Toggle tx bit and send to ALCT hard reset 3-input OR u107a
				if (isource==0)	{							// boot source
					adr	 = tmb_boot_adr+base_adr;
					status  = vme_read(adr,rd_data);			// get current boot reg
					rd_data = rd_data & 0xFEFF;				// turn off alct reset bit
					wr_data = (itx << 8) | rd_data;			// 1=fire /alct hard reset, makes reset=0
					status	 = vme_write(adr,wr_data);
				}
				else if (isource==1) {						// fpga source
					adr	 = vme_step_adr+base_adr;
					status  = vme_read(adr,rd_data);			// get current step reg
					rd_data = rd_data & 0xF7FF;				// turn off alct reset bit
					wr_data = (((itx+1) & 0x1) << 11) | rd_data;// 0=fire /alct hard reset, makes reset=0
					status	 = vme_write(adr,wr_data);
				}
				else if (isource==2) {						// ccb source
					wr_data = (itx << 9);						// bits 15:0
					wr_data = (~wr_data) & 0x0FFFF;			// invert
					adr     = ccb_txa_adr+base_adr;
					status	 = vme_write(adr,wr_data);
					wr_data = 0;								// bits 17:16
					wr_data = (~wr_data) & 0x0000F;			// invert
					adr     = ccb_txb_adr+base_adr;
					status	 = vme_write(adr,wr_data);
				}
				else {
					stop("moron");
				}

				// Read ALCT input registers
				alct_data = 0;
				adr		  = base_adr+tmb_boot_adr;
				status	  = vme_read(adr,rd_data);
				alct_data = alct_data | ((rd_data >> 15) & 0x1); // rx0 is TDO

				for (ireg=0; ireg<=3; ++ireg) {
					adr		  = base_adr+alct_rxa_adr+2*ireg;
					status	  = vme_read(adr,rd_data);
					rd_data   = rd_data & 0xFF;
					alct_data = alct_data | (rd_data << (ireg*8));
				}
				dprintf(stdout,"alct_data=%8.8X\n",alct_data);

				// Check rx vs tx, alct_hard_reset is looped back to alct_rx18
				//	alct_data = alct_data & 0x00FFFFFF;	// bit 25 and 28 always 1 so mask them off
				//	alct_data = alct_data & 0x00040000;
				alct_err  = 0;
				if (wr_pat!=alct_data) alct_err=1;

				if ((alct_err!=0 && !debug_loop) || debug_step) {
					tmb_nfailed[itest]=1;

					fprintf(test_file,"\tError: ALCT Hard Reset: bit=%2i source=%5.4X\n",itx,isource);
					fprintf(test_file,"\talct read=%8.8X\n",alct_data);
					fprintf(test_file,"\texpect   =%8.8X pass=%5i\n",wr_pat,ipass);

					fprintf(stdout,   "\tError: ALCT Hard Reset: bit=%2i source=%5.4X\n",itx,isource);
					fprintf(stdout,   "\talct read=%8.8X\n",alct_data);
					fprintf(stdout,   "\texpect   =%8.8X pass=%5i\n",wr_pat,ipass);

					printf("\tSkip, Loop, Debug, Continue, Exit[s,l,d,c,e] ? ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
					if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L18150;}
					if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					if (n==1 && (i=='D' || i=='d'))  debug_step = true;
				}

				// Close loops
			}	 // itx
		}	// isource
	}	// ipass
	if (debug_loop) goto L18146;

	// Set ccb signals quiescent high
	wr_data = 0xFFFF;
	adr     = ccb_txa_adr+base_adr;
	status  = vme_write(adr,wr_data);
	adr     = ccb_txb_adr+base_adr;
	status	 = vme_write(adr,wr_data);

L18150:
	if (status!=0            ) tmb_nfailed[itest]=1;
	if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	aokf("ALCT Hard Reset",itest,tmb_npassed[itest]);
	if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	CFEB SCSI Cable Loopback ported from RAT
	//	Adapted for 2-tmb operation
	//------------------------------------------------------------------------------
L18160:
	//	itest=43,44,45,46,47

	if (!tmb_ref_exists) {
		fprintf(test_file,"\tSkipping CFEB tests, reference board absent\n");
		fprintf(stdout,   "\tSkipping CFEB tests, reference board absent\n");
		for (icfeb=0; icfeb<=4; ++icfeb) {
			itest=icfeb+43;
			tmb_nskipped[i]=1;
		}
		goto L18170;
	}

	//L91300:
	for (icfeb=0; icfeb<=4; ++icfeb) {	// 91370
		itest=icfeb+43;

L91301:
		tmb_nfailed[itest]=0;
		printf("\tTMB: CFEB SCSI Cable Loopback Test:\n");
		printf("\tConnect a 25pr cable from RAT ALCTtx to CFEB%1i S=skip <cr>=run ",icfeb+1);

		gets(line);
		n = strlen(line);
		i = line[0];

		if (n==1 && (i=='S' || i=='s')) {
			tmb_nskipped[itest]=1;
			goto L91370;	// next cfeb
		}
		if (n==1 && (i=='L' || i=='l')) debug_loop = true;
		if (n==1 && (i=='D' || i=='d')) debug_step = true;

		debug_beep = false;
		if (debug_loop) debug_beep = true;

		for (ipass=1; ipass<=1000; ++ipass) {		 // 91365
L91361:	
			sel_boot_jtag  = 0x0080;
			sel_step_alct  = 0x1C10;					// was 1d10, but that turns off cfeb3..why was it there?
			sel_step_cfeb  = 0x1C10 | (1 << (icfeb+5));	// was 1d10, but that turns off cfeb3..why was it there?
			cfeb_id_expect = 0xC0   | icfeb;
			alct_id_expect = 0xA0;
			cfeb_err=0;

			// Turn off CFEB clock drivers on DUT board
			wr_data	= sel_step_alct;
			adr		= vme_step_adr+base_adr_dut;
			status	= vme_write(adr,wr_data);

			adr		= vme_step_adr + base_adr_ref;
			status	= vme_write(adr,wr_data);

			// Put ALCT into loopback mode, enable CFEBs, and RAT ALCT SCSI on Reference Board
			sel_loopbk = 0x0A9F;		// Enable RAT, disable front SCSI !was 0A93 for tmb2004
			adr		= vme_loopbk_adr+base_adr_dut;
			wr_data = sel_loopbk;
			status	= vme_write(adr,wr_data);

			adr		= vme_loopbk_adr + base_adr_ref;
			wr_data = sel_loopbk;
			status	= vme_write(adr,wr_data);

			// Send walking 1s to ALCT transmitter
			for (itx=0; itx<=23; ++itx) {	// 91364
				wr_pat  = (1 << itx);

				wr_data = sel_boot_jtag;	status = vme_write(adr=(tmb_boot_adr+base_adr_ref),wr_data);
				wr_data = 0;				status = vme_write(adr=(alct_txa_adr+base_adr_ref),wr_data);
				wr_data = 0;				status = vme_write(adr=(alct_txb_adr+base_adr_ref),wr_data);
				wr_data = sel_step_alct;	status = vme_write(adr=(vme_step_adr+base_adr_ref),wr_data);

				if (itx>=0 && itx<=4) {
					wr_data = (1 << itx) | sel_boot_jtag;
					adr	 = tmb_boot_adr + base_adr_ref;
					status	 = vme_write(adr,wr_data);
				}
				else if (itx>=5 && itx<=17) {
					wr_data = (1 << (itx-5));
					adr	 = alct_txa_adr + base_adr_ref;
					status	 = vme_write(adr,wr_data);
				}
				else if (itx==18) {
					wr_data = (1 << 8) | sel_boot_jtag;
					adr	 = tmb_boot_adr + base_adr_ref;
					status	 = vme_write(adr,wr_data);
				}
				else if (itx==20) {
					wr_data = (1 << (itx-20)) | sel_step_alct;
					adr	 = vme_step_adr + base_adr_ref;
					status	 = vme_write(adr,wr_data);
				}
				else if (itx>=19 || itx<=23) {
					wr_data = (1 << (itx-19));
					if (itx==21) wr_data = (1 << (20-19));
					if (itx==22) wr_data = (1 << (21-19));
					if (itx==23) wr_data = (1 << (22-19));
					if (itx==24) wr_data = (1 << (23-19));
					adr	 = alct_txb_adr + base_adr_ref;
					status	 = vme_write(adr,wr_data);		
				}

				// Read back CFEB data registers from DUT board
				cfeb_data = 0;
				cfeb_base = base_adr+icfeb*cfeb_offset_adr;

				adr	    = cfeb0a_adr+cfeb_base;
				status	= vme_read(adr,rd_data);
				cfeb_id = (rd_data >> 8) & 0xFF;
				rd_data = rd_data & 0xFF;
				cfeb_data = cfeb_data | rd_data;

				if (cfeb_id!=cfeb_id_expect) {
					tmb_nfailed[itest]=1;
					printf("\tWrong CFEB id: expected1=%8.8X  read=%8.8X\n",cfeb_id_expect,cfeb_id);
				}

				adr	    = cfeb0b_adr+cfeb_base;
				status	= vme_read(adr,rd_data);
				cfeb_id = (rd_data >> 8) & 0xFF;
				rd_data = rd_data & 0xFF;
				cfeb_data = cfeb_data | (rd_data << 8);

				if (cfeb_id!=cfeb_id_expect) {
					tmb_nfailed[itest]=1;
					printf("\tWrong CFEB id: expected2=%8.8X  read=%8.8X\n",cfeb_id_expect,cfeb_id);
				}

				adr	    = cfeb0c_adr+cfeb_base;
				status	= vme_read(adr,rd_data);
				cfeb_id = (rd_data >> 8) & 0xFF;
				rd_data = rd_data & 0xFF;
				cfeb_data = cfeb_data | (rd_data << 16);

				if (cfeb_id!=cfeb_id_expect) {
					tmb_nfailed[itest]=1;
					printf("\tWrong CFEB id: expected3=%8.8X  read=%8.8X\n",cfeb_id_expect,cfeb_id);
				}

				// Un-invert the inverted ALCT bits...thanks a lot, Vlad
				cfeb_data = cfeb_data ^ 0xAEAAAA;	

				// Compare CFEB read data to ALCT write data
				if (ipass==1) fprintf(test_file,"\tCFEB%1i[%2i] read=%6.6X expect=%6.6X\n",icfeb,itx,cfeb_data,wr_pat);

				if ((cfeb_data!=wr_pat || debug_step) && (!debug_loop || debug_beep)) {
					tmb_nfailed[itest]=1;
					cfeb_err++;
					printf("\tFailed CFEB%1i bit=%2i wr=%6.6X rd=%6.6X\n",icfeb+1,itx,(1<<itx),cfeb_data);

					printf("\tSkip, Loop, Debug, Continue, Retry, Exit[s,l,d,c,r,e] ? ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='R' || i=='r'))  goto L91301;
					if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
					if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L91370;}
					if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					if (n==1 && (i=='D' || i=='d'))  debug_step = true;
				}	// close if cfeb data

			} // close CFEB bit 91364

			if (debug_loop) goto L91361;	// commented out 6/7/2005 debugging tmb2005 rev 1.0

			// Test CFEB transmit clock bit: Take ALCT out of loop-back mode
			wr_data = 0x0A9D;	// was 0A91 for tmb2004
			adr		= vme_loopbk_adr + base_adr;
			status	= vme_write(adr,wr_data);

			// Turn on CFEB clock driver on DUT
			wr_data	= (sel_step_cfeb & 0xFC1F) | (1 << (icfeb+5));
			adr		= vme_step_adr + base_adr;	
			status	= vme_write(adr,wr_data);

			// Write a 1 to CFEB clock driver
			wr_data	= (sel_step_cfeb & 0xFC1F) | (1 << (icfeb+5)) | 0x0008;
			adr		= vme_step_adr + base_adr;
			status	= vme_write(adr,wr_data);

			// Read ALCT receiver on REF
			adr		= alct_rxa_adr + base_adr_ref;
			status	= vme_read(adr,rd_data);
			alct_id = (rd_data >> 8) & 0xFF;
			rd_data = rd_data & 0xFF;

			if (alct_id!=alct_id_expect) {
				tmb_nfailed[itest]=1;
				printf("\tWrong ALCT id: expect=%8.8X read=%8.8X\n",alct_id_expect,alct_id);
			}

			// Check if ALCT read a 1, un-invert it...thanks a lot, Vlad
			rd_data = ((rd_data >> 3) & 0x0001) ^ 0x0001;

			if (ipass==1) fprintf(test_file,"\tCFEB%1i[CK] read=%6.1X expect=%6.1X\n",icfeb+1,rd_data,0x1);

			if ((rd_data!=1 || debug_step) && !debug_loop) {
				tmb_nfailed[itest]=1;
				cfeb_err++;
				printf("\tFailed CFEB%1i clock bit wr=1 rd=%6.6X\n",icfeb+1,rd_data);

				printf("\tSkip, Loop, Debug, Continue, Retry, Exit[s,l,d,c,r,e] ? ");
				gets(line);
				n = strlen(line);
				i = line[0];

				if (n==1 && (i=='R' || i=='r'))  goto L91301;
				if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
				if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L91370;}
				if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
				if (n==1 && (i=='D' || i=='d'))  debug_step = true;
			} // close if rdata
			if (debug_loop) goto L91361;	// commented out 6/7/2005 debugging tmb2005 rev 1.0

			// Write a 0 to CFEB clock driver on DUT
			wr_data	= (sel_step_cfeb & 0xFC1F) | (1 << (icfeb+5)) | 0x0000;
			adr		= vme_step_adr + base_adr;
			status	= vme_write(adr,wr_data);

			// Read ALCT receiver on REF
			adr		= alct_rxa_adr + base_adr_ref;
			status	= vme_read(adr,rd_data);
			alct_id = (rd_data >> 8) & 0xFF;
			rd_data = rd_data & 0xFF;

			// Check if ALCT read a 0, un-invert it...thanks a lot, Vlad
			rd_data = ((rd_data >> 3) & 0x0001) ^ 0x0001;

			if (ipass==1) fprintf(test_file,"\tCFEB%1i[CK] read=%6.1X expect=%6.1X\n\n",icfeb+1,rd_data,0x0);

			if (rd_data!=0 || debug_step && !debug_loop) {
				tmb_nfailed[itest]=1;
				cfeb_err++;
				printf("\tFailed CFEB%1i clock bit wr=0 rd=%6.6X\n",icfeb+1,rd_data);

				printf("\tSkip, Loop, Debug, Continue, Retry, Exit[s,l,d,c,r,e] ? ");
				gets(line);
				n = strlen(line);
				i = line[0];

				if (n==1 && (i=='R' || i=='r'))  goto L91301;
				if (n==1 && (i=='E' || i=='e'))  goto tmb_auto_done;
				if (n==1 && (i=='S' || i=='s')) {tmb_nskipped[itest]=1; goto L91380;}
				if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
				if (n==1 && (i=='D' || i=='d'))  debug_step = true;
			} // close if rd_data
			if (debug_loop) goto L91361;

			// CFEB passes
			//L91365:
		} // close ipass 91365

		sprintf(cid,"%1i",icfeb+1);
		sid  = string(cid);

		if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
		aokf(string("CFEB").append(sid).append(string(" RAT SCSI Cable Loopback")),itest,tmb_npassed[itest]);
		if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

		// close loops
L91370:;
	}		// close 91370 icfeb

	// Next test
L91380:;

	   //------------------------------------------------------------------------------
	   //	Full Auto Test:
	   //	3D3444 Delays
	   //------------------------------------------------------------------------------
L18170:
	   itest=48;	// itest 48-59

	   // Turn off step mode
	   sel_step_alct = 0x1FE0;
	   adr     = vme_step_adr+base_adr;
	   wr_data = sel_step_alct;
	   status	= vme_write(adr,wr_data);

	   // Prompt for scope connections
	   printf("\n");
	   printf("\tSet Scope Ch1 & Ch2 to 2V/division 10ns/division\n");
	   printf("\tSet Scope Display Persistence to 1.2 sec\n");
	   printf("\tSet Scope to trigger on Ch1, display Ch2 only\n");
	   printf("\tConnect Scope Ch1 to 40MHz CLK at TP501 on TMB\n");

	   printf("\n");
	   printf("\tEnter F to fail a delay channel\n");
	   printf("\tEnter P to pass a delay channel\n");
	   printf("\tEnter S to skip a delay channel\n");
	   printf("\tEnter E to exit\n");
	   printf("\n");

	   // Loop DDD channels
	   for (ichip=0; ichip<=2; ++ichip) {	// L91003
		   for (ich=0;   ich<=3;   ++ich  ) {	// L91002
			   itest=48+ich+4*ichip;

			   if (ichip==1 && ich==0) printf("\tSkip TP53-5 TMB0\n");
			   printf("\tScope Ch2: 3D3444 chip%2i channel%2i %s [P,F,S] ",ichip,ich,ddd_tp[ichip][ich].c_str());

L18171:
			   for (ddd_delay=0; ddd_delay<=12; ++ddd_delay) {	// 91001
				   dprintf(stdout,"\tTesting Chip=%1i Ch=%i Delay=%1X\r",ichip,ich,ddd_delay);

				   wr_data = (ddd_delay << (ich*4));
				   adr	    = base_adr+vme_ddd0_adr+2*ichip;
				   status  = vme_write(adr,wr_data);

				   // Start DDD state machine
				   adr	    = base_adr+vme_dddsm_adr;
				   status  = vme_read(adr,rd_data);
				   autostart = rd_data & 0x0020;	// get current autostart state
				   wr_data	= 0x0000 | autostart;	// stop machine
				   status	= vme_write(adr,wr_data);
				   wr_data = 0x0001 | autostart;	// start machine
				   status	= vme_write(adr,wr_data);
				   wr_data = 0x0000 | autostart;	// unstart machine
				   status	= vme_write(adr,wr_data);

				   // Wait for it to finish
				   for (i=1; i<=1000; ++i) {
					   status   = vme_read(adr,rd_data);
					   ddd_busy      = (rd_data >> 6) & 0x1;
					   ddd_verify_ok = (rd_data >> 7) & 0x1;
					   if (ddd_busy==0) goto L18172;
				   }
				   fprintf(test_file,"\t3d3444 state machine timeout: ich=%1i ddd_delay=%1X\n",ich,ddd_delay);
				   fprintf(stdout,   "\t3d3444 state machine timeout: ich=%1i ddd_delay=%1X\n",ich,ddd_delay);

L18172:
				   if (ddd_verify_ok!=1) {
					   fprintf(test_file,"\t3d3444 verify failed: ich=%1i ddd_delay=%1X\n",ich,ddd_delay);
					   fprintf(stdout,   "\t3d3444 verify failed: ich=%1i ddd_delay=%1X\n",ich,ddd_delay);

					   printf("\tSkip, Loop, Debug, Continue, Exit[s,l,d,c,e] ? ");
					   gets(line);
					   n = strlen(line);
					   i = line[0];

					   if (n==1 && (i=='E' || i=='e')) goto tmb_auto_done;
					   if (n==1 && (i=='S' || i=='s')) {tmb_nfailed[itest]=1; goto L91002;}	// try next channel
					   if (n==1 && (i=='L' || i=='l')) goto L18171;							// loop on ddd_delay
				   }	// close ddd_verify_ok

				   // Hold this delay for scope persistence
				   msec = 100;
				   if (ddd_delay==0) msec = 600;					// Hold at 0 delay for a moment
				   sleep(msec);

				   // Check for keyboard input
				   if (!_kbhit()) goto L91001;			// Check for keyboard hit
				   ckey = _getch();					// Read key
				   printf("\tKey pressed=%c\n",ckey);

				   if (ckey=='e' || ckey=='E') {goto tmb_auto_done;}					// Exit
				   if (ckey=='p' || ckey=='P') {goto L18173;}							// Channel passes,  go to next channel
				   if (ckey=='s' || ckey=='S') {tmb_nskipped[itest]=1;	goto L18173;}	// Channel skipped, go to next channel
				   if (ckey=='f' || ckey=='F') {tmb_nfailed[itest] =1; goto L18173;}	// Channel failed,  go to next channel

L91001:;
			   } // close for idelay				// next delay
			   goto L18171;						// keep on this channel until key pressed

			   // Change to next channel
L18173:	
			   sprintf(cid,  "%1i", ichip);
			   sprintf(cich, "%1X", ich  );

			   sid  = string(cid);
			   sich = string(cich);

			   if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
			   aokf(string("3D3444 Delay  Chip ").append(sid).append(string(" Channel ")).append(sich),itest,tmb_npassed[itest]);
			   if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

			   // Close channel,chip loops
L91002:;
		   }		// close ich 91002
	   }		// close ichip 91003

	   //------------------------------------------------------------------------------
	   //	TMB Full Auto Test:
	   //	CCB clock selected, LEDs
	   //------------------------------------------------------------------------------
	   //L18180:
	   itest=60;

	   // Turn on JTAG leds
	   sel_boot_jtag = 0x0080;
	   wr_data = 0x7F | sel_boot_jtag;
	   adr     = tmb_boot_adr+base_adr;
	   status  = vme_write(adr,wr_data);

	   // Turn on Board LEDs
	   adr     = vme_led_adr+base_adr;		// turn on all LEDs
	   wr_data = 0xFFFF;
	   status	= vme_write(adr,wr_data);

	   adr     = ccb_cfg_adr+base_adr;		// Select vme as led source
	   status  = vme_read(adr,rd_data);
	   wr_data = rd_data & 0xFFF0;			// turn off old mode
	   wr_data = wr_data | 0x6;			// turn on vme source for bd and cylon fp
	   status	= vme_write(adr,wr_data);

	   printf("\n\tLED Check:\n");

	   ledtest[0] = pass_fail("\tIs clock source shunt SH501=CCB?              [P,F]<cr> ");
	   ledtest[1] = pass_fail("\tAre Ref and Test TMB front panel LEDs in sync?[P,F]<cr> ");
	   ledtest[2] = pass_fail("\tAre all 8 BD_0-BD_7 LEDs BGGGGGGR lit?        [P,F]<cr> ");
	   ledtest[3] = pass_fail("\tAre all 7 Voltage Status LEDs green?          [P,F]<cr> ");
	   ledtest[4] = pass_fail("\tAre 7 JTAG LEDs green, SRC=010? (ignore TDO)  [P,F]<cr> ");
	   ledtest[5] = pass_fail("\tAre all 3 Fuse LEDs on? (F4,F1,F2)            [P,F]<cr> ");
	   ledtest[6] = pass_fail("\tIs the D_VEN1 LED on?                         [P,F]<cr> ");
	   printf("\n");

	   for (i=0; i<=6; ++i) {
		   if (ledtest[i]==false) tmb_nfailed[itest]=1;
		   fprintf(test_file,"\tLED test [%1i] = %c\n",i,logical(ledtest[i]));
	   }

	   if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	   aokf("Clock from CCB",itest,tmb_npassed[itest]);
	   if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	   //------------------------------------------------------------------------------
	   //	TMB Full Auto Test:
	   //	Future tests go here
	   //------------------------------------------------------------------------------
	   //L18190:
	   itest=61;	// increase tmb_ntests if you use this

	   //------------------------------------------------------------------------------
	   //	TMB Full Auto Test:
	   //	Done
	   //------------------------------------------------------------------------------
	   // Enumerate
tmb_auto_done:

	   tmb_nfail = 0;
	   tmb_npass = 0;
	   tmb_nskip = 0;

	   for (itest=1; itest<=tmb_ntests; ++itest) {
		   tmb_nfail = tmb_nfail + tmb_nfailed[itest];
		   tmb_npass = tmb_npass + tmb_npassed[itest];
		   tmb_nskip = tmb_nskip + tmb_nskipped[itest];
	   }

	   fprintf(test_file,"\ttest:"); for(i=1;i<=tmb_ntests;++i) fprintf(test_file,"%1i",i/10           ); fprintf(test_file,"\n");
	   fprintf(test_file,"\ttest:"); for(i=1;i<=tmb_ntests;++i) fprintf(test_file,"%1i",i%10           ); fprintf(test_file,"\n");
	   fprintf(test_file,"\tpass:"); for(i=1;i<=tmb_ntests;++i) fprintf(test_file,"%1i",tmb_npassed[i] ); fprintf(test_file,"\n");
	   fprintf(test_file,"\tskip:"); for(i=1;i<=tmb_ntests;++i) fprintf(test_file,"%1i",tmb_nskipped[i]); fprintf(test_file,"\n");
	   fprintf(test_file,"\tfail:"); for(i=1;i<=tmb_ntests;++i) fprintf(test_file,"%1i",tmb_nfailed[i] ); fprintf(test_file,"\n");

	   fprintf(stdout,   "\n");
	   fprintf(stdout,   "\tTMB Full Auto Tests Completed\n");
	   fprintf(stdout,   "\tTests Passed =%3i\n",tmb_npass);
	   fprintf(stdout,   "\tFailed       =%3i\n",tmb_nfail);
	   fprintf(stdout,   "\tSkipped      =%3i\n",tmb_nskip);

	   fprintf(test_file,"\n");
	   fprintf(test_file,"\tTMB Full Auto Tests Completed\n");
	   fprintf(test_file,"\tTests Passed =%3i\n",tmb_npass);
	   fprintf(test_file,"\tFailed       =%3i\n",tmb_nfail);
	   fprintf(test_file,"\tSkipped      =%3i\n",tmb_nskip);

	   if (tmb_nfail==0 && tmb_npass==tmb_ntests && tmb_nskip==0)
	   {
		   fprintf(stdout,   "\n");
		   fprintf(stdout,   "\t+------+\n");
		   fprintf(stdout,   "\t| PASS |\n");
		   fprintf(stdout,   "\t+------+\n");
		   fprintf(test_file,"\n");
		   fprintf(test_file,"\t+------+\n");
		   fprintf(test_file,"\t| PASS |\n");
		   fprintf(test_file,"\t+------+\n");}
	   else
	   {
		   fprintf(stdout,   "\n");
		   fprintf(stdout,   "\t+-----------------------+\n");
		   fprintf(stdout,   "\t|******** FAIL *********|\n");
		   fprintf(stdout,   "\t+-----------------------+\n");
		   fprintf(test_file,"\n");
		   fprintf(test_file,"\t+-----------------------+\n");
		   fprintf(test_file,"\t|******** FAIL *********|\n");
		   fprintf(test_file,"\t+-----------------------+\n");
	   }

	   if (test_file!=NULL) fclose(test_file);

	   if (ifunc<0) goto L1800;
	   pause ("<cr>=return to main menu");
	   return;
}
//------------------------------------------------------------------------------
//	RAT Test Sub-Menu
//------------------------------------------------------------------------------
void L1900() {
L1900:

	printf("\n");
	printf("\t     RAT Module Test Menu:\n");
	printf("\t1:   RPC 80MHz Sync-mode delay scan: Debug firmware\n");
	printf("\t2:   RAT ALCT  SCSI Cable loopback\n");
	printf("\t3:   RAT CFEB  SCSI Cable loopback\n");
	printf("\t4:   RAT RPC   SCSI Cable loopback\n");
	printf("\t5:   RAT LED Test\n");
	printf("\t6:   RPC 80MHz Sync-mode delay scan: Normal firmware\n");
	printf("\t7:   RAT DLL stress test, try to lose lock\n");
	printf("\t8:   Read  RAT USER1 JTAG chain\n");
	printf("\t9:   Write RAT USER2 JTAG chain\n");
	printf("\t10:  Write RAT 3D3444 Delay with JTAG\n");
	printf("\t11:  Write RAT 3D3444 Delay with VME\n");
	printf("\t12:  Read/Reset parity error counters\n");
	printf("\t13:  Read Current RPC data from RAT\n");
	printf("\t<cr> Exit to main menu\n");

	if (firmware_type != firmware_debug)
	{
		printf("\r\n");
		printf("\tTMB has wrong firmware type for tests 1-5\n");
	}
	printf("       > ");

	gets(line);
	if (line[0]==NULL) return;
	sscanf(line,"%i",&ifunc);

	i=abs(ifunc);
	if (i== 1) goto L19100;
	if (i== 2) goto L19200;
	if (i== 3) goto L19300;
	if (i== 4) goto L19400;
	if (i== 5) goto L19500;
	if (i== 6) goto L19600;
	if (i== 7) goto L19700;
	if (i== 8) goto L19800;
	if (i== 9) goto L19900;
	if (i==10) goto L99000;
	if (i==11) goto L99100;
	if (i==12) goto L99200;
	if (i==13) goto L99300;
	goto L1900;


	//------------------------------------------------------------------------------
	//	RAT: RPC 80MHz Sync-mode delay scan
	//------------------------------------------------------------------------------
L19100:

	// Turn off step mode
	sel_step_alct = 0x1FE0;
	adr     = vme_step_adr+base_adr;
	wr_data = sel_step_alct;
	status  = vme_write(adr,wr_data);

	// Take TMB and RAT out of loop-back mode
	adr	    = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFCF;			// turn off RPC loop bits
	status  = vme_write(adr,wr_data);

	// Put RAT in sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
	adr	    = rpc_txb_adr+base_adr;
	wr_data = 0x0003;				// [0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	status  = vme_write(adr,wr_data);

	// Get current delay register
	ichip = 0;
	ich   = 3;

	adr	    = vme_ddd0_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_ddd0 = rd_data;

	rpc_delay_default = rd_ddd0;
	rd_ddd0           = rd_ddd0 & 0x0FFF;

	// Clear error accumulator
	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		rpc_bad[ddd_delay] = 0;
	}

	// Generate expected bit pattern for comparison
	bit_to_array(0x2AAAA, rpc0_rdata_expect, 19);
	bit_to_array(0x55555, rpc1_rdata_expect, 19);
	bit_to_array(0x55555, rpc2_rdata_expect, 19);
	bit_to_array(0x2AAAA, rpc3_rdata_expect, 19);

	// Step rpc clock delay
	npasses=1000;

	for (ipass    =1; ipass    <=npasses; ++ipass    ) {	// 19115
		for (ddd_delay=0; ddd_delay<=15;      ++ddd_delay) {	// 19110

			wr_data = (ddd_delay<<(ich*4)) | rd_ddd0;
			adr	    = base_adr+vme_ddd0_adr+2*ichip;
			status  = vme_write(adr,wr_data);

			// Start DDD state machine
			adr	    = base_adr+vme_dddsm_adr;
			status  = vme_read(adr,rd_data);
			autostart = rd_data & 0x0020;	// get current autostart state
			wr_data	= 0x0000 | autostart;	// stop machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0001 | autostart;	// start machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0000 | autostart;	// unstart machine
			status	= vme_write(adr,wr_data);

			// Wait for it to finish
			for (i=1; i<=1000; ++i) {
				status   = vme_read(adr,rd_data);
				ddd_busy = (rd_data>>6) & 0x1;
				ddd_verify_ok = (rd_data>>7) & 0x1;
				if (ddd_busy==0) goto L19105;
			}
			printf("\n\t3d3444 verify failed ich=%1i ddd_delay=%1i\n",ich,ddd_delay);

			// Let RAT DLL re-sync
			sleep(200);

			// Check RAT 80MHz demux register
L19105:
			status	= vme_read(adr=rpc_rxa_adr+base_adr, rpc_rxa);	// 1st in time
			status	= vme_read(adr=rpc_rxb_adr+base_adr, rpc_rxb);
			status	= vme_read(adr=rpc_rxc_adr+base_adr, rpc_rxc);

			status	= vme_read(adr=rpc_rxd_adr+base_adr, rpc_rxd);	// 2nd in time
			status	= vme_read(adr=rpc_rxe_adr+base_adr, rpc_rxe);
			status	= vme_read(adr=rpc_rxf_adr+base_adr, rpc_rxf);

			//	bit_to_array(rpc_rxa, &rpc_data_1st[ 0], 16);
			//	bit_to_array(rpc_rxb, &rpc_data_1st[16], 16);
			//	bit_to_array(rpc_rxc, &rpc_data_1st[32],  6);

			//	bit_to_array(rpc_rxd, &rpc_data_2nd[ 0], 16);
			//	bit_to_array(rpc_rxe, &rpc_data_2nd[16], 16);
			//	bit_to_array(rpc_rxf, &rpc_data_2nd[32],  6);

			// Assemble rpc data words a,b,c=1st[37:0] d,e,f=2nd[37:0]
			rpc_rx[0] = rpc_rxa & 0xFFFF;				// rx[15:0]	pack [15: 0]	1st in time
			rpc_rx[1] = rpc_rxb & 0xFFFF;				// rx[15:0]	pack [34:19]	1st in time

			rpc_bxn[0]= (rpc_rxc>>0) & 0x0007;			// bxn[2:0]	pack [18:16]
			rpc_bxn[1]= (rpc_rxc>>3) & 0x0007;			// bxn[2:0]	pack [37:35]

			rpc_rx[2] = rpc_rxd & 0xFFFF;				// rx[15:0]	pack [15: 0]	1st in time
			rpc_rx[3] = rpc_rxe & 0xFFFF;				// rx[15:0]	pack [34:19]	1st in time

			rpc_bxn[2]= (rpc_rxf>>0) & 0x0007;			// bxn[2:0]	pack [18:16]
			rpc_bxn[3]= (rpc_rxf>>3) & 0x0007;			// bxn[2:0]	pack [37:35]

			// Repack bxn, invert lvds bits
			for (i=0; i<=3; ++i) {
				rpc_word[i] = rpc_rx[i] | (rpc_bxn[i]<<16);
			}

			bit_to_array(rpc_word[0], &rpc_data_1st[ 0], 19);
			bit_to_array(rpc_word[1], &rpc_data_1st[19], 19);
			bit_to_array(rpc_word[2], &rpc_data_2nd[ 0], 19);
			bit_to_array(rpc_word[3], &rpc_data_2nd[19], 19);

			// Check for correct data received
			bad_1st=0;
			bad_2nd=0;

			//	for (i=0; i<=37; ++i) {
			//	if (rpc_data_1st[i] != (i+0)%2) bad_1st++;	// 1010
			//	if (rpc_data_2nd[i] != (i+1)%2) bad_2nd++;	// 0101
			//	}

			for (i=0; i<=18; ++i) {
				if (rpc_data_1st[i   ] != rpc0_rdata_expect[i]) bad_1st++;
				if (rpc_data_1st[i+19] != rpc1_rdata_expect[i]) bad_1st++;

				if (rpc_data_2nd[i   ] != rpc2_rdata_expect[i]) bad_2nd++;
				if (rpc_data_2nd[i+19] != rpc3_rdata_expect[i]) bad_2nd++;
			}

			rpc_bad[ddd_delay]=rpc_bad[ddd_delay]+bad_1st+bad_2nd;

			if (ipass==1) {
				printf("\tdelay=%2i",ddd_delay);
				printf(" rpc_rx_1st[37:0]="); for(i=37;i>=0;--i) printf("%1i",rpc_data_1st[i]); printf("%2i\n",bad_1st);
				printf("             ");
				printf(" rpc_rx_2nd[37:0]="); for(i=37;i>=0;--i) printf("%1i",rpc_data_2nd[i]); printf("%2i\n",bad_2nd);
			}

			// Close loops
		}	// close for ddd_delay 19110

		if (ipass==1)    printf("\tAccumulating statistics...\n\n");
		if (ipass%10==0) printf("\t%4i\r",npasses-ipass);

	}	// close for ipass 19115
	if (ifunc<0) goto L19100;

	// Put RPC delay back to default
	adr	    = vme_ddd0_adr+base_adr;
	wr_data = rpc_delay_default;
	status	= vme_write(adr,wr_data);

	// Display timing results
	printf("  2nsStep Berrs   Pct  0123456789 %5i cycles\n",npasses);

	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay)
	{
		pctbad = 100.*float(rpc_bad[ddd_delay])/76000.;
		nbad   = int(pctbad/10.);
		if (pctbad!=0.0 && nbad==0) nbad=1;

		printf("\t%2i  %7i%7.0f ",ddd_delay,rpc_bad[ddd_delay],pctbad);
		for (i=0;i<=nbad;++i) printf("x"); 
		printf("\n");
	}

	printf("\tReturn to default delay %2i\n",(rpc_delay_default>>12) & 0xF);
	pause ("\tRAT clock delay scan complete");
	goto L1900;

	//------------------------------------------------------------------------------
	//	RAT: ALCT SCSI Cable Loopback
	//------------------------------------------------------------------------------
L19200:
	printf("\tRAT: ALCT SCSI Cable Loopback Test:\n");
	printf("\tConnect a 25pr cable from ALCTtx to ALCTrx on RAT S=skip <cr>=run");

	gets(line);
	n = strlen(line);
	i = line[0];

	if (n==1 && (i=='S' || i=='s')) goto L1900;
	if (n==1 && (i=='E' || i=='e')) goto L1900;
	if (n==1 && (i=='L' || i=='l')) debug_loop = true;
	if (n==1 && (i=='D' || i=='d')) debug_step = true;

	if (debug_loop) debug_beep = true;
	else            debug_beep = false;

L19251:
	sel_boot_jtag = 0x0080;
	sel_step_alct = 0x1D10;
	sel_loopbk    = 0x0A9F;			// ALCT loop mode
	alct_err      = 0;

	// Put ALCT into loopback mode, enable CFEBs, and ALCT SCSI
	adr		= vme_loopbk_adr+base_adr;
	wr_data = sel_loopbk;
	status	= vme_write(adr,wr_data);

	// Turn off 40MHz FPGA output to drive RPC input clock
	adr     = vme_ratctrl_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rat_ctrl_data = rd_data;
	wr_data = rd_data & 0xFFDF;		// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
	status  = vme_write(adr,wr_data);

	// Send walking 1s to ALCT transmitter
	for (ipass=1; ipass<=1000; ++ipass) {	// 19256
		for (itx  =0; itx  <=24;   ++itx  ) {	// 19255

			status	 = vme_write(adr=tmb_boot_adr+base_adr,     wr_data=sel_boot_jtag);
			status	 = vme_write(adr=alct_txa_adr+base_adr,     wr_data=0);
			status	 = vme_write(adr=alct_txb_adr+base_adr,     wr_data=0);
			status	 = vme_write(adr=adr=vme_step_adr+base_adr, wr_data=sel_step_alct);

			if (itx>=0 && itx<=4) {
				wr_data= (1<<itx) | sel_boot_jtag;
				adr	= tmb_boot_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx>=5 && itx<=17) {
				wr_data= (1<<(itx-5));
				adr	= alct_txa_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx==18) {
				wr_data= (1<<8) | sel_boot_jtag;
				adr	= tmb_boot_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx==20) {
				wr_data= 0x0001 | sel_step_alct;
				adr	= vme_step_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx>=19 || itx<=24) {
				wr_data= (1<<(itx-19));
				if (itx==21) wr_data = (1<<(20-19));
				if (itx==22) wr_data = (1<<(21-19));
				if (itx==23) wr_data = (1<<(22-19));
				if (itx==24) wr_data = (1<<(23-19));
				adr	= alct_txb_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}	
			else {
				stop("dumbass");
			}

			// Read back ALCT data registers
			alct_data=0;

			for (ireg=0; ireg<=3; ++ireg) {
				adr		= base_adr+alct_rxa_adr+2*ireg;
				status	= vme_read(adr,rd_data);
				alct_id = (rd_data>>8) & 0xFF;
				rd_data = rd_data & 0xFF;
				alct_data      = alct_data | (rd_data<<(ireg*8));
				alct_id_expect = 0xA0 | ireg;
				if (alct_id!=alct_id_expect || debug_step)
					printf("\tWrong ALCT id expect=%4.4X id=%2.2X read=%4.4X\n",alct_id_expect,alct_id,rd_data);
			}

			// Read back TDO rx[0], merge with rx[28:1]
			adr		 = tmb_boot_adr + base_adr;
			status	 = vme_read(adr,rd_data);
			alct_tdo = rd_data;

			alct_tdo  = alct_tdo  & 0x1;
			alct_lsbs = alct_data ^ 0xF;			// invert
			alct_lsbs = alct_lsbs & 0xE;			// trim off [28:4]
			alct_lsbs = alct_lsbs | alct_tdo;		// invert [3:1] add [0]

			// Check lower 4 ALCT rx bits that are hardwired to tx drivers
			alct_expect = (1<<itx);					// (1<<(itx-20)) & 0x000F;

			if (itx>=22)         alct_expect = (1<<(itx-21));
			if (itx==0 )         alct_expect = 1;	// tdo bit
			if (itx<22 && itx>0) alct_expect = 0;

			if (alct_lsbs!=alct_expect) {
				printf("\tALCT hardwire error: itx=%3i read=%8.8X expect=%8.8X\n",itx,alct_lsbs,alct_expect);
				pause("<cr> to resume");
			}

			// Un-invert the inverted ALCT bits...thanks a lot, Vlad
			dprintf(stdout,"alct_data=%8.8X\n",alct_data);
			alct_data = alct_data ^ 0x1FBFFFF0;
			alct_data = (alct_data>>4);		// rx4 is the ALCT lsb

			// Compare ALCT read data to ALCT write data
			if ((alct_data!=(1<<itx) && (!debug_loop || debug_beep)) || debug_step) {
				alct_err++;

				if (ifunc>=0) {
					printf("\t\tFailed ALCT bit itx=%2i wr=%8.8X rd=%8.8X%c\n",itx,(1<<itx),alct_data,bell);
					printf("\tSkip, Loop, Debug, Continue <cr> ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='S' || i=='s')) goto L19260;
					if (n==1 && (i=='L' || i=='l')) debug_loop = true;
					if (n==1 && (i=='D' || i=='d')) debug_step = true;

				}	// close if ifunc
			}	// close if alct_data

			// close loops
		}	// close for itx 19255
		if (debug_loop || debug_step) goto L19251;

	}	// close for  ipass 19256

	// ALCT passes
	aok("RAT: ALCT SCSI Cable Loopback");

	// Done
L19260:
	goto L1900;

	//------------------------------------------------------------------------------
	//	RAT: CFEB SCSI Cable Loopback
	//------------------------------------------------------------------------------
L19300:
	for (icfeb=0; icfeb<=4; ++icfeb) {	// 19370

		printf("\tRAT: ALCT SCSI Cable Loopback Test:\n");
		printf("\tConnect a 25pr cable from RAT ALCTtx to CFEB%1i S=skip <cr>=run",icfeb);

		gets(line);
		n = strlen(line);
		i = line[0];

		if (n==1 && (i=='S' || i=='s')) goto L19370;
		if (n==1 && (i=='E' || i=='e')) goto L1900;
		if (n==1 && (i=='L' || i=='l')) debug_loop = true;
		if (n==1 && (i=='D' || i=='d')) debug_step = true;

		if (debug_loop) debug_beep = true;
		else            debug_beep = false;

		// Passes loop
		for (ipass=1; ipass<=1000; ++ipass) {		// 19365

L19361:
			sel_boot_jtag  = 0x0080;
			sel_step_alct  = 0x1C10;					// was 1d10, but that turns off cfeb3..why was it there?
			sel_step_cfeb  = 0x1C10 | (1<<(icfeb+5));	// was 1d10, but that turns off cfeb3..why was it there?
			cfeb_id_expect = 0xC0 | icfeb;
			alct_id_expect = 0xA0;
			cfeb_err       = 0;

			// Turn off CFEB clock drivers
			wr_data	= sel_step_alct;
			adr		= vme_step_adr + base_adr;
			status	= vme_write(adr,wr_data);

			// Put ALCT into loopback mode, enable CFEBs, and RAT ALCT SCSI
			sel_loopbk = 0x0A9F;						// Enable RAT, disable front SCSI !was 0A93 for tmb2004
			adr		   = vme_loopbk_adr + base_adr;
			status	   = vme_write(adr,wr_data=sel_loopbk);

			// Send walking 1s to ALCT transmitter
			for (itx=0; itx<=23; ++itx) {	// 19364
				wr_pat  = (1<<itx);
				status	= vme_write(adr=tmb_boot_adr+base_adr, wr_data=sel_boot_jtag);
				status	= vme_write(adr=alct_txa_adr+base_adr, wr_data=0);
				status	= vme_write(adr=alct_txb_adr+base_adr, wr_data=0);
				status	= vme_write(adr=vme_step_adr+base_adr, wr_data=sel_step_alct);

				if (itx>=0 && itx<=4) {
					wr_data= (1<<itx) | sel_boot_jtag;
					adr	= tmb_boot_adr + base_adr;
					status	= vme_write(adr,wr_data);
				}
				else if (itx>=5 && itx<=17) {
					wr_data= (1<<(itx-5));
					adr	= alct_txa_adr + base_adr;
					status	= vme_write(adr,wr_data);
				}
				else if (itx==18) {
					wr_data= (1<<8) | sel_boot_jtag;
					adr	= tmb_boot_adr + base_adr;
					status	= vme_write(adr,wr_data);
				}
				else if (itx==20) {
					wr_data= (1<<(itx-20)) | sel_step_alct;
					adr	= vme_step_adr + base_adr;
					status	= vme_write(adr,wr_data);
				}
				else if (itx>=19 || itx<=23) {
					wr_data= (1<<(itx-19));
					if (itx==21) wr_data = (1<<(20-19));
					if (itx==22) wr_data = (1<<(21-19));
					if (itx==23) wr_data = (1<<(22-19));
					if (itx==24) wr_data = (1<<(23-19));
					adr	= alct_txb_adr + base_adr;
					status	= vme_write(adr,wr_data);		
				}
				else {
					stop("moron");
				}

				// Read back CFEB data registers
				cfeb_data = 0;
				cfeb_base = base_adr+icfeb*cfeb_offset_adr;

				adr	      = cfeb0a_adr+cfeb_base;
				status	  = vme_read(adr,rd_data);
				cfeb_id   = (rd_data>>8) & 0xFF;
				rd_data   = rd_data & 0xFF;
				cfeb_data = cfeb_data | rd_data;

				if (cfeb_id != cfeb_id_expect)
					printf("\tWrong CFEB id: expect=%8.8X rd=%8.8X\n",cfeb_id_expect,cfeb_id);

				adr	      = cfeb0b_adr+cfeb_base;
				status	  = vme_read(adr,rd_data);
				cfeb_id   = (rd_data>>8) & 0xFF;
				rd_data   = rd_data & 0xFF;
				cfeb_data = cfeb_data | (rd_data<<8);

				if (cfeb_id != cfeb_id_expect)
					printf("\tWrong CFEB id: expect=%8.8X rd=%8.8X\n",cfeb_id_expect,cfeb_id);

				adr	      = cfeb0c_adr+cfeb_base;
				status	  = vme_read(adr,rd_data);
				cfeb_id   = (rd_data>>8) & 0xFF;
				rd_data   = rd_data & 0xFF;
				cfeb_data = cfeb_data | (rd_data<<16);

				if (cfeb_id != cfeb_id_expect)
					printf("\tWrong CFEB id: expect=%8.8X rd=%8.8X\n",cfeb_id_expect,cfeb_id);

				// Un-invert the inverted ALCT bits...thanks a lot, Vlad
				cfeb_data = cfeb_data ^ 0xAEAAAA;

				// Compare CFEB read data to ALCT write data
				if ((cfeb_data!=wr_pat || debug_step) && (!debug_loop || debug_beep))
				{
					cfeb_err++;
					printf("\t\tFailed CFEB%1i bit=%2i wr=%6.6X rd=%6.6X\n",icfeb,itx,(1<<itx),cfeb_data);

					printf("\tSkip, Loop, Debug, Continue <cr> ");
					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='S' || i=='s')) goto L19370;
					if (n==1 && (i=='L' || i=='l')) debug_loop = true;
					if (n==1 && (i=='D' || i=='d')) debug_step = true;
				}

			}	// close for itx 19364
			if (debug_loop) goto L19361;

			// Test CFEB transmit clock bit: Take ALCT out of loop-back mode
			wr_data = 0x0A9D;		// was 0A91 for tmb2004
			adr		= vme_loopbk_adr + base_adr;
			status	= vme_write(adr,wr_data);

			// Turn on CFEB clock driver 
			wr_data	= (sel_step_cfeb & 0xFC1F) | (1<<(icfeb+5));
			adr		= vme_step_adr + base_adr;	
			status	= vme_write(adr,wr_data);

			// Write a 1 to CFEB clock driver
			wr_data	= (sel_step_cfeb & 0xFC1F) | (1<<(icfeb+5)) | 0x0008;
			adr		= vme_step_adr + base_adr;	
			status	= vme_write(adr,wr_data);

			// Read ALCT receiver
			adr		= alct_rxa_adr + base_adr;
			status	= vme_read(adr,rd_data);
			alct_id = (rd_data>>8) & 0xFF;
			rd_data = rd_data & 0xFF;

			if (alct_id!=alct_id_expect)
				printf("\tWrong ALCT id: expect=%8.8X rd=%8.8X\n",alct_id_expect,alct_id);

			// Check if ALCT read a 1, un-invert it...thanks a lot, Vlad
			rd_data = ((rd_data>>3) & 0x0001) ^ 0x0001;

			if ((rd_data!=1 || debug_step) && !debug_loop)
			{
				cfeb_err++;
				printf("\t\tFailed CFEB%1i clock bit wr=1 rd=%6.6X\n",rd_data);

				printf("\tSkip, Loop, Debug, Continue <cr> ");
				gets(line);
				n = strlen(line);
				i = line[0];

				if (n==1 && (i=='S' || i=='s')) goto L19370;
				if (n==1 && (i=='L' || i=='l')) debug_loop = true;
				if (n==1 && (i=='D' || i=='d')) debug_step = true;
			}
			if (debug_loop) goto L19361;

			// Write a 0 to CFEB clock driver
			wr_data	= (sel_step_cfeb & 0xFC1F) | (1<<(icfeb+5)) | 0x0000;
			adr		= vme_step_adr + base_adr;
			status	= vme_write(adr,wr_data);

			// Read ALCT receiver
			adr		= alct_rxa_adr + base_adr;
			status	= vme_read(adr,rd_data);
			alct_id = (rd_data>>8) & 0xFF;
			rd_data = rd_data & 0xFF;

			// Check if ALCT read a 0, un-invert it...thanks a lot, Vlad
			rd_data = ((rd_data>>3) & 0x0001) ^ 0x0001;

			if ((rd_data!=0 || debug_step) && !debug_loop)
			{
				cfeb_err++;
				printf("\t\tFailed CFEB%1i clock bit wr=0 rd=%6.6X\n",rd_data);

				printf("\tSkip, Loop, Debug, Continue <cr> ");
				gets(line);
				n = strlen(line);
				i = line[0];

				if (n==1 && (i=='S' || i=='s')) goto L19380;
				if (n==1 && (i=='L' || i=='l')) debug_loop = true;
				if (n==1 && (i=='D' || i=='d')) debug_step = true;
			}
			if (debug_loop) goto L19361;

			// CFEB passes
		}	// close for ipass 19365

		sprintf(cid,"%1i",icfeb);	// convert cfeb id to strip
		sid  = string(cid);
		aok(string("CFEB").append(sid).append(string(" RAT SCSI Cable Loopback")));

		// Done
L19370:;
	}	// close for icfeb 19370

L19380:
	goto L1900;

	//------------------------------------------------------------------------------
	//	RAT: RPC SCSI Cable Loopback
	//------------------------------------------------------------------------------
	//
	//	Pair	SCSIpins	RPCrx	ALCTtx		ALCTtx Inverted
	//	---- 	--------	-----	----------	---------------
	//	 1		1,2			rx0		tx0	tdi
	//	 2		49,50		rx1		tx1			Y
	//	 3		3,4			rx2		tx2	tck
	//	 4		47,48		rx3		tx3			Y
	//	 5		5,6			rx4		tx4	sel1
	//	 6		45,46		rx5		tx5			Y
	//	 7		7,8			rx6		tx6
	//	 8		43,44		rx7		tx7			Y
	//	 9		9,10		rx8		tx8
	//	 10		41,42		rx9		tx9			Y
	//	 11		11,12		rx10	tx10
	//	 12		39,40		rx11	tx11		Y
	//	 13		13,14		rx12	tx12
	//	 14		37,38		rx13	tx13		Y
	//	 15		15,16		rx14	tx14
	//	 16		35,36		rx15	tx15		Y
	//	 17		17,18		clock	tx16
	//	 18		33,34		bxn0	tx17 async	Y
	//	 19		19,20		bxn1	tx18 hrst
	//	 20		31,32		bxn2	tx19		Y
	//	 21		21,22		rxg0	clock
	//	 22		29,30		rxg1	tx20
	//	 23		23,24		rxg2	tx21		Y
	//	 24		27,28		rxg3	tx22
	//	 25		25,26		gnd		tx23		Y

L19400:
	for (irpc=0; irpc<=1; ++irpc) {	// 19470

		printf("\tRAT: RPC SCSI Cable Loopback Test:\n");
		printf("\tConnect a 25pr cable from RAT ALCTtx to RPC%i S=skip <cr>=run",irpc);

		gets(line);
		n = strlen(line);
		i = line[0];

		if (n==1 && (i=='S' || i=='s')) goto L19470;
		if (n==1 && (i=='E' || i=='e')) goto L1900;
		if (n==1 && (i=='L' || i=='l')) debug_loop = true;
		if (n==1 && (i=='D' || i=='d')) debug_step = true;

		if (debug_loop) debug_beep = true;
		else            debug_beep = false;

		// Take ALCT out of loopback mode, enable CFEBs, and RAT ALCT SCSI
		sel_boot_jtag = 0x0080;
		sel_loopbk    = 0x0A8D;				// Enable RAT, disable front SCSI, was a81 for tmb2004

		adr		= vme_loopbk_adr + base_adr;
		wr_data = sel_loopbk;
		status	= vme_write (adr,wr_data);

		// Turn on ALCT 40MHz clock
		adr	    = vme_step_adr + base_adr;
		wr_data = 0x1FE0;
		status	= vme_write(adr,wr_data);

		// Turn on 40MHz FPGA output to drive RPC input clock
		adr     = vme_ratctrl_adr+base_adr;
		status  = vme_read(adr,rd_data);
		rat_ctrl_data = rd_data;
		wr_data = rd_data & 0xFFDF;			// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
		wr_data = wr_data | 0x0020;			// 	enable clock bit
		status  = vme_write(adr,wr_data);

		// Take RAT out of sync mode, keep posneg=1
		adr	    = rpc_txb_adr+base_adr;
		wr_data = 0x0002;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
		status  = vme_write(adr,wr_data);

		// Set RAT clock delay
		adr	    = base_adr+vme_ddd0_adr;
		status	= vme_read(adr,rd_data);

		wr_data = rd_data & 0x0FF0;
		//	wr_data = wr_data | (3 << 12);		// RAT delay 3 for DDR mux
		wr_data = wr_data | (9 << 12);		// RAT delay 9 for non-DDR
		wr_data = wr_data | (2 <<  0);		// ALCTtx delay 2

		status  = vme_write(adr,wr_data);

		// Start DDD state machine
		adr	    = base_adr+vme_dddsm_adr;
		status  = vme_read(adr,rd_data);
		autostart = rd_data & 0x0020;		// get current autostart state
		wr_data	= 0x0000 | autostart;		// stop machine
		status	= vme_write(adr,wr_data);
		wr_data = 0x0001 | autostart;		// start machine
		status	= vme_write(adr,wr_data);
		wr_data = 0x0000 | autostart;		// unstart machine
		status	= vme_write(adr,wr_data);

		// Loop over repeat-passes
		for (ipass=1; ipass<=1000; ++ipass) {// 19465
L19461:
			rpc_err = 0;

			// Send walking 1s to ALCT transmitter
			for (itx=0; itx<=18; ++itx) {		// 19464 

				wr_pat      = (1<<itx);
				wr_pat_ck   = wr_pat;
				if (itx>=16)  wr_pat = (wr_pat<<1);	// skip alct_tx16. tmb bdtest firmware sends rpc clock on alct_tx[16]
				//	wr_pat_vlad = wr_pat ^ 0x00015555;	// pre-invert  ALCT tx data so RPC sees all 0s + 1
				//	wr_pat_vlad = wr_pat ^ 0x00AEAAAA;	// pre-invert  ALCT tx data so RPC sees all 0s + 1 pre-feb 2006
				wr_pat_vlad = wr_pat ^ 0x00015555;	// pre-invert  ALCT tx data so RPC sees all 0s + 1 feb 2006, no inversion

				jtag_alct        = (wr_pat_vlad >>  0) & 0x001F;	// tx[4:0]
				alct_tx_lo       = (wr_pat_vlad >>  5) & 0x1FFF;	// tx[17:5]
				nhard_reset_alct = (wr_pat_vlad >> 18) & 0x0001;	// tx[18]	inverted on tmb
				alct_tx_hi       = (wr_pat_vlad >> 19) & 0x001F;	// tx[23:19]

				// Send to ALCT output registers
				adr		= tmb_boot_adr+base_adr;
				wr_data = sel_boot_jtag & 0xFEFF;	// blank alct_hard_reset bit
				wr_data = wr_data | (nhard_reset_alct << 8);
				wr_data	= wr_data | jtag_alct;
				status	= vme_write(adr,wr_data);

				adr		= alct_txa_adr+base_adr;
				wr_data	= alct_tx_lo;
				status	= vme_write(adr,wr_data);

				adr		= alct_txb_adr+base_adr;
				wr_data	= alct_tx_hi;
				status	= vme_write(adr,wr_data);

				// Read back RPC data registers
				for (i=0; i<38; ++i) rpc_data[i]=0;

				status	= vme_read(adr=rpc_rxa_adr+base_adr, rpc_rxa);	// 1st in time
				status	= vme_read(adr=rpc_rxb_adr+base_adr, rpc_rxb);
				status	= vme_read(adr=rpc_rxc_adr+base_adr, rpc_rxc);

				status	= vme_read(adr=rpc_rxd_adr+base_adr, rpc_rxd);	// 2nd in time
				status	= vme_read(adr=rpc_rxe_adr+base_adr, rpc_rxe);
				status	= vme_read(adr=rpc_rxf_adr+base_adr, rpc_rxf);

				dprintf(stdout,"\trpc_rx abcddef=%4.4X %4.4X %4.4X %4.4X %4.4X %4.4X\n",rpc_rxa,rpc_rxb,rpc_rxc,rpc_rxd,rpc_rxe,rpc_rxf);

				// Assemble rpc data words a,b,c=1st[37:0] d,e,f=2nd[37:0]
				rpc_rx[0]  = rpc_rxa & 0xFFFF;				// rx[15:0]	pack [15: 0]	1st in time
				rpc_rx[1]  = rpc_rxb & 0xFFFF;				// rx[15:0]	pack [34:19]	1st in time

				rpc_bxn[0] = rpc_rxc & 0x0007;				// bxn[2:0]	pack [18:16]
				rpc_bxn[1] = (rpc_rxc >> 3) & 0x0007;		// bxn[2:0]	pack [37:35]

				rpc_rx[2]  = rpc_rxd & 0xFFFF;				// rx[15:0]	pack [15: 0]	1st in time
				rpc_rx[3]  = rpc_rxe & 0xFFFF;				// rx[15:0]	pack [34:19]	1st in time

				rpc_bxn[2] = rpc_rxf & 0x0007;				// bxn[2:0]	pack [18:16]
				rpc_bxn[3] = (rpc_rxf >> 3) & 0x0007;		// bxn[2:0]	pack [37:35]

				// Repack bxn, invert lvds bits
				for (i=0; i<=3; ++i)
				{
					rpc_word[i] = (rpc_rx[i]   | (rpc_bxn[i] << 16));	// append bxn to rpc data
					rpc_word[i] = (rpc_word[i] ^ 0x007FFFF);			// invert bits 18:0
					dprintf(stdout,"\trpc%1i  %4.4X %4.4X\n",i,rpc_rx[i],rpc_bxn[i]);
				}

				// Compare RPC read data to ALCT write data
				if ((rpc_word[irpc]!=wr_pat_ck || debug_step) && (!debug_loop || debug_beep))
				{
					rpc_err++;

					printf("\t\tFailed RPC%1i bit=%2i wr=%6.6X rd=%6.6X\n",irpc,itx,wr_pat_ck,rpc_word[irpc]);
					printf("\tSkip, Loop, Debug, Continue <cr> ");

					gets(line);
					n = strlen(line);
					i = line[0];

					if (n==1 && (i=='S' || i=='s')) goto L19470;
					if (n==1 && (i=='L' || i=='l')) debug_loop = true;
					if (n==1 && (i=='D' || i=='d')) debug_step = true;
				}

				// RPC passes
			}	// close for itx 19464
			if (debug_loop) goto L19461;
		}	// close for ipass 19465

		sprintf(cid, "%1i", irpc);
		sid  = string(cid);

		aok(string("RPC").append(sid).append(string(" RAT SCSI Cable Loopback")));

L19470:;
	}	//	close for irpc

	// Turn off 40MHz FPGA output to drive RPC input clock
	adr     = vme_ratctrl_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rat_ctrl_data = rd_data;
	wr_data = rd_data & 0xFFDF;			// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
	status  = vme_write(adr,wr_data);

	goto L1900;

	//------------------------------------------------------------------------------
	//	RAT: LED Test
	//------------------------------------------------------------------------------
L19500:
	printf("\n");
	printf("\t     RAT Module LED Test Menu:\n");
	printf("\t1:   Cylon loop-back mode\n");
	printf("\t2:   Cylon sync mode\n");
	printf("\t3:   Normal running mode\n");
	printf("\t<cr> Exit to previous menu\n");

	gets(line);
	if (line[0]==NULL) return;
	sscanf(line,"%i",&ifunc);

	i=abs(ifunc);
	if (i== 1) goto L19510;
	if (i== 2) goto L19520;
	if (i== 3) goto L19530;
	goto L1900;

	// Cylon loop-back mode
L19510:

	// Turn off step mode
	sel_step_alct = 0x1FE0;
	adr     =  vme_step_adr+base_adr;
	wr_data = sel_step_alct;
	status  = vme_write(adr,wr_data);

	// Put TMB and RAT into loop-back mode
	adr	    = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x0030;			// turn on RPC loop bits
	status  = vme_write(adr,wr_data);

	// Take RAT out sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
	adr	    = rpc_txb_adr+base_adr;
	wr_data = 0x0006;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	status  = vme_write(adr,wr_data);
	goto L19500;

	// Cylon sync mode
L19520:

	// Turn off step mode
	sel_step_alct = 0x1FE0;
	adr     = vme_step_adr+base_adr;
	wr_data = sel_step_alct;
	status  = vme_write(adr,wr_data);

	// Take TMB and RAT out of loop-back mode, take ALCT lvds transmitter out of loop mode
	adr	    = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFCD;			// turn off RPC loop bits
	status  = vme_write(adr,wr_data);

	// Put RAT in sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
	adr	    = rpc_txb_adr+base_adr;
	wr_data = 0x0003;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	status  = vme_write(adr,wr_data);
	goto L19500;

	// Normal running mode
L19530:

	// Turn off step mode
	sel_step_alct = 0x1FE0;
	adr     = vme_step_adr+base_adr;
	wr_data = sel_step_alct;
	status  = vme_write(adr,wr_data);

	// Take TMB and RAT out of loop-back mode
	adr	    = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFCD;			// turn off RPC loop bits
	status  = vme_write(adr,wr_data);

	// Take RAT out sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
	adr	    = rpc_txb_adr+base_adr;
	wr_data = 0x0002;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	status  = vme_write(adr,wr_data);

	goto L19500;

	//------------------------------------------------------------------------------
	//	RAT: RPC 80MHz Sync-mode delay scan: Normal Firmware
	//------------------------------------------------------------------------------
L19600:

	// Switch from SCSI to RAT
	wr_data = 0x000D;
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_write(adr,wr_data);

	// Put RAT in sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
	wr_data = 0x0003;	//	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	adr	    = vme_ratctrl_adr+base_adr;
	status  = vme_write(adr,wr_data);

	// Unmask inputs from RAT
	adr	   = rpc_inj_adr+base_adr;
	status = vme_read(adr,rd_data);
	wr_data= rd_data | 0x0001;		// 1=enable rat inputs to tmb 
	status = vme_write(adr,wr_data);

	// Get current delay register
	ichip = 0;
	ich   = 3;

	adr	    = vme_ddd0_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_ddd0 = rd_data & 0x0FFF;
	rpc_delay_default = rd_data;

	// Clear error accumulator
	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		rpc_bad[ddd_delay]=0;
	}

	// Generate expected bit pattern for comparison
	bit_to_array(0x2AAAA, &rpc0_rdata_expect[0], 19);
	bit_to_array(0x55555, &rpc1_rdata_expect[0], 19);

	// Step rpc clock delay
	npasses=1000;
	for (ipass=1;ipass<=npasses; ++ ipass)			{	// do 19615
		for (ddd_delay=0; ddd_delay<=15; ++ddd_delay)	{	// do 19610

			wr_data = (ddd_delay << (ich*4)) | rd_ddd0;
			adr	    = base_adr+vme_ddd0_adr+(2*ichip);
			status  = vme_write(adr,wr_data);

			// Start DDD state machine
			adr	    = base_adr+vme_dddsm_adr;
			status  = vme_read(adr,rd_data);
			autostart = rd_data & 0x0020;	// get current autostart state

			wr_data	= 0x0000 | autostart;	// stop machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0001 | autostart;	// start machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0000 | autostart;	// unstart machine
			status	= vme_write(adr,wr_data);

			// Wait for it to finish
			for (i=1; i<=1000; ++i) {
				status   = vme_read(adr,rd_data);
				ddd_busy = (rd_data >> 6) & 0x1;
				ddd_verify_ok = (rd_data >> 7) & 0x1;
				if (ddd_busy==0) goto L19605;
			}
			printf("\t3d3444 verify failed. ich=%i ddd_elay=%i\n",ich,ddd_delay);

			// Let RAT DLL re-sync
			sleep(200);

			// Read RAT 80MHz demux registers
L19605:

			for (irat=0; irat<=3; ++irat)
			{
				adr     = rpc_cfg_adr+base_adr;
				status	= vme_read(adr,rd_data);
				rd_data = rd_data & 0xF9FF;			// zero out old rat bank
				wr_data = rd_data | (irat << 9);	// select rat ram bank
				status	= vme_write(adr,wr_data);

				adr    = rpc_cfg_adr+base_adr;
				status = vme_read(adr,rd_data);
				rpc_rbxn[irat] = (rd_data >> 11) & 0x0007;	// rat MSBs

				adr    = rpc_rdata_adr+base_adr;			// rat LSBs
				status = vme_read(adr,rd_data);
				rpc_rdata[irat] = rd_data;
			}

			bit_to_array(rpc_rdata[0], &rpc_data_1st[ 0], 16);
			bit_to_array(rpc_rbxn[0],  &rpc_data_1st[16],  3);

			bit_to_array(rpc_rdata[1], &rpc_data_1st[19], 16);
			bit_to_array(rpc_rbxn[1],  &rpc_data_1st[35],  3);

			// Check for correct data received
			bad_1st = 0;
			bad_2nd = 0;

			for (i=0; i<=18; ++i) {
				if (rpc_data_1st[i   ] != rpc0_rdata_expect[i]) bad_1st++;
				if (rpc_data_1st[i+19] != rpc1_rdata_expect[i]) bad_1st++;
			}

			rpc_bad[ddd_delay]=rpc_bad[ddd_delay]+bad_1st+bad_2nd;

			if (ipass==1) {
				printf("\tdelay=%2i rpc_rx_1st[37:0]=",ddd_delay);
				for (i=37; i>=0; --i) printf("%1i",rpc_data_1st[i]);
				printf(" %2i\n",bad_1st);
			}

			//L19610:
		}	// continue 19610
		if (ipass    == 1) printf("\n\tAccumulating statistics...\n");
		if (ipass%10 != 0) printf("\t %4i \r",npasses-ipass);

		//L19615:
	}	// continue 19615

	if (ifunc<0) goto L19600;

	// Put RPC delay back to default
	adr	    = vme_ddd0_adr+base_adr;
	wr_data = rpc_delay_default;
	status	= vme_write(adr,wr_data);
	printf("\tReturn to default delay %2i\n\n",(rpc_delay_default >> 12) & 0xF);

	// Display timing results
	printf("\t2nsStep Berrs    Pct 123456789A  %5i samples\n",npasses);

	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		pctbad = 100.*float(rpc_bad[ddd_delay])/76000.;
		nbad   = int(pctbad/10.0);
		if ((pctbad != 0.0) && (nbad == 0)) nbad=1;
		printf("\t  %2i  %7i%7.0f ",ddd_delay,rpc_bad[ddd_delay],pctbad);
		for (i=1; i<=nbad; ++i) printf("x");
		printf("\n");
	}

	printf("\n\tRAT clock delay scan complete <cr>");
	gets(line);

	goto L1900;

	//------------------------------------------------------------------------------
	//	RAT: DLL Stress test, try to make it lose lock
	//------------------------------------------------------------------------------
L19700:
	printf("\n");
	printf("\tThis test runs continuously, ctrl-c to exit\n");
	printf("\tCheck RAT LEDs for loss-of lock inidication\n");

	// Get current delay register
	ichip = 0;
	ich   = 3;

	adr	    = vme_ddd0_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rd_ddd0 = rd_data & 0x0FFF;

	// Step rpc clock delay
	n=1;
L19705:	
	printf("\tPass=%6i000\n");
	n++;
	npasses = 1000;

	for (ipass    =1; ipass    <=npasses; ++npasses  ) {	// 19715
		for (ddd_delay=0; ddd_delay<=15;      ++ddd_delay) {	// 19710

			adr	    = base_adr+vme_ddd0_adr+2*ichip;
			wr_data = (ddd_delay << (ich*4)) | rd_ddd0;
			status  = vme_write(adr,wr_data);

			// Start DDD state machine
			adr	    = base_adr+vme_dddsm_adr;
			status  = vme_read(adr,rd_data);
			autostart = rd_data & 0x0020;		// get current autostart state
			wr_data	= 0x0000 | autostart;		// stop machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0001 | autostart;		// start machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0000 | autostart;		// unstart machine
			status	= vme_write(adr,wr_data);

			// Wait for it to finish
			for (i=1; i<=1000; ++i) {
				status        = vme_read(adr,rd_data);
				ddd_busy      = (rd_data >> 6) & 0x1;
				ddd_verify_ok = (rd_data >> 7) & 0x1;
				if (ddd_busy==0) goto L19710;
			}
			printf("\n\t3d3444 verify failed ich=%1i ddd_delay=%2i\n",ich,ddd_delay);

L19710:;
		}	// close for ddd_delay 19710
	}	// close for ipass     19715
	goto L19705;

	//------------------------------------------------------------------------------
	//	RAT: Read USER1 JTAG chain
	//------------------------------------------------------------------------------
L19800:
	printf("\tMake sure you removed the JTAG cable\n");

	// Check RPC fpga done
	if (firmware_type==firmware_debug)
	{
		adr      = vme_gpio_adr+base_adr;
		status   = vme_read(adr,rd_data);
		rpc_done = (rd_data>>4) & 0x1;							// rpc_done=gp_io[4]
	}
	else 
	{
		adr		 = base_adr+rpc_cfg_adr;
		status	 = vme_read(adr,rd_data);
		rpc_done = (rd_data>>14) & 0x1;
	}

	printf("\tRPC_done=%1i\n",rpc_done);

	// Select RAT JTAG chain from TMB boot register
L19810:
	ichain = 0x000D;										// RAT jtag chain
	adr    = boot_adr;										// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);					// Take TAP to RTI

	// Read FPGA/PROM IDcodes (8 bit opcode)
	for (chip_id=0; chip_id<=1; ++chip_id)
	{
		if (chip_id==0) opcode=0x09;							// FPGA IDcode opcode
		if (chip_id==1) opcode=0xFE;							// PROM IDcode opcode
		reg_len=32;												// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],idcode,32,0);

		if (ifunc>0) printf("RAT %s device %1i IDcode=  %8.8X\n",rat_chip_type[chip_id].c_str(),chip_id,idcode);
	}	//  close for chip_id

	// Read FPGA/PROM USERCodes (8 bit opcode)
	for (chip_id=0; chip_id<=1; ++chip_id)
	{
		if (chip_id==0) opcode=0x08;							// FPGA USERcode opcode
		if (chip_id==1) opcode=0xFD;							// PROM USERcode opcode
		reg_len=32;												// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],idcode,32,0);

		if (ifunc>0) printf("RAT %s device %1i USERcode=%8.8X\n",rat_chip_type[chip_id].c_str(),chip_id,idcode);
	}

	// Read RAT USER1 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x02;											// FPGA USER1 opcode
	//	reg_len = 64;											// USER1 register length, non 3D rats
	reg_len = 224;											// USER1 register length, 3D rats after 11/30/05

	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");
	if (ifunc<0) goto L19810;

	// Decode RAT USER1 register
	for (i=0; i<reg_len; ++i) rs[i]=tdo[i];

	tdi_to_i4(&tdo[  0], rat_user1[0], 32,0);
	tdi_to_i4(&tdo[ 32], rat_user1[1], 32,0);
	tdi_to_i4(&tdo[ 64], rat_user1[2], 32,0);
	tdi_to_i4(&tdo[ 96], rat_user1[3], 32,0);
	tdi_to_i4(&tdo[128], rat_user1[4], 32,0);
	tdi_to_i4(&tdo[160], rat_user1[5], 32,0);
	tdi_to_i4(&tdo[192], rat_user1[6], 32,0);
	printf("\tRAT USER1="); for(i=6; i>=0; --i) printf("%8.8X",rat_user1[i]); printf("\n");

	tdi_to_i4(&rs[  0], rs_begin,           4,0);
	tdi_to_i4(&rs[  4], rs_version,         4,0);
	tdi_to_i4(&rs[  8], rs_monthday,       16,0);
	tdi_to_i4(&rs[ 24], rs_year,           16,0);

	tdi_to_i4(&rs[ 40], rs_syncmode,        1,0);
	tdi_to_i4(&rs[ 41], rs_posneg,          1,0);
	tdi_to_i4(&rs[ 42], rs_loop,            1,0);

	tdi_to_i4(&rs[ 43], rs_rpc_en,          2,0);
	tdi_to_i4(&rs[ 45], rs_clk_active,      2,0);
	tdi_to_i4(&rs[ 47], rs_locked_tmb,      1,0);
	tdi_to_i4(&rs[ 48], rs_locked_rpc0,     1,0);
	tdi_to_i4(&rs[ 49], rs_locked_rpc1,     1,0);
	tdi_to_i4(&rs[ 50], rs_locklost_tmb,    1,0);
	tdi_to_i4(&rs[ 51], rs_locklost_rpc0,   1,0);
	tdi_to_i4(&rs[ 52], rs_locklost_rpc1,   1,0);

	tdi_to_i4(&rs[ 53], rs_txok,            1,0);
	tdi_to_i4(&rs[ 54], rs_rxok,            1,0);

	tdi_to_i4(&rs[ 55], rs_ntcrit,          1,0);
	tdi_to_i4(&rs[ 56], rs_rpc_free,        1,0);	
	tdi_to_i4(&rs[ 57], rs_dsn,             1,0);

	tdi_to_i4(&rs[ 58], rs_dddoe_wr,        4,0);
	tdi_to_i4(&rs[ 62], rs_ddd_wr,         16,0);
	tdi_to_i4(&rs[ 78], rs_ddd_auto,        1,0);
	tdi_to_i4(&rs[ 79], rs_ddd_start,       1,0);
	tdi_to_i4(&rs[ 80], rs_ddd_busy,        1,0);
	tdi_to_i4(&rs[ 81], rs_ddd_verify_ok,   1,0);

	tdi_to_i4(&rs[ 82], rs_rpc0_parity_ok,  1,0);
	tdi_to_i4(&rs[ 83], rs_rpc1_parity_ok,  1,0);
	tdi_to_i4(&rs[ 84], rs_rpc0_cnt_perr,  16,0);
	tdi_to_i4(&rs[100], rs_rpc1_cnt_perr,  16,0);
	tdi_to_i4(&rs[116], rs_last_opcode,     5,0);

	tdi_to_i4(&rs[121], rw_rpc_en,          2,0);
	tdi_to_i4(&rs[123], rw_ddd_start,       1,0);
	tdi_to_i4(&rs[124], rw_ddd_wr,         16,0);
	tdi_to_i4(&rs[140], rw_dddoe_wr,        4,0);
	tdi_to_i4(&rs[144], rw_perr_reset,      1,0);
	tdi_to_i4(&rs[145], rw_parity_odd,      1,0);
	tdi_to_i4(&rs[146], rw_perr_ignore,     1,0);
	tdi_to_i4(&rs[147], rw_rpc_future,      6,0);

	tdi_to_i4(&rs[153], rs_rpc0_pdata,     19,0);
	tdi_to_i4(&rs[172], rs_rpc1_pdata,     19,0);

	tdi_to_i4(&rs[191], rs_unused,         29,0);
	tdi_to_i4(&rs[220], rs_end,             4,0);

	printf("\t%s%4.1X\n","rs_begin          ",rs_begin);
	printf("\t%s%4.1X\n","rs_version        ",rs_version);
	printf("\t%s%4.4X\n","rs_monthday       ",rs_monthday);
	printf("\t%s%4.4X\n","rs_year           ",rs_year);

	printf("\t%s%4.1X\n","rs_syncmode       ",rs_syncmode);
	printf("\t%s%4.1X\n","rs_posneg         ",rs_posneg);
	printf("\t%s%4.1X\n","rs_loop           ",rs_loop);

	printf("\t%s%4.1X\n","rs_rpc_en         ",rs_rpc_en);
	printf("\t%s%4.1X\n","rs_clk_active     ",rs_clk_active);

	printf("\t%s%4.1X\n","rs_locked_tmb     ",rs_locked_tmb);
	printf("\t%s%4.1X\n","rs_locked_rpc0    ",rs_locked_rpc0);
	printf("\t%s%4.1X\n","rs_locked_rpc1    ",rs_locked_rpc1);
	printf("\t%s%4.1X\n","rs_locklost_tmb   ",rs_locklost_tmb);
	printf("\t%s%4.1X\n","rs_locklost_rpc0  ",rs_locklost_rpc0);
	printf("\t%s%4.1X\n","rs_locklost_rpc1  ",rs_locklost_rpc1);

	printf("\t%s%4.1X\n","rs_txok           ",rs_txok);
	printf("\t%s%4.1X\n","rs_rxok           ",rs_rxok);

	printf("\t%s%4.1X\n","rs_ntcrit         ",rs_ntcrit);
	printf("\t%s%4.1X\n","rs_rpc_free       ",rs_rpc_free);

	printf("\t%s%4.1X\n","rs_dsn            ",rs_dsn);
	printf("\t%s%4.1X\n","rs_dddoe_wr       ",rs_dddoe_wr);
	printf("\t%s%4.4X\n","rs_ddd_wr         ",rs_ddd_wr);
	printf("\t%s%4.1X\n","rs_ddd_auto       ",rs_ddd_auto);
	printf("\t%s%4.1X\n","rs_ddd_start      ",rs_ddd_start);
	printf("\t%s%4.1X\n","rs_ddd_busy       ",rs_ddd_busy);
	printf("\t%s%4.1X\n","rs_ddd_verify_ok  ",rs_ddd_verify_ok);

	printf("\t%s%4.1X\n","rs_rpc0_parity_ok ",rs_rpc0_parity_ok);
	printf("\t%s%4.1X\n","rs_rpc1_parity_ok ",rs_rpc1_parity_ok);
	printf("\t%s%4.4X\n","rs_rpc0_cnt_perr  ",rs_rpc0_cnt_perr);
	printf("\t%s%4.4X\n","rs_rpc1_cnt_perr  ",rs_rpc1_cnt_perr);
	printf("\t%s%4.2X\n","rs_last_opcode    ",rs_last_opcode);

	printf("\t%s%4.1X\n","rw_rpc_en         ",rw_rpc_en);
	printf("\t%s%4.1X\n","rw_ddd_start      ",rw_ddd_start);
	printf("\t%s%4.4X\n","rw_ddd_wr         ",rw_ddd_wr);
	printf("\t%s%4.1X\n","rw_dddoe_wr       ",rw_dddoe_wr);
	printf("\t%s%4.1X\n","rw_perr_reset     ",rw_perr_reset);
	printf("\t%s%4.1X\n","rw_parity_odd     ",rw_parity_odd);
	printf("\t%s%4.1X\n","rw_perr_ignore    ",rw_perr_ignore);
	printf("\t%s%4.2X\n","rw_rpc_future     ",rw_rpc_future);

	printf("\t%s%5.5X\n","rs_rpc0_pdata     ",rs_rpc0_pdata);
	printf("\t%s%5.5X\n","rs_rpc1_pdata     ",rs_rpc1_pdata);

	printf("\t%s%7.7X\n","rs_unused         ",rs_unused);
	printf("\t%s%4.1X\n","rs_end            ",rs_end);
	printf("\n");

	goto L1900;

	//------------------------------------------------------------------------------
	//	RAT: Write USER2 JTAG chain
	//------------------------------------------------------------------------------
L19900:
	printf("\n\tMake sure you removed the JTAG cable\n");

	// Check RPC fpga done
	if (firmware_type==firmware_debug) {
		adr      = vme_gpio_adr+base_adr;
		status   = vme_read(adr,rd_data);
		rpc_done = (rd_data >> 4) & 0x1;			// rpc_done=gp_io[4]
	}	
	else {
		adr		 = base_adr+rpc_cfg_adr;
		status	 = vme_read(adr,rd_data);
		rpc_done = (rd_data >> 14) & 0x1;
	}

	printf("\tRPC_done=%1i\n",rpc_done);

	// Select RAT JTAG chain from TMB boot register
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Create fat 0 for writing to data registers
	for (i=0; i<mxbitstream; ++i) {
		tdi[i]=0;
	}

	// Read RAT USER2 register (5 bit opcode), readout is destructive
	chip_id = 0;
	opcode  = 0x03;								// FPGA USER2 opcode
	//	reg_len = 4;								// USER2 register length, non 3d rat
	reg_len = 32;								// USER2 register length, 3d rat
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Decode USER2 data
	for (i=0; i<reg_len; ++i) {
		wso[i]=tdo[i];
	}

	tdi_to_i4(&tdo[0], rat_user2[0], 32, 0);
	printf("\tRAT USER2=%8.8X\n",rat_user2[0]);

	tdi_to_i4(&wso[ 0], ws_rpc_en,     2,0);
	tdi_to_i4(&wso[ 2], ws_ddd_start,  1,0);
	tdi_to_i4(&wso[ 3], ws_ddd_wr,    16,0);
	tdi_to_i4(&wso[19], ws_dddoe_wr,   4,0);
	tdi_to_i4(&wso[23], ws_perr_reset, 1,0);
	tdi_to_i4(&wso[24], ws_parity_odd, 1,0);
	tdi_to_i4(&wso[25], ws_perr_ignore,1,0);
	tdi_to_i4(&wso[26], ws_rpc_future, 6,0);

	printf("\tws_rpc_en      %1.1X\n",ws_rpc_en);
	printf("\tws_ddd_start   %1.1X\n",ws_ddd_start);
	printf("\tws_ddd_wr      %4.4X\n",ws_ddd_wr);
	printf("\tws_dddoe_wr    %1.1X\n",ws_dddoe_wr);
	printf("\tws_perr_reset  %1.1X\n",ws_perr_reset);
	printf("\tws_parity_odd  %1.1X\n",ws_parity_odd);
	printf("\tws_perr_ignore %1.1X\n",ws_perr_ignore);
	printf("\tws_rpc_future  %2.2X\n",ws_rpc_future);
	printf("\n");

	// Write new data to USER2
	inquirl("\tws_rpc_en <cr>=%4.1X", minv= 0, maxv=  1, radix=16, ws_rpc_en     );
	inquirl("\tws_rpc_en <cr>=%4.1X", minv= 0, maxv=  1, radix=16, ws_ddd_start  );
	inquirl("\tws_rpc_en <cr>=%4.4X", minv= 0, maxv=255, radix=16, ws_ddd_wr     );
	inquirl("\tws_rpc_en <cr>=%4.1X", minv= 0, maxv=  1, radix=16, ws_dddoe_wr   );
	inquirl("\tws_rpc_en <cr>=%4.1X", minv= 0, maxv=  1, radix=16, ws_perr_reset );
	inquirl("\tws_rpc_en <cr>=%4.1X", minv= 0, maxv=  1, radix=16, ws_parity_odd );
	inquirl("\tws_rpc_en <cr>=%4.1X", minv= 0, maxv=  1, radix=16, ws_perr_ignore);
	inquirl("\tws_rpc_en <cr>=%4.2X", minv= 0, maxv=255, radix=16, ws_rpc_future );

	// Set new RAT USER2 bits
	bit_to_array(ws_rpc_en,      &ivalarray[ 0],  2);
	bit_to_array(ws_ddd_start,   &ivalarray[ 2],  1);
	bit_to_array(ws_ddd_wr,      &ivalarray[ 3], 16);
	bit_to_array(ws_dddoe_wr,    &ivalarray[19],  4);
	bit_to_array(ws_perr_reset,  &ivalarray[23],  1);
	bit_to_array(ws_parity_odd,  &ivalarray[24],  1);
	bit_to_array(ws_perr_ignore, &ivalarray[25],  1);
	bit_to_array(ws_rpc_future,  &ivalarray[26],  6);

	for (i=0; i<reg_len; ++i) {
		rsd[i]=ivalarray[i];
	}

	// Write RAT USER2 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x03;											// VirtexE USER2 opcode
	reg_len = 32;											// USER2 register length, 3d rat
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

	printf("\tdi="); for(i=0;i<reg_len;++i)printf("%1i",rsd[i]); printf("\n");
	printf("\tdo="); for(i=0;i<reg_len;++i)printf("%1i",tdo[i]); printf("\n");

	goto L1900;

	//------------------------------------------------------------------------------
	//	Read/Write 3D3444 Delay using RAT JTAG State Machine:
	//------------------------------------------------------------------------------
L99000:
	// Select RAT JTAG chain from TMB boot register
	ichain  = 0x000D;										// RAT jtag chain
	adr     = boot_adr;										// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);					// Take TAP to RTI

	// Read RAT USER1 register (5 bit opcode)
	adr     = boot_adr;										// Boot register address
	ichain  = 0x000D;										// RAT jtag chain
	chip_id = 0;
	opcode  = 0x02;											// FPGA USER1 opcode
	reg_len = 224;											// USER1 register length, 3D rats after 11/30/05
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Decode RAT USER1 register
	for (i=0; i<reg_len; ++i) {
		rs[i]=tdo[i];
	}

	tdi_to_i4(&tdo[  0], rat_user1[0], 32,0);
	tdi_to_i4(&tdo[ 32], rat_user1[1], 32,0);
	tdi_to_i4(&tdo[ 64], rat_user1[2], 32,0);
	tdi_to_i4(&tdo[ 96], rat_user1[3], 32,0);
	tdi_to_i4(&tdo[128], rat_user1[4], 32,0);
	tdi_to_i4(&tdo[160], rat_user1[5], 32,0);
	tdi_to_i4(&tdo[192], rat_user1[6], 32,0);
	printf("\tRAT USER1="); for(i=6;i>=0;--i)printf("8.8X"); printf("\n");

	tdi_to_i4(&rs[58], rs_dddoe_wr,      4,0);
	tdi_to_i4(&rs[62], rs_ddd_wr,       16,0);
	tdi_to_i4(&rs[78], rs_ddd_auto,      1,0);
	tdi_to_i4(&rs[79], rs_ddd_start,     1,0);
	tdi_to_i4(&rs[80], rs_ddd_busy,      1,0);
	tdi_to_i4(&rs[81], rs_ddd_verify_ok, 1,0);

	// Get current delay values
	ddd_read[0] = (rs_ddd_wr >>  0) & 0xF;
	ddd_read[1] = (rs_ddd_wr >>  4) & 0xF;
	ddd_read[2] = (rs_ddd_wr >>  8) & 0xF;
	ddd_read[3] = (rs_ddd_wr >> 12) & 0xF;

	// Display current delay values
	printf("\n\tCurrent 3D3444 Delay Settings:\n");

	printf("\trs_dddoe_wr       %4.4X\n",rs_dddoe_wr);
	printf("\trs_ddd_wr         %4.4X\n",rs_ddd_wr);
	printf("\trs_ddd_auto       %4.1X\n",rs_ddd_auto);
	printf("\trs_ddd_start      %4.1X\n",rs_ddd_start);
	printf("\trs_ddd_busy       %4.1X\n",rs_ddd_busy);
	printf("\trs_ddd_verify_ok  %4.1X\n",rs_ddd_verify_ok);
	printf("\n");

	for (i=0; i<=3; ++i) {
		printf("\tCh%1X  %2isteps  %2ins  %s\n",i,ddd_read[i],ddd_read[i]*2,ddd_name_rat[i].c_str());
	}

	// Get new delay value
L99010:
	printf("\tEnter Channel[0-3],Delay[0-15d] <cr>=exit: ");

	gets(line);
	n = strlen(line);
	sscanf(line,"%x %i",&ich,&ddd_delay);

	if (n>=0) goto L1900;
	if ((ich>=0 && ich<=3) && (ddd_delay>=0 && ddd_delay<=15)) goto L99020;
	printf("Channel must be 0-3, Value must be 0-15d\n");
	goto L99010;

	// Write new delay values to 3D3444 data registers
L99020:
	printf("\tWriting to 3D3444s....\n");

	ddd_read[ich] = ddd_delay;

	wr_data= (ddd_read[0] <<  0) |
		(ddd_read[1] <<  4) |
		(ddd_read[2] <<  8) |
		(ddd_read[3] << 12);

	// Select RAT JTAG chain from TMB boot register
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Create fat 0 for writing to data registers
	for (i=0; i<mxbitstream; ++i) {
		tdi[i]=0;
	}

	// Read current RAT USER2 register (5 bit opcode), readout is destructive
	chip_id = 0;
	opcode  = 0x03;								// FPGA USER2 opcode
	reg_len = 32;								// USER2 register length, 3d rat
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	printf("tdo="); for(i=0;i<reg_len;++i)printf("%1i",tdo[i]); printf("\n");

	// Decode USER2 data
	for (i=0; i<reg_len; ++i) {
		wso[i]=tdo[i];
	}

	tdi_to_i4(&tdo[0], rat_user2[0], 32, 0);
	printf("\tRAT USER2=%8.8X\n",rat_user2[0]);

	tdi_to_i4(&wso[ 0], ws_rpc_en,     2,0);
	tdi_to_i4(&wso[ 2], ws_ddd_start,  1,0);
	tdi_to_i4(&wso[ 3], ws_ddd_wr,    16,0);
	tdi_to_i4(&wso[19], ws_dddoe_wr,   4,0);
	tdi_to_i4(&wso[23], ws_perr_reset, 1,0);
	tdi_to_i4(&wso[24], ws_parity_odd, 1,0);
	tdi_to_i4(&wso[25], ws_perr_ignore,1,0);
	tdi_to_i4(&wso[26], ws_rpc_future, 6,0);

	// Set new RAT USER2 bits, sets new DDD delay values and un-starts state machine
	ws_ddd_wr    = wr_data;
	ws_ddd_start = 0;

	bit_to_array(ws_rpc_en,      &ivalarray[ 0],  2);
	bit_to_array(ws_ddd_start,   &ivalarray[ 2],  1);
	bit_to_array(ws_ddd_wr,      &ivalarray[ 3], 16);
	bit_to_array(ws_dddoe_wr,    &ivalarray[19],  4);
	bit_to_array(ws_perr_reset,  &ivalarray[23],  1);
	bit_to_array(ws_parity_odd,  &ivalarray[24],  1);
	bit_to_array(ws_perr_ignore, &ivalarray[25],  1);
	bit_to_array(ws_rpc_future,  &ivalarray[26],  6);

	for (i=0; i<reg_len; ++i) {
		rsd[i]=ivalarray[i];
	}

	// Turn on logging to make jtag example prom
	jtaglogmode = true;

	if (jtaglogmode) {
		jtag_file_name = "jtaglog.txt";
		jtag_file      = fopen(jtag_file_name.c_str(),"w");
		if (jtag_file  != NULL)  dprintf(stdout,"Opened         %s\n",jtag_file_name.c_str());
		if (jtag_file  == NULL) {fprintf(stdout,"Failed to open %s\n",jtag_file_name.c_str()); pause("WTF?");}

		ichain = 0x000D;							// RAT jtag chain
		adr    = boot_adr;							// Boot register address
		vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI
	}

	// Write RAT USER2 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x03;								// FPGA USER2 opcode
	reg_len = 32;								// USER2 register length, 3d rat
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

	// Check that DDD state machine went idle
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	chip_id = 0;
	opcode  = 0x02;								// FPGA USER1 opcode
	reg_len = 224;								// USER1 register length, 3D rats after 11/30/05
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	for (i=0; i<reg_len; ++i) {
		rs[i]=tdo[i];
	}

	tdi_to_i4(&tdo[  0], rat_user1[0], 32,0);
	tdi_to_i4(&tdo[ 32], rat_user1[1], 32,0);
	tdi_to_i4(&tdo[ 64], rat_user1[2], 32,0);
	tdi_to_i4(&tdo[ 96], rat_user1[3], 32,0);
	tdi_to_i4(&tdo[128], rat_user1[4], 32,0);
	tdi_to_i4(&tdo[160], rat_user1[5], 32,0);
	tdi_to_i4(&tdo[192], rat_user1[6], 32,0);

	tdi_to_i4(&rs[80], rs_ddd_busy,		1,0);

	if (rs_ddd_busy!=0) pause("ERROR: RAT 3D3444 State Machine stuck busy.");

	// Start DDD state machine
	ws_ddd_start = 1;
	reg_len      = 32;							// USER2 register length, 3d rat
	bit_to_array(ws_ddd_start, &ivalarray[2], 1);

	for (i=0; i<reg_len; ++i) {
		rsd[i]=ivalarray[i];
	}

	chip_id = 0;
	opcode  = 0x03;								// FPGA USER2 opcode
	reg_len = 32;								// USER2 register length, 3d rat
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

	// Check that state machine went busy
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	chip_id = 0;
	opcode  = 0x02l;							// FPGA USER1 opcode
	reg_len = 224;								// USER1 register length, 3D rats after 11/30/05
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	for (i=0; i<reg_len; ++i) {
		rs[i]=tdo[i];
	}

	tdi_to_i4(&tdo[  0], rat_user1[0], 32,0);
	tdi_to_i4(&tdo[ 32], rat_user1[1], 32,0);
	tdi_to_i4(&tdo[ 64], rat_user1[2], 32,0);
	tdi_to_i4(&tdo[ 96], rat_user1[3], 32,0);
	tdi_to_i4(&tdo[128], rat_user1[4], 32,0);
	tdi_to_i4(&tdo[160], rat_user1[5], 32,0);
	tdi_to_i4(&tdo[192], rat_user1[6], 32,0);

	tdi_to_i4(&rs[80], rs_ddd_busy,		1,0);

	if (rs_ddd_busy!=1) pause("ERROR: RAT 3D3444 State Machine failed to go busy.");

	// Un-start DDD state machine, it completes in a few microseconds
	ws_ddd_start = 0;
	reg_len      = 32;							// USER2 register length, 3d rat
	bit_to_array(ws_ddd_start, &ivalarray[2], 1);

	for (i=0; i<reg_len; ++i) {
		rsd[i]=ivalarray[i];
	}

	chip_id = 0;
	opcode  = 0x03;								// FPGA USER2 opcode
	reg_len = 32;								// USER2 register length, 3d rat
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

	// Check that machine went un-busy and verifed DDD data OK
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	adr     = boot_adr;							// Boot register address
	ichain  = 0x000D;							// RAT jtag chain
	chip_id = 0;
	opcode  = 0x02;								// FPGA USER1 opcode
	reg_len = 224;								// USER1 register length, 3D rats after 11/30/05
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	for (i=0; i<reg_len; ++i) {
		rs[i]=tdo[i];
	}

	tdi_to_i4(&tdo[  0], rat_user1[0], 32,0);
	tdi_to_i4(&tdo[ 32], rat_user1[1], 32,0);
	tdi_to_i4(&tdo[ 64], rat_user1[2], 32,0);
	tdi_to_i4(&tdo[ 96], rat_user1[3], 32,0);
	tdi_to_i4(&tdo[128], rat_user1[4], 32,0);
	tdi_to_i4(&tdo[160], rat_user1[5], 32,0);
	tdi_to_i4(&tdo[192], rat_user1[6], 32,0);

	tdi_to_i4(&rs[80], rs_ddd_busy,		1,0);
	tdi_to_i4(&rs[81], rs_ddd_verify_ok,1,0);

	// Check busy+verify bits
	if (rs_ddd_busy!=0) pause("ERROR: RAT 3D3444 State Machine stuck busy.");

	if (rs_ddd_verify_ok==1) printf("\tRAT 3D3444 State Machine verify OK\n\n\n");
	if (rs_ddd_verify_ok!=1) pause("ERROR: RAT 3D3444 State Machine failed to verify.");

	if (jtaglogmode) {
		fprintf(jtag_file,"%4.4X\n",0xE000 | (ichain << 3));	// relax all
		jtaglogmode=false;
		fclose(jtag_file);
	}

	goto L99000;

	//------------------------------------------------------------------------------
	//	Read/Write 3D3444 Delay using RAT JTAG State Machine:
	//------------------------------------------------------------------------------
L99100:
	pause ("Not implemented");
	goto L1900;

	//------------------------------------------------------------------------------
	//	Read/Reset RPC Parity Error counters in RAT FGPA
	//------------------------------------------------------------------------------
L99200:
	// Take RAT JTAG TAP to RTI
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Read RAT USER1 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x02;									// FPGA USER1 opcode
	reg_len = 224;									// USER1 register length, 3D rats after 11/30/05
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Decode RAT USER1 register
	for (i=0; i<reg_len; ++i) {
		rs[i]=tdo[i];
	}

	tdi_to_i4(&tdo[  0], rat_user1[0],32,0);
	tdi_to_i4(&tdo[ 32], rat_user1[1],32,0);
	tdi_to_i4(&tdo[ 64], rat_user1[2],32,0);
	tdi_to_i4(&tdo[ 96], rat_user1[3],32,0);
	tdi_to_i4(&tdo[128], rat_user1[4],32,0);
	tdi_to_i4(&tdo[160], rat_user1[5],32,0);
	tdi_to_i4(&tdo[192], rat_user1[6],32,0);
	printf("\tRAT USER1="); for(i=6;i>=0;--i)printf("8.8X"); printf("\n");

	tdi_to_i4(&rs[ 82], rs_rpc0_parity_ok,1,0);
	tdi_to_i4(&rs[ 83], rs_rpc1_parity_ok,1,0);
	tdi_to_i4(&rs[ 84], rs_rpc0_cnt_perr,16,0);
	tdi_to_i4(&rs[100], rs_rpc1_cnt_perr,16,0);

	tdi_to_i4(&rs[153], rs_rpc0_pdata,   19,0);
	tdi_to_i4(&rs[172], rs_rpc1_pdata,   19,0);

	printf("\t%s%5.1X\n","rs_rpc0_parity_ok ",rs_rpc0_parity_ok);
	printf("\t%s%5.1X\n","rs_rpc1_parity_ok ",rs_rpc1_parity_ok);
	printf("\t%s%5.4X\n","rs_rpc0_cnt_perr  ",rs_rpc0_cnt_perr);
	printf("\t%s%5.4X\n","rs_rpc1_cnt_perr  ",rs_rpc1_cnt_perr);
	printf("\t%s%5.5X\n","rs_rpc0_pdata     ",rs_rpc0_pdata);
	printf("\t%s%5.5X\n","rs_rpc1_pdata     ",rs_rpc1_pdata);

	// Inquire if want reset
	printf("\n\tClear parity error counters? y|n <cr>=n: ");
	gets(line);
	n = strlen(line);
	sscanf(line,"%c",&i);

	if (n<=0 || (i!='Y' && i!='y')) goto L1900;

	// Read current RAT USER2 register (5 bit opcode), readout is destructive
	chip_id = 0;
	opcode  = 0x03;							// FPGA USER2 opcode
	reg_len = 32;							// USER2 register length, 3d rat
	adr     = boot_adr;						// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");

	// Decode USER2 data
	for (i=0; i<reg_len; ++i) {
		wso[i]=tdo[i];
	}

	tdi_to_i4(&tdo[0],rat_user2[0],32,0);
	dprintf(stdout,"\tRAT USER2=%8.8X\n",rat_user2[0]);

	tdi_to_i4(&wso[ 0], ws_rpc_en,      2,0);
	tdi_to_i4(&wso[ 2], ws_ddd_start,   1,0);
	tdi_to_i4(&wso[ 3], ws_ddd_wr,     16,0);
	tdi_to_i4(&wso[19], ws_dddoe_wr,    4,0);
	tdi_to_i4(&wso[23], ws_perr_reset,  1,0);
	tdi_to_i4(&wso[24], ws_parity_odd,  1,0);
	tdi_to_i4(&wso[25], ws_perr_ignore, 1,0);
	tdi_to_i4(&wso[26], ws_rpc_future,  6,0);

	// Set new RAT USER2 bits, assert parity error reset
	ws_perr_reset=1;

	bit_to_array(ws_rpc_en,     &ivalarray[ 0], 2);
	bit_to_array(ws_ddd_start,  &ivalarray[ 2], 1);
	bit_to_array(ws_ddd_wr,     &ivalarray[ 3],16);
	bit_to_array(ws_dddoe_wr,   &ivalarray[19], 4);
	bit_to_array(ws_perr_reset, &ivalarray[23], 1);
	bit_to_array(ws_parity_odd, &ivalarray[24], 1);
	bit_to_array(ws_perr_ignore,&ivalarray[25], 1);
	bit_to_array(ws_rpc_future, &ivalarray[26], 6);

	for (i=0; i<reg_len; ++i) {
		rsd[i]=ivalarray[i];
	}

	chip_id = 0;
	opcode  = 0x03;								// FPGA USER2 opcode
	reg_len = 32;								// USER2 register length, 3d rat
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

	// Set new RAT USER2 bits, de-assert parity error reset
	ws_perr_reset=0;

	bit_to_array(ws_perr_reset, &ivalarray[23],1);

	for (i=0; i<reg_len; ++i) {
		rsd[i]=ivalarray[i];
	}

	chip_id = 0;
	opcode  = 0x03;								// FPGA USER2 opcode
	reg_len = 32;								// USER2 register length, 3d rat
	adr     = boot_adr;							// Boot register address
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

	printf("\tRAT parity counter cleared.\n\n");
	goto L1900;

	//------------------------------------------------------------------------------
	//	Read Current RPC data
	//------------------------------------------------------------------------------
L99300:
	// Get current RAT mode
	adr	   = vme_ratctrl_adr+base_adr;
	status = vme_read(adr,rd_data);
	rat_sync_mode = rd_data & 0x1;

	// Change mode
	inquire("\tRAT sync mode cr=%1i", minv=0, maxv=1, radix=10, rat_sync_mode);

	wr_data = (rd_data & 0xFFFE) | rat_sync_mode;
	adr	    = vme_ratctrl_adr+base_adr;
	status  = vme_write(adr,wr_data);

	// Unmask inputs from RAT
	adr	   = rpc_inj_adr+base_adr;
	status = vme_read(adr,rd_data);
	wr_data= rd_data | 0x0001;				// 1=enable rat inputs to tmb 
	status = vme_write(adr,wr_data);

	// Read RAT data registers
	for (irat=0; irat<=1; ++irat) {
		adr     = rpc_cfg_adr+base_adr;
		status	= vme_read(adr,rd_data);
		rd_data = rd_data & 0xF9FF;				// zero out old rat bank
		wr_data = rd_data | (irat<<9);			// select rat ram bank
		status	= vme_write(adr,wr_data);

		adr     = rpc_cfg_adr+base_adr;
		status	= vme_read(adr,rd_data);
		rpc_rbxn[irat] = (rd_data>>11) & 0x0007;// rat MSBs

		adr     = rpc_rdata_adr+base_adr;		// rat LSBs
		status	= vme_read(adr,rd_data);
		rpc_rdata[irat] = rd_data;

		printf("\tRPC%1i bxn=%1.1X pads=%4.4X\n",irat,rpc_bxn[irat],rpc_rdata[irat]);
	}	// close for irat

	goto L1900;
}
//------------------------------------------------------------------------------
//	TTC Command
//------------------------------------------------------------------------------
void L2000() {
	//L2000:

	printf("\t0   Exit\n");
	printf("\t1   BX0\n");
	printf("\t3   L1 Reset\n");
	printf("\t6   Start Trigger\n");
	printf("\t7   Stop  Trigger\n");

	// Get current FMM state
L2020:
	adr    = base_adr+ccb_cmd_adr;
	status = vme_read(adr,rd_data);
	fmm_state = (rd_data >> 4) & 0x0007;

	printf("\tFMM State %2.2X %s  TTC Command: ",fmm_state,sfmm_state[fmm_state%5].c_str());
	gets(line);
	sscanf(line,"%i",&ifunc);

	if (ifunc==0) return;
	ttc_cmd = abs(ifunc);

	// Turn off ccb_cmd_strobe, disconnect ccb backplane
L2021:
	adr     = base_adr+ccb_cmd_adr;
	wr_data =0x0001;
	status  = vme_write(adr,wr_data);

	// Assert ttc command and turn on strobe
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);

	// deassert ttc command and turn off strobe
	wr_data =0x0001;
	status  = vme_write(adr,wr_data);

	if (ifunc < 0) goto L2021;	// bang mode
	goto L2020;
}
//------------------------------------------------------------------------------
//	Sequencer State, Buffer Queue, L1A Queue, Sequencer Debug
//------------------------------------------------------------------------------
void L2100() {
L2100:

	// Get current FMM state
	adr    = base_adr+ccb_cmd_adr;
	status = vme_read(adr,rd_data);
	fmm_state = (rd_data >> 4) & 0x0007;

	// Get current Sequencer state and L1A queue status
	adr     = base_adr+seqsm_adr;
	status  = vme_read(adr,rd_data);
	clct_sm = (rd_data >> 0) & 0x7;
	read_sm = (rd_data >> 3) & 0x1F;

	queue_full = (rd_data >>  8) & 0x1;
	queue_empty= (rd_data >>  9) & 0x1;
	queue_ovf  = (rd_data >> 10) & 0x1;
	queue_udf  = (rd_data >> 11) & 0x1;

	printf("\tFMM state      %4i %s\n",fmm_state,sfmm_state[fmm_state%5].c_str());
	printf("\tclct_sm state  %4i %s\n",clct_sm,sclct_sm[clct_sm%6].c_str());
	printf("\tread_sm state  %4i %s\n",read_sm,sread_sm[read_sm%21].c_str());

	printf("\tqueue_full     %4i\n",queue_full);
	printf("\tqueue_empty    %4i\n",queue_empty);
	printf("\tqueue_ovf      %4i\n",queue_ovf);
	printf("\tqueue_udf      %4i\n",queue_udf);

	// Read buffer status
	adr    = buf_stat0_adr+base_adr;
	status = vme_read(adr,rd_data);

	wr_buf_ready	= (rd_data >>  0) & 0x1;		// Write buffer is ready
	buf_stalled		= (rd_data >>  1) & 0x1;		// Buffer write pointer hit a fence and stalled
	buf_q_full		= (rd_data >>  2) & 0x1;		// All raw hits ram in use, ram writing must stop
	buf_q_empty		= (rd_data >>  3) & 0x1;		// No fences remain on buffer stack
	buf_q_ovf_err	= (rd_data >>  4) & 0x1;		// Tried to push when stack full
	buf_q_udf_err	= (rd_data >>  5) & 0x1;		// Tried to pop when stack empty
	buf_q_adr_err	= (rd_data >>  6) & 0x1;		// Fence adr popped from stack doesnt match rls adr
	buf_display		= (rd_data >>  8) & 0xFF;		// Buffer fraction in use display

	adr    = buf_stat1_adr+base_adr;
	status = vme_read(adr,rd_data);
	wr_buf_adr = (rd_data >> 0) & 0x7FF;			// Current ddress of header write buffer

	adr    = buf_stat2_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_dist = (rd_data >> 0) & 0x7FF;		// Distance to 1st fence address
	buf_free_space  = int(100.*float(buf_fence_dist)/2047.);

	adr    = buf_stat3_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_cnt = (rd_data >> 0) & 0x7FF;			// Number of fences in fence RAM currently

	adr    = buf_stat4_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_cnt_peak=(rd_data >> 0) & 0xFFF;		// Peak number of fences in fence RAM

	printf("\twr_buf_ready   %4i\n",wr_buf_ready);
	printf("\tbuf_stalled    %4i\n",buf_stalled);
	printf("\tbuf_q_full     %4i\n",buf_q_full);
	printf("\tbuf_q_empty    %4i\n",buf_q_empty);
	printf("\tbuf_q_ovf_err  %4i\n",buf_q_ovf_err);
	printf("\tbuf_q_udf_err  %4i\n",buf_q_udf_err);
	printf("\tbuf_q_adr_err  %4i\n",buf_q_adr_err);
	printf("\tbuf_display    %4i\n",buf_display);
	printf("\twr_buf_adr     %4i\n",wr_buf_adr);
	printf("\tbuf_fence_dist %4i\n",buf_fence_dist);
	printf("\tbuf_fence_cnt  %4i\n",buf_fence_cnt);
	printf("\tbuf_fence_peak %4i\n",buf_fence_cnt_peak);
	printf("\tbuf_free_space %4i\n",buf_free_space);
	printf("\n");

	// Read sequencer Debug register
	for (seqdeb_adr=0; seqdeb_adr<=8; ++seqdeb_adr)
	{
		adr     = seq_debug_adr+base_adr;
		wr_data = seqdeb_adr;
		status  = vme_write(adr,wr_data);	// write sub adr
		status  = vme_read (adr,rd_data);	// read data
		seqdeb_rd_mux = (rd_data >> 4);		// Extract mux data

		switch (seqdeb_adr)
		{
			case 0x0: deb_wr_buf_adr	= seqdeb_rd_mux;							break;	// [10:0]	Buffer write address at last pretrig
			case 0x1: deb_buf_push_adr	= seqdeb_rd_mux;							break;	// [10:0]	Queue push address at last push
			case 0x2: deb_buf_pop_adr	= seqdeb_rd_mux;							break;	// [10:0]	Queue pop  address at last pop

			case 0x3: deb_buf_push_data	= seqdeb_rd_mux;							break;	// [11:0]	Queue push data at last push
			case 0x4: deb_buf_push_data = deb_buf_push_data | (seqdeb_rd_mux << 12);break;	// [23:12]
			case 0x5: deb_buf_push_data = deb_buf_push_data | (seqdeb_rd_mux << 24);break;	// [31:24]

			case 0x6: deb_buf_pop_data	= seqdeb_rd_mux;							break;	// [11:0]	Queue pop data at last pop
			case 0x7: deb_buf_pop_data	= deb_buf_pop_data | (seqdeb_rd_mux << 12);	break;	// [23:12]
			case 0x8: deb_buf_pop_data	= deb_buf_pop_data | (seqdeb_rd_mux << 24);	break;	// [31:24]
		}
	}
	deb_adr_diff= abs(long(deb_buf_push_adr-deb_wr_buf_adr));

	printf("\tdeb_wr_buf_adr    %8.4X\n",deb_wr_buf_adr);
	printf("\tdeb_buf_push_adr  %8.4X  ",deb_buf_push_adr);printf("push_adr-pretrig_adr=%8.4X\n",deb_adr_diff);
	printf("\tdeb_buf_pop_adr   %8.4X\n",deb_buf_pop_adr);
	printf("\tdeb_buf_push_data %8.8X\n",deb_buf_push_data);
	printf("\tdeb_buf_pop_data  %8.8X\n",deb_buf_pop_data);
	printf("\n");

	// Unpack L1A write data
	push_l1a_bxn_win	= (deb_buf_push_data >>  0) & 0x7FF;		// [11:0] BXN at L1A arrival
	push_l1a_cnt_win	= (deb_buf_push_data >> 12) & 0x7FF;		// [11:0] L1As received at time of this event
	push_l1a_match_win	= (deb_buf_push_data >> 24) & 0x7;			// [3:0]  Position of l1a in window
	push_l1a_push_me	= (deb_buf_push_data >> 28) & 0x1;			// [0:0]  L1A with TMB in window, and readouts enabled
	push_l1a_notmb		= (deb_buf_push_data >> 29) & 0x1;			// [0:0]  L1A with no TMB in window, readout anyway
	push_tmb_nol1a		= (deb_buf_push_data >> 30) & 0x1;			// [0:0]  TMB with no L1A arrival, readout anyway
	push_wr_buf_avail	= (deb_buf_push_data >> 31) & 0x1;			// [0:0]  Buffer available at L1A match

	pop_l1a_bxn_win		= (deb_buf_pop_data >>  0) & 0x7FF;			// [11:0] BXN at L1A arrival
	pop_l1a_cnt_win		= (deb_buf_pop_data >> 12) & 0x7FF;			// [11:0] L1As received at time of this event
	pop_l1a_match_win	= (deb_buf_pop_data >> 24) & 0x7;			// [3:0]  Position of l1a in window
	pop_l1a_push_me		= (deb_buf_pop_data >> 28) & 0x1;			// [0:0]  L1A with TMB in window, and readouts enabled
	pop_l1a_notmb		= (deb_buf_pop_data >> 29) & 0x1;			// [0:0]  L1A with no TMB in window, readout anyway
	pop_tmb_nol1a		= (deb_buf_pop_data >> 30) & 0x1;			// [0:0]  TMB with no L1A arrival, readout anyway
	pop_wr_buf_avail	= (deb_buf_pop_data >> 31) & 0x1;			// [0:0]  Buffer available at L1A match

	printf("\tpush_l1a_bxn_win   %4.3X\n",push_l1a_bxn_win);
	printf("\tpush_l1a_cnt_win   %4.3X\n",push_l1a_cnt_win);
	printf("\tpush_l1a_match_win %4.1X\n",push_l1a_match_win);
	printf("\tpush_l1a_push_me   %4.1X\n",push_l1a_push_me);
	printf("\tpush_l1a_notmb     %4.1X\n",push_l1a_notmb);
	printf("\tpush_tmb_nol1a     %4.1X\n",push_tmb_nol1a);
	printf("\tpush_wr_buf_avail  %4.1X\n",push_wr_buf_avail);
	printf("\n");

	printf("\tpop_l1a_bxn_win    %4.3X\n",pop_l1a_bxn_win);
	printf("\tpop_l1a_cnt_win    %4.3X\n",pop_l1a_cnt_win);
	printf("\tpop_l1a_match_win  %4.1X\n",pop_l1a_match_win);
	printf("\tpop_l1a_push_me    %4.1X\n",pop_l1a_push_me);
	printf("\tpop_l1a_notmb      %4.1X\n",pop_l1a_notmb);
	printf("\tpop_tmb_nol1a      %4.1X\n",pop_tmb_nol1a);
	printf("\tpop_wr_buf_avail   %4.1X\n",pop_wr_buf_avail);
	printf("\n");

	// Inquire
	printf("\texit=<cr>,else=run again:");
	gets(line);
	if (line[0]==NULL) return;
	goto L2100;
}
//------------------------------------------------------------------------------
//	MPC Accept
//------------------------------------------------------------------------------
void L2200() {
L2200:

	// Get current MPC accept state
	adr    = base_adr+tmb_trig_adr;
	status = vme_read(adr,rd_data);

	// Decode MPC status
	mpc_delay     = (rd_data >>  5) & 0xF;
	mpc_accept0   = (rd_data >>  9) & 0x1;
	mpc_accept1   = (rd_data >> 10) & 0x1;
	mpc_reserved0 = (rd_data >> 11) & 0x1;
	mpc_reserved1 = (rd_data >> 12) & 0x1;

	printf("\tmpc_accept0   = %2i\n",mpc_accept0);
	printf("\tmpc_accept1   = %2i\n",mpc_accept1);
	printf("\tmpc_reserved0 = %2i\n",mpc_reserved0);
	printf("\tmpc_reserved1 = %2i\n",mpc_reserved1);
	printf("\tmpc_reserved1 = %2i\n",mpc_reserved1);
	printf("\n");

	// Change MPC accept delay
	printf("\tmpc_delay     = %2i <cr>=keep: ",mpc_delay);
	gets(line);
	if (line[0]==NULL) return;
	sscanf(line,"%i",&mpc_delay);	

	adr     = base_adr+tmb_trig_adr;
	wr_data = rd_data & 0xFE1F;
	wr_data = wr_data | (mpc_delay << 5);
	status  = vme_write(adr,wr_data);

	goto L2200;
}
//------------------------------------------------------------------------------
//	ALCT Test Sub-Menu
//------------------------------------------------------------------------------
void L2300() {
L2300:

	// Display menu
	printf("\n");
	printf("\tALCT Test Submenu:\n");
	printf("\t1:  Read ALCT JTAG Register:  NORMAL ALCT firmware\n");
	printf("\t2:  Read ALCT JTAG Register:  DEBUG  ALCT firmware\n");
	printf("\t3:  ALCT tx clock delay scan: NORMAL ALCT firmware\n");
	printf("\t4:  ALCT tx clock delay scan: DEBUG  ALCT firmware\n");
	printf("\t5:  ALCT rx clock delay scan: DEBUG  ALCT firmware\n");
	printf("\t6:  Software ext_trig ALCT:   Check for CRC errors\n");
	printf("\t7:  Hardware ext_trig ALCT:   Check for CRC errors\n");
	printf("\t8:  JTAG tests\n");
	printf("\t9:  Hardware ext_trig ALCT:   ALCT bits vs CRC\n");
	printf("\t10: ALCT rxd clock delay scan:    ALCT-to-TMB Teven|Todd\n");
	printf("\t11: ALCT txd clock delay scan:    TMB-to-ALCT Teven|Todd Loopback\n");
	printf("\t12: ALCT txd+rxd default delays   TMB-to-ALCT Walking 1  Loopback\n");
	printf("\t13: ALCT txd+rxd clock delay scan TMB-to-ALCT TMB Random Loopback\n");
	printf("\t14: ALCT-TMB Quick Test\n");
	printf("\t15: CFEB rx loopback using ALCT\n");
	printf("\t16: ALCT effect of posneg and tof on bx0 arrival at TMB\n");
	printf("\t17: ALCT txd+rxd clock delay scan, Random Loopback, posneg table\n");
	printf("\t18: CFEB bad-bits register tests\n");
	printf("\t19: ALCT effect of txd,rxd,tof,posnegs on bx0 arrival at TMB\n");
	printf("\t20: CFEB Blocked CFEB distrips walking hcm test\n");
	printf("\t<cr> Exit\n");
	printf("       > ");

	gets(line);
	if (line[0]==NULL) return;
	sscanf(line,"%i",&ifunc);

	i=abs(ifunc);
	if (i== 1) goto L23100;
	if (i== 2) goto L23200;
	if (i== 3) goto L23300;
	if (i== 4) goto L23400;
	if (i== 5) goto L23500;
	if (i== 6) goto L23600;
	if (i== 7) goto L23700;
	if (i== 8) goto L23800;
	if (i== 9) goto L23900;
	if (i==10) goto L231000;
	if (i==11) goto L231100;
	if (i==12) goto L231200;
	if (i==13) goto L231300;
	if (i==14) goto L231400;
	if (i==15) goto L231500;
	if (i==16) goto L231600;
	if (i==17) goto L231700;
	if (i==18) goto L231800;
	if (i==19) goto L231900;
	if (i==20) goto L232000;
	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT: Read JTAG chain: Normal Firmware
	//------------------------------------------------------------------------------
L23100:
	printf("\tMake sure you removed the JTAG cable\n");

	//	Chain ID	Section		 Control or Program
	//	--------	------------ ------------------
	//	  0			Slow Control control registers
	//	  1			Slow Control PROM
	//	  2			Mezzanine    control registers
	//	  3			Mezzanine    FPGA+PROM
	//
	//
	//	Mezzanie Virtex Control Registers (5-bit opcode)
	//
	//	Name			OpCd		Len	Dir		Function
	//	------------	---			---	-----	------------------
	IDRead        = 0x0;  // 	40	read	Virtex ID register
	HCMaskRead    = 0x1;  // 	384	read	hot mask
	HCMaskWrite   = 0x2;  // 	384	write	hot mask
	RdTrig        = 0x3;  // 	5	read	trigger register
	WrTrig        = 0x4;  // 	5	write	trigger register
	RdCfg         = 0x6;  // 	69	read	control register
	WrCfg         = 0x7;  // 	69	write	control register
	Wdly          = 0xd;  // 	120	write	delay lines. cs_dly bits in Par
	Rdly          = 0xe;  // 	121?read	delay lines. cs_dly bits in Par
	CollMaskRead  = 0x13; // 	224	read	collision pattern mask
	CollMaskWrite = 0x14; // 	224	write	collision pattern mask
	ParamRegRead  = 0x15; // 	6	read	delay line control register actually
	ParamRegWrite = 0x16; // 	6	read	delay line control register actually
	InputEnable   = 0x17; // 	0	write?	commands to disable and enable input
	InputDisable  = 0x18; // 	0	write?	commands to disable and enable input
	YRwrite       = 0x19; // 	31	write	output register (for debugging with UCLA test board)
	OSread        = 0x1a; // 	49	read	output storage
	SNread        = 0x1b; //	1	read	one bit of serial number
	SNwrite0      = 0x1c; //	0	write	0 bit into serial number chip
	SNwrite1      = 0x1d; //	0	write	1 bit into serial number chip
	SNreset       = 0x1e; //	0	write	reset serial number chip
	Bypass        = 0x1f; // 	1	bypass
	//
	//	Configuration Register
	//	Register Bits	Signal				Default	BeamTest
	//	-------------	--------------		-------	--------
	//	ConfgReg[1:0]	trig_mode[1:0]		0		2
	//	ConfgReg[2]		ext_trig_en			0		0
	//	ConfgReg[3]		pretrig_halt		0		0
	//	ConfgReg[4]		inject				0		?
	//	ConfgReg[5]		inject_mode			0		?
	//	ConfgReg[12:6]	inject_mask[6:0]	7Fh		?
	//	ConfgReg[15:13]	nph_thresh[2:0]		2		2
	//	ConfgReg[18:16]	nph_pattern[2:0]	4		4
	//	ConfgReg[20:19]	drift_delay[1:0]	3		?
	//	ConfgReg[25:21]	fifo_tbins[4:0]		7		8
	//	ConfgReg[30:26]	fifo_pretrig[4:0]	1		12d
	//	ConfgReg[32:31]	fifo_mode[1:0]		1		?
	//	ConfgReg[35:33]	fifo_lastlct[2:0]	3		?
	//	ConfgReg[43:36]	l1a_delay[7:0]		78h		128d, 78h=120d
	//	ConfgReg[47:44]	l1a_window[3:0]		3		3
	//	ConfgReg[51:48]	l1a_offset[3:0]		0		1
	//	ConfgReg[52]	l1a_internal		0		0
	//	ConfgReg[55:53]	BoardID[2:0]		5		?
	//	ConfgReg[59:56]	bxn_offset[3:0]		0		?
	//	ConfgReg[60]	ccb_enable			0		-
	//	ConfgReg[61]	alct_jtag_ds		1		-
	//	ConfgReg[63:62]	alct_tmode[1:0]		0		-
	//	ConfgReg[65:64]	alct_amode[1:0]		0		?		
	//	ConfgReg[66]	alct_mask_all		0		-
	//	ConfgReg[67]	trig_info_en		1		?
	//	ConfgReg[68]	sn_select			0		0
	//
	//
	//	Virtex-E ID register
	//	Field		Len	Typical	Description
	//	-------		---	-------	--------------------------
	//	[3:0]		4	7		Chip ID number, fixed at 7
	//	[7:4]		4	C		Software Version ID [0-F]
	//	[23:8]		16	2001	Year: 4 BCD digits
	//	[31:24]		8	17		Day:  2 BCD digits
	//	[39:32]		8	09		Month: 2 BCD digits
	//
	//	Virtex-E / Spartan-6 ID register
	//	Field		Len	Name	Description
	//	-------		---	----	--------------------------
	//	[5:0]		6	ver		Firmware version
	//	[8:6]		3	wgn		(see Table 9)
	//	[9]			1	bf		(see Table 9)
	//	[10]		1	np		(see Table 9)
	//	[11]		1	mr		(see Table 9)
	//	[12]		1	ke		(see Table 9)
	//	[13]		1	rl		(see Table 9)
	//	[14]		1	pb		(see Table 9)
	//	[15]		1	sp6		(see Table 9)
	//	[16]		1	seu		(see Table 9)
	//	[18:17]		2	resvd	Reserved
	//	[30:19]		12	yea		binary code
	//	[35:31]		5	day		binary code
	//	[39:36]		4	month	binary code

	// IDCODEs
	//	Device		IR Length	IDCODEinstruction	DR Length	IDCODE			USERCODEinstruction	DR Length
	//	XCV600E		5 bits		0x09				32 bits		0xv0A30093		0x08				32 bits
	//	XC6SLX150	6 bits		0x09				32 bits		0xX401D093		0x08				32 bits
	//	XCS40XL		3 bits		0x6					32 bits		0x0041C093		None				None
	//	XC18V01		8 bits		0xFE				32 bits		0xv50X4093		0xFD				32 bits
	//	XC18V04		8 bits		0xFE				32 bits		0xv50X6093		0xFD				32 bits
	//	XCF08P		16 bits		0x00FE				32 bits		0xv5057093		0x00FD				32 bits
	//	XCF32P		16 bits		0x00FE				32 bits		0xv5059093		0x00FD				32 bits
	//
	//------------------------------------------------------------------------------
	// Read ALCT mez FPGA IDcode
	//!	ichain = 0x03;									// ALCT Virtex-E  Mezzanine pgm jtag chain
	ichain = 0x13;									// ALCT Spartan-6 Mezzanine pgm jtag chain

	adr    = boot_adr;								// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI

	chip_id = 0;
	opcode  = 0x09;									// FPGA IDcode opcode
	reg_len = 32;

	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	tdi_to_i4(tdo,idcode,32,0);								// Deserialize

	idcode_decode (idcode, sdevice_type, sdevice_name, sdevice_version, sdevice_size);

	fprintf(stdout,"\tALCT Mez  Device=%1i IDcode=%8.8X %s Name=%s\tVer=%s\tSize=%s \n",
			chip_id, idcode, sdevice_type.c_str(), sdevice_name.c_str(), sdevice_version.c_str(), sdevice_size.c_str());

	// Read FPGA and PROM IDcodes
	for (chip_id=0; chip_id<=2; ++chip_id) {

		if (chip_id==0) opcode=0x09;					// FPGA IDcode opcode, expect v0A30093
		if (chip_id==1) opcode=0xFE;					// PROM IDcode opcode
		reg_len=32;										// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],idcode,32,0);
		idcode_decode (idcode, sdevice_type, sdevice_name, sdevice_version, sdevice_size);

		fprintf(stdout,"\tALCT Mez  Device=%1i IDcode=%8.8X %s Name=%s\tVer=%s\tSize=%s \n",
				chip_id, idcode, sdevice_type.c_str(), sdevice_name.c_str(), sdevice_version.c_str(), sdevice_size.c_str());

	}	// close for chip_id

	// Read FPGA/PROM USERCodes
	for (chip_id=0; chip_id<=2; ++chip_id) {
		if (chip_id==0) opcode = 0x08;					// FPGA USERcode opcode
		if (chip_id==1) opcode = 0xFD;					// PROM USERcode opcode
		reg_len=32;										// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],idcode,32,0);
		printf("\tALCT %s device %1i USERcode = %8.8X\n",alct_chip_type[chip_id].c_str(),chip_id,idcode);
	}	// close for chip_id

	// Create fat 0 for writing to data registers
	for (i=0; i<mxbitstream; ++i) {
		tdi[i]=0;
	}

	// Select ALCT Mezzanine FPGA control JTAG chain from TMB boot register
	ichain = 0x0002;								// ALCT Mezzanine control jtag chain
	adr    = boot_adr;								// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI

	// Read ALCT ID register (5 bit opcode)
	chip_id = 0;
	opcode  = IDRead;								// ALCT ID register opcode
	reg_len = 40;									// Register length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");

	// Decode ALCT ID register
	for (i=0; i<=39; ++i) {
		rsa[i]=tdo[i];
	}

	tdi_to_i4(&tdo[ 0], alct_idreg[0], 32,0);
	tdi_to_i4(&tdo[32], alct_idreg[1],  8,0);
	printf("\n\tALCT ID =%8.8X%8.8X\n",alct_idreg[1],alct_idreg[0]);

	bool alct_virtexe=false;
	if (alct_virtexe)
	{
		tdi_to_i4(&rsa[ 0], rsa_chip_id,  4,0);
		tdi_to_i4(&rsa[ 4], rsa_version,  4,0);
		tdi_to_i4(&rsa[ 8], rsa_year,    16,0);
		tdi_to_i4(&rsa[24], rsa_day,      8,0);
		tdi_to_i4(&rsa[32], rsa_month,    8,0);

		printf("\trsa_chip_id %4.1X\n",rsa_chip_id);
		printf("\trsa_version %4.1X\n",rsa_version);
		printf("\trsa_year    %4.4X\n",rsa_year);
		printf("\trsa_day     %4.2X\n",rsa_day);
		printf("\trsa_month   %4.2X\n",rsa_month);
	}
	else
	{
		tdi_to_i4(&rsa[ 0], rsa_ver,      6,0);
		tdi_to_i4(&rsa[ 6], rsa_wgn,      3,0);
		tdi_to_i4(&rsa[ 9], rsa_bf,       1,0);
		tdi_to_i4(&rsa[10], rsa_np,       1,0);
		tdi_to_i4(&rsa[11], rsa_mr,       1,0);
		tdi_to_i4(&rsa[12], rsa_ke,       1,0);
		tdi_to_i4(&rsa[13], rsa_rl,       1,0);
		tdi_to_i4(&rsa[14], rsa_pb,       1,0);
		tdi_to_i4(&rsa[15], rsa_sp6,      1,0);
		tdi_to_i4(&rsa[16], rsa_seu,      1,0);
		tdi_to_i4(&rsa[17], rsa_res1,     2,0);
		tdi_to_i4(&rsa[19], rsa_year,    12,0);
		tdi_to_i4(&rsa[31], rsa_day,      5,0);
		tdi_to_i4(&rsa[36], rsa_month,    4,0);

		printf("\trsa_ver     %4.2X\n",rsa_ver);
		printf("\trsa_wgn     %4.1X\n",rsa_wgn);
		printf("\trsa_bf      %4.1X\n",rsa_bf);
		printf("\trsa_np      %4.1X\n",rsa_np);
		printf("\trsa_mr      %4.1X\n",rsa_mr);
		printf("\trsa_ke      %4.1X\n",rsa_ke);
		printf("\trsa_rl      %4.1X\n",rsa_rl);
		printf("\trsa_pb      %4.1X\n",rsa_pb);
		printf("\trsa_sp6     %4.1X\n",rsa_sp6);
		printf("\trsa_seu     %4.1X\n",rsa_seu);
		printf("\trsa_res1    %4.1X\n",rsa_res1);
		printf("\trsa_year    %4.3X %4.4i\n",rsa_year,rsa_year);
		printf("\trsa_day     %4.2X %4.2i\n",rsa_day,rsa_day);
		printf("\trsa_month   %4.1X %4.2i\n",rsa_month,rsa_month);
	}

	// Read ALCT digital serial numbers
	// Reset DS2401
	vme_jtag_write_ir(adr,ichain,chip_id,SNreset );
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite1);

	// Send read command 33h to ibutton chip
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite1);
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite1);
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite0);
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite0);

	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite1);
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite1);
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite0);
	vme_jtag_write_ir(adr,ichain,chip_id,SNwrite0);

	// Read 64 bits of DSN bit by bit
	reg_len    = 1;											// Register length
	alct_sn[0] = 0;
	alct_sn[1] = 0;

	for (i=0; i<=63; ++i) {
		vme_jtag_write_ir(adr,ichain,chip_id,SNread);
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		ibit=tdo[0];
		if (i>= 0 && i < 31) alct_sn[0] = alct_sn[0] | (ibit<<i);
		if (i>=32 && i < 63) alct_sn[1] = alct_sn[1] | (ibit<<i);
	}

	printf("\n\tALCT DSN =%8.8X%8.8X\n",alct_sn[1],alct_sn[0]);

	alct_dsn_mfg = (alct_sn[0] >>  0) & 0x00FF;
	alct_dsn     = (alct_sn[0] >>  8) & 0xFFFFFF;
	alct_dsn_crc = (alct_sn[0] >> 28) & 0x00FF;

	printf("\n\tDigital Serial for ALCT");
	printf(" CRC=%2.2X",alct_dsn_crc);
	printf(" DSN=%6.6X",alct_dsn);
	printf(" MFG=%2.2X",alct_dsn_mfg);
	printf("\n");

	// Select ALCT Mezzanine FPGA control JTAG chain from TMB boot register
	ichain = 0x0002;							// ALCT Mezzanine control jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Read ALCT Configuration register (5 bit opcode)
	chip_id = 0;
	opcode  = RdCfg;							// ALCT cfg register opcode
	//	opcode  = 0x06;								// ALCT cfg register opcode
	reg_len = 69;								// Register length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");

	// Decode ALCT configuration register
	for (i=0; i<69; ++i) {
		rsa[i]=tdo[i];
	}

	tdi_to_i4(&tdo[ 0], alct_cfgreg[0], 32,0);
	tdi_to_i4(&tdo[32], alct_cfgreg[1], 32,0);
	tdi_to_i4(&tdo[64], alct_cfgreg[2],  5,0);

	printf("\n\tALCT Cfg=%2.2X%8.8X%8.8X\n",alct_cfgreg[2],alct_cfgreg[1],alct_cfgreg[0]);

	tdi_to_i4(&rsa[ 0], rsa_trig_mode,    2,0);
	tdi_to_i4(&rsa[ 2], rsa_ext_trig_en,  1,0);
	tdi_to_i4(&rsa[ 3], rsa_pretrig_halt, 1,0);
	tdi_to_i4(&rsa[ 4], rsa_inject,       1,0);
	tdi_to_i4(&rsa[ 5], rsa_inject_mode,  1,0);
	tdi_to_i4(&rsa[ 6], rsa_inject_mask,  7,0);
	tdi_to_i4(&rsa[13], rsa_nph_thresh,   3,0);
	tdi_to_i4(&rsa[16], rsa_nph_pattern,  3,0);
	tdi_to_i4(&rsa[19], rsa_drift_delay,  2,0);
	tdi_to_i4(&rsa[21], rsa_fifo_tbins,   5,0);
	tdi_to_i4(&rsa[26], rsa_fifo_pretrig, 5,0);
	tdi_to_i4(&rsa[31], rsa_fifo_mode,    2,0);
	tdi_to_i4(&rsa[33], rsa_fifo_lastlct, 3,0);
	tdi_to_i4(&rsa[36], rsa_l1a_delay,    8,0);
	tdi_to_i4(&rsa[44], rsa_l1a_window,   4,0);
	tdi_to_i4(&rsa[48], rsa_l1a_offset,   4,0);	
	tdi_to_i4(&rsa[52], rsa_l1a_internal, 1,0);
	tdi_to_i4(&rsa[53], rsa_board_id,     3,0);
	tdi_to_i4(&rsa[56], rsa_bxn_offset,   4,0);
	tdi_to_i4(&rsa[60], rsa_ccb_enable,   1,0);
	tdi_to_i4(&rsa[61], rsa_alct_jtag_ds, 1,0);
	tdi_to_i4(&rsa[62], rsa_alct_tmode,   2,0);
	tdi_to_i4(&rsa[64], rsa_alct_amode,   2,0);
	tdi_to_i4(&rsa[66], rsa_alct_maskall, 1,0);
	tdi_to_i4(&rsa[67], rsa_trig_info_en, 1,0);
	tdi_to_i4(&rsa[68], rsa_sn_select,    1,0);

	printf("\t 0 rsa_trig_mode    %3i\n",rsa_trig_mode);
	printf("\t 2 rsa_ext_trig_en  %3i\n",rsa_ext_trig_en);
	printf("\t 3 rsa_pretrig_halt %3i\n",rsa_pretrig_halt);
	printf("\t 4 rsa_inject       %3i\n",rsa_inject);
	printf("\t 5 rsa_inject_mode  %3i\n",rsa_inject_mode);
	printf("\t 6 rsa_inject_mask  %3i\n",rsa_inject_mask);
	printf("\t13 rsa_nph_thresh   %3i\n",rsa_nph_thresh);
	printf("\t16 rsa_nph_pattern  %3i\n",rsa_nph_pattern);
	printf("\t19 rsa_drift_delay  %3i\n",rsa_drift_delay);
	printf("\t21 rsa_fifo_tbins   %3i\n",rsa_fifo_tbins);
	printf("\t26 rsa_fifo_pretrig %3i\n",rsa_fifo_pretrig);
	printf("\t31 rsa_fifo_mode    %3i\n",rsa_fifo_mode);
	printf("\t33 rsa_fifo_lastlct %3i\n",rsa_fifo_lastlct);
	printf("\t36 rsa_l1a_delay    %3i\n",rsa_l1a_delay);
	printf("\t44 rsa_l1a_window   %3i\n",rsa_l1a_window);
	printf("\t48 rsa_l1a_offset   %3i\n",rsa_l1a_offset);
	printf("\t52 rsa_l1a_internal %3i\n",rsa_l1a_internal);
	printf("\t53 rsa_board_id     %3i\n",rsa_board_id);
	printf("\t56 rsa_bxn_offset   %3i\n",rsa_bxn_offset);
	printf("\t60 rsa_ccb_enable   %3i\n",rsa_ccb_enable);
	printf("\t61 rsa_alct_jtag_ds %3i\n",rsa_alct_jtag_ds);
	printf("\t62 rsa_alct_tmode   %3i\n",rsa_alct_tmode);
	printf("\t64 rsa_alct_amode   %3i\n",rsa_alct_amode);
	printf("\t66 rsa_alct_maskall %3i\n",rsa_alct_maskall);
	printf("\t67 rsa_trig_info_en %3i\n",rsa_trig_info_en);
	printf("\t68 rsa_sn_select    %3i\n",rsa_sn_select);
	printf("\n");

	printf("\n\tWrite new data? bit,len,val <cr=no> ");
	gets(line);
	if (line[0]==NULL) goto L2300;
	sscanf(line,"%i %i %X",&ibit,&ilen,&ival);	

	// Set new ALCT cfg bits
	bit_to_array(ival,ivalarray,ilen);

	for (i=0; i<=68; ++i) {
		rsa[i]=tdo[i+1];
		if (i>=ibit && i<=(ibit+ilen-1)) rsa[i]=ivalarray[i-ibit];
	}

	// Write ALCT Configuration register (5 bit opcode)
	chip_id = 0;
	opcode  = WrCfg;										// ALCT cfg register opcode
	reg_len = 69;											// Register length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsa,tdo,reg_len);	// Write data
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");

	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT JTAG read/write: Debug firmware
	//------------------------------------------------------------------------------
L23200:

	printf("\tMake sure you removed the JTAG cable!\n");

	//	Chain ID	Section		 Control or Program
	//	--------	------------ ------------------
	//	  0			Slow Control control registers
	//	  1			Slow Control PROM
	//	  2			Mezzanine    control registers (alct normal firmware)
	//	  3			Mezzanine    FPGA+PROM
	//
	//
	//	ALCT Debug Firmware BSCAN Register USER1 readonly:
	//	Field		Len	Typical	Description
	//	-------		---	-------	--------------------------
	//	[ 3: 0]		4	B		Begin marker
	//	[ 7: 4]		4	A		Version ID
	//	[23: 8]		16	0823	Version date
	//	[39:24]		16	2004	Version date
	//	[40]		1	1		Mez FPGA reports done
	//	[41]		1	1		Slow control FPGA reports done
	//	[42]		1	1		DLL locked
	//	[43]		1	1		Clock enable
	//	[47:44]		4	C		USER2 alignment marker
	//	[48]		1	0		Cmd_sync_mode 1=sync mode	
	//	[49]		1	-		1=80MHz synch mode
	//	[50]		1	-		First  80MHz phase data ok
	//	[51]		1	-		Second 80MHz phase data ok
	//	[63:52]		12	-		First  80MHz phase data alct_rx_1st[16:5]
	//	[75:64]		12			Second 80MHz phase data alct_rx_2nd[16:5]
	//	[76]		1	1		cmd_l1a_en, enable l1a readout on ext_trig
	//	[77]		1	1		cmd_trig_en,enable trigger word on ext_trig
	//	[78]		1	0		cmd_dummy
	//	[79:76]		4	00		Free
	//	[83:80]		4=	E		End marker
	//
	//
	//  ALCT Debug Firmware BSCAN Register USER2 write/read:
	//	Field		Len	Typical	Description
	//	-------		---	-------	--------------------------
	//	[ 3: 0]		4	C		Alignment marker
	//	[4]			1	0		1=sync_mode
	//	[5]			1	1		cmd_l1a_en, enable l1a readout on ext_trig
	//	[6]			1	1		cmd_trig_en,enable trigger word on ext_trig
	//	[7]			1	0		cmd_dummy
	//	[23:8]		16	FFFF	tx_en0, enable alct0 trigger bits
	//	[39:24]		16	FFFF	tx_en1, enable alct1 trigger bits
	//
	//------------------------------------------------------------------------------
	// Select ALCT Mezzanine FPGA programming JTAG chain from TMB boot register
	ichain = 0x0003;							// ALCT Mezzanine pgm jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Read Virtex-E FPGA (5-bit opcode) and XC18V04 PROM IDcodes (8-bit opcode)
	for (chip_id=0; chip_id<=1; ++chip_id) {
		if (chip_id==0) opcode = 0x09;				// FPGA IDcode opcode, expect v0A30093
		if (chip_id==1) opcode = 0xFE;				// PROM IDcode opcode
		reg_len=32;									// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],idcode,32,0);
		printf("\tALCT %s device %1i IDcode   = %8.8X\n",alct_chip_type[chip_id].c_str(),chip_id,idcode);
	}

	// Read FPGA/PROM USERCodes (8 bit opcode)
	for (chip_id=0; chip_id<=1; ++chip_id) {
		if (chip_id==0) opcode = 0x08;				// FPGA USERcode opcode
		if (chip_id==1) opcode = 0xFD;				// PROM USERcode opcode
		reg_len=32;									// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		tdi_to_i4(&tdo[0],idcode,32,0);
		printf("\tALCT %s device %1i USERcode = %8.8X\n",alct_chip_type[chip_id].c_str(),chip_id,idcode);
	}

	// Create fat 0 for writing to data registers
	for (i=0; i<mxbitstream; ++i) {
		tdi[i]=0;
	}

	// Select ALCT Mezzanine FPGA VirtexE JTAG chain from TMB boot register
	ichain = 0x0003;							// ALCT VirtexE
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Read ALCT VirtexE USER1 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x02;								// VirtexE USER1 opcode
	reg_len = 84;								// Register length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");
	if (ifunc<0) goto L23200;

	// Decode ALCT USER1 register
	for (i=0; i<reg_len; ++i) {
		rsd[i]=tdo[i];
	}

	tdi_to_i4(&tdo[ 0], alct_user1[0], 32,0);
	tdi_to_i4(&tdo[32], alct_user1[1], 32,0);
	tdi_to_i4(&tdo[64], alct_user1[2], 16,0);

	printf("\n\tALCT USER1 = %8.8X%8.8X%8.8X\n",alct_user1[2],alct_user1[1],alct_user1[0]);

	tdi_to_i4(&rsd[ 0], rsd_begin,          4,0);
	tdi_to_i4(&rsd[ 4], rsd_version,        4,0);
	tdi_to_i4(&rsd[ 8], rsd_monthday,      16,0);
	tdi_to_i4(&rsd[24], rsd_year,          16,0);
	tdi_to_i4(&rsd[40], rsd_mc_done,        1,0);
	tdi_to_i4(&rsd[41], rsd_sc_done,        1,0);
	tdi_to_i4(&rsd[42], rsd_clock_lock,     1,0);
	tdi_to_i4(&rsd[43], rsd_clock_en,       1,0);
	tdi_to_i4(&rsd[44], rsd_cmd_align,      4,0);
	tdi_to_i4(&rsd[48], rsd_cmd_sync_mode,  1,0);
	tdi_to_i4(&rsd[49], rsd_sync_mode,      1,0);
	tdi_to_i4(&rsd[50], rsd_sync_rx_1st_ok, 1,0);
	tdi_to_i4(&rsd[51], rsd_sync_rx_2nd_ok, 1,0);
	tdi_to_i4(&rsd[52], rsd_alct_rx_1st,   12,0);
	tdi_to_i4(&rsd[64], rsd_alct_rx_2nd,   12,0);
	tdi_to_i4(&rsd[76], rsd_cmd_l1a_en,     1,0);
	tdi_to_i4(&rsd[77], rsd_cmd_trig_en,    1,0);
	tdi_to_i4(&rsd[78], rsd_cmd_dummy,      1,0);
	tdi_to_i4(&rsd[79], rsd_free0,          1,0);
	tdi_to_i4(&rsd[80], rsd_end,            4,0);

	printf("\trsd_begin          %4.1X\n",rsd_begin);
	printf("\trsd_version        %4.1X\n",rsd_version);
	printf("\trsd_monthday       %4.4X\n",rsd_monthday);
	printf("\trsd_year           %4.4X\n",rsd_year);
	printf("\trsd_mc_done        %4.1X\n",rsd_mc_done);
	printf("\trsd_sc_done        %4.1X\n",rsd_sc_done);
	printf("\trsd_clock_lock     %4.1X\n",rsd_clock_lock);
	printf("\trsd_clock_en       %4.1X\n",rsd_clock_en);
	printf("\trsd_cmd_align      %4.1X\n",rsd_cmd_align);
	printf("\trsd_cmd_sync_mode  %4.1X\n",rsd_cmd_sync_mode);
	printf("\trsd_sync_mode      %4.1X\n",rsd_sync_mode);
	printf("\trsd_sync_rx_1st_ok %4.1X\n",rsd_sync_rx_1st_ok);
	printf("\trsd_sync_rx_2nd_ok %4.1X\n",rsd_sync_rx_2nd_ok);
	printf("\trsd_alct_rx_1st    %4.3X\n",rsd_alct_rx_1st);
	printf("\trsd_alct_rx_2nd    %4.3X\n",rsd_alct_rx_2nd);
	printf("\trsd_cmd_l1a_en     %4.3X\n",rsd_cmd_l1a_en);
	printf("\trsd_cmd_trig_en    %4.3X\n",rsd_cmd_trig_en);
	printf("\trsd_cmd_dummy      %4.3X\n",rsd_cmd_dummy);
	printf("\trsd_free0          %4.1X\n",rsd_free0);
	printf("\trsd_end            %4.1X\n",rsd_end);

	// Read ALCT VirtexE USER2 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x03;								// VirtexE USER2 opcode
	reg_len = 40;								// Register length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");

	// Decode ALCT USER2 register
	for (i=0; i<reg_len; ++i) {
		rsd[i]=tdo[i];
	}

	tdi_to_i4(&tdo[ 0],alct_user2[0],32,0);
	tdi_to_i4(&tdo[32],alct_user2[1], 8,0);

	printf("\tALCT USER2 = %8.8X%8.8X\n",alct_user2[1],alct_user2[0]);

	tdi_to_i4(&rsd[ 0], rsd_cmd_align,     4,0);
	tdi_to_i4(&rsd[ 4], rsd_cmd_sync_mode, 1,0);
	tdi_to_i4(&rsd[ 5], rsd_cmd_l1a_en,    1,0);
	tdi_to_i4(&rsd[ 6], rsd_cmd_trig_en,   1,0);
	tdi_to_i4(&rsd[ 7], rsd_cmd_dummy,     1,0);
	tdi_to_i4(&rsd[ 8], rsd_tx_en0,       16,0);
	tdi_to_i4(&rsd[24], rsd_tx_en1,       16,0);

	printf("\trsd[3:0]   rsd_cmd_align     %4.1X\n",rsd_cmd_align);
	printf("\trsd[4]     rsd_cmd_sync_mode %4.1X\n",rsd_cmd_sync_mode);
	printf("\trsd[5]     rsd_cmd_l1a_en    %4.1X\n",rsd_cmd_l1a_en);
	printf("\trsd[6]     rsd_cmd_trig_en   %4.1X\n",rsd_cmd_trig_en);
	printf("\trsd[7]     rsd_cmd_dummy     %4.1X\n",rsd_cmd_dummy);
	printf("\trsd[23:8]  rsd_tx_en0        %4.4X\n",rsd_tx_en0);
	printf("\trsd[39:24] rsd_tx_en1        %4.4X\n",rsd_tx_en1);

	// Restore USER2 because readout was destructive, alas
	for (i=0; i<reg_len; ++i) {
		tdi[i]=tdo[i];
	}

	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Write new data to USER2
	printf("\n\tWrite new data? bit,len,val <cr=no> ");
	gets(line);
	if (line[0]==NULL) goto L23299;
	sscanf(line,"%i %i %X",&ibit,&ilen,&ival);	

	// Set new ALCT USER2 bits
	bit_to_array(ival,ivalarray,ilen);

	for (i=0; i<reg_len; ++i) {
		if (i>=ibit && i<=(ibit+ilen-1)) {
			rsd[i]=ivalarray[i-ibit];
		}
	}

	// Write ALCT USER2 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x03;								// VirtexE USER2 opcode
	reg_len = 40;								// Register length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data
	dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");

L23299:
	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT Delay Scan:Time in ALCT transmit clock, ALCT Normal Firmware 
	//------------------------------------------------------------------------------
L23300:
	// Turn off CCB inputs to zero alct_adb_sync and ext_trig
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;					// Clear previous l1a
	wr_data = wr_data | 0x1;					// Turn off CCB backplane
	status  = vme_write(adr,wr_data);

	// Select ALCT cable port
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x000C;
	status  = vme_write(adr,wr_data);

	// Take TMB out of sync_mode
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// get current state
	wr_data = rd_data & 0xFF8F;					// clear bits[6:4] alct_seq_cmd[2:0]
	status  = vme_write(adr,wr_data);

	// Take ALCT debug firmware out of sync_mode
	//	ichain  = 0x0003;							// ALCT VirtexE
	//	adr     = boot_adr;							// Boot register address
	//	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI
	//	chip_id = 0;
	//	opcode  = 0x03;								// VirtexE USER2 opcode
	//	reg_len = 40;								// Register length
	//	i4_to_tdi(i4=0x6C,      &tdi[0], 8,0);		// not sync mode + marker
	//	i4_to_tdi(i4=0xFFFFFFFF,&tdi[8],32,0)		// tx enables
	//	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	//	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Get current 3D3444 delay
	adr	   = base_adr+vme_ddd0_adr;
	status = vme_read(adr,rd_data);
	alct_tx_default = rd_data & 0x000F;
	ddd0_delay      = rd_data & 0xFFF0;			 // zero out alct_tx delay

	// Clear error accumulator
	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		alct_tx_bad[ddd_delay]=0;
	}

	// Step alct clock delay
	npasses=1000;

	for (ipass     = 1; ipass     <= npasses; ++ipass    ) { // 23315
		for (ddd_delay = 0; ddd_delay <= 15;      ++ddd_delay) { // 23310

			wr_data = ddd0_delay | (ddd_delay<<0);
			adr	    = base_adr+vme_ddd0_adr;
			status  = vme_write(adr,wr_data);

			// Start DDD state machine
			adr	    = base_adr+vme_dddsm_adr;
			status  = vme_read(adr,rd_data);
			autostart = rd_data & 0x0020;	// get current autostart state
			wr_data	= 0x0000 | autostart;	// stop machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0001 | autostart;	// start machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0000 | autostart;	// unstart machine
			status	= vme_write(adr,wr_data);

			// Wait for it to finish
			for (i=1; i<=1000; ++i) {
				status   = vme_read(adr,rd_data);
				ddd_busy = (rd_data >> 6) & 0x1;
				ddd_verify_ok = (rd_data >> 7) & 0x1;
				if (ddd_busy==0) goto L23305;
			}
			printf("\n\t3d3444 verify failed %2i\n",ddd_delay);

			// Get alct raw hits busy bit
L23305:
			adr    = alct_fifo_adr+base_adr;
			status = vme_read(adr,rd_data);
			alct_raw_busy = rd_data & 0x0001;

			// Check for correct data received
			alct_tx_bad[ddd_delay] = alct_tx_bad[ddd_delay] + alct_raw_busy;

			// Close loops
		}	// close for ddd_delay 23310

		if (ipass    == 1) printf("\tAccumulating statistics...\n\n");
		if (ipass%10 == 0) printf("\t%4i\r",npasses-ipass);

	}	// close for ipass 23315

	// Display timing results
	printf(" 2nsStep Berrs   Pct  0123456789  %5i cycles\n",npasses);

	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		pctbad = 100.*float(alct_tx_bad[ddd_delay])/float(npasses);
		nbad   = int(pctbad/10.);
		if (pctbad!=0.0 && nbad==0) nbad=1;
		printf("   %2i  %7i%7.0f ",ddd_delay,alct_tx_bad[ddd_delay],pctbad);
		for (i=1;i<=nbad;++i) printf("x"); printf("\n");
	}

	// Put back default delay
	wr_data = ddd0_delay | (alct_tx_default<<0);
	adr	    = base_adr+vme_ddd0_adr;
	status  = vme_write(adr,wr_data);
	adr	    = base_adr+vme_dddsm_adr;
	status  = vme_read(adr,rd_data);
	autostart = rd_data & 0x0020;	// get current autostart state
	wr_data	= 0x0000 | autostart;	// stop machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0001 | autostart;	// start machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0000 | autostart;	// unstart machine
	status	= vme_write(adr,wr_data);

	for (i=1; i<=1000; ++i) {
		status   = vme_read(adr,rd_data);
		ddd_busy = (rd_data >> 6) & 0x1;
		ddd_verify_ok = (rd_data >> 7) & 0x1;
		if (ddd_busy==0) goto L23320;
	}

	printf("\n\tVerify failed writing back default ddd_delay=%2i\n",ddd_delay);

L23320:
	pause("\tALCT txclock delay scan complete");
	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT Delay Scan:Time in ALCT transmit clock,ALCT Debug Firmware 
	//------------------------------------------------------------------------------
L23400:
	// Turn off CCB inputs to zero alct_adb_sync and ext_trig
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;		// Clear previous l1a
	wr_data = wr_data | 0x1;		// Turn off CCB backplane
	status  = vme_write(adr,wr_data);

	// Select ALCT cable port
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | 0x000C;
	status  = vme_write(adr,wr_data);

	// Put TMB into sync_mode
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// get current state
	wr_data = rd_data & 0xFF8F;					// clear bits[6:4] alct_seq_cmd[2:0]
	wr_data = wr_data | (0x5<<4);				// alct_seq_cmd=5 for alct_sync_mode
	status  = vme_write(adr,wr_data);

	// Put ALCT debug firmware into sync_mode
	ichain = 0x0003;							// ALCT VirtexE
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	chip_id = 0;
	opcode  = 0x03;								// VirtexE USER2 opcode
	reg_len = 40;								// Register length
	i4_to_tdi(i4=0x7C,      &tdi[0], 8,0);		// sync mode + marker
	i4_to_tdi(i4=0xFFFFFFFF,&tdi[8],32,0);		// tx enables
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Get current 3D3444 delay
	adr	   = base_adr+vme_ddd0_adr;
	status = vme_read(adr,rd_data);
	alct_tx_default = rd_data & 0x000F;
	ddd0_delay      = rd_data & 0xFFF0;			 // zero out alct_tx delay

	// Clear error accumulator
	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		alct_tx_bad[ddd_delay]=0;
	}

	// Step alct tx clock delay
	printf("\tStepping alct_tx clock delay, checking 80MHz data TMB gets from ALCT\n");

	npasses=1000;

	for (ipass     = 1; ipass     <= npasses; ++ipass    ) {	// 23415
		for (ddd_delay = 0; ddd_delay <= 15;      ++ddd_delay) {	// 23410

			adr	    = base_adr+vme_ddd0_adr;
			wr_data = ddd0_delay | (ddd_delay<<0);
			status  = vme_write(adr,wr_data);

			// Start DDD state machine
			adr	    = base_adr+vme_dddsm_adr;
			status  = vme_read(adr,rd_data);
			autostart = rd_data & 0x0020;	// get current autostart state
			wr_data	= 0x0000 | autostart;	// stop machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0001 | autostart;	// start machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0000 | autostart;	// unstart machine
			status	= vme_write(adr,wr_data);

			// Wait for it to finish
			for (i=1; i<=1000; ++i) {
				status   = vme_read(adr,rd_data);
				ddd_busy = (rd_data>>6) | 0x1;
				ddd_verify_ok = (rd_data>>7) & 0x1;
				if (ddd_busy==0) goto L23405;
			}
			printf("\n\t3d3444 verify failed, ddd_delay=%2i\n",ddd_delay);

			// Read demux data
L23405:
			for (i=0; i<=3; ++i) 		// loop over 1st/2nd demux words	0=1st[14:1],1=1st[28:15]
			{
				adr     = alctfifo1_adr+base_adr;
				wr_data = 0x2000;			// select sync_mode addressing
				wr_data = wr_data | (i<<1);
				status	= vme_write(adr,wr_data);

				adr    = alctfifo2_adr+base_adr;
				status = vme_read(adr,rd_data);
				alct_demux_rd[i]=rd_data;
			}

			alct_1st_demux = alct_demux_rd[0] | (alct_demux_rd[1] << 14);
			alct_2nd_demux = alct_demux_rd[2] | (alct_demux_rd[3] << 14);
			alct_demux_err = 0;

			if (alct_1st_demux!=0xAAAAAAA) alct_demux_err=1;
			if (alct_2nd_demux!=0x5555555) alct_demux_err=1;

			if (ipass==1) printf("%2i %8.8X %8.8X\n",ddd_delay,alct_1st_demux,alct_2nd_demux);

			// Check for correct data received
			alct_tx_bad[ddd_delay] = alct_tx_bad[ddd_delay] + alct_demux_err;

			// Close loops
		}	// close for ddd_delay 23410

		if (ipass    == 1) printf("\tAccumulating statistics...\n\n");
		if (ipass%10 == 0) printf("\t%4i\r",npasses-ipass);

	}	// close for ipass 23415

	// Display timing results
	printf(" 2nsStep Berrs   Pct  0123456789  %5i cycles\n",npasses);

	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		pctbad = 100.*float(alct_tx_bad[ddd_delay])/float(npasses);
		nbad   = int(pctbad/10.);
		if (pctbad!=0.0 && nbad==0) nbad=1;
		printf("   %2i  %7i%7.0f ",ddd_delay,alct_tx_bad[ddd_delay],pctbad);
		for (i=1;i<=nbad;++i) printf("x"); printf("\n");
	}

	// Set alct tx delay
	inquire("\tSet default alct_txd_delay delay? cr=%2i", minv=0, maxv=15, radix=10, alct_tx_default);

	wr_data = ddd0_delay | (alct_tx_default<<0);
	adr	    = base_adr+vme_ddd0_adr;
	status  = vme_write(adr,wr_data);
	adr	    = base_adr+vme_dddsm_adr;
	status  = vme_read(adr,rd_data);
	autostart = rd_data & 0x0020;	// get current autostart state
	wr_data	= 0x0000 | autostart;	// stop machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0001 | autostart;	// start machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0000 | autostart;	// unstart machine
	status	= vme_write(adr,wr_data);

	for (i=1; i<=1000; ++i) {
		status   = vme_read(adr,rd_data);
		ddd_busy = (rd_data>>6) & 0x1;
		ddd_verify_ok = (rd_data>>7) & 0x1;
		if (ddd_busy==0) goto L23440;
	}
	printf("\n\tVerify failed writing back default ddd_delay=%2i\n",ddd_delay);

	// Take ALCT debug firmware out of sync_mode
L23440:
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// get current state
	wr_data = rd_data & 0xFF8F;					// clear bits[6:4] alct_seq_cmd[2:0]
	status  = vme_write(adr,wr_data);

	// Take ALCT debug firmware out of sync_mode
	ichain = 0x0003;							// ALCT VirtexE
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	chip_id = 0;
	opcode  = 0x03;								// VirtexE USER2 opcode
	reg_len = 40;								// Register length
	i4_to_tdi(i4=0x6C,      &tdi[0], 8,0);		// not sync mode + marker
	i4_to_tdi(i4=0xFFFFFFFF,&tdi[8],32,0);		// tx enables
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT Delay Scan:Time in ALCT receive clock,ALCT Debug Firmware 
	//------------------------------------------------------------------------------
L23500:
	printf("\tMake sure you removed the JTAG cable\n");

	// Turn off CCB inputs to zero alct_adb_sync and ext_trig
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;		// Clear previous l1a
	wr_data = wr_data | 0x1;		// Turn off CCB backplane
	status  = vme_write(adr,wr_data);

	// Select ALCT cable port:
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x000C;
	status  = vme_write(adr,wr_data);

	// Put TMB firmware into sync_mode
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// get current state
	wr_data = rd_data & 0xFF8F;					// clear bits[6:4] alct_seq_cmd[2:0]
	wr_data = wr_data | (0x5<<4);				// alct_seq_cmd=5 for alct_sync_mode
	status  = vme_write(adr,wr_data);

	// Put ALCT debug firmware into sync_mode
	ichain = 0x0003;							// ALCT VirtexE
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	chip_id = 0;
	opcode  = 0x03;								// VirtexE USER2 opcode
	reg_len = 40;								// Register length
	i4_to_tdi(i4=0x7C,      &tdi[0], 8,0);		// sync mode + marker
	i4_to_tdi(i4=0xFFFFFFFF,&tdi[8],32,0);		// tx enables
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Get current 3D3444 delay
	adr	   = base_adr+vme_ddd0_adr;
	status = vme_read(adr,rd_data);
	alct_rx_default =(rd_data>>4) & 0x000F;		// alct rx clock
	ddd0_delay      = rd_data     & 0xFF0F;		// zero out alct_rx delay

	// Clear error accumulator
	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		alct_rx_bad[ddd_delay]=0;
	}

	// Step alct rx clock delay
	printf("\tStepping alct_rx clock delay checking 80MHz data ALCT gets from TMB\n");
	printf("\tYou should set alct_txd_delay first\n");

	npasses=100;

	for (ipass=1;    ipass      <=npasses; ++ipass    ) { // 23515
		for (ddd_delay=0; ddd_delay <=15;      ++ddd_delay) { // 23510

			adr	    = base_adr+vme_ddd0_adr;
			wr_data = ddd0_delay | (ddd_delay<<4);
			status  = vme_write(adr,wr_data);

			// Start DDD state machine
			adr	    = base_adr+vme_dddsm_adr;
			status  = vme_read(adr,rd_data);
			autostart = rd_data & 0x0020;	// get current autostart state
			wr_data	= 0x0000 | autostart;	// stop machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0001 | autostart;	// start machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0000 | autostart;	// unstart machine
			status	= vme_write(adr,wr_data);

			// Wait for it to finish
			for (i=1; i<=1000; ++i) {
				status   = vme_read(adr,rd_data);
				ddd_busy      = (rd_data>>6) & 0x1;
				ddd_verify_ok = (rd_data>>7) & 0x1;
				if (ddd_busy==0) goto L23505;
			}
			printf("\n\t3d3444 verify failed ddd_delay=%2i\n",ddd_delay);

			// Read demux data on ALCT side
L23505:

			// Select ALCT Mezzanine FPGA VirtexE JTAG chain from TMB boot register
			ichain = 0x0003;							// ALCT VirtexE
			adr    = boot_adr;							// Boot register address
			vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

			// Read ALCT VirtexE USER1 register (5 bit opcode)
			chip_id = 0;
			opcode  = 0x02;								// VirtexE USER1 opcode
			reg_len = 84;								// Register length
			vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
			dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");

			// Decode ALCT USER1 register
			for (i=0; i<reg_len; ++i) {
				rsd[i]=tdo[i];
			}

			tdi_to_i4(&rsd[ 0], rsd_begin,           4,0);
			tdi_to_i4(&rsd[ 4], rsd_version,         4,0);
			tdi_to_i4(&rsd[ 8], rsd_monthday,       16,0);
			tdi_to_i4(&rsd[24], rsd_year,           16,0);
			tdi_to_i4(&rsd[40], rsd_mc_done,         1,0);
			tdi_to_i4(&rsd[41], rsd_sc_done,         1,0);
			tdi_to_i4(&rsd[42], rsd_clock_lock,      1,0);
			tdi_to_i4(&rsd[43], rsd_clock_en,        1,0);
			tdi_to_i4(&rsd[44], rsd_cmd_align,       4,0);
			tdi_to_i4(&rsd[48], rsd_cmd_sync_mode,   1,0);
			tdi_to_i4(&rsd[49], rsd_sync_mode,       1,0);
			tdi_to_i4(&rsd[50], rsd_sync_rx_1st_ok,  1,0);
			tdi_to_i4(&rsd[51], rsd_sync_rx_2nd_ok,  1,0);
			tdi_to_i4(&rsd[52], rsd_alct_rx_1st,    12,0);
			tdi_to_i4(&rsd[64], rsd_alct_rx_2nd,    12,0);
			tdi_to_i4(&rsd[76], rsd_free0,           4,0);
			tdi_to_i4(&rsd[80], rsd_end,             4,0);

			dprintf(stdout,"\trsd_sync_rx_1st_ok %4.1X\n",rsd_sync_rx_1st_ok);
			dprintf(stdout,"\trsd_sync_rx_2nd_ok %4.1X\n",rsd_sync_rx_2nd_ok);
			dprintf(stdout,"\trsd_alct_rx_1st    %4.3X\n",rsd_alct_rx_1st);
			dprintf(stdout,"\trsd_alct_rx_2nd    %4.3X\n",rsd_alct_rx_2nd);

			alct_demux_err=0;

			if (rsd_alct_rx_1st!=0x0AAA) alct_demux_err=1;
			if (rsd_alct_rx_2nd!=0x0555) alct_demux_err=1;

			adr	   = base_adr+alct_stat_adr;
			status = vme_read(adr,rd_data);

			rsd_alct_rx_1st = (rd_data>>1) & 0x0001;	// get seq status[0]
			rsd_alct_rx_2nd = (rd_data>>2) & 0x0001;	// get seq status[1]

			//	if (rsd_alct_rx_1st!=1) alct_demux_err=1;
			//	if (rsd_alct_rx_2nd!=1) alct_demux_err=1;

			if (ipass==1) printf(" %2i 8.8X %8.8X\n",ddd_delay,rsd_alct_rx_1st,rsd_alct_rx_2nd);

			// Check for correct data received
			alct_rx_bad[ddd_delay] = alct_rx_bad[ddd_delay] + alct_demux_err;

			// Cose loops
		}	// close for ddd_delay 23510

		if (ipass    == 1) printf("\tAccumulating statistics...\n\n");
		if (ipass%10 == 0) printf("\t%4i\r",npasses-ipass);

	}	// close for ipass 23515

	// Display timing results
	printf(" 2nsStep Berrs   Pct  0123456789  %5i cycles\n",npasses);

	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		pctbad = 100.*float(alct_tx_bad[ddd_delay])/float(npasses);
		nbad   = int(pctbad/10.);
		if (pctbad!=0.0 && nbad==0) nbad=1;
		printf("   %2i  %7i%7.0f ",ddd_delay,alct_tx_bad[ddd_delay],pctbad);
		for (i=1;i<=nbad;++i) printf("x"); printf("\n");
	}

	// Set alct tx delay
	inquire("\tSet default alct_rxd_delay delay? cr=%2i", minv=0, maxv=15, radix=10, alct_rx_default);

	wr_data = ddd0_delay | (alct_rx_default<<4);
	adr	    = base_adr+vme_ddd0_adr;
	status  = vme_write(adr,wr_data);
	adr   	= base_adr+vme_dddsm_adr;
	status  = vme_read(adr,rd_data);
	autostart = rd_data & 0x0020;	// get current autostart state
	wr_data	= 0x0000 | autostart;	// stop machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0001 | autostart;	// start machine
	status	= vme_write(adr,wr_data);
	wr_data = 0x0000 | autostart;	// unstart machine
	status	= vme_write(adr,wr_data);

	for (i=1; i<=1000; ++i ) {
		status  = vme_read(adr,rd_data);
		ddd_busy      = (rd_data>>6) & 0x1;
		ddd_verify_ok = (rd_data>>7) & 0x1;
		if (ddd_busy==0) goto L23540;
	}
	printf("\n\tVerify failed writing back default ddd_delay=%2i\n",ddd_delay);

	// Take TMB firmware out of sync_mode
L23540:
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// get current state
	wr_data = rd_data & 0xFF8F;					// clear bits[6:4] alct_seq_cmd[2:0]
	status  = vme_write(adr,wr_data);

	// Take ALCT debug firmware out of sync_mode
	ichain = 0x0003;							// ALCT VirtexE
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	chip_id = 0;
	opcode  = 0x03;								// VirtexE USER2 opcode
	reg_len = 40;								// Register length
	i4_to_tdi(i4=0x6C,      &tdi[0], 8,0);		// not sync mode + marker
	i4_to_tdi(i4=0xFFFFFFFF,&tdi[8],32,0);		// tx enables
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT Software ext_trig ALCT, check for CRC errors, ALCT Debug Firmware 
	//------------------------------------------------------------------------------
L23600:
	printf("\tMake sure you set alct_txd_delay and alct_rxd_delay");

	// Turn off CCB inputs to zero alct_adb_sync and ext_trig
	//	adr     = ccb_cfg_adr+base_adr;
	//	status  = vme_read(adr,rd_data);
	//	wr_data = rd_data & 0xFFBF;		// Clear previous l1a
	//	wr_data = wr_data | 0x1;		// Turn off CCB backplane
	//	status  = vme_write(adr,wr_data);

	// Turn off CCB inputs to zero alct_adb_sync and ext_trig, enable l1a emulator
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBA;		// Clear previous l1a
	wr_data = wr_data | 0x0001;		// Turn off CCB backplane
	wr_data = wr_data | 0x0004;		// Enable L1A emulator
	status  = vme_write(adr,wr_data);

	// Disable GTL ccb_clct_ext_trig
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0;
	wr_data = wr_data | 0x0001;		// request ccb l1a on alct_ext_trig
	//	if (itrig_src==0) wr_data = wr_data | 0x0040;	// ccb_allow_ext_bypass to input GTL pulser
	wr_data = wr_data | (132<<8);	// set emulator delay for alct ext_trig timing
	status  = vme_write(adr,wr_data);

	// Select ALCT cable port
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x000C;
	status  = vme_write(adr,wr_data);

	// Take TMB firmware out of sync_mode
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// get current state
	wr_data = rd_data & 0xFF8F;					// clear bits[6:4] alct_seq_cmd[2:0]
	status  = vme_write(adr,wr_data);

	// Take ALCT debug firmware out of sync_mode
	//	ichain = 0x0003;							// ALCT VirtexE
	//	adr    = boot_adr;							// Boot register address
	//	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	//	chip_id = 0;
	//	opcode  = 0x03;								// VirtexE USER2 opcode
	//	reg_len = 8;								// Register length
	//	i4_to_tdi(i4=6C,tdi,reg_len,0);				// sync mode + marker
	//	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	//	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Set start_trigger state for FMM
	ttc_cmd = 6;
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status = vme_write(adr,wr_data);

	// Clear error counters
	ievent              = 0;
	err_alct_fifo_clr	= 0;	// ALCT fifo failed to clear
	err_alct_lct0		= 0;	// ALCT LCT0 unchanged
	err_alct_lct1		= 0;	// ALCT LCT1 unchanged
	err_alct_fifo_busy	= 0;	// ALCT fifo stuck busy
	err_alct_fifo_ndone	= 0;	// ALCT fifo not done
	err_alct_raw_nwords	= 0;	// ALCT wrong word count
	err_firmware_crc	= 0;	// TMB firmware CRC
	err_alct_crc		= 0;	// ALCT crc error, WTF// 

	// Clear TMB firmware counters
	adr     = base_adr+cnt_ctrl_adr;
	wr_data = 0x0021;						// clear + enable alct err
	status  = vme_write(adr,wr_data);
	wr_data = 0x0020;						// unclear +  + enable alct err
	status  = vme_write(adr,wr_data);

	// Event loop
L23610:
	ievent++;
	if (ievent%100==0 || ievent==1) printf("\tEvent %9i\n",ievent);

	// Clear last event
	adr     = alctfifo1_adr+base_adr;
	wr_data = 1;							// reset word counter
	status  = vme_write(adr,wr_data);
	wr_data = 0	;							// enable word counter
	status  = vme_write(adr,wr_data);

	// Make sure alct fifo went unbusy
	adr    = alct_fifo_adr+base_adr;
	status = vme_read(adr,rd_data);
	alct_raw_busy = (rd_data>>0) & 0x0001;
	alct_raw_done = (rd_data>>1) & 0x0001;
	if (alct_raw_busy==1) err_alct_fifo_clr++;	// ALCT FIFO failed to clear

	// Fire ext_trig to ALCT board
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);		// get current state
	wr_data = rd_data & 0xFFF0;				// clear bits[3:0] alct ext trig
	wr_data = wr_data | 0x0004;				// fire alct ext trig
	//	wr_data = wr_data | 0x0008;				// or fire alct ext inject
	status  = vme_write(adr,wr_data);
	wr_data = rd_data & 0xFFF0;				// clear bits[3:0] alct ext trig
	status  = vme_write(adr,wr_data);

	// Read ALCT trigger words
	adr      = alct_alct0_adr+base_adr;
	status   = vme_read(adr,rd_data);		// get current state
	alct0_rd = rd_data;

	adr      = alct_alct1_adr+base_adr;
	status   = vme_read(adr,rd_data);		// get current state
	alct1_rd = rd_data;

	if (alct0_rd==alct0_prev) err_alct_lct0++;	// ALCT LCT0 unchanged
	if (alct1_rd==alct1_prev) err_alct_lct1++;	// ALCT LCT1 unchanged

	alct0_prev = alct0_rd;
	alct1_prev = alct1_rd;

	// Fire CCB L1A oneshot to ALCT
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;			// Clear previous l1a
	wr_data = wr_data | 0x1;			// Turn off CCB backplane
	wr_data = wr_data | 0x0040;			// Fire ccb L1A oneshot
	status  = vme_write(adr,wr_data);
	wr_data = wr_data & 0xFFBF;			// Clear previous l1a	
	status  = vme_write(adr,wr_data);

	// Check alct fifo status
	for (i=1; i<=100; ++i) {			// cheap readout delay 
		adr    = alct_fifo_adr+base_adr;
		status = vme_read(adr,rd_data);
		alct_raw_busy = (rd_data>>0) & 0x0001;
		alct_raw_done = (rd_data>>1) & 0x0001;
		if (alct_raw_busy==0) goto L23620;
	}
	err_alct_fifo_busy++;				// alct fifo stuck busy

L23620:
	dprintf(stdout,"\tALCT L1A alct_raw_done waits=%5i\n",i);
	if (alct_raw_done!=1) err_alct_fifo_ndone++;	 // alct fifo not done

	// Check TMBs firmware CRC result
	adr     = base_adr+cnt_ctrl_adr;
	wr_data = 0x0022;					// snap
	status  = vme_write(adr,wr_data);
	wr_data = 0x0020;					// unsnap
	status  = vme_write(adr,wr_data);
	wr_data = (0<<8) | 0x0020;			// crc is counter adr 0
	status  = vme_write(adr,wr_data);
	adr     = base_adr+cnt_rdata_adr;
	status  = vme_read(adr,rd_data);	// counter LSB is sufficient
	if (rd_data!=0) err_firmware_crc++;

	// Check TMBs firmware ALCT LCT error counter
	adr     = base_adr+cnt_ctrl_adr;
	wr_data = 0x0022;					// snap
	status  = vme_write(adr,wr_data);
	wr_data = 0x0020;					// unsnap
	status  = vme_write(adr,wr_data);
	wr_data = (4<<8) | 0x0020;			// alct lct is counter adr 4
	status  = vme_write(adr,wr_data);
	adr     = base_adr+cnt_rdata_adr;
	status  = vme_read(adr,rd_data);	// counter LSB is sufficient
	if (rd_data!=0) printf("\talct_lct_err=%10i\n",rd_data);

	// Get alct word count
	adr    = alct_fifo_adr+base_adr;	// alct word count
	status = vme_read(adr,rd_data);
	alct_raw_nwords = (rd_data>>2) & 0x07FF;

	if (alct_raw_nwords!=0x018C) {
		err_alct_raw_nwords++;
		goto L23630;						// skip readout analysis if word count wrong
	}

	// Read alct fifo data
	for (i=0; i<=max(alct_raw_nwords-1,0); ++i) {
		adr     = alctfifo1_adr+base_adr;
		wr_data = (i<<1);					// ram read address
		status  = vme_write(adr,wr_data);

		adr=alctfifo2_adr+base_adr;			// alct raw data lsbs
		status = vme_read(adr,rd_data);
		dprintf(log_file,"adr=%4i alct raw lsbs=%4.4X\n",rd_data);
		alct_raw_data = rd_data;

		adr     = alct_fifo_adr+base_adr;	// alct raw data msbs
		status  = vme_read(adr,rd_data);
		dprintf(log_file,"adr=%4i alct raw msbs=%4.4X\n",rd_data);
		rd_data = (rd_data>>13) & 0x0003;
		alct_raw_data = alct_raw_data | (rd_data<<16);
		if (i<mxframe)vf_data[i]=alct_raw_data;
	}

	// Calculate CRC for data stream
	dmb_wdcnt=alct_raw_nwords;

	for (iframe=0; iframe<=dmb_wdcnt-1-4; ++iframe) {	// dont include last 4 frames
		din = vf_data[iframe];
		if (iframe==0) crc22a(din,crc,1);					// reset crc
		crc22a(din,crc,0);
	}

	// Compare our computed CRC to what TMB computed
	tmb_crc_lsb = vf_data[dmb_wdcnt-1-3] & 0x07FF;		// 11 crc bits per frame
	tmb_crc_msb = vf_data[dmb_wdcnt-1-2] & 0x07FF;		// 11 crc bits per frame
	tmb_crc     = tmb_crc_lsb | (tmb_crc_msb<<11);		// full 22 bit crc
	crc_match   = crc==tmb_crc;
	if (!crc_match) err_alct_crc++; // ALCT crc error, WTF!

	// Compare data stream ALCTs to trigger path ALCTs
	alct0_raw_lsb = vf_data[5] & 0x00FF;	// alct0[7:0]
	alct0_raw_msb = vf_data[6] & 0x00FF;	// alct0[15:8]
	alct0_raw     = alct0_raw_lsb | (alct0_raw_msb<<8);

	alct1_raw_lsb = vf_data[7] & 0x00FF;	// alct1[7:0]
	alct1_raw_msb = vf_data[8] & 0x00FF;	// alct1[15:8]
	alct1_raw     = alct1_raw_lsb | (alct1_raw_msb<<8);

	if (alct0_rd!=alct0_raw) err_lct++;
	if (alct1_rd!=alct1_raw) err_lct++;

	// Decompose trigger path ALCTs
	alct0_vpf	= (alct0_rd >> 0) & 0x0001;	//  Valid pattern flag
	alct0_qual	= (alct0_rd >> 1) & 0x0003;	//  Pattern quality
	alct0_amu	= (alct0_rd >> 3) & 0x0001;	//  Accelerator muon
	alct0_key	= (alct0_rd >> 4) & 0x007F;	//  Wire group ID number
	alct0_bxn	= (alct0_rd >>11) & 0x0003;	//  Bunch crossing number

	alct1_vpf	= (alct1_rd >> 0) & 0x0001;	//  Valid pattern flag
	alct1_qual	= (alct1_rd >> 1) & 0x0003;	//  Pattern quality
	alct1_amu	= (alct1_rd >> 3) & 0x0001;	//  Accelerator muon
	alct1_key	= (alct1_rd >> 4) & 0x007F;	//  Wire group ID number
	alct1_bxn	= (alct1_rd >>11) & 0x0003;	//  Bunch crossing number

	alct0_keya  = alct0_key & 0x000F;
	alct1_keya  = alct1_key & 0x000F;

	alct0_keyb  = alct0_key & 0x0070;
	alct1_keyb  = alct1_key & 0x0070;

	alct1_amu	= ~alct1_amu  & 0x0001;
	alct1_qual	= ~alct1_qual & 0x0003;
	alct1_keyb	= ~alct1_keyb & 0x0070;

	// Compare trigger path ALCTs to each other, alct debug firmware inverts some alct1 bits
	err_lct_cmp = 0;

	if (alct0_vpf  != alct1_vpf ) err_lct_cmp++;	
	if (alct0_qual != alct1_qual) err_lct_cmp++;
	if (alct0_amu  != alct1_amu ) err_lct_cmp++;
	if (alct0_keya != alct1_keya) err_lct_cmp++;
	if (alct0_keyb != alct1_keyb) err_lct_cmp++;
	if (alct0_bxn  != alct1_bxn ) err_lct_cmp++;

	// Next event
L23630:
	err_sum=
		err_alct_fifo_clr
		+ err_alct_lct0
		+ err_alct_lct1
		+ err_alct_fifo_busy
		+ err_alct_fifo_ndone
		+ err_alct_raw_nwords
		+ err_firmware_crc
		+ err_alct_crc
		+ err_lct
		+ err_lct_cmp;

	if (err_sum!=0) {
		printf("\terr_alct_fifo_clr   %9i\n",err_alct_fifo_clr);
		printf("\terr_alct_lct0       %9i\n",err_alct_lct0);
		printf("\terr_alct_lct1       %9i\n",err_alct_lct1);
		printf("\terr_alct_fifo_busy  %9i\n",err_alct_fifo_busy);
		printf("\terr_alct_fifo_ndone %9i\n",err_alct_fifo_ndone);
		printf("\terr_alct_raw_nwords %9i\n",err_alct_raw_nwords);
		printf("\terr_firmware_crc    %9i\n",err_firmware_crc);
		printf("\terr_alct_crc        %9i\n",err_alct_crc);
		printf("\terr_lct             %9i\n",err_lct);
		printf("\terr_lct_cmp         %9i\n",err_lct_cmp);
		pause("<cr> to continue");
	}

	goto L23610;	// endless loop, stops on error

	//------------------------------------------------------------------------------
	//	ALCT Hardware ext_trig ALCT, check for CRC errors',ALCT Debug Firmware 
	//------------------------------------------------------------------------------
L23700:
	printf("\tMake sure you set alct_txd_delay and alct_rxd_delay");

	inquire("\tUse alct_ext_trig from GTLPulser[0] or Firmware[1] cr=%2i", minv=-1, maxv= 1, radix=10, itrig_src );
	inquire("\tALCT PipelineDelay wrtCLCT?                        cr=%2i", minv=-1, maxv=15, radix=10, alct_delay);

	// Turn off CCB inputs to zero alct_adb_sync and ext_trig, enable l1a emulator
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	//  wr_data = rd_data & 0xFFB6;		// Clear previous l1a
	wr_data = rd_data & 0xFFBA;		// Clear previous l1a
	wr_data = wr_data | 0x0001;		// Turn off CCB backplane
	wr_data = wr_data | 0x0004;		// Enable L1A emulator
	status  = vme_write(adr,wr_data);

	// Enable GTL ccb_clct_ext_trig
	adr = ccb_trig_adr+base_adr;
	wr_data = 0;
	wr_data = wr_data | 0x0001;		// request ccb l1a on alct_ext_trig
	if (itrig_src==0) wr_data = wr_data | 0x0040;	// ccb_allow_ext_bypass to input GTL pulser
	wr_data = wr_data | (132<<8);	// set emulator delay for alct ext_trig timing
	status = vme_write(adr,wr_data);

	// Select ALCT cable port:
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x000C;
	status  = vme_write(adr,wr_data);

	// Take TMB firmware out of sync_mode, enable alct ext_trig from ccb
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);		// get current state
	wr_data = rd_data & 0xFF8F;				// clear bits[6:4] alct_seq_cmd[2:0]
	wr_data = wr_data | 0x0001;				// set bit[0] to enable alct_ext_trig from ccb
	status  = vme_write(adr,wr_data);

	// Take ALCT debug firmware out of sync_mode
	//	ichain = 0x0003;						// ALCT VirtexE
	//	adr    = boot_adr;						// Boot register address
	//	vme_jtag_anystate_to_rti(adr,ichain);	// Take TAP to RTI

	//	chip_id = 0;
	//	opcode  = 0x03;							// VirtexE USER2 opcode
	//	reg_len = 8;							// Register length
	//	i4_to_tdi('6C'x,tdi,reg_len,0)			// sync mode + marker
	//	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	//	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;				// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;				// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Select sequencer to take clct ext or alct ext trig
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0060;				// Select alct or clct ext trig mode
	status  = vme_write(adr,wr_data);

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | alct_delay;
	status  = vme_write(adr,wr_data);

	// Adjust trigger timing and L1A timing to account for cable and alct delays
	adr     = seq_trig_dly1_adr+base_adr;	// 6C ALCT ext trig delay, delays cfeb wrt alct, cuz we are using alct gtl trigger input
	wr_data = 0x0B71;
	status  = vme_write(adr,wr_data);

	adr     = seq_l1a_adr+base_adr;			// 74 L1A delay
	wr_data = 0x037E;
	status  = vme_write(adr,wr_data);

	adr = tmbtim_adr+base_adr;				// B2 delay alct_vpf wrt clct_vpf
	wr_data = 0x0030;
	status = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Fire CCB external clct trigger with pulse generator
	if (itrig_src==0)
		printf("\tConnect GTL pulse +1.5V/0V to TMB P2A E10 (RAT E16),monitor TP382-7\n");

	// Clear TMB firmware counters, enable alct debug lct error counter
	adr     = base_adr+cnt_ctrl_adr;
	wr_data = 0x0021;					// clear + enable alct err
	status  = vme_write(adr,wr_data);
	wr_data = 0x0020;					// unclear + enable alct err
	status  = vme_write(adr,wr_data);

	// Event loop: Arm scope trigger, taking sample of 1 event, pulser free runs at MHz speeds
L23710:
	rdscope        = true;
	scp_arm        = true;
	scp_readout    = false;
	scp_raw_decode = false;
	scp_silent     = false;
	scp_playback   = false;

	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	msec=1000;
	sleep(msec);						// duration in i*4 milliseconds

	// Fake-fire ext_trig to test software without using pulser, eh
	if (itrig_src==1)
	{
		adr     = ccb_trig_adr+base_adr;
		status  = vme_read(adr,rd_data);	// get current state
		wr_data = rd_data & 0xFFF7;			// clear bit[3] alct_ext_trig_vme
		status  = vme_write(adr,wr_data);
		wr_data = rd_data | 0x008;			// set bit[3] alct_ext_trig_vme
		status  = vme_write(adr,wr_data);
		wr_data = rd_data & 0xFFF7;			// clear bit[3] alct_ext_trig_vme
		status  = vme_read(adr,rd_data);	// get current state
	}

	// Read back embedded scope data
	scp_arm        = false;
	scp_readout    = true;
	scp_raw_decode = false;
	scp_silent     = true;
	scp_playback   = false;

	if (rdscope)
		scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

	// Take snapshot of current counter state
	adr = base_adr+cnt_ctrl_adr;
	wr_data=0x0022;	//snap
	status = vme_write(adr,wr_data);
	wr_data=0x0020;	//unsnap
	status = vme_write(adr,wr_data);

	// Read counters
	for (i=0; i<mxcounter; ++i) {
		for (j=0; j<=1; ++j) {
			adr = base_adr+cnt_ctrl_adr;
			wr_data=(i << 9) | 0x0020 | (j << 8);
			status = vme_write(adr,wr_data);
			adr = base_adr+cnt_rdata_adr;
			status = vme_read(adr,rd_data);

			// Combine lsbs+msbs
			if (j==0)			// Even addresses contain counter LSBs
				cnt_lsb=rd_data;
			else {				// Odd addresses contain counter MSBs
				cnt_msb=rd_data;
				cnt_full=cnt_lsb | (cnt_msb << 16);
				cnt[i]=cnt_full;	// Assembled counter MSB,LSB
			}
		}}	//close j,i

	// Read buffer status
	adr    = buf_stat0_adr+base_adr;
	status = vme_read(adr,rd_data);

	wr_buf_ready	= (rd_data >>  0) & 0x1;		// Write buffer is ready
	buf_stalled		= (rd_data >>  1) & 0x1;		// Buffer write pointer hit a fence and stalled
	buf_q_full		= (rd_data >>  2) & 0x1;		// All raw hits ram in use, ram writing must stop
	buf_q_empty		= (rd_data >>  3) & 0x1;		// No fences remain on buffer stack
	buf_q_ovf_err	= (rd_data >>  4) & 0x1;		// Tried to push when stack full
	buf_q_udf_err	= (rd_data >>  5) & 0x1;		// Tried to pop when stack empty
	buf_q_adr_err	= (rd_data >>  6) & 0x1;		// Fence adr popped from stack doesnt match rls adr
	buf_display		= (rd_data >>  8) & 0xFF;		// Buffer fraction in use display

	adr    = buf_stat1_adr+base_adr;
	status = vme_read(adr,rd_data);
	wr_buf_adr = (rd_data >> 0) & 0x7FF;			// Current ddress of header write buffer

	adr    = buf_stat2_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_dist = (rd_data >> 0) & 0x7FF;		// Distance to 1st fence address
	buf_free_space  = int(100.*float(buf_fence_dist)/2047.);

	adr    = buf_stat3_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_cnt = (rd_data >> 0) & 0x7FF;			// Number of fences in fence RAM currently

	adr    = buf_stat4_adr+base_adr;
	status = vme_read(adr,rd_data);
	buf_fence_cnt_peak=(rd_data >> 0) & 0xFFF;		// Peak number of fences in fence RAM

	// Get current FMM state
	adr    = base_adr+ccb_cmd_adr;
	status = vme_read(adr,rd_data);
	fmm_state = (rd_data >> 4) & 0x0007;

	// Get current Sequencer state and L1A queue status
	adr     = base_adr+seqsm_adr;
	status  = vme_read(adr,rd_data);
	clct_sm = (rd_data >> 0) & 0x7;
	read_sm = (rd_data >> 3) & 0x1F;

	queue_full = (rd_data >>  8) & 0x1;
	queue_empty= (rd_data >>  9) & 0x1;
	queue_ovf  = (rd_data >> 10) & 0x1;
	queue_udf  = (rd_data >> 11) & 0x1;

	// Errors since last update
	crc_err =cnt[11]-crc_err_old;						// cnt[11]=alct crc daq errors
	crc_err =int(float(crc_err)/(float(msec)/1000.));	// errors per second
	crc_err_old = cnt[11];

	// Dislay counters
	printf("\n");
	printf("\t%2.2i %10i %s\n",0,crc_err,"ALCT: CRC errors/second");

	printf("\n\tCounters:\n");
	for (i=0; i<mxcounter; ++i) {
		printf("\t%2.2i %10i %s\n",i,cnt[i],scnt[i].c_str());
	}

	printf("\n\tRaw hits buffer:\n");
	printf("\twr_buf_ready   %4i\n",wr_buf_ready);
	printf("\tbuf_stalled    %4i\n",buf_stalled);
	printf("\tbuf_q_full     %4i\n",buf_q_full);
	printf("\tbuf_q_empty    %4i\n",buf_q_empty);
	printf("\tbuf_q_ovf_err  %4i\n",buf_q_ovf_err);
	printf("\tbuf_q_udf_err  %4i\n",buf_q_udf_err);
	printf("\tbuf_q_adr_err  %4i\n",buf_q_adr_err);
	printf("\tbuf_display    %4i\n",buf_display);
	printf("\twr_buf_adr     %4i\n",wr_buf_adr);
	printf("\tbuf_fence_dist %4i\n",buf_fence_dist);
	printf("\tbuf_fence_cnt  %4i\n",buf_fence_cnt);
	printf("\tbuf_fence_peak %4i\n",buf_fence_cnt_peak);
	printf("\tbuf_free_space %4i\n",buf_free_space);

	printf("\n\tTrigger status:\n");
	printf("\tFMM state      %4i %s\n",fmm_state,sfmm_state[fmm_state%5].c_str());
	printf("\tclct_sm  state %4i %s\n",clct_sm,sclct_sm[clct_sm%6].c_str());
	printf("\tread_sm  state %4i %s\n",read_sm,sread_sm[read_sm%21].c_str());

	printf("\n\tReadout queue:\n");
	printf("\tqueue_full     %4i\n",queue_full);
	printf("\tqueue_empty    %4i\n",queue_empty);
	printf("\tqueue_ovf      %4i\n",queue_ovf);
	printf("\tqueue_udf      %4i\n",queue_udf);

	goto L23710;

	//------------------------------------------------------------------------------
	//	ALCT JTAG read/write: Debug firmware
	//------------------------------------------------------------------------------
L23800:
	printf("\tMake sure you removed the JTAG cable!\n");
	printf("\tinfinite loop anystate to rti on chain 3\n");

L23810:
	ichain = 0x0002;							// ALCT User
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI
	sleep(1);

	// Read Virtex-E FPGA (5-bit opcode) and XC18V04 PROM IDcodes (8-bit opcode)
	chip_id = 0;
	opcode  = 0x09;								// FPGA IDcode opcode, expect v0A30093
	reg_len = 32;								// IDcode length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	sleep(1);

	if (ifunc>0) goto L23810;
	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT: Check CRC errors caused by ALCT trigger bits
	//------------------------------------------------------------------------------
L23900:
	// Turn off CCB inputs to zero alct_adb_sync and ext_trig, enable l1a emulator
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFB6;			// Clear previous l1a
	wr_data = wr_data | 0x0001;			// Turn off CCB backplane
	wr_data = wr_data | 0x0004;			// Enable L1A emulator
	status  = vme_write(adr,wr_data);

	// Enable GTL ccb_clct_ext_trig
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0;
	wr_data = wr_data | 0x0001;			// request ccb l1a on alct_ext_trig
	wr_data = wr_data | 0x0040;			// ccb_allow_ext_bypass to input GTL pulser
	wr_data = wr_data | (132<<8);		// set emulator delay for alct ext_trig timing
	status  = vme_write(adr,wr_data);

	// Select ALCT cable port:
	adr     = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x000C;
	status  = vme_write(adr,wr_data);

	// Take TMB firmware out of sync_mode, enable alct ext_trig from ccb
	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);	// get current state
	wr_data = rd_data & 0xFF8F;			// clear bits[6:4] alct_seq_cmd[2:0]
	wr_data = wr_data | 0x0001;			// set bit[0] to enable alct_ext_trig from ccb
	status  = vme_write(adr,wr_data);

	// Turn off CFEB cable inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;			// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;			// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Select sequencer to take clct ext or alct ext trig
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	wr_data = wr_data | 0x0060;			// Select alct or clct ext trig mode
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;
	wr_data = 0x0003 | (ttc_cmd<<8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Fire CCB external clct trigger with pulse generator
	printf("\tConnect GTL pulse +1.5V/0V to TMB P2A E10 (RAT E16),monitor TP382-7\n");

	// Clear TMB firmware counters, enable alct debug lct error counter
	adr     = base_adr+cnt_ctrl_adr;
	wr_data = 0x0021;					// clear + enable alct err
	status  = vme_write(adr,wr_data);
	wr_data = 0x0020;					// unclear + enable alct err
	status  = vme_write(adr,wr_data);

	// Event loop:
	crc_err_old=0;

	for (ibit=0; ibit<=31; ++ibit) {

		// Set new ALCT USER2 bits to enable specified alct trigger path bits
		rsd[0]=1;	// rsd[3:0)='D'x
		rsd[1]=0;
		rsd[2]=1;
		rsd[3]=1;
		rsd[4]=0;	// sync mode
		rsd[5]=1;	// enable l1a
		rsd[6]=1;	// enable extrig
		rsd[7]=0;	// dummy

		for (i=8; i<=39; ++i)
		{
			rsd[i]=0x1;
			if (i==(ibit+8)) rsd[i]=0;
		}

		// Write ALCT USER2 register (5 bit opcode)
		ichain = 0x0003;							// ALCT VirtexE
		adr    = boot_adr;							// Boot register address
		vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

		chip_id = 0;
		opcode  = 0x03;								// VirtexE USER2 opcode
		reg_len = 40;								// Register length
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data
		dprintf(stdout,"tdo="); for (i=0; i<reg_len; ++i) dprintf(stdout,"%1i",tdo[i]); dprintf(stdout,"\n");
		//	pause("<cr> to continue");

		// Accumulate hardware triggers
		sleep(1000);								// duration in i*4 milliseconds

		// Take snapshot of current counter state
		adr = base_adr+cnt_ctrl_adr;
		wr_data=0x0022;	//snap
		status = vme_write(adr,wr_data);
		wr_data=0x0020;	//unsnap
		status = vme_write(adr,wr_data);

		// Read counters
		for (i=0; i<mxcounter; ++i) {
			for (j=0; j<=1; ++j) {
				adr = base_adr+cnt_ctrl_adr;
				wr_data=(i << 9) | 0x0020 | (j << 8);
				status = vme_write(adr,wr_data);
				adr = base_adr+cnt_rdata_adr;
				status = vme_read(adr,rd_data);

				// Combine lsbs+msbs
				if (j==0)			// Even addresses contain counter LSBs
					cnt_lsb=rd_data;
				else {				// Odd addresses contain counter MSBs
					cnt_msb=rd_data;
					cnt_full=cnt_lsb | (cnt_msb << 16);
					cnt[i]=cnt_full;	// Assembled counter MSB,LSB
				}
			}}	//close j,i

		// Display daq crc errors
		crc_err=cnt[11]-crc_err_old;	// cnt[0]=alct crc daq errors
		crc_err_old=cnt[11];

		printf("\tibit=%2i ALCT daq CRC errors/sec=%10i\n",crc_err);

		// Close liio
	} // close for ibit

	goto L2300;

	//------------------------------------------------------------------------------
	//	ALCT rxd clock delay scan: ALCT-to-TMB Teven|Todd
	//------------------------------------------------------------------------------
L231000:
	//	unit  = stdout;
	unit  = log_file;
	debug = false;

	fprintf(unit,"ALCT rxd clock delay scan: ALCT-to-TMB Teven|Todd\n");

	// Get current 3D3444 + phaser delays
	alct_tof_default = ddd_rd(base_adr, ddd_chip=0, ddd_channel=0);	// alct_tof_delay is chip0 ch0
	alct_txd_default = phaser_rd(base_adr,"alct_txd",dps_delta);
	alct_rxd_default = phaser_rd(base_adr,"alct_rxd",dps_delta);

	// Get current posnegs
	alct_rxd_posneg_default = posneg_rd(base_adr,"alct_rxd");
	alct_txd_posneg_default = posneg_rd(base_adr,"alct_txd");

	// Inquire
	alct_rxd_posneg = alct_rxd_posneg_default;
	alct_txd_posneg = alct_txd_posneg_default;
	alct_rxd_delay	= alct_rxd_default;
	alct_txd_delay	= alct_txd_default;
	alct_tof_delay  = alct_tof_default;

	inquire("Set alct_rxd_posneg? -1=scan, cr=%2i", minv=-1, maxv= 1, radix=10, alct_rxd_posneg);
	inquire("Set alct_tof_delay ? -1=scan, cr=%2i", minv=-1, maxv=12, radix=10, alct_tof_delay );

	// Turn off CCB inputs to zero alct_adb_sync and ext_trig
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;					// Clear previous l1a
	wr_data = wr_data | 0x1;					// Turn off CCB backplane
	status  = vme_write(adr,wr_data);

	// Put ALCT into xmit Teven|Todd pattern, seq_cmd[0],[2] share same wire pair
	seq_cmd_bit[0]=1;	seq_cmd_bit[2]=1;		// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
	seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;		// (seq_cmd[0] & seq_cmd[2] == 1} tells ALCT to send Teven|Todd pattern

	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// Get current state
	wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
	wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
	wr_data = wr_data | (seq_cmd_bit[1] << 5);
	wr_data = wr_data | (seq_cmd_bit[2] << 6);
	wr_data = wr_data | (seq_cmd_bit[3] << 7);
	status  = vme_write(adr,wr_data);

	// Scan tof and rxd_posneg, or use input values
	alct_tof_delay_min	= (alct_tof_delay  < 0) ?  0 : alct_tof_delay;
	alct_tof_delay_max	= (alct_tof_delay  < 0) ? 12 : alct_tof_delay;
	alct_rxd_posneg_min	= (alct_rxd_posneg < 0) ?  0 : alct_rxd_posneg;
	alct_rxd_posneg_max	= (alct_rxd_posneg < 0) ?  1 : alct_rxd_posneg;

	for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
		for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {

			// Set scanned delays and posnegs
			ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0

			posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
			posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

			// Clear error accumulators
			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
				for (ibit=0; ibit<=27; ++ibit) {
					alct_rxd_bad[alct_rxd_delay][ibit]=0;
				}}

			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
				alct_sync_1st_err_ff[alct_rxd_delay] = 0;
				alct_sync_2nd_err_ff[alct_rxd_delay] = 0;
			}

			// Step alct rxd clock delay
			fprintf(unit,"\n");	
			fprintf(unit,"Checking 80MHz Teven|Todd data TMB receives from ALCT\n");
			fprintf(unit,"Setting  alct_tof_delay  =%2i\n",alct_tof_delay);
			fprintf(unit,"Setting  alct_rxd_posneg =%2i\n",alct_rxd_posneg);
			fprintf(unit,"Using    dps_max         =%2i\n",dps_max);
			fprintf(unit,"Using    dps_delta       =%2i\n",dps_delta);
			fprintf(unit,"\n");	
			fprintf(unit,"Stepping alct_rxd_delay...\n\n");
			if (unit!=stdout) fprintf(stdout,"Scanning alct_tof_delay=%2i alct_rxd_posneg=%1i...wait",alct_tof_delay,alct_rxd_posneg);

			npasses = 1000;
			for (ipass=1; ipass<=npasses; ++ipass) {							// L231015
				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {	// L231010

					// Set alct_rxd_delay
					phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);

					// Clear TMB data check flipflops for this delay value, set transmitted data delay depth
					alct_sync_rxdata_dly = 0;
					alct_sync_tx_random  = 0;
					alct_sync_clr_err    = 1;

					adr     = alct_sync_ctrl_adr+base_adr;		// get current
					status	= vme_read(adr,rd_data);
					alct_sync_rxdata_pre = (rd_data >> 12) & 0xF;

					wr_data = (alct_sync_rxdata_dly <<  0) |	// Set delay depth, clear error FFs
						(alct_sync_tx_random  <<  4) |
						(alct_sync_clr_err    <<  5) |
						(alct_sync_rxdata_pre << 12);
					status	= vme_write(adr,wr_data);

					wr_data = wr_data & ~(1 << 5);				// un-clear error FFs
					status	= vme_write(adr,wr_data);

					// Read TMB received demux data
					for (i=0; i<=7; ++i) {			// loop over 1st/2nd demux words	0=1st[14:1],1=1st[28:15]
						adr     = alctfifo1_adr+base_adr;
						wr_data = 0x2000;				// select alct_loopback mode addressing
						wr_data = wr_data | (i << 1);
						status	= vme_write(adr,wr_data);

						adr     = alctfifo2_adr+base_adr;
						status  = vme_read(adr,rd_data);
						alct_demux_rd[i]=rd_data;
					}

					alct_sync_rxdata_1st = alct_demux_rd[0] | (alct_demux_rd[1] << 14);
					alct_sync_rxdata_2nd = alct_demux_rd[2] | (alct_demux_rd[3] << 14);
					alct_sync_expect_1st = alct_demux_rd[4] | (alct_demux_rd[5] << 14);
					alct_sync_expect_2nd = alct_demux_rd[6] | (alct_demux_rd[7] << 14);

					//	alct_sync_rxdata_1st = alct_sync_rxdata_1st | (1 << 5);	// Set rx bit lvds high to test bad bit detection and satisfy nattering nabob
					//	alct_sync_rxdata_2nd = alct_sync_rxdata_2nd | (1 << 5);

					// Read TMB data check flipflops
					adr     = alct_sync_ctrl_adr+base_adr;
					status  = vme_read(adr,rd_data);

					alct_sync_1st_err[alct_rxd_delay]    = ((rd_data >> 6) & 0x1);
					alct_sync_2nd_err[alct_rxd_delay]    = ((rd_data >> 7) & 0x1);
					alct_sync_1st_err_ff[alct_rxd_delay] = ((rd_data >> 8) & 0x1) | alct_sync_1st_err_ff[alct_rxd_delay];
					alct_sync_2nd_err_ff[alct_rxd_delay] = ((rd_data >> 9) & 0x1) | alct_sync_1st_err_ff[alct_rxd_delay];

					if (ipass==1) {
						fprintf(unit,"Teven|Todd: rxd_delay=%2i ",alct_rxd_delay);
						fprintf(unit,"rxdata_1st=%8.8X rxdata_2nd=%8.8X ",alct_sync_rxdata_1st,alct_sync_rxdata_2nd);
						fprintf(unit,"1st_err=%1i/%1i 2nd_err=%1i/%1i\n",
								alct_sync_1st_err[alct_rxd_delay],alct_sync_1st_err_ff[alct_rxd_delay],
								alct_sync_2nd_err[alct_rxd_delay],alct_sync_2nd_err_ff[alct_rxd_delay]);
						//	fprintf(unit,"\t\t expect_1st=%8.8X expect_2nd=%8.8X\n",alct_sync_expect_1st,alct_sync_expect_2nd);
					}

					// Compare received bits to expected pattern
					alct_1st_expect = 0xAAAAAAA;	// Teven
					alct_2nd_expect = 0x5555555;	// Todd 

					if (alct_1st_expect != alct_sync_expect_1st) {fprintf(unit,"TMB internal error: alct_sync_expect_1st %8.8X %8.8X",alct_1st_expect,alct_sync_expect_1st); pause("WTF!?");}
					if (alct_2nd_expect != alct_sync_expect_2nd) {fprintf(unit,"TMB internal error: alct_sync_expect_2nd %8.8X %8.8X",alct_2nd_expect,alct_sync_expect_2nd); pause("WTF!?");}

					for (ibit=0; ibit<=27; ++ibit) {
						ibit_1st_expected = (alct_1st_expect		>> ibit) & 0x1;
						ibit_2nd_expected = (alct_2nd_expect		>> ibit) & 0x1;
						ibit_1st_received = (alct_sync_rxdata_1st	>> ibit) & 0x1;
						ibit_2nd_received = (alct_sync_rxdata_2nd	>> ibit) & 0x1;
						if ((ibit_1st_expected !=  ibit_1st_received) ||
								(ibit_2nd_expected !=  ibit_2nd_received)) alct_rxd_bad[alct_rxd_delay][ibit]++;
					}	// Close ibit

				}	// Close ipass L23101:
				if (ipass==1) fprintf(unit,"\nAccumulating statistics...\n\n");
				if ((ipass%10==0) && (unit==stdout)) fprintf(unit,"%4i\r",npasses-ipass);
			}	// Close alct_rxd_delay L231015:

			// Find good spots window width and center in alct_rxd_delay for this alct_tof_delay and alct_rxd_posneg
			ngood		=  0;
			ngood_max	=  0;
			ngood_edge	=  0;
			ngood_center=  0;

			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
				good_spot= !(alct_sync_1st_err_ff[alct_rxd_delay] || alct_sync_2nd_err_ff[alct_rxd_delay]);
				good_spots[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay]=good_spot;
				fprintf(unit,"alct_rxd_delay=%2i good_spot=%1i\n",alct_rxd_delay,good_spot);
			}

			for (i=0; i<(dps_max*2); ++i) {	// scan delays 0 to 25 twice to span the awkward 25 to 0 wrap around
				alct_rxd_delay=i%(dps_max+1);
				good_spot=good_spots[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay];
				//	printf("alct_rxd_delay=%2i good_spot=%1i\n",alct_rxd_delay,good_spot);
				//	printf("i             =%2i good_spot=%1i\n",i,good_spot);

				if  (good_spot==1) ngood++;			// this is a good spot
				if ((good_spot==0) && (ngood>0)) {	// good spot just went away, so window preceeds it
					ngood_max  = ngood;
					ngood_edge = i;
					ngood      = 0;
				}	// close if
			}	// close for i

			if (ngood_max>0) ngood_center=(dps_max+ngood_edge-(ngood_max/2))%(dps_max+1);

			window_width[alct_rxd_posneg][alct_tof_delay]  = ngood_max;
			window_center[alct_rxd_posneg][alct_tof_delay] = ngood_center;

			fprintf(unit,"Window width  = %2i at tof=%2i posneg=%1i\n",window_width[alct_rxd_posneg][alct_tof_delay],alct_tof_delay,alct_rxd_posneg);
			fprintf(unit,"Window center = %2i at tof=%2i posneg=%1i\n",window_center[alct_rxd_posneg][alct_tof_delay],alct_tof_delay,alct_rxd_posneg);
			fprintf(unit,"\n");	

			if (unit!=stdout)
				fprintf(stdout," width=%2i center=%2i\n",
						window_width[alct_rxd_posneg][alct_tof_delay],
						window_center[alct_rxd_posneg][alct_tof_delay]);

			// Display timing window twice in case good area is near 0 or 25ns
			fprintf(unit,"Rxd    \n");	
			fprintf(unit,"Step   Berrs Average 12 01234567890123456789012345678  %5i samples\n",npasses);	

			for (j=0; j<=1; ++j) {
				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
					nbad=0;
					for (ibit=0; ibit<=27; ++ibit) {nbad=nbad+alct_rxd_bad[alct_rxd_delay][ibit];}
					avgbad=double(nbad)/double(npasses);
					nx=int(avgbad);
					if ((nx==0) && (nbad != 0)) nx=1;
					fprintf(unit,"%2i  %8i %7.4f %c%c |",alct_rxd_delay,nbad,avgbad,passfail[alct_sync_1st_err_ff[alct_rxd_delay]],passfail[alct_sync_2nd_err_ff[alct_rxd_delay]]);
					if (nbad!=0) for(i=1; i<=nx; ++i) fprintf(unit,"x");
					if (alct_rxd_delay==window_center[alct_rxd_posneg][alct_tof_delay]) fprintf(unit,"\t\t\t\t<--Center");
					fprintf(unit,"\n");
				}}

			// Display bad bits vs delay
			fprintf(unit,"\nCable Pair Errors vs alct_rxd_clock Delay Step\n");

			fprintf(unit," delay ");
			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {fprintf(unit,"%5i",alct_rxd_delay);}	// display delay values header
			fprintf(unit,"\n");

			fprintf(unit,"pair   ");
			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {fprintf(unit," ----");}
			fprintf(unit,"\n");

			for (ibit=0; ibit<=27; ++ibit) {
				fprintf(unit,"rx[%2i] ",ibit);
				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {fprintf(unit,"%5i",alct_rxd_bad[alct_rxd_delay][ibit]);}
				fprintf(unit,"\n");
			}

			// Close scan loops
		}	// alct_tof_delay
	}	// alct_rxd_posneg

// Display window center and width vs tof and posneg
if ((alct_rxd_posneg_min != alct_rxd_posneg_max) && alct_tof_delay_min != alct_tof_delay_max) alct_rxd_scan_done=true;

fprintf(unit,"\n");
for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
	for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {

		fprintf(unit,"Tof=%2i Posneg=%1i Window center=%2i  width=%2i\n",
				alct_tof_delay,alct_rxd_posneg,
				window_center[alct_rxd_posneg][alct_tof_delay],
				window_width[alct_rxd_posneg][alct_tof_delay]);

		newcenter=window_center[alct_rxd_posneg][alct_tof_delay];
	}
	fprintf(unit,"\n");
}

// Make a new default rxd delay table that can be imported to c++, need it for txd tof scan
if (alct_rxd_scan_done) {
	fprintf(log_file,"\nWindow Center vs ToF Look-up Table\n");
	fprintf(log_file,"int window_center_rxd[2][16]={");
	for (alct_rxd_posneg=0; alct_rxd_posneg<=1;  ++alct_rxd_posneg) {
		for (alct_tof_delay=0;  alct_tof_delay<=15;  ++alct_tof_delay ) {
			if (alct_tof_delay<=12)fprintf(log_file,"%3i",window_center[alct_rxd_posneg][alct_tof_delay]);
			if (alct_tof_delay> 12)fprintf(log_file,"%3i",0);
			if (!((alct_rxd_posneg==1) && (alct_tof_delay==15))) fprintf(log_file,",");
		}}
	fprintf(log_file,"};\n");
}

// Set alct rxd delay and posneg to new value or restore default
alct_rxd_default=newcenter;

inquire("\nDefault alct_rxd_delay  =%3i, change? ", minv=0, maxv=dps_max, radix=10, alct_rxd_default);
inquire(  "Default alct_rxd_posneg =%3i, change? ", minv=0, maxv=1,       radix=10, alct_rxd_posneg_default);

printf("Setting alct_rxd_delay  =%3i\n",alct_rxd_default);
printf("Setting alct_rxd_posneg =%3i\n",alct_rxd_posneg_default);

alct_rxd_delay	= alct_rxd_default;
alct_txd_delay	= alct_txd_default;
alct_tof_delay	= alct_tof_default;

ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0
phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);
posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg_default);
posneg_wr(base_adr,"alct_txd",alct_txd_posneg_default);

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;			// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);				// Get current state
wr_data = rd_data & 0xFF0F;						// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);		// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

goto L2300;

//------------------------------------------------------------------------------
//	ALCT txd clock delay scan: TMB-to-ALCT Teven|Todd Loopback
//------------------------------------------------------------------------------
L231100:
//	unit = stdout;
unit = log_file;

fprintf(unit,"ALCT txd clock delay scan: ALCT-to-TMB Teven|Todd Loopback\n");

// Get current 3D3444 + phaser delays
alct_tof_default = ddd_rd(base_adr, ddd_chip=0, ddd_channel=0);	// alct_tof_delay is chip0 ch0
alct_txd_default = phaser_rd(base_adr,"alct_txd",dps_delta);
alct_rxd_default = phaser_rd(base_adr,"alct_rxd",dps_delta);

// Get current posnegs
alct_rxd_posneg_default = posneg_rd(base_adr,"alct_rxd");
alct_txd_posneg_default = posneg_rd(base_adr,"alct_txd");

// Inquire
alct_rxd_delay	= alct_rxd_default;
alct_txd_delay	= alct_txd_default;
alct_tof_delay  = alct_tof_default;
alct_rxd_posneg = alct_rxd_posneg_default;
alct_txd_posneg = alct_txd_posneg_default;

inquire("Set alct_rxd_delay ?          cr=%2i", minv= 0, maxv= dps_max, radix=10, alct_rxd_delay);
inquire("Set alct_rxd_posneg?          cr=%2i", minv= 0, maxv= 1,       radix=10, alct_rxd_posneg);
inquire("Set alct_txd_posneg? -1=scan, cr=%2i", minv=-1, maxv= 1,       radix=10, alct_txd_posneg);
inquire("Set alct_tof_delay ? -1=scan, cr=%2i", minv=-1, maxv=12,       radix=10, alct_tof_delay );

alct_rxd_default = alct_rxd_delay;

// Turn off CCB inputs to zero alct_adb_sync and ext_trig
adr     = ccb_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFBF;					// Clear previous l1a
wr_data = wr_data | 0x1;					// Turn off CCB backplane
status  = vme_write(adr,wr_data);

// Put ALCT into loopback mode, turn off Teven|Todd xmit, seq_cmd[0],[2] share same wire pair
seq_cmd_bit[0]=1;	seq_cmd_bit[2]=0;		// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;		// (seq_cmd[1] , seq_cmd[3]) selects alct storage bank 0,1,2

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);			// Get current state
wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

// Scan tof and txd_posneg, or use input values
alct_tof_delay_min	= (alct_tof_delay  < 0) ?  0 : alct_tof_delay;
alct_tof_delay_max	= (alct_tof_delay  < 0) ? 12 : alct_tof_delay;
alct_txd_posneg_min	= (alct_txd_posneg < 0) ?  0 : alct_txd_posneg;
alct_txd_posneg_max	= (alct_txd_posneg < 0) ?  1 : alct_txd_posneg;
alct_tof_scan		= (alct_tof_delay  < 0) ?  true : false;

for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {
	for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {

		// Set scanned delays
		ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0

		// Shift rxd to track moving tof, use a scan table if it exists, else use default table
		if (alct_tof_scan) {
			if (alct_rxd_scan_done) {
				alct_rxd_delay = window_center[alct_rxd_posneg][alct_tof_delay];
				fprintf(unit,"Setting alct_rxd_delay=%2i for alct_rxd_posneg=%1i tof=%2i, ",alct_rxd_delay,alct_rxd_posneg,alct_tof_delay);
				fprintf(unit,"using alct_rxd_delay scan table\n");}
			else {
				alct_rxd_delay = window_center_rxd[alct_rxd_posneg][alct_tof_delay];
				fprintf(unit,"Setting alct_rxd_delay=%2i for alct_rxd_posneg=%1i tof=%2i, ",alct_rxd_delay,alct_rxd_posneg,alct_tof_delay);
				fprintf(unit,"using default table\n");
			}
			phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
		}	// close if alct_tof_scan

		// Set scanned posnegs
		posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
		posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

		// Clear error accumulators
		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			for (ibit=0; ibit<=27; ++ibit) {
				alct_txd_bad[alct_txd_delay][ibit]=0;
			}}

		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			alct_sync_1st_err_ff[alct_txd_delay] = 0;
			alct_sync_2nd_err_ff[alct_txd_delay] = 0;
		}

		// Step alct txd clock delay
		fprintf(unit,"\n");	
		fprintf(unit,"Checking 80MHz Teven|Todd data ALCT looped back from TMB\n");
		fprintf(unit,"Holding  alct_rxd_delay  =%2i\n",alct_rxd_delay);
		fprintf(unit,"Setting  alct_tof_delay  =%2i\n",alct_tof_delay);
		fprintf(unit,"Setting  alct_txd_posneg =%2i\n",alct_txd_posneg);
		fprintf(unit,"Using    dps_max         =%2i\n",dps_max);
		fprintf(unit,"Using    dps_delta       =%2i\n",dps_delta);
		fprintf(unit,"\n");	
		fprintf(unit,"Stepping alct_txd_delay...\n\n");
		if (unit!=stdout) fprintf(stdout,"Scanning alct_tof_delay=%2i alct_txd_posneg=%1i...wait",alct_tof_delay,alct_txd_posneg);

		npasses = 1000;
		for (ipass=1; ipass<=npasses; ++ipass) {								// L231115
			for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++ alct_txd_delay) {	// L231110

				// Set scanned delays
				phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

				// Write Teven|Todd into ALCT loopback bank 0, writes 0s to banks 1,2
				alct_1st_bank[0] = 0x2AA;	alct_2nd_bank[0] = 0x155;	//1st-in-time: Teven = 10'b10 1010 1010, 2nd-in-time: Todd  = 10'b01 0101 0101
				alct_1st_bank[1] = 0;		alct_2nd_bank[1] = 0;
				alct_1st_bank[2] = 0;		alct_2nd_bank[2] = 0;
				seq_cmd_bit[0]   = 1;		seq_cmd_bit[2]   = 0;		// (seq_cmd[0] | seq_cmd[2] == 1) keeps ALCT in loopback mode

				for (ibank=0; ibank<=2; ++ibank) {
					adr     = alct_cfg_adr+base_adr;
					status  = vme_read(adr,rd_data);				// Get current seq_cmd[3:0] state

					seq_cmd_bit[1] = (ibank >> 0) & 0x1;
					seq_cmd_bit[3] = (ibank >> 1) & 0x1;			// (seq_cmd[1] , seq_cmd[3]) selects alct storage bank 0,1,2

					wr_data = rd_data & 0xFF0F;						// Clear bits[7:4] alct_seq_cmd[3:0]
					wr_data = wr_data | (seq_cmd_bit[0] << 4);
					wr_data = wr_data | (seq_cmd_bit[1] << 5);
					wr_data = wr_data | (seq_cmd_bit[2] << 6);
					wr_data = wr_data | (seq_cmd_bit[3] << 7);
					status  = vme_write(adr,wr_data);				// Write new seq_cmd to select ibank

					adr		= alct_sync_txdata_1st+base_adr;
					wr_data = alct_1st_bank[ibank];					// Write 1st-in-time data for this bank
					status  = vme_write(adr,wr_data);	

					adr		= alct_sync_txdata_2nd+base_adr;
					wr_data = alct_2nd_bank[ibank];					// Write 2nd-in-time data for this bank
					status  = vme_write(adr,wr_data);
				}

				// Clear TMB data check flipflops for this delay value, set transmitted data delay depth
				alct_sync_rxdata_dly = 0;
				alct_sync_tx_random  = 0;
				alct_sync_clr_err    = 1;

				adr     = alct_sync_ctrl_adr+base_adr;			// Set delay depth, clear error FFs
				status	= vme_read(adr,rd_data);				// get current
				alct_sync_rxdata_pre = (rd_data >> 12) & 0xF;

				wr_data = (alct_sync_rxdata_dly <<  0) |
					(alct_sync_tx_random  <<  4) |
					(alct_sync_clr_err    <<  5) |
					(alct_sync_rxdata_pre << 12);
				status	= vme_write(adr,wr_data);

				wr_data = wr_data & ~(1 << 5);					// un-clear error FFs
				status	= vme_write(adr,wr_data);	

				// Read TMB received demux data
				for (i=0; i<=7; ++i) {			// loop over 1st/2nd demux words	0=1st[14:1],1=1st[28:15]
					adr     = alctfifo1_adr+base_adr;
					wr_data = 0x2000;				// select alct_loopback mode addressing
					wr_data = wr_data | (i << 1);
					status	= vme_write(adr,wr_data);

					adr     = alctfifo2_adr+base_adr;
					status  = vme_read(adr,rd_data);
					alct_demux_rd[i]=rd_data;
				}

				alct_sync_rxdata_1st = alct_demux_rd[0] | (alct_demux_rd[1] << 14);
				alct_sync_rxdata_2nd = alct_demux_rd[2] | (alct_demux_rd[3] << 14);
				alct_sync_expect_1st = alct_demux_rd[4] | (alct_demux_rd[5] << 14);
				alct_sync_expect_2nd = alct_demux_rd[6] | (alct_demux_rd[7] << 14);

				//	alct_sync_rxdata_1st = alct_sync_rxdata_1st | (1 << 5);	// Set rx bit lvds high to test bad bit detection and satisfy nattering nabob
				//	alct_sync_rxdata_2nd = alct_sync_rxdata_2nd | (1 << 5);

				// Read TMB data check flipflops
				adr     = alct_sync_ctrl_adr+base_adr;
				status  = vme_read(adr,rd_data);

				alct_sync_1st_err[alct_txd_delay]    = ((rd_data >> 6) & 0x1);
				alct_sync_2nd_err[alct_txd_delay]    = ((rd_data >> 7) & 0x1);
				alct_sync_1st_err_ff[alct_txd_delay] = ((rd_data >> 8) & 0x1) | alct_sync_1st_err_ff[alct_txd_delay];
				alct_sync_2nd_err_ff[alct_txd_delay] = ((rd_data >> 9) & 0x1) | alct_sync_1st_err_ff[alct_txd_delay];

				if (ipass==1) {
					fprintf(unit,"Teven|Todd: alct_txd_delay=%2i 1st=%8.8X 2nd=%8.8X ",alct_txd_delay,alct_sync_rxdata_1st,alct_sync_rxdata_2nd);
					fprintf(unit,"1st_err=%1i/%1i 2nd_err=%1i/%1i\n",alct_sync_1st_err[alct_txd_delay],alct_sync_1st_err_ff[alct_txd_delay],alct_sync_2nd_err[alct_txd_delay],alct_sync_2nd_err_ff[alct_txd_delay]);
				}

				// Compare received bits to expected pattern
				alct_1st_expect = 0x2AA;	// Teven
				alct_2nd_expect = 0x155;	// Todd 

				if (alct_1st_expect != alct_sync_expect_1st) {fprintf(unit,"TMB internal error: alct_1st_expect=%8.8X alct_sync_expect_1st=%8.8X\n",alct_1st_expect,alct_sync_expect_1st);}
				if (alct_2nd_expect != alct_sync_expect_2nd) {fprintf(unit,"TMB internal error: alct_2nd_expect=%8.8X alct_sync_expect_2nd %8.8X\n",alct_2nd_expect,alct_sync_expect_2nd);}

				for (ibit=0; ibit<=27; ++ibit) {
					ibit_1st_expected = (alct_1st_expect		>> ibit) & 0x1;
					ibit_2nd_expected = (alct_2nd_expect		>> ibit) & 0x1;
					ibit_1st_received = (alct_sync_rxdata_1st	>> ibit) & 0x1;
					ibit_2nd_received = (alct_sync_rxdata_2nd	>> ibit) & 0x1;
					if ((ibit_1st_expected !=  ibit_1st_received) ||
							(ibit_2nd_expected !=  ibit_2nd_received)) alct_txd_bad[alct_txd_delay][ibit]++;
				}	// Close ibit

			}	// Close for ipass L231110
			if (ipass==1   ) printf("\nAccumulating statistics...\n\n");
			if (ipass%10==0) printf("%4i\r",npasses-ipass);
		}	// Close for alct_txd_delay L231115:

		// Find good spots window width and center in alct_txd_delay for this alct_tof_delay and alct_txd_posneg
		ngood		=  0;
		ngood_max	=  0;
		ngood_edge	=  0;
		ngood_center=  0;

		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			good_spot= !(alct_sync_1st_err_ff[alct_txd_delay] || alct_sync_2nd_err_ff[alct_txd_delay]);
			good_spots[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay]=good_spot;
			//	printf("alct_txd_delay=%2i good_spot=%1i\n",alct_txd_delay,good_spot);
		}

		for (i=0; i<=(dps_max*2); ++i) {	// scan delays 0 to 25 twice to span the awkward 25 to 0 wrap around
			alct_txd_delay=i%(dps_max+1);
			good_spot=good_spots[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay];
			//	printf("alct_txd_delay=%2i good_spot=%1i\n",alct_txd_delay,good_spot);
			//	printf("i             =%2i good_spot=%1i\n",i,good_spot);

			if  (good_spot==1) ngood++;			// this is a good spot
			if ((good_spot==0) && (ngood>0)) {	// good spot just went away, so window preceeds it
				ngood_max  = ngood;
				ngood_edge = i;
				ngood      = 0;
			}	// close if
		}	// close for i

		if (ngood_max>0) ngood_center=(dps_max+ngood_edge-(ngood_max/2))%(dps_max+1);

		window_width[alct_txd_posneg][alct_tof_delay]  = ngood_max;
		window_center[alct_txd_posneg][alct_tof_delay] = ngood_center;

		fprintf(unit,"Window width  = %2i at tof=%2i posneg=%1i\n",window_width[alct_txd_posneg][alct_tof_delay],alct_tof_delay,alct_txd_posneg);
		fprintf(unit,"Window center = %2i at tof=%2i posneg=%1i\n",window_center[alct_txd_posneg][alct_tof_delay],alct_tof_delay,alct_txd_posneg);
		fprintf(unit,"\n");	

		if (unit!=stdout)
			fprintf(stdout," width=%2i center=%2i\n",
					window_width[alct_txd_posneg][alct_tof_delay],
					window_center[alct_txd_posneg][alct_tof_delay]);

		// Display timing window twice in case good area is near 0 or 25ns
		fprintf(unit,"Txd    \n");	
		fprintf(unit,"Step   Berrs Average 12 01234567890123456789012345678  %5i samples\n",npasses);	

		for (j=0; j<=1; ++j) {
			for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
				nbad=0;
				for (ibit=0; ibit<=27; ++ibit) {nbad=nbad+alct_txd_bad[alct_txd_delay][ibit];}
				avgbad=double(nbad)/double(npasses);
				nx=int(avgbad);
				if ((nx==0) && (nbad != 0)) nx=1;
				fprintf(unit,"%2i  %8i %7.4f %c%c |",alct_txd_delay,nbad,avgbad,passfail[alct_sync_1st_err_ff[alct_txd_delay]],passfail[alct_sync_2nd_err_ff[alct_txd_delay]]);
				if (nbad!=0) for(i=1; i<=nx; ++i) fprintf(unit,"x");
				if (alct_txd_delay==window_center[alct_txd_posneg][alct_tof_delay]) fprintf(unit,"\t\t\t\t<--Center");
				fprintf(unit,"\n");
			}}

		// Display bad bits vs delay
		fprintf(unit,"\nCable Pair Errors vs alct_txd_clock Delay Step\n");

		fprintf(unit," delay ");
		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {fprintf(unit,"%5i",alct_txd_delay);}	// display delay values header
		fprintf(unit,"\n");

		fprintf(unit,"pair   ");
		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {fprintf(unit," ----");}
		fprintf(unit,"\n");

		for (ibit=0; ibit<=27; ++ibit) {
			fprintf(unit,"tx[%2i] ",ibit);
			for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {fprintf(unit,"%5i",alct_txd_bad[alct_txd_delay][ibit]);}
			fprintf(unit,"\n");
		}

		// Close scan loops
	}	// alct_tof_delay
}	// alct_txd_posneg

// Display window center and width vs tof and posneg
fprintf(unit,"\n");
for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {
	for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {

		fprintf(unit,"Tof=%2i Posneg=%1i Window center=%2i  width=%2i\n",
				alct_tof_delay,alct_txd_posneg,
				window_center[alct_txd_posneg][alct_tof_delay],
				window_width[alct_txd_posneg][alct_tof_delay]);

		newcenter=window_center[alct_txd_posneg][alct_tof_delay];
	}
	fprintf(unit,"\n");
}

// Set alct txd delay and posneg to new value or restore default
alct_txd_default=newcenter;

inquire("\nDefault alct_txd_delay  =%2i, change? ", minv=0, maxv=dps_max, radix=10, alct_txd_default);
inquire(  "Default alct_txd_posneg =%2i, change? ", minv=0, maxv= 1,      radix=10, alct_txd_posneg_default);

printf("Setting alct_txd_delay  =%2i\n",alct_txd_default);
printf("Setting alct_txd_posneg =%2i\n",alct_txd_posneg_default);

alct_rxd_delay	= alct_rxd_default;
alct_txd_delay	= alct_txd_default;
alct_tof_delay	= alct_tof_default;
alct_rxd_posneg	= alct_rxd_posneg_default;
alct_txd_posneg	= alct_txd_posneg_default;

ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0
phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);
posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg_default);
posneg_wr(base_adr,"alct_txd",alct_txd_posneg_default);

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;			// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);				// Get current state
wr_data = rd_data & 0xFF0F;						// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);		// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

goto L2300;

//------------------------------------------------------------------------------
//	ALCT Tx|Rx default delays TMB-to-ALCT Walking 1 Loopback
//------------------------------------------------------------------------------
L231200:
//	unit  = stdout;
unit  = log_file;
debug = false;

fprintf(unit,"\nALCT tx+rx default delays TMB-to-ALCT Walking 1 Loopback\n");

// Get current 3D3444 + phaser delays
alct_tof_default = ddd_rd(base_adr, ddd_chip=0, ddd_channel=0);	// alct_tof_delay is chip0 ch0
alct_txd_default = phaser_rd(base_adr,"alct_txd",dps_delta);
alct_rxd_default = phaser_rd(base_adr,"alct_rxd",dps_delta);

// Get current posnegs
alct_rxd_posneg_default = posneg_rd(base_adr,"alct_rxd");
alct_txd_posneg_default = posneg_rd(base_adr,"alct_txd");

// Inquire
alct_rxd_delay	= alct_rxd_default;
alct_txd_delay	= alct_txd_default;
alct_tof_delay  = alct_tof_default;
alct_rxd_posneg = alct_rxd_posneg_default;
alct_txd_posneg = alct_txd_posneg_default;

inquire("Set alct_rxd_delay ? cr=%2i", minv=0, maxv=dps_max, radix=10, alct_rxd_delay );
inquire("Set alct_txd_delay ? cr=%2i", minv=0, maxv=dps_max, radix=10, alct_txd_delay );
inquire("Set alct_tof_delay ? cr=%2i", minv=0, maxv=12,      radix=10, alct_tof_delay );
inquire("Set alct_rxd_posneg? cr=%2i", minv=0, maxv= 1,      radix=10, alct_rxd_posneg);
inquire("Set alct_txd_posneg? cr=%2i", minv=0, maxv= 1,      radix=10, alct_txd_posneg);

// Turn off CCB inputs to zero alct_adb_sync and ext_trig
adr     = ccb_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFBF;					// Clear previous l1a
wr_data = wr_data | 0x1;					// Turn off CCB backplane
status  = vme_write(adr,wr_data);

// Put ALCT into loopback mode, turn off Teven|Todd xmit, seq_cmd[0],[2] share same wire pair
seq_cmd_bit[0]=1;	seq_cmd_bit[2]=0;		// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;		// (seq_cmd[1] , seq_cmd[3]) selects alct storage bank 0,1,2

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);			// Get current state
wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

// Set non-scanned posnegs
posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

// Set non-scanned delays
ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0
phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

// Clear error accumulators
for (ifs=0; ifs<=1;  ++ifs) {	// loop over 1st-in-time, 2nd-in-time
	for (itx=0; itx<=27; ++itx) {	// loop over 28 bits
		for (ibit=0; ibit<=27; ++ibit) {
			alct_walking1_err[itx][ifs][ibit]=0;
			alct_walking1_hit[itx][ifs][ibit][0]=0;
			alct_walking1_hit[itx][ifs][ibit][1]=0;
		}}}

// Step walking 1 bit
fprintf(unit,"\nChecking 80MHz walking 1 data ALCT looped back from TMB\n\n");
fprintf(unit,"        ");
fprintf(unit,"1st 0123456789012345678901234567 2nd 0123456789012345678901234567 \n");

npasses = 1000;
for (ipass=1; ipass<=npasses; ++ipass) {			// L231205
	for (ifs=0; ifs<=1;  ++ifs) {	// loop over 1st-in-time, 2nd-in-time
		for (itx=0; itx<=27; ++itx) {	// loop over 28 bits

			// Write walking 1 into ALCT loopback bank 0,1,2
			ibank = itx/10;		// 0-9 in bank 0, 10-19 in bank 1, 20-27 in bank 2
			ibit  = itx%10;		// bit position within a bank

			alct_1st_bank[0] = 0;
			alct_1st_bank[1] = 0;
			alct_1st_bank[2] = 0;
			alct_1st_bank[ibank] = (1 << ibit) * (ifs==0);

			alct_2nd_bank[0] = 0;
			alct_2nd_bank[1] = 0;
			alct_2nd_bank[2] = 0;
			alct_2nd_bank[ibank] = (1 << ibit) * (ifs==1);

			seq_cmd_bit[0]=1; seq_cmd_bit[2]=0;				// (seq_cmd[0] | seq_cmd[2] == 1) keeps ALCT in loopback mode

			for (ibank=0; ibank<=2; ++ibank) {
				adr     = alct_cfg_adr+base_adr;
				status  = vme_read(adr,rd_data);				// Get current seq_cmd[3:0] state

				seq_cmd_bit[1] = (ibank >> 0) & 0x1;
				seq_cmd_bit[3] = (ibank >> 1) & 0x1;			// (seq_cmd[1] , seq_cmd[3]) selects alct storage bank 0,1,2

				wr_data = rd_data & 0xFF0F;						// Clear bits[7:4] alct_seq_cmd[3:0]
				wr_data = wr_data | (seq_cmd_bit[0] << 4);
				wr_data = wr_data | (seq_cmd_bit[1] << 5);
				wr_data = wr_data | (seq_cmd_bit[2] << 6);
				wr_data = wr_data | (seq_cmd_bit[3] << 7);
				status  = vme_write(adr,wr_data);				// Write new seq_cmd to select ibank

				adr		= alct_sync_txdata_1st+base_adr;
				wr_data = alct_1st_bank[ibank];					// Write 1st-in-time data for this bank
				status  = vme_write(adr,wr_data);	

				adr		= alct_sync_txdata_2nd+base_adr;
				wr_data = alct_2nd_bank[ibank];					// Write 2nd-in-time data for this bank
				status  = vme_write(adr,wr_data);
			}

			// Read TMB received demux data
			for (i=0; i<=7; ++i) {			// loop over 1st/2nd demux words	0=1st[14:1],1=1st[28:15]
				adr     = alctfifo1_adr+base_adr;
				wr_data = 0x2000;				// select alct_loopback mode addressing
				wr_data = wr_data | (i << 1);
				status	= vme_write(adr,wr_data);

				adr     = alctfifo2_adr+base_adr;
				status  = vme_read(adr,rd_data);
				alct_demux_rd[i]=rd_data;
			}

			alct_sync_rxdata_1st = alct_demux_rd[0] | (alct_demux_rd[1] << 14);
			alct_sync_rxdata_2nd = alct_demux_rd[2] | (alct_demux_rd[3] << 14);
			alct_sync_expect_1st = alct_demux_rd[4] | (alct_demux_rd[5] << 14);
			alct_sync_expect_2nd = alct_demux_rd[6] | (alct_demux_rd[7] << 14);

			//	alct_sync_rxdata_1st = alct_sync_rxdata_1st | (1 << 5);	// Set rx bit lvds high to test bad bit detection and satisfy nattering nabob
			//	alct_sync_rxdata_2nd = alct_sync_rxdata_2nd | (1 << 5);
			//	if (ipass==1) fprintf(unit,"Teven|Todd: 1st=%8.8X 2nd=%8.8X\n",alct_sync_rxdata_1st,alct_sync_rxdata_2nd);
			//	fprintf(unit,"Walking 1: 1st/2nd=%1i tx bit=%2i 1st=%8.8X 2nd=%8.8X\n",ifs,itx,alct_sync_rxdata_1st,alct_sync_rxdata_2nd);

			// Display tx bits vs received bits
			if (ipass==1) {
				fprintf(unit,"%1i %2i tx",ifs,itx);
				fprintf(unit," 1st "); for (i=0; i<=27; ++i) fprintf(unit,"%1c",dash1[(i==itx)*(ifs==0)]);
				fprintf(unit," 2nd "); for (i=0; i<=27; ++i) fprintf(unit,"%1c",dash1[(i==itx)*(ifs==1)]);
				fprintf(unit,"\n");
				fprintf(unit,"     rx");
				fprintf(unit," 1st "); for (i=0; i<=27; ++i) fprintf(unit,"%1c",dash1[(alct_sync_rxdata_1st >> i) & 0x1]);
				fprintf(unit," 2nd "); for (i=0; i<=27; ++i) fprintf(unit,"%1c",dash1[(alct_sync_rxdata_2nd >> i) & 0x1]);
				fprintf(unit,"\n");
			}

			// Compare received bits to expected pattern
			alct_1st_expect = (1 << itx) * (ifs==0);
			alct_2nd_expect = (1 << itx) * (ifs==1); 

			if (alct_1st_expect != alct_sync_expect_1st) {fprintf(unit,"TMB internal error: alct_sync_expect_1st %8.8X %8.8X",alct_1st_expect,alct_sync_expect_1st); pause("WTF!?");}
			if (alct_2nd_expect != alct_sync_expect_2nd) {fprintf(unit,"TMB internal error: alct_sync_expect_2nd %8.8X %8.8X",alct_2nd_expect,alct_sync_expect_2nd); pause("WTF!?");}

			for (ibit=0; ibit<=27; ++ibit) {
				ibit_1st_expected = (alct_1st_expect >> ibit) & 0x1;
				ibit_2nd_expected = (alct_2nd_expect >> ibit) & 0x1;
				ibit_1st_received = (alct_sync_rxdata_1st  >> ibit) & 0x1;
				ibit_2nd_received = (alct_sync_rxdata_2nd  >> ibit) & 0x1;

				if ((ibit_1st_expected !=  ibit_1st_received) ||
						(ibit_2nd_expected !=  ibit_2nd_received)) alct_walking1_err[itx][ifs][ibit]++;

				alct_walking1_hit[itx][ifs][ibit][0]=alct_walking1_hit[itx][ifs][ibit][0]+ibit_1st_received;
				alct_walking1_hit[itx][ifs][ibit][1]=alct_walking1_hit[itx][ifs][ibit][1]+ibit_2nd_received;
			}	// Close ibit

			// Close bit, first, passes
		}	// close itx bit loop
	}	// close ifs first/second loop
	if (ipass==1   ) printf("\nAccumulating statistics...\n\n");
	if (ipass%10==0) printf("%4i\r",npasses-ipass);

}	// Close for ipass L231205

// Display hit bits
if (debug) {
	fprintf(unit,"\nALCT Sync-mode Walking 1: Errors\n"); 
	for (ifs=0; ifs<=1;  ++ifs) {	// loop over 1st-in-time, 2nd-in-time
		for (itx=0; itx<=27; ++itx) {	// loop over 28 bits
			fprintf(unit,"ifs=%1i itx=%2i ",ifs,itx);
			for (ibit=0; ibit<=27; ++ibit) {
				fprintf(unit,"%5i",alct_walking1_err[itx][ifs][ibit]);
			}
			fprintf(unit,"\n");
		}}
}

// Display summary
fprintf(unit,"ALCT Sync-mode Walking 1 Loopback: Any bit hit displays a 1\n"); 
fprintf(unit,"                            1         2         3         4         5\n"); 
fprintf(unit,"1st|2nd TxBit  Rx=01234567890123456789012345678901234567890123456789012345\n"); 
for (ifs=0; ifs<=1;  ++ifs) {	// loop over 1st-in-time, 2nd-in-time
	for (itx=0; itx<=27; ++itx) {	// loop over 28 bits
		fprintf(unit,"ifs=%2i  itx=%2i    ",ifs,itx);
		nbad=0;
		for (ibit=0; ibit<=27; ++ibit) {fprintf(unit,"%c",dash1[(alct_walking1_hit[itx][ifs][ibit][0]!=0)]);}
		for (ibit=0; ibit<=27; ++ibit) {fprintf(unit,"%c",dash1[(alct_walking1_hit[itx][ifs][ibit][1]!=0)]);}
		for (ibit=0; ibit<=27; ++ibit) {nbad=nbad+alct_walking1_err[itx][ifs][ibit];}
		fprintf(unit," %c",(passfail[nbad!=0]));
		fprintf(unit,"\n");
	}}

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;			// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);				// Get current state
wr_data = rd_data & 0xFF0F;						// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);		// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

goto L2300;

//------------------------------------------------------------------------------
//	ALCT Txd|Rxd clock delay scan TMB-to-ALCT TMB Random Loopback
//------------------------------------------------------------------------------
L231300:
//	unit  = stdout;
unit  = log_file;
debug = false;

fprintf(unit,"\nALCT Txd|Rxd clock delay scan TMB-to-ALCT TMB Random Loopback\n");

// Get current 3D3444 + phaser delays
alct_tof_default = ddd_rd(base_adr, ddd_chip=0, ddd_channel=0);	// alct_tof_delay is chip0 ch0
alct_txd_default = phaser_rd(base_adr,"alct_txd",dps_delta);
alct_rxd_default = phaser_rd(base_adr,"alct_rxd",dps_delta);

// Get current posnegs
alct_rxd_posneg_default = posneg_rd(base_adr,"alct_rxd");
alct_txd_posneg_default = posneg_rd(base_adr,"alct_txd");

// Inquire
alct_rxd_delay	= alct_rxd_default;
alct_txd_delay	= alct_txd_default;
alct_tof_delay  = alct_tof_default;
alct_rxd_posneg = alct_rxd_posneg_default;
alct_txd_posneg = alct_txd_posneg_default;
msec            = 1000;

inquire("Set alct_rxd_posneg? -1=scan, cr=%3i", minv=-1, maxv= 1, radix=10, alct_rxd_posneg);
inquire("Set alct_txd_posneg? -1=scan, cr=%3i", minv=-1, maxv= 1, radix=10, alct_txd_posneg);
inquire("Set alct_tof_delay ? -1=scan, cr=%3i", minv=-1, maxv=12, radix=10, alct_tof_delay );
inquire("Millisecs per spot ?          cr=%3i", minv= 0, maxv=1000000, radix=10, msec);

// Turn off CCB inputs to zero alct_adb_sync and ext_trig
adr     = ccb_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFBF;					// Clear previous l1a
wr_data = wr_data | 0x1;					// Turn off CCB backplane
status  = vme_write(adr,wr_data);

// Put ALCT into loopback mode, turn off Teven|Todd xmit, seq_cmd[0],[2] share same wire pair
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=1;		// (seq_cmd[2] &!seq_cmd[0]) puts ALCT into loopback randoms mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;		// (seq_cmd[3] , seq_cmd[1]) selects alct storage bank 0,1,2

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);			// Get current state
wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

// Scan tof and posnegs, or use input values
alct_tof_delay_min  = (alct_tof_delay  >= 0) ? alct_tof_delay :  0;
alct_tof_delay_max  = (alct_tof_delay  >= 0) ? alct_tof_delay : 12;

alct_rxd_posneg_min = (alct_rxd_posneg >= 0) ? alct_rxd_posneg : 0;
alct_rxd_posneg_max = (alct_rxd_posneg >= 0) ? alct_rxd_posneg : 1;

alct_txd_posneg_min = (alct_txd_posneg >= 0) ? alct_txd_posneg : 0;
alct_txd_posneg_max = (alct_txd_posneg >= 0) ? alct_txd_posneg : 1;

for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {
	for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
		for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {

			// Set scanned delays and posnegs
			ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0

			posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
			posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

			// Display scanned parameters
			fprintf(unit,"\n");
			fprintf(unit,"Scan Setting:\n");
			fprintf(unit,"alct_tof_delay  = %2i\n", alct_tof_delay );
			fprintf(unit,"alct_rxd_posneg = %2i\n", alct_rxd_posneg);
			fprintf(unit,"alct_txd_posneg = %2i\n", alct_txd_posneg);
			fprintf(unit,"\n");

			// Step alct rxd and txd clock delays, and transmitter pipeline depth
			fprintf(unit,"Checking 80MHz Random numbers ALCT looped back from TMB\n");

			for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
				phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
					phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);

					printf("tof=%2i txd_posneg=%1i rxd_posneg=%1i txd_delay=%2i rxd_delay=%2i\r",
							alct_tof_delay,alct_txd_posneg,alct_rxd_posneg,alct_txd_delay,alct_rxd_delay);

					for (pipe_depth=0; pipe_depth<=15; ++pipe_depth) {
						alct_sync_rxdata_dly = pipe_depth;

						// Set pipe depth, clear data check flip-flops
						alct_sync_tx_random  = 1;
						alct_sync_clr_err    = 1;

						adr      = alct_sync_ctrl_adr+base_adr;					// Set pipe depth, clear error FFs
						status   = vme_read(adr,rd_data);						// get current
						alct_sync_rxdata_pre = (rd_data >> 12) & 0xF;

						wr_data = (alct_sync_rxdata_dly <<  0) |
							(alct_sync_tx_random  <<  4) |
							(alct_sync_clr_err    <<  5) |
							(alct_sync_rxdata_pre << 12);
						status	= vme_write(adr,wr_data);

						wr_data = wr_data & ~(1 << 5);							// un-clear error FFs, hammer it a few times while system settles from delay changes
						for (i=0; i<=100; ++i) {
							status	= vme_write(adr,wr_data);	
						}

						// Wait for error stats to accumulate
						ibad=0;
						for (i=0; i<=msec; i=i+100) {							// 0 msec first time thru for quick reject of  bad spots
							sleep(i);

							// See if TMB data check flipflops are OK
							adr     = alct_sync_ctrl_adr+base_adr;
							status  = vme_read(adr,rd_data);

							alct_sync_1st_err_ff[0] = (rd_data >> 8) & 0x1;
							alct_sync_2nd_err_ff[0] = (rd_data >> 9) & 0x1;

							ibad = alct_sync_1st_err_ff[0] | alct_sync_2nd_err_ff[0];
							alct_rxd_txd_depth[alct_rxd_delay][alct_txd_delay][pipe_depth]=ibad;

							//	fprintf(unit,"alct_txd_delay=%1X alct_rxd_delay=%1X pipe_depth=%1X ibad=%1i\n",alct_txd_delay,alct_rxd_delay,pipe_depth,ibad);
							if (ibad != 0) break;			// TMB data check already went bad, so done with this rx tx pair
						}	// close for msec

						// Read TMB received demux data just to see whats going on
						if (debug) {
							for (i=0; i<=7; ++i) {			// loop over 1st/2nd demux words	0=1st[14:1],1=1st[28:15]
								adr     = alctfifo1_adr+base_adr;
								wr_data = 0x2000;				// select alct_loopback mode addressing
								wr_data = wr_data | (i << 1);
								status	= vme_write(adr,wr_data);

								adr     = alctfifo2_adr+base_adr;
								status  = vme_read(adr,rd_data);
								alct_demux_rd[i]=rd_data;
							}

							alct_sync_rxdata_1st = alct_demux_rd[0] | (alct_demux_rd[1] << 14);
							alct_sync_rxdata_2nd = alct_demux_rd[2] | (alct_demux_rd[3] << 14);
							alct_sync_expect_1st = alct_demux_rd[4] | (alct_demux_rd[5] << 14);
							alct_sync_expect_2nd = alct_demux_rd[6] | (alct_demux_rd[7] << 14);

							fprintf(unit,"Random Loopback: alct_txd_delay=%2i alct_rxd_delay=%2i", alct_txd_delay,alct_rxd_delay);
							fprintf(unit,"  read 1st=%8.8X 2nd=%8.8X ", alct_sync_rxdata_1st,alct_sync_rxdata_2nd);
							fprintf(unit,"expect 1st=%8.8X 2nd=%8.8X\n",alct_sync_expect_1st,alct_sync_expect_2nd);
						}

						// Close txd,rxd,depth loops...we are still inside posnegs and ToF loops
					}}}

			// Find correct depth in the transmitter delay pipeline, and count good spots
			ngood_spots=0;
			for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
					ngood_depths=0;
					good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay]=-1;
					for (pipe_depth=0; pipe_depth<=15; ++pipe_depth) {
						ibad = alct_rxd_txd_depth[alct_rxd_delay][alct_txd_delay][pipe_depth];
						if (ibad==0) {
							ngood_depths++;
							good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay]=pipe_depth;
							ngood_spots++;
							fprintf(log_file,"alct_txd_delay=%3i alct_rxd_delay=%3i pipe_depth=%1X ibad=%1i\n",alct_txd_delay,alct_rxd_delay,pipe_depth,ibad);
						}	// close ibad
					}	// close pipe
					if (ngood_depths >1) printf("Warning: data match found at >1 pipeline depths, should not happen tx=%2i rx=%2i ngood_depths=%2i\n",alct_txd_delay,alct_rxd_delay,ngood_depths);
				}}	// close txt rxd

			good_spots_pos_tof[alct_rxd_posneg][alct_txd_posneg][alct_tof_delay]=ngood_spots;
			fprintf(unit,"\n\ntof=%2i alct_rxd_posneg=%1i alct_txd_posneg=%1i good_spots=%3i\n",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg,ngood_spots);

			// Display good depths vs rxd txd
			fprintf(unit,"\nPipeline depth adr bit where RxData=TxData vs alct_txd_delay vs alct_rxd_delay  %3imsec=%ibx\n",msec,msec*int(40e3));
			fprintf(unit," rxd_step=");	
			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) fprintf(unit,"%5i",alct_rxd_delay);
			fprintf(unit,"\n");

			for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
				fprintf(unit,"txd_step=%2i ",alct_txd_delay);
				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
					good_depths=0;
					for (pipe_depth=0; pipe_depth<=15; ++pipe_depth) {
						ibad = alct_rxd_txd_depth[alct_rxd_delay][alct_txd_delay][pipe_depth];
						if (ibad==0) good_depths=good_depths | (1 << pipe_depth);
					}	// close pipe_depth
					fprintf(unit,"%5.4X",good_depths);
				}	// close rxd
				fprintf(unit,"\n");
			}	// close tx

			// Display timing matrix twice in case good area is near an edge
			fprintf(unit,"\n\nRandom loopback good_spots at Tof=%2i alct_rxd_posneg=%1i alct_txd_posneg=%1i, \n",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg);
			fprintf(unit,"scan time per spot %3imsec=%ibx\n",msec,msec*int(40e3));	
			fprintf(unit,"    rxd_step=");
			for (i=0; i<=1; ++i) {for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) fprintf(unit,"%1i",(alct_rxd_delay%10));}
			fprintf(unit,"\n");

			for (i=0; i<=1; ++i) {
				for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
					fprintf(unit,"txd_step=%3i ",alct_txd_delay);
					for (j=0; j<=1; ++j) {
						for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
							pipe_depth=good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay];
							symbol = (pipe_depth >= 0) ? '0'+pipe_depth : '-';	// display "-" for bad data, display ascii-hex pipe depth for good data
							fprintf(unit,"%c",symbol);
						}}	// close rx 1st pass, rx 2nd pass
					fprintf(unit,"\n");
				}}	// close tx 1st pass, tx 2nd pass

			// Close posneg scan loops
		}}
	fprintf(unit,"\nClosed posneg loops");

	// Display good spots pipe depth at this ToF for all combinations of posnegs
	fprintf(unit,"\n\nRandom loopback good_spots pipe depth at Tof=%2i for ALL alct_rxd_posneg | alct_txd_posneg combinations\n",alct_tof_delay);
	fprintf(unit,"Scan time per spot %3imsec=%ibx\n",msec,msec*int(40e3));	
	fprintf(unit,"    rxd_step=");
	for (i=0; i<=1; ++i) {for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) fprintf(unit,"%1i",(alct_rxd_delay%10));}
	fprintf(unit,"\n");

	for (i=0; i<=1; ++i) {
		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			fprintf(unit,"txd_step=%3i ",alct_txd_delay);
			for (j=0; j<=1; ++j) {
				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {

					symbol='-';
					for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
						for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {
							pipe_depth=good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay];
							if (pipe_depth >= 0) symbol='0'+pipe_depth;	// display "-" for bad data, display ascii-hex pipe depth for good data at ANY posneg
						}}	// close posneg local loops

					fprintf(unit,"%c",symbol);
				}}	// close rx 1st pass, rx 2nd pass
			fprintf(unit,"\n");
		}}	// close tx 1st pass, tx 2nd pass

	// Display good spots posnegs at this ToF for all combinations of posnegs
	fprintf(unit,"\n\nRandom loopback good_spots posneg code at Tof=%2i for ALL alct_rxd_posneg | alct_txd_posneg combinations\n",alct_tof_delay);
	fprintf(unit,"Scan time per spot %3imsec=%ibx\n",msec,msec*int(40e3));	
	fprintf(unit,"Posneg code = {rxd_posneg,txd_posneg}\n");	
	fprintf(unit,"    rxd_step=");
	for (i=0; i<=1; ++i) {for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) fprintf(unit,"%1i",(alct_rxd_delay%10));}
	fprintf(unit,"\n");

	good_spots_tof[alct_tof_delay]=0;

	for (i=0; i<=1; ++i) {
		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			fprintf(unit,"txd_step=%3i ",alct_txd_delay);
			for (j=0; j<=1; ++j) {
				for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {

					ngood_depths=0;
					posneg_code =0;

					for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
						for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {
							pipe_depth=good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay];
							if (pipe_depth >= 0) {
								ngood_depths++;
								posneg_code=posneg_code | (alct_rxd_posneg << 1) | (alct_txd_posneg << 0);
							}
						}}	// close posneg local loops

					symbol = (ngood_depths > 0) ? '0'+posneg_code : '-';	// display "-" for bad data, display ascii-hex code for good data
					fprintf(unit,"%c",symbol);
					if (ngood_depths > 0) good_spots_tof[alct_tof_delay]++;
				}}	// close rx 1st pass, rx 2nd pass
			fprintf(unit,"\n");
		}}	// close tx 1st pass, tx 2nd pass

	good_spots_tof[alct_tof_delay]=good_spots_tof[alct_tof_delay]/4;	// correct for having counting 2x in rx and 2x in tx

	// Close ToF scan loop
}

// Display good spots vs tof and posnegs
fprintf(unit,"\nEnd of ToF scan------------------------------------------------------------------------------------\n");
fprintf(unit,"\nRandom Loopback Scan Summary\n");
for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {
	for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
		for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {
			ngood_spots=good_spots_pos_tof[alct_rxd_posneg][alct_txd_posneg][alct_tof_delay];
			fprintf(unit,"tof=%2i alct_rxd_posneg=%1i alct_txd_posneg=%1i good_spots=%3i\n",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg,ngood_spots);
		}}
	fprintf(unit,"\n");
}

// Display good spots vs tof at ALL posnegs
fprintf(unit,"\n\n");
for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {
	ngood_spots=good_spots_tof[alct_tof_delay];
	fprintf(unit,"ToF=%2i good_spots for ALL posnegs = %3i\n",alct_tof_delay,ngood_spots);
}

// Display good depths vs tof at ALL posnegs
fprintf(unit,"\n\n");

for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {

	for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
		for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
			depth_code  =0;
			ngood_depths=0;
			i=0;

			for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
				for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {

					pipe_depth=good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay];
					if (pipe_depth >= 0) {
						depth_code=depth_code | (pipe_depth << i*4);
						ngood_depths++;
					}
					i++;
				}}
			if (ngood_depths > 0)
				fprintf(unit,"ToF=%2i good depths for ALL posnegs rxd=%3i txd=%3i depth_code= %4.4X\n",alct_tof_delay,alct_rxd_delay,alct_txd_delay,depth_code);
		}}}

// Restore default delays and posnegs
fprintf(unit,"\n");
fprintf(unit,"Restoring default alct_tof_delay  = %2i\n",alct_tof_default);
fprintf(unit,"Restoring default alct_rxd_delay  = %2i\n",alct_rxd_default);
fprintf(unit,"Restoring default alct_txd_delay  = %2i\n",alct_txd_default);
fprintf(unit,"Restoring default alct_rxd_posneg = %2i\n",alct_rxd_posneg_default);
fprintf(unit,"Restoring default alct_txd_posneg = %2i\n",alct_txd_posneg_default);

alct_rxd_delay	= alct_rxd_default;
alct_txd_delay	= alct_txd_default;
alct_tof_delay	= alct_tof_default;
alct_rxd_posneg	= alct_rxd_posneg_default;
alct_txd_posneg	= alct_txd_posneg_default;

ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0
phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;				// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);					// Get current state
wr_data = rd_data & 0xFF0F;							// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);			// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

goto L2300;

//------------------------------------------------------------------------------
//	ALCT-TMB Quick Test Series
//------------------------------------------------------------------------------
L231400:
printf("\tQuick test series removed 5.20.2010\n");
pause("\tReturn to sub-menu <cr> ");
goto L2300;

//------------------------------------------------------------------------------
//	CFEB rxd clock delay scan: ALCT|CFEB-to-TMB Teven|Todd
//------------------------------------------------------------------------------
L231500:
//	unit  = stdout;
unit  = log_file;
debug = false;
display_cfeb=true;
//	display_cfeb=false;

fprintf(unit,"CFEB rxd clock delay scan using ALCT as a CFEB:  Teven|Todd\n");

// Get current 3D3444 + phaser delays + posnegs
for (icfeb=0; icfeb<=4; ++icfeb) {
	sprintf(ccfeb, "%1i",icfeb);	// Convert icfeb to string
	scfeb=string(ccfeb);
	cfeb_rxd_delay_default[icfeb]  = phaser_rd(base_adr,string("cfeb_rxd_").append(scfeb),dps_delta);
	cfeb_rxd_posneg_default[icfeb] = posneg_rd(base_adr,string("cfeb_rxd_").append(scfeb));
	cfeb_nbx_delay_default[icfeb]  = cfebbx_rd(base_adr,string("cfeb_nbx_").append(scfeb));
	cfeb_txc_delay_default[icfeb]  = dddstr_rd(base_adr,string("cfeb_txc_").append(scfeb));
}
cfeb_tof_delay_default         = dddstr_rd(base_adr,string("cfeb_tof"));

// Inquire
icfeb=0;
inquire("Select CFEB[0-4]   ?          cr=%3i", minv= 0, maxv=  4, radix=10, icfeb);

cfeb_tof_delay  = cfeb_tof_delay_default;
cfeb_rxd_delay	= cfeb_rxd_delay_default[icfeb];
cfeb_rxd_posneg = cfeb_rxd_posneg_default[icfeb];
cfeb_nbx_delay  = cfeb_nbx_delay_default[icfeb];

inquire("Set cfeb_tof_delay ? -1=scan, cr=%3i", minv=-1, maxv= 12, radix=10, cfeb_tof_delay );
inquire("Set cfeb_rxd_posneg? -1=scan, cr=%3i", minv=-1, maxv=  1, radix=10, cfeb_rxd_posneg);
inquire("Set cfeb_nbx_delay ?          cr=%3i", minv=-1, maxv= 15, radix=10, cfeb_nbx_delay );

// Set CFEB fifo tbins, each one is an independent rx data sample
adr    = base_adr+seq_fifo_adr;
status = vme_read(adr,rd_data);

fifo_mode		= (rd_data >> 0) & 0x07;	// 3 bits
fifo_tbins		= (rd_data >> 3) & 0x1F;	// 5 bits
fifo_pretrig	= (rd_data >> 8) & 0x1F;	// 5 bits

fifo_tbins      = 31;

wr_data = rd_data & 0xF000;			// clear lower bits
	wr_data = wr_data
	| ((fifo_mode    & 0x07) << 0)		// [2:0]
| ((fifo_tbins   & 0x1F) << 3)		// [7:3]
	| ((fifo_pretrig & 0x1F) << 8);		// [12:8]

	status  = vme_write(adr,wr_data);

	// Turn off CCB backplane inputs, turn on L1A emulator
	adr     = ccb_cfg_adr+base_adr;
	wr_data = 0x003D;
	status  = vme_write(adr,wr_data);

	// Enable l1a on sequencer trigger, turn off dmb trigger, set internal l1a delay
	adr     = ccb_trig_adr+base_adr;
	wr_data = 0x0004;
	wr_data = wr_data | (l1a_delay << 8);
	status  = vme_write(adr,wr_data);

	// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x0000;
	wr_data = wr_data | 0x0005;
	wr_data = wr_data | (alct_injector_delay << 5);
	status  = vme_write(adr,wr_data);

	// Set ALCT delay for TMB matching
	adr     = tmbtim_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | 0x0003;
	status  = vme_write(adr,wr_data);

	// Turn on all CFEB inputs so we can check for crosstalk
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;
	wr_data = wr_data | 0x001F;
	status  = vme_write(adr,wr_data);

	// Turn on CFEB enables to over-ride mask_all
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x03FF;		// clear old cfeb_en and source
	wr_data = wr_data | 0x7C00;		// ceb_en_source=0,cfeb_en=1F
	status  = vme_write(adr,wr_data);

	// Turn off internal level 1 accept for sequencer, set l1a window width
	adr     = seq_l1a_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0x00FF;
	wr_data = wr_data | 0x0300;		// l1a window width
	status  = vme_write(adr,wr_data);

	// Turn off CLCT pattern trigger
	adr     = seq_trig_en_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFF00;
	status  = vme_write(adr,wr_data);

	// Clear previous ALCT inject
	adr     = alct_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFFD;
	status  = vme_write(adr,wr_data);

	// Set start_trigger state for FMM
	ttc_cmd = 6;			// start_trigger
	adr     = base_adr+ccb_cmd_adr;
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	ttc_cmd = 1;			// bx0
	wr_data = 0x0003 | (ttc_cmd << 8);
	status  = vme_write(adr,wr_data);
	wr_data = 0x0001;
	status  = vme_write(adr,wr_data);

	// Clear DMB RAM write-address
	adr     = dmb_ram_adr+base_adr;
	wr_data = 0x2000;	//reset RAM write address
	status  = vme_write(adr,wr_data);
	wr_data = 0x0000;	// unreset
	status  = vme_write(adr,wr_data);

	// Set CFEB nbx delay
	adr     = delay0_int_adr+base_adr;
	status  = vme_read(adr,rd_data);			// Get current cfeb0-3
	cfeb_delay_is[0]= (rd_data >>  0) & 0xF;
	cfeb_delay_is[1]= (rd_data >>  4) & 0xF;
	cfeb_delay_is[2]= (rd_data >>  8) & 0xF;
	cfeb_delay_is[3]= (rd_data >> 12) & 0xF;

	adr     = delay1_int_adr+base_adr;
	status  = vme_read(adr,rd_data);			// Get current cfeb4
	cfeb_delay_is[4]= (rd_data >>  0) & 0xF;

	cfeb_delay_is[icfeb]=cfeb_nbx_delay;		// Set new delay for selected cfeb

	adr     = delay0_int_adr+base_adr;			// Write new cfeb0-3
	wr_data = 0;
	wr_data = wr_data | (cfeb_delay_is[0] <<  0);
	wr_data = wr_data | (cfeb_delay_is[1] <<  4);
	wr_data = wr_data | (cfeb_delay_is[2] <<  8);
	wr_data = wr_data | (cfeb_delay_is[3] << 12);
	status  = vme_write(adr,wr_data);

	adr     = delay1_int_adr+base_adr;			// Write new cfeb 4
	wr_data = rd_data & 0xFFF0;
	wr_data = wr_data | (cfeb_delay_is[4] <<   0);
	status  = vme_write(adr,wr_data);

	// Put ALCT into xmit Teven|Todd pattern, seq_cmd[0],[2] share same wire pair
	seq_cmd_bit[0]=1;	seq_cmd_bit[2]=1;		// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
	seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;		// (seq_cmd[0] & seq_cmd[2] == 1} tells ALCT to send Teven|Todd pattern

	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// Get current state
	wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
	wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
	wr_data = wr_data | (seq_cmd_bit[1] << 5);
	wr_data = wr_data | (seq_cmd_bit[2] << 6);
	wr_data = wr_data | (seq_cmd_bit[3] << 7);
	status  = vme_write(adr,wr_data);

	// Scan tof and rxd_posneg, or use input values
	cfeb_tof_delay_min	= (cfeb_tof_delay  < 0) ?  0 : cfeb_tof_delay;
	cfeb_tof_delay_max	= (cfeb_tof_delay  < 0) ? 12 : cfeb_tof_delay;
	cfeb_rxd_posneg_min	= (cfeb_rxd_posneg < 0) ?  0 : cfeb_rxd_posneg;
	cfeb_rxd_posneg_max	= (cfeb_rxd_posneg < 0) ?  1 : cfeb_rxd_posneg;

	for (cfeb_rxd_posneg = cfeb_rxd_posneg_min; cfeb_rxd_posneg <= cfeb_rxd_posneg_max; ++cfeb_rxd_posneg) {
		for (cfeb_tof_delay  = cfeb_tof_delay_min;  cfeb_tof_delay  <= cfeb_tof_delay_max;  ++cfeb_tof_delay ) {

			// Set scanned delays and posnegs
			alct_tof_delay=cfeb_tof_delay;									// ALCT is acting as a cfeb, so use it to delay tof
			ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0

			sprintf(ccfeb, "%1i",icfeb);	// Convert icfeb to string
			scfeb=string(ccfeb);
			posneg_wr(base_adr,string("cfeb_rxd_").append(scfeb),cfeb_rxd_posneg);

			// Clear error accumulators
			for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) {
				for (ibit=0; ibit<=23; ++ibit) {
					cfeb_rxd_bad[cfeb_rxd_delay][ibit]=0;
				}}

			for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) {
				cfeb_sync_1st_err[cfeb_rxd_delay] = 0;
				cfeb_sync_2nd_err[cfeb_rxd_delay] = 0;
			}

			// Step alct rxd clock delay
			fprintf(unit,"\n");	
			fprintf(unit,"Checking 80MHz Teven|Todd data ALCT sends into CFEB%1i\n",icfeb);
			fprintf(unit,"Setting  cfeb_tof_delay  =%2i\n",cfeb_tof_delay);
			fprintf(unit,"Setting  cfeb_rxd_posneg =%2i\n",cfeb_rxd_posneg);
			fprintf(unit,"Using    dps_max         =%2i\n",dps_max);
			fprintf(unit,"Using    dps_delta       =%2i\n",dps_delta);
			fprintf(unit,"\n");	
			fprintf(unit,"Stepping cfeb_rxd_delay...\n");
			//	if (unit!=stdout) fprintf(stdout,"Scanning cfeb_tof_delay=%2i cfeb_rxd_posneg=%1i...wait",cfeb_tof_delay,cfeb_rxd_posneg);
			printf("Scanning cfeb_tof_delay=%2i cfeb_rxd_posneg=%1i...wait\n\n",cfeb_tof_delay,cfeb_rxd_posneg);

			npasses=33;
			for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) { if(debug) fprintf(log_file,"cfeb_rxd_delay=%2i\n",cfeb_rxd_delay);
				for (ipass=1; ipass<=npasses; ++ipass) {

					// Set cfeb_rxd_delay
					phaser_wr(base_adr,string("cfeb_rxd_").append(scfeb),cfeb_rxd_delay,dps_delta);

					// Wait >51 usec for raw hits RAM to write all 2048 addresses
					sleep(1);

					// Fire VME trigger
					adr     = seq_trig_en_adr+base_adr;
					status  = vme_read(adr,rd_data);
					wr_data = rd_data & 0xFF00;
					wr_data	= wr_data | (1 << 7);	// fire vme trigger
					status  = vme_write(adr,wr_data);
					wr_data = rd_data & 0xFF00;		// unfire vme trigger
					status  = vme_write(adr,wr_data);

					// Wait for TMB to read out to DMB
					sleep(1);

					// Get DMB RAM word count and busy bit
					adr       = dmb_wdcnt_adr+base_adr;
					status    = vme_read(adr,rd_data);
					dmb_wdcnt = rd_data & 0x0FFF;
					dmb_busy  = (rd_data >> 14) & 0x0001;

					if (debug) {	
						fprintf(log_file,"\tdmb word count = %4i\n",dmb_wdcnt);
						fprintf(log_file,"\tdmb busy       = %4i\n",dmb_busy);
					}

					if (dmb_busy  != 0) pause ("Can not read RAM: dmb reports busy");
					if (dmb_wdcnt <= 0) pause ("Can not read RAM: dmb reports word count <=0");

					// Write RAM read address to TMB
					for (iadr=0; iadr<=dmb_wdcnt-1; ++iadr) {
						adr     = dmb_ram_adr+base_adr;
						wr_data = iadr & 0xFFFF;
						status  = vme_write(adr,wr_data);

						// Read RAM data from TMB
						adr    = dmb_rdata_adr+base_adr;
						status = vme_read(adr,rd_data);			// read lsbs
						dmb_rdata_lsb=rd_data;

						adr    = dmb_wdcnt_adr+base_adr;
						status = vme_read(adr,rd_data);			// read msbs
						dmb_rdata_msb = (rd_data >> 12) & 0x3;	// rdata msbs

						dmb_rdata = dmb_rdata_lsb | (dmb_rdata_msb << 16);
						vf_data[iadr]=dmb_rdata;

						if (debug) fprintf(log_file,"Adr=%4i Data=%5.5X\n",iadr,dmb_rdata);
					}	// close iadr

					// Clear RAM address for next event
					adr     = dmb_ram_adr+base_adr;
					wr_data = 0x2000;	// reset RAM write address
					status  = vme_write(adr,wr_data);
					wr_data = 0x0000;	// unreset
					status  = vme_write(adr,wr_data);

					// Point to start of CFEB data
					iframe     = 5;
					r_nheaders = vf_data[iframe] & 0x3F;					// Number of header words
					adr_e0b    = r_nheaders;

					if (debug) fprintf(log_file,"r_nheaders=%i\n",r_nheaders);
					if (adr_e0b <=0) pause ("Unreasonable nheaders");

					iframe=19;
					r_ncfebs=			(vf_data[iframe] >>  0) & 0x7;		// Number of CFEBs read out
					r_fifo_tbins=		(vf_data[iframe] >>  3) & 0x1F;		// Number of time bins per CFEB in dump

					if (debug) fprintf(log_file,"r_fifo_tbins=%i\n",r_fifo_tbins);
					if (r_fifo_tbins<=0) pause ("Unreasonable ntbins");

					// Copy triad bits to a holding array
					iframe = adr_e0b+1;										// First raw hits frame for cfeb0

					for (jcfeb  = 0; jcfeb  <= r_ncfebs-1;     ++jcfeb ) {	// Loop over all cfebs so we can see crosstalk
						for (itbin  = 0; itbin  <= r_fifo_tbins-1; ++itbin ) {	// Loop over time bins
							for (ilayer = 0; ilayer <= mxly-1;         ++ilayer) {	// Loop over layers

								rdcid  = (vf_data[iframe] >> 12) & 0x7;					// CFEB ID in the dump
								rdtbin = (vf_data[iframe] >>  8) & 0xF;					// Tbin number in the dump
								hits8  =  vf_data[iframe]        & 0xFF;				// 8 triad block

								for (ids=0; ids< mxds; ++ids) {							// Loop over hits per block
									hits1=(hits8 >> ids) & 0x1;								// Extract 1 hit
									ids_abs=ids+jcfeb*8;									// Absolute distrip id
									read_pat[itbin][ilayer][ids_abs]=hits1;					// hit this distrip
									if (hits1 != 0) nonzero_triads++;						// Count nonzero triads
									dprintf(log_file,"iframe=%4i vf_data=%5.5X hits8=%i jcfeb=%i itbin=%i ids_abs=%i hits1=%i\n",iframe,vf_data[iframe],hits8,jcfeb,itbin,ids_abs,hits1);
								}														// Close ids
								iframe++;												// Next frame
							}														// Close for ilayer
						}														// Close for itbin
					}														// Close for jcfeb

					// Display cfeb and ids column markers
					if (display_cfeb) {
						fprintf(log_file,"\n");
						fprintf(log_file,"     Raw Hits Triads\n");

						fprintf(log_file,"Cfeb-");
						for (jcfeb=0; jcfeb < mxcfeb; ++jcfeb) { fprintf(log_file,"%|");	// display cfeb columms
							for (ids=0;   ids   < mxds;   ++ids  )   fprintf(log_file,"%1.1i",jcfeb);}
						fprintf(log_file,"|\n");

						fprintf(log_file,"Ds---");
						for (jcfeb=0; jcfeb < mxcfeb; ++jcfeb) { fprintf(log_file,"%|",x);	// display ids columns
							for (ids=0;   ids   < mxds;   ++ids  )   fprintf(log_file,"%1.1i",ids%10);}
						fprintf(log_file,"|\n");
						fprintf(log_file,"Ly Tb\n");

						// Display CFEB raw hits
						for (ilayer=0; ilayer <= mxly-1;         ++ilayer)        {
							for (itbin=0;  itbin  <= r_fifo_tbins-1; ++itbin ) { fprintf(log_file,"%1i %2i ",ilayer,itbin);

								for (ids_abs=0;ids_abs<=39;++ids_abs) {
									if (ids_abs%8==0) {fprintf(log_file,"|");}
									fprintf(log_file,"%1.1i",read_pat[itbin][ilayer][ids_abs]);
								}	// close for ids_abs
								fprintf(log_file,"|\n");
							}	// close itbin
							fprintf(log_file,"\n");
						}	// close ilayer
					}	// close display cfeb

					// Map CFEB Signal names into Triad names, use BFA150/CED243 for simulator check
					//	ALCT	Pins	1st Cy 	2nd Cy	Triad_ff	CFEB
					//	rx0		1+	2-	Ly0Tr0	Ly3Tr0	0	24		rx0
					//	rx1		49+	50-	Ly0Tr1	Ly3Tr1	1	25		rx23
					//	rx2		3+	4-	Ly0Tr2	Ly3Tr2	2	26		rx1
					//	rx3		47+	48-	Ly0Tr3	Ly3Tr3	3	27		rx22
					//	rx4		5+	6-	Ly5Tr0	Ly4Tr0	4	28		rx2
					//	rx5		45+	46-	Ly5Tr1	Ly4Tr1	5	29		rx21
					//	rx6		7+	8-	Ly5Tr2	Ly4Tr2	6	30		rx3
					//	rx7		43+	44-	Ly5Tr3	Ly4Tr3	7	31		rx20
					//	rx8		9+	10-	Ly1Tr0	Ly2Tr0	8	32		rx4
					//	rx9		41+	42-	Ly1Tr1	Ly2Tr1	9	33		rx19
					//	rx10	11+	12-	Ly1Tr2	Ly2Tr2	10	34		rx5
					//	rx11	39+	40-	Ly1Tr3	Ly2Tr3	11	35		rx18
					//	rx12	13+	14-	Ly0Tr4	Ly3Tr4	12	36		rx6
					//	rx13	37+	38-	Ly0Tr5	Ly3Tr5	13	37		rx17
					//	rx14	15+	16-	Ly0Tr6	Ly3Tr6	14	38		rx7
					//	rx15	35+	36-	Ly0Tr7	Ly3Tr7	15	39		rx16
					//	rx16	17+	18-	Ly5Tr4	Ly4Tr4	16	40		rx8
					//	rx17	33+	34-	Ly5Tr5	Ly4Tr5	17	41		rx15
					//	rx18	19+	20-	Ly5Tr6	Ly4Tr6	18	42		rx9
					//	rx19	31+	32-	Ly5Tr7	Ly4Tr7	19	43		rx14
					//	rx20	21+	22-	Ly1Tr4	Ly2Tr4	20	44		rx10
					//	rx21	29+	30-	Ly1Tr5	Ly2Tr5	21	45		rx13
					//	rx22	23+	24-	Ly1Tr6	Ly2Tr6	22	46		rx11
					//	rx23	27+	28-	Ly1Tr7	Ly2Tr7	23	47		rx12

					// Each tbin is an independent rx data measurement
					ids_abs=icfeb*8;

					for (itbin=0; itbin<=r_fifo_tbins-1; ++itbin) {

						// First in time map
						cfeb_rxdata_1st[ 0] = read_pat[itbin][0][0+ids_abs];
						cfeb_rxdata_1st[ 1] = read_pat[itbin][0][1+ids_abs];
						cfeb_rxdata_1st[ 2] = read_pat[itbin][0][2+ids_abs];
						cfeb_rxdata_1st[ 3] = read_pat[itbin][0][3+ids_abs];

						cfeb_rxdata_1st[ 4] = read_pat[itbin][5][0+ids_abs];
						cfeb_rxdata_1st[ 5] = read_pat[itbin][5][1+ids_abs];
						cfeb_rxdata_1st[ 6] = read_pat[itbin][5][2+ids_abs];
						cfeb_rxdata_1st[ 7] = read_pat[itbin][5][3+ids_abs];

						cfeb_rxdata_1st[ 8] = read_pat[itbin][1][0+ids_abs];
						cfeb_rxdata_1st[ 9] = read_pat[itbin][1][1+ids_abs];
						cfeb_rxdata_1st[10] = read_pat[itbin][1][2+ids_abs];
						cfeb_rxdata_1st[11] = read_pat[itbin][1][3+ids_abs];

						cfeb_rxdata_1st[12] = read_pat[itbin][0][4+ids_abs];
						cfeb_rxdata_1st[13] = read_pat[itbin][0][5+ids_abs];
						cfeb_rxdata_1st[14] = read_pat[itbin][0][6+ids_abs];
						cfeb_rxdata_1st[15] = read_pat[itbin][0][7+ids_abs];

						cfeb_rxdata_1st[16] = read_pat[itbin][5][4+ids_abs];
						cfeb_rxdata_1st[17] = read_pat[itbin][5][5+ids_abs];
						cfeb_rxdata_1st[18] = read_pat[itbin][5][6+ids_abs];
						cfeb_rxdata_1st[19] = read_pat[itbin][5][7+ids_abs];

						cfeb_rxdata_1st[20] = read_pat[itbin][1][4+ids_abs];
						cfeb_rxdata_1st[21] = read_pat[itbin][1][5+ids_abs];
						cfeb_rxdata_1st[22] = read_pat[itbin][1][6+ids_abs];
						cfeb_rxdata_1st[23] = read_pat[itbin][1][7+ids_abs];

						// Second in time map
						cfeb_rxdata_2nd[ 0] = read_pat[itbin][3][0+ids_abs];
						cfeb_rxdata_2nd[ 1] = read_pat[itbin][3][1+ids_abs];
						cfeb_rxdata_2nd[ 2] = read_pat[itbin][3][2+ids_abs];
						cfeb_rxdata_2nd[ 3] = read_pat[itbin][3][3+ids_abs];

						cfeb_rxdata_2nd[ 4] = read_pat[itbin][4][0+ids_abs];
						cfeb_rxdata_2nd[ 5] = read_pat[itbin][4][1+ids_abs];
						cfeb_rxdata_2nd[ 6] = read_pat[itbin][4][2+ids_abs];
						cfeb_rxdata_2nd[ 7] = read_pat[itbin][4][3+ids_abs];

						cfeb_rxdata_2nd[ 8] = read_pat[itbin][2][0+ids_abs];
						cfeb_rxdata_2nd[ 9] = read_pat[itbin][2][1+ids_abs];
						cfeb_rxdata_2nd[10] = read_pat[itbin][2][2+ids_abs];
						cfeb_rxdata_2nd[11] = read_pat[itbin][2][3+ids_abs];

						cfeb_rxdata_2nd[12] = read_pat[itbin][3][4+ids_abs];
						cfeb_rxdata_2nd[13] = read_pat[itbin][3][5+ids_abs];
						cfeb_rxdata_2nd[14] = read_pat[itbin][3][6+ids_abs];
						cfeb_rxdata_2nd[15] = read_pat[itbin][3][7+ids_abs];

						cfeb_rxdata_2nd[16] = read_pat[itbin][4][4+ids_abs];
						cfeb_rxdata_2nd[17] = read_pat[itbin][4][5+ids_abs];
						cfeb_rxdata_2nd[18] = read_pat[itbin][4][6+ids_abs];
						cfeb_rxdata_2nd[19] = read_pat[itbin][4][7+ids_abs];

						cfeb_rxdata_2nd[20] = read_pat[itbin][2][4+ids_abs];
						cfeb_rxdata_2nd[21] = read_pat[itbin][2][5+ids_abs];
						cfeb_rxdata_2nd[22] = read_pat[itbin][2][6+ids_abs];
						cfeb_rxdata_2nd[23] = read_pat[itbin][2][7+ids_abs];

						// Remap CFEB bits to correct for stupid ALCT signal order and inversion
						cfeb_rxdata_1st_remap[ 0] = cfeb_rxdata_1st[ 0] ^ 0x1;
						cfeb_rxdata_1st_remap[ 1] = cfeb_rxdata_1st[23];
						cfeb_rxdata_1st_remap[ 2] = cfeb_rxdata_1st[ 1] ^ 0x1;
						cfeb_rxdata_1st_remap[ 3] = cfeb_rxdata_1st[22];

						cfeb_rxdata_1st_remap[ 4] = cfeb_rxdata_1st[ 2] ^ 0x1;
						cfeb_rxdata_1st_remap[ 5] = cfeb_rxdata_1st[21];
						cfeb_rxdata_1st_remap[ 6] = cfeb_rxdata_1st[ 3] ^ 0x1;
						cfeb_rxdata_1st_remap[ 7] = cfeb_rxdata_1st[20];

						cfeb_rxdata_1st_remap[ 8] = cfeb_rxdata_1st[ 4] ^ 0x1;
						cfeb_rxdata_1st_remap[ 9] = cfeb_rxdata_1st[19];
						cfeb_rxdata_1st_remap[10] = cfeb_rxdata_1st[ 5] ^ 0x1;
						cfeb_rxdata_1st_remap[11] = cfeb_rxdata_1st[18];

						cfeb_rxdata_1st_remap[12] = cfeb_rxdata_1st[ 6] ^ 0x1;
						cfeb_rxdata_1st_remap[13] = cfeb_rxdata_1st[17];
						cfeb_rxdata_1st_remap[14] = cfeb_rxdata_1st[ 7] ^ 0x1;
						cfeb_rxdata_1st_remap[15] = cfeb_rxdata_1st[16];

						cfeb_rxdata_1st_remap[16] = cfeb_rxdata_1st[ 8] ^ 0x1;
						cfeb_rxdata_1st_remap[17] = cfeb_rxdata_1st[15];
						cfeb_rxdata_1st_remap[18] = cfeb_rxdata_1st[ 9] ^ 0x1;
						cfeb_rxdata_1st_remap[19] = cfeb_rxdata_1st[14];

						cfeb_rxdata_1st_remap[20] = cfeb_rxdata_1st[10] ^ 0x1;
						cfeb_rxdata_1st_remap[21] = cfeb_rxdata_1st[13];
						cfeb_rxdata_1st_remap[22] = cfeb_rxdata_1st[11] ^ 0x1;
						cfeb_rxdata_1st_remap[23] = cfeb_rxdata_1st[12];

						cfeb_rxdata_2nd_remap[ 0] = cfeb_rxdata_2nd[ 0] ^ 0x1;
						cfeb_rxdata_2nd_remap[ 1] = cfeb_rxdata_2nd[23];
						cfeb_rxdata_2nd_remap[ 2] = cfeb_rxdata_2nd[ 1] ^ 0x1;
						cfeb_rxdata_2nd_remap[ 3] = cfeb_rxdata_2nd[22];

						cfeb_rxdata_2nd_remap[ 4] = cfeb_rxdata_2nd[ 2] ^ 0x1;
						cfeb_rxdata_2nd_remap[ 5] = cfeb_rxdata_2nd[21];
						cfeb_rxdata_2nd_remap[ 6] = cfeb_rxdata_2nd[ 3] ^ 0x1;
						cfeb_rxdata_2nd_remap[ 7] = cfeb_rxdata_2nd[20];

						cfeb_rxdata_2nd_remap[ 8] = cfeb_rxdata_2nd[ 4] ^ 0x1;
						cfeb_rxdata_2nd_remap[ 9] = cfeb_rxdata_2nd[19];
						cfeb_rxdata_2nd_remap[10] = cfeb_rxdata_2nd[ 5] ^ 0x1;
						cfeb_rxdata_2nd_remap[11] = cfeb_rxdata_2nd[18];

						cfeb_rxdata_2nd_remap[12] = cfeb_rxdata_2nd[ 6] ^ 0x1;
						cfeb_rxdata_2nd_remap[13] = cfeb_rxdata_2nd[17];
						cfeb_rxdata_2nd_remap[14] = cfeb_rxdata_2nd[ 7] ^ 0x1;
						cfeb_rxdata_2nd_remap[15] = cfeb_rxdata_2nd[16];

						cfeb_rxdata_2nd_remap[16] = cfeb_rxdata_2nd[ 8] ^ 0x1;
						cfeb_rxdata_2nd_remap[17] = cfeb_rxdata_2nd[15];
						cfeb_rxdata_2nd_remap[18] = cfeb_rxdata_2nd[ 9] ^ 0x1;
						cfeb_rxdata_2nd_remap[19] = cfeb_rxdata_2nd[14];

						cfeb_rxdata_2nd_remap[20] = cfeb_rxdata_2nd[10] ^ 0x1;
						cfeb_rxdata_2nd_remap[21] = cfeb_rxdata_2nd[13];
						cfeb_rxdata_2nd_remap[22] = cfeb_rxdata_2nd[11] ^ 0x1;
						cfeb_rxdata_2nd_remap[23] = cfeb_rxdata_2nd[12];

						// Convert to integers
						cfeb_sync_rxdata_1st = 0;
						cfeb_sync_rxdata_2nd = 0;

						for (i=0; i<=23; ++i) {
							cfeb_sync_rxdata_1st = cfeb_sync_rxdata_1st | (cfeb_rxdata_1st_remap[i] << i);
							cfeb_sync_rxdata_2nd = cfeb_sync_rxdata_2nd | (cfeb_rxdata_2nd_remap[i] << i);	
						}

						if (debug) {
							fprintf(log_file,"rxd_1st=%8.7X\n",cfeb_sync_rxdata_1st);
							fprintf(log_file,"rxd_2nd=%8.7X\n",cfeb_sync_rxdata_2nd);
						}

						// Compare received bits to expected pattern
						cfeb_1st_expect = 0x0AAAAAA;	// Teven
						cfeb_2nd_expect = 0x0555555;	// Todd 

						if (cfeb_sync_rxdata_1st != cfeb_1st_expect) cfeb_sync_1st_err[cfeb_rxd_delay]=1;
						if (cfeb_sync_rxdata_2nd != cfeb_2nd_expect) cfeb_sync_2nd_err[cfeb_rxd_delay]=1;

						for (ibit=0; ibit<=23; ++ibit) {
							ibit_1st_expected = (cfeb_1st_expect		>> ibit) & 0x1;
							ibit_2nd_expected = (cfeb_2nd_expect		>> ibit) & 0x1;
							ibit_1st_received = (cfeb_sync_rxdata_1st	>> ibit) & 0x1;
							ibit_2nd_received = (cfeb_sync_rxdata_2nd	>> ibit) & 0x1;
							if ((ibit_1st_expected !=  ibit_1st_received) ||
									(ibit_2nd_expected !=  ibit_2nd_received)) cfeb_rxd_bad[cfeb_rxd_delay][ibit]++;
						}	// Close ibit

						// Close scan loops
					}	// close itbin
					printf("rxd=%2i tof=%2i posneg=%1i passes left=%4i\r",cfeb_rxd_delay,cfeb_tof_delay,cfeb_rxd_posneg,npasses-ipass);
				}	// Close ipass
			}	// Close cfeb_rxd_delay
			fprintf(unit,"\n");

			// Find good spots window width and center in cfeb_rxd_delay for this cfeb_tof_delay and cfeb_rxd_posneg
			ngood		=  0;
			ngood_max	=  0;
			ngood_edge	=  0;
			ngood_center=  0;

			for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) {
				good_spot= !(cfeb_sync_1st_err[cfeb_rxd_delay] || cfeb_sync_2nd_err[cfeb_rxd_delay]);
				good_spots[cfeb_rxd_delay][cfeb_rxd_posneg][0][0][cfeb_tof_delay]=good_spot;
				fprintf(unit,"cfeb_rxd_delay=%2i good_spot=%1i\n",cfeb_rxd_delay,good_spot);
			}

			for (i=0; i<(dps_max*2); ++i) {	// scan delays 0 to 25 twice to span the awkward 25 to 0 wrap around
				cfeb_rxd_delay=i%(dps_max+1);
				good_spot=good_spots[cfeb_rxd_delay][cfeb_rxd_posneg][0][0][cfeb_tof_delay];
				//	printf("cfeb_rxd_delay=%2i good_spot=%1i\n",cfeb_rxd_delay,good_spot);
				//	printf("i             =%2i good_spot=%1i\n",i,good_spot);

				if  (good_spot==1) ngood++;			// this is a good spot
				if ((good_spot==0) && (ngood>0)) {	// good spot just went away, so window preceeds it
					ngood_max  = ngood;
					ngood_edge = i;
					ngood      = 0;
				}	// close if
			}	// close for i

			if (ngood_max>0) ngood_center=(dps_max+ngood_edge-(ngood_max/2))%(dps_max+1);

			window_width[cfeb_rxd_posneg][cfeb_tof_delay]  = ngood_max;
			window_center[cfeb_rxd_posneg][cfeb_tof_delay] = ngood_center;

			fprintf(unit,"Window width  = %2i at tof=%2i posneg=%1i\n",window_width[cfeb_rxd_posneg][cfeb_tof_delay],cfeb_tof_delay,cfeb_rxd_posneg);
			fprintf(unit,"Window center = %2i at tof=%2i posneg=%1i\n",window_center[cfeb_rxd_posneg][cfeb_tof_delay],cfeb_tof_delay,cfeb_rxd_posneg);
			fprintf(unit,"\n");	

			if (unit!=stdout)
				fprintf(stdout,"\nwidth=%2i center=%2i\n",
						window_width[cfeb_rxd_posneg][cfeb_tof_delay],
						window_center[cfeb_rxd_posneg][cfeb_tof_delay]);

			// Display timing window twice in case good area is near 0 or 25ns
			nsamples = npasses*r_fifo_tbins;
			fprintf(unit,"CFEB%1i Scan of cfeb_rxd_delay digital phase shift at ToF=%2i Posneg=%1i\n",icfeb,cfeb_tof_delay,cfeb_rxd_posneg);
			fprintf(unit,"Passes  =%4i\n",npasses);	
			fprintf(unit,"Tbins   =%4i\n",r_fifo_tbins);	
			fprintf(unit,"Samples =%4i\n",nsamples);	
			fprintf(unit,"Width   =%4i\n",ngood_max);
			fprintf(unit,"Center  =%4i\n",ngood_center);
			fprintf(unit,"\n");	
			fprintf(unit,"Rxd\n");	
			fprintf(unit,"Step   Berrs Average 12 0123456789012345678901234\n");	

			for (j=0; j<=1; ++j) {
				for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) {
					nbad=0;
					for (ibit=0; ibit<=23; ++ibit) {nbad=nbad+cfeb_rxd_bad[cfeb_rxd_delay][ibit];}
					avgbad=double(nbad)/double(nsamples);
					nx=int(avgbad);
					if ((nx==0) && (nbad != 0)) nx=1;
					fprintf(unit,"%2i  %8i %7.4f %c%c |",cfeb_rxd_delay,nbad,avgbad,passfail[cfeb_sync_1st_err[cfeb_rxd_delay]],passfail[cfeb_sync_2nd_err[cfeb_rxd_delay]]);
					if (nbad!=0) for(i=1; i<=nx; ++i) fprintf(unit,"x");
					if (cfeb_rxd_delay==window_center[cfeb_rxd_posneg][cfeb_tof_delay]) fprintf(unit,"\t\t\t\t<--Center=%2i  Width=%2i",ngood_center,ngood_max);
					fprintf(unit,"\n");
				}}

			// Display bad bits vs delay
			fprintf(unit,"\nCFEB%1i Cable Pair Errors vs cfeb_rxd_clock Delay Step\n",icfeb);

			fprintf(unit," delay ");
			for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) {fprintf(unit,"%5i",cfeb_rxd_delay);}	// display delay values header
			fprintf(unit,"\n");

			fprintf(unit,"pair   ");
			for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) {fprintf(unit," ----");}
			fprintf(unit,"\n");

			for (ibit=0; ibit<=23; ++ibit) {
				fprintf(unit,"rx[%2i] ",ibit);
				for (cfeb_rxd_delay=0; cfeb_rxd_delay<=dps_max; ++cfeb_rxd_delay) {fprintf(unit,"%5i",cfeb_rxd_bad[cfeb_rxd_delay][ibit]);}
				fprintf(unit,"\n");
			}

			// Close scan loops
		}	// cfeb_tof_delay
	}	// cfeb_rxd_posneg

// Display window center and width vs tof and posneg for plotting
if ((cfeb_rxd_posneg_min != cfeb_rxd_posneg_max) && cfeb_tof_delay_min != cfeb_tof_delay_max) cfeb_rxd_scan_done=true;

fprintf(unit,"\n");
fprintf(unit,"CFEB%1i Scan summary:\n\n",icfeb);
for (cfeb_rxd_posneg = cfeb_rxd_posneg_min; cfeb_rxd_posneg <= cfeb_rxd_posneg_max; ++cfeb_rxd_posneg) {
	for (cfeb_tof_delay  = cfeb_tof_delay_min;  cfeb_tof_delay  <= cfeb_tof_delay_max;  ++cfeb_tof_delay ) {

		fprintf(unit,"Tof=%2i Posneg=%1i Window center=%2i  width=%2i\n",
				cfeb_tof_delay,cfeb_rxd_posneg,
				window_center[cfeb_rxd_posneg][cfeb_tof_delay],
				window_width[cfeb_rxd_posneg][cfeb_tof_delay]);

		newcenter=window_center[cfeb_rxd_posneg][cfeb_tof_delay];
	}
	fprintf(unit,"\n");
}

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;			// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);				// Get current state
wr_data = rd_data & 0xFF0F;						// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);		// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

goto L2300;

//------------------------------------------------------------------------------
//	ALCT effect of alct_tof_delay and posneg on bx0 arrival
//------------------------------------------------------------------------------
L231600:
unit  = stdout;
//	unit  = log_file;
debug = false;

fprintf(unit,"ALCT effect of alct_tof_delay and posneg on bx0 arrival\n");

// Turn off CCB inputs to zero alct_adb_sync and ext_trig
adr     = ccb_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFBF;					// Clear previous l1a
wr_data = wr_data | 0x1;					// Turn off CCB backplane
status  = vme_write(adr,wr_data);

// Turn off CFEB cable inputs
adr     = cfeb_inj_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFE0;					// mask_all=5'b00000
status  = vme_write(adr,wr_data);

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;		// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);			// Get current state
wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

// Select TMB bx0 instead of default TTC bx0
adr     = tmb_trig_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & !(1 << 13);				// turn off [13] mpc_sel_ttc_bx0
status  = vme_write(adr,wr_data);

// Step through alct_tof_delay using table of known alct_rxd_delay, alct_txd_delay values
for (alct_tof_delay=0; alct_tof_delay<=12; ++alct_tof_delay) {

	ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0

	// Set best delay and posneg for ths tof
	if (alct_tof_delay == 0) {alct_rxd_posneg=0; alct_txd_posneg=0; alct_rxd_delay= 3; alct_txd_delay=15;}
	if (alct_tof_delay == 1) {alct_rxd_posneg=0; alct_txd_posneg=0; alct_rxd_delay= 5; alct_txd_delay=18;}
	if (alct_tof_delay == 2) {alct_rxd_posneg=0; alct_txd_posneg=0; alct_rxd_delay= 6; alct_txd_delay=19;}
	if (alct_tof_delay == 3) {alct_rxd_posneg=0; alct_txd_posneg=0; alct_rxd_delay= 9; alct_txd_delay=22;}
	if (alct_tof_delay == 4) {alct_rxd_posneg=0; alct_txd_posneg=1; alct_rxd_delay=12; alct_txd_delay=24;}
	if (alct_tof_delay == 5) {alct_rxd_posneg=0; alct_txd_posneg=1; alct_rxd_delay=13; alct_txd_delay= 0;}
	if (alct_tof_delay == 6) {alct_rxd_posneg=1; alct_txd_posneg=1; alct_rxd_delay=15; alct_txd_delay= 2;}
	if (alct_tof_delay == 7) {alct_rxd_posneg=1; alct_txd_posneg=1; alct_rxd_delay=18; alct_txd_delay= 4;}
	if (alct_tof_delay == 8) {alct_rxd_posneg=1; alct_txd_posneg=1; alct_rxd_delay=19; alct_txd_delay= 6;}
	if (alct_tof_delay == 9) {alct_rxd_posneg=1; alct_txd_posneg=1; alct_rxd_delay=22; alct_txd_delay= 8;}
	if (alct_tof_delay ==10) {alct_rxd_posneg=1; alct_txd_posneg=0; alct_rxd_delay=23; alct_txd_delay=10;}
	if (alct_tof_delay ==11) {alct_rxd_posneg=1; alct_txd_posneg=0; alct_rxd_delay=25; alct_txd_delay=12;}
	if (alct_tof_delay ==12) {alct_rxd_posneg=0; alct_txd_posneg=0; alct_rxd_delay= 1; alct_txd_delay=13;}

	fprintf(unit,"ToF=%2i: Setting alct_rxd_posneg=%1i alct_txd_posneg=%1i alct_rxd_delay=%2i alct_txd_delay=%2i\n",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg,alct_rxd_delay,alct_txd_delay);

	// Adjust phasers and posnegs for this tof
	posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
	posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

	phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
	phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

	// Scan bx0 offset delays looking for alct*tmb bx0 match
	for (i=0; i<=64; ++i) {		// scan bx0+-32
		if (i<32) bxn_offset_pretrig = (3563-i) & 0xFFF;
		else      bxn_offset_pretrig = (i-32  ) & 0xFFF;

		//	for (bxn_offset_pretrig=0; bxn_offset_pretrig<=3563; ++bxn_offset_pretrig) {
		adr     = seq_offset0_adr+base_adr;
		status  = vme_read(adr,rd_data);
		wr_data = rd_data & 0x000F;						// clear old offset
		wr_data = wr_data | (bxn_offset_pretrig << 4);	// set   new offset
		status  = vme_write(adr,wr_data);

		// Resync ALCT and TMB bxns
		adr     = base_adr+ccb_cmd_adr;

		ttc_cmd = 3;		// ttc_resync
		wr_data = 0x0003 | (ttc_cmd << 8);
		status  = vme_write(adr,wr_data);
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);

		ttc_cmd=1;			// bx0
		wr_data = 0x0003 | (ttc_cmd << 8);
		status  = vme_write(adr,wr_data);
		wr_data = 0x0001;
		status  = vme_write(adr,wr_data);

		// Wait at least an LHC orbit for bxn to wrap around to 0 again
		sleep(1);

		// Check for alct_bx0==clct_bx0
		adr     = bx0_delay_adr+base_adr;
		status  = vme_read(adr,rd_data);
		bx0_match = (rd_data >> 10) & 0x1;

		if (bx0_match==1) fprintf(unit,"ToF=%2i bx0_match=%1i at bx0_offset=%4i\n",alct_tof_delay,bx0_match,bxn_offset_pretrig);
		//	if (bx0_match==0) fprintf(unit,"ToF=%2i bx0_match=%1i at bx0_offset=%4i\n",alct_tof_delay,bx0_match,bxn_offset_pretrig);

		// Close scan loops
	}	// close bxn_offset
	}	// close alct_tof_delay

	goto L2300;

	//----------------------------------------------------------------------------------
	//	ALCT Txd|Rxd clock delay scan TMB-to-ALCT TMB Random Loopback using posneg table
	//----------------------------------------------------------------------------------
L231700:
	//	unit  = stdout;
	unit  = log_file;
	debug = false;

	fprintf(unit,"\nALCT Txd|Rxd clock delay scan TMB-to-ALCT TMB Random Loopback, using posneg table\n");

	// Get current 3D3444 + phaser delays
	alct_tof_default = ddd_rd(base_adr, ddd_chip=0, ddd_channel=0);	// alct_tof_delay is chip0 ch0
	alct_txd_default = phaser_rd(base_adr,"alct_txd",dps_delta);
	alct_rxd_default = phaser_rd(base_adr,"alct_rxd",dps_delta);

	// Get current posnegs
	alct_rxd_posneg_default = posneg_rd(base_adr,"alct_rxd");
	alct_txd_posneg_default = posneg_rd(base_adr,"alct_txd");

	// Inquire
	alct_tof_delay  = alct_tof_default;
	msec            = 1000;

	inquire("Set alct_tof_delay ? -1=scan, cr=%3i", minv=-1, maxv=12, radix=10, alct_tof_delay );
	inquire("Millisecs per spot ?          cr=%3i", minv= 0, maxv=1000000, radix=10, msec);

	// Turn off CCB inputs to zero alct_adb_sync and ext_trig
	adr     = ccb_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFBF;					// Clear previous l1a
	wr_data = wr_data | 0x1;					// Turn off CCB backplane
	status  = vme_write(adr,wr_data);

	// Put ALCT into loopback mode, turn off Teven|Todd xmit, seq_cmd[0],[2] share same wire pair
	seq_cmd_bit[0]=0;	seq_cmd_bit[2]=1;		// (seq_cmd[2] &!seq_cmd[0]) puts ALCT into loopback randoms mode
	seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;		// (seq_cmd[3] , seq_cmd[1]) selects alct storage bank 0,1,2

	adr     = alct_cfg_adr+base_adr;
	status  = vme_read(adr,rd_data);			// Get current state
	wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
	wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
	wr_data = wr_data | (seq_cmd_bit[1] << 5);
	wr_data = wr_data | (seq_cmd_bit[2] << 6);
	wr_data = wr_data | (seq_cmd_bit[3] << 7);
	status  = vme_write(adr,wr_data);

	// Scan tof and posnegs, or use input values
	alct_tof_delay_min  = (alct_tof_delay  >= 0) ? alct_tof_delay :  0;
	alct_tof_delay_max  = (alct_tof_delay  >= 0) ? alct_tof_delay : 12;

	for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {

		// Set tof delay
		ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0

		// Display scanned parameters
		fprintf(unit,"\n");
		fprintf(unit,"Scan Setting:\n");
		fprintf(unit,"alct_tof_delay  = %2i\n", alct_tof_delay);
		fprintf(unit,"\n");

		// Step alct rxd and txd clock delays, and transmitter pipeline depth
		fprintf(unit,"Checking 80MHz Random numbers ALCT looped back from TMB\n");

		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
				phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);

				// Look up posnegs and integer delays
				if (alct_rxd_delay > 25) stop ("alct_rxd_delay>25, posneg table requires 0-25");
				if (alct_txd_delay > 25) stop ("alct_txd_delay>25, posneg table requires 0-25");

				alct_rxd_posneg    = alct_rxd_posneg_table[alct_rxd_delay];
				alct_txd_posneg    = alct_txd_posneg_table[alct_txd_delay];
				alct_txd_int_delay = alct_txd_int_delay_table[alct_txd_delay];
				alct_rxd_int_delay = alct_rxd_int_delay_table[alct_rxd_delay];

				adr	    = base_adr+alct_stat_adr;
				status  = vme_read(adr,rd_data);
				wr_data = rd_data & 0x0FFF;								// clear old alc_txd_int_delay 
				wr_data = wr_data | (alct_txd_int_delay << 12);			// set   new alc_txd_int_delay 
				status  = vme_write(adr,wr_data);

				posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
				posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

				//	fprintf(unit,"alct_rxd_posneg = %2i\n", alct_rxd_posneg);
				//	fprintf(unit,"alct_txd_posneg = %2i\n", alct_txd_posneg);

				printf("tof=%2i txd_posneg=%1i rxd_posneg=%1i txd_delay=%2i rxd_delay=%2i txd_int=%2i\r",
						alct_tof_delay,alct_txd_posneg,alct_rxd_posneg,alct_txd_delay,alct_rxd_delay,alct_txd_int_delay);

				for (pipe_depth=0; pipe_depth<=15; ++pipe_depth) {
					alct_sync_rxdata_dly = pipe_depth;

					// Set pipe depth, clear data check flip-flops
					alct_sync_tx_random  = 1;
					alct_sync_clr_err    = 1;

					adr      = alct_sync_ctrl_adr+base_adr;					// Set pipe depth, clear error FFs
					status   = vme_read(adr,rd_data);						// get current
					alct_sync_rxdata_pre = (rd_data >> 12) & 0xF;

					wr_data = (alct_sync_rxdata_dly <<  0) |
						(alct_sync_tx_random  <<  4) |
						(alct_sync_clr_err    <<  5) |
						(alct_sync_rxdata_pre << 12);
					status	= vme_write(adr,wr_data);

					wr_data = wr_data & ~(1 << 5);							// un-clear error FFs, hammer it a few times while system settles from delay changes
					for (i=0; i<=100; ++i) {
						status	= vme_write(adr,wr_data);	
					}

					// Wait for error stats to accumulate
					ibad=0;
					for (i=0; i<=msec; i=i+100) {							// 0 msec first time thru for quick reject of  bad spots
						sleep(i);

						// See if TMB data check flipflops are OK
						adr     = alct_sync_ctrl_adr+base_adr;
						status  = vme_read(adr,rd_data);

						alct_sync_1st_err_ff[0] = (rd_data >> 8) & 0x1;
						alct_sync_2nd_err_ff[0] = (rd_data >> 9) & 0x1;

						ibad = alct_sync_1st_err_ff[0] | alct_sync_2nd_err_ff[0];
						alct_rxd_txd_depth[alct_rxd_delay][alct_txd_delay][pipe_depth]=ibad;

						//	fprintf(unit,"alct_txd_delay=%1X alct_rxd_delay=%1X pipe_depth=%1X ibad=%1i\n",alct_txd_delay,alct_rxd_delay,pipe_depth,ibad);
						if (ibad != 0) break;			// TMB data check already went bad, so done with this rx tx pair
					}	// close for msec

					// Read TMB received demux data just to see whats going on
					if (debug) {
						for (i=0; i<=7; ++i) {			// loop over 1st/2nd demux words	0=1st[14:1],1=1st[28:15]
							adr     = alctfifo1_adr+base_adr;
							wr_data = 0x2000;				// select alct_loopback mode addressing
							wr_data = wr_data | (i << 1);
							status	= vme_write(adr,wr_data);

							adr     = alctfifo2_adr+base_adr;
							status  = vme_read(adr,rd_data);
							alct_demux_rd[i]=rd_data;
						}

						alct_sync_rxdata_1st = alct_demux_rd[0] | (alct_demux_rd[1] << 14);
						alct_sync_rxdata_2nd = alct_demux_rd[2] | (alct_demux_rd[3] << 14);
						alct_sync_expect_1st = alct_demux_rd[4] | (alct_demux_rd[5] << 14);
						alct_sync_expect_2nd = alct_demux_rd[6] | (alct_demux_rd[7] << 14);

						fprintf(unit,"Random Loopback: alct_txd_delay=%2i alct_rxd_delay=%2i", alct_txd_delay,alct_rxd_delay);
						fprintf(unit,"  read 1st=%8.8X 2nd=%8.8X ", alct_sync_rxdata_1st,alct_sync_rxdata_2nd);
						fprintf(unit,"expect 1st=%8.8X 2nd=%8.8X\n",alct_sync_expect_1st,alct_sync_expect_2nd);
					}

					// Close txd,rxd,depth loops...we are still inside ToF loop
				}}}

		// Find correct depth in the transmitter delay pipeline, and count good spots
		ngood_spots=0;
		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
				ngood_depths=0;
				good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay]=-1;
				for (pipe_depth=0; pipe_depth<=15; ++pipe_depth) {
					ibad = alct_rxd_txd_depth[alct_rxd_delay][alct_txd_delay][pipe_depth];
					if (ibad==0) {
						ngood_depths++;
						good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay]=pipe_depth;
						ngood_spots++;
						//	fprintf(log_file,"alct_txd_delay=%3i alct_rxd_delay=%3i pipe_depth=%1X ibad=%1i\n",alct_txd_delay,alct_rxd_delay,pipe_depth,ibad);
					}	// close ibad
				}	// close pipe
				if (ngood_depths >1) printf("Warning: data match found at >1 pipeline depths, should not happen tx=%2i rx=%2i ngood_depths=%2i\n",alct_txd_delay,alct_rxd_delay,ngood_depths);
			}}	// close txt rxd

		//	good_spots_pos_tof[alct_rxd_posneg][alct_txd_posneg][alct_tof_delay]=ngood_spots;
		//	fprintf(unit,"\n\ntof=%2i alct_rxd_posneg=%1i alct_txd_posneg=%1i good_spots=%3i\n",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg,ngood_spots);

		good_spots_pos_tof[0][0][alct_tof_delay]=ngood_spots;
		fprintf(unit,"\n\ntof=%2i good_spots=%3i\n",alct_tof_delay,ngood_spots);

		// Display good depths vs rxd txd
		fprintf(unit,"\nPipeline depth adr bit where RxData=TxData vs alct_txd_delay vs alct_rxd_delay  %3imsec=%ibx\n",msec,msec*int(40e3));
		fprintf(unit," rxd_step=");	
		for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) fprintf(unit,"%5i",alct_rxd_delay);
		fprintf(unit,"\n");

		for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
			fprintf(unit,"txd_step=%2i ",alct_txd_delay);
			for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
				good_depths=0;
				for (pipe_depth=0; pipe_depth<=15; ++pipe_depth) {
					ibad = alct_rxd_txd_depth[alct_rxd_delay][alct_txd_delay][pipe_depth];
					if (ibad==0) good_depths=good_depths | (1 << pipe_depth);
				}	// close pipe_depth
				fprintf(unit,"%5.4X",good_depths);
			}	// close rxd
			fprintf(unit,"\n");
		}	// close tx

		// Display timing matrix twice in case good area is near an edge
		fprintf(unit,"\n\nRandom loopback good_spots at Tof=%2i \n",alct_tof_delay);
		fprintf(unit,"scan time per spot %3imsec=%ibx\n",msec,msec*int(40e3));	
		fprintf(unit,"    rxd_step=");
		for (i=0; i<=1; ++i) {for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) fprintf(unit,"%1i",(alct_rxd_delay%10));}
		fprintf(unit,"\n");

		for (i=0; i<=1; ++i) {
			for (alct_txd_delay=0; alct_txd_delay<=dps_max; ++alct_txd_delay) {
				fprintf(unit,"txd_step=%3i ",alct_txd_delay);
				for (j=0; j<=1; ++j) {
					for (alct_rxd_delay=0; alct_rxd_delay<=dps_max; ++alct_rxd_delay) {
						pipe_depth=good_depth[alct_rxd_delay][alct_rxd_posneg][alct_txd_delay][alct_txd_posneg][alct_tof_delay];
						//	if (pipe_depth!=0)pipe_depth=pipe_depth-alct_rxd_int_delay_table[alct_tof_delay];	// temporarily correct for missing rxd delay stages
						symbol = (pipe_depth >= 0) ? '0'+pipe_depth : '-';	// display "-" for bad data, display ascii-hex pipe depth for good data
						fprintf(unit,"%c",symbol);
					}}	// close rx 1st pass, rx 2nd pass
				fprintf(unit,"\n");
			}}	// close tx 1st pass, tx 2nd pass

		// Close posneg scan loops
		//	}}
		//	fprintf(unit,"\nClosed posneg loops");

		// Close ToF scan loop
}

// Display good spots vs tof and posnegs
fprintf(unit,"\nEnd of ToF scan------------------------------------------------------------------------------------\n");
fprintf(unit,"\nRandom Loopback Scan Summary\n");
for (alct_tof_delay  = alct_tof_delay_min;  alct_tof_delay  <= alct_tof_delay_max;  ++alct_tof_delay ) {
	//	for (alct_rxd_posneg = alct_rxd_posneg_min; alct_rxd_posneg <= alct_rxd_posneg_max; ++alct_rxd_posneg) {
	//	for (alct_txd_posneg = alct_txd_posneg_min; alct_txd_posneg <= alct_txd_posneg_max; ++alct_txd_posneg) {
	//	ngood_spots=good_spots_pos_tof[alct_rxd_posneg][alct_txd_posneg][alct_tof_delay];
	//	fprintf(unit,"tof=%2i alct_rxd_posneg=%1i alct_txd_posneg=%1i good_spots=%3i\n",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg,ngood_spots);

	ngood_spots=good_spots_pos_tof[0][0][alct_tof_delay];
	fprintf(unit,"tof=%2i good_spots=%3i\n",alct_tof_delay,ngood_spots);

	//	}}
	//	fprintf(unit,"\n");
}

// Restore default delays and posnegs
fprintf(unit,"\n");
fprintf(unit,"Restoring default alct_tof_delay  = %2i\n",alct_tof_default);
fprintf(unit,"Restoring default alct_rxd_delay  = %2i\n",alct_rxd_default);
fprintf(unit,"Restoring default alct_txd_delay  = %2i\n",alct_txd_default);
fprintf(unit,"Restoring default alct_rxd_posneg = %2i\n",alct_rxd_posneg_default);
fprintf(unit,"Restoring default alct_txd_posneg = %2i\n",alct_txd_posneg_default);

alct_rxd_delay	= alct_rxd_default;
alct_txd_delay	= alct_txd_default;
alct_tof_delay	= alct_tof_default;
alct_rxd_posneg	= alct_rxd_posneg_default;
alct_txd_posneg	= alct_txd_posneg_default;

ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0
phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;				// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);					// Get current state
wr_data = rd_data & 0xFF0F;							// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);			// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

goto L2300;

//----------------------------------------------------------------------------------
//	CFEB bad-bits register tests
//----------------------------------------------------------------------------------
L231800:
//	unit  = stdout;
unit  = log_file;
//	debug = false;
debug = true;

fprintf(unit,"\n\tCFEB bad-bits register tests\n\n");

//----------------------------------------------------------------------------------
// CFEB bad-bits register tests: See how long it takes a bit to go bad
//----------------------------------------------------------------------------------
// Get default nbx
adr     = cfeb_badbits_timer_adr+base_adr;			// CFEB  Bad Bit Check Interval
status  = vme_read(adr,rd_data);					// Get TMB current value
cfeb_badbits_nbx = rd_data;

// Turn on CFEB inputs
adr     = cfeb_inj_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFE0;							// mask off all cfebs
wr_data = wr_data | 0x1F;							// turn on  all cfebs
status  = vme_write(adr,wr_data);

// Loop over nbx wait times
for (ibit=0; ibit<=15; ++ibit) {
	nbx=(1<<ibit);

	// Set nbx for bad bits to be high
	adr     = cfeb_badbits_timer_adr+base_adr;			// CFEB  Bad Bit Check Interval
	wr_data = nbx;										// Set a new nbx wait value
	status  = vme_write(adr,wr_data);

	// Reset bad bits
	adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
	status  = vme_read(adr,rd_data);					// read current
	rd_data = rd_data & 0xFFE0;							// clean out old reset bits
	wr_data = rd_data | 0x001F;							// assert reset[4:0]
	status  = vme_write(adr,wr_data);					// write reset
	wr_data = rd_data;									// retrieve original register contents
	status  = vme_write(adr,wr_data);					// write un-reset

	// Loop over VME reads to cause a 16usec wait per cycle
	for (icycle=0; icycle<=1000; ++icycle) {

		// Get current bad cfeb bits register
		adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
		status  = vme_read(adr,rd_data);

		cfeb_badbits_reset   = (rd_data >>  0) & 0x1F;
		cfeb_badbits_block   = (rd_data >>  5) & 0x1F;
		cfeb_badbits_found   = (rd_data >> 10) & 0x1F;
		cfeb_badbits_blocked = (rd_data >> 15) & 0x1;

		// Check for bits gone bad
		if (cfeb_badbits_found!=0) {
			fprintf(unit,"\tcfeb_badbits_nbx=%6i: bad bits detected at vme cycle=%6i %6ibx\n",nbx,icycle,icycle*16*40);
			break;
		}	// close if cfeb
	}	// close icycle

	if (cfeb_badbits_found==0) pause("\tBad bits NOT detected...wtf?");

	//	Close loops
}	// close nbx

// Restore default nbx
adr     = cfeb_badbits_timer_adr+base_adr;
wr_data = cfeb_badbits_nbx;
status  = vme_write(adr,wr_data);

//----------------------------------------------------------------------------------
// CFEB bad-bits register tests: Check bad bits one CFEB at a time
//----------------------------------------------------------------------------------
// Giant loop over CFEBs
for (jcfeb=0; jcfeb<=4; ++jcfeb) {
	fprintf(unit,"\tEnable CFEB%1i Cable Inputs\n\n",jcfeb);

	// Turn off CFEB inputs
	adr     = cfeb_inj_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFE0;			// mask off all cfebs
	wr_data = wr_data | (1 << jcfeb);	// turn on jth cfeb
	status  = vme_write(adr,wr_data);

	// Enable bad bit blocking
	adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
	status  = vme_read(adr,rd_data);
	wr_data = rd_data | (0x1F << 5);
	status  = vme_write(adr,wr_data);

	// Reset bad bits
	adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
	status  = vme_read(adr,rd_data);					// read current
	rd_data = rd_data & 0xFFE0;							// clean out old reset bits
	wr_data = rd_data | 0x001F;							// assert reset[4:0]
	status  = vme_write(adr,wr_data);					// write reset
	wr_data = rd_data;									// retrieve original register contents
	status  = vme_write(adr,wr_data);					// restore register with resets off

	// Wait for the bad bit high-too-long timer to cycle, 3564bx=89usec
	sleep(1);

	// Display bad cfeb bits register
	adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
	status  = vme_read(adr,rd_data);

	cfeb_badbits_reset   = (rd_data >>  0) & 0x1F;
	cfeb_badbits_block   = (rd_data >>  5) & 0x1F;
	cfeb_badbits_found   = (rd_data >> 10) & 0x1F;
	cfeb_badbits_blocked = (rd_data >> 15) & 0x1;

	adr     = cfeb_badbits_timer_adr+base_adr;			// CFEB  Bad Bit Check Interval
	status  = vme_read(adr,rd_data);
	cfeb_badbits_nbx = rd_data;

	fprintf(unit,"\tcfeb_badbits_reset   = %4.2X\n",cfeb_badbits_reset);
	fprintf(unit,"\tcfeb_badbits_block   = %4.2X\n",cfeb_badbits_block);
	fprintf(unit,"\tcfeb_badbits_found   = %4.2X\n",cfeb_badbits_found);
	fprintf(unit,"\tcfeb_badbits_blocked = %4.1X\n",cfeb_badbits_blocked);
	fprintf(unit,"\tcfeb_badbits_nbx     = %4.4X=%4.4d\n",cfeb_badbits_nbx,cfeb_badbits_nbx);

	// Read bad cfeb bits map from VME registers
	for (icfeb =0; icfeb <=4; ++icfeb ) {					// loop over cfebs
		for (ilayer=0; ilayer<=5; ++ilayer) {					// Loop over layers

			adr_offset = 3*(icfeb*2) + 2*(ilayer/2); 				// Read 2 layers per VME address, 3 adrs per cfeb

			if ((ilayer%2)==0) {									// Read VME for even layers
				adr     = cfeb0_badbits_ly01_adr+adr_offset+base_adr;
				status  = vme_read(adr,rd_data);
				cfeb_badbits[icfeb][ilayer  ] = (rd_data >> 0) & 0xFF;
				cfeb_badbits[icfeb][ilayer+1] = (rd_data >> 8) & 0xFF;
				//	fprintf(unit,"icfeb=%1i ilayer=%1i cfeb_badbits=%4.4X\n",icfeb,ilayer,rd_data);
			}	// close if ilayer

		}}	// close for icfeb,ilayer

	// Display cfeb and ids column markers
	fprintf(unit,"\n");
	fprintf(unit,"\tCFEB bad bits DiStrips\n\n");

	fprintf(unit,"\tCFEB----");
	for (icfeb=0; icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|");	// display cfeb columms
		for (ids=0;   ids   < mxds;   ++ids  )   fprintf(unit,"%1.1i",icfeb);}
	fprintf(unit,"|\n");

	fprintf(unit,"\tDiStrip-");
	for (icfeb=0; icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|",x);	// display ids columns
		for (ids=0;   ids   < mxds;   ++ids  )   fprintf(unit,"%1.1i",ids%10);}
	fprintf(unit,"|\n");

	fprintf(unit,"\t        ");
	for (icfeb=0; icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|",x);	// display spacer columns
		for (ids=0;   ids   < mxds;   ++ids  )   fprintf(unit,"-");}
	fprintf(unit,"|\n");

	// Display bad cfeb bits
	for (ilayer=0; ilayer<=mxly-1; ++ilayer) {
		fprintf(unit,"\tLayer %1i ",ilayer);

		for (icfeb=0;  icfeb < mxcfeb; ++icfeb ) {
			for (ids=0;    ids   < mxds;   ++ids   ) {

				if (ids==0) {fprintf(unit,"|");}
				ibadbit=(cfeb_badbits[icfeb][ilayer] >> ids) & 0x1;	// extract 1 distrip bit on this cfeb,layer
				fprintf(unit,"%1.1x",ibadbit);
			}}	// close ids,icfeb

		fprintf(unit,"|\n");
	}	// close ilayer

	// Close giant cfeb loop
	fprintf(unit,"\n");
}	// close jcfeb

//----------------------------------------------------------------------------------
// CFEB bad-bits register tests: Check bad bits one CFEB bit at a time
//----------------------------------------------------------------------------------
// Get current thresholds
adr    = seq_clct_adr+base_adr;
status = vme_read(adr,rd_data);

triad_persist		= (rd_data >>  0) & 0xF;	// 4 bits
hit_thresh_pretrig	= (rd_data >>  4) & 0x7;	// 3 bits
dmb_thresh_pretrig	= (rd_data >>  7) & 0x7;	// 3 bits
hit_thresh_postdrift= (rd_data >> 10) & 0x7;	// 3 bits
drift_delay			= (rd_data >> 13) & 0x3;	// 2 bits

adr    = temp0_adr+base_adr;
status = vme_read(adr,rd_data);

pid_thresh_pretrig  = (rd_data >> 2) & 0xF;	// 4 bits
pid_thresh_postdrift= (rd_data >> 6) & 0xF;	// 4 bits

adr    = layer_trig_adr+base_adr;
status = vme_read(adr,rd_data);
lyr_thresh_pretrig = (rd_data >> 1) & 0xF;	// 4 bits

// Lower thresholds to trigger on single bit hits
hit_thresh_pretrig   = 1;
hit_thresh_postdrift = 1;

adr    = seq_clct_adr+base_adr;
status = vme_read(adr,rd_data);	
wr_data = rd_data;									// Current thresholds
wr_data = wr_data & ~(0x7 <<  4);					// clear hit_thresh_pretrig
wr_data = wr_data & ~(0x7 << 10);					// clear hit_thresh_postdrift

wr_data = wr_data | (hit_thresh_pretrig   <<  4);	// set hit_thresh_pretrig
wr_data = wr_data | (hit_thresh_postdrift << 10);	// set hit_thresh_postdrift
status  = vme_write(adr,wr_data);

// Get L1A delay
adr     = ccb_trig_adr+base_adr;
status  = vme_read(adr,rd_data);
l1a_delay = (rd_data >> 8) & 0xFF;

// Turn off CFEB cable inputs
adr     = cfeb_inj_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFE0;		// mask_all=5'b00000
status  = vme_write(adr,wr_data);

// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
adr     = alct_inj_adr+base_adr;
status  = vme_read(adr,rd_data);

alct_injector_delay=13;

wr_data = rd_data & 0x0000;
wr_data = wr_data | 0x0005;
wr_data = wr_data | (alct_injector_delay << 5);
status  = vme_write(adr,wr_data);

// Turn on CFEB enables to over-ride mask_all
adr     = seq_trig_en_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0x03FF;			// clear old cfeb_en and source
wr_data = wr_data | 0x7C00;			// ceb_en_source=0,cfeb_en=1F
status  = vme_write(adr,wr_data);

// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
adr     = ccb_trig_adr+base_adr;
wr_data = 0x0004;
wr_data = wr_data | (l1a_delay << 8);
status  = vme_write(adr,wr_data);

// Turn off CCB backplane inputs, turn on L1A emulator, do this after turning off cfeb and alct cable inputs
adr     = ccb_cfg_adr+base_adr;
wr_data = 0x0000;
wr_data = wr_data | 0x0001;	// ccb_ignore_rx
wr_data = wr_data | 0x0004;	// ccb_int_l1a_en
wr_data = wr_data | 0x0008;	// ccb_status_oe_vme
wr_data = wr_data | 0x0010;	// alct_status_en
wr_data = wr_data | 0x0020;	// clct_status_en
status  = vme_write(adr,wr_data);

// Turn off internal level 1 accept for sequencer, set l1a window width
adr     = seq_l1a_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0x00FF;
wr_data = wr_data | 0x0300;			//  l1a window width
status  = vme_write(adr,wr_data);

// Set pid_thresh_pretrig, pid_thresh_postdrift
adr    = temp0_adr+base_adr;
status = vme_read(adr,rd_data);

wr_data=rd_data & 0xFC03;
wr_data=wr_data | (pid_thresh_pretrig   << 2);	// 4 bits
wr_data=wr_data | (pid_thresh_postdrift << 6);	// 4 bits
status = vme_write(adr,wr_data);

// Set start_trigger state for FMM
//	ttc_cmd=1	// bx0
//	ttc_cmd=3	// l1reset
//	ttc_cmd=6	// start_trigger
//	ttc_cmd=7	// stop_trigger
adr     = base_adr+ccb_cmd_adr;

ttc_cmd = 3;			// l1reset
wr_data = 0x0003 | (ttc_cmd << 8);
status  = vme_write(adr,wr_data);
wr_data = 0x0001;
status  = vme_write(adr,wr_data);

ttc_cmd = 6;			// start_trigger
wr_data = 0x0003 | (ttc_cmd << 8);
status  = vme_write(adr,wr_data);
wr_data = 0x0001;
status  = vme_write(adr,wr_data);

ttc_cmd = 1;			// bx0
wr_data = 0x0003 | (ttc_cmd << 8);
status  = vme_write(adr,wr_data);
wr_data =0x0001;
status  = vme_write(adr,wr_data);

// Pass loop
for (ipass=1; ipass<=3; ++ipass) {					// 1st pass checks individual bad bits, 2nd pass marks them all bad, 3rd pass shouldnt trigger
	//	for (ipass=1; ipass<=1; ++ipass) {					// 1st pass checks individual bad bits, 2nd pass marks them all bad, 3rd pass shouldnt trigger

	if (ipass==1) fprintf(unit,"\n1st Pass:  Check individual bad bit mapping\n");
	if (ipass==2) fprintf(unit,"\n2nd Pass:  Mark all bits bad\n");
	if (ipass==3) fprintf(unit,"\n3rd Pass:  Should not trigger on bad bits\n");

	if (unit!=stdout) {
		if (ipass==1) fprintf(stdout,"\n1st Pass:  Check individual bad bit mapping\n");
		if (ipass==2) fprintf(stdout,"\n2nd Pass:  Mark all bits bad\n");
		if (ipass==3) fprintf(stdout,"\n3rd Pass:  Should not trigger on bad bits\n");
	}

	// Set nbx for bad bits to be high
	nbx     = 1;
	adr     = cfeb_badbits_timer_adr+base_adr;			// CFEB  Bad Bit Check Interval
	wr_data = nbx;										// Set a new nbx wait value
	status  = vme_write(adr,wr_data);

	// Enable bad bit blocking
	adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & ~(0x1F << 5);					// Clear out old enables
	wr_data = rd_data |  (0x1F << 5);					// Turn  on  new enables
	status  = vme_write(adr,wr_data);

	// Loop over cfeb input bits
	for (icfeblp  = 0; icfeblp  <= 4; ++icfeblp ) {					// loop over cfebs
		for (ilayerlp = 0; ilayerlp <= 5; ++ilayerlp) {					// Loop over layers
			for (idslp    = 0; idslp    <= 7; ++idslp   ) {

				if (unit!=stdout) fprintf(unit,"\tTesting cfeb%1i layer%1i ids%1i\n",icfeblp,ilayerlp,idslp);
				printf(     "\tTesting cfeb%1i layer%1i ids%1i\n",icfeblp,ilayerlp,idslp);

				// Reset bad bits on 1st pass to check individual bit mapping
				if ((ipass==1) || ((ipass==2) && (icfeblp==0) && (ilayerlp==0) && (idslp==0)))
				{
					adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
					status  = vme_read(adr,rd_data);					// read current
					rd_data = rd_data & 0xFFE0;							// clean out old reset bits
					wr_data = rd_data | 0x001F;							// assert reset[4:0]
					status  = vme_write(adr,wr_data);					// write reset
					wr_data = rd_data;									// retrieve original register contents
					status  = vme_write(adr,wr_data);					// restore register with resets off
				}

				// Construct triad image with just 1 hit
				for (ilayer   = 0; ilayer   <=  5; ++ilayer  ) {
					for (itbin    = 0; itbin    <= 31; ++itbin   ) {
						for (idistrip = 0; idistrip <= 39; ++idistrip) {
							itriad[itbin][idistrip][ilayer]=0;
						}}}

				itbin    = 0;
				idistrip = idslp+(8*icfeblp);
				ilayer   = ilayerlp;

				if (nbx==1)
					itriad[0][idistrip][ilayer]=1;

				if (nbx!=1) {
					itriad[1][idistrip][ilayer]=1;
					itriad[2][idistrip][ilayer]=1;
					itriad[3][idistrip][ilayer]=1;
					itriad[4][idistrip][ilayer]=1;
				}

				// Display triad image
				if (debug) {
					fprintf(unit,"\n\tTriad image tbin0\n");
					itbin=0;
					for (ilayer   = 0; ilayer   <=  5; ++ilayer  ) {
						fprintf(unit,"\tilayer%1i ",ilayer);
						for (idistrip = 0; idistrip <= 39; ++idistrip) {
							ibit=itriad[itbin][idistrip][ilayer];
							fprintf(unit,"%1i",ibit);
						}	// close idistrip
						fprintf(unit,"\n");
					}	// close ilayer
				}	// close if debug

				// Pack triads into pattern RAM
				wr_data=0;

				for (ilayer=0; ilayer<=5; ilayer=ilayer+2) {
					iram=ilayer/2;
					for (itbin=0; itbin<=31; ++itbin) {
						for (idistrip=0; idistrip<=39; ++idistrip) {
							icfeb=idistrip/8;
							idslocal=idistrip%8;
							if (idslocal==0) wr_data=0; 		// clear for each cfeb

							ibit=itriad[itbin][idistrip][ilayer];
							wr_data=wr_data | (ibit << idslocal);

							ibit=itriad[itbin][idistrip][ilayer+1];
							wr_data=wr_data | (ibit << (idslocal+8));

							pat_ram[itbin][iram][icfeb]=wr_data;
							dprintf(log_file,"pat_ram tbin=%2i ram=%1i wr_data=%4.4X\n",itbin,iram,wr_data);
						}	// close ilayer
					}	// close itbin
				}	// close idistrip

				// Write muon RAM data
				for (icfeb = 0; icfeb <= 4;  ++icfeb) {
					for (iram  = 0; iram  <= 2;  ++iram ) {
						for (itbin = 0; itbin <= 31; ++itbin) {

							wadr   = itbin;
							adr    = cfeb_inj_adr+base_adr;					// Select injector RAM
							status = vme_read(adr,rd_data);					// Get current data

							wr_data = rd_data & 0xFC1F;						// Zero FEB select
							febsel  = (1 << icfeb);							// Select FEB
							wr_data = wr_data | (febsel << 5) | 0x7C00;		// Set febsel, enable injectors
							status  = vme_write(adr,wr_data);				// Select FEB

							adr     = cfeb_inj_adr_adr+base_adr;
							ren     = 0;
							wen     = 0;
							wr_data = wen | (ren << 2) | (wadr << 6);
							status  = vme_write(adr,wr_data);				// Set RAM Address + No write

							adr     = cfeb_inj_wdata_adr+base_adr;
							wr_data = pat_ram[itbin][iram][icfeb];
							wr_data_mem = wr_data;
							status  = vme_write(adr,wr_data);				// Store RAM Data

							adr     = cfeb_inj_adr_adr+base_adr;
							wen     = iram;
							wr_data = wen | (ren << 2) | (wadr << 6);
							status  = vme_write(adr,wr_data);				// Set RAM Address + Assert write

							wen     = 0;
							wr_data = wen | (ren << 2) | (wadr << 6);
							status  = vme_write(adr,wr_data);				// Set RAM Address + No write

							ren     = iram;
							wr_data = wen | (ren << 2) | (wadr << 6);
							status  = vme_write(adr,wr_data);				// Set RAM Address + Read enable

							adr     = cfeb_inj_rdata_adr+base_adr;			// Read RAM data
							status  = vme_read(adr,rd_data);

							if (rd_data != wr_data_mem) {
								printf("\tInj Err: cfeb%1i key%3i RAM%2i Tbin%2i wr=%4.4X rd=%4.4X\n",icfeb,ikey,iram,itbin,wr_data_mem,rd_data);
								pause ("borked");
							}

						}	// close itbin
					}	// close iram
				}	// close icfeb

				// Fire CLCT+ALCT Injectors
				adr     = cfeb_inj_adr+base_adr;
				status  = vme_read(adr,rd_data);
				wr_data = rd_data | 0x8000;		// fire injector
				status  = vme_write(adr,wr_data);
				wr_data = rd_data & 0x7FFF;		// unfire
				status  = vme_write(adr,wr_data);

				// Wait for the bad bit high-too-long timer to cycle, 3564bx=89usec
				sleep(1);

				// Display bad cfeb bits register
				adr     = cfeb_badbits_ctrl_adr+base_adr;			// CFEB  Bad Bit Control/Status
				status  = vme_read(adr,rd_data);

				cfeb_badbits_reset   = (rd_data >>  0) & 0x1F;
				cfeb_badbits_block   = (rd_data >>  5) & 0x1F;
				cfeb_badbits_found   = (rd_data >> 10) & 0x1F;
				cfeb_badbits_blocked = (rd_data >> 15) & 0x1;

				adr     = cfeb_badbits_timer_adr+base_adr;			// CFEB  Bad Bit Check Interval
				status  = vme_read(adr,rd_data);
				cfeb_badbits_nbx = rd_data;

				fprintf(unit,"\tcfeb_badbits_reset   = %4.2X\n",cfeb_badbits_reset);
				fprintf(unit,"\tcfeb_badbits_block   = %4.2X\n",cfeb_badbits_block);
				fprintf(unit,"\tcfeb_badbits_found   = %4.2X\n",cfeb_badbits_found);
				fprintf(unit,"\tcfeb_badbits_blocked = %4.1X\n",cfeb_badbits_blocked);
				fprintf(unit,"\tcfeb_badbits_nbx     = %4.4X=%4.4d\n",cfeb_badbits_nbx,cfeb_badbits_nbx);

				// Read bad cfeb bits map from VME registers
				for (icfeb  = 0; icfeb  <=4; ++icfeb ) {				// loop over cfebs
					for (ilayer = 0; ilayer <=5; ++ilayer) {				// Loop over layers

						adr_offset = 3*(icfeb*2) + 2*(ilayer/2); 				// Read 2 layers per VME address, 3 adrs per cfeb

						if ((ilayer%2)==0) {									// Read VME for even layers
							adr     = cfeb0_badbits_ly01_adr+adr_offset+base_adr;
							status  = vme_read(adr,rd_data);
							cfeb_badbits[icfeb][ilayer  ] = (rd_data >> 0) & 0xFF;
							cfeb_badbits[icfeb][ilayer+1] = (rd_data >> 8) & 0xFF;
							//	fprintf(unit,"icfeb=%1i ilayer=%1i cfeb_badbits=%4.4X\n",icfeb,ilayer,rd_data);
						}	// close if ilayer

					}}	// close for icfeb,layer

				// Compare bad cfeb bits map to whats expected
				for (icfeb  = 0; icfeb  <= 4; ++icfeb ) {				// loop over cfebs
					for (ilayer = 0; ilayer <= 5; ++ilayer) {				// Loop over layers
						for (ids    = 0; ids    <= 7; ++ids   ) {				// Loop over local distrips
							iword  = cfeb_badbits[icfeb][ilayer];
							ibit   = (iword >> ids) & 0x1;

							if ((icfeb==icfeblp) && (ilayer==ilayerlp) && (ids==idslp)) {	// This is the 1 bit expected to be hit
								if (ipass==1) iword_expect=(1<<ids);			// 1st pass hits 1 bit
								if (ipass==2) iword_expect=iword | (1<<ids);	// 2nd pass accumulates bits
								if (ipass==3) iword_expect=0xFF;				// 3rd pass accumulated all bits
								if ((ibit != 1) || (iword != iword_expect)) fprintf(unit,"Bad bits error at icfeb=%1i ilayer=%1i ids=%1i iword=%4.4X expected %4.4X, ibit=%1i expected 1\n",icfeb,ilayer,ids,iword,iword_expect,ibit);
							}
							if (((icfeb!=icfeblp) || (ilayer!=ilayerlp)) && (ipass==1))	{					// This is NOT the 1 bit expected to be hit
								iword_expect=0;
								if (iword !=iword_expect) fprintf(unit,"Bad bits error at icfeb=%1i ilayer=%1i ids=%1i iword=%4.4X expected %4.4X\n",icfeb,ilayer,ids,iword,iword_expect);
							}

						}}}	// close loops

				// Display cfeb and ids column markers
				fprintf(unit,"\n\tCFEB----");
				for (icfeb=0;  icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|");	// display cfeb columms
					for (ids  =0;  ids   < mxds;   ++ids  )   fprintf(unit,"%1.1i",icfeb);}
				fprintf(unit,"|\n");

				fprintf(unit,"\tDiStrip-");
				for (icfeb=0; icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|",x);	// display ids columns
					for (ids  =0; ids   < mxds;   ++ids  )   fprintf(unit,"%1.1i",ids%10);}
				fprintf(unit,"|\n");

				fprintf(unit,"\t        ");
				for (icfeb=0; icfeb < mxcfeb; ++icfeb) { fprintf(unit,"%|",x);	// display spacer columns
					for (ids  =0; ids   < mxds;   ++ids  )   fprintf(unit,"-");}
				fprintf(unit,"|\n");

				// Display bad cfeb bits
				for (ilayer=0; ilayer<=mxly-1; ++ilayer) {
					fprintf(unit,"\tLayer %1i ",ilayer);

					for (icfeb=0;  icfeb < mxcfeb; ++icfeb ) {
						for (ids  =0;  ids   < mxds;   ++ids   ) {

							if (ids==0) {fprintf(unit,"|");}
							ibadbit=(cfeb_badbits[icfeb][ilayer] >> ids) & 0x1;	// extract 1 distrip bit on this cfeb,layer
							fprintf(unit,"%1.1x",ibadbit);
						}}	// close ids,icfeb

					fprintf(unit,"|\n");
				}	// close ilayer

				// Close big key-stepping loops
			}	// close ids
		}	// close ilayer
	}	// close icfeb
}	// close ipass
// Done
goto L2300;

//------------------------------------------------------------------------------
// ALCT effect of txd,rxd,tof,posnegs on bx0 arrival at TMB
//------------------------------------------------------------------------------
L231900:
//	unit  = stdout;
unit  = log_file;
debug = false;

printf("\t19: ALCT effect of txd,rxd,tof,posnegs on bx0 arrival at TMB\n");

// Turn off CCB inputs to zero alct_adb_sync and ext_trig
adr     = ccb_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFBF;					// Clear previous l1a
wr_data = wr_data | 0x1;					// Turn off CCB backplane
status  = vme_write(adr,wr_data);

// Turn off CFEB cable inputs
adr     = cfeb_inj_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFE0;					// mask_all=5'b00000
status  = vme_write(adr,wr_data);

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;		// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);			// Get current state
wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

// Select TMB bx0 instead of default TTC bx0
adr     = tmb_trig_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & !(1 << 13);				// turn off [13] mpc_sel_ttc_bx0
status  = vme_write(adr,wr_data);

// Step through the entire phase space
//	for (alct_tof_delay  =0; alct_tof_delay  <=12; ++alct_tof_delay ) {
//	for (alct_txd_delay  =0; alct_txd_delay  <=25; ++alct_txd_delay ) {
//	for (alct_rxd_delay  =0; alct_rxd_delay  <=25; ++alct_rxd_delay ) {
//	for (alct_txd_posneg =0; alct_txd_posneg <= 1; ++alct_txd_posneg) {
//	for (alct_rxd_posneg =0; alct_rxd_posneg <= 1; ++alct_rxd_posneg) {

// Scan alct_rxd_delay and posneg
for (alct_rxd_posneg =0; alct_rxd_posneg <= 1; ++alct_rxd_posneg) {
	for (alct_rxd_delay  =0; alct_rxd_delay  <=25; ++alct_rxd_delay ) {

		// Set tof and alct_txd to compensate, at tof=0 alct_txd_delay=15
		if      (alct_rxd_delay == 0) {alct_tof_delay = 11; alct_txd_posneg=0; alct_txd_delay=12;}	// extrapolated
		else if (alct_rxd_delay == 1) {alct_tof_delay = 12; alct_txd_posneg=0; alct_txd_delay=13;}
		else if (alct_rxd_delay == 2) {alct_tof_delay =  0; alct_txd_posneg=0; alct_txd_delay=14;}	// extrapolated
		else if (alct_rxd_delay == 3) {alct_tof_delay =  0; alct_txd_posneg=0; alct_txd_delay=15;}
		else if (alct_rxd_delay == 4) {alct_tof_delay =  1; alct_txd_posneg=0; alct_txd_delay=16;}	// extrapolated
		else if (alct_rxd_delay == 5) {alct_tof_delay =  1; alct_txd_posneg=0; alct_txd_delay=18;}
		else if (alct_rxd_delay == 6) {alct_tof_delay =  2; alct_txd_posneg=0; alct_txd_delay=19;}
		else if (alct_rxd_delay == 7) {alct_tof_delay =  2; alct_txd_posneg=0; alct_txd_delay=20;}	// extrapolated
		else if (alct_rxd_delay == 8) {alct_tof_delay =  3; alct_txd_posneg=0; alct_txd_delay=21;}	// extrapolated
		else if (alct_rxd_delay == 9) {alct_tof_delay =  3; alct_txd_posneg=0; alct_txd_delay=22;}
		else if (alct_rxd_delay ==10) {alct_tof_delay =  3; alct_txd_posneg=0; alct_txd_delay=22;}	// extrapolated
		else if (alct_rxd_delay ==11) {alct_tof_delay =  4; alct_txd_posneg=1; alct_txd_delay=23;}	// extrapolated
		else if (alct_rxd_delay ==12) {alct_tof_delay =  4; alct_txd_posneg=1; alct_txd_delay=24;}
		else if (alct_rxd_delay ==13) {alct_tof_delay =  5; alct_txd_posneg=1; alct_txd_delay= 0;}
		else if (alct_rxd_delay ==14) {alct_tof_delay =  5; alct_txd_posneg=1; alct_txd_delay= 1;}	// extrapolated
		else if (alct_rxd_delay ==15) {alct_tof_delay =  6; alct_txd_posneg=1; alct_txd_delay= 2;}
		else if (alct_rxd_delay ==16) {alct_tof_delay =  6; alct_txd_posneg=1; alct_txd_delay= 3;}	// extrapolated
		else if (alct_rxd_delay ==17) {alct_tof_delay =  7; alct_txd_posneg=1; alct_txd_delay= 4;}	// extrapolated
		else if (alct_rxd_delay ==18) {alct_tof_delay =  7; alct_txd_posneg=1; alct_txd_delay= 4;}
		else if (alct_rxd_delay ==19) {alct_tof_delay =  8; alct_txd_posneg=1; alct_txd_delay= 6;}
		else if (alct_rxd_delay ==20) {alct_tof_delay =  8; alct_txd_posneg=1; alct_txd_delay= 6;}	// extrapolated
		else if (alct_rxd_delay ==21) {alct_tof_delay =  9; alct_txd_posneg=1; alct_txd_delay= 7;}	// extrapolated
		else if (alct_rxd_delay ==22) {alct_tof_delay =  9; alct_txd_posneg=1; alct_txd_delay= 8;}
		else if (alct_rxd_delay ==23) {alct_tof_delay = 10; alct_txd_posneg=0; alct_txd_delay=10;}
		else if (alct_rxd_delay ==24) {alct_tof_delay = 11; alct_txd_posneg=0; alct_txd_delay=11;}	// extrapolated
		else if (alct_rxd_delay ==25) {alct_tof_delay = 11; alct_txd_posneg=0; alct_txd_delay=12;}
		else	stop("moron");

		fprintf(unit,  "ToF=%2i: Setting alct_rxd_posneg=%1i alct_txd_posneg=%1i alct_rxd_delay=%2i alct_txd_delay=%2i\n",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg,alct_rxd_delay,alct_txd_delay);
		if (unit!=stdout)
			fprintf(stdout,"ToF=%2i: Setting alct_rxd_posneg=%1i alct_txd_posneg=%1i alct_rxd_delay=%2i alct_txd_delay=%2i\r",alct_tof_delay,alct_rxd_posneg,alct_txd_posneg,alct_rxd_delay,alct_txd_delay);

		// Adjust phasers, posnegs, tof
		ddd_wr(base_adr, ddd_chip=0, ddd_channel=0, alct_tof_delay);	// alct_tof_delay is chip0 ch0

		posneg_wr(base_adr,"alct_rxd",alct_rxd_posneg);
		posneg_wr(base_adr,"alct_txd",alct_txd_posneg);

		phaser_wr(base_adr,"alct_rxd",alct_rxd_delay,dps_delta);
		phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);

		// Scan bx0 offset delays looking for alct*tmb bx0 match
		nmatches = 0;
		bxn_offset_at_match = -99;

		for (i=-32; i<=31; ++i) {		// scan bx0+-32
			bxn_offset_signed= i;
			if (i<0) bxn_offset_pretrig = (3564+i) & 0xFFF;
			else     bxn_offset_pretrig = (i     ) & 0xFFF;

			adr     = seq_offset0_adr+base_adr;
			status  = vme_read(adr,rd_data);
			wr_data = rd_data & 0x000F;						// clear old offset
			wr_data = wr_data | (bxn_offset_pretrig << 4);	// set   new offset
			status  = vme_write(adr,wr_data);

			// Resync ALCT and TMB bxns
			adr     = base_adr+ccb_cmd_adr;

			ttc_cmd = 3;		// ttc_resync
			wr_data = 0x0003 | (ttc_cmd << 8);
			status  = vme_write(adr,wr_data);
			wr_data = 0x0001;
			status  = vme_write(adr,wr_data);

			ttc_cmd=1;			// bx0
			wr_data = 0x0003 | (ttc_cmd << 8);
			status  = vme_write(adr,wr_data);
			wr_data = 0x0001;
			status  = vme_write(adr,wr_data);

			// Wait at least an LHC orbit for bxn to wrap around to 0 again
			sleep(1);

			// Check for alct_bx0==clct_bx0
			adr     = bx0_delay_adr+base_adr;
			status  = vme_read(adr,rd_data);
			bx0_match = (rd_data >> 10) & 0x1;

			if (bx0_match==1)
			{
				nmatches++;
				bxn_offset_at_match=i;
				fprintf(unit,  "ToF=%2i bx0_match=%1i at bxn_offset=%4i signed=%4i\n",alct_tof_delay,bx0_match,bxn_offset_pretrig,bxn_offset_signed);
				if (unit!=stdout) {
					if (nmatches==1)
						fprintf(stdout,"\n");
					fprintf(stdout,"ToF=%2i bx0_match=%1i at bxn_offset=%4i signed=%4i\n",alct_tof_delay,bx0_match,bxn_offset_pretrig,bxn_offset_signed);
				}}

			// close bxn scan
		}	// close bxn_offset

		if (nmatches==1) bx0_match_state="OK";
		else             bx0_match_state="BAD";

		fprintf(scn_file,"ToF=%2i alct_rxd_delay=%2i alct_rxd_posneg=%1i bx0_offset_at_match=%3i nmatches=%2i %3i %3i state=%s\n",alct_tof_delay,alct_rxd_delay,alct_rxd_posneg,bxn_offset_at_match,nmatches,alct_rxd_delay*10,bxn_offset_at_match+287+16,bx0_match_state.c_str());
		fprintf(unit,    "ToF=%2i alct_rxd_delay=%2i alct_rxd_posneg=%1i bx0_offset_at_match=%3i nmatches=%2i %3i %3i state=%s\n",alct_tof_delay,alct_rxd_delay,alct_rxd_posneg,bxn_offset_at_match,nmatches,alct_rxd_delay*10,bxn_offset_at_match+287+16,bx0_match_state.c_str());
		if (unit!=stdout)
			fprintf(stdout,  "ToF=%2i bx0_offset_at_match=%3i nmatches=%2i state=%s\n",alct_tof_delay,bxn_offset_at_match,nmatches,bx0_match_state.c_str());

		// close phase space scan
		//	}	// close alct_tof_delay
		//	}	// close alct_txd_delay
		//	}	// close alct_txd_posneg
			}	// close alct_rxd_posneg
}	// close alct_rxd_delay

// Done
if (unit!=stdout) fprintf(stdout,"\n");
goto L2300;

//------------------------------------------------------------------------------
// CFEB Blocked CFEB distrips walking hcm test
//------------------------------------------------------------------------------
L232000:
//	unit  = stdout;
unit  = log_file;
debug = false;

printf("\t20: CFEB Blocked CFEB distrips walking hcm test\n");

// Turn off CCB backplane inputs, turn on L1A emulator
adr     = ccb_cfg_adr+base_adr;
wr_data = 0x003D;
status  = vme_write(adr,wr_data);

// Enable sequencer trigger, turn off dmb trigger, set internal l1a delay
l1a_delay = 119;
adr     = ccb_trig_adr+base_adr;
wr_data = 0x0004;
wr_data = wr_data | (l1a_delay << 8);
status  = vme_write(adr,wr_data);

// Turn ON CFEB cable inputs, otherwise they fill up the blocked bits table
adr     = cfeb_inj_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFE0;					// mask_all=5'b00000
wr_data = wr_data | 0x1F;
status  = vme_write(adr,wr_data);

// Turn off ALCT cable inputs, enable synchronized alct+clct triggers
adr     = alct_inj_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0x0000;
wr_data = wr_data | 0x0005;
wr_data = wr_data | (alct_injector_delay << 5);
status  = vme_write(adr,wr_data);

// Take ALCT firmware out of loopback mode
seq_cmd_bit[0]=0;	seq_cmd_bit[2]=0;		// (seq_cmd[0] | seq_cmd[2] == 1) puts ALCT into loopback mode
seq_cmd_bit[1]=0;	seq_cmd_bit[3]=0;

adr     = alct_cfg_adr+base_adr;
status  = vme_read(adr,rd_data);			// Get current state
wr_data = rd_data & 0xFF0F;					// Clear bits[7:4] alct_seq_cmd[3:0]
wr_data = wr_data | (seq_cmd_bit[0] << 4);	// New seq_cmd
wr_data = wr_data | (seq_cmd_bit[1] << 5);
wr_data = wr_data | (seq_cmd_bit[2] << 6);
wr_data = wr_data | (seq_cmd_bit[3] << 7);
status  = vme_write(adr,wr_data);

// Enable blocked bits readout
adr    = base_adr+seq_fifo_adr;
status = vme_read(adr,rd_data);
bcb_read_enable = (rd_data >> 15) & 0x1;	// 1 bit
bcb_read_enable = 1;						// set to 1 manually until it becomes the default
wr_data = rd_data | (bcb_read_enable << 15);
status = vme_write(adr,wr_data);

// Turn off CLCT pattern trigger
adr     = seq_trig_en_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFF00;
status  = vme_write(adr,wr_data);

// Clear previous ALCT inject
adr     = alct_inj_adr+base_adr;
status  = vme_read(adr,rd_data);
wr_data = rd_data & 0xFFFD;
status  = vme_write(adr,wr_data);

// Set start_trigger state for FMM
ttc_cmd = 6;			// start_trigger
adr     = base_adr+ccb_cmd_adr;
wr_data = 0x0001;
status  = vme_write(adr,wr_data);
wr_data = 0x0003 | (ttc_cmd << 8);
status  = vme_write(adr,wr_data);
wr_data = 0x0001;
status  = vme_write(adr,wr_data);

ttc_cmd = 1;			// bx0
wr_data = 0x0003 | (ttc_cmd << 8);
status  = vme_write(adr,wr_data);
wr_data = 0x0001;
status  = vme_write(adr,wr_data);

// Clear DMB RAM write-address
adr     = dmb_ram_adr+base_adr;
wr_data = 0x2000;	//reset RAM write address
status  = vme_write(adr,wr_data);
wr_data = 0x0000;	// unreset
status  = vme_write(adr,wr_data);

// Clear HCMs, packed 2 layers per word, 3 words per cfeb, on even numbered addresses
wr_data=0xFFFF;

for (icfeb  = 0; icfeb  <= 4; ++icfeb        ) {
	for (ilayer = 0; ilayer <= 5; ilayer=ilayer+2) {

		hcm_adr = hcm001_adr + 2*(icfeb*3 + ilayer/2);
		adr     = hcm_adr+base_adr;
		status  = vme_write(adr,wr_data);

	}}

// Hot channel mask walking 1, hcms packed 2 layers per word, 3 words per cfeb
for (icfeb  = 0; icfeb  <= 4; ++icfeb ) {	// loop over cfebs
	for (ilayer = 0; ilayer <= 5; ++ilayer) {	// Loop over layers
		for (ids    = 0; ids    <= 7; ++ids   ) {	// Loop over local distrips

			hcm_adr = hcm001_adr + 2*(icfeb*3 + ilayer/2);

			if (ilayer%2==0) hcm_data = (1 << (ids+0));	// layers 0,2,4 set bit[ids]=1
			else             hcm_data = (1 << (ids+8));	// layers 1,3,5

			adr     = hcm_adr+base_adr;
			wr_data = ~hcm_data;						// invert, hcm[ids]=0, rest of mask=1
			status  = vme_write(adr,wr_data);

			printf("\tcfeb%1i layer%1i ids%1i adr=%6.6X data=%4.4X\r",icfeb,ilayer,ids,adr,wr_data);

			// Fire VME trigger
			adr     = seq_trig_en_adr+base_adr;
			status  = vme_read(adr,rd_data);
			wr_data = rd_data & 0xFF00;
			wr_data	= wr_data | (1 << 7);	// fire vme trigger
			status  = vme_write(adr,wr_data);
			wr_data = rd_data & 0xFF00;		// unfire vme trigger
			status  = vme_write(adr,wr_data);

			// Get DMB RAM word count and busy bit
			adr       = dmb_wdcnt_adr+base_adr;
			status    = vme_read(adr,rd_data);
			dmb_wdcnt = rd_data & 0x0FFF;
			dmb_busy  = (rd_data >> 14) & 0x0001;

			fprintf(log_file,"Raw Hits Dump: ikey=%3i\n",ikey);
			fprintf(log_file,"word count = %4i\n",dmb_wdcnt);
			fprintf(log_file,"busy       = %4i\n",dmb_busy);

			if (dmb_busy) {
				fprintf(log_file,"Can not read RAM: dmb reports busy\n");
				fprintf(stdout,  "Can not read RAM: dmb reports busy\n");
				pause("wtf?");
			}

			if (dmb_wdcnt <= 0) {
				fprintf(log_file,"Can not read RAM: dmb reports word count <=0\n");
				fprintf(stdout,  "Can not read RAM: dmb reports word count <=0\n");
				pause("wtf?");
			}

			// Write RAM read address to TMB
			for (i=0; i<=dmb_wdcnt-1; ++i) {
				adr     = dmb_ram_adr+base_adr;
				wr_data = i & 0xffff;
				status  = vme_write(adr,wr_data);

				// Read RAM data from TMB
				adr    = dmb_rdata_adr+base_adr;
				status = vme_read(adr,rd_data);				// read lsbs
				dmb_rdata_lsb = rd_data;

				adr    = dmb_wdcnt_adr+base_adr;
				status = vme_read(adr,rd_data);				// read msbs
				dmb_rdata_msb = (rd_data >> 12) & 0x3;		// rdata msbs
				dmb_rdata     = dmb_rdata_lsb | (dmb_rdata_msb << 16);

				vf_data[i]=dmb_rdata;
				fprintf(log_file,"Adr=%5i Data=%6.5X\n",i,dmb_rdata);
			} // close i

			// Clear RAM address for next event
			adr     = dmb_ram_adr+base_adr;
			wr_data = 0x2000;	// reset RAM write address
			status  = vme_write(adr,wr_data);
			wr_data = 0x0000;	// unreset
			status  = vme_write(adr,wr_data);

			// Readout raw hits
			decode_readout(vf_data,dmb_wdcnt,err_check=false);

			// Check blocked bits match what was set

			// Put HCM back to normal
			adr     = hcm_adr+base_adr;
			wr_data = 0xFFFF;
			status  = vme_write(adr,wr_data);

			// Close hcm walking 1 loops
		}	// close for icfeb
	}	// close for ilayer
}	// close for ids

// Done
printf("\n");
goto L2300;
}
//------------------------------------------------------------------------------
//	Boot register test: Infinite loop, use scope to check
//------------------------------------------------------------------------------
void L2400() {
	//L2400:

	ipass = 0;
	//	goto L2420;

	// write randoms to boot reg, check boot reads back ok
L2410:
	ipass = ipass+1;

	for (ibit=0; ibit<=13; ++ibit) {
		rnd     = rand()/(float(RAND_MAX)+1); 
		wr_data = int(65536*rnd);
		if (ipass == 1) wr_data = (1 << ibit);		// Walking 1 on first pass

		wr_data = wr_data & 0xFFFB;					// Don't toggle tck, nooooo
		status  = vme_write(boot_adr,wr_data);		// Write boot
		status	= vme_read (base_adr,rd_data);		// Read  base to purge bit3 buffers
		status	= vme_read (boot_adr,rd_data);		// Read  boot

		rd_data = rd_data & 0x3FFB;					// Remove read-only bits
		wr_data = wr_data & 0x3FFB;

		if (rd_data != wr_data) {
			fprintf(log_file,"\tFailed Boot bit=%2i wr=%8.8X rd=%8.8X\n",ibit,wr_data,rd_data);
			fprintf(stdout,  "\tFailed Boot bit=%2i wr=%8.8X rd=%8.8X\n",ibit,wr_data,rd_data);
			pause ("continue");
		} // close if
	} // close do ibit

	if ((ipass==1) || (ipass%1000==0)) printf("\tboot pass=%10i\n",ipass);
	goto L2410;

	// toggle tck forever
L2420:
	ipass = ipass+1;
	tck    = ipass & 0x1;					// toggles lsb = tck

	wr_data = 0x0083 | (tck << 2);			// tms=tdi=1,vme/usr=1
	status	= vme_write(boot_adr,wr_data);	// Write boot
	goto L2420;
}
//------------------------------------------------------------------------------
//	RAT Full Auto Test:
//	Determine VME slots to use, check for reference TMB
//------------------------------------------------------------------------------
void L2500() {
L2500:

	// Determine which computer we are using, superfluous since we use LCL adr for Ref TMB
	printf("\tRAT Tests Started on host %s\n",scomputer_name.c_str());

	if (scomputer_name.compare("X34")==0) {	// We be on my PC, use slots 5,6
		islot_ref = 27;							// loopback board left  slot
		islot_dut = 6;}							// loopback board right slot
	else {									// We be on your PC, use slots 7,8
		islot_ref = 27;
		islot_dut = 8;
	}

	// Base addresses for TMB
	base_adr_ref = (islot_ref<<19);
	boot_adr_ref = base_adr_ref | 0x070000;

	base_adr     = base_adr_ref;
	boot_adr     = boot_adr_ref;

	base_adr_dut = base_adr_ref;
	boot_adr_dut = boot_adr_ref;

	base_adr_global = (tmb_global_slot<<19);
	boot_adr_global = base_adr_global | 0x070000;

	//	Reset TMB+RAT to get all registers to default
	status = vme_read(boot_adr,rd_data);		// Get current boot reg
	printf("\tBoot reg=%4.4X\n",rd_data);

	wr_data = 0x0200;
	status  = vme_write(boot_adr_ref,wr_data);	// Assert hard reset
	wr_data = 0x0000;
	status  = vme_write(boot_adr_ref,wr_data);	// De-assert hard reset
	sleep(800);									// Wait for TMBs to reload, mSecs

	// Check for log file environment variable
	lenv = 81;
	lenv = ExpandEnvironmentStrings("%RAT_LogFolder%",rat_logfolder,lenv);
	logfolder = string(rat_logfolder);

	if (lenv==0) {
		printf("\tSystem Environment Variable RAT_LogFolder not defined.\n");
		printf("\tSuggest you set RAT_LogFolder=D:\\RAT2005\\Testlogs\\\n\n");}
	else {
		printf("\tEnvironment variable RAT_LogFolder=%s\n",rat_logfolder);
	}

	// Check for reference TMB in left slot
	adr   = base_adr_ref+vme_dsn_adr;
	itype = 0;
	dsn_rd(adr,itype,dsn);
	dow_crc(dsn,icrc);

	idsn = 0;
	for (i=1;i<=4;++i) idsn=idsn|(dsn[i]<<(8*(i-1)));	// Convert dsn to integer, 2 hex digits at a time, skip [0]=mfg
	sprintf(cdsn,"%7.7X",idsn);							// Convert dsn to character

	if (icrc!=dsn[7]|| icrc==0) sdsn="BadDSNf";			// dsn gave bad  crc
	else                        sdsn=string(cdsn);		// dsn gave good crc

	tmb_ref_skip   = false;
	tmb_ref_exists = false;
	if (icrc==dsn[7] && icrc!=0) tmb_ref_exists = true;	// ref board exists

	// Read ref boot register expected in slot 27
	boot = 0;

	if (tmb_ref_exists)
	{
		adr    = (27<<19) + tmb_boot_adr;	
		status = vme_read(adr,rd_data);
		boot   = rd_data;

		fprintf(stdout,"\tReference TMB boot data = %4.4X\n",boot);
		fprintf(log_file,"Reference TMB boot data = %4.4X\n",boot);

		boot = rd_data & 0x4000;	// usually c000, but high bit is tdo, unpredictable
	}

	if (tmb_ref_exists) 
	{
		fprintf(stdout,"\tTMB Reference Board   in slot %2i-LCL TMBdsn=%s\n",islot_ref,sdsn.c_str());
		fprintf(log_file,"TMB Reference Board   in slot %2i-LCL TMBdsn=%s\n",islot_ref,sdsn.c_str());

		if (boot!=0x4000) {
			printf("\tYou must set SW2/1 LCL VME Adr=27 on Reference TMB\n");
			pause("<cr> to continue");
			return;
		}
	}
	else {
		printf("\tTMB Reference Board NOT found in slot %2i-LCL, RAT can not be tested\n",islot_ref);
		pause("<cr> to continue");
		return;
	}

	// Check reference TMB firmware is DEBUG version
	adr    = base_adr_ref;
	status = vme_read(adr,rd_data);
	firmware_type_ref = rd_data & 0xF;

	if (firmware_type_ref!=0xD) {
		tmb_ref_exists =  false;
		printf("\n\tReference TMB has wrong firmware type %X1.1\n",firmware_type_ref);
		pause("<cr> to continue");
		return;
	}

	// Read RAT dsn, set posneg=0, enable rat dsn
	adr     = vme_ratctrl_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rat_ctrl_data = rd_data;
	wr_data = rd_data & 0xFFFD;	// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en
	wr_data = wr_data | 0x0010;	// 	enable dsn bit
	status  = vme_write(adr,wr_data);

	// Set Loop-mode register to idle
	loopstate = 0x0AAF;
	adr     = vme_loopbk_adr+base_adr;
	wr_data = loopstate;
	status  = vme_write(adr,wr_data);

	// Loop over dsn chips, rat is last
	itype = 2;
	adr   = base_adr_ref+vme_dsn_adr;
	dsn_rd(adr,itype,dsn);
	dow_crc(dsn,icrc);

	idsn = 0;
	for (i=1;i<=4;++i) idsn=idsn|(dsn[i]<<(8*(i-1)));	// Convert dsn to integer, 2 hex digits at a time, skip [0]=mfg
	sprintf(cdsn,"%7.7X",idsn);							// Convert dsn to character

	if (icrc!=dsn[7]|| icrc==0) sdsn="BadDSNf";			// dsn gave bad  crc
	else                        sdsn=string(cdsn);		// dsn gave good crc

	// Put posneg back
	adr     = vme_ratctrl_adr+base_adr;
	wr_data = rat_ctrl_data;
	status  = vme_write(adr,wr_data);

	fprintf(stdout,"\tStarting tests on RAT in slot %2i-LCL RATdsn=%s\n",islot_ref,sdsn.c_str());
	fprintf(log_file,"Starting tests on RAT in slot %2i-LCL RATdsn=%s\n",islot_ref,sdsn.c_str());

	// Clear error flags
	pause_on_fail = false;

	for (i=1; i<=rat_ntests; ++i) {
		rat_npassed[i]  = 0;
		rat_nfailed[i]  = 0;
		rat_nskipped[i] = 0;
	}

	// Get RAT board ID
	printf("\tEnter RAT Board ID Number [5xxx]: ");
	gets(line);
	n = strlen(line);
	sscanf(line,"%i",&i);

	if (n> 0) rat_board_id = i;
	if (n<=0) rat_board_id = 5000;

	if (rat_board_id==5000) printf("\tUsing default board ID 5000\n");

	if (rat_board_id>5600 || rat_board_id<5000) {
		printf("\tBoard ID must be 5000-5600\n");
		pause("<cr> to continue");
		goto L2500;
	}

	//------------------------------------------------------------------------------
	//	RAT Full Auto Test:
	//	Open log file
	//------------------------------------------------------------------------------
	// Look for a previous test file version in current folder
	for (iver=1; iver<=99; ++iver) {
		sprintf(cfver,"%2.2i",iver);	// Convert version number to string
		sfver=string(cfver);

		sprintf(cbid,"%4.4i",rat_board_id);

		if (icrc!=dsn[7]|| icrc==0) {	// RAT board has issues
			printf("\n");
			printf("\tTest RAT has bad Digital Serial %s\n",sdsn.c_str());
			inquirb("\tContinue anyway? [y|n]? cr=%3c",bans);
			if (!bans) {
				printf("\n\tTest cancelled\n");
				return;
			}
		}

		// Check if file exists
		test_file_name = logfolder;
		test_file_name = test_file_name.append(string("rat_")).append(cbid).append(string("_")).append(sdsn).append(string("_")).append(sfver).append(string(".txt"));

		test_file = fopen(test_file_name.c_str(),"r");	// Check if this version already exists
		if (test_file==NULL) goto L2502;				// No, so we use this version number
		fclose(test_file);								// Yes, so close it, proceed to next version number
	}	// close for iver

	// Already have 99 versions of this test file, kinda excessive, you should delete the older versions
	pause("Log file version > 99, why? Delete old versions, then restart test.");
	return;

	// Open RAT test log file
L2502:
	if (test_file!=NULL) fclose(test_file);
	test_file = fopen(test_file_name.c_str(),"w");

	if (test_file!=NULL) {printf("\tOpened file    %s\n",test_file_name.c_str());}
	else                 {printf("\tFailed to open %s\n",test_file_name.c_str()); pause("\tPerhaps folder does not exist"); return;}

	// Insert the date
	_strtime(timestr);
	_strdate(datestr);

	fprintf(test_file,"RAT AutoTest started on %s %s\n",datestr,timestr);
	fprintf(test_file,"Logfile %s\n\n",test_file_name.c_str());

	fprintf(stdout, "\tRAT AutoTest started on %s %s\n",datestr,timestr);
	fprintf(stdout, "\tLogfile %s\n\n",test_file_name.c_str());

	// Auto pass counter
	ipass_full_auto=0;
L2505:
	ipass_full_auto++;

	//------------------------------------------------------------------------------
	//	RAT Full Auto Test:
	//	Check Digital Serial Number
	//------------------------------------------------------------------------------
	//L25010:
	itest=1;

	i='ERR!';
	j='OK  ';

	if (icrc==dsn[7] && icrc!=0) {
		i='OK  ';
		rat_npassed[itest]=1;}
	else {
		rat_nfailed[itest]=1;
	}

	ck(string("Digital Serial ").append(dsn_chip[itype]),i,j);

	if (rat_nfailed[itest]==0) rat_npassed[itest]=1;
	aokf(string("RAT Digital Serial ").append(sdsn),itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Voltage Discriminators
	//------------------------------------------------------------------------------
	//L25020:
	itest=2;

	// Initialze looback registers, take RAT out of loop-back cuz it will toast if ya dont
	adr     = vme_loopbk_adr+base_adr;
	wr_data = loopstate;
	status	= vme_write(adr,wr_data);

	//	Partially, stress ccb gtl drivers for current measurements. Loopback regulator can't handle full load
	//	wr_data = 0xFEFF;					// All bits 0, except 8, tmb reset
	wr_data = 0x00FF;					// 1/2 bits 0
	wr_data = (~wr_data) & 0x0FFFF;		// invert
	adr     = ccb_txa_adr+base_adr;
	status	= vme_write(adr,wr_data);
	wr_data = 0xFFFF;					// bits 17:16
	wr_data = (~wr_data) & 0x0000F;		// invert
	adr     = ccb_txb_adr+base_adr;
	status	= vme_write(adr,wr_data);

	//	Read voltage discriminators
	adr    = vme_adc_adr+base_adr;
	status = vme_read(adr,rd_data);

	vstat_5p0v = ok[(rd_data >> 0) & 0x1];
	vstat_3p3v = ok[(rd_data >> 1) & 0x1];
	vstat_1p8v = ok[(rd_data >> 2) & 0x1];
	vstat_1p5v = ok[(rd_data >> 3) & 0x1];
	tcrit      = ok[(rd_data >> 4) & 0x1];

	fprintf(test_file,"\t5.0V TMB  status=%s\n",vstat_5p0v.c_str());
	fprintf(test_file,"\t3.3V TMB  status=%s\n",vstat_3p3v.c_str());
	fprintf(test_file,"\t1.8V RAT  status=%s\n",vstat_1p8v.c_str());
	fprintf(test_file,"\t1.5V TMB  status=%s\n",vstat_1p5v.c_str());
	fprintf(test_file,"\tTcrit     status=%s\n",tcrit.c_str());

	statid[1] = cks("5.0V  Status bit",(int)vstat_5p0v[0],(int)'O');
	statid[2] = cks("3.3V  Status bit",(int)vstat_3p3v[0],(int)'O');
	statid[3] = cks("1.8V  Status bit",(int)vstat_1p8v[0],(int)'O');
	statid[4] = cks("1.5V  Status bit",(int)vstat_1p5v[0],(int)'O');
	statid[5] = cks("Tcrit Status bit",(int)tcrit[0]     ,(int)'O');

	for (i=1; i<=5; ++i) {
		if (statid[i]!=0) rat_nfailed[itest]=1;
	}

	if (rat_nfailed[itest]==0) rat_npassed[itest]=1;
	aokf("Voltage Comparators",itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	ADC+Status
	//------------------------------------------------------------------------------
	//L25030:
	// itest=3,4,5

	// Read ADCs
	adc_read(base_adr);	// returns data via common block

	// Read LM84 temperature from TMB, don't read RAT beco this board is in the loopback backplane and has no RAT
	smb_adr  = 0x2A;	// float,float state LM84 chip address
	smb_cmd  = 0x00;	// Local temperature command
	smb_data = 0xFF;	// Null write data
	adc_adr  = base_adr+vme_adc_adr;

	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data

	t_local_c_tmb = float(smb_data_tmb);
	t_local_f_tmb = t_local_c_tmb*(9./5.)+32.;

	smb_cmd  = 0x01;	// Remote temperature command
	smb_data = 0xFF;	// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	

	t_remote_c_tmb = float(smb_data_tmb);
	t_remote_f_tmb = t_remote_c_tmb*(9./5.)+32.;

	smb_cmd  = 0x05;	// Local tcrit
	smb_data = 0xFF;	// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	

	tcrit_local_c_tmb = float(smb_data_tmb);
	tcrit_local_f_tmb = tcrit_local_c_tmb*(9./5.)+32.;

	smb_cmd  = 0x07;	// Remote tcrit
	smb_data = 0xFF;	// Null write data
	smb_write(adc_adr, smb_adr, smb_cmd,      smb_data);		// write command
	smb_read (adc_adr, smb_adr, smb_data_tmb, smb_data_rat);	// read  data	

	tcrit_remote_c_tmb = float(smb_data_tmb);
	tcrit_remote_f_tmb = tcrit_remote_c_tmb*(9./5.)+32.;

	// Display final results
	fprintf(test_file,"\n");
	fprintf(test_file,"\tTMB2005E ADC\n");
	fprintf(test_file,"\t+5.0 TMB      %5.3f V  %8.3f A\n",v5p0,		a5p0);
	fprintf(test_file,"\t+3.3 TMB      %5.3f V  %8.3f A\n",v3p3,		a3p3);
	fprintf(test_file,"\t+1.5 TMBcore  %5.3f V  %8.3f A\n",v1p5core,	a1p5core);
	fprintf(test_file,"\t+1.5 GTLtt    %5.3f V  %8.3f A\n",v1p5tt,		a1p5tt);
	fprintf(test_file,"\t+1.0 GTLref   %5.3f V  %8.3f A\n",v1p0,		0.0);
	fprintf(test_file,"\t+3.3 RAT      %5.3f V  %8.3f A\n",v3p3,		a3p3rat);	// v3p3rat depends on sh921 setting
	fprintf(test_file,"\t+1.8 RATcore  %5.3f V  %8.3f A\n",v1p8rat,		a1p8rat);	// a1p8rat depends on sh921 setting
	fprintf(test_file,"\t+vref/2       %5.3f V  %8.3f A\n",vref2,		0.0);
	fprintf(test_file,"\t+vzero        %5.3f V  %8.3f A\n",vzero,		0.0);
	fprintf(test_file,"\t+vref         %5.3f V  %8.3f A\n",vref,		0.0);

	fprintf(test_file,"\n");
	fprintf(test_file,"\tTMB2005E Temperature IC\n");
	fprintf(test_file,"\tT tmb pcb  %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_local_f_tmb,t_local_c_tmb,tcrit_local_f_tmb,tcrit_local_c_tmb);
	fprintf(test_file,"\tT tmb fpga %6.1f   F%7.0f    C  Tcrit=%4.0f/%4.0f\n",t_remote_f_tmb,t_remote_c_tmb,tcrit_remote_f_tmb,tcrit_remote_c_tmb);
	fprintf(test_file,"\n");

	for (i=1; i<=mxadcerr; ++i) {
		adc_err[i] = 0;
	}

	// Check Currents
	itest=3;

	amptol=0.16;
	tok("+5.0a TMB      ",a5p0,	    0.275, amptol*1.5, adc_err[10]);
	tok("+3.3a TMB      ",a3p3,     1.525, amptol*2.,  adc_err[11]);	// RAT takes more amps than loopback
	tok("+1.5a TMB Core ",a1p5core, 0.870, amptol,     adc_err[12]);
	tok("+1.5a TT       ",a1p5tt,	0.030, amptol*7. , adc_err[13]);	// Small current, large uncertainty
	tok("+1.8a RAT Core ",a1p8rat,	0.070, amptol*2.5, adc_err[14]);	// loop backplane sends 1.5v, RAT sends true current

	for (i=10; i<=14; ++i) {
		if (adc_err[i]!=0) rat_nfailed[itest]=1;
	}

	if (rat_nfailed[itest]==0) rat_npassed[itest]=1;	
	aokf("ADC Currents",itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	// Check Voltages 
	itest=4;
	vcore_noload = 1.525;						// Puts Vcore=1.500 at 2.5amp load, midrange of 1.425-to-1.575
	vcore_expect = vcore_noload-a1p5core*0.010;	// Expect Vcore-Acore*.010ohms. At Acore nom=0.870A, Vcore=1.516
	v1p0_expect  = 1.005;						// Expect 1.005+- a little

	fprintf(test_file,"Vcore expect=%5.3f NoLoad=%5.3f Acore=%5.3f\n\n",vcore_expect,vcore_noload,a1p5core);

	tok("+5.0v TMB      ", v5p0,     5.000,        .0250, adc_err[1]);
	tok("+3.3V TMB      ", v3p3,     3.260,        .0250, adc_err[2]);
	tok("+1.5V Core     ", v1p5core, vcore_expect, .0015, adc_err[3]);	// expect 1.516 pretty close
	tok("+1.5V TT       ", v1p5tt,   1.493,        .0250, adc_err[4]);
	tok("+1.0v TT       ", v1p0,     v1p0_expect,  .0030, adc_err[5]);
	tok("+1.8V RAT Core ", v1p8rat,  1.805,        .0250, adc_err[6]);
	tok("+vref/2        ", vref2,    2.048,        .0010, adc_err[7]);
	tok("+vzero         ", vzero,    0.0,          .0010, adc_err[8]);
	tok("+vref          ", vref,     4.095,        .0010, adc_err[9]);

	// Enumerate errors
	for (i=1; i<=9; ++i) {
		if (adc_err[i]!=0) rat_nfailed[itest]=1;
	}

	if (rat_nfailed[itest]==0)rat_npassed[itest]=1;	
	aokf("ADC Voltages",itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	// Check TMB+RAT Temperatures
	itest=5;

	ttol=0.35;
	tok("T tmb pcb      ",t_local_f_tmb,   77.0, ttol, adc_err[15]);
	tok("T fpga chip    ",t_remote_f_tmb, 104.0, ttol, adc_err[16]);
	tok("T rat pcb      ",t_local_f_tmb,   77.0, ttol, adc_err[17]);
	tok("T rat xstr     ",t_remote_f_tmb, 104.0, ttol, adc_err[18]);

	for (i=115; i<=18; ++i) {
		if (adc_err[i]!=0) rat_nfailed[itest]=1;
	}

	fprintf(test_file,"\n");
	fprintf(test_file,"RAT 2005E Temperature IC\n");

	fprintf(test_file,"T rat pcb  %6.1   F %7.0f    C  Tcrit=%4.0f/%4.0f\n",t_local_f_rat, t_local_c_rat, tcrit_local_f_rat, tcrit_local_c_rat );
	fprintf(test_file,"T rat xstr %6.1   F %7.0f    C  Tcrit=%4.0f/%4.0f\n",t_remote_f_rat,t_remote_c_rat,tcrit_remote_f_rat,tcrit_remote_c_rat);

	iflocal = int(t_local_f_rat  + 0.5);
	ifhsink = int(t_remote_f_rat + 0.5);

	sprintf(cflocal,"%3i",iflocal);
	sprintf(cfhsink,"%3i",ifhsink);

	sflocal=string(cflocal);
	sfhsink=string(sfhsink);

	if (rat_nfailed[itest]==0)rat_npassed[itest]=1;	
	aokf(string("ADC Temperatures Tpcb=").append(sflocal).append(string("F, Thsink=")).append(sfhsink).append(string("F")),itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//	Unstress ccb gtl drivers
	wr_data = 0x0000;						// All bits 0
	wr_data = (~wr_data) & 0x0FFFF;			// invert
	adr     = ccb_txa_adr+base_adr;
	status	= vme_write(adr,wr_data);
	wr_data = 0xFFFF;						// bits 17:16
	wr_data = (~wr_data) & 0x0000F;			// invert
	adr     = ccb_txb_adr+base_adr;
	status	= vme_write(adr,wr_data);

	//	TMB2005E with heater-code firmware resuls for reference
	//	Unit	+5.0a	+3.3a	+1.8a	+1.5aCore	+1.05aTT	+3.3Arat	Tchip	Tpcb
	//	TMB5013	0.275	0.775	7.490	0.870		0.030		-			104F	77F

	//------------------------------------------------------------------------------
	//	RAT Full Auto Test:
	//	Check FPGA + PROM ID Codes
	//------------------------------------------------------------------------------
	//	itest=6,7

	// Select RAT JTAG chain from TMB boot register, backplane uses RAT JTAG signals
	ichain = 0x000D;							// RAT jtag chain
	adr    = boot_adr;							// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	// Read FPGA/PROM IDcodes (8 bit opcode)
	for (chip_id=0; chip_id<=1; ++chip_id)
	{
		itest=chip_id+6;
		if (chip_id==0) opcode = 0x09;				// FPGA IDcode opcode
		if (chip_id==1) opcode = 0xFE;				// PROM IDcode opcode
		reg_len = 32;								// IDcode length
		// FPGA,PROM chip
		vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		// Check ID codes
		tdi_to_i4(&tdo[0],idcode,32,0);

		sprintf(cid, "%1i",  chip_id);
		sprintf(cidc,"%8.8X",idcode );

		sid  = string(cid);
		sidc = string(cidc);

		if (chip_id==0)
		{
			status=cks(string("RAT FPGA ID Code ").append(sid),idcode,0x20A10093);
			if (status!=0            ) rat_nfailed[itest]=1;
			if (rat_nfailed[itest]==0) rat_npassed[itest]=1;	
			aokf(string("RAT FPGA ID Code ").append(sid).append(string(" ")).append(sidc),itest,rat_npassed[itest]);
		}
		else 
		{
			if (idcode==0x05034093)
			{
				status=cks(string("RAT PROM ID Code ").append(sid),idcode,0x05034093);
				if (status!=0) rat_nfailed[itest]=1;
			}
			else 
			{
				status=cks(string("RAT PROM ID Code ").append(sid),idcode,0x05024093);
				if (status!=0) rat_nfailed[itest]=1;
			}

			if (rat_nfailed[itest]==0) rat_npassed[itest]=1;	
			aokf(string("RAT PROM ID Code ").append(sid).append(string(" ")).append(sidc),itest,rat_npassed[itest]);

		}	// close if chip_id==0

		if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");
	}	// close for chip_id

	//------------------------------------------------------------------------------
	//	Full Auto Test:
	//	Test RAT Hard Reset via TMB boot register
	//------------------------------------------------------------------------------
	itest=8;

	adr     = boot_adr;
	status  = vme_read(adr,rd_data);		// Get current boot register
	boot_data = rd_data;
	wr_data = boot_data | 0x2000;			// d[13]=1=rat reset
	status  = vme_write(adr,wr_data);		// Assert RAT hard reset

	adr     = vme_gpio_adr+base_adr;
	status  = vme_read(adr,rd_data);								// Check for RATfpga not ready
	rd_data = (rd_data>>4) & 0x1;									// gpio4=rpc_done
	status=cks("FPGA Hard reset fpga not ready",rd_data,0x0000);	// expect 0 for not done
	if (status!=0) rat_nfailed[itest]=1;

	adr     = boot_adr;
	wr_data = boot_data & 0xDFFF;			// d[13]=0=deassert rat reset
	status  = vme_write(boot_adr,wr_data);	// De-assert hard reset
	sleep(200);								// Wait for RAT to reload

	adr     = vme_gpio_adr+base_adr;
	status  = vme_read(adr,rd_data);								// Check for fpga ready
	rd_data = (rd_data>>4) & 0x1;									// gpio4=rpc_done
	status=cks("RAT FPGA Hard reset fpga ready",rd_data,0x0001);	// expect 1 for done
	if (status!=0) rat_nfailed[itest]=1;

	if (rat_nfailed[itest]==0)rat_npassed[itest]=1;	
	aokf("RAT FPGA Hard reset",itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	RAT Full Auto Test:
	//	Read RAT JTAG Register
	//	Check FPGA Firmware date 
	//------------------------------------------------------------------------------
	itest=9;

	// Select RAT JTAG chain from TMB boot register
	ichain = 0x000D;						// RAT jtag chain
	adr    = boot_adr;						// Boot register address
	vme_jtag_anystate_to_rti(adr,ichain);	// Take TAP to RTI

	// Read RAT USER1 register (5 bit opcode)
	chip_id = 0;
	opcode  = 0x02;							// FPGA USER1 opcode
	reg_len = 224;							// USER1 register length
	vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	dprintf("tdo="); for (i=0; i<reg_len; ++i) dprintf("%1i",tdo[i]); dprintf("\n");

	// Decode RAT USER1 register
	for (i=0; i<reg_len; ++i) rs[i]=tdo[i];

	tdi_to_i4(&tdo[  0], rat_user1[0], 32,0);
	tdi_to_i4(&tdo[ 32], rat_user1[1], 32,0);
	tdi_to_i4(&tdo[ 64], rat_user1[2], 32,0);
	tdi_to_i4(&tdo[ 96], rat_user1[3], 32,0);
	tdi_to_i4(&tdo[128], rat_user1[4], 32,0);
	tdi_to_i4(&tdo[160], rat_user1[5], 32,0);
	tdi_to_i4(&tdo[192], rat_user1[6], 32,0);
	fprintf(test_file,"RAT USER1="); for(i=6; i>=0; --i) printf("%8.8X",rat_user1[i]); printf("\n");

	tdi_to_i4(&rs[  0], rs_begin,           4,0);
	tdi_to_i4(&rs[  4], rs_version,         4,0);
	tdi_to_i4(&rs[  8], rs_monthday,       16,0);
	tdi_to_i4(&rs[ 24], rs_year,           16,0);

	tdi_to_i4(&rs[ 40], rs_syncmode,        1,0);
	tdi_to_i4(&rs[ 41], rs_posneg,          1,0);
	tdi_to_i4(&rs[ 42], rs_loop,            1,0);

	tdi_to_i4(&rs[ 43], rs_rpc_en,          2,0);
	tdi_to_i4(&rs[ 45], rs_clk_active,      2,0);
	tdi_to_i4(&rs[ 47], rs_locked_tmb,      1,0);
	tdi_to_i4(&rs[ 48], rs_locked_rpc0,     1,0);
	tdi_to_i4(&rs[ 49], rs_locked_rpc1,     1,0);
	tdi_to_i4(&rs[ 50], rs_locklost_tmb,    1,0);
	tdi_to_i4(&rs[ 51], rs_locklost_rpc0,   1,0);
	tdi_to_i4(&rs[ 52], rs_locklost_rpc1,   1,0);

	tdi_to_i4(&rs[ 53], rs_txok,            1,0);
	tdi_to_i4(&rs[ 54], rs_rxok,            1,0);

	tdi_to_i4(&rs[ 55], rs_ntcrit,          1,0);
	tdi_to_i4(&rs[ 56], rs_rpc_free,        1,0);	
	tdi_to_i4(&rs[ 57], rs_dsn,             1,0);

	tdi_to_i4(&rs[ 58], rs_dddoe_wr,        4,0);
	tdi_to_i4(&rs[ 62], rs_ddd_wr,         16,0);
	tdi_to_i4(&rs[ 78], rs_ddd_auto,        1,0);
	tdi_to_i4(&rs[ 79], rs_ddd_start,       1,0);
	tdi_to_i4(&rs[ 80], rs_ddd_busy,        1,0);
	tdi_to_i4(&rs[ 81], rs_ddd_verify_ok,   1,0);

	tdi_to_i4(&rs[ 82], rs_rpc0_parity_ok,  1,0);
	tdi_to_i4(&rs[ 83], rs_rpc1_parity_ok,  1,0);
	tdi_to_i4(&rs[ 84], rs_rpc0_cnt_perr,  16,0);
	tdi_to_i4(&rs[100], rs_rpc1_cnt_perr,  16,0);
	tdi_to_i4(&rs[116], rs_last_opcode,     5,0);

	tdi_to_i4(&rs[121], rw_rpc_en,          2,0);
	tdi_to_i4(&rs[123], rw_ddd_start,       1,0);
	tdi_to_i4(&rs[124], rw_ddd_wr,         16,0);
	tdi_to_i4(&rs[140], rw_dddoe_wr,        4,0);
	tdi_to_i4(&rs[144], rw_perr_reset,      1,0);
	tdi_to_i4(&rs[145], rw_parity_odd,      1,0);
	tdi_to_i4(&rs[146], rw_perr_ignore,     1,0);
	tdi_to_i4(&rs[147], rw_rpc_future,      6,0);

	tdi_to_i4(&rs[153], rs_rpc0_pdata,     19,0);
	tdi_to_i4(&rs[172], rs_rpc1_pdata,     19,0);

	tdi_to_i4(&rs[191], rs_unused,         29,0);
	tdi_to_i4(&rs[220], rs_end,             4,0);

	fprintf(test_file,"%s%4.1X\n","rs_begin          ",rs_begin);
	fprintf(test_file,"%s%4.1X\n","rs_version        ",rs_version);
	fprintf(test_file,"%s%4.4X\n","rs_monthday       ",rs_monthday);
	fprintf(test_file,"%s%4.4X\n","rs_year           ",rs_year);

	fprintf(test_file,"%s%4.1X\n","rs_syncmode       ",rs_syncmode);
	fprintf(test_file,"%s%4.1X\n","rs_posneg         ",rs_posneg);
	fprintf(test_file,"%s%4.1X\n","rs_loop           ",rs_loop);

	fprintf(test_file,"%s%4.1X\n","rs_rpc_en         ",rs_rpc_en);
	fprintf(test_file,"%s%4.1X\n","rs_clk_active     ",rs_clk_active);

	fprintf(test_file,"%s%4.1X\n","rs_locked_tmb     ",rs_locked_tmb);
	fprintf(test_file,"%s%4.1X\n","rs_locked_rpc0    ",rs_locked_rpc0);
	fprintf(test_file,"%s%4.1X\n","rs_locked_rpc1    ",rs_locked_rpc1);
	fprintf(test_file,"%s%4.1X\n","rs_locklost_tmb   ",rs_locklost_tmb);
	fprintf(test_file,"%s%4.1X\n","rs_locklost_rpc0  ",rs_locklost_rpc0);
	fprintf(test_file,"%s%4.1X\n","rs_locklost_rpc1  ",rs_locklost_rpc1);

	fprintf(test_file,"%s%4.1X\n","rs_txok           ",rs_txok);
	fprintf(test_file,"%s%4.1X\n","rs_rxok           ",rs_rxok);

	fprintf(test_file,"%s%4.1X\n","rs_ntcrit         ",rs_ntcrit);
	fprintf(test_file,"%s%4.1X\n","rs_rpc_free       ",rs_rpc_free);

	fprintf(test_file,"%s%4.1X\n","rs_dsn            ",rs_dsn);
	fprintf(test_file,"%s%4.1X\n","rs_dddoe_wr       ",rs_dddoe_wr);
	fprintf(test_file,"%s%4.4X\n","rs_ddd_wr         ",rs_ddd_wr);
	fprintf(test_file,"%s%4.1X\n","rs_ddd_auto       ",rs_ddd_auto);
	fprintf(test_file,"%s%4.1X\n","rs_ddd_start      ",rs_ddd_start);
	fprintf(test_file,"%s%4.1X\n","rs_ddd_busy       ",rs_ddd_busy);
	fprintf(test_file,"%s%4.1X\n","rs_ddd_verify_ok  ",rs_ddd_verify_ok);

	fprintf(test_file,"%s%4.1X\n","rs_rpc0_parity_ok ",rs_rpc0_parity_ok);
	fprintf(test_file,"%s%4.1X\n","rs_rpc1_parity_ok ",rs_rpc1_parity_ok);
	fprintf(test_file,"%s%4.4X\n","rs_rpc0_cnt_perr  ",rs_rpc0_cnt_perr);
	fprintf(test_file,"%s%4.4X\n","rs_rpc1_cnt_perr  ",rs_rpc1_cnt_perr);
	fprintf(test_file,"%s%4.2X\n","rs_last_opcode    ",rs_last_opcode);

	fprintf(test_file,"%s%4.1X\n","rw_rpc_en         ",rw_rpc_en);
	fprintf(test_file,"%s%4.1X\n","rw_ddd_start      ",rw_ddd_start);
	fprintf(test_file,"%s%4.4X\n","rw_ddd_wr         ",rw_ddd_wr);
	fprintf(test_file,"%s%4.1X\n","rw_dddoe_wr       ",rw_dddoe_wr);
	fprintf(test_file,"%s%4.1X\n","rw_perr_reset     ",rw_perr_reset);
	fprintf(test_file,"%s%4.1X\n","rw_parity_odd     ",rw_parity_odd);
	fprintf(test_file,"%s%4.1X\n","rw_perr_ignore    ",rw_perr_ignore);
	fprintf(test_file,"%s%4.2X\n","rw_rpc_future     ",rw_rpc_future);

	fprintf(test_file,"%s%5.5X\n","rs_rpc0_pdata     ",rs_rpc0_pdata);
	fprintf(test_file,"%s%5.5X\n","rs_rpc1_pdata     ",rs_rpc1_pdata);

	fprintf(test_file,"%s%7.7X\n","rs_unused         ",rs_unused);
	fprintf(test_file,"%s%4.1X\n","rs_end            ",rs_end);
	fprintf(test_file,"\n");

	// Check ID register date
	rat_user1_string = "BAD";

	if (
			rs_begin	== 0xB		&&
			rs_end		== 0xE		&&
			rs_version	== 0xE		&&
			rs_monthday	== 0x0223	&&	// monthday
			rs_year		== 0x2006		// year
	   ) rat_user1_string = "OK ";

	if (rat_user1_string.compare("BAD")!=0) rat_npassed[itest]=1;
	if (rat_user1_string.compare("BAD")==0)
	{
		rat_nfailed[itest]=1;
		fprintf(stdout, "\tError in RAT JTAG USER1 chain; wrong firmware?");
		fprintf(test_file,"Error in RAT JTAG USER1 chain; wrong firmware?");
	}

	// Check 3D3444 status
	if (rs_ddd_verify_ok!=1)
	{
		rat_nfailed[itest]=1;
		fprintf(stdout, "\tRAT: 3D3444 USER1 erify error\n");
		fprintf(test_file,"RAT: 3D3444 USER1 erify error\n");
	}

	if (rat_nfailed[itest]==0)rat_npassed[itest]=1;	
	aokf("RAT: JTAG USER1 Register",itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	RAT Full Auto Test:
	//	RPC data timing window
	//------------------------------------------------------------------------------
	itest=10;

	// Turn off step mode
	sel_step_alct = 0x1FE0;
	adr     = vme_step_adr+base_adr;
	wr_data = sel_step_alct;
	status  = vme_write(adr,wr_data);

	// Take TMB and RAT out of loop-back mode
	adr	    = vme_loopbk_adr+base_adr;
	status  = vme_read(adr,rd_data);
	wr_data = rd_data & 0xFFCF;			// turn off RPC loop bits
	status  = vme_write(adr,wr_data);

	// Put RAT in sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
	wr_data = 0x0003;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	adr	    = rpc_txb_adr+base_adr;
	status  = vme_write(adr,wr_data);

	// Get current delay register
	ichip = 0;
	ich   = 3;

	adr	    = vme_ddd0_adr+base_adr;
	status  = vme_read (adr,rd_data);
	rd_ddd0 = rd_data;

	rpc_delay_default = rd_ddd0;
	rd_ddd0 = rd_ddd0 & 0x0FFF;

	// Clear error accumulator
	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay) {
		rpc_bad[ddd_delay] = 0;
	}

	// Generate expected bit pattern for comparison
	bit_to_array(0x2AAAA, rpc0_rdata_expect, 19);
	bit_to_array(0x55555, rpc1_rdata_expect, 19);
	bit_to_array(0x55555, rpc2_rdata_expect, 19);
	bit_to_array(0x2AAAA, rpc3_rdata_expect, 19);

	// Step rpc clock delay
	npasses=1000;

	for (ipass=1;     ipass<=npasses; ++ipass    ) {	// 2515
		for (ddd_delay=0; ddd_delay<=15;  ++ddd_delay) {	// 2510

			wr_data = (ddd_delay<<(ich*4)) | rd_ddd0;
			adr	    = base_adr+vme_ddd0_adr+2*ichip;
			status  = vme_write(adr,wr_data);

			// Start DDD state machine
			adr	    = base_adr+vme_dddsm_adr;
			status  = vme_read(adr,rd_data);
			autostart = rd_data & 0x0020;	// get current autostart state
			wr_data	= 0x0000 | autostart;	// stop machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0001 | autostart;	// start machine
			status	= vme_write(adr,wr_data);
			wr_data = 0x0000 | autostart;	// unstart machine
			status	= vme_write(adr,wr_data);

			// Wait for it to finish
			for (i=1; i<=1000; ++i) {
				status   = vme_read(adr,rd_data);
				ddd_busy = (rd_data>>6) & 0x1;
				ddd_verify_ok =(rd_data>>7) & 0x1;
				if (ddd_busy==0) goto L2506;
			}

			printf("\n\tTMB 3d3444 verify failed. ich=%1i ddd_delay=%1X\n",ich,ddd_delay);
			rat_nfailed[itest]=1;
			pause("<cr> to continue");

			// Let RAT DLL re-sync
			sleep(200);

			// Check RAT 80MHz demux register
L2506:
			status	= vme_read(adr=rpc_rxa_adr+base_adr,rpc_rxa);	// 1st in time
			status	= vme_read(adr=rpc_rxb_adr+base_adr,rpc_rxb);
			status	= vme_read(adr=rpc_rxc_adr+base_adr,rpc_rxc);

			status	= vme_read(adr=rpc_rxd_adr+base_adr,rpc_rxd);	// 2nd in time
			status	= vme_read(adr=rpc_rxe_adr+base_adr,rpc_rxe);
			status	= vme_read(adr=rpc_rxf_adr+base_adr,rpc_rxf);

			// Assemble rpc data words a,b,c=1st[37:0] d,e,f=2nd[37:0]
			rpc_rx[0]  = rpc_rxa & 0xFFFF;					// rx[15:0]	pack [15: 0]	// 1st in time
			rpc_rx[1]  = rpc_rxb & 0xFFFF;					// rx[15:0]	pack [34:19]	// 1st in time

			rpc_bxn[0] = rpc_rxc & 0x0007;					// bxn[2:0]	pack [18:16]
			rpc_bxn[1] = (rpc_rxc>>3) & 0x0007;				// bxn[2:0]	pack [37:35]

			rpc_rx[2]  = rpc_rxd & 0xFFFF;					// rx[15:0]	pack [15: 0]	// 1st in time
			rpc_rx[3]  = rpc_rxe & 0xFFFF;					// rx[15:0]	pack [34:19]	// 1st in time

			rpc_bxn[2] = rpc_rxf & 0x0007;					// bxn[2:0]	pack [18:16]
			rpc_bxn[3] = (rpc_rxf>>3) & 0x0007;				// bxn[2:0]	pack [37:35]

			// Repack bxn, invert lvds bits
			for (i=0; i<=3; ++i) {
				rpc_word[i] = rpc_rx[i] | (rpc_bxn[i]<<16);
			}

			bit_to_array(rpc_word[0],&rpc_data_1st[ 0],19);
			bit_to_array(rpc_word[1],&rpc_data_1st[19],19);
			bit_to_array(rpc_word[2],&rpc_data_2nd[ 0],19);
			bit_to_array(rpc_word[3],&rpc_data_2nd[19],19);

			// Check for correct data received
			bad_1st=0;
			bad_2nd=0;

			for (i=0; i<=18; ++i) {
				if (rpc_data_1st[i   ]!=rpc0_rdata_expect[i]) bad_1st++;
				if (rpc_data_1st[i+19]!=rpc1_rdata_expect[i]) bad_1st++;

				if (rpc_data_2nd[i   ]!=rpc2_rdata_expect[i]) bad_2nd++;
				if (rpc_data_2nd[i+19]!=rpc3_rdata_expect[i]) bad_2nd++;
			}

			rpc_bad[ddd_delay]=rpc_bad[ddd_delay]+bad_1st+bad_2nd;

			if (ipass==1) {
				fprintf(test_file,"delay=%2i\n");
				fprintf(test_file,"rpx_tx_1st[37:0]="); for(i=37; i>=0; --i) fprintf(test_file,"%1i",rpc_data_1st[i]); fprintf(test_file,"\n");
				fprintf(test_file,"rpx_tx_1st[37:0]="); for(i=37; i>=0; --i) fprintf(test_file,"%1i",rpc_data_2nd[i]); fprintf(test_file,"\n");
				fprintf(test_file,"delay=%2i\n");
			}

			// Display probable bad bits
			if (ipass==1 && ddd_delay==9)
			{
				err_bit=-1;
				for (i=0; i<=18; ++i)
				{
					if (rpc_data_1st[i   ]!=rpc0_rdata_expect[i]) err_bit=i;
					if (rpc_data_1st[i+19]!=rpc1_rdata_expect[i]) err_bit=i;

					if (rpc_data_2nd[i   ]!=rpc2_rdata_expect[i]) err_bit=i+19;
					if (rpc_data_2nd[i+19]!=rpc3_rdata_expect[i]) err_bit=i+19;

					if (err_bit>=0) fprintf(stdout, "\tERROR in RPC bit=%2i\n",i);
					if (err_bit>=0) fprintf(test_file,"ERROR in RPC bit=%2i\n",i);
				}	// close do
			}	// close if

			// Close loops
		}	// close for ddd_delay 2510

		if (ipass==1   ) fprintf(test_file,"RPC data: Running delay curve\n\n");
		if (ipass%10==0) fprintf(stdout, "\tRPC data: Running delay curve %4i\r",npasses-ipass);

	}	// close for ipass 2515

	// Take RAT out of sync mode,it consumes massive power, dunno why
	wr_data = 0x0000;			// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	adr	    = rpc_txb_adr+base_adr;
	status  = vme_write(adr,wr_data);

	// Put RPC delay back to default
	adr     = vme_ddd0_adr+base_adr;
	wr_data = rpc_delay_default;
	status	= vme_write(adr,wr_data);

	// Display timing results
	fprintf(test_file,"2nsStep Berrs   Pct  0123456789  %5i cycles\n",npasses);

	for (ddd_delay=0; ddd_delay<=15; ++ddd_delay)
	{
		pctbad = 100.*float(rpc_bad[ddd_delay])/76000.;
		nbad   = int(pctbad/10.);
		if (pctbad!=0.0 && nbad==0)  nbad=1;
		rat_window_nbad[ddd_delay] = nbad;

		if (nbad!=0 && ddd_delay==9) {
			fprintf(stdout,"\tError in RPC data: ddd_delay=%2i rpc_bad=%7i pctbad=%7.0f"); for(i=1;i<=nbad;++i) printf("%c",'x'); printf("\n");}
		fprintf(test_file,                  "ddd_delay=%2i rpc_bad=%7i pctbad=%7.0f"); for(i=1;i<=nbad;++i) printf("%c",'x'); printf("\n");
	}
	fprintf(test_file,"Return to default delay %2i\n",(rpc_delay_default>>12) & 0xF);

	// Find window width and center
	rat_window_width =  0;
	rat_window_open  = -1;
	rat_window_close = -1;

	for (i=0; i<=15; ++i) {
		nbad=rat_window_nbad[i];
		if (nbad!=0 && rat_window_open>=0 && rat_window_close<0) rat_window_close = i-1;	// window closed previous tbin
		if (nbad==0 && rat_window_open<0                       ) rat_window_open  = i;		// window opens
	}

	rat_window_width  = rat_window_close-rat_window_open+1;
	rat_window_center = rat_window_open+int(float(rat_window_width)/2.0);

	if (rat_window_width<4) {
		rat_nfailed[itest]=1;
		fprintf(stdout, "\tERROR bad RPC window width %3i\n",rat_window_width);
		fprintf(test_file,"ERROR bad RPC window width %3i\n",rat_window_width);
	}

	i='PASS';
	if (rat_nfailed[itest]!=0) i='FAIL';

	fprintf(stdout,"\t");
	fprintf(stdout,"RPC DelayWindow opn=%3i ",rat_window_open);
	fprintf(stdout,"end=%2i ",rat_window_close);
	fprintf(stdout,"wid=%2i ",rat_window_width);
	fprintf(stdout,"ctr=%2i ",rat_window_center);
	fprintf(stdout,"    %c\n",i);

	fprintf(test_file,"RPC DelayWindow opn=%3i ",rat_window_open);
	fprintf(test_file,"end=%2i ",rat_window_close);
	fprintf(test_file,"wid=%2i ",rat_window_width);
	fprintf(test_file,"ctr=%2i ",rat_window_center);
	fprintf(test_file,"    %c\n",i);

	if (rat_nfailed[itest]==0) rat_npassed[itest]=1;	
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	//------------------------------------------------------------------------------
	//	RAT Full Auto Test:
	//	Burn-in loop for self-contained tests
	//------------------------------------------------------------------------------
	if (ifunc<0)
	{
		printf("\tBurn-in Pass"); for(i=0;i<42;++i)printf(" "); printf("%10i\n",ipass_full_auto);
		goto L2505;
	}

	//------------------------------------------------------------------------------
	//	RAT Full Auto Test:
	//	ALCT SCSI Cable Loopback
	//------------------------------------------------------------------------------
	itest=11;

	printf("\n");
	printf("\tRAT: ALCT SCSI Cable Loopback Test:\n");
	printf("\tConnect a 25pr cable from ALCTtx to ALCTrx on RAT\n");
	printf("\tSkip, Loop, Debug, Continue <cr> ");

	gets(line);
	n = strlen(line);
	i = line[0];

	debug_beep = false;

	if (n==1 && (i=='S' || i=='s')) {rat_nskipped[itest]=1; goto L2580;};
	if (n==1 && (i=='L' || i=='l')) {debug_loop = true; debug_beep = true;}
	if (n==1 && (i=='D' || i=='d'))  debug_step = true;

L25251:
	sel_boot_jtag = 0x0080;
	sel_step_alct = 0x1D10;
	sel_loopbk    = 0x0A9F;	// ALCT loop mode
	alct_err      = 0;

	// Put ALCT into loopback mode, enable CFEBs, and ALCT SCSI
	adr		= vme_loopbk_adr + base_adr;
	wr_data = sel_loopbk;
	status	= vme_write (adr,wr_data);

	// Turn off 40MHz FPGA output to drive RPC input clock
	adr     = vme_ratctrl_adr+base_adr;
	status  = vme_read(adr,rd_data);
	rat_ctrl_data = rd_data;
	wr_data = rd_data & 0xFFDF;	// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
	status  = vme_write(adr,wr_data);

	// Send walking 1s to ALCT transmitter
	npasses = 1000;

	for (ipass=1; ipass<=npasses; ++ipass)	// 25256
	{
		if (ipass%10==0      ) printf("\tALCT cable: Running loopback test %4i \r",npasses-ipass);
		if (ipass   ==npasses) printf("\t                                      \r");

		for (itx=0; itx<=24; ++itx)	// 25255
		{
			status	 = vme_write(adr=(tmb_boot_adr+base_adr),wr_data=sel_boot_jtag);
			status	 = vme_write(adr=(alct_txa_adr+base_adr),wr_data=0);
			status	 = vme_write(adr=(alct_txb_adr+base_adr),wr_data=0);
			status	 = vme_write(adr=(vme_step_adr+base_adr),wr_data=sel_step_alct);

			if (itx>=0 && itx<=4) {
				wr_data= (1<<itx) | sel_boot_jtag;
				adr	= tmb_boot_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx>=5 && itx<=17) {
				wr_data= (1<<(itx-5));
				adr	= alct_txa_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx==18) {
				wr_data= (1<<8) | sel_boot_jtag;
				adr	= tmb_boot_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx==20) {
				wr_data= 0x0001 | sel_step_alct;
				adr	= vme_step_adr + base_adr;
				status	= vme_write(adr,wr_data);
			}
			else if (itx>=19 || itx<=24) {
				wr_data= (1<<(itx-19));
				if (itx==21) wr_data = (1<<(20-19));
				if (itx==22) wr_data = (1<<(21-19));
				if (itx==23) wr_data = (1<<(22-19));
				if (itx==24) wr_data = (1<<(23-19));
				adr	= alct_txb_adr + base_adr;
				status	= vme_write(adr,wr_data);	
			}	
			else {
				stop("dumbass");
			}

			// Read back ALCT data registers
			alct_data = 0;

			for (ireg=0; ireg<=3; ++ireg) {
				adr		= base_adr+alct_rxa_adr+2*ireg;
				status	= vme_read(adr,rd_data);
				alct_id = (rd_data>>8) & 0xFF;
				rd_data = rd_data & 0xFF;
				alct_data      = alct_data | (rd_data<<(ireg*8));
				alct_id_expect = 0xA0 | ireg;

				if (alct_id!=alct_id_expect || debug_step) {
					fprintf(stdout, "\tERROR Wrong ALCT id alct_id_expect=%4.4X alct_id=%2.2X rd_data=%2.2X\n",alct_id_expect,alct_id,rd_data);
					fprintf(test_file,"ERROR Wrong ALCT id alct_id_expect=%4.4X alct_id=%2.2X rd_data=%2.2X\n",alct_id_expect,alct_id,rd_data);
					rat_nfailed[itest]=1;
					if (pause_on_fail) pause("\tFailed. <cr> to continue anyway");
				}	// close if alct_id
			}	// close for ireg

			// Read back TDO rx[0], merge with rx[28:1]
			adr		  = tmb_boot_adr + base_adr;
			status	  = vme_read(adr,rd_data);
			alct_tdo  = rd_data;
			alct_tdo  = alct_tdo  & 0x1;
			alct_lsbs = alct_data ^ 0xF;		// invert
			alct_lsbs = alct_lsbs & 0xE;		// trim off [28:4]
			alct_lsbs = alct_lsbs | alct_tdo;	// invert [3:1] add [0]

			// Check lower 4 ALCT rx bits that are hardwired to tx drivers
			alct_expect = (1<<itx);
			if (itx>=22        ) alct_expect = (1<<(itx-21));
			if (itx==0         ) alct_expect = 1; // tdo bit
			if (itx<22 && itx>0) alct_expect = 0;

			if (alct_lsbs!=alct_expect) {
				alct_err++;
				if (!debug_loop) {
					printf("\tALCT hardwire error: itx=%3i  read=%8.8X expect=%8.8X\n",itx,alct_lsbs,alct_expect);
					rat_nfailed[itest]=1;
					if (pause_on_fail) pause("\tFailed. <cr> to continue anyway");
				}}


			// Un-invert the inverted ALCT bits...thanks a lot, Vlad
			alct_data =  alct_data ^ 0x1FBFFFF0;
			alct_data = (alct_data>>4);	// rx4 is the ALCT lsb

			// Compare ALCT read data to ALCT write data
			if ((alct_data!=(1<<itx) || (alct_lsbs!=alct_expect) && (!debug_loop || debug_beep)) || debug_step)
			{
				alct_err++;

				if (ifunc>=0)
				{
					rat_nfailed[itest]=1;
					fprintf(test_file,"Failed ALCT bit=%2i wr=%8.8X rd=%8.8X %c\n",(1<<itx),alct_data,bell);
					fprintf(stdout ,"\tFailed ALCT bit=%2i wr=%8.8X rd=%8.8X %c\n",(1<<itx),alct_data,bell);

					printf("\tSkip, Loop, Debug, Continue <cr> ");

					gets(line);
					n = strlen(line);
					i = line[0];

					debug_beep = false;

					if (n==1 && (i=='S' || i=='s')) {rat_nskipped[itest]=1; goto L25260;};
					if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					if (n==1 && (i=='D' || i=='d'))  debug_step = true;

				}	// close if ifunc
			}	// close if alct_data

			// Close loops
		}	// close for itx 25255
		if (debug_loop || debug_step) goto L25251;
	}	// close for ipass 25256

	// ALCT passes
	if (rat_nfailed[itest]==0) rat_npassed[itest]=1;	
	aokf("RAT: ALCT SCSI Cable Loopback",itest,rat_npassed[itest]);
	if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

L25260:;

	   //------------------------------------------------------------------------------
	   //	RAT Full Auto Test:
	   //	ALCT txoe, rxoe, loop signal tests
	   //------------------------------------------------------------------------------
L2580:
	   //	itest=12,13,14

	   // Loop over signal to be tested
	   for (irtest=1; irtest<=3; ++irtest)	// 25275
	   {
		   itest = irtest+11;

		   if (irtest==1) {		// disable txoe
			   alct_rxoe = 1;
			   alct_txoe = 0;
			   alct_loop = 1;
		   }
		   else if (irtest==2) {	// disable rxoe
			   alct_rxoe = 0;
			   alct_txoe = 1;
			   alct_loop = 1;
		   }
		   else if (irtest==3) {	// disable loop
			   alct_rxoe = 1;
			   alct_txoe = 1;
			   alct_loop = 0;
		   }

		   // Loop over signals enabled or disabled
		   for (imode=0; imode<=1; ++imode)	// 25272
		   {
			   // Set txoe,rxoe,loop
			   adr     = vme_loopbk_adr+base_adr;
			   status  = vme_read(adr,rd_data);
			   wr_data = rd_data & 0xFFF1;		// clear out previous [3:1]
			   if (imode==0) {					// disable a signal
				   wr_data = wr_data | (alct_loop << 1);
				   wr_data = wr_data | (alct_rxoe << 2);
				   wr_data = wr_data | (alct_txoe << 3);
			   }
			   else {
				   wr_data = rd_data | 0xE;		// enable all signals
			   }

			   status = vme_write(adr,wr_data);
			   dprintf(test_file,"RAT: itest=%2i imode=%1i adr=%6.6X wr_data=%4.4X\n",itest,imode,adr,wr_data);

			   // Toggle all ALCT bits
			   for (i=0; i<=1; ++i)	// 25270
			   {
				   // write all 0s or all 1s to alct transmitter
				   wr_data = (i<<(23-19));
				   adr	 = alct_txb_adr + base_adr;
				   status	 = vme_write(adr,wr_data);

				   if (i==0) {		// send all 0's to alct transmitter
					   status	 = vme_write (adr=(tmb_boot_adr+base_adr),wr_data=sel_boot_jtag);
					   status	 = vme_write (adr=(alct_txa_adr+base_adr),wr_data=0);
					   status	 = vme_write (adr=(alct_txb_adr+base_adr),wr_data=0);
					   status	 = vme_write (adr=(vme_step_adr+base_adr),wr_data=sel_step_alct);
				   }
				   else {			// send all 1's to alct transmitter
					   wr_data = 0x1F | sel_boot_jtag;				// [4:0]
					   adr	 = tmb_boot_adr + base_adr;
					   status	 = vme_write(adr,wr_data);

					   wr_data = 0x1FFF;								// [17:5]
					   adr	 = alct_txa_adr + base_adr;
					   status	 = vme_write(adr,wr_data);

					   wr_data = (1<<8) | sel_boot_jtag;				// [18]
					   adr	 = tmb_boot_adr + base_adr;
					   status	 = vme_write(adr,wr_data);

					   wr_data = 0x0001 | sel_step_alct;				// [20]
					   adr	 = vme_step_adr + base_adr;
					   status	 = vme_write(adr,wr_data);

					   wr_data = 0x003F;								// [24:19] skips 20
					   adr	 = alct_txb_adr + base_adr;
					   status	 = vme_write(adr,wr_data);		
				   }

				   // Read alct receivers
				   alct_data = 0;

				   for (ireg=0; ireg<=3; ++ireg) {
					   adr		= base_adr+alct_rxa_adr+2*ireg;
					   status	= vme_read(adr,rd_data);
					   rd_data   = rd_data & 0xFF;
					   alct_data = alct_data | (rd_data<<(ireg*8));
				   }

				   // Read back TDO rx[0], merge with rx[28:1]
				   adr		  = tmb_boot_adr + base_adr;
				   status	  = vme_read(adr,rd_data);
				   alct_tdo  = rd_data;
				   alct_tdo  = alct_tdo & 0x1;
				   alct_lsbs = alct_data ^ 0xF;		// invert
				   alct_lsbs = alct_lsbs & 0xE;		// trim off [28:4]
				   alct_lsbs = alct_lsbs | alct_tdo;	// invert [3:1] add [0]

				   // Check expected ALCT receiver data
				   //	test 1 disable txoe, so all receiver inputs (except loop driven) should go high
				   //	test 2 disable rxoe, so all receiver outputs should float...dunno what to expect
				   //	test 3 disable loop, should stop writing to alct_rx[3:0] alct_rx[28:25]
				   //
				   //	mode 0 disable one of the signals
				   //	mode 1 enable all signals, for normal test runs
				   //
				   //	i=0 sets all alct_tx bits to 0
				   //	i=1 sets all alct_rx bits to 1

				   if (irtest==1 && imode==0 && i==0) alct_expect = 0x1F00000E;
				   if (irtest==1 && imode==0 && i==1) alct_expect = 0x00000000;

				   if (irtest==1 && imode==1 && i==0) alct_expect = 0x1FBFFFFE;
				   if (irtest==1 && imode==1 && i==1) alct_expect = 0x004001F0;

				   if (irtest==2 && imode==0 && i==0) alct_expect = 0x004001F0;
				   if (irtest==2 && imode==0 && i==1) alct_expect = 0x004001F0;

				   if (irtest==2 && imode==1 && i==0) alct_expect = 0x1FBFFFFE;
				   if (irtest==2 && imode==1 && i==1) alct_expect = 0x004001F0;

				   if (irtest==3 && imode==0 && i==0) alct_expect = 0x01BFFFF0;
				   if (irtest==3 && imode==0 && i==1) alct_expect = 0x1E4001FE;

				   if (irtest==3 && imode==1 && i==0) alct_expect = 0x1FBFFFFE;
				   if (irtest==3 && imode==1 && i==1) alct_expect = 0x004001F0;

				   if (irtest==1 && imode==0) {				// test 100,101 have variable results
					   alct_data=alct_expect;
				   }

				   if (irtest==3 && imode==0 && i==0) {		// test 300 has variable results
					   alct_data   = alct_data   & 0x001FFFF0;
					   alct_expect = alct_expect & 0x001FFFF0;
				   }

				   if (irtest==3 && imode==0 && i==1) {		// test 301 has variable results
					   alct_data  = alct_data   & 0x001FFFF0;
					   alct_expect= alct_expect & 0x001FFFF0;
				   }

				   if (alct_data!=alct_expect) {
					   rat_nfailed[itest]=1;
					   alct_err++;
					   if (!debug_loop) printf("\tALCT control signal error: irtest=%2i imode=%1i i=%1i read=%8.8X expect=%8.8X\n",irtest,imode,i,alct_data,alct_expect);
				   }

			   }	// close for i     25270
		   }	// close for imode 25272

		   // Results
		   if (rat_nfailed[itest]==0) rat_npassed[itest]=1;

		   if (irtest==1) aokf("RAT: ALCT txoe signal",itest,rat_npassed[itest]);
		   if (irtest==2) aokf("RAT: ALCT rxoe signal",itest,rat_npassed[itest]);
		   if (irtest==3) aokf("RAT: ALCT loop signal",itest,rat_npassed[itest]);

		   if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	   }	// close for irtet 25275

	   //------------------------------------------------------------------------------
	   //	RAT Full Auto Test:
	   //	RPC SCSI Cable Loopback
	   //
	   //	itest=15 rpc0 loop
	   //	itest=16 rpc0 ddd
	   //	itest=17 rpc1 loop
	   //	itest=18 rpc1 ddd
	   //
	   //------------------------------------------------------------------------------
	   for (irpc=0; irpc<=1; ++irpc)	// 2590	test rpc loop: itest=15,17, ddd section increments itest for 16,18
	   {

		   itest=15+irpc*2;

		   // Inform the biounit its time to move the cable
		   printf("\n");
		   printf("\tRAT: RPC SCSI Cable Loopback Test:\n");
		   printf("\tConnect a 25pr cable from RAT ALCTtx to RPC%i\n",irpc);
		   printf("\tSkip, Loop, Debug, Continue <cr> ");

		   gets(line);
		   n = strlen(line);
		   i = line[0];

		   debug_beep = false;

		   if (n==1 && (i=='S' || i=='s')) {rat_nskipped[itest]=1; goto L25470;};
		   if (n==1 && (i=='L' || i=='l')) {debug_loop = true; debug_beep = true;}
		   if (n==1 && (i=='D' || i=='d'))  debug_step = true;

		   // Turn on 40MHz FPGA output to drive RPC input clock
		   adr    = vme_ratctrl_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   rat_ctrl_data = rd_data;
		   wr_data = rd_data & 0xFFDF;		// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
		   wr_data = wr_data | 0x0020;		// 	enable clock bit
		   status  = vme_write(adr,wr_data);


		   // Take ALCT out of loopback mode, enable CFEBs, and RAT ALCT SCSI
		   sel_boot_jtag = 0x0080;
		   sel_loopbk    = 0x0A8D;			//was 0A8D // Enable RAT, disable front SCSI, was a81 for tmb2004
		   adr		= vme_loopbk_adr + base_adr;
		   wr_data = sel_loopbk;
		   status	= vme_write(adr,wr_data);


		   // Turn off step mode
		   //turns RPCrx into a 40 Mhz clock for some reason..
		   wr_data = 0x1FE0;
		   adr	    = vme_step_adr + base_adr;
		   status	= vme_write(adr,wr_data);


		   // Turn off step mode (needed for DDD chips next test) 
		   //sel_step_alct = 0x1FE0;
		   //adr     = vme_step_adr+base_adr;
		   //wr_data = sel_step_alct;
		   //status  = vme_write(adr,wr_data);

		   // Take TMB and RAT out of loop-back mode
		   adr	    = vme_loopbk_adr+base_adr;
		   status  = vme_read(adr,rd_data);
		   wr_data = rd_data & 0xFFCD;			// turn off RPC loop bits
		   status  = vme_write(adr,wr_data);

		   // Take RAT out sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
		   adr	    = rpc_txb_adr+base_adr;
		   wr_data = 0x0002;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
		   status  = vme_write(adr,wr_data);

		   adr    = vme_ratctrl_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   wr_data = rd_data & 0xFFFA;		// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
		   wr_data = wr_data | 0x0020;		// 	enable clock bit
		   wr_data = wr_data | 0x03FA;
		   status  = vme_write(adr,wr_data);

		   // Set RAT clock delay
		   adr	    = base_adr+vme_ddd0_adr; 
		   status	= vme_read(adr,rd_data);
		   wr_data = rd_data & 0x0FF0;

		   //	wr_data = wr_data | (3 << 12);	// RAT delay 3  for DDR mux
		   wr_data = wr_data | (9 << 12);	// RAT delay 9 for non-DDR
		   wr_data = wr_data | (2 <<  0);	// ALCTtx delay 2

		   status  = vme_write(adr,wr_data);

		   // Start DDD state machine
		   adr	    = base_adr+vme_dddsm_adr;
		   status  = vme_read(adr,rd_data);
		   autostart = rd_data & 0x0020;	// get current autostart state
		   wr_data	= 0x0000 | autostart;	// stop machine
		   status	= vme_write(adr,wr_data);
		   wr_data = 0x0001 | autostart;	// start machine
		   status	= vme_write(adr,wr_data);
		   wr_data = 0x0000 | autostart;	// unstart machine
		   status	= vme_write(adr,wr_data);

		   // Loop over repeat-passes
		   npasses = 1000;

		   for (ipass=1; ipass<=npasses; ++ipass)	// 25465
		   {
			   if (ipass%10==0      ) printf("\tRPC cable: Running loopback test %4i \r",npasses-ipass);
			   if (ipass   ==npasses) printf("\t                                      \r");

L25461:	
			   rpc_err = 0;

			   // Send walking 1s to ALCT transmitter
			   for (itx=0; itx<=18; ++itx)	// 25464
			   {
				   wr_pat    = (1<<itx);
				   wr_pat_ck = wr_pat;

				   if (itx>=16)  
					   wr_pat = (wr_pat<<1);		// skip alct_tx16. tmb bdtest firmware sends rpc clock on alct_tx[16]

				   wr_pat_vlad = wr_pat ^0x00AEAAAA;		// pre-invert  ALCT tx data so RPC sees all 0s + 1

				   jtag_alct        = (wr_pat_vlad >>  0) & 0x001F;	// tx[4:0]
				   alct_tx_lo       = (wr_pat_vlad >>  5) & 0x1FFF;	// tx[17:5]
				   nhard_reset_alct = (wr_pat_vlad >> 18) & 0x0001;	// tx[18]	inverted on tmb
				   alct_tx_hi       = (wr_pat_vlad >> 19) & 0x001F;	// tx[23:19]

				   //reset; blank alct_hard_reset bit
				   wr_data = sel_boot_jtag & 0xFEFF;		
				   wr_data = wr_data | (nhard_reset_alct<<8);
				   wr_data	= wr_data | jtag_alct;
				   status	= vme_write(adr=(tmb_boot_adr+base_adr),wr_data);

				   // Send Patterns to ALCT output registers
				   status	= vme_write(adr=(alct_txa_adr+base_adr),wr_data=(alct_tx_lo));
				   status	= vme_write(adr=(alct_txb_adr+base_adr),wr_data=alct_tx_hi);

				   for (i=0; i<38; ++i);
				   rpc_data[i]=0;

				   // Read back RPC data registers
				   status	= vme_read(adr=(rpc_rxa_adr+base_adr),rpc_rxa);	// 1st in time
				   status	= vme_read(adr=(rpc_rxb_adr+base_adr),rpc_rxb);
				   status	= vme_read(adr=(rpc_rxc_adr+base_adr),rpc_rxc);

				   status	= vme_read(adr=(rpc_rxd_adr+base_adr),rpc_rxd);	// 2nd in time
				   status	= vme_read(adr=(rpc_rxe_adr+base_adr),rpc_rxe);
				   status	= vme_read(adr=(rpc_rxf_adr+base_adr),rpc_rxf);

				   //printf("rpc_rxa=%4.4X rpc_rxb=%4.4X rpc_rxc=%4.4X rpc_rxd=%4.4X rpc_rxe=%4.4X rpc_rxf=%4.4X\n",rpc_rxa,rpc_rxb,rpc_rxc,rpc_rxd,rpc_rxe,rpc_rxf); 			
				   dprintf(test_file,"rpc_rxa=%4.4X rpc_rxb=%4.4X rpc_rxc=%4.4X rpc_rxd=%4.4X rpc_rxe=%4.4X rpc_rxf=%4.4X\n",rpc_rxa,rpc_rxb,rpc_rxc,rpc_rxd,rpc_rxe,rpc_rxf); 			

				   // Assemble rpc data words a,b,c=1st[37:0] d,e,f=2nd[37:0]
				   rpc_rx[0] = rpc_rxa & 0xFFFF;				// rx[15:0]	pack [15: 0]	// 1st in time
				   rpc_rx[1] = rpc_rxb & 0xFFFF;				// rx[15:0]	pack [34:19]	// 1st in time

				   rpc_bxn[0]= (rpc_rxc >> 0) & 0x0007;		// bxn[2:0]	pack [18:16]
				   rpc_bxn[1]= (rpc_rxc >> 3) & 0x0007;		// bxn[2:0]	pack [37:35]

				   rpc_rx[2] = rpc_rxd & 0xFFFF;				// rx[15:0]	pack [15: 0]	// 1st in time
				   rpc_rx[3] = rpc_rxe & 0xFFFF;				// rx[15:0]	pack [34:19]	// 1st in time

				   rpc_bxn[2]= (rpc_rxf >> 0) & 0x0007;		// bxn[2:0]	pack [18:16]
				   rpc_bxn[3]= (rpc_rxf >> 3) & 0x0007;		// bxn[2:0]	pack [37:35]

				   // Repack bxn, invert lvds bits
				   for (i=0; i<=3; ++i) {
					   rpc_word[i] = (rpc_rx[i] | (rpc_bxn[i]<<16));		// append bxn to rpc data
					   //rpc_word[i] = (rpc_word[i] ^ 007FFFF);				// invert bits 18:0, 2/23/2006 we dont invert in rat any more, so dont uninvert here
					   dprintf(test_file,"rpc%i1 rpc_rx=%4.4X rpc_bxn=%4.4X\n",i,rpc_rx[i],rpc_bxn[i]);
				   }

				   // Compare RPC read data to ALCT write data
				   if (ipass>=npasses-1) rpc_word[irpc]=wr_pat_ck;		// temporary for rev 1 boards, rev 2 will not latch new data

				   if ((rpc_word[irpc]!=wr_pat_ck || debug_step) && (!debug_loop || debug_beep)) {
					   rat_nfailed[itest]=1;
					   rpc_err++;
					   fprintf(stdout, "\tRPC: Failed irpc=%1i bit=%2i wr=%6.6X rd=%6.6X pass=%9i\n",irpc,itx,wr_pat_ck,rpc_word[irpc],ipass);
					   fprintf(test_file,"RPC: Failed irpc=%1i bit=%2i wr=%6.6X rd=%6.6X pass=%9i\n",irpc,itx,wr_pat_ck,rpc_word[irpc],ipass);

					   printf("\tSkip, Loop, Debug, Continue <cr> ");

					   gets(line);
					   n = strlen(line);
					   i = line[0];

					   debug_beep = false;

					   if (n==1 && (i=='S' || i=='s')) {rat_nskipped[itest]=1; goto L25470;};
					   if (n==1 && (i=='L' || i=='l'))  debug_loop = true;
					   if (n==1 && (i=='D' || i=='d'))  debug_step = true;
				   }	// close if rpc_word

				   // Close itx loop
			   }	// close for itx 25464

			   if (debug_loop) goto L25461;

			   // On next to last pass, turn off this RPCs receiver enables
			   //	npasses-2	disable rpc,    checked on npasses-1
			   //	npasses-1	re-enable rpc   checked on npasses
			   //	npasses		do nothing		not checked, cuz switching to next rpc
			   if (ipass<=npasses-3) goto L25465;

			   // Select RAT JTAG chain from TMB boot register
			   ichain = 0x000D;								// RAT jtag chain
			   adr    = boot_adr;								// Boot register address
			   vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI

			   // Read current RAT USER2
			   chip_id = 0;
			   opcode  = 0x03;									// FPGA USER2 opcode
			   reg_len = 32;									// USER2 register length, 3d rat
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
			   dprintf("tdo="); 
			   for (i=0; i<reg_len; ++i) dprintf("%1i",tdo[i]); dprintf("\n");

			   // Set new RAT USER2 bits to enable or disable rpcs
			   ibit = 0;
			   if (ipass==npasses-3) ibit=1;	// will disable this rpc
			   if (ipass==npasses-2) ibit=0;	// will re-enable this rpc
			   ival = (1<<irpc);				// 01 for rpc0, 10 for rpc1
			   ival = ival ^ 0x3;				// 10 for rpc1, 01 for rpc1, disables current rpc
			   if (ipass>=npasses-1) ival=0x3;

			   bit_to_array(ival,ivalarray,reg_len);
			   for (i=0; i<reg_len; ++i) rsd[i]=ivalarray[i];

			   // Write RAT USER2 register (5 bit opcode)
			   chip_id = 0;
			   opcode  = 0x03;								// VirtexE USER2 opcode
			   reg_len = 32;								// Register length
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

			   // RPC passes loop
L25465:;
		   }	// close ipass 25465

		   // Take RAT out of sync mode
		   wr_data = 0x0000;	// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
		   adr	    = rpc_txb_adr+base_adr;
		   status  = vme_write(adr,wr_data);

		   sprintf(cid, "%1i",  irpc);
		   sid  = string(cid);

		   if (rat_nfailed[itest]==0) rat_npassed[itest]=1;	
		   aokf(string("RPC").append(sid).append(string("RAT SCSI Cable Loopback")),itest,rat_npassed[itest]);
		   if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

		   // Done rpc loop test
L25470:;

	   //------------------------------------------------------------------------------
	   //	RAT Full Auto Test:
	   //	DDD Delays
	   //
	   //	itest=16,18
	   //------------------------------------------------------------------------------
	   //L2550:
	   itest=16+irpc*2;

	   // Prompt for scope connections
	   printf("\n");
	   printf("\tSet Scope Ch1 & Ch2 to 2V/division\n");
	   printf("\tSet Scope View Persistence to 1.2 sec\n");
	   printf("\tSet Scope to trigger on Ch1, display Ch2 only\n");
	   printf("\tConnect Scope Ch1 to 40MHz CLK at TP501 on TMB\n");

	   printf("\n");
	   printf("\tEnter F to fail a delay channel\n");
	   printf("\tEnter P to pass a delay channel\n");
	   printf("\tEnter S to skip a delay channel\n");
	   printf("\n");

	   // Turn off step mode //Andrew
	   sel_step_alct = 0x1FE0;
	   adr     = vme_step_adr+base_adr;
	   wr_data = sel_step_alct;
	   status  = vme_write(adr,wr_data);

	   // Turn on 40MHz FPGA output to drive RPC input clock
	   adr     = vme_ratctrl_adr+base_adr;
	   status  = vme_read(adr,rd_data);
	   rat_ctrl_data = rd_data;
	   wr_data = rd_data | 0x0020;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
	   status  = vme_write(adr,wr_data);

	   // Select RAT JTAG chain from TMB boot register
	   ichain = 0x000D;							// RAT jtag chain
	   adr    = boot_adr;							// Boot register address
	   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

	   // Create fat 0 for writing to data registers
	   for (i=1; i<mxbitstream; ++i) tdi[i]=0;

	   // Read current RAT USER2 register (5 bit opcode), readout is destructive
	   chip_id = 0;
	   opcode  = 0x03;								// FPGA USER2 opcode
	   reg_len = 32;								// USER2 register length, 3d rat
	   adr     = boot_adr;							// Boot register address
	   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
	   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
	   dprintf("tdo="); for (i=0; i<reg_len; ++i) dprintf("%1i",tdo[i]); dprintf("\n");

	   // Decode USER2 data
	   for (i=1; i<reg_len; ++i) wso[i]=tdo[i];

	   tdi_to_i4(tdo,rat_user2[0],32,0);
	   dprintf("\tRAT USER2=%8.8X\n",rat_user2[0]);

	   tdi_to_i4(&wso[ 0],ws_rpc_en,	  2,0);
	   tdi_to_i4(&wso[ 2],ws_ddd_start,  1,0);
	   tdi_to_i4(&wso[ 3],ws_ddd_wr,    16,0);
	   tdi_to_i4(&wso[19],ws_dddoe_wr,	  4,0);
	   tdi_to_i4(&wso[23],ws_perr_reset, 1,0);
	   tdi_to_i4(&wso[24],ws_parity_odd, 1,0);
	   tdi_to_i4(&wso[25],ws_perr_ignore,1,0);
	   tdi_to_i4(&wso[26],ws_rpc_future, 6,0);

	   // Loop DDD channels, delays
	   //	for (ich=0; ich<=1; ++ich) {	// 2570 loop starts in rpc test section now
	   //	itest=17+ich;

	   ich = irpc;
	   printf("\tScope Ch2: U34 3D3444 test point CD%1i [P,F,S]\n",ich);

L25171:
	   for (ddd_delay=0; ddd_delay<=12; ++ddd_delay)	// 2560
	   {

		   // Set new RAT USER2 bits, sets new DDD delay values and un-starts state machine
		   reg_len      = 32;									// USER2 register length, 3d rat
		   ws_ddd_wr    = (ddd_delay<<ich*4);
		   ws_ddd_start = 0;
		   ws_rpc_en    = 0x3;
		   ws_dddoe_wr  = 0x3;

		   bit_to_array(ws_rpc_en,     &ivalarray[ 0],2);
		   bit_to_array(ws_ddd_start,  &ivalarray[ 2],1);
		   bit_to_array(ws_ddd_wr,     &ivalarray[ 3],16);
		   bit_to_array(ws_dddoe_wr,   &ivalarray[19],4);
		   bit_to_array(ws_perr_reset, &ivalarray[23],1);
		   bit_to_array(ws_parity_odd, &ivalarray[24],1);
		   bit_to_array(ws_perr_ignore,&ivalarray[25],1);
		   bit_to_array(ws_rpc_future, &ivalarray[26],6);

		   for (i=0; i<reg_len; ++i) rsd[i]=ivalarray[i];

		   // Write RAT USER2 register (5 bit opcode)
		   chip_id = 0;
		   opcode  = 0x03;								// FPGA USER2 opcode
		   reg_len = 32;								// USER2 register length, 3d rat
		   adr     = boot_adr;							// Boot register address
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

		   // Check that DDD state machine went idle
		   ichain = 0x000D;							// RAT jtag chain
		   adr    = boot_adr;							// Boot register address
		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

		   chip_id = 0;
		   opcode  = 0x02;								// FPGA USER1 opcode
		   reg_len = 224;								// USER1 register length, 3D rats after 11/30/05
		   adr     = boot_adr;							// Boot register address
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		   for (i=0; i<reg_len; ++i) rs[i]=tdo[i];

		   tdi_to_i4(&tdo[  0],rat_user1[0],32,0);
		   tdi_to_i4(&tdo[ 32],rat_user1[1],32,0);
		   tdi_to_i4(&tdo[ 64],rat_user1[2],32,0);
		   tdi_to_i4(&tdo[ 96],rat_user1[3],32,0);
		   tdi_to_i4(&tdo[128],rat_user1[4],32,0);
		   tdi_to_i4(&tdo[160],rat_user1[5],32,0);
		   tdi_to_i4(&tdo[192],rat_user1[6],32,0);

		   tdi_to_i4(&rs[80],rs_ddd_busy,1,0);

		   if (rs_ddd_busy!=0) {
			   rat_nfailed[itest]=1;
			   fprintf(test_file,"ERROR: RAT 3D3444 State Machine stuck busy\n");
			   pause("\tERROR: RAT 3D3444 State Machine stuck busy");
		   }

		   // Start DDD state machine
		   ws_ddd_start = 1;
		   reg_len      = 32;							// USER2 register length, 3d rat
		   bit_to_array(ws_ddd_start,&ivalarray[2],1);

		   for (i=0; i<reg_len; ++i) rsd[i]=ivalarray[i];

		   chip_id = 0;
		   opcode  = 0x03;								// FPGA USER2 opcode
		   reg_len = 32;								// USER2 register length, 3d rat
		   adr     = boot_adr;							// Boot register address
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

		   // Check that state machine went busy
		   ichain = 0x000D;							// RAT jtag chain
		   adr    = boot_adr;							// Boot register address
		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

		   chip_id = 0;
		   opcode  = 0x02;								// FPGA USER1 opcode
		   reg_len = 224;								// USER1 register length, 3D rats after 11/30/05
		   adr     = boot_adr;							// Boot register address
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		   for (i=0; i<reg_len; ++i) rs[i]=tdo[i];

		   tdi_to_i4(&tdo[  0],rat_user1[0],32,0);
		   tdi_to_i4(&tdo[ 32],rat_user1[1],32,0);
		   tdi_to_i4(&tdo[ 64],rat_user1[2],32,0);
		   tdi_to_i4(&tdo[ 96],rat_user1[3],32,0);
		   tdi_to_i4(&tdo[128],rat_user1[4],32,0);
		   tdi_to_i4(&tdo[160],rat_user1[5],32,0);
		   tdi_to_i4(&tdo[192],rat_user1[6],32,0);

		   tdi_to_i4(&rs[80],rs_ddd_busy,1,0);

		   if (rs_ddd_busy!=1) {
			   rat_nfailed[itest]=1;
			   fprintf(test_file,"ERROR: RAT 3D3444 State Machine failed to go busy\n");
			   pause("\tERROR: RAT 3D3444 State Machine failed to go busy");
		   }

		   // Un-start DDD state machine, it completes in a few microseconds
		   ws_ddd_start = 0;
		   reg_len      = 32;							// USER2 register length, 3d rat
		   bit_to_array(ws_ddd_start,&ivalarray[2],1);

		   for (i=0; i<reg_len; ++i) rsd[i]=ivalarray[i];

		   chip_id = 0;
		   opcode  = 0x03;								// FPGA USER2 opcode
		   reg_len = 32;								// USER2 register length, 3d rat
		   adr     = boot_adr;							// Boot register address
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,rsd,tdo,reg_len);	// Write data

		   // Check that machine went un-busy and verifed DDD data OK
		   ichain = 0x000D;							// RAT jtag chain
		   adr    = boot_adr;							// Boot register address
		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

		   adr     = boot_adr;							// Boot register address
		   ichain  = 0x000D;							// RAT jtag chain
		   chip_id = 0;
		   opcode  = 0x02;								// FPGA USER1 opcode
		   reg_len = 224;								// USER1 register length, 3D rats after 11/30/05
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		   for (i=1; i<reg_len; ++i) rs[i]=tdo[i];

		   tdi_to_i4(&tdo[  0],rat_user1[0],32,0);
		   tdi_to_i4(&tdo[ 32],rat_user1[1],32,0);
		   tdi_to_i4(&tdo[ 64],rat_user1[2],32,0);
		   tdi_to_i4(&tdo[ 96],rat_user1[3],32,0);
		   tdi_to_i4(&tdo[128],rat_user1[4],32,0);
		   tdi_to_i4(&tdo[160],rat_user1[5],32,0);
		   tdi_to_i4(&tdo[192],rat_user1[6],32,0);

		   tdi_to_i4(&rs[80],rs_ddd_busy,     1,0);
		   tdi_to_i4(&rs[81],rs_ddd_verify_ok,1,0);

		   // Check busy+verify bits
		   if (rs_ddd_busy!=0) {
			   rat_nfailed[itest]=1;
			   fprintf(test_file,"ERROR: RAT 3D3444 State Machine stuck busy.\n");
			   fprintf(stdout, "\tERROR: RAT 3D3444 State Machine stuck busy.\n");
		   }

		   if (rs_ddd_verify_ok!=1) {
			   fprintf(test_file,"ERROR: RAT 3D3444 State Machine failed to verify.\n");
			   fprintf(stdout, "\tERROR: RAT 3D3444 State Machine failed to verify.\n");
		   }

		   // Hold this delay for scope persistence
		   if (ddd_delay==0) msec = 600;			// Hold at 0 delay for a moment
		   else              msec = 100;
		   sleep(msec);

		   // Check for keyboard input
		   if (!_kbhit()) goto L2560;			// Check for keyboard hit
		   ckey = _getch();					// Read key
		   printf("\tKey pressed=%c\n",ckey);

		   if (ckey=='e' || ckey=='E') {goto rat_auto_done;}					// Exit
		   if (ckey=='p' || ckey=='P') {goto L25173;}							// Channel passes,  go to next channel
		   if (ckey=='s' || ckey=='S') {tmb_nskipped[itest]=1;	goto L25173;}	// Channel skipped, go to next channel
		   if (ckey=='f' || ckey=='F') {tmb_nfailed[itest] =1; goto L25173;}	// Channel failed,  go to next channel

L2560:;				// next delay
	   }				// close for ddd_delay 2560
	   goto L25171;	// keep on this channel until key pressed

	   // Change to next channel
L25173:
	   sprintf(cid,  "%1i", ichip);
	   sprintf(cidc, "%1i", ich  );

	   sid  = string(cid);
	   sidc = string(cidc);

	   if (rat_nfailed[itest]==0) rat_npassed[itest]=1;
	   aokf(string("RAT 3D3444 Delay Chip ").append(sid).append(string(" Channel ")).append(sidc),itest,rat_npassed[itest]);
	   if (pause_on_fail && rat_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	   // 2570	continue	// close ich, replaced by  loop 2590
	   // close irpc loop 2590, include RPC loop tests and ddd delay tests
	   }

	   // Turn off 40MHz FPGA output to drive RPC input clock
	   adr     = vme_ratctrl_adr+base_adr;
	   status  = vme_read(adr,rd_data);
	   rat_ctrl_data = rd_data;
	   wr_data = rd_data & 0xFFDF;	// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0 [4]=dsn en [5]=clock en
	   status  = vme_write(adr,wr_data);

	   //------------------------------------------------------------------------------
	   //	RAT Full Auto Test:
	   //	LEDs
	   //------------------------------------------------------------------------------
	   //L25187:
	   itest=19;

	   // Cool down the stinkin RAT, revert to idle loop state
	   adr     = vme_loopbk_adr + base_adr;
	   wr_data = loopstate;
	   status	= vme_write(adr,wr_data);

	   // Put RAT in sync mode, select posneg=1 to sync to rising edge of tmb clock in spartan
	   wr_data = 0x0003;					// 	[0]=sync_mode [1]=posneg [2]=loop_tmb [3]=free_tx0
	   adr	    = rpc_txb_adr+base_adr;
	   status  = vme_write(adr,wr_data);

	   printf("\n\tLED Check:\n");

	   ledtest[0] = pass_fail("\tAre all 8 RAT Panel LEDs OK?          [P,F]<cr> ");
	   ledtest[1] = pass_fail("\tAre all 3 Staus LEDs on? DF1 DF2 DF3? [P,F]<cr> ");
	   printf("\n");

	   for (i=0; i<=1; ++i) {
		   if (ledtest[i]==false) tmb_nfailed[itest]=1;
		   fprintf(test_file,"\tLED test [%1i] = %c\n",i,logical(ledtest[i]));
	   }

	   if (tmb_nfailed[itest]==0) tmb_npassed[itest]=1;
	   aokf("RAT LEDs",itest,tmb_npassed[itest]);
	   if (pause_on_fail && tmb_nfailed[itest]!=0) pause("\tFailed. <cr> to continue anyway");

	   //------------------------------------------------------------------------------
	   //	RAT Full Auto Test:
	   //	Future tests go here
	   //------------------------------------------------------------------------------
	   //	futcha

	   //------------------------------------------------------------------------------
	   //	RAT Full Auto Test:
	   //	Done
	   //------------------------------------------------------------------------------
	   // Enumerate
rat_auto_done:

	   rat_nfail = 0;
	   rat_npass = 0;
	   rat_nskip = 0;

	   for (itest=1; itest<=rat_ntests; ++itest) {
		   rat_nfail = rat_nfail + rat_nfailed[itest];
		   rat_npass = rat_npass + rat_npassed[itest];
		   rat_nskip = rat_nskip + rat_nskipped[itest];
	   }

	   fprintf(test_file,"\ttest:"); for(i=1;i<=rat_ntests;++i) fprintf(test_file,"%1i",i/10           ); fprintf(test_file,"\n");
	   fprintf(test_file,"\ttest:"); for(i=1;i<=rat_ntests;++i) fprintf(test_file,"%1i",i%10           ); fprintf(test_file,"\n");
	   fprintf(test_file,"\tpass:"); for(i=1;i<=rat_ntests;++i) fprintf(test_file,"%1i",rat_npassed[i] ); fprintf(test_file,"\n");
	   fprintf(test_file,"\tskip:"); for(i=1;i<=rat_ntests;++i) fprintf(test_file,"%1i",rat_nskipped[i]); fprintf(test_file,"\n");
	   fprintf(test_file,"\tfail:"); for(i=1;i<=rat_ntests;++i) fprintf(test_file,"%1i",rat_nfailed[i] ); fprintf(test_file,"\n");

	   fprintf(stdout,   "\n");
	   fprintf(stdout,   "\tRAT Full Auto Tests Completed\n");
	   fprintf(stdout,   "\tTests Passed =%3i\n",rat_npass);
	   fprintf(stdout,   "\tFailed       =%3i\n",rat_nfail);
	   fprintf(stdout,   "\tSkipped      =%3i\n",rat_nskip);

	   fprintf(test_file,"\n");
	   fprintf(test_file,"\tRAT Full Auto Tests Completed\n");
	   fprintf(test_file,"\tTests Passed =%3i\n",rat_npass);
	   fprintf(test_file,"\tFailed       =%3i\n",rat_nfail);
	   fprintf(test_file,"\tSkipped      =%3i\n",rat_nskip);

	   if (rat_nfail==0 && rat_npass==rat_ntests && rat_nskip==0)
	   {
		   fprintf(stdout,   "\n");
		   fprintf(stdout,   "\t+------+\n");
		   fprintf(stdout,   "\t| PASS |\n");
		   fprintf(stdout,   "\t+------+\n");
		   fprintf(test_file,"\n");
		   fprintf(test_file,"\t+------+\n");
		   fprintf(test_file,"\t| PASS |\n");
		   fprintf(test_file,"\t+------+\n");}
	   else
	   {
		   fprintf(stdout,   "\n");
		   fprintf(stdout,   "\t+-----------------------+\n");
		   fprintf(stdout,   "\t|******** FAIL *********|\n");
		   fprintf(stdout,   "\t+-----------------------+\n");
		   fprintf(test_file,"\n");
		   fprintf(test_file,"\t+-----------------------+\n");
		   fprintf(test_file,"\t|******** FAIL *********|\n");
		   fprintf(test_file,"\t+-----------------------+\n");
	   }

	   if (test_file!=NULL) fclose(test_file);

	   if (ifunc<0) goto L2500;
	   pause ("<cr>=return to main menu");
	   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Scope snapshot of current system
	   //------------------------------------------------------------------------------
	   void L2600() {
L2600:

		   printf("\t<cr> to arm acope, else exit: ");
		   gets(line);
		   if (line[0] != NULL) return;

		   // Arm scope trigger
		   scp_arm        = true;
		   scp_readout    = false;
		   scp_raw_decode = false;
		   scp_silent     = false;
		   scp_playback   = false;

		   scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

		   // Wait a mo
		   sleep(100);

		   // Read back embedded scope data
		   scp_arm        = false;
		   scp_readout    = true;
		   scp_raw_decode = false;
		   scp_silent     = false;
		   scp_playback   = false;

		   scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);
		   goto L2600;
	   }
	   //------------------------------------------------------------------------------
	   //	Trim Vcore or Vtt
	   //------------------------------------------------------------------------------
	   void L2700() {
		   //L2700:

		   // Get current ADC values
		   adc_read(base_adr);								// Returns data via common block

		   vcore_noload = 1.525;							// Puts Vcore=1.500 at 2.5amp load, midrange of 1.425-to-1.575
		   vcore_expect = vcore_noload-a1p5core*0.010;		// Expect Vcore-Acore*.010ohms. At Acore nom=0.870A, Vcore=1.516
		   v1p0_expect  = 1.005;							// Expect 1.005+- a little

		   // Offer to trim Vtt
		   printf("\tVtt=%5.3f Target=%5.3f\n",v1p0,v1p0_expect);
		   printf("\tTrim now or skip(T,S)<cr=S>?");
		   gets(line);
		   n = strlen(line);
		   sscanf(line,"%i",&i);
		   if ((n==0) || (i=='S') || (i=='s')) goto L2750;

		   printf("\tAdjust GTLP 1.0Vref R412.\n");
		   printf("\tCtrl-C when done");

		   // Trimming Vtt
L2710:
		   adc_read(base_adr);								// Returns data via common block

		   printf("\tVtt=%5.3f Target=%5.3f\r",v1p0,v1p0_expect);
		   diff = (v1p0-v1p0_expect);
		   vtol = 0.001;

		   if      (abs(diff) <= vtol)	{Beep(600,250);}	// Just right
		   else if (diff       > vtol)	{Beep(800,250);}	// Too high
		   else						{Beep(400,250);}	// Too low

		   goto L2710;

		   // Offer to trim Vcore
L2750:
		   printf("\tVcore=%5.3f Target=%5.3f NoLoad=%5.3f Acore=%5.3f\n",v1p5core,vcore_expect,vcore_noload,a1p5core);
		   printf("\tTrim now or skip(T,S)<cr=S>?");
		   gets(line);
		   n = strlen(line);
		   sscanf(line,"%i",&i);
		   if ((n==0) || (i=='S') || (i=='s')) goto L2790;

		   printf("\tAdjust +Vcore R683.\n");
		   printf("\tCtrl-C when done, and restart test");

L2760:
		   adc_read(base_adr);								// Returns data via common block

		   printf("\tVcore=%5.3f Target=%5.3f\r",v1p5core,vcore_expect);
		   diff = (v1p5core-vcore_expect);
		   vtol = 0.001;

		   if      (abs(diff) <= vtol)	{Beep(600,250);}	// Just right
		   else if (diff       > vtol)	{Beep(800,250);}	// Too high
		   else						{Beep(400,250);}	// Too low

		   goto L2760;

		   // Future trims
L2790:
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	TMB Unjam, try to clear a jammed TMB
	   //------------------------------------------------------------------------------
	   void L2800() {
L2800:

		   // Clear boot register
		   printf("\tClearing boot register\n");

		   adr     = boot_adr;
		   wr_data = 0x0000;
		   status  = vme_write(adr,wr_data);			// Assert hard reset
		   sleep(110);									// Wait at least 101msec for reboot

		   // FPGA PROMs
		   ijtag_src = 1;								// use boot register jtag

		   // Select FPGA Mezzanine FPGA programming JTAG chain from TMB boot register
		   printf("\tClearing JTAG chains\n");

		   ichain = 0x0004;							// TMB Mezzanine pgm jtag chain
		   if (ijtag_src == 0) adr = vme_usr_jtag_adr+base_adr;
		   if (ijtag_src == 1) adr = boot_adr;

		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

		   // Read Virtex2 FPGA (6-bit opcode) and XC18V04 PROM IDcodes (8-bit opcode)
		   printf("\tReading TMB PROM data\n");

		   for (chip_id=0; chip_id<=4; ++chip_id) {
			   if (chip_id == 0)opcode = 0x09;				// FPGA IDcode opcode, expect v0A30093
			   if (chip_id >= 1)opcode = 0xFE;				// PROM IDcode opcode
			   reg_len = 32;								// IDcode length
			   // FPGA,PROM chip
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		   } // close for chip_id

		   // Read FPGA/PROM USERCodes (8 bit opcode)
		   for (chip_id=0; chip_id<=4; ++chip_id) {
			   if (chip_id == 0)opcode = 0x08;				// FPGA USERcode opcode
			   if (chip_id == 1)opcode = 0xFD;				// PROM USERcode opcode
			   reg_len = 32;								// IDcode length
			   // FPGA,PROM chip
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		   } // close for chip_id

		   // User PROMs
		   ichain = 0x0008;							// User PROM chain
		   if (ijtag_src == 0) adr = vme_usr_jtag_adr+base_adr;
		   if (ijtag_src == 1) adr = boot_adr;
		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI
		   opcode  = 0xFE;								// IDcode opcode
		   reg_len = 32;								// IDcode length

		   for (chip_id=0; chip_id<=1; ++chip_id) {
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		   } // close for chip_id

		   // Read User PROM data
		   for(iprom=0; iprom<=1; ++iprom) {
			   jprom = (iprom+1)%2;

			   prom_clk[iprom] = 0;	// enable this one
			   prom_oe[iprom]  = 1;
			   prom_nce[iprom] = 0;

			   prom_clk[jprom] = 0;	// disble this one
			   prom_oe[jprom]  = 0;
			   prom_nce[jprom] = 1;
			   prom_src        = 1;

			   adr     = vme_prom_adr+base_adr;

			   wr_data = 
				   (prom_src    << 14) |
				   (prom_nce[1] << 13) |
				   (prom_oe[1]  << 12) |
				   (prom_clk[1] << 11) |
				   (prom_nce[0] << 10) |
				   (prom_oe[0]  <<  9) |
				   (prom_clk[0] <<  8);

			   status  = vme_write(adr,wr_data);

			   // Read data from selected PROM

			   for (prom_adr=0; prom_adr<=15; ++prom_adr)
			   {
				   status = vme_read(adr,rd_data);
				   prom_data = rd_data & 0xFF;

				   // Toggle clock to advance address
				   prom_clk[iprom] = 1;

				   wr_data = 
					   (prom_src    << 14) |
					   (prom_nce[1] << 13) |
					   (prom_oe[1]  << 12) |
					   (prom_clk[1] << 11) |
					   (prom_nce[0] << 10) |
					   (prom_oe[0]  <<  9) |
					   (prom_clk[0] <<  8);

				   status = vme_write(adr,wr_data);

				   prom_clk[iprom] = 0;

				   wr_data = 
					   (prom_src    << 14) |
					   (prom_nce[1] << 13) |
					   (prom_oe[1]  << 12) |
					   (prom_clk[1] << 11) |
					   (prom_nce[0] << 10) |
					   (prom_oe[0]  <<  9) |
					   (prom_clk[0] <<  8);

				   status = vme_write(adr,wr_data);
			   } // close for prom_adr

			   // Turn PROMs off
			   prom_clk[iprom] = 0;	// disble this one
			   prom_oe[iprom]  = 0;
			   prom_nce[iprom] = 1;
			   prom_src        = 0;

			   wr_data = 
				   (prom_src    << 14) |
				   (prom_nce[1] << 13) |
				   (prom_oe[1]  << 12) |
				   (prom_clk[1] << 11) |
				   (prom_nce[0] << 10) |
				   (prom_oe[0]  <<  9) |
				   (prom_clk[0] <<  8);

			   status = vme_write(adr,wr_data);
		   } // close for iprom

		   // RAT FPGA PROM
		   printf("\tReading RAT PROM data\n");

		   ichain = 0x000D;							// RAT jtag chain
		   if (ijtag_src == 0) adr = vme_usr_jtag_adr+base_adr;
		   if (ijtag_src == 1) adr = boot_adr;

		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

		   // Read FPGA/PROM IDcodes (8 bit opcode)
		   for (chip_id=0; chip_id<=1; ++chip_id) {
			   if (chip_id == 0) opcode = 0x09;			// FPGA IDcode opcode
			   if (chip_id == 1) opcode = 0xFE;			// PROM IDcode opcode
			   reg_len = 32;								// IDcode length

			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		   } // close for chip_id

		   // Read FPGA/PROM USERCodes (8 bit opcode)
		   for (chip_id=0; chip_id<=1; ++chip_id) {
			   if (chip_id == 0)opcode = 0x08;				// FPGA USERcode opcode
			   if (chip_id == 1)opcode = 0xFD;				// PROM USERcode opcode
			   reg_len = 32;								// IDcode length

			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
		   } // close for chip_id

		   sleep(110);

		   // Pulse boot register hard reset
		   printf("\tFiring hard reset\n");

		   adr     = boot_adr;
		   wr_data = 0x0200;
		   status  = vme_write(boot_adr,wr_data);		 // Assert hard reset

		   sleep(110);

		   adr     = boot_adr;
		   wr_data = 0x0000;
		   status  = vme_write(adr,wr_data);			// Deassert

		   sleep(500);									// Wait for TMB to reload

		   //	Go again
		   printf("\tTry again? <cr=no>: ");
		   gets(line);
		   if (line[0]==NULL) return;
		   goto L2800;
	   }
	   //------------------------------------------------------------------------------
	   //	Program Xilinx PROMs
	   //------------------------------------------------------------------------------
	   void L2900() {
L2900:

		   printf("\tXilinx PROM Chain ID Select:\n\n");
		   printf("\t 1:  ALCT Slow Control PROM\n");
		   printf("\t 3:  ALCT Mezzanine PROMs\n");
		   printf("\t 4:  TMB Mezzanine PROMs\n");
		   printf("\t 8:  TMB User PROMs\n");
		   printf("\t D:  RAT PROM\n");
		   printf("\t<cr> Exit\n");
		   printf("       > ");

		   gets(line);
		   if (line[0]==NULL) return;
		   sscanf(line,"%i",&ichain);

		   if (ichain == 0x0001) goto L2920;	// ALCT Slow Control PROM
		   if (ichain == 0x0003) goto L2920;	// ALCT Mezzanine PROMs
		   if (ichain == 0x0004) goto L2920;	// TMB Mezzanine pgm jtag chain
		   if (ichain == 0x0008) goto L2920;	// User PROM chain
		   if (ichain == 0x000D) goto L2920;	// RAT jtag chain

		   pause("Invalid chain ID");
		   goto L2900;

L2920:
		   // Get XSVF file name
		   printf("\n\tXSVF File Name: <default=%s> :",xsvf_tmb_user_default.c_str());
		   gets(line);

		   if (line[0]==NULL) {
			   printf("\tUsing default: %s\n",xsvf_tmb_user_default.c_str());
			   xsvf_file_name = xsvf_tmb_user_default;
		   }
		   else {
			   xsvf_file_name = string(line);}

		   xsvf_file = fopen(xsvf_file_name.c_str(),"rb");

		   if (xsvf_file==NULL) {
			   fprintf(stdout,"\tFailed to open %s\n",xsvf_file_name.c_str()); 
			   pause(" ");
			   goto L2900;
		   }

		   printf("\tOpened xsvf file %s\n",xsvf_file_name.c_str());

		   stat_result    = _stat(xsvf_file_name.c_str(), &buf);
		   xsvf_file_size = buf.st_size;

		   printf("\tFile size     = %i\n",xsvf_file_size);
		   printf("\tTime modified = %s\n",ctime(&buf.st_atime));

		   // Select JTAG chain 
		   status  = vme_read(boot_adr,rd_data);				// Get current boot reg
		   wr_data = rd_data & 0xFFF8;							// zero tck, tms, tdi
		   status  = vme_write(boot_adr,wr_data);

		   wr_data = wr_data & 0xFF80 | (ichain << 3);			// Select new chain id
		   status  = vme_write(boot_adr,wr_data);

		   wr_data = wr_data | (1 << 7);						// Commandeer the jtag chain
		   status  = vme_write(boot_adr,wr_data);

		   xilinx_boot_adr  = boot_adr;
		   xilinx_boot_data = wr_data;							// store for portsf

		   // Run Xilinx XSVF player
		   printf("\tStarting Xilinx XSVF Player\n");

		   setport_calls  = 0;
		   setport_writes = 0;
		   setport_reads  = 0;
		   setport_writes_expected = xsvf_file_size;			// rough estimate for jtag competion
		   xsvf_verbosity = 0;
		   wlog           = true;

		   setPort(TMS, 1);
		   startClock  = clock();
		   status      = xsvfExecute();
		   endClock    = clock();

		   if (xsvf_file!=NULL) fclose(xsvf_file);
		   ucTdoBit= readTDOBit();								// purge any pending write in the buffer

		   if (status != 0) printf("\tXSVF Player FAILURE =:-(\n");
		   if (status == 0) printf("\tXSVF Player SUCCESS =:-)\n");

		   printf("\tStatus=%X\n",status);
		   printf("\tExecution Time = %.3f seconds\n",(((double)(endClock-startClock))/CLOCKS_PER_SEC));
		   printf("\tsetPort calls =%10i\n",setport_calls);
		   printf("\tsetPort writes=%10i\n",setport_writes);
		   printf("\tsetPort reads =%10i\n",setport_reads);
		   printf("\tsetPort buffer=%10i\n",setport_peak_nwords);

		   status  = vme_read(boot_adr,rd_data);				// Get current boot reg
		   wr_data = rd_data & 0xFF80;
		   status  = vme_write(boot_adr,wr_data);				// zero tck, tms, tdi

		   pause(" ");
		   goto L2900;
	   }
	   //------------------------------------------------------------------------------
	   //	JTAG PROM utilities
	   //------------------------------------------------------------------------------
	   void L3000() {
L3000:

		   // Display menu
		   printf("\n");
		   printf("\tJTAG PROM Utilities Submenu:\n");
		   printf("\t1: Create  User PROM ascii file\n");
		   printf("\t2: Convert User PROM ascii to Intel MCS-86 PROM format\n");
		   printf("\t3: Convert User PROM mcs file to XSVF\n");
		   printf("\t4: Read User PROM device IDs via JTAG\n");
		   printf("\t5: Read/Compare UserProm data via TMB FPGA\n");
		   printf("\t6: Convert jtaglog.txt to USER PROM ascii\n");
		   printf("\t7: JTAG PROM state machine\n");
		   printf("\t<cr> Exit\n");
		   printf("       > ");

		   gets(line);
		   if (line[0]==NULL) return;
		   sscanf(line,"%i",&ifunc);

		   i=abs(ifunc);
		   if (i== 1) goto L30100;
		   if (i== 2) goto L30200;
		   if (i== 3) goto L30300;
		   if (i== 4) goto L30400;
		   if (i== 5) goto L30500;
		   if (i== 6) goto L30600;
		   if (i== 7) goto L30700;

		   goto L3000;

		   //------------------------------------------------------------------------------
		   //	Create JTAG PROM ascii file
		   //------------------------------------------------------------------------------
L30100:
		   ilen = 0x7FFF;
		   inquire("\tMaximum address? cr=%4.4X", minv=0x0, maxv=0x7FFF, radix=16, ilen);

		   // Inquire prom output file
		   sprintf(czsize,"%4.4X",ilen);
		   szsize = string(czsize);
		   prom_file_name_default = "userprom"+szsize+".txt";

		   printf("\tPROM output file name: <cr=%s>",prom_file_name_default.c_str());

		   gets(line);
		   if (line[0]==0) {prom_file_name = prom_file_name_default;}
		   else            {prom_file_name = string(line);}

		   // Open prom output file
		   if (prom_file!=NULL) fclose(prom_file);
		   prom_file = fopen(prom_file_name.c_str(),"w");

		   if (prom_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",prom_file_name.c_str());}
		   else                 {fprintf(stdout,"\tFailed to open %s\n",prom_file_name.c_str()); pause("WTF?"); goto L30100;}

		   // This version merely stores data=adr at every address to aid decrypting the xsvf file: format=AAAA DD
		   //	n=(ilen*1024)/8-1;

		   for (i=0; i<=ilen; ++i) {
			   adr     = i;
			   wr_data = i & 0x00FF;
			   fprintf(prom_file,"%4.4X %2.2X\n",adr,wr_data);
		   }

		   if (prom_file!=NULL) fclose(prom_file);
		   goto L3000;

		   //------------------------------------------------------------------------------
		   //	Convert User PROM ascii to Intel MCS-86 PROM format
		   //------------------------------------------------------------------------------
L30200:
		   // ASCII input file
		   ascii_file_name_default = "userprom256.txt";

		   printf("\tASCII input  file name: <cr=%s>",ascii_file_name_default.c_str());

		   gets(line);
		   if (line[0]==0) {ascii_file_name = ascii_file_name_default;}
		   else            {ascii_file_name = string(line);}

		   if (ascii_file!=NULL) fclose(ascii_file);
		   ascii_file = fopen(ascii_file_name.c_str(),"r");

		   if (ascii_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",ascii_file_name.c_str());}
		   else                  {fprintf(stdout,"\tFailed to open %s\n",ascii_file_name.c_str()); pause("WTF?"); goto L30200;}

		   // MCS output file
L30201:
		   mcs_file_name_default   = "userprom256.mcs";

		   printf("\tMCS   output file name: <cr=%s>",ascii_file_name_default.c_str());

		   gets(line);
		   if (line[0]==0) {mcs_file_name = mcs_file_name_default;}
		   else            {mcs_file_name = string(line);}

		   if (mcs_file!=NULL) fclose(mcs_file);
		   mcs_file = fopen(mcs_file_name.c_str(),"w");

		   if (mcs_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",mcs_file_name.c_str());}
		   else                {fprintf(stdout,"\tFailed to open %s\n",mcs_file_name.c_str()); pause("WTF?"); goto L30201;}

		   // Output MCS first word: extended address record
		   rec_len    = 2;
		   adr_offset = 0;
		   rec_type   = 2;
		   segment    = 0;
		   cksum      = 0xFC;
		   nwrite     = 1;

		   fprintf(mcs_file,"%c%2.2X%4.4X%2.2X%4.4X%2.2X\n",colon,rec_len,adr_offset,rec_type,segment,cksum);

		   // Read input data stream: expect format AAAA DDD, presumes addresses are sequential
		   ibyte  = -1;
		   cksum  =  0;
		   nwords =  0;

L30210:
		   iadr_previous = iadr;

		   if (feof(ascii_file)) goto L30230;			// hit end of file
		   fgets(line,81,ascii_file);					// get a new line
		   sscanf(line,"%4X %2X%*[^\n]",&iadr,&idata);	// get adr and data, skip comments

		   nwords++;
		   if (iadr!=0 && (iadr%65536==0)        ) goto L30240; // 64K boundary
		   if (iadr >  512*1024/8-1              ) pause("\tfile: prom address out of range");
		   if (iadr!=0 && iadr != iadr_previous+1) pause("\tfile: prom address out of order");

		   // Pack data into 1 MCS record of up to 16 words
L30220:
		   ibyte++;
		   outbuf[ibyte] = idata;
		   cksum         = cksum+idata;
		   if (ibyte==15) goto L30230;
		   goto L30210;

		   // Output MCS data record
L30230:
		   rec_len=ibyte+1;
		   if (rec_len<=0) goto L30250;	// end of file and buffer is empty, so dont write
		   adr         = (iadr/16)*16-adr_offset;
		   rec_type    = 0;
		   adr_hi_byte = (adr>>8) & 0xFF;
		   adr_lo_byte = adr & 0xFF;
		   cksum       = cksum+rec_len+adr_hi_byte+adr_lo_byte+rec_type;
		   cksum       = cksum & 0x000000FF;
		   cksum       = (0x100-cksum) & 0x000000FF;

		   fprintf(mcs_file,"%c%2.2X%4.4X%2.2X",colon,rec_len,adr,rec_type);
		   for (i=0; i<=ibyte; ++i) fprintf(mcs_file,"%4.4X",outbuf[i]);
		   fprintf(mcs_file,"%2.2X\n",cksum);
		   nwrite++;
		   ibyte = -1;
		   cksum =  0;

		   if (feof(ascii_file)) goto L30250;	// end of record
		   goto L30210;

		   // Output MCS Extended Address Record at 64K Boundary
L30240:
		   adr_offset  = adr_offset+65536;
		   adr         = (adr_offset>>16);
		   rec_len     = 2;
		   rec_type    = 4;
		   segment     = 0;
		   adr_hi_byte = (adr>>8) & 0x00FF;
		   adr_lo_byte = adr & 0x00FF;
		   cksum       = cksum+rec_len+adr_hi_byte+adr_lo_byte+rec_type;
		   cksum       = cksum & 0x000000FF;
		   nwrite++;

		   fprintf(mcs_file,"%c%2.2X%4.4X%2.2X%4.4X%2.2X\n",colon,rec_len,adr_offset,rec_type,segment,cksum);

		   printf("\tExtended address at %8.8X\n",adr_offset);
		   goto L30220;

		   // Output MCS end of file record
L30250:
		   rec_len  = 0;
		   filler   = 0;
		   rec_type = 1;
		   cksum    = 0xFF;
		   nwrite++;

		   fprintf(mcs_file,"%c%2.2X%4.4X%2.2X%2.2X\n",colon,rec_len,filler,rec_type,cksum);

		   // Close up
		   if (ascii_file!=NULL) fclose(ascii_file);
		   if (mcs_file  !=NULL) fclose(mcs_file  );

		   printf("\n");
		   printf("\tRead  %6i data words  \n",nwords);
		   printf("\tWrote %6i mcs  records\n",nwrite);

		   goto L3000;

		   //------------------------------------------------------------------------------
		   //	Convert mcs to UserProm XSVF
		   //------------------------------------------------------------------------------
L30300:
		   pause("\tSee stand-alone xsvfwriter.cpp");
		   goto L3000;

		   //------------------------------------------------------------------------------
		   //	Read User PROM device IDs via JTAG
		   //------------------------------------------------------------------------------
L30400:
		   // Read prom IDCodes
		   ichain  = 0x0008;							// User PROM chain
		   adr     = boot_adr;
		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI

		   opcode  = 0xFE;								// IDcode opcode
		   reg_len = 32;								// IDcode length

		   // User proms may have idcode 05022093 for 256KB, and either 05023093 or 05033093 for 512KB
		   for (chip_id=0; chip_id<=1; ++chip_id)					// Loop over PROM chips
		   {
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

			   tdi_to_i4(tdo,idcode,32,0);

			   if       (idcode==0x05022093) {ssize = "256"; ilen = 256*1024/8;}
			   else if  (idcode==0x05023093) {ssize = "512"; ilen = 512*1024/8;}
			   else if  (idcode==0x05033093) {ssize = "512"; ilen = 512*1024/8;}
			   else                          {ssize = "unk"; ilen = 0;}

			   printf("\tXilinx User PROM%1i IDcode=%8.8X %sKbit\n",chip_id,idcode,ssize.c_str());
			   if (ilen==0) pause("Can not determine PROM size");

		   }	// close for chip_id

		   // Read PROM usercodes
		   ichain  = 0x0008;								// User PROM chain
		   adr     = boot_adr;
		   vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI
		   opcode  = 0xFD;									// Usercode opcode
		   reg_len = 32;									// Usercode length

		   for (chip_id=0; chip_id<=1; ++chip_id)			// Loop over PROM chips
		   {
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);	// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
			   tdi_to_i4(tdo,usercode,32,0);

			   printf("\tXilinx User PROM%1i Usercode=%8.8X\n",chip_id,usercode);
		   }
		   printf("\n");

		   goto L3000;

		   //------------------------------------------------------------------------------
		   //	Read back UserProm data via TMB FPGA
		   //------------------------------------------------------------------------------
L30500:
		   // Inquire Dump output file
		   iprom = 0;
		   inquire("\tRead PROM 0(tmb) or 1(alct) cr=%1i", minv=0, maxv=1, radix=10, iprom);

		   sprintf(cprom,"%1i",iprom);
		   sprom = string(cprom);
		   dump_file_name_default = "userprom"+sprom+"_readback.txt";

		   printf("\tPROM dump output file: <cr=%s>",dump_file_name_default.c_str());

		   gets(line);
		   if (line[0]==0) {dump_file_name = dump_file_name_default;}
		   else            {dump_file_name = string(line);}

		   if (dump_file!=NULL) fclose(dump_file);
		   dump_file = fopen(dump_file_name.c_str(),"w");

		   if (dump_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",dump_file_name.c_str());}
		   else                 {fprintf(stdout,"\tFailed to open %s\n",dump_file_name.c_str()); pause("WTF?"); goto L30500;}

		   // Open input compare file
L30501:
		   compare_prom_file = false;
		   inquirb("\tCompare PROM to file?? [y|n]? cr=%3c",compare_prom_file);

		   compare_file_name_default = "userprom256.txt";

		   if (compare_prom_file)
		   {
			   printf("\tCompare to input file: <cr=%s>",compare_file_name_default.c_str());

			   gets(line);
			   if (line[0]==0) {compare_file_name = compare_file_name_default;}
			   else            {compare_file_name = string(line);}

			   if (compare_file!=NULL) fclose(compare_file);
			   compare_file = fopen(compare_file_name.c_str(),"r");

			   if (compare_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",compare_file_name.c_str());}
			   else                    {fprintf(stdout,"\tFailed to open %s\n",compare_file_name.c_str()); pause("WTF?"); goto L30501;}
		   }	// close if compare

		   // Determine prom type
		   ichain  = 0x0008;						// User PROM chain
		   adr     = boot_adr;
		   vme_jtag_anystate_to_rti(adr,ichain);	// Take TAP to RTI
		   opcode  = 0xFE;							// IDcode opcode
		   reg_len = 32;							// IDcode length

		   chip_id=iprom;											// Loop over PROM chips
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		   tdi_to_i4(tdo,idcode,32,0);

		   if      (idcode == 0x05022093) {ssize = "256"; ilen  = 256*1024/8;}
		   else if (idcode == 0x05023093) {ssize = "512"; ilen  = 512*1024/8;}
		   else if (idcode == 0x05033093) {ssize = "512"; ilen  = 512*1024/8;}
		   else                           {ssize = "unk"; ilen  = 0;         }

		   printf("\tXilinx User PROM%1i IDcode=%8.8X %sKbit\n",chip_id,idcode,ssize.c_str());

		   if (ilen==0) pause("\tCan not determine PROM size");

		   // Enable 1 prom disable the other, they share the onboard led bus
		   jprom = (iprom+1)%2;

		   prom_clk[iprom] = 0;	// enable this one
		   prom_oe[iprom]  = 1;
		   prom_nce[iprom] = 0;

		   prom_clk[jprom] = 0;	// disble this one
		   prom_oe[jprom]  = 0;
		   prom_nce[jprom] = 1;
		   prom_src        = 1;

		   adr     = vme_prom_adr+base_adr;
		   wr_data = 
			   (prom_src     <<14) | 
			   (prom_nce[1] << 13) | 
			   (prom_oe[1]  << 12) | 
			   (prom_clk[1] << 11) | 
			   (prom_nce[0] << 10) | 
			   (prom_oe[0]  <<  9) |
			   (prom_clk[0] <<  8 );
		   status = vme_write(adr,wr_data);

		   // Read data from selected PROM
		   jsm_trailer_adr = 0;
		   jsm_data_valid  = 1;
		   alct_end_marker = 0;
		   cksum           = 0;
		   wdcnt           = 0;
		   njtag_frames    = 0;
		   nerrors         = 0;

		   for (prom_adr=0; prom_adr<=ilen-1; ++prom_adr)
		   {
			   status    = vme_read(adr,rd_data);
			   prom_data = rd_data & 0x00FF;
			   dprintf(stdout,"\tPROM%1i Adr=%4.4X Data=%2.2X\n",iprom,prom_adr,prom_data);

			   // Read data from source file
			   if (compare_prom_file)
			   {
				   fgets(line,81,compare_file);						// get a new line
				   sscanf(line,"%4X %2X%*[^\n]",&cmp_adr,&cmp_data);	// get adr and data, skip comments

				   if (!feof(compare_file)) {							// compare file has data
					   if (cmp_data != prom_data) nerrors++;
					   if (cmp_adr  != prom_adr ) nerrors++;
				   }
				   else {												// compare file is empty
					   cmp_data = 0;
					   cmp_adr  = 0;
				   }

				   if (prom_adr==0) {
					   fprintf(dump_file,"PROM PROM File File\n");	
					   fprintf(dump_file,"Adr  Data Adr  Data Ascii Err\n");
				   }

				   fprintf(dump_file,"%4.4X %2.2X   %4.4X %2.2X   %c%8i\n",prom_adr,prom_data,cmp_adr,cmp_data,prom_data,nerrors);
			   }	// close if compare

			   // Display header words from TMB prom
			   if (iprom==0) {
				   if (prom_adr<16 || prom_adr==ilen-1) printf("\tPROM%1i Adr=%4.4X Data=%2.2X %c\n",iprom,prom_adr,prom_data,prom_data);
				   goto L30510;
			   }

			   // For ALCT PROM, extract header and trailer frame data
			   jsm_flag_word = (prom_data >> 4) & 0xF;
			   jsm_flag_bit  = (prom_data >> 7) & 0x1;

			   sjsm_frame_type                            = "Unknown         ";
			   if (jsm_flag_bit  != 0   ) sjsm_frame_type = "Unknown Control ";
			   if (jsm_flag_bit  == 0   ) sjsm_frame_type = "JTAG Frame      ";
			   if (prom_adr      == 0   ) sjsm_frame_type = "Begin   Marker: ";
			   if (jsm_flag_word == 0x8 ) sjsm_frame_type = "Header  Frame : ";
			   if (jsm_flag_word == 0xC ) sjsm_frame_type = "Trailer Frame : ";

			   if (prom_data     == 0xEA) sjsm_frame_type = "End Hdr Marker: ";
			   if (prom_data     == 0xFA) sjsm_frame_type = "End Jtg Marker: ";
			   if (prom_data     == 0xFF) sjsm_frame_type = "End     Marker: ";

			   if (jsm_flag_bit!=0 && jsm_data_valid==1) printf("\t%s %4.4X  %2.2X\n",sjsm_frame_type.c_str(),prom_adr,prom_data);

			   jsm_data=prom_data & 0x000F;

			   switch (prom_adr)
			   {
				   case 0x0: alct_begin_marker = prom_data;						break;
				   case 0x1: alct_type         = (jsm_data <<  8);					break;
				   case 0x2: alct_type         = (jsm_data <<  4) | alct_type;		break;
				   case 0x3: alct_type         = (jsm_data <<  0) | alct_type;		break;
				   case 0x4: alct_month        = (jsm_data <<  4);					break;
				   case 0x5: alct_month        = (jsm_data <<  0) | alct_month;	break;
				   case 0x6: alct_day          = (jsm_data <<  4);					break;
				   case 0x7: alct_day          = (jsm_data <<  0) | alct_day;		break;
				   case 0x8: alct_year         = (jsm_data << 12);					break;
				   case 0x9: alct_year         = (jsm_data <<  8) | alct_year;		break;
				   case 0xA: alct_year         = (jsm_data <<  4) | alct_year;		break;
				   case 0xB: alct_year         = (jsm_data <<  0) | alct_year;		break;
				   case 0xC: alct_version      = (jsm_data <<  0);					break;
				   case 0xD: alct_unass        = (jsm_data <<  4);					break;
				   case 0xE: alct_unass        = (jsm_data <<  0) | alct_unass;	break;
				   case 0xF: alct_end_header   =  prom_data;						break;
			   }

			   if (jsm_flag_bit==0 && jsm_data_valid) njtag_frames++;
			   if (prom_data==0xFA) jsm_trailer_adr = prom_adr;

			   if (jsm_trailer_adr!=0 && jsm_data_valid)
			   {
				   i = prom_adr-jsm_trailer_adr+1;

				   switch (i)
				   {
					   case 0x2: prom_wdcnt= (jsm_data << 12);					break;
					   case 0x3: prom_wdcnt= (jsm_data <<  8) | prom_wdcnt;	break;
					   case 0x4: prom_wdcnt= (jsm_data <<  4) | prom_wdcnt;	break;
					   case 0x5: prom_wdcnt= (jsm_data <<  0) | prom_wdcnt;	break;
					   case 0x6: prom_cksum= (jsm_data <<  4);					break;
					   case 0x7: prom_cksum= (jsm_data <<  0) | prom_cksum;	break;
					   case 0x8: alct_end_marker = prom_data;					break;
				   }
			   }	// close if jsm

			   // Accumulate word count and check-sum as would be seen by jtagsm state machine
			   if (alct_end_marker!=0 || prom_data==0xFF) jsm_data_valid = false;

			   if (jsm_data_valid) {
				   if (jsm_trailer_adr==0 || (prom_adr-jsm_trailer_adr+1 <= 5)) cksum = (cksum+prom_data) & 0x00FF;
				   if (jsm_trailer_adr==0 || (prom_adr-jsm_trailer_adr    <=0)) wdcnt++;
			   }

			   // Toggle clock to advance address
L30510:
			   prom_clk[iprom] = 1;
			   wr_data =
				   (prom_src    << 14) |
				   (prom_nce[1] << 13) |
				   (prom_oe[1]  << 12) |
				   (prom_clk[1] << 11) |
				   (prom_nce[0] << 10) |
				   (prom_oe[0]  <<  9) |
				   (prom_clk[0] <<  8);
			   status = vme_write(adr,wr_data);

			   prom_clk[iprom] = 0;
			   wr_data = 
				   (prom_src    << 14) |
				   (prom_nce[1] << 13) |
				   (prom_oe[1]  << 12) |
				   (prom_clk[1] << 11) |
				   (prom_nce[0] << 10) |
				   (prom_oe[0]  <<  9) |
				   (prom_clk[0] <<  8);
			   status = vme_write(adr,wr_data);

		   }	// close for prom_adr

		   // Close files
		   if (dump_file    != NULL) fclose(dump_file   );
		   if (compare_file != NULL) fclose(compare_file);

		   // Turn PROMs off
		   prom_clk[iprom] = 0;	// disble this one
		   prom_oe[iprom]  = 0;
		   prom_nce[iprom] = 1;
		   prom_src        = 0;

		   wr_data = 
			   (prom_src    << 14) |
			   (prom_nce[1] << 13) |
			   (prom_oe[1]  << 12) |
			   (prom_clk[1] << 11) |
			   (prom_nce[0] << 10) |
			   (prom_oe[0]  <<  9) |
			   (prom_clk[0] <<  8);
		   status = vme_write(adr,wr_data);

		   // Display ALCT PROM data summary
		   if (iprom==1 && alct_begin_marker==0xBA)
		   {
			   printf("\n");
			   printf("\talct_begin_marker %6.2X\n",alct_begin_marker);
			   printf("\talct_type         %6.3X\n",alct_type);
			   printf("\talct_month        %6.2X\n",alct_month);
			   printf("\talct_day          %6.2X\n",alct_day);
			   printf("\talct_year         %6.4X\n",alct_year);
			   printf("\talct_version      %6.2X\n",alct_version);
			   printf("\talct_unassigned   %6.2X\n",alct_unass);
			   printf("\talct_end_header   %6.2X\n",alct_end_header);
			   printf("\tjtag frames       %6i  \n",njtag_frames);
			   printf("\twdcnt calc        %6i  \n",wdcnt);
			   printf("\twdcnt stored      %6i  \n",prom_wdcnt);
			   printf("\tcksum calc        %6.2X\n",cksum);
			   printf("\tcksum stored      %6.2X\n",prom_cksum);

			   if (prom_cksum==cksum) sresult_cksum = "Checksum  Match:";
			   else                   sresult_cksum = "Checksum  Error:";

			   if (prom_wdcnt==wdcnt) sresult_wdcnt = "Wordcount Match:";
			   else                   sresult_wdcnt = "Wordcount Error:";


			   printf("\t%s calc=%6.2X stored=%6.2X\n",sresult_cksum.c_str(),cksum,prom_cksum);
			   printf("\t%s calc=%6i stored=%6i\n",sresult_wdcnt.c_str(),wdcnt,prom_wdcnt);
			   printf("\tCompare Errors:\n",nerrors);

		   }	// close if iprom
		   goto L3000;

		   //------------------------------------------------------------------------------
		   //	Convert jtaglog.txt to ALCT USER PROM ascii
		   //------------------------------------------------------------------------------
L30600:
		   // Inquire prom output file
		   ilen=256;
		   printf("\tPROM size 256 or 512 <cr=%3i> ",ilen);
		   gets(line);
		   if (line[0]!=NULL) sscanf(line,"%i",&ilen);
		   if ((ilen!=256) && (ilen!=512)) goto L30600;

		   sprintf(csize,"%3.3i",ilen);
		   ssize = string(csize);
		   prom_file_name_default = string("userprom").append(ssize).append(".txt");

		   printf("\tPROM output file name: <cr=%s>",prom_file_name_default.c_str());

		   gets(line);
		   if (line[0]==0) {prom_file_name = prom_file_name_default;}
		   else            {prom_file_name = string(line);}

		   if (prom_file!=NULL) fclose(prom_file);
		   prom_file = fopen(prom_file_name.c_str(),"w");

		   if (prom_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",prom_file_name.c_str());}
		   else                 {fprintf(stdout,"\tFailed to open %s\n",prom_file_name.c_str()); pause("WTF?"); goto L30600;}

		   // Open jtaglog.txt for reading
		   jtag_file_name = "jtaglog.txt";
		   jtag_file = fopen(jtag_file_name.c_str(),"r");

		   if (jtag_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",jtag_file_name.c_str());}
		   else                 {fprintf(stdout,"\tFailed to open %s\n",jtag_file_name.c_str()); pause("WTF?"); return;}

		   // Insert header
		   _strdate(datestr);
		   imonth = (datestr[0]-'0') * 16;
		   imonth = (datestr[1]-'0') *  1 | imonth;
		   iday   = (datestr[3]-'0') * 16;
		   iday   = (datestr[4]-'0') *  1 | iday;
		   iyear  = (datestr[6]-'0') * 16;
		   iyear  = (datestr[7]-'0') *  1 | iyear | 0x2000;

		   inquire("\tALCT Begin marker %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, alct_begin_marker = 0x00BC);
		   inquire("\tALCT Type         %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, alct_type         = 0x0384);
		   inquire("\tALCT Month        %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, alct_month        = imonth);
		   inquire("\tALCT Day          %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, alct_day          = iday  );
		   inquire("\tALCT Year         %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, alct_year         = iyear );
		   inquire("\tALCT Version      %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, alct_version      = 0x0000);

		   adr   = 0;
		   cksum = 0;

		   for (i=0; i<=0xF; ++i) {
			   switch (adr)
			   {
				   case 0x0: jtag_data = alct_begin_marker;				break;
				   case 0x1: jtag_data = 0x80 | (alct_type  >>  8) & 0xF;	break;
				   case 0x2: jtag_data = 0x80 | (alct_type  >>  4) & 0xF;	break;
				   case 0x3: jtag_data = 0x80 | (alct_type  >>  0) & 0xF;	break;
				   case 0x4: jtag_data = 0x80 | (alct_month >>  4) & 0xF;	break;
				   case 0x5: jtag_data = 0x80 | (alct_month >>  0) & 0xF;	break;
				   case 0x6: jtag_data = 0x80 | (alct_day   >>  4) & 0xF;	break;
				   case 0x7: jtag_data = 0x80 | (alct_day   >>  0) & 0xF;	break;
				   case 0x8: jtag_data = 0x80 | (alct_year  >> 12) & 0xF;	break;
				   case 0x9: jtag_data = 0x80 | (alct_year  >>  8) & 0xF;	break;
				   case 0xA: jtag_data = 0x80 | (alct_year  >>  4) & 0xF;	break;
				   case 0xB: jtag_data = 0x80 | (alct_year  >>  0) & 0xF;	break;
				   case 0xC: jtag_data = 0x80 | alct_version & 0xF;		break;
				   case 0xD: jtag_data = 0x80 | 0;							break;
				   case 0xE: jtag_data = 0x80 | 0;							break;
				   case 0xF: jtag_data = 0xAA;								break;//  end header marker
			   }

			   cksum = (cksum+jtag_data) & 0x00FF;
			   fprintf(prom_file,"%4.4X %2.2X Header cksum=%2.2X\n",adr,jtag_data,cksum);

			   adr++;
		   }	// close for i

		   // Insert jtag data to toggle tck into the fpga chain, so state machine can check if it has control of jtag chain
		   jtag_sel = 0xC;	// point to fpga chain
		   jtag_tdi = 0;
		   jtag_tms = 0;

		   for (i=0; i<=4; ++i)
		   {
			   jtag_tck = i%2;	// 0,1,0,1,0

			   jtag_data=
				   (jtag_sel << 3) |
				   (jtag_tck << 2) |
				   (jtag_tms << 1) |
				   (jtag_tdi << 0);

			   cksum = (cksum+jtag_data) & 0x00FF;

			   fprintf(prom_file,"%4.4X %2.2X tck=%1i tms=%1i tdi=%1i sel=%1i cksum=%2.2X\n",adr,jtag_data,jtag_tck,jtag_tms,jtag_tdi,jtag_sel,cksum);

			   adr++;
		   }	// close for i

		   // Insert jtag data body from boot image file
L30610:
		   if (feof(jtag_file)) goto L30620;							// compare file has data

		   fgets(line,81,jtag_file);						// get a new line
		   sscanf(line,"%4X%*[^\n]",&rd_data);	// get adr and data, skip comments

		   jtag_data = rd_data & 0x007F;
		   jtag_tdi  = (rd_data >> 0   ) & 0x1;
		   jtag_tms  = (rd_data >> 1   ) & 0x1;
		   jtag_tck  = (rd_data >> 2   ) & 0x1;
		   jtag_sel  = (rd_data >> 3   ) & 0xF;
		   cksum     = (cksum+jtag_data) & 0xFF;

		   fprintf(prom_file,"%4.4X %2.2X tck=%1i tms=%1i tdi=%1i sel=%1i cksum=%2.2X\n",adr,jtag_data,jtag_tck,jtag_tms,jtag_tdi,jtag_sel,cksum);

		   adr++;
		   if (adr > (1<<15)-8) pause("\tPROM address > 32K, will not fit in 256Kbit PROM");
		   if (adr > (1<<16)-8) pause("\tPROM address > 64K, will not fit in 512Kbit PROM");
		   goto L30610;

		   // Insert Trailer
L30620:
		   wdcnt=adr+1;		// beco adr0 is word count =1 

		   for (i=1; i<=8; ++i) {
			   switch (i)
			   {
				   case 0x1: jtag_data = 0xFA;							break;	// end of JTAG data marker
				   case 0x2: jtag_data = 0xC0 | (wdcnt >> 12) & 0xF;	break;
				   case 0x3: jtag_data = 0xC0 | (wdcnt >>  8) & 0xF;	break;
				   case 0x4: jtag_data = 0xC0 | (wdcnt >>  4) & 0xF;	break;
				   case 0x5: jtag_data = 0xC0 | (wdcnt >>  0) & 0xF;	break;
				   case 0x6: jtag_data = 0xC0 | (cksum >>  4) & 0xF;	break;
				   case 0x7: jtag_data = 0xC0 | (cksum >>  0) & 0xF;	break;
				   case 0x8: jtag_data = 0xFF;							break;	// end of PROM data marker
			   }

			   if (i<=5) cksum = (cksum+jtag_data) & 0xFF;
			   fprintf(prom_file,"%4.4X %2.2X Trailer cksum=%2.2X\n",adr,jtag_data,cksum);
			   adr++;
		   }	// close for i

		   printf("\tWord count=%5i Checksum=%2.2X\n",wdcnt,cksum);

		   if (jtag_file!=NULL) fclose(jtag_file);
		   if (prom_file!=NULL) fclose(prom_file);

		   goto L3000;

		   //------------------------------------------------------------------------------
		   //	JTAG PROM state machine
		   //------------------------------------------------------------------------------
L30700:
		   // Get current status
		   adr    = vmesm0_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   jsm_autostart = (rd_data >> 7) & 0x1;

		   adr    = jtagsm0_adr+base_adr;
		   status = vme_read(adr,rd_data);

		   jsm_prom_start_vme	= (rd_data >>  0) & 0x1;
		   jsm_sreset			= (rd_data >>  1) & 0x1;
		   jsm_sel				= (rd_data >>  2) & 0x1;
		   jsm_busy			= (rd_data >>  3) & 0x1;
		   jsm_aborted			= (rd_data >>  4) & 0x1;
		   jsm_cksum_ok		= (rd_data >>  5) & 0x1;
		   jsm_wdcnt_ok		= (rd_data >>  6) & 0x1;
		   jsm_tck_fpga_ok		= (rd_data >>  7) & 0x1;
		   jsm_vme_ready		= (rd_data >>  8) & 0x1;
		   jsm_ok				= (rd_data >>  9) & 0x1;
		   jsm_jtag_oe			= (rd_data >> 10) & 0x1;
		   jsm_unass0			= (rd_data >> 11) & 0x1;
		   jsm_throttle		= (rd_data >> 12) & 0xF;

		   adr    = jtagsm1_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   jsm_wdcnt = rd_data;

		   adr    = jtagsm2_adr+base_adr;
		   status = vme_read(adr,rd_data);

		   jsm_cksum	  = (rd_data >>  0) & 0xFF;
		   jsm_tck_fpga  = (rd_data >>  8) & 0xF;
		   jsm_tckcnt_ok = (rd_data >> 12) & 0x1;
		   jsm_end_ok    = (rd_data >> 13) & 0x1;
		   jsm_header_ok = (rd_data >> 14) & 0x1;
		   jsm_chain_ok  = (rd_data >> 15) & 0x1;

		   adr    = vmesm2_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   jsm_jtag_sm_vec = (rd_data >> 13) & 0x3;

		   adr    = vmesm3_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   jsm_prom_sm_vec   = (rd_data >>  8) & 0xF;
		   jsm_format_sm_vec = (rd_data >> 12) & 0x7;


		   switch (jsm_prom_sm_vec)
		   {
			   case 0x0: jsm_prom_state = "wait_dll ";	break;
			   case 0x1: jsm_prom_state = "wait_vme ";	break;
			   case 0x2: jsm_prom_state = "idle     ";	break;
			   case 0x3: jsm_prom_state = "init     ";	break;
			   case 0x4: jsm_prom_state = "reset_adr";	break;
			   case 0x5: jsm_prom_state = "prom_tacc";	break;
			   case 0x6: jsm_prom_state = "latch_prm";	break;
			   case 0x7: jsm_prom_state = "hold_adr ";	break;
			   case 0x8: jsm_prom_state = "inc_adr  ";	break;
			   case 0x9: jsm_prom_state = "unstart  ";	break;
			   default:  jsm_prom_state = "Unknown  "; break;
		   }

		   switch (jsm_format_sm_vec)
		   {
			   case 0x0: jsm_format_state = "wait_prom   "; break;
			   case 0x1: jsm_format_state = "check_header"; break;
			   case 0x2: jsm_format_state = "wait_chain  "; break;
			   case 0x3: jsm_format_state = "load_chain  "; break;
			   case 0x4: jsm_format_state = "load_tckcnt0"; break;
			   case 0x5: jsm_format_state = "load_tckcnt1"; break;
			   case 0x6: jsm_format_state = "abend       "; break;
			   case 0x7: jsm_format_state = "wait_prom   "; break;
			   default:  jsm_format_state = "Unknown     "; break;
		   }

		   switch (jsm_jtag_sm_vec)
		   {
			   case 0x0: jsm_jtag_state = "wait_format "; break;
			   case 0x1: jsm_jtag_state = "tck_low     "; break;
			   case 0x2: jsm_jtag_state = "tck_high    "; break;
			   default:  jsm_jtag_state = "Unknown     "; break;
		   }

		   printf("\tCurrent JTAG PROM State Machine Status\n");
		   printf("\tprom_start_vme:  %5i\n",jsm_prom_start_vme);
		   printf("\tjsm_autostart:   %5i\n",jsm_autostart);
		   printf("\tsreset:          %5i\n",jsm_sreset);
		   printf("\tjsm_sel:         %5i\n",jsm_sel);
		   printf("\tbusy:            %5i\n",jsm_busy);
		   printf("\taborted:         %5i\n",jsm_aborted);
		   printf("\theader_ok:       %5i\n",jsm_header_ok);
		   printf("\tchain_ok:        %5i\n",jsm_chain_ok);
		   printf("\ttckcnt_ok:       %5i\n",jsm_tckcnt_ok);
		   printf("\twdcnt_ok:        %5i\n",jsm_wdcnt_ok);
		   printf("\tcksum_ok:        %5i\n",jsm_cksum_ok);
		   printf("\tend_ok:          %5i\n",jsm_end_ok);
		   printf("\ttck_fpga_ok:     %5i\n",jsm_tck_fpga_ok);
		   printf("\tvme_ready:       %5i\n",jsm_vme_ready);
		   printf("\tjsm_ok:          %5i\n",jsm_ok);
		   printf("\tthrottle         %5i\n",jsm_throttle);
		   printf("\tjtag_oe          %5i\n",jsm_jtag_oe);
		   printf("\tunassigned:      %5i\n",jsm_unass0);
		   printf("\twdcnt dec:       %5i\n",jsm_wdcnt);
		   printf("\twdcnt hex:       %5X\n",jsm_wdcnt);
		   printf("\tcksum:           %5X\n",jsm_cksum);
		   printf("\ttck_fpga:        %5i\n",jsm_tck_fpga);
		   printf("\tprom_sm_state:   %s \n",jsm_prom_state.c_str());
		   printf("\tformat_sm_state: %s \n",jsm_format_state.c_str());
		   printf("\tjtag_sm_state:   %s \n",jsm_jtag_state.c_str());

		   // Inquire re-fire
		   inquirb("\tFire ALCT JTAG State Machine? [y|n]? cr=%3c",bans);
		   if (!bans) goto L3000;
		   inquire("\tJTAG throttle[0-15]?                 cr=%3i",minv= 0, maxv=15, radix=10, jsm_throttle);

		   // Re-fire Alct JTAG state machine
L30710:
		   adr     = boot_adr;
		   status  = vme_read(adr,rd_data);		// get current boot register
		   wr_data = rd_data & 0xFF7F;
		   status  = vme_write(boot_adr,wr_data);	// make fpga the jtag master

		   adr     = jtagsm0_adr+base_adr;
		   wr_data = 0x2 | (jsm_throttle<<12);		// clear state machine status
		   status  = vme_write(adr,wr_data);
		   wr_data = 0x0 | (jsm_throttle<<12);		// cancel clear command
		   status  = vme_write(adr,wr_data);

		   status  = vme_read(adr,rd_data);		// read new status

		   jsm_busy		= (rd_data >> 3) & 0x1;
		   jsm_aborted		= (rd_data >> 4) & 0x1;
		   jsm_cksum_ok	= (rd_data >> 5) & 0x1;
		   jsm_wdcnt_ok	= (rd_data >> 6) & 0x1;

		   adr     = jtagsm1_adr+base_adr;			// read new word count
		   status  = vme_read(adr,rd_data);
		   jsm_wdcnt = rd_data;

		   if (jsm_wdcnt    !=0 ||					// check that status bits cleared
				   jsm_busy     !=0 ||
				   jsm_aborted  !=0 ||
				   jsm_cksum_ok !=0 ||
				   jsm_wdcnt_ok !=0) pause("\tjsm status bits failed to clear");

		   adr     = jtagsm0_adr+base_adr;
		   wr_data = 0x1 | (jsm_throttle<<12);		// fire machine
		   status  = vme_write(adr,wr_data);
		   wr_data = 0x0 | (jsm_throttle<<12);		// un-fire machine
		   status  = vme_write(adr,wr_data);

		   for (i=1; i<=1000; ++i) {				// wait for busy to clear
			   status   = vme_read(adr,rd_data);
			   jsm_busy = (rd_data>>3) & 0x1;
			   if (jsm_busy==0) goto L30720;
		   }
		   pause("\tjtagsm stuck in busy state");

L30720:
		   if (ifunc>0) printf("\tjtagsm machine finished, ncycles=%4i\n",i);

		   if (ifunc<=0) {
			   sleep(1);
			   goto L30710; // bang mode
		   }

		   goto L30700;
	   }
	   //------------------------------------------------------------------------------
	   //	VME PROM utilities
	   //------------------------------------------------------------------------------
	   void L3100() {
L3100:

		   // Display menu
		   printf("\n");
		   printf("\tVME PROM Utilities Submenu:\n");
		   printf("\t1: Create  VME PROM data ascii file\n");
		   printf("\t2: Convert VME PROM ascii to Intel MCS-86 PROM format\n");
		   printf("\t3: Convert VME PROM mcs file to XSVF\n");
		   printf("\t4: Read    VME PROM data\n");
		   printf("\t5: VME PROM state machine\n");
		   printf("\t<cr> Exit\n");
		   printf("       > ");

		   gets(line);
		   if (line[0]==NULL) return;
		   sscanf(line,"%i",&ifunc);

		   i=abs(ifunc);
		   if (i== 1) goto L31100;
		   if (i== 2) goto L31200;
		   if (i== 3) goto L31300;
		   if (i== 4) goto L31400;
		   if (i== 5) goto L31500;

		   goto L3100;

		   //------------------------------------------------------------------------------
		   //	Create PROM data ascii file
		   //------------------------------------------------------------------------------
L31100:
		   // Inquire prom output file
		   ilen=256;
		   printf("\tPROM size 256 or 512 <cr=%3i> ",ilen);
		   gets(line);
		   if (line[0]!=NULL) sscanf(line,"%i",&ilen);
		   if ((ilen!=256) && (ilen!=512)) goto L31100;

		   sprintf(csize,"%3.3i",ilen);
		   ssize = string(csize);
		   prom_file_name_default = string("vmeprom").append(ssize).append(".txt");

		   printf("\tPROM output file name: <cr=%s>",prom_file_name_default.c_str());

		   gets(line);
		   if (line[0]==0) {prom_file_name = prom_file_name_default;}
		   else            {prom_file_name = string(line);}

		   // Open prom file
		   if (prom_file!=NULL) fclose(prom_file);
		   prom_file = fopen(prom_file_name.c_str(),"w");

		   if (prom_file!=NULL) {fprintf(stdout,"\tOpened file    %s\n",prom_file_name.c_str());}
		   else                 {fprintf(stdout,"\tFailed to open %s\n",prom_file_name.c_str()); pause("WTF?"); goto L31100;}

		   // Inquire header data
		   _strdate(datestr);
		   imonth = (datestr[0]-'0') * 16;
		   imonth = (datestr[1]-'0') *  1 | imonth;
		   iday   = (datestr[3]-'0') * 16;
		   iday   = (datestr[4]-'0') *  1 | iday;
		   iyear  = (datestr[6]-'0') * 16;
		   iyear  = (datestr[7]-'0') *  1 | iyear | 0x2000;

		   inquire("\tCLCT Begin marker %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_begin_marker = 0x00BC);
		   inquire("\tCLCT Type         %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, clct_type        = 0x0384);
		   inquire("\tCLCT Month        %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_month        = imonth);
		   inquire("\tCLCT Day          %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_day          = iday  );
		   inquire("\tCLCT Year         %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_year         = iyear );
		   inquire("\tCLCT Version      %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_version      = 0x0000);
		   inquire("\tCLCT Option0      %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_option0      = 0x00AA);
		   inquire("\tCLCT Option1      %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_option1      = 0x00AA);
		   inquire("\tCLCT Option2      %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_option2      = 0x0055);
		   inquire("\tCLCT Option3      %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_option3      = 0x0055);
		   inquire("\tCLCT Option4      %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vsm_option4      = 0x0000);
		   inquire("\tCLCT Adr E2       %4.4X", minv=0x0000, maxv=0xFFFF, radix=16, vmesm4_data      = 0x55AA);

		   // insert fixed data at vmesm4_adr
		   nmodified=1;
		   store_adr[nmodified]  = vmesm4_adr;
		   store_data[nmodified] = 0x55AA;

		   // Inquire VME data
		   printf("\n\tEnter VME Address to modify: <cr>=done\n");

L31120:
		   printf("\tAdr, data=");
		   gets(line);
		   if (line[0]==NULL) goto L31180;		// <cr> = done
		   sscanf(line,"%X,%X",&newadr,&wr_data);

		   if ((newadr <0) || (newadr >0xFFFFFF)) {printf("\tAdr  out of range 0-FFFFFF, read=%X\n",newadr ); goto L31120;}
		   if ((wr_data<0) || (wr_data>0xFFFF  )) {printf("\tData out of range 0-FFFF,   read=%X\n",wr_data); goto L31120;}

		   dprintf(stdout,"\tadr = %X\n",newadr);
		   dprintf(stdout,"\tdata= %X\n",wr_data);

		   // Store
		   nmodified++;
		   if (nmodified>mxmodified) pause("increase mxmodified");
		   store_adr[nmodified]  = newadr;
		   store_data[nmodified] = wr_data;
		   goto L31120;

		   // Summary
L31180:
		   printf("\tAddresses modified=%5i\n",nmodified);

		   for (i=1; i<=nmodified; ++i) {
			   printf("\tAdr=%6.6X data=%4.4X\n",store_adr[i],store_data[i]);
		   }
		   printf("\n");

		   // Insert header
		   adr      = 0;
		   cksum    = 0;
		   vsm_data = 0;
		   prom_wdcnt = nmodified*5+16+3;	// 3 adr, 2 data per addy, 16 header 3 trailer

		   for (i=0; i<=0xF; ++i) {
			   switch (adr)
			   {
				   case 0x0: vsm_data = vsm_begin_marker;			break;
				   case 0x1: vsm_data =(prom_wdcnt >> 0) & 0xFF;	break;
				   case 0x2: vsm_data =(prom_wdcnt >> 8) & 0xFF;	break;
				   case 0x3: vsm_data =(clct_type  >> 0) & 0xFF;	break;
				   case 0x4: vsm_data =(clct_type  >> 8) & 0xFF;	break;
				   case 0x5: vsm_data = vsm_month;					break;
				   case 0x6: vsm_data = vsm_day;					break;
				   case 0x7: vsm_data =(vsm_year   >> 0) & 0xFF;	break;
				   case 0x8: vsm_data =(vsm_year   >> 8) & 0xFF;	break;
				   case 0x9: vsm_data = vsm_version;				break;
				   case 0xA: vsm_data = vsm_option0;				break;
				   case 0xB: vsm_data = vsm_option1;				break;
				   case 0xC: vsm_data = vsm_option2;				break;
				   case 0xD: vsm_data = vsm_option3;				break;
				   case 0xE: vsm_data = vsm_option4;				break;
				   case 0xF: vsm_data = 0xEC;						break;	//  end header marker
			   }

			   cksum = (cksum+vsm_data) & 0xFF;
			   fprintf(stdout, "\t%4.4X %2.2X Header  cksum=%2.2X\n",adr,vsm_data,cksum);
			   fprintf(prom_file,"%4.4X %2.2X Header  cksum=%2.2X\n",adr,vsm_data,cksum);
			   adr++;
		   }	// close i

		   // Insert vme addresses and data
		   for (i=1; i<=nmodified; ++i) {
			   for (j=1; j<=5; ++j) {
				   vstr = "wtf??? ";
				   switch (j)
				   {
					   case 0x1: vsm_data = (store_adr[i]  >>  0) & 0xFF;	vstr = "adr0   ";	break;
					   case 0x2: vsm_data = (store_adr[i]  >>  8) & 0xFF;	vstr = "adr1   ";	break;
					   case 0x3: vsm_data = (store_adr[i]  >> 16) & 0xFF;	vstr = "adr2   ";	break;
					   case 0x4: vsm_data = (store_data[i] >>  0) & 0xFF;	vstr = "data0  ";	break;
					   case 0x5: vsm_data = (store_data[i] >>  8) & 0xFF;	vstr = "data1  ";	break;
				   }

				   cksum = (cksum+vsm_data) & 0xFF;
				   fprintf(stdout, "\t%4.4X %2.2X %s cksum=%2.2X\n",adr,vsm_data,vstr.c_str(),cksum);
				   fprintf(prom_file,"%4.4X %2.2X %s cksum=%2.2X\n",adr,vsm_data,vstr.c_str(),cksum);

				   adr++;

				   if (adr > (1 << 15)-3) pause("PROM address > 32K, will not fit in 256Kbit PROM");
				   if (adr > (1 << 16)-3) pause("PROM address > 64K, will not fit in 512Kbit PROM");
			   }	// close j
		   }	// close i

		   // Insert Trailer
		   L = prom_wdcnt-1;

		   for (i=1; i<=3; ++i) {

			   if (adr==L-2) vsm_data = 0xFC;	// vsm_end_data_marker
			   if (adr==L-1) vsm_data = cksum;
			   if (adr==L  ) vsm_data = 0xFF;	// vsm_end_prom_marker
			   if (adr==L-2) cksum    = (cksum+vsm_data) & 0xFF;

			   fprintf(stdout, "\t%4.4X %2.2X Trailer cksum=%2.2X\n",adr,vsm_data,cksum);
			   fprintf(prom_file,"%4.4X %2.2X Trailer cksum=%2.2X\n",adr,vsm_data,cksum);

			   adr++;
		   }	// close i

		   // Done
		   printf("\n\tWord count=%5id %4.4Xh Checksum=%2.2X\n",prom_wdcnt,prom_wdcnt,cksum);

		   fclose(prom_file);
		   goto L3100;

		   //------------------------------------------------------------------------------
		   // Convert VME PROM ascii to Intel MCS-86 PROM format
		   //------------------------------------------------------------------------------
L31200:
		   pause ("Use xsvfwriter to convert txt to xsvf");
		   goto L3100;

		   //------------------------------------------------------------------------------
		   // Convert VME PROM mcs file to XSVF
		   //------------------------------------------------------------------------------
L31300:
		   pause ("Use xsvfwriter to convert txt to xsvf");
		   goto L3100;

		   //------------------------------------------------------------------------------
		   //	Read back VME Prom data via TMB FPGA
		   //------------------------------------------------------------------------------
L31400:
		   // Get dump file name
		   iprom = 0;		//  TMB PROM
		   sprintf(cprom,"%1i",iprom);
		   dump_file_name_default = string("userprom").append(cprom).append("_readback.txt");

		   printf("\tPROM Dump output file: <cr=%s>",dump_file_name_default.c_str());
		   gets(line);
		   n = line[0];
		   if (n<=0) {dump_file_name = dump_file_name_default;}
		   else      {dump_file_name = string(line);}

		   // Open dump file
		   if (dump_file!=0) fclose(dump_file);
		   dump_file = fopen(dump_file_name.c_str(),"w");

		   if (dump_file != NULL)  fprintf(stdout,"\tOpened file    %s\n",dump_file_name.c_str());
		   if (dump_file == NULL) {fprintf(stdout,"\tFailed to open %s\n",dump_file_name.c_str()); pause("WTF?"); goto L31400;}

		   // Put date into verify file for kix
		   _strtime(timestr);
		   _strdate(datestr);

		   fprintf(dump_file,"PROM dump started: %s %s\n",datestr,timestr);

		   // Determine prom type
		   ichain  = 0x0008;							// User PROM chain
		   adr     = boot_adr;
		   vme_jtag_anystate_to_rti(adr,ichain);		// Take TAP to RTI
		   opcode  = 0xFE;								// IDcode opcode
		   reg_len = 32;								// IDcode length

		   chip_id = iprom;										// Loop over PROM chips
		   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
		   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

		   tdi_to_i4(&tdo[0],idcode,32,0);

		   if       (idcode==0x05022093) {ssize = "256"; ilen = 256*1024/8;}
		   else if  (idcode==0x05023093) {ssize = "512"; ilen = 512*1024/8;}
		   else if  (idcode==0x05033093) {ssize = "512"; ilen = 512*1024/8;}
		   else                          {ssize = "unk"; ilen = 0;}

		   printf("\tXilinx User PROM%1i IDcode=%8.8X %sKbit\n",chip_id,idcode,ssize.c_str());
		   if (ilen==0) pause("Can not determine PROM size");

		   // Enable 1 prom disable the other, they share the onboard led bus
		   jprom = (iprom+1)%2;

		   prom_clk[iprom] = 0;	// enable this one
		   prom_oe[iprom]  = 1;
		   prom_nce[iprom] = 0;

		   prom_clk[jprom] = 0;	// disble this one
		   prom_oe[jprom]  = 0;
		   prom_nce[jprom] = 1;
		   prom_src = 1;

		   adr     = vme_prom_adr+base_adr;
		   wr_data = 
			   (prom_src    << 14) |
			   (prom_nce[1] << 13) |
			   (prom_oe[1]  << 12) |
			   (prom_clk[1] << 11) |
			   (prom_nce[0] << 10) |
			   (prom_oe[0]  <<  9) |
			   (prom_clk[0] <<  8);

		   status = vme_write(adr,wr_data);

		   // Read data from selected PROM
		   cksum      = 0;
		   wdcnt      = 0;
		   prom_wdcnt = 0;
		   L          = 65535;
		   nmodified  = 0;

		   for (prom_adr=0; prom_adr<=ilen-1; ++prom_adr) {
			   status    = vme_read(adr,rd_data);
			   prom_data = rd_data & 0xFF;

			   if (prom_adr==0) {
				   fprintf(dump_file,"PROM PROM  File\n");	
				   fprintf(dump_file,"Adr  Data  Data\n");
			   }
			   fprintf(dump_file,"%4.4X %2.2X    %4.4X\n",prom_adr,prom_data,prom_data);

			   // Extract header frame data
			   vsm_data = prom_data & 0xFF;

			   switch (prom_adr)
			   {
				   case 0x0: vsm_begin_marker = vsm_data;						break;
				   case 0x1: prom_wdcnt       = vsm_data;						break;
				   case 0x2: prom_wdcnt       =(vsm_data << 8) | prom_wdcnt;	break;
				   case 0x3: clct_type	       = vsm_data;						break;
				   case 0x4: clct_type	       =(vsm_data << 8) | clct_type;	break;
				   case 0x5: vsm_month        = vsm_data;						break;
				   case 0x6: vsm_day          = vsm_data;						break;
				   case 0x7: vsm_year         = vsm_data;						break;
				   case 0x8: vsm_year         =(vsm_data << 8) | vsm_year;		break;
				   case 0x9: vsm_version      = vsm_data;						break;
				   case 0xA: vsm_option0      = vsm_data;						break;
				   case 0xB: vsm_option1      = vsm_data;						break;
				   case 0xC: vsm_option2      = vsm_data;						break;
				   case 0xD: vsm_option3      = vsm_data;						break;
				   case 0xE: vsm_option4      = vsm_data;						break;
				   case 0xF: vsm_end_header   = vsm_data;						break;
			   }

			   // Extract VME addresses and data
			   if ((prom_adr>0xF) & (prom_adr<(L-2))) {

				   adr_mod5 = (prom_adr-0x10)%5;
				   if (adr_mod5==0) nmodified++;
				   if (nmodified>mxmodified) pause("increase mxmodified");
				   i = nmodified-1;

				   switch (adr_mod5)
				   {
					   case 0x0: store_adr[i] = vsm_data;							break;
					   case 0x1: store_adr[i] = store_adr[i]  | (vsm_data <<  8);	break;
					   case 0x2: store_adr[i] = store_adr[i]  | (vsm_data << 16);	break;
					   case 0x3: store_data[i]= vsm_data;							break;
					   case 0x4: store_data[i]= store_data[i] | (vsm_data <<  8);	break;
				   }
			   }	// close if prom_adr

			   // Extract trailer frame data
			   if (prom_adr == 2  ) L                   = prom_wdcnt-1;
			   if (prom_adr == L-2) vsm_end_data_marker = vsm_data;
			   if (prom_adr == L-1) prom_cksum          = vsm_data;
			   if (prom_adr == L  ) vsm_end_prom_marker = vsm_data;

			   // Frame descriptions
			   svsm_frame_type = "Unknown         ";
			   if (prom_adr == 0x0000) svsm_frame_type = "Begin   Marker: ";
			   if (prom_adr == 0x0001) svsm_frame_type = "Wordcount[ 7:0]:";
			   if (prom_adr == 0x0002) svsm_frame_type = "Wordcount[15:8]:";
			   if (prom_adr == 0x0003) svsm_frame_type = "CSC type [ 7:0]:";
			   if (prom_adr == 0x0004) svsm_frame_type = "CSC type [15:8]:";
			   if (prom_adr == 0x0005) svsm_frame_type = "Month:          ";
			   if (prom_adr == 0x0006) svsm_frame_type = "Day:            ";
			   if (prom_adr == 0x0007) svsm_frame_type = "Year     [ 7:0]:";
			   if (prom_adr == 0x0008) svsm_frame_type = "Year:    [15:8]:";
			   if((prom_adr >= 0x0009) && 
					   (prom_adr <= 0x000E))svsm_frame_type = "Option:         ";
			   if (prom_adr == 0x000F) svsm_frame_type = "End Hdr Marker: ";
			   if((prom_adr >  0x000F) &&
					   (prom_adr <  L-2   ))svsm_frame_type = "VME adr/data:   ";
			   if (prom_adr == L-2   ) svsm_frame_type = "End Dta Marker: ";
			   if (prom_adr == L-1   ) svsm_frame_type = "Checksum:       ";
			   if (prom_adr == L     ) svsm_frame_type = "End     Marker: ";

			   // Accumulate word count and check-sum as would be seen by vmesm state machine
			   if ((prom_adr>=0) && (prom_adr<=L-2)) cksum = (cksum+prom_data) & 0xFF;
			   if ((prom_adr>=0) || (prom_adr<=L  )) wdcnt++;

			   if (((prom_adr<=L) || (L==0)) && (prom_adr<256))
				   printf("\t%s %4.4X  %2.2X  %2.2X\n",svsm_frame_type.c_str(),prom_adr,prom_data,cksum);

			   // Toggle clock to advance address
			   prom_clk[iprom] = 1;
			   adr     = vme_prom_adr+base_adr;
			   wr_data = 
				   (prom_src    << 14) |
				   (prom_nce[1] << 13) | 
				   (prom_oe[1]  << 12) |
				   (prom_clk[1] << 11) | 
				   (prom_nce[0] << 10) | 
				   (prom_oe[0]  <<  9) | 
				   (prom_clk[0] <<  8);

			   status = vme_write(adr,wr_data);

			   prom_clk[iprom] = 0;
			   wr_data = 
				   (prom_src    << 14) |
				   (prom_nce[1] << 13) | 
				   (prom_oe[1]  << 12) |
				   (prom_clk[1] << 11) | 
				   (prom_nce[0] << 10) |
				   (prom_oe[0]  <<  9) | 
				   (prom_clk[0] <<  8);

			   status = vme_write(adr,wr_data);

			   // Continue PROM adrs
			   if (prom_adr>=L) goto L31420;
		   } // close prom_adr

		   // Close files
L31420:
		   fclose(dump_file);

		   // Turn PROMs off
		   prom_clk[iprom] = 0;	// disble this one
		   prom_oe[iprom]  = 0;
		   prom_nce[iprom] = 1;
		   prom_src = 0;

		   adr     = vme_prom_adr+base_adr;
		   wr_data = 
			   (prom_src    << 14) |
			   (prom_nce[1] << 13) |
			   (prom_oe[1]  << 12) |
			   (prom_clk[1] << 11) |
			   (prom_nce[0] << 10) |
			   (prom_oe[0]  <<  9) | 
			   (prom_clk[0] <<  8);

		   status = vme_write(adr,wr_data);

		   // Display PROM data summary
		   printf("\n");
		   printf("\tvsm_begin_marker    %6.2X\n",vsm_begin_marker);
		   printf("\tclct_type           %6.3X\n",clct_type);
		   printf("\tvsm_month           %6.2X\n",vsm_month);
		   printf("\tvsm_day             %6.2X\n",vsm_day);
		   printf("\tvsm_year            %6.4X\n",vsm_year);
		   printf("\tvsm_version         %6.2X\n",vsm_version);
		   printf("\tvsm_end_header      %6.2X\n",vsm_end_header);

		   if (nmodified==0) printf("\tno VME address data!\n");
		   else {
			   for (i=0; i<nmodified; ++i) {
				   printf("\tvme edits       adr=%6.6X data=%4.4X\n",store_adr[i],store_data[i]);
			   }
		   }

		   printf("\tvsm_end_data_marker %6.2X\n", vsm_end_data_marker);
		   printf("\tvsm_end_prom_marker %6.2X\n", vsm_end_prom_marker);
		   printf("\twdcnt calc          %6i\n",   wdcnt);
		   printf("\twdcnt stored        %6i\n",   prom_wdcnt);
		   printf("\tcksum calc          %6.2X\n", cksum);
		   printf("\tcksum stored        %6.2X\n", prom_cksum);

		   sresult_cksum = "Checksum  Match:";
		   sresult_wdcnt = "Wordcount Match:";

		   if (prom_cksum!=cksum) sresult_cksum = "Checksum  Error:";
		   if (prom_wdcnt!=wdcnt) sresult_wdcnt = "Wordcount Error:";

		   printf("\t%s calc=%6.2X stored=%6.2X\n",sresult_cksum.c_str(),cksum,prom_cksum);
		   printf("\t%s calc=%6i stored=%6i\n",sresult_wdcnt.c_str(),wdcnt,prom_wdcnt);

		   printf("\n");
		   goto L3100;

		   //------------------------------------------------------------------------------
		   //	VME PROM state machine
		   //------------------------------------------------------------------------------
L31500:
		   // Get current status
		   adr    = vmesm0_adr+base_adr;
		   status = vme_read(adr,rd_data);

		   vsm_start		= (rd_data >>  0) & 0x1;
		   vsm_sreset		= (rd_data >>  1) & 0x1;
		   vsm_autostart	= (rd_data >>  2) & 0x1;
		   vsm_busy		= (rd_data >>  3) & 0x1;
		   vsm_aborted		= (rd_data >>  4) & 0x1;
		   vsm_cksum_ok	= (rd_data >>  5) & 0x1;
		   vsm_wdcnt_ok	= (rd_data >>  6) & 0x1;
		   vsm_jtag_auto	= (rd_data >>  7) & 0x1;
		   vsm_vme_ready	= (rd_data >>  8) & 0x1;
		   vsm_ok			= (rd_data >>  9) & 0x1;
		   vsm_pathok		= (rd_data >> 10) & 0x1;
		   vsm_unass0		= (rd_data >> 11) & 0x1;
		   vsm_throttle	= (rd_data >> 12) & 0xF;

		   adr    = vmesm1_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   vsm_wdcnt = rd_data;

		   adr    = vmesm2_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   vsm_cksum   = rd_data & 0xFF;
		   vsm_fmt_err = (rd_data >> 8) & 0x1F;

		   vsm_fmt_err0 = (vsm_fmt_err >> 0) & 0x1;
		   vsm_fmt_err1 = (vsm_fmt_err >> 1) & 0x1;
		   vsm_fmt_err2 = (vsm_fmt_err >> 2) & 0x1;
		   vsm_fmt_err3 = (vsm_fmt_err >> 3) & 0x1;
		   vsm_fmt_err4 = (vsm_fmt_err >> 4) & 0x1;

		   adr    = vmesm3_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   vsm_nvme_writes = rd_data & 0xFF;

		   adr    = vmesm4_adr+base_adr;
		   status = vme_read(adr,rd_data);
		   vsm_path = rd_data;

		   printf("\tCurrent VME PROM State Machine Status\n");
		   printf("\tstart:         %5i\n",vsm_start);
		   printf("\tsreset:        %5i\n",vsm_sreset);
		   printf("\tautostart:     %5i\n",vsm_autostart);
		   printf("\tbusy:          %5i\n",vsm_busy);
		   printf("\taborted:       %5i\n",vsm_aborted);
		   printf("\tcksum_ok:      %5i\n",vsm_cksum_ok);
		   printf("\twdcnt_ok:      %5i\n",vsm_wdcnt_ok);
		   printf("\tjtag_auto:     %5i\n",vsm_jtag_auto);
		   printf("\tvme_ready:     %5i\n",vsm_vme_ready);
		   printf("\tvsm_ok         %5i\n",vsm_ok);
		   printf("\tvsm_pathok     %5i\n",vsm_pathok);
		   printf("\tunass0         %5i\n",vsm_unass0);
		   printf("\tthrottle:      %5i\n",vsm_throttle);
		   printf("\twdcnt:         %5i\n",vsm_wdcnt);
		   printf("\tcksum:         %5X\n",vsm_cksum);
		   printf("\tfmt_err:       %5X\n",vsm_fmt_err);
		   printf("\t0: missing BC: %5i\n",vsm_fmt_err0);
		   printf("\t1: missing EC: %5i\n",vsm_fmt_err1);
		   printf("\t2: missing FC: %5i\n",vsm_fmt_err2);
		   printf("\t3: missing FF: %5i\n",vsm_fmt_err3);
		   printf("\t4: wdcnt ovf:  %5i\n",vsm_fmt_err4);
		   printf("\tnvme_writes:   %5i\n",vsm_nvme_writes);
		   printf("\tvsm_path:      %5.4X\n",vsm_path);

		   // Inquire re-fire
		   printf("\n\tFire VME PROM State Machine y/n? <cr=n> ");
		   gets(line);
		   n=strlen(line);
		   i=line[0];
		   if ((n==0) || ((i!='Y') && (i!='y'))) goto L3100;

		   printf("\tPROM throttle[0-15]? <cr=%2i>",vsm_throttle);
		   gets(line);
		   n=strlen(line);
		   sscanf(line,"%i",&i);

		   if (n!=0 && ((i>15) || (i<0))) {
			   pause ("Throttle out of range 0-15");
			   goto L31500;
		   }
		   if (n!=0) vsm_throttle=i;

		   // Re-fire VME PROM state machine
L31510:
		   adr     = boot_adr;
		   status  = vme_read(adr,rd_data);		// get current boot register
		   wr_data = rd_data & 0xFF7F;
		   status  = vme_write(adr,wr_data);		// make fpga the jtag master

		   adr     = vmesm0_adr+base_adr;
		   wr_data = 0x2 | (vsm_throttle << 12);	// clear state machine status
		   status  = vme_write(adr,wr_data);
		   wr_data = (vsm_throttle << 12);			// cancel clear command
		   status  = vme_write(adr,wr_data);

		   status = vme_read(adr,rd_data);			// read new status
		   adr    = vmesm1_adr+base_adr;

		   vsm_busy     = (rd_data >> 3) & 0x1;
		   vsm_aborted  = (rd_data >> 4) & 0x1;
		   vsm_cksum_ok = (rd_data >> 5) & 0x1;
		   vsm_wdcnt_ok = (rd_data >> 6) & 0x1;

		   status = vme_read(adr,rd_data);			// read word count
		   vsm_wdcnt = rd_data;

		   if (
				   (vsm_wdcnt    != 0) ||					//  check that status bits cleared
				   (vsm_busy     != 0) ||
				   (vsm_aborted  != 0) ||
				   (vsm_cksum_ok != 0) ||
				   (vsm_wdcnt_ok != 0)) pause("vsm status bits failed to clear");

		   adr     = vmesm0_adr+base_adr;
		   wr_data = 0x5 || (vsm_throttle << 12);	//  fire machine, assert autostart also
		   status  = vme_write(adr,wr_data);
		   wr_data = (vsm_throttle << 12);			//  un-fire machine
		   status  = vme_write(adr,wr_data);

		   for (i=1; i<=1000; ++i) {				//  wait for busy to clear
			   status   = vme_read(adr,rd_data);
			   vsm_busy = (rd_data >> 3) & 0x1;
			   if (vsm_busy==0) goto L31520;
		   }
		   pause ("vmesm stuck in busy state");

L31520:
		   if (ifunc>0) 
			   printf("\tvmesm machine finished, ncycles=%4i\n\n",i);

		   // Bang mode
		   if (ifunc<=0) {
			   sleep(1);
			   goto L31510;	// bang
		   }
		   goto L31500;	// menu
	   }
	   //------------------------------------------------------------------------------
	   //	Check U76 JTAG Bus-Hold circuit
	   //------------------------------------------------------------------------------
	   void L3200() {
L3200:

		   // itest=6,7
		   // Check U76 can select FPGA chain
		   // Put boot register back to power-up state
		   adr     = boot_adr;
		   wr_data = 0;
		   status	= vme_write(adr,wr_data);

		   // Select FPGA Mezzanine FPGA programming JTAG chain from TMB boot register
		   if (id_rev_fpga==6) {ichain=0x14; nchips=3;}	// Virtex6 TMB Mezzanine pgm jtag chain
		   else                {ichain=0x04; nchips=5;}	// Virtex2 TMB Mezzanine pgm jtag chain

		   ichain = 0x0004;								// TMB Mezzanine pgm jtag chain
		   adr    = boot_adr;								// Boot register address
		   vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI

		   // Read Virtex2 FPGA (6-bit opcode) and XC18V04 PROM IDcodes (8-bit opcode)
		   for (chip_id=0; chip_id<nchips; ++chip_id) {
			   itest = chip_id+8;
			   tmb_nfailed[itest] = 0;
			   tmb_npassed[itest] = 0;
			   tmb_nskipped[itest]= 0;

			   if (chip_id == 0) opcode = 0x09;				// FPGA IDcode opcode, expect v0A30093
			   if (chip_id >= 1) opcode = 0xFE;				// PROM IDcode opcode
			   reg_len = 32;									// IDcode length
			   // FPGA,PROM chip
			   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
			   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode

			   // Interpret ID code
			   tdi_to_i4(&tdo[0],idcode,32,0);

			   sprintf(cid, "%1i",  chip_id);	// Convert chip_id to string
			   sprintf(cidc,"%8.8X",idcode);	// Convert idcode  to string

			   sid  = string(cid);
			   sidc = string(cidc);

			   if (chip_id==0)
			   {
				   if (id_rev_fpga==6) status=cks(string("FPGAmez ID Code ").append(sid),idcode,0x2424C093);
				   else                status=cks(string("FPGAmez ID Code ").append(sid),idcode,0x11050093);

				   if (status             != 0) tmb_nfailed[itest] = 1;
				   if (tmb_nfailed[itest] == 0) tmb_npassed[itest] = 1;	

				   aokf(string("FPGAmez ID Code ").append(sid).append(" ").append(sidc),itest,tmb_npassed[itest]);
				   if (pause_on_fail && (tmb_nfailed[itest] != 0)) pause(" ");
			   }

			   else
			   {
				   //	                    X5036093		// whacks leading digit, converts 5036093 to 5026093
				   idcode = idcode & 0x0FFEFFFF;		// newer proms have idcode  X5036093, older proms have 05026093
				   if (id_rev_fpga==6) status=cks(string("PROMmez ID Code ").append(sid),idcode,0x05049093);
				   else                status=cks(string("PROMmez ID Code ").append(sid),idcode,0x05026093);

				   if (status             != 0) tmb_nfailed[itest] = 1;
				   if (tmb_nfailed[itest] == 0) tmb_npassed[itest] = 1;

				   aokf(string("PROMmez ID Code ").append(sid).append(" ").append(sidc),itest,tmb_npassed[itest]);
				   if (pause_on_fail && (tmb_nfailed[itest] != 0)) pause(" ");
			   }	// close if chip_id
		   }	// close for chip_id

		   // Check U76 can select user prom chain
		   // Put boot register back to power-up state
		   adr     = boot_adr;
		   wr_data = 0;
		   status	= vme_write(adr,wr_data);

		   // Loop over Chain sources Usr,Boot
		   for (ijtag_src=0; ijtag_src<=1; ++ijtag_src) {	// 0=Usr source, 1=boot source

			   itest = ijtag_src+6;
			   tmb_nfailed[itest] = 0;
			   tmb_npassed[itest] = 0;
			   tmb_nskipped[itest]= 0;

			   if (ijtag_src == 0) adr = vme_usr_jtag_adr+base_adr;
			   if (ijtag_src == 1) adr = boot_adr;
			   status = vme_write(adr,wr_data);

			   // Select user PROM chain
			   ichain = 0x0008;								// User PROM chain
			   vme_jtag_anystate_to_rti(adr,ichain);			// Take TAP to RTI
			   opcode  = 0xFE;									// IDcode opcode
			   reg_len = 32;									// IDcode length

			   for (chip_id=0; chip_id<=1; ++chip_id) {
				   vme_jtag_write_ir(adr,ichain,chip_id,opcode);			// Set opcode
				   vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);	// Write 0's read idcode
				   tdi_to_i4(&tdo[0],idcode,32,0);

				   user_idcode[chip_id] = idcode;

				   sprintf(cid, "%1i",  chip_id);	// Convert chip_id to string
				   sprintf(cidc,"%8.8X",idcode);	// Convert idcode  to string

				   sid  = string(cid);
				   sidc = string(cidc);

				   // user proms may have idcode 05022093 for 256KB, and either 05023093 or 05033093 for 512KB
				   idcode = idcode & 0xFFFEEFFF;	// blank 23 or 33 case
				   status = cks(string("PROMusr ID Code ").append(sid),idcode,0x05022093);	// xc18v256 idcode
				   if (status != 0) tmb_nfailed[itest] = 1;

				   // require both PROMs to have same idcode
				   if (chip_id == 1 ) {
					   if (user_idcode[0] != user_idcode[1]) {
						   tmb_nfailed[itest] = 1;
						   fprintf(log_file,"\tUser PROM IDcode Mismatch: U80=%8.8X U81=%8.8X\n",user_idcode[0],user_idcode[1]);
						   fprintf(stdout,  "\tUser PROM IDcode Mismatch: U80=%8.8X U81=%8.8X\n",user_idcode[0],user_idcode[1]);
					   }	//  close user_idcode
				   }	//  close chip_id

				   if (tmb_nfailed[itest] == 0) tmb_npassed[itest] = 1;	
				   aokf(string("PROMusr ID Code ").append(sid).append(" ").append(sidc),itest,tmb_npassed[itest]);
				   if (pause_on_fail && (tmb_nfailed[itest] != 0)) pause(" ");

			   }	//  close chip_id
		   }	//  close ijtag_src

		   // Put boot register back to power-up state
		   adr     = boot_adr;
		   wr_data = 0;
		   status	= vme_write(adr,wr_data);

		   // Loop over Chain sources Usr,Boot
		   if (firmware_type == firmware_normal) goto L3220;	// Normal firmware can't do this section, as it uses gpio for outputs
		   for (ijtag_src=0; ijtag_src<=1; ++ijtag_src) {		// 0=Usr source, 1=boot source
			   itest = 6;
			   if (ijtag_src==1) itest = 7;

			   tmb_nfailed[itest] = 0;
			   tmb_npassed[itest] = 0;
			   tmb_nskipped[itest]= 0;

			   // Loop over tx bits
			   ichain = 0x000C;								//  FPGA chain 1100
			   for (ipass=1; ipass<=100; ++ipass) {
				   for (itx=0; itx<=4; ++itx) {
					   wr_pat = (1 << itx);							//  Step through tdi,tms,tck,sel0,sel1

					   // Send walking 1 to jtag chain
					   wr_data = (1 << itx) | (ichain << 3) | (1 <<7);	// Select FPGA JTAG chain
					   if (ijtag_src==0) adr = vme_usr_jtag_adr+base_adr;
					   if (ijtag_src==1) adr = boot_adr;
					   status	= vme_write(adr,wr_data);

					   // Copy tdi to tdo through gp_io0
					   adr     = vme_gpio_adr+base_adr;
					   status  = vme_read(adr,rd_data);
					   wr_data = (rd_data >> 1) & 0x1;					// get tdi on gp_io1
					   status	= vme_write(adr,wr_data);				// send it back out on gp_io0

					   // Read FPGA chain
					   adr     = vme_gpio_adr+base_adr;
					   status  = vme_read(adr,rd_data);
					   rd_data = rd_data & 0xF;

					   pat_expect = 0;
					   if (itx <= 2) pat_expect = (wr_pat << 1);
					   if (itx == 0) pat_expect = 3;					// cuz you just wrote gp_io0=gp_io1 
					   if (itx >= 3) pat_expect = 0xF;					// sel[1:0]=0 selects FPGA chain, else see pullups to 1

					   if ((itx==0) && (rd_data==0xF)) {
						   pause ("Disconnect jtag cable and restart");
						   return;
					   }

					   if ((rd_data!=pat_expect) && (firmware_type==firmware_debug)) {
						   pause ("JTAG failure on GPIO signals");
						   return;
					   }

					   if (ijtag_src==0) statid[0]=cks("jtag bit USR  chain",rd_data,pat_expect);
					   if (ijtag_src==1) statid[1]=cks("jtag bit Boot chain",rd_data,pat_expect);

					   if ((statid[0]!=0) || (statid[1]!=0)) tmb_nfailed[itest] = 1;
				   } // close itx
			   } // close ipass

			   if (tmb_nfailed[itest]==0) tmb_npassed[itest] = 1;	

			   if (ijtag_src==0) aokf("USR  JTAG Chain",itest,tmb_npassed[itest]);
			   if (ijtag_src==1) aokf("Boot JTAG Chain",itest,tmb_npassed[itest]);

			   if (pause_on_fail && (tmb_nfailed[itest]!=0)) pause(" ");
		   } // close ijtag_src

		   // Put boot register back to power-up state, makes FPGA the jtag chain source
		   adr     = boot_adr;
		   wr_data = 0;
		   status	= vme_write(adr,wr_data);

		   // Write a pattern to U76
L3220:
		   n=2;													// bdtest firmware can only check tdi,tms,tck
		   if (firmware_type == firmware_normal) n=6;				// normal firmware can read back all 7 usr jtag bits from its inout port 

		   for (i=0; i<=n; ++i) {									// loop over tdi,tms,tck
			   pat_expect = (1 << i);									// walking 1 in jtag signals
			   adr        = base_adr+vme_usr_jtag_adr;
			   ichain     = 0x000C;									// FPGA chain 1100
			   if (firmware_type==firmware_normal) ichain = 0x0000;	// Point to oblivion for normal firmware, beco fpga chain will short to gpio
			   wr_data    = (ichain << 3) | pat_expect;				// boot[7]=chain en=0, boot[6:0]=sel[3:0],jtag[2:0]
			   status	   = vme_write(adr,wr_data);

			   // Hard-reset TMB
			   wr_data = wr_data | 0x0200;
			   status  = vme_write(boot_adr,wr_data);					// Assert hard reset
			   wr_data = 0x0000; 
			   status  = vme_write(boot_adr,wr_data);					// De-assert hard reset
			   sleep(500);												// Wait for TMBs to reload, mSecs (TMB takes 100ms, V6 375ms)

			   // Read back U76
			   if (firmware_type==firmware_normal) {
				   adr     = base_adr+vme_usr_jtag_adr;
				   status  = vme_read(adr,rd_data);
				   rd_data = rd_data & 0x007F;
			   }
			   else {
				   adr     = vme_gpio_adr+base_adr;
				   status  = vme_read(adr,rd_data);
				   rd_data = (rd_data >> 1) & 0x7;							// gpio has tck,tms,tdi,tdo, so shift off the tdo
			   }

			   status=cks("U76 bus hold test",rd_data,pat_expect);

			   if (status!=0) {
				   if (ifunc<0) goto L3200;
				   printf("\tU76 did not retain jtag data. Fails.\n");
				   printf("\tU76 may be an SN74LVC2244ADW device or your\n");
				   printf("\tTMB firmware may not have jtag tri-state logic.\n");
				   printf("\tIf U76 is an SN74LVC2244ADW device,\n");
				   printf("\treplace it with SN74LVCH244ADW.\n");
				   pause (" ");
				   return;
			   } // close if status
		   } // close for ipat

		   // Done or bang
		   printf("\tU76 retained jtag data. Passes.\n");
		   if (ifunc<0) goto L3200;
		   pause (" ");
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	VME Register dump
	   //------------------------------------------------------------------------------
	   void L3300() {
L3300:

		   // Get dump file name
		   sprintf(cid_rev,"%4.4X",id_rev);

		   vme_file_name_default = string("tmb_vme_dump_revcode_").append(cid_rev).append(".txt");

		   printf("\tDump output file:    <cr=%s>",vme_file_name_default.c_str());
		   gets(line);
		   n = line[0];
		   if (n<=0) {vme_file_name = vme_file_name_default;}
		   else      {vme_file_name = string(line);}

		   // Open dump file
		   if (vme_file!=NULL) fclose(vme_file);
		   vme_file = fopen(vme_file_name.c_str(),"r");

		   if (vme_file != NULL)  fprintf(stdout,"\tOpened      %s\n",vme_file_name.c_str());
		   if (vme_file == NULL) {
			   fprintf(stdout,"\tFailed to open %s\n",vme_file_name.c_str());
			   pause("WTF?");
			   goto L3300;
		   }

		   // Read VME registers
		   if (last_vme_adr>vme_mx_adr) stop("Increase vme_mx_adr");

		   for (iadr=0; iadr<=last_vme_adr; iadr=iadr+2)
		   {
			   adr    = iadr+base_adr;
			   status = vme_read(adr,rd_data);
			   vme_readback[iadr] = rd_data;
			   fprintf(vme_file,"%6.6X %4.4X\n",iadr,rd_data);
		   }

		   // Done reading
		   printf("\tLast address=%6.6X\n",last_vme_adr);
		   fclose(vme_file);

		   // Inquire compare file
L3310:
		   printf("\tCompare input file:  <cr=%s>",vme_file_name_default.c_str());
		   gets(line);
		   n = line[0];
		   if (n<=0) {vme_file_name = vme_file_name_default;}
		   else      {vme_file_name = string(line);}

		   // Open compare file
		   if (vme_file!=NULL) fclose(vme_file);
		   vme_file = fopen(vme_file_name.c_str(),"r");

		   if (vme_file != NULL)  fprintf(stdout,"\tOpened      %s\n",vme_file_name.c_str());
		   if (vme_file == NULL) {
			   fprintf(stdout,"\tFailed to open %s\n",vme_file_name.c_str());
			   pause("WTF?");
			   goto L3310;
		   }

		   // Read compare file
		   nmiss = 0;
		   nadrs = 0;

		   for (iadr=0; iadr<vme_mx_adr; iadr=iadr+2)
		   {
			   if (feof(vme_file)) goto L3320;			// hit end of file
			   fgets(line,81,vme_file);				// get a new line
			   sscanf(line,"%6x %4X%*[^\n]",&iadr_rd,&rd_data_rd);	// get adr and data, skip comments

			   if (iadr != iadr_rd     ) fprintf(stdout,"\tAdr mismatch at iadr=%6.6X iadr_rd=%6.6X\n",iadr,iadr_rd);
			   if (iadr >  last_vme_adr) fprintf(stdout,"\tAdr overflow at iadr_rd=%6.6X\n",iadr_rd);
			   nadrs++;

			   rd_data = 0;
			   if (iadr   <= last_vme_adr) rd_data = vme_readback[iadr];
			   if (rd_data!= rd_data_rd  ) {
				   fprintf(stdout,"\tData mismatch at iadr=%6.6X rd_data(vme)=%4.4X rd_data_rd(file)=%4.4X\n",iadr,rd_data,rd_data_rd);
				   nmiss++;
			   }

		   }	// close for iadr

L3320:
		   if (vme_file!=NULL) fclose(vme_file);

		   printf("\tAddresses read = %3i\n",nadrs);
		   printf("\tMis-matches    = %3i\n",nmiss);

		   pause("\t<cr> return to main_menu");
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	VME Register Load
	   //------------------------------------------------------------------------------
	   void L3400() {
L3400:

		   // Get dump file name
		   if (last_vme_adr > vme_mx_adr) pause("Increase vme_mx_adr");
		   sprintf(cid_rev,"%4.4X",id_rev);
		   vme_file_name_default = string("tmb_vme_dump_revcode_").append(cid_rev).append(".txt");

		   printf("\tDump output file: <cr=%s>",vme_file_name_default.c_str());
		   gets(line);
		   n = line[0];
		   if (n<=0) {vme_file_name = vme_file_name_default;}
		   else      {vme_file_name = string(line);}

		   // Open dump file
		   if (vme_file!=NULL) fclose(vme_file);
		   vme_file = fopen(vme_file_name.c_str(),"r");

		   if (vme_file != NULL)  fprintf(stdout,"\tOpened      %s\n",vme_file_name.c_str());
		   if (vme_file == NULL) {
			   fprintf(stdout,"\tFailed to open %s\n",vme_file_name.c_str());
			   pause("WTF?");
			   goto L3400;
		   }
		   pause ("code incomplete");

		   // Read current VME register values into memory
		   for (iadr=0; iadr<=last_vme_adr; iadr=iadr+2) {
			   adr    = iadr+base_adr;
			   status = vme_read(adr,rd_data);
			   vme_readback[iadr] = rd_data;
		   }

		   // Read dump file into memory to overwrite specified current values
		   nadrs_read = 0;

		   for (iadr=0; iadr<=vme_mx_adr; iadr=iadr+2) {

			   if (feof(raw_file)) goto L3420;
			   fgets(line,81,raw_file);
			   sscanf(line,"%6x %4X%*[^\n]",&iadr_rd,&rd_data_rd);	// get adr and data, skip comments

			   if (iadr != iadr_rd    ) printf("Adr mismatch at iadr=%6.6X iadr_rd=%6.6X\n",iadr,iadr_rd);
			   if (iadr > last_vme_adr) printf("Adr overflow at iadr=%6.6X\n",iadr_rd);
			   nadrs_read++;

			   if (iadr_rd<=last_vme_adr) vme_readback[iadr_rd]=rd_data_rd;
		   }	// close for iadr
		   pause("attempt to read past end of file");
		   if (iadr_rd!=last_vme_adr) pause("dump file does not span adrs");

		   // Done reading dump file
L3420:	
		   if (vme_file != NULL) fclose(vme_file);
		   printf("\tAddresses read=%i3 last adr=%6.6X\n",nadrs_read,iadr_rd);
		   if (nadrs_read<=0) stop("bad addresses");

		   // Write VME registers from memory
		   nadrs_written = 0;

		   for (iadr=0; iadr<=iadr_rd; iadr=iadr+2) {
			   adr     = iadr+base_adr;
			   wr_data = vme_readback[iadr];
			   status  = vme_write(adr,wr_data);
			   nadrs_written++;
		   }
		   if (nadrs_written!=nadrs_read) stop("address count err");

		   // Done
		   if (vme_file != NULL) fclose(vme_file);
		   printf("Last address written = %6.6X \n",adr);
		   pause("\tReturn to main menu <cr> ");
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Playback event dump to display header and raw hits
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
	   //------------------------------------------------------------------------------
	   void L3500() {
		   //L3500:

		   // Event dump input file
		   raw_file_name_default = "dump47344.txt";

		   printf("\tEvent dump input file: <cr=%s>",raw_file_name_default.c_str());
		   gets(line);
		   n = line[0];
		   if (n<=0) {raw_file_name = raw_file_name_default;}
		   else      {raw_file_name = string(line);}

		   raw_file      = fopen(raw_file_name.c_str(),"r");

		   if (raw_file  != NULL)  dprintf(stdout,"Opened      %s\n",raw_file_name.c_str());
		   if (raw_file  == NULL) {fprintf(stdout,"\tFailed to open %s\n",raw_file_name.c_str()); pause("\tWTF? <cr>=return to main menu: "); return;}

		   // Read comment line, col(1-4)= !DDU for ddu format, !RAW for raw hits format, !
read_comment:

		   fgets(comment,mxcomment,raw_file);

		   if (feof(raw_file)) {
			   pause ("\tEnd of raw hits file. Exiting.");
			   goto exit_playback;
		   }

		   fprintf(stdout,"\n\t%s",comment);
		   fprintf(log_file,"\n%s",comment);


		   if(comment[0] != '!') {
			   pause ("\tComment line missing. Oh noes! Exiting.");
			   goto exit_playback;
		   }

		   diff=_strnicmp(comment,"!DDU",4);
		   if(diff == NULL) {
			   printf("\t%s\n","File is !DDU format"); 
			   goto read_ddu;
		   }

		   diff=_strnicmp(comment,"!ADRDDU",5);
		   if(diff == NULL) {
			   printf("\t%s\n","File is !ADRDDU format"); 
			   goto read_adrddu;
		   }

		   diff=_strnicmp(comment,"!DMB",4);
		   if(diff == NULL) {
			   printf("\t%s\n","File is !DMB format"); 
			   goto read_dmb;
		   }

		   pause ("\tFile type !DDU or !DMB or !ADRDDU not found on line 1, wtf?");
		   goto exit_playback;

		   // Read DMB raw-hits format dump, 1 address/word per line: Adr=    0 Data= 0DB0C
read_dmb:
		   dmb_wdcnt=0;
		   iadr=99;

		   for (i=0; i<=mxframe; ++i) {
			   if (feof(raw_file)) goto decode;
			   fgets(line,81,raw_file);							// fprintf(log_file,"debug: %i\t%s",i,line);
			   if(line[0]==LF) goto decode;						// hit new event
			   sscanf(line,"%*4s%5i%*7s%5x%*[^\n]",&iadr,&idata);	// get adr and data, skip comments
			   fprintf(log_file,"read: %5i %6.5X\n",iadr,idata);

			   if(iadr != i) {
				   fprintf(log_file,"iadr !=i fault: iadr=%i i=%i\n",iadr,i);
				   fprintf(stderr,"\tiadr !=i fault: iadr=%i i=%i\n",iadr,i);
				   pause ("\tiadr !=i fault. Exiting");
				   goto exit_playback;
			   }

			   vf_data[i]=idata;
			   dmb_wdcnt=dmb_wdcnt+1;
		   }

		   pause ("\tDMB input ovf, increase mxframe. Oh Noes! Exiting.");
		   goto exit_playback;

		   // Read DDU-format data, 4 words per line: db0c d8aa dce8 d0aa
read_ddu:
		   dmb_wdcnt=0;

		   for (i=0; i<=mxframe/4; i=i+4) {
			   if (feof(raw_file)) goto decode;
			   fgets(line,81,raw_file);							// fprintf(log_file,"debug: %i\t%s",i,line);
			   if(line[0]==LF) goto decode;						// hit new event COME BACK TO THIS LATER
			   sscanf(line,"%4x%4x%4x%4x%*[^\n]",&vf_data[i],&vf_data[i+1],&vf_data[i+2],&vf_data[i+3]);
			   fprintf(log_file,"read: %5i %6.5X %6.5X %6.5X %6.5X\n",i,vf_data[i],vf_data[i+1],vf_data[i+2],vf_data[i+3]);
			   dmb_wdcnt=dmb_wdcnt+4;
		   }

		   pause ("\tDDU input ovf, increase mxframe. Oh Noes! Exiting.");
		   goto exit_playback;

		   // Read ADRDDU-format data 02a6ab0 de0d d2f6 d037 da5c db0c dab7 d0de d071
read_adrddu:
		   dmb_wdcnt=0;

		   for (i=0; i<=mxframe/8; i=i+8) {
			   if (feof(raw_file)) goto trim_adrddu;
			   fgets(line,81,raw_file);							// fprintf(log_file,"debug: %i\t%s",i,line);
			   if(line[0]==LF) goto decode;						// hit new event COME BACK TO THIS LATER
			   sscanf(line,"%7x%4x%4x%4x%4x%4x%4x%4x%4x%*[^\n]",&adrddu,
					   &vf_data[i+0],&vf_data[i+1],&vf_data[i+2],&vf_data[i+3],
					   &vf_data[i+4],&vf_data[i+5],&vf_data[i+6],&vf_data[i+7]);

			   fprintf(log_file,"read: %5i %7.7X %4.4X %4.4X %4.4X %4.4X %4.4X %4.4X %4.4X %4.4X\n",i,adrddu,
					   vf_data[i+0],vf_data[i+1],vf_data[i+2],vf_data[i+3],
					   vf_data[i+4],vf_data[i+5],vf_data[i+6],vf_data[i+7]);
			   dmb_wdcnt=dmb_wdcnt+8;
		   }

		   pause ("\tADRDDU input ovf, increase mxframe. Oh Noes! Exiting.");
		   goto exit_playback;

		   // Remove first 4 words, I mean wtf are they doing there anyway?
trim_adrddu:
		   for (i=0; i<=dmb_wdcnt-1; ++i) {
			   vf_data[i]=vf_data[i+4];
		   }
		   dmb_wdcnt=dmb_wdcnt-4;

		   // Decode raw hits dump
decode:
		   printf("\tTMB frames read=%i\n",dmb_wdcnt);

		   decode_readout(vf_data,dmb_wdcnt,err_check=false);

		   goto read_comment;

		   // Done
exit_playback:

		   if (raw_file!=NULL) fclose(raw_file);
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Playback raw hits dump into TMB
	   //------------------------------------------------------------------------------
	   void L3600() {
		   //L3600:

		   pause("\tRaw hits playback not yet implemented. <eturn to main menu <cr> ");
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Read/Write Phaser Delays
	   //------------------------------------------------------------------------------
	   void L3700() {
L3700:

		   // Get current phaser delays
		   alct_rxd_default          = phaser_rd(base_adr,"alct_rxd",  dps_delta);
		   alct_txd_default          = phaser_rd(base_adr,"alct_txd",  dps_delta);
		   cfeb_rxd_delay_default[0] = phaser_rd(base_adr,"cfeb_rxd_0",dps_delta);
		   cfeb_rxd_delay_default[1] = phaser_rd(base_adr,"cfeb_rxd_1",dps_delta);
		   cfeb_rxd_delay_default[2] = phaser_rd(base_adr,"cfeb_rxd_2",dps_delta);
		   cfeb_rxd_delay_default[3] = phaser_rd(base_adr,"cfeb_rxd_3",dps_delta);
		   cfeb_rxd_delay_default[4] = phaser_rd(base_adr,"cfeb_rxd_4",dps_delta);

		   printf("\n");
		   printf("\talct  rxd %3i\n",alct_rxd_default);
		   printf("\talct  txd %3i\n",alct_txd_default);
		   printf("\tcfeb0 rxd %3i\n",cfeb_rxd_delay_default[0]);
		   printf("\tcfeb1 rxd %3i\n",cfeb_rxd_delay_default[1]);
		   printf("\tcfeb2 rxd %3i\n",cfeb_rxd_delay_default[2]);
		   printf("\tcfeb3 rxd %3i\n",cfeb_rxd_delay_default[3]);
		   printf("\tcfeb4 rxd %3i\n",cfeb_rxd_delay_default[4]);
		   printf("\n");

		   alct_txd_delay=alct_txd_default;

		   inquire("\tALCT txd delay %3i", minv=0, maxv=0xFF, radix=10, alct_txd_delay);

		   phaser_wr(base_adr,"alct_txd",alct_txd_delay,dps_delta);
		   goto L3700;

		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Fire VME sysreset
	   //------------------------------------------------------------------------------
	   void L3800() {
L3800:

		   status = vme_sysreset();						// Assert sysreset*

		   sleep(150);										// Wait for VME to reset
		   if (ifunc <0 ) goto L3800;						// Bang mode
		   return;											// Get latest firmware type
	   }
	   //------------------------------------------------------------------------------
	   //	VME Bus Contention Test
	   //------------------------------------------------------------------------------
	   void L3900() {
		   printf("\tVME bus contention test started. Ctrl-c to exit\n");
		   adr     = hcm001_adr+base_adr;
L3900:
		   wr_data = 0xAAAA;
		   status  = vme_write(adr,wr_data);				// Write teven
		   wr_data = 0x5555;
		   status  = vme_write(adr,wr_data);				// Write tod
		   goto L3900;										// Bang mode
	   }
	   //------------------------------------------------------------------------------
	   //	GTX Optical Receiver Status
	   //------------------------------------------------------------------------------
	   void L4000() {
		   //L4000:
		   printf("\tGTX Optical Receiver Status\n");
		   printf("\n");

		   // Read QPPL status and SNAP12 serial interface
		   adr    = adr_virtex6_snap12_qpll+base_adr;
		   status = vme_read(adr,rd_data);

		   qpll_nrst	= (rd_data >> 0) & 0x1;	// RW	nReset QPLL, 0=reset
		   qpll_lock	= (rd_data >> 1) & 0x1;	// R	QPLL locked status
		   qpll_err	= (rd_data >> 2) & 0x1;	// R	QPLL error status

		   r12_sclk	= (rd_data >> 4) & 0x1;	// RW	Serial interface clock, drive high
		   r12_sdat	= (rd_data >> 5) & 0x1;	// R	Serial interface data
		   r12_fok		= (rd_data >> 6) & 0x1;	// R	Serial interface status

		   printf("\tQPLL Status\n");
		   printf("\t[0] qpll_nrst  = %1i\n",qpll_nrst);
		   printf("\t[1] qpll_lock  = %1i\n",qpll_lock);
		   printf("\t[2] qpll_err   = %1i\n",qpll_err);
		   printf("\n");

		   printf("\tGTX Optical Receiver Status\n");
		   printf("\t[4] r12_sclk   = %1i\n",r12_sclk);
		   printf("\t[5] r12_sdat   = %1i\n",r12_sdat);
		   printf("\t[6] r12_fok    = %1i\n",r12_fok);
		   printf("\n");

		   // Read Virtex-6 GTX  common control
		   adr    = adr_virtex6_gtx_rx_all+base_adr;
		   status = vme_read(adr,rd_data);

		   gtx_rx_enable_all			= (rd_data >>  0) & 0x1;	// RW	Enable all GTX optical inputs, you should disable copper via mask_all
		   gtx_rx_reset_all			= (rd_data >>  1) & 0x1;	// RW	Reset all GTX
		   gtx_rx_reset_err_cnt_all	= (rd_data >>  2) & 0x1;	// RW	Reset all PRBS test error counters
		   gtx_rx_en_prbs_test_all		= (rd_data >>  3) & 0x1;	// RW	Select all  random input test data mode
		   gtx_rx_start_all			= (rd_data >>  4) & 0x1;	// R	Set when the DCFEB Start Pattern is present
		   gtx_rx_fc_all				= (rd_data >>  5) & 0x1;	// R	Flags when Rx sees "FC" code (sent by Tx) for latency measurement
		   gtx_rx_valid_all			= (rd_data >>  6) & 0x1;	// R	Valid data detected on link
		   gtx_rx_match_all			= (rd_data >>  7) & 0x1;	// R	PRBS test data match detected, for PRBS tests, a VALID = "should have a match" such that !MATCH is an error
		   gtx_rx_sync_done_all		= (rd_data >>  8) & 0x1;	// R	Use these to determine gtx_ready
		   gtx_rx_pol_swap_all			= (rd_data >>  9) & 0x1;	// R	GTX 5,6 [ie dcfeb 4,5] have swapped rx board routes
		   gtx_rx_err_all				= (rd_data >> 10) & 0x1;	// R	PRBS test detects an error

		   printf("\tGTX Optical Receiver Common CSR\n");
		   printf("\t[0] gtx_rx_enable_all        = %1i\n",gtx_rx_enable_all);
		   printf("\t[1] gtx_rx_reset_all         = %1i\n",gtx_rx_reset_all );
		   printf("\t[2] gtx_rx_reset_err_cnt_all = %1i\n",gtx_rx_reset_err_cnt_all);
		   printf("\t[3] gtx_rx_en_prbs_test_all  = %1i\n",gtx_rx_en_prbs_test_all);
		   printf("\t[4] gtx_rx_start_all         = %1i\n",gtx_rx_start_all);
		   printf("\t[5] gtx_rx_fc_all            = %1i\n",gtx_rx_fc_all);
		   printf("\t[6] gtx_rx_valid_all         = %1i\n",gtx_rx_valid_all);
		   printf("\t[7] gtx_rx_match_all         = %1i\n",gtx_rx_match_all);
		   printf("\t[8] gtx_rx_sync_done_all     = %1i\n",gtx_rx_sync_done_all);
		   printf("\t[9] gtx_rx_pol_swap_all      = %1i\n",gtx_rx_pol_swap_all);
		   printf("\t[A] gtx_rx_err_all           = %1i\n",gtx_rx_err_all);
		   printf("\n");

		   // Read Virtex-6 GTX receiver 0 = 0x14C through receiver 6 = 0x158 status
		   for (idcfeb=0; idcfeb<7; idcfeb++)
		   {
			   adr    = adr_virtex6_gtx_rx0+(idcfeb*2)+base_adr;
			   status = vme_read(adr,rd_data);

			   gtx_rx_enable[idcfeb]			= (rd_data >>  0) & 0x1;	// RW	Enable all GTX optical inputs, you should disable copper via mask_all
			   gtx_rx_reset[idcfeb]			= (rd_data >>  1) & 0x1;	// RW	Reset all GTX
			   gtx_rx_reset_err_cnt[idcfeb]	= (rd_data >>  2) & 0x1;	// RW	Reset all PRBS test error counters
			   gtx_rx_en_prbs_test[idcfeb]		= (rd_data >>  3) & 0x1;	// RW	Select all  random input test data mode
			   gtx_rx_start[idcfeb]			= (rd_data >>  4) & 0x1;	// R	Set when the DCFEB Start Pattern is present
			   gtx_rx_fc[idcfeb]				= (rd_data >>  5) & 0x1;	// R	Flags when Rx sees "FC" code (sent by Tx) for latency measurement
			   gtx_rx_valid[idcfeb]			= (rd_data >>  6) & 0x1;	// R	Valid data detected on link
			   gtx_rx_match[idcfeb]			= (rd_data >>  7) & 0x1;	// R	PRBS test data match detected, for PRBS tests, a VALID = "should have a match" such that !MATCH is an error
			   gtx_rx_sync_done[idcfeb]		= (rd_data >>  8) & 0x1;	// R	Use these to determine gtx_ready
			   gtx_rx_pol_swap[idcfeb]			= (rd_data >>  9) & 0x1;	// R	GTX 5,6 [ie dcfeb 4,5] have swapped rx board routes
			   gtx_rx_err[idcfeb]				= (rd_data >> 10) & 0x1;	// R	PRBS test detects an error
		   }

		   printf("\tGTX Optical Receiver   GTX:6543210\n");
		   printf("\t[0] gtx_rx_enable        = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_enable[i]);        printf("\n");
		   printf("\t[1] gtx_rx_reset         = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_reset[i]);         printf("\n");
		   printf("\t[2] gtx_rx_reset_err_cnt = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_reset_err_cnt[i]); printf("\n");
		   printf("\t[3] gtx_rx_en_prbs_test  = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_en_prbs_test[i]);  printf("\n");
		   printf("\t[4] gtx_rx_start         = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_start[i]);         printf("\n");
		   printf("\t[5] gtx_rx_fc            = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_fc[i]);            printf("\n");
		   printf("\t[6] gtx_rx_valid         = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_valid[i]);         printf("\n");
		   printf("\t[7] gtx_rx_match         = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_match[i]);         printf("\n");
		   printf("\t[8] gtx_rx_sync_done     = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_sync_done[i]);     printf("\n");
		   printf("\t[9] gtx_rx_pol_swap      = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_pol_swap[i]);      printf("\n");
		   printf("\t[A] gtx_rx_err           = "); for(i=6;i>=0;--i) printf("%1i",gtx_rx_err[i]);           printf("\n");
		   printf("\n");

		   // Take snapshot of current counter state
		   adr = base_adr+cnt_ctrl_adr;
		   wr_data=0x0022;	//snap
		   status = vme_write(adr,wr_data);
		   wr_data=0x0020;	//unsnap
		   status = vme_write(adr,wr_data);

		   // Read counters
		   for (i=0; i<mxcounter; ++i) {
			   for (j=0; j<=1; ++j) {
				   adr = base_adr+cnt_ctrl_adr;
				   wr_data=(i << 9) | 0x0020 | (j << 8);
				   status = vme_write(adr,wr_data);
				   adr = base_adr+cnt_rdata_adr;
				   status = vme_read(adr,rd_data);

				   // Combine lsbs+msbs
				   if (j==0)			// Even addresses contain counter LSBs
					   cnt_lsb=rd_data;
				   else {				// Odd addresses contain counter MSBs
					   cnt_msb=rd_data;
					   cnt_full=cnt_lsb | (cnt_msb << 16);
					   cnt[i]=cnt_full;	// Assembled counter MSB,LSB
				   }
			   }}	//close j,i

		   // Dislay counters
		   printf("\tGTX Optical Receiver Error Counters\n");
		   for (i=79; i<=85; ++i) {
			   printf("\t%2.2i %10i %s\n",i,cnt[i],scnt[i].c_str());
		   }
		   printf("\n");

		   pause ("\tReturn to main menu <cr>");
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //
	   // Service routines for main
	   //
	   //------------------------------------------------------------------------------
	   //	Flip pattern ID numbers, because Im too lazy to flip the hs image
	   //------------------------------------------------------------------------------
	   int flip_pid(int pid)
	   {	
		   return (pid==0xA) ? 0xA : pid^0x1;	// invert pid lsb unless its pattern A
	   }

	   //------------------------------------------------------------------------------
	   //	Check data read vs data expected
	   //------------------------------------------------------------------------------
	   void ck(string msg_string, int data_read, int data_expect)
	   {	
		   if (data_read != data_expect) {
			   fprintf(stdout,  "ERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
			   fprintf(log_file,"ERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
			   //	pause(" ");
		   }
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Check data read vs data expected, with status return
	   //------------------------------------------------------------------------------
	   int cks(string msg_string, int data_read, int data_expect)
	   {
		   int status;

		   status = 0;	// good return
		   if (data_read != data_expect) {
			   status = 1;	// bad return
			   fprintf(stdout,  "\tERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
			   fprintf(log_file,"\tERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
			   //	pause(" ");
		   }

		   return status;
	   }
	   //------------------------------------------------------------------------------
	   //	Check data read vs data expected, floating point version  with tolerance
	   //------------------------------------------------------------------------------
	   void tok(string msg_string, double fdata_read, double fdata_expect, double tolerance, int &status)
	   {
		   double err;
		   double errpct;

		   err    = (fdata_read-fdata_expect)/__max(fdata_expect,.01);
		   errpct = err*100.;

		   status=0;
		   if (abs(err)>tolerance) {
			   status=1;
			   fprintf(stdout,  "\tERRm: in %s: read=%10.4g expect=%10.4g %10.2f\n",msg_string.c_str(),fdata_read,fdata_expect,errpct);
			   fprintf(log_file,"\tERRm: in %s: read=%10.4g expect=%10.4g %10.2f\n",msg_string.c_str(),fdata_read,fdata_expect,errpct);
		   }

		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Inquire prompt for integer
	   //------------------------------------------------------------------------------
	   void inquire(string prompt, const int &minv, const int &maxv, const int &radix, int &now)
	   {
		   char	line[80];
		   int		i;
		   int		n;

ask:
		   printf(prompt.c_str(),now);
		   gets(line);
		   n=strlen(line);
		   if (radix==16)	sscanf(line,"%x",&i);
		   else			sscanf(line,"%i",&i);

		   if ((n!=0) && ((i<minv) || (i>maxv))) {
			   if (radix==16) printf("Out of range. Expect %X to %X\n",minv,maxv);
			   else           printf("Out of range. Expect %i to %i\n",minv,maxv);
			   goto ask;
		   }
		   if (n!=0) now = i;
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Inquire prompt for two integers
	   //------------------------------------------------------------------------------
	   void inquir2(string prompt, const int &min, const int &max, const int &radix, int &num, int &now)
	   {
		   char	line[80];
		   int		i;
		   int		n;

ask:
		   printf(prompt.c_str(),num,now);
		   gets(line);
		   n=strlen(line);
		   if (radix==16)	sscanf(line,"%x",&i);
		   else			sscanf(line,"%i",&i);

		   if ((n!=0) && ((i<min) || (i>max))) {
			   if (radix==16) printf("Out of range. Expect %X to %X\n",min,max);
			   else           printf("Out of range. Expect %i to %i\n",min,max);
			   goto ask;
		   }
		   if (n!=0) now = i;
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Inquire prompt for long integer
	   //------------------------------------------------------------------------------
	   void inquirl(string prompt, const int &min, const int &max, const int &radix, long int &now)
	   {
		   char		line[80];
		   long int	i;
		   int			n;

ask:
		   printf(prompt.c_str(),now);
		   gets(line);
		   n=strlen(line);
		   if (radix==16)	sscanf(line,"%x",&i);
		   else			sscanf(line,"%i",&i);

		   if ((n!=0) && ((i<min) || (i>max))) {
			   if (radix==16) printf("Out of range. Expect %X to %X\n",min,max);
			   else           printf("Out of range. Expect %i to %i\n",min,max);
			   goto ask;
		   }
		   if (n!=0) now = i;
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Inquire prompt for bool
	   //------------------------------------------------------------------------------
	   void inquirb(string prompt, bool &now)
	   {
		   char	line[80];
		   char	i;
		   int		n;

ask:
		   printf(prompt.c_str(),yesno(now&0x1));
		   gets(line);
		   n=strlen(line);
		   sscanf(line,"%c",&i);

		   if (n!=0)
		   {
			   if (i!='y' && i!='Y' && i!='n' && i!='N') {printf("\tEnter y or n\n"); goto ask;} 
			   if (i=='y' || i=='Y') now = true;
			   if (i=='n' || i=='N') now = false;
		   }
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Pass Fail prompt
	   //------------------------------------------------------------------------------
	   bool pass_fail(string prompt)
	   {
		   char	line[80];
		   int		i;
		   int		n;
		   bool	ans;

ask:
		   printf(prompt.c_str());
		   gets(line);
		   n = strlen(line);
		   i = line[0];

		   if (n!=0 && (i=='p' || i=='P')) ans = true; 
		   else
			   if (n!=0 && (i=='f' || i=='F')) ans = false;
			   else {
				   printf("Enter P or F\n");
				   goto ask;
			   }
		   return ans;
	   }
	   //------------------------------------------------------------------------------
	   //	Display Test OK
	   //------------------------------------------------------------------------------
	   void aok(string msg_string)
	   {	
		   int		tab           = 45;
		   int		msg_spaces    = msg_string.length();
		   int		insert_spaces = tab-msg_spaces;
		   string	spaces        = " ";

		   for (int i=0; i<=insert_spaces; ++i) spaces.append(string(" "));

		   fprintf(log_file,"\t%s %s OK\n",msg_string.c_str(),spaces.c_str());	// log file
		   fprintf(stdout,  "\t%s %s OK\n",msg_string.c_str(),spaces.c_str());	// screen
		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Display Test OK or FAIL
	   //------------------------------------------------------------------------------
	   void aokf(string msg_string, const int itest, const int status)	
	   {
		   string	sstat[2]={"FAIL","PASS"};

		   int		tab           = 45;
		   int		msg_spaces    = msg_string.length();
		   int		insert_spaces = tab-msg_spaces;
		   string	spaces        = " ";

		   for (int i=0; i<=insert_spaces; ++i) spaces.append(string(" "));

		   fprintf(log_file,"\t%3i %s %s %s\n",itest,msg_string.c_str(),spaces.c_str(),sstat[status].c_str());	// log file
		   fprintf(stdout,  "\t%3i %s %s %s\n",itest,msg_string.c_str(),spaces.c_str(),sstat[status].c_str());	// screen

		   return;
	   }
	   //------------------------------------------------------------------------------
	   //	Convert integer bit string to an array
	   //------------------------------------------------------------------------------
	   void bit_to_array(const int &idata, int iarray[], const int &n) {
		   int i;

		   for (i=0; i<n; ++i) {
			   iarray[i]=(idata >> i) & 0x00000001;
		   }
		   return;
	   }
	   //--------------------------------------------------------------------------------
	   // Wait for specified number of milliseconds, probably MS Visual Studio specific
	   //--------------------------------------------------------------------------------
	   void sleep(clock_t msec)
	   {
		   clock_t goal;
		   goal = msec + clock();
		   while (goal > clock());
	   }

	   //------------------------------------------------------------------------------
	   // The bitter end
	   //------------------------------------------------------------------------------
