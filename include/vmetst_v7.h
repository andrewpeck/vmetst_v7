//------------------------------------------------------------------------------
#ifndef VMETST_V7_H
#define VMETST_V7_H
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include <string> 
#include "common.h"

//------------------------------------------------------------------------------
// Prototypes
//------------------------------------------------------------------------------
bool pass_fail    (std::string  prompt);
int  flip_pid     (int          pid);
void aok          (std::string  msg_string);
void aokf         (std::string  msg_string, const int itest, const int status);
void tok          (std::string  msg_string, double fdata_read, double fdata_expect, double tolerance, int &status);
void inquire      (std::string  prompt, const int &minv, const int &maxv, const int &radix, int &now);
void inquir2      (std::string  prompt, const int &minv, const int &maxv, const int &radix, int &num, int &now);
void inquirl      (std::string  prompt, const int &minv, const int &maxv, const int &radix, long int &now);
void inquirb      (std::string  prompt, bool &now);
void bit_to_array (const        int &idata, int iarray[], const int &n);

//extern
int xsvfExecute();

// Common/TMB_VME_addresses
#ifdef __linux__
const unsigned long    tmb_global_slot = 14;
#else
const unsigned long    tmb_global_slot = 26;
#endif
const unsigned long    tmb_brcst_slot  = 27;
const unsigned long    tmb_boot_adr    = 0x070000;
//------------------------------------------------------------------------------
const unsigned long vme_idreg_adr           = 0x000000; // For tmb2005 and bdtest_v5
const unsigned long vme_status_adr          = 0x000008;
const unsigned long vme_adr0_adr            = 0x00000A;
const unsigned long vme_adr1_adr            = 0x00000C;
const unsigned long vme_loopbk_adr          = 0x00000E;

const unsigned long vme_usr_jtag_adr        = 0x000010;
const unsigned long vme_prom_adr            = 0x000012;

const unsigned long vme_dddsm_adr           = 0x000014;
const unsigned long vme_ddd0_adr            = 0x000016;
const unsigned long vme_ddd1_adr            = 0x000018;
const unsigned long vme_ddd2_adr            = 0x00001A;
const unsigned long vme_dddoe_adr           = 0x00001C;
const unsigned long vme_ratctrl_adr         = 0x00001E;

const unsigned long vme_step_adr            = 0x000020;
const unsigned long vme_led_adr             = 0x000022;
const unsigned long vme_adc_adr             = 0x000024;
const unsigned long vme_dsn_adr             = 0x000026;
//------------------------------------------------------------------------------
const unsigned long mod_cfg_adr             = 0x000028; // For tmb2005 normal firmware
const unsigned long ccb_cfg_adr             = 0x00002A;
const unsigned long ccb_trig_adr            = 0x00002C;
const unsigned long ccb_stat0_adr           = 0x00002E;
const unsigned long alct_cfg_adr            = 0x000030;
const unsigned long alct_inj_adr            = 0x000032;
const unsigned long alct0_inj_adr           = 0x000034;
const unsigned long alct1_inj_adr           = 0x000036;
const unsigned long alct_stat_adr           = 0x000038;
const unsigned long alct_alct0_adr          = 0x00003A;
const unsigned long alct_alct1_adr          = 0x00003C;
const unsigned long alct_fifo_adr           = 0x00003E;
const unsigned long dmb_mon_adr             = 0x000040;
const unsigned long cfeb_inj_adr            = 0x000042;
const unsigned long cfeb_inj_adr_adr        = 0x000044;
const unsigned long cfeb_inj_wdata_adr      = 0x000046;
const unsigned long cfeb_inj_rdata_adr      = 0x000048;
const unsigned long hcm001_adr              = 0x00004A;
const unsigned long hcm023_adr              = 0x00004C;
const unsigned long hcm045_adr              = 0x00004E;
const unsigned long hcm101_adr              = 0x000050;
const unsigned long hcm123_adr              = 0x000052;
const unsigned long hcm145_adr              = 0x000054;
const unsigned long hcm201_adr              = 0x000056;
const unsigned long hcm223_adr              = 0x000058;
const unsigned long hcm245_adr              = 0x00005A;
const unsigned long hcm301_adr              = 0x00005C;
const unsigned long hcm323_adr              = 0x00005E;
const unsigned long hcm345_adr              = 0x000060;
const unsigned long hcm401_adr              = 0x000062;
const unsigned long hcm423_adr              = 0x000064;
const unsigned long hcm445_adr              = 0x000066;
const unsigned long seq_trig_en_adr         = 0x000068;
const unsigned long seq_trig_dly0_adr       = 0x00006A;
const unsigned long seq_trig_dly1_adr       = 0x00006C;
const unsigned long seq_id_adr              = 0x00006E;
const unsigned long seq_clct_adr            = 0x000070;
const unsigned long seq_fifo_adr            = 0x000072;
const unsigned long seq_l1a_adr             = 0x000074;
const unsigned long seq_offset0_adr         = 0x000076;
const unsigned long seq_clct0_adr           = 0x000078;
const unsigned long seq_clct1_adr           = 0x00007A;
const unsigned long seq_trig_src_adr        = 0x00007C;
const unsigned long dmb_ram_adr             = 0x00007E;
const unsigned long dmb_wdata_adr           = 0x000080;
const unsigned long dmb_wdcnt_adr           = 0x000082;
const unsigned long dmb_rdata_adr           = 0x000084;
const unsigned long tmb_trig_adr            = 0x000086;
const unsigned long mpc0_frame0_adr         = 0x000088;
const unsigned long mpc0_frame1_adr         = 0x00008A;
const unsigned long mpc1_frame0_adr         = 0x00008C;
const unsigned long mpc1_frame1_adr         = 0x00008E;
const unsigned long mpc_inj_adr             = 0x000090;
const unsigned long mpc_ram_adr             = 0x000092;
const unsigned long mpc_ram_wdata_adr       = 0x000094;
const unsigned long mpc_ram_rdata_adr       = 0x000096;
const unsigned long ccb_cmd_adr             = 0x00009C;

const unsigned long buf_stat0_adr           = 0x00009E;
const unsigned long buf_stat1_adr           = 0x0000A0;
const unsigned long buf_stat2_adr           = 0x0000A2;
const unsigned long buf_stat3_adr           = 0x0000A4;
const unsigned long buf_stat4_adr           = 0x0000A6;
const unsigned long alctfifo1_adr           = 0x0000A8;
const unsigned long alctfifo2_adr           = 0x0000AA;
const unsigned long seqmod_adr              = 0x0000AC;
const unsigned long seqsm_adr               = 0x0000AE;
const unsigned long seq_clctm_adr           = 0x0000B0;
const unsigned long tmbtim_adr              = 0x0000B2;
const unsigned long lhc_cycle_adr           = 0x0000B4;
const unsigned long rpc_cfg_adr             = 0x0000B6;
const unsigned long rpc_rdata_adr           = 0x0000B8;
const unsigned long rpc_raw_delay_adr       = 0x0000BA;
const unsigned long rpc_inj_adr             = 0x0000BC;
const unsigned long rpc_inj_adr_adr         = 0x0000BE;
const unsigned long rpc_inj_wdata_adr       = 0x0000C0;
const unsigned long rpc_inj_rdata_adr       = 0x0000C2;
const unsigned long rpc_tbins_adr           = 0x0000C4;
const unsigned long rpc_rpc0_hcm_adr        = 0x0000C6;
const unsigned long rpc_rpc1_hcm_adr        = 0x0000C8;
const unsigned long bx0_delay_adr           = 0x0000CA;
const unsigned long non_trig_adr            = 0x0000CC;
const unsigned long scp_trig_adr            = 0x0000CE;
const unsigned long cnt_ctrl_adr            = 0x0000D0;
const unsigned long cnt_rdata_adr           = 0x0000D2;

const unsigned long jtagsm0_adr             = 0x0000D4;
const unsigned long jtagsm1_adr             = 0x0000D6;
const unsigned long jtagsm2_adr             = 0x0000D8;

const unsigned long vmesm0_adr              = 0x0000DA;
const unsigned long vmesm1_adr              = 0x0000DC;
const unsigned long vmesm2_adr              = 0x0000DE;
const unsigned long vmesm3_adr              = 0x0000E0;
const unsigned long vmesm4_adr              = 0x0000E2;

const unsigned long dddrsm_adr              = 0x0000E4;
const unsigned long dddr0_adr               = 0x0000E6;

const unsigned long uptimer_adr             = 0x0000E8;
const unsigned long bdstatus_adr            = 0x0000EA;

const unsigned long bxn_clct_adr            = 0x0000EC;
const unsigned long bxn_alct_adr            = 0x0000EE;

const unsigned long layer_trig_adr          = 0x0000F0;
const unsigned long ise_version_adr         = 0x0000F2;

const unsigned long temp0_adr               = 0x0000F4;
const unsigned long temp1_adr               = 0x0000F6;
const unsigned long temp2_adr               = 0x0000F8;

const unsigned long parity_adr              = 0x0000FA;
const unsigned long ccb_stat1_adr           = 0x0000FC;
const unsigned long bxn_l1a_adr             = 0x0000FE;
const unsigned long l1a_lookback_adr        = 0x000100;
const unsigned long seq_debug_adr           = 0x000102;

const unsigned long alct_sync_ctrl_adr      = 0x000104; // ALCT sync mode control
const unsigned long alct_sync_txdata_1st    = 0x000106; // ALCT sync mode transmit data, 1st in time
const unsigned long alct_sync_txdata_2nd    = 0x000108; // ALCT sync mode transmit data, 2nd in time

const unsigned long seq_offset1_adr         = 0x00010A;
const unsigned long miniscope_adr           = 0x00010C;

const unsigned long phaser0_adr             = 0x00010E;
const unsigned long phaser1_adr             = 0x000110;
const unsigned long phaser2_adr             = 0x000112;
const unsigned long phaser3_adr             = 0x000114;
const unsigned long phaser4_adr             = 0x000116;
const unsigned long phaser5_adr             = 0x000118;
const unsigned long phaser6_adr             = 0x00011A;

const unsigned long delay0_int_adr          = 0x00011C;
const unsigned long delay1_int_adr          = 0x00011E;

const unsigned long sync_err_ctrl_adr       = 0x000120; // Synchronization Error Control

const unsigned long cfeb_badbits_ctrl_adr   = 0x000122; // CFEB  Bad Bit Control/Status
const unsigned long cfeb_badbits_timer_adr  = 0x000124; // CFEB  Bad Bit Check Interval

const unsigned long cfeb0_badbits_ly01_adr  = 0x000126; // CFEB0 Bad Bit Array
const unsigned long cfeb0_badbits_ly23_adr  = 0x000128; // CFEB0 Bad Bit Array
const unsigned long cfeb0_badbits_ly45_adr  = 0x00012A; // CFEB0 Bad Bit Array

const unsigned long cfeb1_badbits_ly01_adr  = 0x00012C; // CFEB1 Bad Bit Array
const unsigned long cfeb1_badbits_ly23_adr  = 0x00012E; // CFEB1 Bad Bit Array
const unsigned long cfeb1_badbits_ly45_adr  = 0x000130; // CFEB1 Bad Bit Array

const unsigned long cfeb2_badbits_ly01_adr  = 0x000132; // CFEB2 Bad Bit Array
const unsigned long cfeb2_badbits_ly23_adr  = 0x000134; // CFEB2 Bad Bit Array
const unsigned long cfeb2_badbits_ly45_adr  = 0x000136; // CFEB2 Bad Bit Array

const unsigned long cfeb3_badbits_ly01_adr  = 0x000138; // CFEB3 Bad Bit Array
const unsigned long cfeb3_badbits_ly23_adr  = 0x00013A; // CFEB3 Bad Bit Array
const unsigned long cfeb3_badbits_ly45_adr  = 0x00013C; // CFEB3 Bad Bit Array

const unsigned long cfeb4_badbits_ly01_adr  = 0x00013E; // CFEB4 Bad Bit Array
const unsigned long cfeb4_badbits_ly23_adr  = 0x000140; // CFEB4 Bad Bit Array
const unsigned long cfeb4_badbits_ly45_adr  = 0x000142; // CFEB4 Bad Bit Array


const unsigned long adr_alct_startup_delay  = 0x000144; // ALCT startup delay milliseconds for Spartan-6
const unsigned long adr_alct_startup_status = 0x000146; // ALCT startup delay machine status

const unsigned long adr_virtex6_snap12_qpll = 0x000148; // Virtex-6 SNAP12 Serial interface + QPLL
const unsigned long adr_virtex6_gtx_rx_all  = 0x00014A; // Virtex-6 GTX  common control
const unsigned long adr_virtex6_gtx_rx0     = 0x00014C; // Virtex-6 GTX0 control and status
const unsigned long adr_virtex6_gtx_rx1     = 0x00014E; // Virtex-6 GTX1 control and status
const unsigned long adr_virtex6_gtx_rx2     = 0x000150; // Virtex-6 GTX2 control and status
const unsigned long adr_virtex6_gtx_rx3     = 0x000152; // Virtex-6 GTX3 control and status
const unsigned long adr_virtex6_gtx_rx4     = 0x000154; // Virtex-6 GTX4 control and status
const unsigned long adr_virtex6_gtx_rx5     = 0x000156; // Virtex-6 GTX5 control and status
const unsigned long adr_virtex6_gtx_rx6     = 0x000158; // Virtex-6 GTX6 control and status
const unsigned long adr_virtex6_sysmon      = 0x00015A; // Virtex-6 Sysmon ADC

const unsigned long last_vme_adr            = 0x00015C; // Last valid address instantiated
//------------------------------------------------------------------------------
const unsigned long vme_gpio_adr            = 0x000028; // For bdtestv3
const unsigned long vme_cfg_adr             = 0x00002A;

const unsigned long cfeb0a_adr              = 0x00002C; // Repeats 2C-48 for CFEBs1-4
const unsigned long cfeb0b_adr              = 0x00002E;
const unsigned long cfeb0c_adr              = 0x000030;
const unsigned long cfeb_offset_adr         = 0x000006;

const unsigned long alct_rxa_adr            = 0x00004A;
const unsigned long alct_rxb_adr            = 0x00004C;
const unsigned long alct_rxc_adr            = 0x00004E;
const unsigned long alct_rxd_adr            = 0x000050;

const unsigned long dmb_rxa_adr             = 0x000052;
const unsigned long dmb_rxb_adr             = 0x000054;
const unsigned long dmb_rxc_adr             = 0x000056;
const unsigned long dmb_rxd_adr             = 0x000058;

const unsigned long mpc_rxa_adr             = 0x00005A;
const unsigned long mpc_rxb_adr             = 0x00005C;

const unsigned long rpc_rxa_adr             = 0x00005E;
const unsigned long rpc_rxb_adr             = 0x000060;
const unsigned long rpc_rxc_adr             = 0x000062;
const unsigned long rpc_rxd_adr             = 0x000064;
const unsigned long rpc_rxe_adr             = 0x000066;
const unsigned long rpc_rxf_adr             = 0x000068;

const unsigned long ccb_rxa_adr             = 0x00006A;
const unsigned long ccb_rxb_adr             = 0x00006C;
const unsigned long ccb_rxc_adr             = 0x00006E;
const unsigned long ccb_rxd_adr             = 0x000070;

const unsigned long alct_txa_adr            = 0x000072;
const unsigned long alct_txb_adr            = 0x000074;

const unsigned long rpc_txa_adr             = 0x000076;
const unsigned long rpc_txb_adr             = 0x000078;

const unsigned long dmb_txa_adr             = 0x00007A;
const unsigned long dmb_txb_adr             = 0x00007C;
const unsigned long dmb_txc_adr             = 0x00007E;
const unsigned long dmb_txd_adr             = 0x000080;

const unsigned long mpc_txa_adr             = 0x000082;
const unsigned long mpc_txb_adr             = 0x000084;

const unsigned long ccb_txa_adr             = 0x000086;
const unsigned long ccb_txb_adr             = 0x000088;

const unsigned long heater_adr              = 0x00008A; // Last bdtestv3 address instantiated



//------------------------------------------------------------------------------
// File scope declarations
//------------------------------------------------------------------------------

// JTAG stream
char            tdi[mxbitstream]={0};
char            tdo[mxbitstream]={0};

// VME calls
long            status;
unsigned long   boot_adr;
unsigned long   adr;
unsigned short  rd_data;
unsigned short  wr_data;

//------------------------------------------------------------------------------
// Event counters
//------------------------------------------------------------------------------
const int       mxcounter = 86;
int             cnt_lsb;
int             cnt_msb;
int             cnt_full;
int             cnt[mxcounter];
std::string     scnt[mxcounter];

//------------------------------------------------------------------------------
// Local
//------------------------------------------------------------------------------
int             islot;
int             islot_old;
int             newslot;
int             geo_adr;

// ID reg
int             id_rev;
int             id_rev_day;
int             id_rev_month;
int             id_rev_year;
int             id_rev_fpga;

int             id_slot;
int             id_ver;
int             id_type;
int             id_month;
int             id_day;
int             id_year;

int             id_reg[4];
int             id_reg_save[4];

bool            biv;
bool            civ;

// Spartan-6 JTAG registers
bool            s6_stat_en;

const int       SPARTAN6_STAT    = 0x08;    // 16 bits
const int       SPARTAN6_BOOTSTS = 0x20;    // 16 bits
const int       SPARTAN6_SEU_OPT = 0x1D;    // 16 bits

long            s6_stat;
long            s6_bootsts;
long            s6_seu_opt;

int             s6_SWWD_strikeout;
int             s6_IN_PWRDN;
int             s6_DONE;
int             s6_INIT_B;
int             s6_MODE;
int             s6_HSWAPEN;
int             s6_PART_SECURED;
int             s6_DEC_ERROR;
int             s6_GHIGH_B;
int             s6_GWE;
int             s6_GTS_CFG_B;
int             s6_DCM_LOCK;
int             s6_ID_ERROR;
int             s6_CRC_ERROR;

int             s6_STRIKE_CNT;
int             s6_CRC_ERROR_1;
int             s6_ID_ERROR_1;
int             s6_WTO_ERROR_1;
int             s6_RESERVED_8;
int             s6_FALLBACK_1;
int             s6_VALID_1;
int             s6_CRC_ERROR_0;
int             s6_ID_ERROR_0;
int             s6_WTO_ERROR_0;
int             s6_RESERVED;
int             s6_FALLBACK_0;
int             s6_VALID_0;

int             s6_RESERVED_15;
int             s6_RESERVED_14;
int             s6_SEU_FREQ;
int             s6_SEU_RUN_ON_ERR;
int             s6_GLUT_MASK;
int             s6_SEU_ENABLE;

// Firmware
unsigned short  firmware_type;
unsigned short  firmware_series;
unsigned short  firmware_normal         =0xC;
unsigned short  firmware_debug          =0xD;
unsigned short  firmware_series_etype   =0xE;

unsigned short  ise_version;
unsigned short  ise_sub;
unsigned short  ise_sp;

char            timestr[9];
char            datestr[9];

std::string         tmb_type;
std::string         fpga_series;
std::string         firmware_name;
std::string         scomputer_name;

// CSC type
int             csc_me1ab;
int             stagger_hs_csc;
int             reverse_hs_csc;
int             reverse_hs_me1a;
int             reverse_hs_me1b;
int             csc_type;
std::string         flags_ok;

// Menu
char            line[80];
int             ifunc;
int             i,j,k,n;

// Peek/poke
char            rwe;
unsigned long   newadr;
unsigned long   newdata;

int             nbang;
int             ibang;
bool            bang_read  = false;
bool            bang_write = false;

// Parity
int             perr_cfeb;
int             perr_rpc;
int             perr_mini;
int             perr_en;
int             perr;

int             perr_cfeb_ff;
int             perr_rpc_ff;
int             perr_mini_ff;
int             perr_reset_vme;
int             perr_free;
int             perr_ff;

int             perr_adr;
int             perr_mux;
int             perr_ram_cfeb0[6];
int             perr_ram_cfeb1[6];
int             perr_ram_cfeb2[6];
int             perr_ram_cfeb3[6];
int             perr_ram_cfeb4[6];
int             perr_ram_rpc[5];
int             perr_ram_mini[2];

// CCB
int             ttc_cmd;
int             ccb_cmd;
int             ccb_clock40_enable;
int             ccb_ttcrx_ready;
int             ccb_qpll_locked;
int             ccb_reserved;
int             ccb_bcntres;
int             ccb_bx0;

int             ccb_ttcrx_lock_never;
int             ccb_ttcrx_lost_ever;
int             ccb_qpll_lock_never;
int             ccb_qpll_lost_ever;

// DDD
int             ddd_read[16]={0};
int             ddd_enable[16];
int             ddd_delay;
int             ddd_chip;
int             ddd_channel;
int             ddd_busy;
int             ddd_verify_ok;
int             ddd0_delay;
int             ddd_error;
int             dddr_error;
int             dddr_busy;
int             dddr_verify_ok;
int             dddr_linktmb;

int             autostart;
int             ich;
char            cch;
double          rnd;

std::string         ddd_name[16]={
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

std::string         ddd_name_rat[4]={
    "RPC0  rx clock",
    "RPC1  rx clock",
    "Not used      ",
    "Not used      "};

std::string         ddd_tp[3][4]={
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
bool            debug_loop;
bool            debug_step;
bool            debug_beep;

// Trigger tests
int             dmb_thresh_pretrig;
int             hit_thresh_pretrig;
int             hit_thresh_postdrift;
int             pid_thresh_pretrig;
int             pid_thresh_postdrift;
int             lyr_thresh_pretrig;

int             triad_persist;
int             drift_delay;
int             clct_sep;
int             active_feb_src;
int             active_feb_list;

bool            layer_mode;
int             layer_trig_en;

int             fifo_mode;
int             fifo_tbins;
int             fifo_pretrig;

int             fifo_tbins_rpc;
int             fifo_pretrig_rpc;
int             rpc_decouple;

int             alct_bx0_en;
int             alct_delay;
int             clct_width;

int             tmb_allow_clct;
int             tmb_allow_alct;
int             tmb_allow_match;

int             tmb_allow_alct_ro;
int             tmb_allow_clct_ro;
int             tmb_allow_match_ro;

int             inj_delay_rat;
int             rpc_tbins_test;
int             rpc_exists;

bool            rrhd;
bool            cprr;
bool            cprr_ignore;
bool            rat_injector_sync=false;
bool            rat_injector_enable=true;
bool            rpcs_in_rdout;
bool            pause_on_fail;
int             vme_bx0_emu_en_default=1;

int             nclcts_inject=1;
int             nalcts_inject=1;
int             mcl;

const int       mxclcts=8;
int             clct_pat_inject[mxclcts];
int             clct_pid_inject[mxclcts];
int             clct_key_inject[mxclcts];
int             clct_hit_inject[mxclcts];
bool            clct_blanked[mxclcts];
int             clct_hit_inject_clip[mxclcts];
bool            loop_keys[mxclcts];
bool            loop_pids[mxclcts];
int             iclct;

int             triad_1st_tbin[6]={0,0,0,0,0,0};
int             l1a_delay=119;  // hits 0th l1a window bx
int             rat_sync_mode;
int             rat_injector_delay;

int             irpc;
int             ibxn;

int             rpc_pad;
int             rpc_inj_bxn;
int             rpc_inj_image[256][2];
int             rpc_inj_wen;
int             rpc_inj_ren;
int             rpc_inj_rwadr;
int             rpc_inj_data;

// Scope
bool            rdscope;
int             scp_arm;
int             scp_readout;
int             scp_raw_decode;
int             scp_silent;
int             scp_raw_data[512*160/16];
int             scp_auto;
int             scp_nowrite;

// Misc
int             boot_decode[16];
unsigned short  boot_data;
int             boot;
long            mez_trig_reg;
int             ipass;

// Pattern cells
int             icell;
int             ihit;
int             ihitp;

int             nhits;
int             layer;

int             ikey;
int             ikeylp;
int             ikey_min;
int             ikey_max;
int             ikey_sep;

int             ipid;
int             ipidlp;
int             ipid_min;
int             ipid_max;

int             icfeb;
int             icfebg;
int             key;
int             ihs[6][160];
int             nstag;

int             idistrip;
int             idslocal;
int             itbin;
int             itbin0;
int             ihstrip;
int             iram;
int             pat_ram[32][3][5]={0};
int             wen;
int             ren;
int             wadr;
int             febsel;
int             icfeblp;
int             ibit;
int             wr_data_mem;
int             rd_data_mem;

std::string         marker="AOXOMOXOA";
//------------------------------------------------------------------------------
//  CLCT Bend Pattern Images, key layer 2
//------------------------------------------------------------------------------
int pattern_image[11][6][11]// pid,layer,cell
={
    //      0 1 2 3 4 5 6 7 8 9 A
    0,0,0,0,0,0,0,0,0,0,0,  // ly0 Pattern 0, empty
    0,0,0,0,0,0,0,0,0,0,0,  // ly1
    0,0,0,0,0,0,0,0,0,0,0,  // ly2
    0,0,0,0,0,0,0,0,0,0,0,  // ly3
    0,0,0,0,0,0,0,0,0,0,0,  // ly4
    0,0,0,0,0,0,0,0,0,0,0,  // ly5

    0,0,0,0,0,0,0,0,0,0,0,  // ly0 Pattern 1, empty
    0,0,0,0,0,0,0,0,0,0,0,  // ly1
    0,0,0,0,0,0,0,0,0,0,0,  // ly2
    0,0,0,0,0,0,0,0,0,0,0,  // ly3
    0,0,0,0,0,0,0,0,0,0,0,  // ly4
    0,0,0,0,0,0,0,0,0,0,0,  // ly5

    0,0,0,0,0,0,0,0,2,2,1,  // ly0 Pattern 2, 0=no hit, 1=primary hit, 2=secondary hit
    0,0,0,0,0,0,2,1,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,1,2,2,0,0,0,0,0,  // ly3
    0,1,2,2,0,0,0,0,0,0,0,  // ly4
    1,2,2,0,0,0,0,0,0,0,0,  // ly5

    1,2,2,0,0,0,0,0,0,0,0,  // ly0 Pattern 3
    0,0,0,1,2,0,0,0,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,0,0,2,2,1,0,0,0,  // ly3
    0,0,0,0,0,0,0,2,2,1,0,  // ly4
    0,0,0,0,0,0,0,0,2,2,1,  // ly5

    0,0,0,0,0,0,0,2,2,1,0,  // ly0 Pattern 4
    0,0,0,0,0,0,2,1,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,1,2,0,0,0,0,0,0,  // ly3
    0,1,2,2,0,0,0,0,0,0,0,  // ly4
    0,1,2,2,0,0,0,0,0,0,0,  // ly5

    0,1,2,2,0,0,0,0,0,0,0,  // ly0 Pattern 5
    0,0,0,1,2,0,0,0,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,0,0,0,2,1,0,0,0,  // ly3
    0,0,0,0,0,0,0,2,2,1,0,  // ly4
    0,0,0,0,0,0,0,2,2,1,0,  // ly5

    0,0,0,0,0,0,2,2,1,0,0,  // ly0 Pattern 6
    0,0,0,0,0,2,1,0,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,0,1,2,0,0,0,0,0,  // ly3
    0,0,0,1,2,0,0,0,0,0,0,  // ly4
    0,0,1,2,2,0,0,0,0,0,0,  // ly5

    0,0,1,2,2,0,0,0,0,0,0,  // ly0 Pattern 7
    0,0,0,0,1,2,0,0,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,0,0,2,1,0,0,0,0,  // ly3
    0,0,0,0,0,0,2,1,0,0,0,  // ly4
    0,0,0,0,0,0,2,2,1,0,0,  // ly5

    0,0,0,0,0,2,2,1,0,0,0,  // ly0 Pattern 8
    0,0,0,0,0,2,1,0,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,0,1,2,0,0,0,0,0,  // ly3
    0,0,0,1,2,2,0,0,0,0,0,  // ly4
    0,0,0,1,2,2,0,0,0,0,0,  // ly5

    0,0,0,1,2,2,0,0,0,0,0,  // ly0 Pattern 9
    0,0,0,0,1,2,0,0,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,0,0,2,1,0,0,0,0,  // ly3
    0,0,0,0,0,2,2,1,0,0,0,  // ly4
    0,0,0,0,0,2,2,1,0,0,0,  // ly5

    0,0,0,0,2,1,2,0,0,0,0,  // ly0 Pattern A
    0,0,0,0,0,1,0,0,0,0,0,  // ly1
    0,0,0,0,0,1,0,0,0,0,0,  // ly2
    0,0,0,0,0,1,0,0,0,0,0,  // ly3
    0,0,0,0,2,1,2,0,0,0,0,  // ly4
    0,0,0,0,2,1,2,0,0,0,0   // ly5
};

//------------------------------------------------------------------------------
int             alct_data;
int             alct_tdo;
int             alct_lsbs;
int             alct_expect;
int             alct_err;
int             alct_id;
int             alct_board_id;
int             mez_board_id;
char            calct_board_id[3+1];
char            cmez_board_id[4+1];
std::string         salct_board_id;
std::string         smez_board_id;
int             alct_id_expect;
int             ireg;
int             alct_injector_delay=14; // experimental


//alct
bool            sc_version_new;
bool            sc_version_old;
int             alct_npass=0;
int             alct_nfail=0;
int             alct_nskip=0;

int             idac_table;
const int       ndac_table=25;
int             dac_table[ndac_table]={0,1,2,3,4,5,6,7,8,12,15,16,24,31,32,48,63,64,96,127,128,160,192,224,255};

std::string         spass_fail[2]={"PASS","FAIL <=="};
std::string         spaces[20]=
{
    "",                     // 0
    " ",                    // 1
    "  ",                   // 2
    "   ",                  // 3
    "    ",                 // 4
    "     ",                // 5
    "      ",               // 6
    "       ",              // 7
    "        ",             // 8
    "         ",            // 9
    "          ",           // 10
    "           ",          // 11
    "            ",         // 12
    "             ",        // 13
    "              ",       // 14
    "               ",      // 15
    "                ",     // 16
    "                 ",    // 17
    "                  ",   // 18
    "                   "   // 19
};

//rat 
std::string         rat_chip_type[2]={"FPGA","PROM"};
long int        rat_user1[7];
long int        rat_user2[1];
int             rat_ctrl_data;

// RAT USER1 status register
char            rs[224];
long int        rs_begin;
long int        rs_version;
long int        rs_monthday;
long int        rs_year;

long int        rs_syncmode;
long int        rs_posneg;
long int        rs_loop;

long int        rs_rpc_en;
long int        rs_clk_active;

long int        rs_locked_tmb;
long int        rs_locked_rpc0;
long int        rs_locked_rpc1;
long int        rs_locklost_tmb;
long int        rs_locklost_rpc0;
long int        rs_locklost_rpc1;

long int        rs_txok;
long int        rs_rxok;

long int        rs_ntcrit;
long int        rs_rpc_free;

long int        rs_dsn;
long int        rs_dddoe_wr;
long int        rs_ddd_wr;
long int        rs_ddd_auto;
long int        rs_ddd_start;
long int        rs_ddd_busy;
long int        rs_ddd_verify_ok;

long int        rs_rpc0_parity_ok;
long int        rs_rpc1_parity_ok;
long int        rs_rpc0_cnt_perr;
long int        rs_rpc1_cnt_perr;
long int        rs_last_opcode;

long int        rw_rpc_en;
long int        rw_ddd_start;
long int        rw_ddd_wr;
long int        rw_dddoe_wr;
long int        rw_perr_reset;
long int        rw_parity_odd;
long int        rw_perr_ignore;
long int        rw_rpc_future;

long int        rs_rpc0_pdata;
long int        rs_rpc1_pdata;

long int        rs_unused;
long int        rs_end;

// RAT USER2 control register
char            wso[32];
long int        ws_rpc_en;
long int        ws_ddd_start;
long int        ws_ddd_wr;
long int        ws_dddoe_wr;
long int        ws_perr_reset;
long int        ws_parity_odd;
long int        ws_perr_ignore;
long int        ws_rpc_future;

// Backplane status register
char            bs[192];

long int        back_user1[6];
long int        bs_begin;
long int        bs_version;
long int        bs_monthday;
long int        bs_year;
long int        bs_endD;
long int        bs_endE;

int             p2a_gnd_c[25+1];
int             p2b_gnd_c[11+1];
int             p2b_vtt_c[10+1];
int             p3a_gnd_c[25+1];
int             p3a_gnd_f[25+1];
int             p3a_vcc_a[24+1];
int             p3b_gnd_c[25+1];
int             p3b_gnd_f[25+1];
int             p3b_vcc_a[25+1];

int             p2a_gnd_c_ok;
int             p2b_gnd_c_ok;
int             p2b_vtt_c_ok;
int             p3a_gnd_c_ok;
int             p3a_gnd_f_ok;
int             p3a_vcc_a_ok;
int             p3b_gnd_c_ok;
int             p3b_gnd_f_ok;
int             p3b_vcc_a_ok;

int             p2a_ok;
int             p2b_ok;
int             p3a_ok;
int             p3b_ok;

int             all_ok;
int             bs_free;

bool            markers_ok;
int             ibplsync;

int             p2a_gnd_c_bad;
int             p2b_gnd_c_bad;
int             p2b_vtt_c_bad;
int             p3a_gnd_c_bad;
int             p3a_gnd_f_bad;
int             p3a_vcc_a_bad;
int             p3b_gnd_c_bad;
int             p3b_gnd_f_bad;
int             p3b_vcc_a_bad;

// ALCT jtag opcodes
int             IDRead;
int             HCMaskRead;
int             HCMaskWrite;
int             RdTrig;
int             WrTrig;
int             RdCfg;
int             WrCfg;
int             Wdly;
int             Rdly;
int             CollMaskRead;
int             CollMaskWrite;
int             ParamRegRead;
int             ParamRegWrite;
int             InputEnable;
int             InputDisable;
int             YRwrite;
int             OSread;
int             SNread;
int             SNwrite0;
int             SNwrite1;
int             SNreset;
int             Bypass;

std::string         alct_chip_type[3]={"FPGA","PROM","PROM"};
std::string         tmb_chip_type[5] ={"FPGA","PROM","PROM","PROM","PROM"};
long int        alct_cfgreg[3];
long int        alct_idreg[2];
char            rsa[69];
int             alct_sn[2];
int             alct_dsn_crc;
int             alct_dsn_mfg;
int             alct_dsn;
int             ilen;
int             ival;
int             ivalarray[69];

int             alct0_rd;
int             alct1_rd;
int             alct0_prev;
int             alct1_prev;

long int        din;
long int        crc;
long int        tmb_crc_lsb;
long int        tmb_crc_msb;
long int        tmb_crc;
bool            crc_match;

long int        rsa_trig_mode;
long int        rsa_ext_trig_en;
long int        rsa_pretrig_halt;
long int        rsa_inject;
long int        rsa_inject_mode;
long int        rsa_inject_mask;
long int        rsa_nph_thresh;
long int        rsa_nph_pattern;
long int        rsa_drift_delay;
long int        rsa_fifo_tbins;
long int        rsa_fifo_pretrig;
long int        rsa_fifo_mode;
long int        rsa_fifo_lastlct;
long int        rsa_l1a_delay;
long int        rsa_l1a_window;
long int        rsa_l1a_offset;
long int        rsa_l1a_internal;
long int        rsa_board_id;
long int        rsa_bxn_offset;
long int        rsa_ccb_enable;
long int        rsa_alct_jtag_ds;
long int        rsa_alct_tmode;
long int        rsa_alct_amode;
long int        rsa_alct_maskall;
long int        rsa_trig_info_en;
long int        rsa_sn_select;

long int        rsa_chip_id;
long int        rsa_version;
long int        rsa_year;
long int        rsa_day;
long int        rsa_month;

long int        rsa_ver;
long int        rsa_wgn;
long int        rsa_bf;
long int        rsa_np;
long int        rsa_mr;
long int        rsa_ke;
long int        rsa_rl;
long int        rsa_pb;
long int        rsa_sp6;
long int        rsa_seu;
long int        rsa_res1;

char            rsd[84];
long int        alct_user1[3];
long int        alct_user2[2];
long int        rsd_begin;
long int        rsd_version;
long int        rsd_monthday;
long int        rsd_year;
long int        rsd_mc_done;
long int        rsd_sc_done;
long int        rsd_clock_lock;
long int        rsd_clock_en;
long int        rsd_cmd_align;
long int        rsd_cmd_sync_mode;
long int        rsd_sync_mode;
long int        rsd_sync_rx_1st_ok;
long int        rsd_sync_rx_2nd_ok;
long int        rsd_alct_rx_1st;
long int        rsd_alct_rx_2nd;
long int        rsd_cmd_l1a_en;
long int        rsd_cmd_trig_en;
long int        rsd_tx_en0;
long int        rsd_tx_en1;
long int        rsd_cmd_dummy;
long int        rsd_free0;
long int        rsd_end;

int             err_alct_fifo_clr;
int             err_alct_lct0;
int             err_alct_lct1;
int             err_alct_fifo_busy;
int             err_alct_fifo_ndone;
int             err_alct_raw_nwords;
int             err_firmware_crc;
int             err_alct_crc;
int             err_lct;
int             err_sum;
int             err_lct_cmp;
int             alct0_keya;
int             alct1_keya;
int             alct0_keyb;
int             alct1_keyb;
int             ievent;
int             itrig_src;

int             rpc_data[38];
int             rpc_data_1st[38];
int             rpc_data_2nd[38];
int             rpc_delay_default;
int             bad_1st;
int             bad_2nd;
int             rpc_bad[16];
int             nbad;
double          pctbad;
int             npasses;
bool            rpc_err;
int             loopbk;
int             itx;
int             ijtag_src;

int             rpc_rx[4];
int             rpc_bxn[4];
int             rpc_word[4];

int             rpc_rbxn[4];
int             rpc_rdata[4];
int             rpc0_rdata_expect[19];
int             rpc1_rdata_expect[19];
int             rpc2_rdata_expect[19];
int             rpc3_rdata_expect[19];
int             irat;

bool            dmb_err;
int             mpc_err;
int             ccb_data[64];
int             ccb_err;
int             reg_err;
int             vme_cfg;
int             vme_data;
int             irx;

std::string         vstat_5p0v;
std::string         vstat_3p3v;
std::string         vstat_1p8v;
std::string         vstat_1p5v;
std::string         tcrit;
std::string         ok[2]={"BAD","OK "};
std::string         sidcode_good;
std::string         rat_user1_string;

long int        i4;
int             adr_mode;
int             loopstate;

int             sel_boot_jtag;
int             sel_boot_nojtag;
int             sel_step_alct;
int             sel_step_cfeb;
int             sel_loopbk;

unsigned long   adc_adr;
int             smb_adr;
int             smb_cmd;
int             smb_data;
int             smb_data_tmb;
int             smb_data_rat;

double          t_local_c_tmb;
double          t_local_f_tmb;
double          t_remote_c_tmb;
double          t_remote_f_tmb; 
double          tcrit_local_c_tmb;
double          tcrit_local_f_tmb;
double          tcrit_remote_c_tmb;
double          tcrit_remote_f_tmb;

double          t_local_c_rat;
double          t_local_f_rat;
double          t_remote_c_rat;
double          t_remote_f_rat; 
double          tcrit_local_c_rat;
double          tcrit_local_f_rat;
double          tcrit_remote_c_rat;
double          tcrit_remote_f_rat;

int             opcode;
int             reg_len;
int             chip_id;
int             nchips;
long int        idcode;
long int        usercode;
int             user_idcode[2];
int             ichain;
int             idcode_v;
int             idcode_f;
int             idcode_a;
int             idcode_c;

std::string         sdevice_type;
std::string         sdevice_name;
std::string         sdevice_version;
std::string         sdevice_size;

const int       vme_mx_adr=254;
int             vme_readback[vme_mx_adr];
char            bell=7;

int             icrc;
int             itype;
int             ichip;
int             dsn_tmb[8];
int             dsn_mez[8];
int             dsn[8];
std::string         dsn_chip[3]={"TMB","Mez","RAT"};
std::string         dsn_chip_alct[2]={"ALCT","AMEZ"};
std::string         icrc_ok;

int             dmb_wdcnt;
int             dmb_busy;
int             dmb_rdata;
int             dmb_rdata_lsb;
int             dmb_rdata_msb;

int             cfeb_base;
int             cfeb_data;
int             cfeb_err;
int             cfeb_id;
int             cfeb_id_expect;

int             iver;
char            cfver[2+1];
std::string         sfver;

int             idsn;
char            cdsn[7+1];
char            cdsnfull[32+1];
std::string         sdsn;

int             nlayers_hit;
int             scint_veto;
int             adc_data;
int             alct_adc_data[5][15]={{0}};

int             alct0_inj_rd;
int             alct1_inj_rd;
int             alct0_inj_wr;
int             alct1_inj_wr;

int             alct0_vpf_inj;
int             alct0_qual_inj;
int             alct0_amu_inj;
int             alct0_key_inj;
int             alct0_bxn_inj;

int             alct1_vpf_inj;
int             alct1_qual_inj;
int             alct1_amu_inj;
int             alct1_key_inj;
int             alct1_bxn_inj;

int             alct0_vpf;
int             alct0_qual;
int             alct0_amu;
int             alct0_key;
int             alct0_bxn;

int             alct1_vpf;
int             alct1_qual;
int             alct1_amu;
int             alct1_key;
int             alct1_bxn;

//  const int       mxframe=4096;       // Max raw hits frame number
int             vf_data[mxframe];
int             iframe;
int             ilayer;

int             adr_e0b;
int             r_nheaders;
int             r_ncfebs;
int             r_fifo_tbins;
int             nsamples;

int             read_pat[mxtbins][mxly][mxdsabs];
int             rdcid;
int             rdtbin;
int             hits8;
int             hits1;
int             ids;
int             ids_abs;
int             jcfeb;
char            x[]="          ";
bool            display_cfeb;

int             cfeb_rxdata_1st[24];
int             cfeb_rxdata_2nd[24];
int             cfeb_rxdata_1st_remap[24];
int             cfeb_rxdata_2nd_remap[24];
int             cfeb_sync_rxdata_1st;
int             cfeb_sync_rxdata_2nd;

int             pat_expect;
int             clct_bxn_expect;

int             clct_key_expect[mxclcts];
int             clct_pid_expect[mxclcts];
int             clct_hit_expect[mxclcts];

int             m0def;
int             m1def;
int             muon0[256];
int             muon1[256];
int             nfdef;
int             nframes;
int             mpc_ram_wrdata[4];

int             mpc_accept0;
int             mpc_accept1;
int             mpc_reserved0;
int             mpc_reserved1;
int             mpc_delay;
int             wr_marker;

char            cid[1];
char            cidc[8];
char            cich[1];
char            cvcore[5];
char            cv2p5_mez[5];
char            cv1p8_mez[5];
char            cv1p2_mez[5];

char            ctfpga_mez[5];
char            ctsink_mez[5];

double          tfpga_mez_f;
double          tsink_mez_f;


std::string         sid;
std::string         sidc;
std::string         sich;
std::string         svcore;
std::string         sv2p5_mez;
std::string         sv1p8_mez;
std::string         sv1p2_mez;
std::string         stfpga_mez;
std::string         stsink_mez;

int             tadc_ok;
int             tfpga_ok;
int             tsink_ok;
int             v2p5_mez_ok;
int             v1p8_mez_ok;
int             v1p2_mez_ok;

int             iflocal;
int             ifhsink;
char            cflocal[3+1];
char            cfhsink[3+1];
std::string         sflocal;
std::string         sfhsink;

int             ccb_rx_bank0;
int             ccb_rx_bank1;
int             ccb_rx_bank2;
int             ccb_rx_bank3;

unsigned short  ccb_rxa;
unsigned short  ccb_rxb;
unsigned short  ccb_rxc;
unsigned short  ccb_rxd;

unsigned short  dmb_rxa;
unsigned short  dmb_rxb;
unsigned short  dmb_rxc;
unsigned short  dmb_rxd;

int             wr_pat;
int             wr_pat_vlad;
int             wr_pat_ck;

unsigned short  mpc_rxa;
unsigned short  mpc_rxb;
int             mpc_rx_bank0;
int             mpc_rx_bank1;

unsigned short  rpc_rxa;
unsigned short  rpc_rxb;
unsigned short  rpc_rxc;
unsigned short  rpc_rxd;
unsigned short  rpc_rxe;
unsigned short  rpc_rxf;

int             rpc_rxh[38];
int             rpc_clock;
int             rd_ddd0;
int             rpc_smbrx;
int             rpc_rx_bank0;
int             rpc_rx_bank1;
int             rpc_rx3126;
int             rpc_rxh0902;
int             rpc_dsn;
int             rpc_done;

int             smb_clk;
int             tck_rpc;
int             tms_rpc;
int             tdi_rpc;
int             tdo_rpc;
int             rpc_sync;
int             rpc_posneg;
int             rpc_loop_tm;
int             sel_rpc_chain;

int             jtag_alct;
int             alct_tx_lo;
int             adb_pulse_async;
int             nhard_reset_alct;
int             alct_tx_hi;
int             alct_loop;
int             alct_rxoe;
int             alct_txoe;
int             alct_clock_en;
int             alct_clock;
int             rpc_free_tx0;
int             nhard_reset_rpc;

int             ipass_full_auto;
double          amptol;
double          ttol;
int             isource;

int             clct_sm;
int             read_sm;
std::string         sclct_sm[6];
std::string         sread_sm[22];

int             hit_thresh_pretrig_temp;
int             hit_thresh_postdrift_temp;

int             fmm_state;
std::string         sfmm_state[5]={"Startup","Resync ","Stop   ","WaitBXO","Run    "};

bool            rdraw;
int             nbxn0;
int             ntrig;

int             nperbank;
int             ibank;
int             alct_1st_bank[3];
int             alct_2nd_bank[3];
int             ifs;

int             alct_raw_busy;
int             alct_raw_done;
int             alct_raw_nwords;
int             alct_raw_data;

int             alct0_raw_lsb;
int             alct0_raw_msb;
int             alct0_raw;

int             alct1_raw_lsb;
int             alct1_raw_msb;
int             alct1_raw;

std::string         dmb_chip[4]={"U28","U29","U30","U31"};
std::string         rpc_chip[2]={"U42","U43"};

int             prom_clk[2];
int             prom_oe[2];
int             prom_nce[2];
int             iprom;
int             jprom;
int             prom_data;
int             prom_src;
int             prom_adr;

int             wr_buf_ready;
int             buf_stalled;
int             buf_q_full;
int             buf_q_empty;
int             buf_q_ovf_err;
int             buf_q_udf_err;
int             buf_q_adr_err;
int             buf_display;
int             wr_buf_adr;
int             buf_fence_dist;
int             buf_fence_cnt;
int             buf_fence_cnt_peak;
int             buf_free_space;

int             queue_full;
int             queue_empty;
int             queue_ovf;
int             queue_udf;

int             seqdeb_adr;
int             seqdeb_rd_mux;
unsigned long   deb_adr_diff;
unsigned long   deb_wr_buf_adr;
unsigned long   deb_buf_push_adr;
unsigned long   deb_buf_pop_adr;
unsigned long   deb_buf_push_data;
unsigned long   deb_buf_pop_data;

int             push_l1a_bxn_win;
int             push_l1a_cnt_win;
int             push_l1a_match_win;
int             push_l1a_push_me;
int             push_l1a_notmb;
int             push_tmb_nol1a;
int             push_wr_buf_avail;

int             pop_l1a_bxn_win;
int             pop_l1a_cnt_win;
int             pop_l1a_match_win;
int             pop_l1a_push_me;
int             pop_l1a_notmb;
int             pop_tmb_nol1a;
int             pop_wr_buf_avail;

int             crc_err;
int             crc_err_old;

int             rat_window_width;
int             rat_window_open;
int             rat_window_close;
int             rat_window_center;
int             rat_window_nbad[16];
int             err_bit;
int             rat_board_id;
int             irtest;
int             imode;

const int       mxadcerr=32;
int             adc_err[mxadcerr+1];
int             adc_err_mez[mxadcerr+1];
int             adc_err_base[14];
int             abs_err;
int             max_err;
int             itest_sc;
bool            bfail;

char            cbid[4+1];
std::string         sbid;
int             lenv;
char            tmb_logfolder[81];
char            alct_logfolder[81];
char            rat_logfolder[81];

int             islot_dut;
int             islot_ref;
unsigned long   base_adr_ref;
unsigned long   boot_adr_ref;
unsigned long   base_adr_dut;
unsigned long   boot_adr_dut;
unsigned long   base_adr_global;
unsigned long   boot_adr_global;
unsigned long   base_adr_chk;
unsigned long   boot_adr_chk;
unsigned long   adr_ww1;

bool            tmb_ref_exists;
bool            tmb_ref_skip;
int             tmb_board_id;
int             firmware_type_ref;
int             statid[10];

const int       tmb_ntests=60;
int             tmb_npassed[tmb_ntests+1];
int             tmb_nfailed[tmb_ntests+1];
int             tmb_nskipped[tmb_ntests+1];
int             itest;

int             tmb_npass=0;
int             tmb_nfail=0;
int             tmb_nskip=0;

const int       rat_ntests=18;
int             rat_npassed[rat_ntests+1];
int             rat_nfailed[rat_ntests+1];
int             rat_nskipped[rat_ntests+1];

int             rat_npass;
int             rat_nfail;
int             rat_nskip;

double          diff;
double          vtol;
char            ckey;

int             geo_adr_rd;
int             geo_parity;
int             parity;

int             radix;
char            csize[3+1];
std::string         ssize;
char            czsize[4+1];
std::string         szsize;
char            cprom[1+1];
std::string         sprom;

unsigned char   outbuf[16];
char            colon=':';



int             rec_len;
int             rec_base_adr;
int             rec_type;
int             adr_hi_byte;
int             adr_lo_byte;
int             segment;
int             cksum;
int             nwords;

int             ibyte;
int             filler;
int             nwrite;
int             iadr_previous;

int             nerrors;
int             nwrites;
int             iadr;
int             cmp_data;
int             cmp_adr;

int             jtag_data;
int             jtag_tck;
int             jtag_tms;
int             jtag_tdi;
int             jtag_sel;

int             lock_tmb_clock0;
int             lock_tmb_clock0d;
int             lock_tmb_clock1;
int             lock_alct_rxclock;
int             lock_alct_rxclockd;
int             lock_mpc_clock;
int             lock_dcc_clock;
int             lock_rpc_rxalt1;

int             jsm_prom_start_vme;
int             jsm_sreset;
int             jsm_autostart;
int             jsm_sel;
int             jsm_busy;
int             jsm_aborted;
int             jsm_header_ok;
int             jsm_chain_ok;
int             jsm_tckcnt_ok;
int             jsm_wdcnt_ok;
int             jsm_cksum_ok;
int             jsm_end_ok;
int             jsm_tck_fpga_ok;
int             jsm_cksum;
int             jsm_vme_ready;
int             jsm_throttle;
int             jsm_jtag_oe;
int             jsm_ok;
int             jsm_unass0;
int             jsm_wdcnt;
int             jsm_tck_fpga;

int             jsm_prom_sm_vec;
int             jsm_format_sm_vec;
int             jsm_jtag_sm_vec;

std::string         jsm_prom_state;
std::string         jsm_format_state;
std::string         jsm_jtag_state;

int             jsm_trailer_adr;
int             jsm_data_valid;
int             jsm_flag_word;
int             jsm_flag_bit;
int             jsm_data;
std::string         sjsm_frame_type;

int             L;
int             vsm_start;
int             vsm_sreset;
int             vsm_autostart;
int             vsm_busy;
int             vsm_aborted;
int             vsm_cksum_ok;
int             vsm_wdcnt_ok;
int             vsm_ok;
int             vsm_pathok;
int             vsm_jtag_auto;
int             vsm_vme_ready;
int             vsm_unass0;
int             vsm_throttle;
int             vsm_wdcnt;
int             vsm_cksum;
int             vsm_fmt_err;
int             vsm_fmt_err0;
int             vsm_fmt_err1;
int             vsm_fmt_err2;
int             vsm_fmt_err3;
int             vsm_fmt_err4;
int             vsm_path;
int             vsm_nvme_writes;
std::string         svsm_frame_type;
std::string         vstr;

const int       mxmodified=1000;
int             nmodified;
int             store_adr[mxmodified];
int             store_data[mxmodified];
int             adr_mod5;

int             vsm_data;
int             vsm_begin_marker;
int             clct_type;
int             vsm_month;
int             vsm_day;
int             vsm_year;
int             vsm_version;
int             vsm_option0;
int             vsm_option1;
int             vsm_option2;
int             vsm_option3;
int             vsm_option4;
int             vsm_end_header;
int             vsm_end_prom_marker;
int             vsm_end_data_marker;
int             vmesm4_data;

int             alct_begin_marker;
int             alct_end_marker;
int             alct_end_header;
int             alct_unass;
int             alct_type;
int             alct_month;
int             alct_day;
int             alct_year;
int             alct_version;
int             imonth;
int             iday;
int             iyear;

int             wdcnt;
int             prom_wdcnt;
int             prom_cksum;
int             njtag_frames;

std::string         sresult_cksum;
std::string         sresult_wdcnt;
bool            first_prom_pass;

int             uptime;
int             uptime_hr;
int             uptime_min;
int             uptime_sec;

int             bd_status_ok;
int             bd_vstat_5p0v;
int             bd_vstat_3p3v;
int             bd_vstat_1p8v;
int             bd_vstat_1p5v;
int             bd_t_crit;

int             iadr_rd;
int             rd_data_rd;
int             nmiss;
int             nadrs;
int             nadrs_written;
int             nadrs_read;
int             blue_flash;

int             alct_bx0_delay;
int             clct_bx0_delay;

bool            compare_prom_file;
bool            fire_injector=false;
bool            err_check=true;
bool            skip_loopback_series=false;

unsigned short  wr_fire_l1a;

int             l1a_lookback;
int             hdr_wr_continuous;
int             lookback_triad_hits[2048]={0};

int             first_nonzero_bx;
int             last_nonzero_bx;
int             first_bx;
int             last_bx;
int             max_triads;
double          scale;
int             tck;

int             xsvf_file_size;
std::string         xsvf_file_name;
std::string         xsvf_tmb_user_default="userproms.xsvf";
struct          _stat buf;
int             stat_result;

clock_t         startClock;
clock_t         endClock;
unsigned char   ucTdoBit;
short int       TMS=1;

// Miniscope
int             mini_read_enable;
int             mini_test;
int             mini_tbins_word;
int             fifo_pretrig_mini;
int             csc_id;

// Digital phase shifters
const int       dps_max   = 25;     //  0-255 spans 25ns, 0-to-25 with delta=10 spans (250/256)*25ns, close enough to 100%
const int       dps_delta = 10;     //  approximate steps per ns

int             alct_sync_rxdata_dly;
int             alct_sync_rxdata_pre;
int             alct_sync_1st_err[dps_max+1];
int             alct_sync_2nd_err[dps_max+1];
int             alct_sync_1st_err_ff[dps_max+1];
int             alct_sync_2nd_err_ff[dps_max+1];

int             alct_tx_default;
int             alct_rx_default;

int             alct_tx_bad[16];
int             alct_rx_bad[16];

int             alct_1st_demux;
int             alct_2nd_demux;
int             alct_demux_err;

int             alct_rxd_bad[dps_max+1][28];
int             alct_txd_bad[dps_max+1][28];
int             alct_rxd_txd_depth[dps_max+1][dps_max+1][16];

int             good_spot;
int             good_spots[dps_max+1][2][dps_max+1][2][16];
int             good_depth[dps_max+1][2][dps_max+1][2][16];
int             good_spots_tof[16];
int             good_spots_pos_tof[2][2][16];

int             ngood;
int             ngood_max;
int             ngood_edge;
int             ngood_center;
int             ngood_depths;
int             ngood_spots;
int             good_depths;
int             depth_code;
int             posneg_code;
int             window_center[2][16];
int             window_width[2][16];

int             maxv;
int             minv;

int             newcenter;
bool            alct_tof_scan;
bool            alct_rxd_scan_done=false;
bool            debug;

int             alct_demux_rd[8];
int             alct_sync_rxdata_1st;
int             alct_sync_rxdata_2nd;
int             alct_sync_expect_1st;
int             alct_sync_expect_2nd;
int             alct_walking1_err[28][2][28];
int             alct_walking1_hit[28][2][28][2];

int             alct_sync_clr_err;
int             alct_sync_tx_random;
int             pipe_depth;
int             msec;
int             ibad;
char            symbol;

int             alct_rxd_posneg,    alct_rxd_posneg_min,    alct_rxd_posneg_max,    alct_rxd_posneg_default;
int             alct_txd_posneg,    alct_txd_posneg_min,    alct_txd_posneg_max,    alct_txd_posneg_default;
int             alct_tof_delay,     alct_tof_delay_min,     alct_tof_delay_max;
int             alct_rxd_delay;
int             alct_txd_delay;
int             alct_rxd_int_delay;
int             alct_txd_int_delay;

int             alct_tof_default={0};           // Reference TMB values
int             alct_rxd_default={9};
int             alct_txd_default={1};

int             cfeb_tof_delay_min;
int             cfeb_tof_delay_max;
int             cfeb_rxd_posneg_min;
int             cfeb_rxd_posneg_max;

int             cfeb_tof_delay_default={0};     // Reference TMB values
int             cfeb_rxd_delay_default[5]={0,0,0,0,0};
int             cfeb_rxd_posneg_default[5]={0,0,0,0,0};
int             cfeb_txc_delay_default[5]={0,0,0,0,0};
int             cfeb_nbx_delay_default[5]={0,0,0,0,0};
int             cfeb_delay_is[5];

//                                                0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
int             alct_rxd_posneg_table[26]   ={1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1};
int             alct_txd_posneg_table[26]   ={1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
int             alct_txd_int_delay_table[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
int             alct_rxd_int_delay_table[26]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

std::string         scfeb;
char            ccfeb[1];

int             cfeb_tof_delay;
int             cfeb_rxd_posneg;
int             cfeb_rxd_delay;
int             cfeb_nbx_delay;
int             cfeb_rxd_bad[dps_max+1][24];
int             cfeb_sync_1st_err[dps_max+1];
int             cfeb_sync_2nd_err[dps_max+1];
int             cfeb_1st_expect;
int             cfeb_2nd_expect;
bool            cfeb_rxd_scan_done=false;

int             seq_cmd_bit[4];
int             alct_1st_expect;
int             alct_2nd_expect;
int             ibit_1st_expected;
int             ibit_2nd_expected;
int             ibit_1st_received;
int             ibit_2nd_received;
int             nx;
double          avgbad;
char            dash1[2]={'-','1'};
char            passfail[2]={'P','F'};

int             bxn_offset_pretrig;
int             bxn_offset_signed;
int             bx0_match;
int             bxn_offset_at_match;
int             nmatches;
std::string     bx0_match_state;

// Window centers from an alct_rxd Teven|Todd scan by posneg and ToF
int             window_center_rxd[2][16]=
{
    1,  3,  5,  7,  9, 11, 13, 15, 18, 20, 21, 23,  0,  0,  0,  0,
    1,  3,  5,  7, 10, 11, 13, 16, 18, 20, 22, 24,  0,  0,  0,  0
};

// Board testing
int             id_month_expect;
int             id_day_expect;
int             id_year_expect;
int             id_rev_fpga_expect;

int             id_rev_month_expect;
int             id_rev_day_expect;
int             id_rev_year_expect;
bool            ledtest[7];
double          a1p5core_expect;

// CFEB bad bits
int             cfeb_badbits_reset;
int             cfeb_badbits_block;
int             cfeb_badbits_found;
int             cfeb_badbits_blocked;
int             cfeb_badbits_nbx;
int             cfeb_badbits[mxcfeb][mxly];
int             bcb_read_enable;
int             ibadbit;
int             adr_offset;
int             icycle;
int             nbx;
int             idslp;
int             ilayerlp;
int             iword;
int             iword_expect;

// Hot channel mask
int             hcm_adr;
int             hcm_data;
int             hcm_data0;
int             hcm_data1;
int             hot_channel_mask[mxcfeb][mxly][mxds];

// Pattern_finder
int             cfeb_en[5]={1,1,1,1,1};

int             hs_key_1st_emu;
int             hs_pid_1st_emu;
int             hs_hit_1st_emu;

int             hs_key_2nd_emu;
int             hs_pid_2nd_emu;
int             hs_hit_2nd_emu;

int             nlayers_hit_emu;
int             layer_trig_emu;
int             cfeb_active_emu[5];

bool            emulator_pretrig;
bool            emulator_latch_clct0;
bool            emulator_latch_clct1;
bool            send_emulator_to_tmb;

int             clct0_vpf_emu;
int             clct0_hit_emu;
int             clct0_pid_emu;
int             clct0_key_emu;
int             clct0_cfeb_emu;
int             clctc_sync_emu;

int             clct1_vpf_emu;
int             clct1_hit_emu;
int             clct1_pid_emu;
int             clct1_key_emu;
int             clct1_cfeb_emu;

int             clct0_vpf_vme;
int             clct0_hit_vme;
int             clct0_pid_vme;
int             clct0_key_vme;
int             clct0_cfeb_vme;

int             clct1_vpf_vme;
int             clct1_hit_vme;
int             clct1_pid_vme;
int             clct1_key_vme;
int             clct1_cfeb_vme;

int             clctc_bxn_vme;
int             clctc_sync_vme;

int             nspan;
int             pspan;
int             busy_min;
int             busy_max;
bool            clct0_is_on_me1a;
int             key_inj;
int             busy_key_inj[160];

int             clct_hit_inj_expect[2];
int             clct_key_inj_expect[2];
int             clct_pid_inj_expect[2];
int             clct_pat_inj_expect[2];

bool            injector_clct0_over;
bool            injector_clct1_over;
bool            injector_pretrig;
bool            injector_latch_clct0;
bool            injector_latch_clct1;

int             clct0_vpf_vme_expect;
int             clct0_hit_vme_expect;
int             clct0_pid_vme_expect;
int             clct0_key_vme_expect;
int             clct0_cfeb_vme_expect;
int             clctc_sync_vme_expect;

int             clct1_vpf_vme_expect;
int             clct1_hit_vme_expect;
int             clct1_pid_vme_expect;
int             clct1_key_vme_expect;
int             clct1_cfeb_vme_expect;

int             clct0_vpf_tmb;
int             clct0_hit_tmb;
int             clct0_pid_tmb;
int             clct0_key_tmb;
int             clct0_cfeb_tmb;

int             clct1_vpf_tmb;
int             clct1_hit_tmb;
int             clct1_pid_tmb;
int             clct1_key_tmb;
int             clct1_cfeb_tmb;

int             clctc_bxn_tmb;
int             clctc_sync_err_tmb;

int             key0;
int             key1;

bool            kill_me1a_clcts;
bool            clct0_exists;
bool            clct1_exists;
bool            clct0_cfeb4;
bool            clct1_cfeb4;
bool            kill_clct0;
bool            kill_clct1;
bool            kill_trig;
bool            bans;

bool            clct_noalct_lost;
bool            alct_only_trig;

bool            clct_keep;
bool            alct_keep;

bool            clct_keep_ro;
bool            alct_keep_ro;

bool            clct_discard;
bool            alct_discard;

bool            clct_match;
bool            clct_noalct;
bool            alct_noclct;
bool            alct_pulse;

bool            trig_pulse;
bool            trig_keep;
bool            non_trig_keep;
bool            alct_only;

bool            clct_match_tr;
bool            alct_noclct_tr;
bool            clct_noalct_tr;
bool            clct_match_ro;
bool            alct_noclct_ro;
bool            clct_noalct_ro;

bool            tmb_trig_pulse;
bool            tmb_trig_keep_ff;
bool            tmb_non_trig_keep_ff;

bool            tmb_match;
bool            tmb_alct_only;
bool            tmb_clct_only;

bool            tmb_match_ro_ff;
bool            tmb_alct_only_ro_ff;
bool            tmb_clct_only_ro_ff;

bool            tmb_alct_discard;
bool            tmb_clct_discard;

int             tmb_alct0;
int             tmb_alct1;
int             alct0_pipe;
int             alct1_pipe;
int             alct0_real;
int             alct1_real;

int             keep_clct;
int             clct0_real;
int             clct0_pipe;
int             clct1_real;
int             clct1_pipe;
int             clctc_real;
int             clctc_pipe;

bool            tmb_match_ro;
bool            tmb_alct_only_ro;
bool            tmb_clct_only_ro;

bool            tmb_trig_keep;
bool            tmb_non_trig_keep;

int             tmb_no_alct_emu;
int             tmb_no_clct_emu;
int             tmb_one_alct_emu;
int             tmb_one_clct_emu;
int             tmb_two_alct_emu;
int             tmb_two_clct_emu;
int             tmb_dupe_alct_emu;
int             tmb_dupe_clct_emu;

int             alct_dummy;
int             clct_dummy;
int             clctc_dummy;
int             clct_bxn_insert_emu;

int             clct0_emu;
int             clct1_emu;
int             clctc_emu;

int             alct0_emu;
int             alct1_emu;

int             lct0_vpf_emu;
int             lct1_vpf_emu;

int             alct0_vpf_emu;
int             alct0_valid_emu;
int             alct0_quality_emu;
int             alct0_amu_emu;
int             alct0_key_emu;
int             alct0_bxn_emu;

int             alct1_vpf_emu;
int             alct1_valid_emu;
int             alct1_quality_emu;
int             alct1_amu_emu;
int             alct1_key_emu;
int             alct1_bxn_emu;

int             clct0_valid_emu;
int             clct0_bend_emu;

int             clct1_valid_emu;
int             clct1_bend_emu;

int             clct_bxn_emu;
int             clct_sync_err_emu;

int             alct0_hit_emu;
int             alct1_hit_emu;

int             clct0_cpat_emu;
int             clct1_cpat_emu;

int             ACC;
int             A;
int             C;
int             A4;
int             C4;
int             P;
int             CPAT;
int             Q;

int             lct0_quality_emu;
int             lct1_quality_emu;
int             tmb_rank_err_emu;

int             alct_bx0_emu;
int             clct_bx0_emu;

int             csc_id_emu;

int             trig_mpc_emu;
int             trig_mpc0_emu;
int             trig_mpc1_emu;

int             mpc0_frame0_emu;
int             mpc0_frame1_emu;
int             mpc1_frame0_emu;
int             mpc1_frame1_emu;

int             mpc0_frame0_pulse;
int             mpc0_frame1_pulse;
int             mpc1_frame0_pulse;
int             mpc1_frame1_pulse;

int             mpc_alct0_key_expect;
int             mpc_clct0_pid_expect;
int             mpc_lct0_qual_expect;
int             mpc_lct0_vpf_expect;

int             mpc_clct0_key_expect;
int             mpc_clct0_bend_expect;
int             mpc_sync_err0_expect;
int             mpc_alct0_bxn_expect;
int             mpc_bx0_clct_expect;
int             mpc_csc_id0_expect;

int             mpc_alct1_key_expect;
int             mpc_clct1_pid_expect;
int             mpc_lct1_qual_expect;
int             mpc_lct1_vpf_expect;

int             mpc_clct1_key_expect;
int             mpc_clct1_bend_expect;
int             mpc_sync_err1_expect;
int             mpc_alct1_bxn_expect;
int             mpc_bx0_alct_expect;
int             mpc_csc_id1_expect;

int             mpc_alct0_key_vme;
int             mpc_clct0_pid_vme;
int             mpc_lct0_qual_vme;
int             mpc_lct0_vpf_vme;

int             mpc_clct0_key_vme;
int             mpc_clct0_bend_vme;
int             mpc_sync_err0_vme;
int             mpc_alct0_bxn_vme;
int             mpc_bx0_clct_vme;
int             mpc_csc_id0_vme;

int             mpc_alct1_key_vme;
int             mpc_clct1_pid_vme;
int             mpc_lct1_qual_vme;
int             mpc_lct1_vpf_vme;

int             mpc_clct1_key_vme;
int             mpc_clct1_bend_vme;
int             mpc_sync_err1_vme;
int             mpc_alct1_bxn_vme;
int             mpc_bx0_alct_vme;
int             mpc_csc_id1_vme;

int             lct0_vme;
int             lct1_vme;

int             ihs_min;
int             ihs_max;
int             ihs_hit;
int             ihs_ds;

int             sync_err_reset;
int             clct_bx0_sync_err_en;
int             alct_ecc_rx_err_en;
int             alct_ecc_tx_err_en;
int             bx0_match_err_en;
int             clock_lock_lost_err_en;
int             sync_err_blanks_mpc_en;
int             sync_err_stops_pretrig_en;
int             sync_err_stops_readout_en;
int             sync_err; 
int             clct_bx0_sync_err; 
int             alct_ecc_rx_err_ff; 
int             alct_ecc_tx_err_ff; 
int             bx0_match_err_ff; 
int             clock_lock_lost_err_ff; 
int             sync_err_force; 

int             clock_lost_lost_clct;
int             clct_bx0_sync_err_clct;

const char      LF=10;  //Line feed 
const int       mxcomment=256;
char            comment[mxcomment];
int             idata;
int             adrddu;

bool            load_clct_injector_image;
int             dscfeb[mxcfeb];

int             mask_all;
int             mask_cfeb;
int             inj_trig;
int             inj_busy;
bool            engage_pattern_finder;

int             wr_data_lsb;
int             wr_data_msb;
int             rd_data_lsb;
int             rd_data_msb;
int             l1a_lookback_data;

// Virtex-6 SNAP12 GTX receivers and QPLL
int             qpll_nrst;
int             qpll_lock;
int             qpll_err;

int             r12_sclk;
int             r12_sdat;
int             r12_fok;

int             gtx_rx_enable_all;
int             gtx_rx_reset_all;
int             gtx_rx_reset_err_cnt_all;
int             gtx_rx_en_prbs_test_all;
int             gtx_rx_start_all;
int             gtx_rx_fc_all;
int             gtx_rx_valid_all;
int             gtx_rx_match_all;
int             gtx_rx_sync_done_all;
int             gtx_rx_pol_swap_all;
int             gtx_rx_err_all;

int             idcfeb;
int             gtx_rx_enable[7];
int             gtx_rx_reset[7];
int             gtx_rx_reset_err_cnt[7];
int             gtx_rx_en_prbs_test[7];
int             gtx_rx_start[7];
int             gtx_rx_fc[7];
int             gtx_rx_valid[7];
int             gtx_rx_match[7];
int             gtx_rx_sync_done[7];
int             gtx_rx_pol_swap[7];
int             gtx_rx_err[7];

int             adc_valid;
double          sysmon_temp_c;
double          sysmon_temp_f;
double          sysmon_vccint;
double          sysmon_vccaux;
double          sysmon_vref;
double          sysmon_vzero;








#endif
