//------------------------------------------------------------------------------
// Decode TMB 2001 raw hits dump
//
//  10/02/08 Port from fortran version
//  10/24/08 Add ability to decode any header type + check readout structure
//  11/04/08 Replace c character strings with c++ strings
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "pause.h"
#include "crc22.h"
#include "common.h"
#include "ck.h"
#include "scope160c.h"
using namespace std;

//------------------------------------------------------------------------------
// Debug print mode
//------------------------------------------------------------------------------
#define debug 1 // comment this line to turn off debug print

    #include "debug_print.h"

//------------------------------------------------------------------------------
// Entry decode_raw_hits()
//------------------------------------------------------------------------------
void            decode_raw_hits (
        int              vf_data[mxframe],
        int              dmb_wdcnt,
        int              itriad[mxtbins][mxdsabs][mxly],
        int              clct0_vme,
        int              clct1_vme,
        int              clctc_vme,
        int              mu0fr0_vme,
        int              mu0fr1_vme,
        int              mu1fr0_vme,
        int              mu1fr1_vme,
        int              first_event,
        int              scp_tbins,
        unsigned long    base_adr,
        unsigned long    scp_ctrl_adr,
        unsigned long    scp_rdata_adr)
    //------------------------------------------------------------------------------
{
    /*
    //DEC$ DEFINE cond=3

    subroutine decode_raw_hits(vf_data,dmb_wdcnt,
    1 itriad,clct0_vme,clct1_vme,clctc_vme,
    1 mu0fr0_vme,mu0fr1_vme,mu1fr0_vme,mu1fr1_vme,first_event,
    1 scp_tbins,base_adr,scp_ctrl_adr,scp_rdata_adr)
    c
    implicit    none

    // Parameters
    parameter   mxframe=4096        //Max raw hits frame number
    parameter   mxtbins=32-1        //Highest time bin
    parameter   mxly=6-1            //# CSC Layers
    parameter   mxds=8-1            //# DiStrips per CFEB
    */  
    //  parameter   mxdsabs=40-1        //# DiStrips per CSC
    //  parameter   mxkey=160-1         //# Key wire groups on CSC
    /*
    //DEC$ ATTRIBUTES C, ALIAS:'_scope160c' :: scope160c

    c Argument list
    integer*4   vf_data(0:mxframe)
    integer*4   dmb_wdcnt
    integer*4   itriad(0:mxtbins,0:mxdsabs,0:mxly)
    integer*4   clct0_vme
    integer*4   clct1_vme
    integer*4   clctc_vme
    integer*4   mu0fr0_vme
    integer*4   mu0fr1_vme
    integer*4   mu1fr0_vme
    integer*4   mu1fr1_vme
    logical     first_event
    integer     scp_tbins
    integer*4   base_adr
    integer*4   scp_ctrl_adr
    integer*4   scp_rdata_adr
    */
    // Header
    bool            header_ok;
    bool            header_only_short;
    bool            header_only_long;
    bool            header_full;
    bool            header_filler;
    static bool     first_entry=true;

    const int       wdcnt_short_hdr=12;
    const int       wdcnt_long_hdr=48;

    int             adr_b0c;
    int             adr_e0b;
    int             adr_b04;
    int             adr_e04;
    int             adr_b05;
    int             adr_e05;
    int             adr_e0c;
    int             adr_fil;
    int             adr_e0f;

    // Local
    int             i;
    int             n;
    int             ipair;
    int             last_frame;

    long int        din;
    long int        crc;
    long int        crc_calc;
    long int        tmb_crc_lsb;
    long int        tmb_crc_msb;
    long int        tmb_crc;
    bool            crc_match;

    int             dmb_wdcnt_trun;
    int             fifo_cfeb_enable;
    int             frame_cnt_expect;
    int             frame_cnt_expect_trun;
    int             frame_cntex_nheaders;
    int             frame_cntex_ntbins;
    int             frame_cntex_b0ce0c;
    int             frame_cntex_rpc;
    int             frame_cntex_b04e04;
    int             frame_cntex_scope;
    int             frame_cntex_b05e05;
    int             frame_cntex_fill;
    int             frame_cntex_trailer;

    int             clct0;
    int             clct0_vpf;
    int             clct0_nhit;
    int             clct0_pat;
    int             clct0_key;
    int             clct0_cfeb;
    int             clct0_fullkey;

    int             clct1;
    int             clct1_vpf;
    int             clct1_nhit;
    int             clct1_pat;
    int             clct1_key;
    int             clct1_cfeb;
    int             clct1_fullkey;

    //  int             clct0_cfebr;
    //  int             clct1_cfebr;

    int             clctc;
    int             clctc_bxn;
    int             clctc_sync;

    int             mu0fr0;
    int             mu0fr1;
    int             mu1fr0;
    int             mu1fr1;

    int             mpc_alct0_key;
    int             mpc_clct0_pat;
    int             mpc_lct0_quality;
    int             mpc_lct0_vpf;

    int             mpc_clct0_key;
    int             mpc_clct0_bend;
    int             mpc_sync_err0;
    int             mpc_alct0_bxn;
    int             mpc_bx0_clct;
    int             mpc_csc_id0;

    int             mpc_alct1_key;
    int             mpc_clct1_pat;
    int             mpc_lct1_quality;
    int             mpc_lct1_vpf;

    int             mpc_clct1_key;
    int             mpc_clct1_bend;
    int             mpc_sync_err1;
    int             mpc_alct1_bxn;
    int             mpc_bx0_alct;
    int             mpc_csc_id1;

    // Local
    int             icfeb;
    int             itbin;
    int             ilayer;

    int             rdcid;
    int             rdtbin;
    int             itbin_bit3;
    int             itbin_bit4;
    int             itbin_merged;
    int             itbin_expect;   
    int             hits1;
    int             hits8;
    int             ids;
    int             ids_abs;
    int             read_pat[mxtbins][mxly][mxdsabs];

    char            x[]="          ";
    /*
       integer*4    active_febs_expect
       integer*4    adjcfeb_dist/5/

       integer*4    clctc_bxn_vme
       integer*4    clctc_bxn_header
       integer*4    l1a_rxcount_save
       integer*4    l1a_rxexpect
       */
    int         rpc_data0;
    int         rpc_data1;
    int         rpc_lsbs;
    int         rpc_tbin;
    int         rpc_msbs;
    int         rpc_bxn;
    int         rpc_data;
    int         rpc_id0;
    int         rpc_id1;

    int         bd_status_vec[15];
    int         lhc_cycle=3564;

    string      sfifo_mode;
    string      sr_type;
    string      sl1a_type;
    string      scsc_type_inferred;

    int         id_rev;
    int         id_rev_day;
    int         id_rev_month;
    int         id_rev_year;
    int         id_rev_fpga;

    int         pretrig_counter;
    int         clct_counter;
    int         trig_counter;
    int         alct_counter;
    int         uptime_counter;
    int         uptime_sec;
    /*
       logical      triad_error
       integer*4    triad_read
       integer*4    triad_write
       integer*4    wrtbin
       */   int         ntbins;
    int         ntbinspre;
    /*
       integer*4    nohits
       integer*4    nhitst
       integer*4    tbin_hits
       integer*4    iwg
       integer*4    layer
       integer*4    ifb
       integer*4    ilb
       integer*4    ichip
       integer*4    ibit
       integer*4    iadb
       integer*4    modadb
       integer*4    nerr

       integer*4    mxchip
       integer*4    top_layer_wg
       integer*4    hcm
       integer*4    nmatch
       */
    int         iscp_begin;
    int         iscp_end;
    int         iscp;
    int         scp_arm;
    int         scp_readout;
    int         scp_raw_decode;
    int         scp_silent;
    int         scp_playback;
    int         scp_raw_data[512*160/16-1]; //512tbins*160ch/(16ch/frame)
    /*  integer*4   mxwg

    //DEC$ IF (cond.LT.2)
    integer*4   marker60
    integer*4   ntbins
    integer*4   febs_read
    integer*4   fifo_mode
    integer*4   l1a_rxcount
    integer*4   csc_id
    integer*4   board_id
    integer*4   l1a_type
    integer*4   bxn_l1a
    integer*4   r_type
    integer*4   nheaders
    integer*4   ncfebs
    integer*4   has_buf
    integer*4   ntbinspre
    integer*4   l1a_txcount
    integer*4   trig_source

    integer*4   exist_febs
    integer*4   run_id
    integer*4   bxn_lct
    integer*4   sync_err

    integer*4   lct0lsb
    integer*4   lct1lsb
    integer*4   lct0msb
    integer*4   lct1msb
    integer*4   invp
    integer*4   tmb_match
    integer*4   alct_match
    integer*4   alct_only
    integer*4   clct_only
    integer*4   bxn0_diff
    integer*4   bxn1_diff
    integer*4   triad_pers

    integer*4   mu0fr0lsb
    integer*4   mu0fr1lsb
    integer*4   mu1fr0lsb
    integer*4   mu1fr1lsb
    integer*4   mpc_accept0
    integer*4   mpc_accept1
    integer*4   mu0fr0msb
    integer*4   mu0fr1msb
    integer*4   mu1fr0msb
    integer*4   mu1fr1msb
    integer*4   mpc_res0
    integer*4   mpc_res1
    integer*4   hit_thresh_pretrig
    integer*4   pid_thresh_pretrig
    integer*4   buf_ready
    integer*4   tbinadr
    integer*4   wrbufadr

    integer*4   buf_ovf
    integer*4   buf_full
    integer*4   buf_fullm1
    integer*4   buf_hfull
    integer*4   buf_empty
    integer*4   buf_nbusy
    integer*4   buf_busy

    integer*4   pop_free
    integer*4   pop_tbin_trig
    integer*4   pop_alct_only
    integer*4   pop_clct_only
    integer*4   pop_buf_adr

    integer*4   disc_nobuf
    integer*4   disc_invp
        integer*4   disc_tmbreject

        integer*4   trig_timo
        integer*4   mpctx_timo
        integer*4   mpcrx_timo

        integer*4   alct_delay
        integer*4   mpc_tx_delay

        integer*4   nlayers_hit
        integer*4   l1a_position
        integer*4   uptime
        integer*4   revcode
        integer*4   eob
        integer*4   eoc
        integer*4   eof
        integer*4   marker626
        integer*4   opt2aaa
        integer*4   opt5555
        integer*4   crc22lsb
        integer*4   crc22msb
        integer*4   lctype28
        integer*4   lctype29
        integer*4   lctype31
        integer*4   ddu_code28
        integer*4   ddu_code29
        integer*4   ddu_code30
        integer*4   ddu_code31
        //DEC$ ENDIF
        */
        //---------------------------------------------------------------------------------
        //  Error flags
        //---------------------------------------------------------------------------------
        const   int     MXERF=37+1;
    char            error_flag[MXERF];
    static  string  error_msg[MXERF];

    if(first_entry) {
        error_msg[ 0] = "0xDB0C first frame marker not found";
        error_msg[ 1] = "0xDE0C or 0xDEEF last frame marker not found";
        error_msg[ 2] = "Calculated word count does not match caller";
        error_msg[ 3] = "Word count <=0";
        error_msg[ 4] = "Word count not a multiple of 4";
        error_msg[ 5] = "Wordcount does not match short or long header format";
        error_msg[ 6] = "CRC error =  embedded does not match calculated";
        error_msg[ 7] = "First frame missing 0xDB0C marker";
        error_msg[ 8] = "First 4 frames do not have DDU-special codes";
        error_msg[ 9] = "Last  4 frames do not have DDU-special codes";
        error_msg[10] = "Last frame-3 missing EEF marker";
        error_msg[11] = "Last frame-3 missing E0F marker";
        error_msg[12] = "Last 4 frames missing bit[11]=1";
        error_msg[13] = "Fifo mode does not match short header format";
        error_msg[14] = "Record type does not match short header format";
        error_msg[15] = "Fifo mode does not match long  header format";
        error_msg[16] = "Record type does not match long header format";
        error_msg[17] = "Record type does not match full header format";
        error_msg[18] = "Expected frame count does not match actual frame count";
        error_msg[19] = "E0B marker not found at expected address";
        error_msg[20] = "B04 marker not found at expected address";
        error_msg[21] = "E04 marker not found at expected address";
        error_msg[22] = "B05 marker not found at expected address";
        error_msg[23] = "E05 marker not found at expected address";
        error_msg[24] = "E0C marker not found at expected address";
        error_msg[25] = "2AAA filler not found at expected address";
        error_msg[26] = "5555 filler not found at expected address";
        error_msg[27] = "Bad board hardware status";
        error_msg[28] = "Clock bx0 sync error";
        error_msg[29] = "RAM SEU parity error";
        error_msg[30] = "CLCT0 key does not match LCT0";
        error_msg[31] = "CLCT0 pattern ID does not match LCT0";
        error_msg[32] = "ALCT0 key does not match LCT0";
        error_msg[33] = "CLCT1 key does not match LCT1";
        error_msg[34] = "CLCT1 pattern ID does not match LCT1";
        error_msg[35] = "ALCT1 key does not match LCT1";
        error_msg[36] = "Expected number of CFEBs 0<r_ncfebs<=5";
        error_msg[37] = "Expected number of CFEB tbins 0<r_fifo_tbins";
    }

    //---------------------------------------------------------------------------------
    //  Board status
    //---------------------------------------------------------------------------------
    const   int     MXSTAT=14+1;
    static  string  bd_status_msg[MXSTAT];
    int             bd_status_expect[MXSTAT];

    if(first_entry) {
        bd_status_msg[ 0] = "bd_status_ok";
        bd_status_msg[ 1] = "vstat_5p0vs";
        bd_status_msg[ 2] = "vstat_3p3v";
        bd_status_msg[ 3] = "vstat_1p8v";
        bd_status_msg[ 4] = "vstat_1p5v";
        bd_status_msg[ 5] = "_t_crit";
        bd_status_msg[ 6] = "vsm_ok";
        bd_status_msg[ 7] = "vsm_aborted";
        bd_status_msg[ 8] = "vsm_cksum_ok";
        bd_status_msg[ 9] = "vsm_wdcnt_ok";
        bd_status_msg[10] = "jsm_ok";
        bd_status_msg[11] = "jsm_aborted";
        bd_status_msg[12] = "jsm_cksum_ok";
        bd_status_msg[13] = "jsm_wdcnt_ok";
        bd_status_msg[14] = "sm_tck_fpga_ok";
    }
    //---------------------------------------------------------------------------------
    //  Header data types
    //---------------------------------------------------------------------------------
    int         ddu[mxframe];
    int         iframe;

    int         boc;
    int         pop_bxn_counter;
    int         pop_l1a_rx_counter;
    int         readout_counter;
    int         board_id;
    int         csc_id;
    int         run_id;
    int         h4_buf_q_ovf_err;
    int         r_sync_err;

    int         r_nheaders;
    int         fifo_mode;
    int         r_type;
    int         l1a_type;
    int         r_has_buf;
    int         r_buf_stalled;
    int         bd_status;
    int         revcode;

    int         r_bxn_counter_ff;
    int         r_tmb_clct0_discard;
    int         r_tmb_clct1_discard;
    int         clock_lock_lost;

    int         r_pretrig_counter_lsb;
    int         r_pretrig_counter_msb;

    int         r_clct_counter_lsb;
    int         r_clct_counter_msb;

    int         r_trig_counter_lsb;
    int         r_trig_counter_msb;

    int         r_alct_counter_lsb;
    int         r_alct_counter_msb;

    int         r_orbit_counter_lsb;
    int         r_orbit_counter_msb;

    int         r_ncfebs;
    int         r_fifo_tbins;
    int         fifo_pretrig;
    int         scope_data_exists;
    int         vme_data_exists;

    int         hit_thresh_pretrig;
    int         pid_thresh_pretrig;
    int         hit_thresh_postdrf;
    int         pid_thresh_postdrf;
    int         stagger_csc;
    //  int         csc_me1ab;

    int         triad_persist;
    int         dmb_thresh;
    int         alct_delay;
    int         clct_window;

    // CLCT Trigger Status
    int         r_trig_source_vec;
    int         r_trig_source_vec9;
    int         r_trig_source_vec10;
    int         r_layers_hit;

    int         r_active_feb_ff;
    int         r_febs_read;
    int         r_l1a_match_win;
    int         hs_layer_trig;
    int         active_feb_src;

    // CLCT+ALCT Match Status
    int         r_tmb_match;
    int         r_tmb_alct_only;
    int         r_tmb_clct_only;
    int         r_tmb_match_win;
    int         r_no_alct_tmb;
    int         r_one_alct_tmb;
    int         r_one_clct_tmb;
    int         r_two_alct_tmb;
    int         r_two_clct_tmb;
    int         r_dupe_alct_tmb;
    int         r_dupe_clct_tmb;
    int         r_rank_err_tmb;

    // CLCT Trigger Data
    int         r_clct0_tmb_lsb;
    int         r_clct1_tmb_lsb;
    int         r_clct0_tmb_msb;
    int         r_clct1_tmb_msb;
    int         r_clctc_tmb;
    int         r_clct0_invp;
    int         r_clct1_invp;
    int         r_clct1_busy;
    int         perr_cfeb_ff;
    int         perr_rpc_ff;
    int         perr_ff;

    // ALCT Trigger Data
    int         r_alct0_valid;
    int         r_alct0_quality;
    int         r_alct0_amu;
    int         r_alct0_key;
    int         r_alct_pretrig_win;

    int         r_alct1_valid;
    int         r_alct1_quality;
    int         r_alct1_amu;
    int         r_alct1_key;
    int         drift_delay;
    int         res29;

    int         r_alct_bxn;
    int         alct_seq_status;
    int         alct_seu_status;
    int         alct_reserved_out;
    int         alct_cfg_done;
    int         res30;

    // MPC Frames
    int         r_mpc0_frame0_lsb;
    int         r_mpc0_frame1_lsb;
    int         r_mpc1_frame0_lsb;
    int         r_mpc1_frame1_lsb;
    int         r_mpc0_frame0_msb;
    int         r_mpc0_frame1_msb;
    int         r_mpc1_frame0_msb;
    int         r_mpc1_frame1_msb;
    int         mpc_tx_delay;
    int         r_mpc_accept;
    int         cfeb_en;

    // RPC Configuration
    int         rd_rpc_list;
    int         rd_nrpcs;
    int         rpc_read_enable;
    int         fifo_tbins_rpc;
    int         fifo_pretrig_rpc;

    // Buffer Status
    int         r_wr_buf_adr;
    int         r_wr_buf_ready;
    int         wr_buf_ready;
    int         buf_q_full;
    int         buf_q_empty;

    int         r_buf_fence_dist;
    int         buf_q_ovf_err;
    int         buf_q_udf_err;
    int         buf_q_adr_err;
    int         buf_stalled;

    // Spare Frames
    int         buf_fence_cnt;
    int         reverse_hs_csc;
    int         reverse_hs_me1a;
    int         reverse_hs_me1b;

    int         buf_fence_cnt_peak;
    int         tmb_trig_pulse;

    int         tmb_allow_alct;
    int         tmb_allow_clct;
    int         tmb_allow_match;
    int         tmb_allow_alct_ro;
    int         tmb_allow_clct_ro;
    int         tmb_allow_match_ro;
    int         tmb_alct_ro;
    int         tmb_clct_ro;
    int         tmb_match_ro;
    int         tmb_trig_keep;
    int         tmb_nontrig_keep;
    int         lyr_thresh_pretrig;
    int         layer_trig_en;

    // E0B marker
    int         eob;
    int         eoc;

    // Optional 2 frames to make word count a multiple of 4
    int         opt2aaa;
    int         opt5555;

    // Last 4 trailer words must conform to DDU specification
    int         eof;
    int         lctype3;
    int         crc22lsb;
    int         lctype2;
    int         crc22msb;
    int         lctype1;
    int         frame_cnt;
    int         lctype0;

    //---------------------------------------------------------------------------------
    //  Entry
    //---------------------------------------------------------------------------------
    fprintf(log_file,"\n");

    // Init check bits
    first_entry=false;
    last_frame = dmb_wdcnt-1;
    header_ok=true;
    header_only_short=false;
    header_only_long=false;
    header_full=false;
    header_filler=false;

    // Clear error flags
    for (i=0; i<MXERF; ++i) {
        error_flag[i]=0;
    }

    //---------------------------------------------------------------------------------
    //  Scan incoming data stream for begin DB0C and end E0F (or DEEF) markers
    //---------------------------------------------------------------------------------
    int wdcnt=0;
    int data;
    int first_word=-1;
    int last_word=-1;

    // Scan for DB0C and DE0F/DEEF markers
    for (i=0; i<mxframe; ++i) {
        data=vf_data[i]&0xFFFF;     // Trim out-of band bits
        dprintf(log_file,"Adr=%5i Data=%6.5X\n",i,data);
        if (data==0xDB0C) first_word=i;
        if((data==0xDE0F) || (data==0xDEEF)) last_word=i+3;
        if(i==last_word) break;
    }

    // Did not find DB0C
    if(first_word==-1) {
        header_ok=false;
        error_flag[0]=1;    // 0xDB0C first frame marker not found
        fprintf(log_file,"Err: 0xDB0C first frame marker not found\n");
    }
    fprintf(log_file,"First frame marker found at Adr=%5i Data=%6.5X\n",first_word,vf_data[first_word]);

    // Did not find DE0F/DEEF
    if(last_word ==-1) {
        header_ok=false;
        error_flag[1]=1;    // 0xDE0C or 0xDEEF last frame marker not found
        fprintf(log_file,"Err: 0xDE0C or 0xDEEF last frame marker not found\n");
    }
    fprintf(log_file,"Last  frame marker found at Adr=%5i Data=%6.5X\n",last_word,vf_data[last_word]);

    // Compare word count to callers value [caller may not have supplied a word count]
    wdcnt=1+last_word-first_word;

    fprintf(log_file,"Calculated word count=%5i\n",wdcnt);
    fprintf(log_file,"Callers    word count=%5i\n",dmb_wdcnt);

    if(wdcnt != dmb_wdcnt) {
        header_ok=false;
        error_flag[2]=1;    // Calculated word count does not match caller
        fprintf(log_file,"Err: Calculated word count does not match caller: wdcnt=%i5 dmb_wdcnt=%i5\n",wdcnt,dmb_wdcnt);
    }

    //  dmb_wdcnt=wdcnt;    // Uncomment if caller did not supply a word count

    //---------------------------------------------------------------------------------
    //  Check word count matches either short,long or full mode, and is a multiple of 4
    //---------------------------------------------------------------------------------
    // No TMB data
    if(dmb_wdcnt <= 0) {
        header_ok=false;
        error_flag[3]=1;    // Wordcount <=0
        fprintf(log_file,"Err: No TMB readout to decode. wdcnt=%i\n",dmb_wdcnt);
        fprintf(stderr,  "Err: No TMB readout to decode. wdcnt=%i\n",dmb_wdcnt);
        goto exit;
    }

    // Check that wdcnt is a multiple of 4, all TMB readouts are mod(4) for DDU error checking
    if(dmb_wdcnt%4 != 0) {
        header_ok=false;
        error_flag[4]=1;    // Wordcount not multiple of 4
        fprintf(log_file,"Err: TMB wdcnt is not a multiple of 4. wdcnt=%i\n",dmb_wdcnt);
        fprintf(stderr,  "Err: TMB wdcnt is not a multiple of 4. wdcnt=%i\n",dmb_wdcnt);
    }
    fprintf(log_file,"TMB wdcnt is a multiple of 4. wdcnt=%i\n",dmb_wdcnt);
    fprintf(stderr,  "TMB wdcnt is a multiple of 4. wdcnt=%i\n",dmb_wdcnt);

    // Short header-only mode
    if(dmb_wdcnt == wdcnt_short_hdr) {
        header_only_short=true;
        fprintf(log_file,"TMB readout short header-only mode. wdcnt=%i\n",dmb_wdcnt);
        fprintf(stderr,  "TMB readout short header-only mode. wdcnt=%i\n",dmb_wdcnt);
    }

    // Long header-only mode
    if(dmb_wdcnt == wdcnt_long_hdr) {
        header_only_long=true;
        fprintf(log_file,"TMB readout long header-only mode. wdcnt=%i\n",dmb_wdcnt);
        fprintf(stderr,  "TMB readout long header-only mode. wdcnt=%i\n",dmb_wdcnt);
    }

    // Long header with raw hits mode
    if(dmb_wdcnt > wdcnt_long_hdr) {
        header_full=true;
        fprintf(log_file,"TMB readout long header with raw hits mode. wdcnt=%i\n",dmb_wdcnt);
        fprintf(stderr,  "TMB readout long header with raw hits mode. wdcnt=%i\n",dmb_wdcnt);
    }

    // Check that header format is recognized
    if (!(header_only_short || header_only_long || header_full)) {
        header_ok=false;
        error_flag[5]=1;    // Wordcount does not match short or long header format
        fprintf(log_file,"Err: TMB wdcnt does not match a defined header format. wdcnt=%i\n",dmb_wdcnt);
        fprintf(stderr,  "Err: TMB wdcnt does not match a defined header format. wdcnt=%i\n",dmb_wdcnt);
    }

    fprintf(log_file,"header_only_short = %c\n",logical(header_only_short));
    fprintf(log_file,"header_only_long  = %c\n",logical(header_only_long));
    fprintf(log_file,"header_full       = %c\n",logical(header_full));
    fprintf(log_file,"header_filler     = %c\n",logical(header_filler));

    //------------------------------------------------------------------------------
    //  Check CRC
    //------------------------------------------------------------------------------
    // Calculate CRC for data stream
    if(dmb_wdcnt < 12) {    // should not ever get here
        fprintf(log_file,"TMB raw hits dump too short for crc calculation, exiting.\n");
        pause("TMB raw hits dump too short for crc calculation");
        header_ok=false;
        goto exit;
    }

    crc=0;
    for (iframe=0; iframe<=dmb_wdcnt-1; ++iframe) {
        din=vf_data[iframe];
        din=din & 0xFFFF;
        if(iframe==0) crc22a(din,crc,1);                // Reset crc
        crc22a(din,crc,0);                              // Calc  crc
        if(iframe==dmb_wdcnt-1-4) crc_calc=crc;         // Latch result prior to de0f marker beco ddu fails to process de0f frame
        dprintf(log_file,"%5i%6.5X%9.8X\n",iframe,din,crc);
    }

    // Compare our computed CRC to what TMB computed
    tmb_crc_lsb=vf_data[dmb_wdcnt-1-2] & 0x07FF;    // 11 crc bits per frame
    tmb_crc_msb=vf_data[dmb_wdcnt-1-1] & 0x07FF;    // 11 crc bits per frame

    tmb_crc=tmb_crc_lsb | (tmb_crc_msb << 11);      // Full 22 bit crc
    crc_match=crc_calc==tmb_crc;

    fprintf(log_file,"calc crc=%6.6X ",crc_calc);
    fprintf(log_file,"tmb crc=%6.6X ",tmb_crc);
    fprintf(log_file,"crc_match=%c\n",logical(crc_match));

    // CRC mismatch
    if(!crc_match) {
        header_ok=false;
        error_flag[6]=1;    // CRC error, embedded does not match calculated
        dprintf(log_file,"Expect vf_data[%i]=%5.5X\n",(dmb_wdcnt-1-2),((crc_calc>> 0) & 0x07FF));   
        dprintf(log_file,"Expect vf_data[%i]=%5.5X\n",(dmb_wdcnt-1-1),((crc_calc>>11) & 0x07FF));   
        pause ("TMB crc ERROR in decode_raw_hits, WTF!?");
    }

    //-------------------------------------------------------------------------------
    //  Unpack first 8 header frames, format is common to short, long, and full modes
    //-------------------------------------------------------------------------------
    // First 4 header words must conform to DDU specification
    iframe=0;
    boc=                (vf_data[iframe] >>  0) & 0xFFF;    // Beginning of Cathode record marker
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    iframe=1;
    pop_bxn_counter=    (vf_data[iframe] >>  0) & 0xFFF;    // Bxn pushed on L1A stack at L1A arrival
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    iframe=2;
    pop_l1a_rx_counter= (vf_data[iframe] >>  0) & 0xFFF;    // L1As received and pushed on L1A stack
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    iframe=3;
    readout_counter=    (vf_data[iframe] >>  0) & 0xFFF;    // Readout counter, same as l1a_rx_counter for now
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    // Next 4 words for short, long or full header modes
    iframe=4;
    board_id=           (vf_data[iframe] >>  0) & 0x1F;     // TMB module ID number = VME slot
    csc_id=             (vf_data[iframe] >>  5) & 0xF;      // Chamber ID number
    run_id=             (vf_data[iframe] >>  9) & 0xF;      // Run info
    h4_buf_q_ovf_err=   (vf_data[iframe] >> 13) & 0x1;      // Fence queue overflow error
    r_sync_err=         (vf_data[iframe] >> 14) & 0x1;      // BXN sync error
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=5;
    r_nheaders=         (vf_data[iframe] >>  0) & 0x3F;     // Number of header words
    fifo_mode=          (vf_data[iframe] >>  6) & 0x7;      // Trigger type and fifo mode
    r_type=             (vf_data[iframe] >>  9) & 0x3;      // Record type: dump,nodump, full header, short header
    l1a_type=           (vf_data[iframe] >> 11) & 0x3;      // L1A Pop type code: buffers, no buffers, clct/alct_only
    r_has_buf=          (vf_data[iframe] >> 13) & 0x1;      // Event has clct and rpc buffer data
    r_buf_stalled=      (vf_data[iframe] >> 14) & 0x1;      // Raw hits buffer was full at pretrigger
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=6;
    bd_status=          (vf_data[iframe] >>  0) & 0x7FFF;   // Board status summary
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=7;
    revcode=            (vf_data[iframe] >>  0) & 0x7FFF;   // Firmware version date code
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // Short header-only mode ends here, next 4 frames should be trailer
    if (header_only_short) goto unpack_trailer;

    //---------------------------------------------------------------------------------------
    //  Unpack frames 8-47 for long header-only mode or long header with full raw hits readout
    //----------------------------------------------------------------------------------------
    iframe=8;
    r_bxn_counter_ff=   (vf_data[iframe] >>  0) & 0xFFF;    // Full CLCT Bunch Crossing number at pretrig
    r_tmb_clct0_discard=(vf_data[iframe] >> 12) & 0x1;      // TMB discarded CLCT0 from ME1A
    r_tmb_clct1_discard=(vf_data[iframe] >> 13) & 0x1;      // TMB discarded CLCT1 from ME1A
    clock_lock_lost=    (vf_data[iframe] >> 14) & 0x1;      // Clock lock lost
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=9;
    r_pretrig_counter_lsb=(vf_data[iframe] >>  0) & 0x7FFF; // Counts CLCT pre-triggers [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=10;
    r_pretrig_counter_msb=(vf_data[iframe] >>  0) & 0x7FFF; // Counts CLCT pre-triggers [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=11;
    r_clct_counter_lsb= (vf_data[iframe] >>  0) & 0x7FFF;   // Counts CLCTs post-drift [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=12;
    r_clct_counter_msb= (vf_data[iframe] >>  0) & 0x7FFF;   // Counts CLCTs post-drift [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=13;
    r_trig_counter_lsb= (vf_data[iframe] >>  0) & 0x7FFF;   // Counts TMB triggers to MPC, L1A request to CCB,
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=14;
    r_trig_counter_msb= (vf_data[iframe] >>  0) & 0x7FFF;   // Counts TMB triggers to MPC, L1A request to CCB,
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=15;
    r_alct_counter_lsb= (vf_data[iframe] >>  0) & 0x7FFF;   // Counts ALCTs received from ALCT board [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=16;
    r_alct_counter_msb= (vf_data[iframe] >>  0) & 0x7FFF;   // Counts ALCTs received from ALCT board [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=17;
    r_orbit_counter_lsb=(vf_data[iframe] >>  0) & 0x7FFF;   // BX0s since last hard reset [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=18;
    r_orbit_counter_msb=(vf_data[iframe] >>  0) & 0x7FFF;   // BX0s since last hard reset [stops on ovf]
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // CLCT Raw Hits Size
    iframe=19;
    r_ncfebs=           (vf_data[iframe] >>  0) & 0x7;      // Number of CFEBs read out
    r_fifo_tbins=       (vf_data[iframe] >>  3) & 0x1F;     // Number of time bins per CFEB in dump
    fifo_pretrig=       (vf_data[iframe] >>  8) & 0x1F;     // # Time bins before pretrigger
    scope_data_exists=  (vf_data[iframe] >> 13) & 0x1;      // Readout includes logic analyzer scope data
    vme_data_exists=    (vf_data[iframe] >> 14) & 0x1;      // VME register dump in readout
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // CLCT Configuration
    iframe=20;
    hit_thresh_pretrig= (vf_data[iframe] >>  0) & 0x7;      // Hits on pattern template pre-trigger threshold
    pid_thresh_pretrig= (vf_data[iframe] >>  3) & 0xF;      // Pattern shape ID pre-trigger threshold
    hit_thresh_postdrf= (vf_data[iframe] >>  7) & 0x7;      // Hits on pattern post-drift threshold
    pid_thresh_postdrf= (vf_data[iframe] >> 10) & 0xF;      // Pattern shape ID post-drift threshold
    stagger_csc=        (vf_data[iframe] >> 14) & 0x1;      // CSC Staggering ON
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=21;
    triad_persist=      (vf_data[iframe] >>  0) & 0xF;      // CLCT Triad persistence
    dmb_thresh=         (vf_data[iframe] >>  4) & 0x7;      // DMB pre-trigger threshold for active-feb
    alct_delay=         (vf_data[iframe] >>  7) & 0xF;      // Delay ALCT for CLCT match window
    clct_window=        (vf_data[iframe] >> 11) & 0xF;      // CLCT match window width
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // CLCT Trigger Status
    iframe=22;
    r_trig_source_vec=  (vf_data[iframe] >>  0) & 0x1FF;    // Trigger source vector
    r_layers_hit=       (vf_data[iframe] >>  9) & 0x3F;     // CSC layers hit on layer trigger
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=23;
    r_active_feb_ff=    (vf_data[iframe] >>  0) & 0x1F;     // Active CFEB list sent to DMB
    r_febs_read=        (vf_data[iframe] >>  5) & 0x1F;     // CFEBs read out for this event
    r_l1a_match_win=    (vf_data[iframe] >> 10) & 0xF;      // Position of l1a in window
    active_feb_src=     (vf_data[iframe] >> 14) & 0x1;      // Active CFEB list source
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // CLCT+ALCT Match Status
    iframe=24;
    r_tmb_match=        (vf_data[iframe] >>  0) & 0x1;      // ALCT and CLCT matched in time, pushed on L1A stack
    r_tmb_alct_only=    (vf_data[iframe] >>  1) & 0x1;      // Only ALCT triggered, pushed on L1a stack
    r_tmb_clct_only=    (vf_data[iframe] >>  2) & 0x1;      // Only CLCT triggered, pushed on L1A stack
    r_tmb_match_win=    (vf_data[iframe] >>  3) & 0xF;      // Location of alct in clct window, pushed on L1A stack
    r_no_alct_tmb=      (vf_data[iframe] >>  7) & 0x1;      // No ALCT
    r_one_alct_tmb=     (vf_data[iframe] >>  8) & 0x1;      // One ALCT
    r_one_clct_tmb=     (vf_data[iframe] >>  9) & 0x1;      // One CLCT
    r_two_alct_tmb=     (vf_data[iframe] >> 10) & 0x1;      // Two ALCTs
    r_two_clct_tmb=     (vf_data[iframe] >> 11) & 0x1;      // Two CLCTs
    r_dupe_alct_tmb=    (vf_data[iframe] >> 12) & 0x1;      // ALCT0 copied into ALCT1 to make 2nd LCT
    r_dupe_clct_tmb=    (vf_data[iframe] >> 13) & 0x1;      // CLCT0 copied into CLCT1 to make 2nd LCT
    r_rank_err_tmb=     (vf_data[iframe] >> 14) & 0x1;      // LCT1 has higher quality than LCT0
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // CLCT Trigger Data
    iframe=25;
    r_clct0_tmb_lsb=    (vf_data[iframe] >>  0) & 0x7FFF;   // CLCT0 after drift lsbs
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=26;
    r_clct1_tmb_lsb=    (vf_data[iframe] >>  0) & 0x7FFF;   // CLCT1 after drift lsbs
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=27;
    r_clct0_tmb_msb=    (vf_data[iframe] >>  0) & 0x1;      // CLCT0 after drift msbs
    r_clct1_tmb_msb=    (vf_data[iframe] >>  1) & 0x1;      // CLCT1 after drift msbs
    r_clctc_tmb=        (vf_data[iframe] >>  2) & 0x7;      // CLCTC after drift
    r_clct0_invp=       (vf_data[iframe] >>  5) & 0x1;      // CLCT0 had invalid pattern after drift delay
    r_clct1_invp=       (vf_data[iframe] >>  6) & 0x1;      // CLCT1 had invalid pattern after drift delay
    r_clct1_busy=       (vf_data[iframe] >>  7) & 0x1;      // 2nd CLCT busy, logic error indicator
    perr_cfeb_ff=       (vf_data[iframe] >>  8) & 0x1F;     // CFEB parity error
    perr_rpc_ff=        (vf_data[iframe] >> 13) & 0x1;      // RPC  parity error
    perr_ff=            (vf_data[iframe] >> 14) & 0x1;      // Parity error summary
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // ALCT Trigger Data
    iframe=28;
    r_alct0_valid=      (vf_data[iframe] >>  0) & 0x1;      // ALCT0 valid pattern flag
    r_alct0_quality=    (vf_data[iframe] >>  1) & 0x3;      // ALCT0 quality
    r_alct0_amu=        (vf_data[iframe] >>  3) & 0x1;      // ALCT0 accelerator muon flag
    r_alct0_key=        (vf_data[iframe] >>  4) & 0x7F;     // ALCT0 key wire group
    r_alct_pretrig_win= (vf_data[iframe] >> 11) & 0xF;      // ALCT active_feb_flag position in pretrig window
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=29;
    r_alct1_valid=      (vf_data[iframe] >>  0) & 0x1;      // ALCT1 valid pattern flag
    r_alct1_quality=    (vf_data[iframe] >>  1) & 0x3;      // ALCT1 quality
    r_alct1_amu=        (vf_data[iframe] >>  3) & 0x1;      // ALCT1 accelerator muon flag
    r_alct1_key=        (vf_data[iframe] >>  4) & 0x7F;     // ALCT1 key wire group
    drift_delay=        (vf_data[iframe] >> 11) & 0x3F;     // CLCT drift delay
    res29=              (vf_data[iframe] >> 13) & 0x1;      // Free 1
    hs_layer_trig=      (vf_data[iframe] >> 14) & 0x1;      // Layer-mode trigger
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=30;
    r_alct_bxn=         (vf_data[iframe] >>  0) & 0x1F;     // ALCT0/1 bxn
    alct_seq_status=    (vf_data[iframe] >>  5) & 0x3;      // Sequencer status [undefined]
    alct_seu_status=    (vf_data[iframe] >>  7) & 0x3;      // Single-event-upset status [undefined]
    alct_reserved_out=  (vf_data[iframe] >>  9) & 0xF;      // Undefined
    alct_cfg_done=      (vf_data[iframe] >> 13) & 0x1;      // ALCT FPGA configuration done
    res30=              (vf_data[iframe] >> 14) & 0x1;      // Free 1
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // MPC Frames
    iframe=31;
    r_mpc0_frame0_lsb=  (vf_data[iframe] >>  0) & 0x7FFF;   // MPC muon 0 frame 0 LSBs
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=32;
    r_mpc0_frame1_lsb=  (vf_data[iframe] >>  0) & 0x7FFF;   // MPC muon 0 frame 1 LSBs
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=33;
    r_mpc1_frame0_lsb=  (vf_data[iframe] >>  0) & 0x7FFF;   // MPC muon 1 frame 0 LSBs
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=34;
    r_mpc1_frame1_lsb=  (vf_data[iframe] >>  0) & 0x7FFF;   // MPC muon 1 frame 1 LSBs
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=35;
    r_mpc0_frame0_msb=  (vf_data[iframe] >>  0) & 0x1;      // MPC muon 0 frame 0 MSB
    r_mpc0_frame1_msb=  (vf_data[iframe] >>  1) & 0x1;      // MPC muon 0 frame 1 MSB
    r_mpc1_frame0_msb=  (vf_data[iframe] >>  2) & 0x1;      // MPC muon 1 frame 0 MSB
    r_mpc1_frame1_msb=  (vf_data[iframe] >>  3) & 0x1;      // MPC muon 1 frame 1 MSB
    mpc_tx_delay=       (vf_data[iframe] >>  4) & 0xF;      // MPC transmit delay
    r_mpc_accept=       (vf_data[iframe] >>  8) & 0x3;      // MPC muon accept response
    cfeb_en=            (vf_data[iframe] >> 10) & 0x1F;     // CFEBs enabled for triggering
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // RPC Configuration
    iframe=36;
    rd_rpc_list=        (vf_data[iframe] >>  0) & 0x3;      // RPCs included in read out
    rd_nrpcs=           (vf_data[iframe] >>  2) & 0x3;      // Number of RPCs in readout, 0,1,2
    rpc_read_enable=    (vf_data[iframe] >>  4) & 0x1;      // RPC readout enabled
    fifo_tbins_rpc=     (vf_data[iframe] >>  5) & 0x1F;     // Number RPC FIFO time bins to read out
    fifo_pretrig_rpc=   (vf_data[iframe] >> 10) & 0x1F;     // Number RPC FIFO time bins before pretrigger
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // Buffer Status
    iframe=37;
    r_wr_buf_adr=       (vf_data[iframe] >>  0) & 0x7FF;    // Buffer RAM write address at pretrigger
    r_wr_buf_ready=     (vf_data[iframe] >> 11) & 0x1;      // Write buffer was ready at pretrig
    wr_buf_ready=       (vf_data[iframe] >> 12) & 0x1;      // Write buffer ready now
    buf_q_full=         (vf_data[iframe] >> 13) & 0x1;      // All raw hits ram in use, ram writing must stop
    buf_q_empty=        (vf_data[iframe] >> 14) & 0x1;      // No fences remain on buffer stack
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=38;
    r_buf_fence_dist=   (vf_data[iframe] >>  0) & 0x7FF;    // Distance to 1st fence address at pretrigger
    buf_q_ovf_err=      (vf_data[iframe] >> 11) & 0x1;      // Tried to push when stack full
    buf_q_udf_err=      (vf_data[iframe] >> 12) & 0x1;      // Tried to pop when stack empty
    buf_q_adr_err=      (vf_data[iframe] >> 13) & 0x1;      // Fence adr popped from stack doesnt match rls adr
    buf_stalled=        (vf_data[iframe] >> 14) & 0x1;      // Buffer write pointer hit a fence and stalled
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // Spare Frames
    iframe=39;
    buf_fence_cnt=      (vf_data[iframe] >>  0) & 0xFFF;    // Number of fences in fence RAM currently
    reverse_hs_csc=     (vf_data[iframe] >> 12) & 0x1;      // 1=Reverse staggered CSC, non-me1
    reverse_hs_me1a=    (vf_data[iframe] >> 13) & 0x1;      // 1=ME1A hstrip order reversed
    reverse_hs_me1b=    (vf_data[iframe] >> 14) & 0x1;      // 1=ME1B hstrip order reversed
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=40;
    buf_fence_cnt_peak= (vf_data[iframe] >>  0) & 0xFFF;    // Peak number of fences in fence RAM
    r_trig_source_vec9= (vf_data[iframe] >> 12) & 0x1;      // Pre-trigger was ME1A only
    r_trig_source_vec10=(vf_data[iframe] >> 13) & 0x1;      // Pre-trigger was ME1B only
    tmb_trig_pulse=     (vf_data[iframe] >> 14) & 0x1;      // TMB trig pulse
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=41;
    tmb_allow_alct=     (vf_data[iframe] >>  0) & 0x1;      // Allow ALCT-only  tmb-matching
    tmb_allow_clct=     (vf_data[iframe] >>  1) & 0x1;      // Allow CLCT-only  tmb-matching
    tmb_allow_match=    (vf_data[iframe] >>  2) & 0x1;      // Allow Match-only tmb-matching
    tmb_allow_alct_ro=  (vf_data[iframe] >>  3) & 0x1;      // Allow ALCT-only  tmb-matching, nontrig readout
    tmb_allow_clct_ro=  (vf_data[iframe] >>  4) & 0x1;      // Allow CLCT-only  tmb-matching, nontrig readout
    tmb_allow_match_ro= (vf_data[iframe] >>  5) & 0x1;      // Allow Match-only tmb-matching, nontrig readout
    tmb_alct_ro=        (vf_data[iframe] >>  6) & 0x1;      // Allow ALCT-only  tmb-matching, nontrig readout
    tmb_clct_ro=        (vf_data[iframe] >>  7) & 0x1;      // Allow CLCT-only  tmb-matching, nontrig readout
    tmb_match_ro=       (vf_data[iframe] >>  8) & 0x1;      // Allow Match-only tmb-matching, nontrig readout
    tmb_trig_keep=      (vf_data[iframe] >>  9) & 0x1;      // Triggering readout
    tmb_nontrig_keep=   (vf_data[iframe] >> 10) & 0x1;      // Non-triggering readout
    lyr_thresh_pretrig= (vf_data[iframe] >> 11) & 0x7;      // Layer pre-trigger threshold
    layer_trig_en=      (vf_data[iframe] >> 14) & 0x1;      // Layer-trigger mode enabled
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // EOB marker
    iframe=42;
    eob=                (vf_data[iframe] >>  0) & 0x7FFF;   // EOB
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    // EOC marker
    iframe=last_frame-6;
    eoc=                (vf_data[iframe] >>  0) & 0x7FFF;
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    //------------------------------------------------------------------------------
    // Unpack optional 2 filler frames to make word count a multiple of 4
    //------------------------------------------------------------------------------
    iframe=last_frame-5;
    opt2aaa=            (vf_data[iframe] >>  0) & 0x7FFF;
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    iframe=last_frame-4;
    opt5555=            (vf_data[iframe] >>  0) & 0x7FFF;
    ddu[iframe]=        (vf_data[iframe] >> 15) & 0x1;      // DDU special

    //------------------------------------------------------------------------------
    //  Unpack trailer frames: Last 4 trailer words must conform to DDU specification
    //------------------------------------------------------------------------------
unpack_trailer:

    iframe=last_frame-3;
    eof=                (vf_data[iframe] >>  0) & 0xFFF;
    lctype3=            (vf_data[iframe] >> 11) & 0x1;
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    iframe=last_frame-2;
    crc22lsb=           (vf_data[iframe] >>  0) & 0x7FF;
    lctype2=            (vf_data[iframe] >> 11) & 0x1;
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    iframe=last_frame-1;
    crc22msb=           (vf_data[iframe] >>  0) & 0x7FF;
    lctype1=            (vf_data[iframe] >> 11) & 0x1;
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    iframe=last_frame;
    frame_cnt=          (vf_data[iframe] >>  0) & 0x7FF;
    lctype0=            (vf_data[iframe] >> 11) & 0x1;
    ddu[iframe]=        (vf_data[iframe] >> 12) & 0xF;      // DDU special

    //------------------------------------------------------------------------------
    // Check DDU frame structure
    //------------------------------------------------------------------------------
    // First frame must be DB0C marker
    iframe=0;
    if ((vf_data[iframe]&0xFFFF)!=0xDB0C) {
        header_ok=false; 
        error_flag[7]=1;        // First frame missing 0xDB0C marker
        fprintf(log_file,"Err: Expected 0xDB0C marker in vf_data[%i], found %5.5X\n",iframe,vf_data[iframe]);
    }

    // First 4 frames must have DDU special D-code set
    for (iframe=0; iframe<=3; ++iframe) {
        if (ddu[iframe]!=0xD) {
            header_ok=false; 
            error_flag[8]=1;        // First 4 frames do not have DDU-special codes
            fprintf(log_file,"Err: Expected DDU special code in vf_data[%iframe], found %5.5X\n",iframe,vf_data[iframe]);
        }}

    // Last 4 frames must have DDU special D-code set
    for (iframe=last_frame-3; iframe<=last_frame; ++iframe) {
        if (ddu[iframe]!=0xD) {
            header_ok=false;
            error_flag[9]=1;        // Last 4 frames do not have DDU-special codes
        }}

    // Last frame-3 must be EEF for short header or E0F for long header
    if (header_only_short) {
        if (eof != 0xEEF) {
            header_ok=false;
            error_flag[10]=1;   // Last frame-3 missing EEF marker
            fprintf(log_file,"Err: Expected EEF at vf_data[%i], found %3.3X\n",last_frame-3,eof);
        }}
    else {
        if (eof != 0xE0F) {
            header_ok=false;
            error_flag[11]=1;   // Last frame-3 missing E0F marker
            fprintf(log_file,"Err: Expected EOF at vf_data[%i], found %3.3X\n",last_frame-3,eof);
        }}

    // Last 4 frames must set bit 11 ==1, its implied in EEF/EOF markers in last_frame-3
    if ((lctype0 != 1) || (lctype1 != 1) || (lctype2 != 1) || (lctype3 != 1)) {
        header_ok=false;
        error_flag[12]=1;   // Last 4 frames missing bit[11]=1
        fprintf(log_file,"Err: Expected bit11=1 in last 4 frames, found %i%i%i%i\n",lctype0,lctype1,lctype2,lctype3);
    }

    //------------------------------------------------------------------------------
    // Unpack event format codes from first 8 frames
    //------------------------------------------------------------------------------
    // CLCT fifo mode
    sfifo_mode           = "Undefined////          ";
    switch (fifo_mode) {
        case 0x0: sfifo_mode = "Dump=No    Header=Full "; break;
        case 0x1: sfifo_mode = "Dump=Full  Header=Full "; break;
        case 0x2: sfifo_mode = "Dump=Local Header=Full "; break;
        case 0x3: sfifo_mode = "Dump=No    Header=Short"; break;
        case 0x4: sfifo_mode = "Dump=No    Header=No   "; break;
        case 0x5: sfifo_mode = "Undefined////          "; break;
        case 0x6: sfifo_mode = "Undefined////          "; break;
        case 0x7: sfifo_mode = "Undefined////          "; break;
    }

    // Raw hits dump mode
    sr_type              = "Undefined////          ";
    switch (r_type) {
        case 0x0: sr_type    = "Dump=No    Header=Full "; break;
        case 0x1: sr_type    = "Dump=Full  Header=Full "; break;
        case 0x2: sr_type    = "Dump=Local Header=Full "; break;
        case 0x3: sr_type    = "Dump=No    Header=Short"; break;
    }

    // Raw hits buffer state
    sl1a_type            = "Undefined////                 ";
    switch (l1a_type) {
        case 0x0: sl1a_type  = "Buffer=yes CLCT trig+L1A match"; break;
        case 0x1: sl1a_type  = "Buffer=no  ALCT trig          "; break;
        case 0x2: sl1a_type  = "Buffer=no  L1A  only          "; break;
        case 0x3: sl1a_type  = "Buffer=yes TMB  trigg no L1A  "; break;
    }

    // Firmware revcode
    id_rev          = revcode;
    id_rev_day      = (id_rev >>  0) & 0x001F;
    id_rev_month    = (id_rev >>  5) & 0x000F;
    id_rev_year     = (id_rev >>  9) & 0x000F;
    id_rev_fpga     = (id_rev >> 13) & 0x0007;
    id_rev_fpga     = id_rev_fpga+2;

    // TMB board hardware status summary
    for (i=0; i<=14; ++i) {
        bd_status_vec[i]=(bd_status >> i) & 0x1;
    }

    // CSC type
    scsc_type_inferred = "Indeterminate";

    if(header_only_short) {
        fprintf(log_file,"Header inferred CSC Type=%s\n",scsc_type_inferred.c_str());
        goto check_types;
    }

    if (stagger_csc     == 1    &&
            reverse_hs_csc  == 0    &&
            reverse_hs_me1a == 0    &&
            reverse_hs_me1b == 0) scsc_type_inferred = "Normal";

    if (stagger_csc     == 1    &&
            reverse_hs_csc  == 1    &&
            reverse_hs_me1a == 0    &&
            reverse_hs_me1b == 0) scsc_type_inferred = "Normal_Reverse";

    if (stagger_csc     == 0    &&
            reverse_hs_csc  == 0    &&
            reverse_hs_me1a == 1    &&
            reverse_hs_me1b == 0) scsc_type_inferred = "ME1A_Reverse_ME1B_Normal";

    if (stagger_csc     == 0    &&
            reverse_hs_csc  == 0    &&
            reverse_hs_me1a == 0    &&
            reverse_hs_me1b == 1) scsc_type_inferred = "ME1A_Normal_ME1B_Reverse";

    fprintf(log_file,"Header inferred CSC Type=%s\n",scsc_type_inferred.c_str());

    //------------------------------------------------------------------------------
    // Check event type codes match actual header size
    //------------------------------------------------------------------------------
check_types:

    if(header_only_short) {
        if (fifo_mode!=0x3) {
            header_ok=false;
            error_flag[13]=1;   // Fifo mode does not match short header format
            fprintf(log_file,"Err: fifo_mode does not match short header format %i%i\n",fifo_mode,header_only_short);
        }
        if (r_type!=0x3) {
            header_ok=false;
            error_flag[14]=1;   // Record type does not match short header format
            fprintf(log_file,"Err: r_type does not match short header format %i%i\n",r_type,header_only_short);
        }}

    if(header_only_long || header_full) {
        if (!((fifo_mode==0x0) || (fifo_mode==0x1) || (fifo_mode==0x2))) {
            header_ok=false;
            error_flag[15]=1;   // Fifo mode does not match long header format
            fprintf(log_file,"Err: fifo_mode does not match long header format %i%i\n",fifo_mode,header_only_short);
        }}

    if(header_only_long) {
        if (r_type!=0x0) {
            header_ok=false;
            error_flag[16]=1;   // Record type does not match long header format
            fprintf(log_file,"Err: r_type does not match long header format %i%i\n",r_type,header_only_short);
        }}

    if(header_full) {
        if ((r_type!=0x1) || (r_type!=0x2)) {
            header_ok=false;
            error_flag[17]=1;   // Record type does not match full header format
            fprintf(log_file,"Err: r_type does not match full header format %i%i\n",r_type,header_only_short);
        }}

    //------------------------------------------------------------------------------
    // Check word count matches expected, assumes mode 1 full readout for now
    //------------------------------------------------------------------------------
    fifo_cfeb_enable        = 0; 
    frame_cntex_ntbins      = 0;
    frame_cntex_b0ce0c      = 0;
    frame_cntex_rpc         = 0;
    frame_cntex_b04e04      = 0;
    frame_cntex_scope       = 0;
    frame_cntex_b05e05      = 0;

    frame_cntex_nheaders    = r_nheaders;                                   // Expected Header words
    fifo_cfeb_enable        = ((fifo_mode==1) || (fifo_mode==2)) && ((r_type==1) || (r_type==2));  // CLCT raw hits exist

    if(header_only_long) {
        frame_cntex_b0ce0c      = 2;                                            // Expected EOB, EOC markers
    }

    if(header_full) {                                                       // Raw hits are only in full readout mode
        frame_cntex_ntbins      = 6*r_fifo_tbins*r_ncfebs;                      // Expected CFEB tbins
        frame_cntex_b0ce0c      = 2;                                            // Expected EOB, EOC markers
        frame_cntex_rpc         = (rd_nrpcs*fifo_tbins_rpc*2)*rpc_read_enable;  // Expected RPC  tbins
        frame_cntex_b04e04      = 2*rpc_read_enable;                            // Expected RPC  B04/E04 markers
        frame_cntex_scope       = ((scp_tbins+1)*64*160/16)*scope_data_exists;  // Expected scope data
        frame_cntex_b05e05      = 2*scope_data_exists;                          // Expected scope B05/E05 markers
    }

    frame_cnt_expect=                                   // Expected frames before trailer
        frame_cntex_nheaders
        +frame_cntex_ntbins
        +frame_cntex_b0ce0c
        +frame_cntex_rpc
        +frame_cntex_b04e04
        +frame_cntex_scope
        +frame_cntex_b05e05;

    frame_cntex_fill=0;                                 // Insert fillers if frames not multiple of 4
    if((frame_cnt_expect%4) != 0)frame_cntex_fill=2;
    if(frame_cntex_fill!=0) header_filler=true;

    frame_cntex_trailer=4;                              // Add 4 trailer words

    frame_cnt_expect=
        frame_cnt_expect
        +frame_cntex_fill
        +frame_cntex_trailer;   

    frame_cnt_expect_trun=frame_cnt_expect & 0x07FF;    // Trailer word count is truncated to 11 bits
    dmb_wdcnt_trun=dmb_wdcnt & 0x07FF;

    if((frame_cnt_expect/4)*4 != frame_cnt_expect)      // Check we are still mod 4 happy
        pause ("expected frame count not mod 4..wtf?");

    fprintf(log_file,"Expected header        frames   =%5i\n",frame_cntex_nheaders);
    fprintf(log_file,"Expected cfeb  tbins   frames   =%5i\n",frame_cntex_ntbins);
    fprintf(log_file,"Expected cfeb  e0b/e0c frames   =%5i\n",frame_cntex_b0ce0c);
    fprintf(log_file,"Expected rpc   tbins   frames   =%5i\n",frame_cntex_rpc);
    fprintf(log_file,"Expected rpc   b04e04  frames   =%5i\n",frame_cntex_b04e04);
    fprintf(log_file,"Expected scope data    frames   =%5i\n",frame_cntex_scope);
    fprintf(log_file,"Expected scope b05e05  frames   =%5i\n",frame_cntex_b05e05);
    fprintf(log_file,"Expected filler        frames   =%5i\n",frame_cntex_fill);
    fprintf(log_file,"Expected trailer       frames   =%5i\n",frame_cntex_trailer);

    fprintf(log_file,"Expected frame count from header=%5i\n",frame_cnt_expect);
    fprintf(log_file,"Frame count stored in trailer   =%5i\n",frame_cnt);
    fprintf(log_file,"Frame count from DMB RAM        =%5i\n",dmb_wdcnt);

    if((dmb_wdcnt_trun==frame_cnt)&&(frame_cnt==frame_cnt_expect_trun))
        fprintf(log_file,"Frame count OK %5i\n",frame_cnt);
    else {
        header_ok=false;
        error_flag[18]=1;   // Expected frame count does not match actual frame count
        fprintf(log_file,"Err: Bad frame count: read=%5i expect=%5i\n",frame_cnt,frame_cnt_expect_trun);
        fprintf(stderr,  "Err: Bad frame count: read=%5i expect=%5i\n",frame_cnt,frame_cnt_expect_trun);
    }

    //------------------------------------------------------------------------------
    // Construct CLCT, RPC, and Scope pointers
    // Do not just scan for the markers, because they are not unique
    //------------------------------------------------------------------------------
    adr_b0c =  0;               // All formats start with b0c
    adr_e0b = -1;               // Short or long header-only events do not have these markers
    adr_b04 = -1;
    adr_e04 = -1;
    adr_b05 = -1;
    adr_e05 = -1;
    adr_e0c = -1;
    adr_fil = -1;
    adr_e0f = dmb_wdcnt-4;      // All formats have e0f or eef near the end

    if (!header_only_short) {   // Long and full have markers
        adr_e0b = r_nheaders;
        adr_b04 = (rpc_read_enable  ==1) ? (adr_e0b+frame_cntex_ntbins ) : -1;
        adr_e04 = (rpc_read_enable  ==1) ? (adr_b04+frame_cntex_rpc    ) : -1;
        adr_b05 = (scope_data_exists==1) ? (adr_e0b+frame_cntex_ntbins+frame_cntex_rpc+frame_cntex_b04e04+1) : -1;
        adr_e05 = (scope_data_exists==1) ? (adr_b05+frame_cntex_scope+1) : -1;
        adr_e0c = adr_e0b+frame_cntex_ntbins+frame_cntex_rpc+frame_cntex_b04e04+frame_cntex_scope+frame_cntex_b05e05+1;
        adr_fil = (frame_cntex_fill !=0) ? (frame_cnt_expect-6         ) : -1;
    }

    //------------------------------------------------------------------------------
    // Check that markers and filler frames exist at the predicted locations
    //------------------------------------------------------------------------------
    fprintf(log_file,"adr_b0c=%5i",adr_b0c); if(adr_b0c!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_b0c]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_e0b=%5i",adr_e0b); if(adr_e0b!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_e0b]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_b04=%5i",adr_b04); if(adr_b04!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_b04]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_e04=%5i",adr_e04); if(adr_e04!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_e04]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_b05=%5i",adr_b05); if(adr_b05!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_b05]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_e05=%5i",adr_e05); if(adr_e05!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_e05]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_e0c=%5i",adr_e0c); if(adr_e0c!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_e0c]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_fil=%5i",adr_fil); if(adr_fil!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_fil]); fprintf(log_file,"\n");
    fprintf(log_file,"adr_e0f=%5i",adr_e0f); if(adr_e0f!=-1)fprintf(log_file," data=%4.4X",vf_data[adr_e0f]); fprintf(log_file,"\n");

    // Check E0B
    if ((adr_e0b>0) && ((vf_data[adr_e0b]&0xFFFF)!=0x6E0B)) {
        header_ok=false;
        error_flag[19]=1;   // E0B marker not found at expected address
        fprintf(log_file,"\n");
    }

    // Check B04
    if ((adr_b04>0) && ((vf_data[adr_b04]&0xFFFF)!=0x6B04)) {
        header_ok=false;
        error_flag[20]=1;   // B04 marker not found at expected address
        fprintf(log_file,"Err: B04 marker not found at expected address\n");
    }

    // Check E04
    if ((adr_e04>0) && ((vf_data[adr_e04]&0xFFFF)!=0x6E04)) {
        header_ok=false;
        error_flag[21]=1;   // E04 marker not found at expected address
        fprintf(log_file,"Err: E04 marker not found at expected address\n");
    }

    // Check B05
    if ((adr_b05>0) && ((vf_data[adr_b05]&0xFFFF)!=0x6B05)) {
        header_ok=false;
        error_flag[22]=1;   // B05 marker not found at expected address
        fprintf(log_file,"Err: B05 marker not found at expected address\n");
    }

    // Check E05
    if ((adr_e05>0) && ((vf_data[adr_e05]&0xFFFF)!=0x6E05)) {
        header_ok=false;
        error_flag[23]=1;   // E05 marker not found at expected address
        fprintf(log_file,"Err: E05 marker not found at expected address\n");
    }

    // Check E0C
    if ((adr_e0c>0) && ((vf_data[adr_e0c]&0xFFFF)!=0x6E0C)) {
        header_ok=false;
        error_flag[24]=1;   // E0C marker not found at expected address
        fprintf(log_file,"Err: E0C marker not found at expected address\n");
    }

    // Check filler 02AAA 05555
    if ((adr_fil>0) && ((vf_data[adr_fil]&0xFFFF)!=0x2AAA)) {
        header_ok=false;
        error_flag[25]=1;   // 2AAA filler not found at expected address
        fprintf(log_file,"Err: Filler frame 0x2AAA not found at expected address\n");
    }

    if ((adr_fil>0) && ((vf_data[adr_fil+1]&0xFFFF)!=0x5555)) {
        header_ok=false;
        error_flag[26]=1;   // 5555 filler not found at expected address
        fprintf(log_file,"Err: Filler frame 0x5555 not found at expected address\n");
    }

    //------------------------------------------------------------------------------
    // Check TMB hardware status
    //------------------------------------------------------------------------------
    bd_status_expect[ 0]=1;     // bd_status_ok
    bd_status_expect[ 1]=1;     // vstat_5p0vs
    bd_status_expect[ 2]=1;     // vstat_3p3v
    bd_status_expect[ 3]=1;     // vstat_1p8v
    bd_status_expect[ 4]=1;     // vstat_1p5v
    bd_status_expect[ 5]=1;     // _t_crit
    bd_status_expect[ 6]=1;     // vsm_ok
    bd_status_expect[ 7]=0;     // vsm_aborted
    bd_status_expect[ 8]=1;     // vsm_cksum_ok
    bd_status_expect[ 9]=1;     // vsm_wdcnt_ok
    bd_status_expect[10]=1;     // jsm_ok
    bd_status_expect[11]=0;     // jsm_aborted
    bd_status_expect[12]=1;     // jsm_cksum_ok
    bd_status_expect[13]=1;     // jsm_wdcnt_ok
    bd_status_expect[14]=1;     // sm_tck_fpga_ok

    for (i=0; i<MXSTAT; ++i) {
        if(bd_status_vec[i]!=bd_status_expect[i]) {
            header_ok=false;
            error_flag[27]=1;
            fprintf(log_file,"ERR: Bad board status %s=%i expected=%i\n",bd_status_msg[i].c_str(),bd_status_vec[i],bd_status_expect[i]);
        }}

    //------------------------------------------------------------------------------
    // Check sync error, requires long header for clct and mpc sync check
    //------------------------------------------------------------------------------
    if (header_only_short) {
        clctc_sync=0;
        mpc_sync_err0=0;
        mpc_sync_err1=0;
    }

    if  ((r_sync_err    !=0) ||
            (clctc_sync !=0) ||
            (mpc_sync_err0  !=0) ||
            (mpc_sync_err1  !=0))
    {
        error_flag[28]=1;
        fprintf(log_file,"ERR: Clock bx0 sync error: r_sync_err=%i clctc_sync=%i mpc_sync_err0=%i mpc_sync_err1=%i\n",
                r_sync_err,clctc_sync,mpc_sync_err0,mpc_sync_err1);
    }

    if (header_only_short) goto display_header;

    //------------------------------------------------------------------------------
    // Check buffer parity error SEU status, requires long header
    //------------------------------------------------------------------------------
    if ((perr_cfeb_ff!=0) || (perr_rpc_ff!=0) || (perr_ff!=0)) {
        header_ok=false;
        error_flag[29]=1;
        fprintf(log_file,"ERR: RAM SEU parity error: cfeb=%X rpc=%X sum=%X\n",perr_cfeb_ff,perr_rpc_ff,perr_ff);
    }

    //------------------------------------------------------------------------------
    // Check buffer status, requires long header
    //------------------------------------------------------------------------------
    /*
    // Buffer Status
    iframe=37;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_wr_buf_adr       = %4.3X\n",    r_wr_buf_adr);
    fprintf(log_file,"r_wr_buf_ready     = %4.1X\n",    r_wr_buf_ready);
    fprintf(log_file,"wr_buf_ready       = %4.1X\n",    wr_buf_ready);
    fprintf(log_file,"buf_q_full         = %4.1X\n",    buf_q_full);
    fprintf(log_file,"buf_q_empty        = %4.1X\n",    buf_q_empty);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=38;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_buf_fence_dist   = %4.3X%5i\n", r_buf_fence_dist,r_buf_fence_dist);
    fprintf(log_file,"buf_q_ovf_err      = %4.1X\n",    buf_q_ovf_err);
    fprintf(log_file,"buf_q_udf_err      = %4.1X\n",    buf_q_udf_err);
    fprintf(log_file,"buf_q_adr_err      = %4.1X\n",    buf_q_adr_err);
    fprintf(log_file,"buf_stalled        = %4.1X\n",    buf_stalled);

*/
    //------------------------------------------------------------------------------
    // Unpack Long header event counters
    //------------------------------------------------------------------------------
    // Long header counters
    pretrig_counter = r_pretrig_counter_lsb | (r_pretrig_counter_msb << 15);
    clct_counter    = r_clct_counter_lsb    | (r_clct_counter_msb    << 15);
    trig_counter    = r_trig_counter_lsb    | (r_trig_counter_msb    << 15);
    alct_counter    = r_alct_counter_lsb    | (r_alct_counter_msb    << 15);
    uptime_counter  = r_orbit_counter_lsb   | (r_orbit_counter_msb   << 15);

    uptime_sec=int(float(lhc_cycle)*float(uptime_counter)*25.0e-09);

    //------------------------------------------------------------------------------
    // Decode LCTs
    //------------------------------------------------------------------------------
    // Decode CLCT0 Word
    clct0=r_clct0_tmb_lsb | (r_clct0_tmb_msb >> 15);        //Reassemble to full 16 bits

    clct0_vpf=  (clct0 >>  0) & 0x1;    // Valid pattern flag
    clct0_nhit= (clct0 >>  1) & 0x7;    // Hits on pattern 0-6
    clct0_pat=  (clct0 >>  4) & 0xF;    // Pattern shape 0-A
    clct0_key=  (clct0 >>  8) & 0x1F;   // 1/2-strip ID number
    clct0_cfeb= (clct0 >> 13) & 0x7;

    clct0_fullkey=clct0_key+32*clct0_cfeb;

    // Decode CLCT1 Word
    clct1=r_clct1_tmb_lsb | (r_clct1_tmb_msb >> 15);        //Reassemble to full 16 bits

    clct1_vpf  = (clct1 >>  0) & 0x1;  // Valid pattern flag
    clct1_nhit = (clct1 >>  1) & 0x7;  // Hits on pattern
    clct1_pat  = (clct1 >>  4) & 0xF;  // Pattern shape 0-A
    clct1_key  = (clct1 >>  8) & 0x1F; // 1/2-strip ID number
    clct1_cfeb = (clct1 >> 13) & 0x7;

    clct1_fullkey=clct1_key+32*clct1_cfeb;

    // Decode CLCT common data
    clctc=r_clctc_tmb;
    clctc_bxn=  (clctc >>   0) & 0x3;
    clctc_sync= (clctc >>   2) & 0x1;   // Sync error  // was negative shifted ?? 

    // Decode MPC Frames
    mu0fr0=r_mpc0_frame0_lsb | (r_mpc0_frame0_msb >> 15);   //Reassemble to full 16 bits
    mu0fr1=r_mpc0_frame1_lsb | (r_mpc0_frame1_msb >> 15);
    mu1fr0=r_mpc1_frame0_lsb | (r_mpc1_frame0_msb >> 15);
    mu1fr1=r_mpc1_frame1_lsb | (r_mpc1_frame1_msb >> 15);

    mpc_alct0_key       =   (mu0fr0 >>   0) & 0x007F;
    mpc_clct0_pat       =   (mu0fr0 >>   7) & 0x000F; // was negative shifted ?? 
    mpc_lct0_quality    =   (mu0fr0 >>  11) & 0x000F; // was negative shifted ??   
    mpc_lct0_vpf        =   (mu0fr0 >>  15) & 0x0001; // was negative shifted ??   
                                                        
    mpc_clct0_key       =   (mu0fr1 >>   0) & 0x00FF;   
    mpc_clct0_bend      =   (mu0fr1 >>   8) & 0x0001; // was negative shifted ??   
    mpc_sync_err0       =   (mu0fr1 >>   9) & 0x0001; // was negative shifted ??   
    mpc_alct0_bxn       =   (mu0fr1 >>  10) & 0x0001; // was negative shifted ??   
    mpc_bx0_clct        =   (mu0fr1 >>  11) & 0x0001; // was negative shifted ??   
    mpc_csc_id0         =   (mu0fr1 >>  12) & 0x000F; // was negative shifted ??   
                                                        
    mpc_alct1_key       =   (mu1fr0 >>   0) & 0x007F; 
    mpc_clct1_pat       =   (mu1fr0 >>   7) & 0x000F; // was negative shifted ??   
    mpc_lct1_quality    =   (mu1fr0 >>  11) & 0x000F; // was negative shifted ??   
    mpc_lct1_vpf        =   (mu1fr0 >>  15) & 0x0001; // was negative shifted ??   
                                                        
    mpc_clct1_key       =   (mu1fr1 >>   0) & 0x00FF; 
    mpc_clct1_bend      =   (mu1fr1 >>   8) & 0x0001; // was negative shifted ??   
    mpc_sync_err1       =   (mu1fr1 >>   9) & 0x0001; // was negative shifted ??   
    mpc_alct1_bxn       =   (mu1fr1 >>  10) & 0x0001; // was negative shifted ??   
    mpc_bx0_alct        =   (mu1fr1 >>  11) & 0x0001; // was negative shifted ??   
    mpc_csc_id1         =   (mu1fr1 >>  12) & 0x000F; // was negative shifted ??   

    //------------------------------------------------------------------------------
    // Check if header LCT matches CLCT and ALCT from header
    //------------------------------------------------------------------------------
    // CLCT0 key
    if (clct0_fullkey != mpc_clct0_key) { 
        header_ok=false;
        error_flag[30]=1;   // CLCT0 key does not match LCT0
        fprintf(log_file,"Err: CLCT0 key does not match LCT0: clct0_fullkey=%i mpc_clct0_key=%i\n",clct0_fullkey,mpc_clct0_key);
    }

    // CLCT0 pattern ID
    if (clct0_pat != mpc_clct0_pat) { 
        header_ok=false;
        error_flag[31]=1;   // CLCT0 pattern ID does not match LCT0
        fprintf(log_file,"Err: CLCT0 pattern ID does not match LCT0: clct0_pat=%1X mpc_clct0_pat=%1X\n",clct0_pat,mpc_clct0_pat);
    }

    // ALCT0 key
    if (r_alct0_key != mpc_alct0_key) { 
        header_ok=false;
        error_flag[32]=1;   // ALCT0 key does not match LCT0
        fprintf(log_file,"Err: ALCT0 key does not match LCT0: r_alct0_key=%1X mpc_alct0_key=%i\n",r_alct0_key,mpc_alct0_key);
    }

    // CLCT1 key
    if (clct1_fullkey != mpc_clct1_key) { 
        header_ok=false;
        error_flag[33]=1;   // CLCT1 key does not match LCT1
        fprintf(log_file,"Err: CLCT1 key does not match LCT1: clct1_fullkey=%i mpc_clct1_key=%i\n",clct1_fullkey,mpc_clct1_key);
    }

    // CLCT1 pattern ID
    if (clct1_pat != mpc_clct1_pat) { 
        header_ok=false;
        error_flag[34]=1;   // CLCT1 pattern ID does not match LCT1
        fprintf(log_file,"Err: CLCT1 pattern ID does not match LCT1: clct1_pat=%1X mpc_clct1_pat=%1X\n",clct1_pat,mpc_clct1_pat);
    }

    // ALCT1 key
    if (r_alct1_key != mpc_alct1_key) { 
        header_ok=false;
        error_flag[35]=1;   // ALCT1 key does not match LCT1
        fprintf(log_file,"Err: ALCT1 key does not match LCT1: r_alct1_key=%1X mpc_alct1_key=%i\n",r_alct1_key,mpc_alct1_key);
    }

    //------------------------------------------------------------------------------
    // Check if LCT header data matches VME latched data
    //------------------------------------------------------------------------------
    /*  call ck('clct0 header',clct0,clct0_vme)
        call ck('clct1 header',clct1,clct1_vme)
        call ck('clctc header',clctc,clctc_vme)

    // Check if lct bxn matches header bxn
    clctc_bxn_vme   = ishft(clctc_vme,-0).and.'0003'x   // Bunch crossing number
    clctc_bxn_header= r_bxn_counter_ff.and.'0003'x
    write(2,'(5z9.8)')
    1 clctc_vme,clctc_bxn_vme,r_bxn_counter_ff,
    1 clctc_bxn_header,pop_bxn_counter

    call ck('clctc lctvmebxn, headerbxn',clctc_bxn_vme,clctc_bxn_header)

    // Check if MPC header matches LCTs and VME
    call ck('mpc0fr0 header vs vme',mu0fr0,mu0fr0_vme)
    call ck('mpc0fr1 header vs vme',mu0fr1,mu0fr1_vme)
    call ck('mpc1fr0 header vs vme',mu1fr0,mu1fr0_vme)
    call ck('mpc1fr1 header vs vme',mu1fr1,mu1fr1_vme)

    // Check for sequential level 1 accept event numbers, first l1a may not be 1 beco offset
    if(first_event)then
    l1a_rxcount_save=pop_l1a_rx_counter-1   
    first_event=.false.
    end if

    l1a_rxexpect=mod(l1a_rxcount_save+1,4096)
    call ck('l1a rxcount  ',trig_counter,l1a_rxexpect)
    call ck('l1a rxtxcount',trig_counter,pop_l1a_rx_counter)
    l1a_rxcount_save=pop_l1a_rx_counter

    d   write(6,'(1x,a,2i5)') 'l1a rx,tx=',l1a_rxcount,l1a_txcount
    */
    //------------------------------------------------------------------------------
    // Check active_feb list is as expected
    //------------------------------------------------------------------------------
    // Construct expected active_feb from 1st and 2nd clcts
    /*  active_febs_expect=0
        adjcfeb_dist=5
        csc_me1ab=0
        if(stagger_csc.eq.0)csc_me1ab=1

        if(clct0_vpf.eq.1)then

        if(reverse_hs_me1b.eq.0)    
        1active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb)       //cfebn was hit

        if(reverse_hs_me1b.eq.1.and.clct0_fullkey.le.127)   
        1active_febs_expect=active_febs_expect.or.ishft(1,3-clct0_cfeb)     //cfebn was hit
        if(reverse_hs_me1b.eq.1.and.clct0_fullkey.ge.128)   
        1active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb)       //cfebn was hit

        if(csc_me1ab.eq.0) then //normal csc
        if(clct0_key.lt.adjcfeb_dist.and.clct0_cfeb.ne.0) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb-1)    //cfebn-1 was hit
        if(clct0_key.gt.31-adjcfeb_dist.and.clct0_cfeb.ne.4) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb+1)    //cfebn+1 was hit

        else if(csc_me1ab.eq.1.and.reverse_hs_me1a.eq.1) then //me1a reversed
        if(clct0_key.lt.adjcfeb_dist.and.clct0_cfeb.ne.0.and.clct0_cfeb.ne.4) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb-1)    //cfebn-1 was hit
        if(clct0_key.gt.31-adjcfeb_dist.and.clct0_cfeb.le.2) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb+1)    //cfebn+1 was hit

        c this section is broken
        else if(csc_me1ab.eq.1.and.reverse_hs_me1b.eq.1.
        1       and.clct0_fullkey.lt.128) then //me1b reversed key on me1a
        if(clct0_key.lt.adjcfeb_dist.and.clct0_cfeb.ne.0) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb+1)    //cfebn-1 was hit
        if((31-clct0_key).gt.31-adjcfeb_dist.and.clct0_cfeb.ne.4) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct0_cfeb-1)    //cfebn+1 was hit
        endif
        endif
        c end broken

        if(clct1_vpf.eq.1)then
        active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb)        //cfebn was hit

        if(reverse_hs_me1b.eq.1.and.clct1_fullkey.le.127)   
        1active_febs_expect=active_febs_expect.or.ishft(1,3-clct1_cfeb)     //cfebn was hit
        if(reverse_hs_me1b.eq.1.and.clct1_fullkey.ge.128)   
        1active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb)       //cfebn was hit

        if(csc_me1ab.eq.0) then //normal csc
        if(clct1_key.lt.adjcfeb_dist.and.clct1_cfeb.ne.0) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb-1)    //cfebn-1 was hit
        if(clct1_key.gt.31-adjcfeb_dist.and.clct1_cfeb.ne.4) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb+1)    //cfebn+1 was hit

        else if(csc_me1ab.eq.1.and.reverse_hs_me1a.eq.1) then //me1a reversed
        if(clct1_key.lt.adjcfeb_dist.and.clct1_cfeb.ne.0.and.clct1_cfeb.ne.4) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb-1)    //cfebn-1 was hit
        if(clct1_key.gt.31-adjcfeb_dist.and.clct1_cfeb.le.2) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb+1)    //cfebn+1 was hit

        c this section is broken
        else if(csc_me1ab.eq.1.and.reverse_hs_me1b.eq.1) then //me1b reversed
        if(clct1_key.lt.adjcfeb_dist.and.clct1_cfeb.ne.0) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb-1)    //cfebn-1 was hit
        if(clct1_key.gt.31-adjcfeb_dist.and.clct1_cfeb.ne.4) 
        1 active_febs_expect=active_febs_expect.or.ishft(1,clct1_cfeb+1)    //cfebn+1 was hit
        endif
        endif
        c this section is broken

        c Compare to TMBs active febs
        call ck('active_febs',r_active_feb_ff,active_febs_expect)
        d   write(8,'(1x,i3,1x,i1,1x,b5.5,1x,b5.5)')
    d   1 lct0_key,lct0_cfeb,active_febs,active_febs_expect
        */
        //------------------------------------------------------------------------------
        // Unpack CFEB raw hits
        //------------------------------------------------------------------------------
        // Check CFEBs exist in readout
        if ((!header_full) || (r_fifo_tbins<=0) || (r_ncfebs<=0) || (adr_e0b<0)) {
            fprintf(log_file,"No CFEB raw hits in this event\n");
            fprintf(stderr,  "No CFEB raw hits in this event\n");
            goto cfeb_done;
        }

    // Check ncfebs is between 1 and 5
    if ((r_ncfebs<=0)||(r_ncfebs>mxcfeb+1)) {
        header_ok=false;
        error_flag[36]=1; // Expected number of CFEBs 0<r_ncfebs<=5
        fprintf(log_file,"Err: Expected number of CFEBs 0<r_ncfebs<=5 %i\n",r_ncfebs);
        goto cfeb_done;
    }

    // Check r_fifo_tbins>0
    if (r_fifo_tbins<=0) {
        header_ok=false;
        error_flag[37]=1; // Expected number of CFEB tbins 0<r_fifo_tbins
        fprintf(log_file,"Err: Expected number of CFEB tbins 0<r_fifo_tbins %i\n",r_fifo_tbins);
        goto cfeb_done;
    }

    // Loop over cfebs, tbins, layers
    iframe=adr_e0b+1;                                   //First raw hits frame 
    for (icfeb=0;  icfeb  <= r_ncfebs-1;    ++icfeb ) { //Loop over cfebs
        for (itbin=0;  itbin  <= r_fifo_tbins-1;++itbin ) { //Loop over time bins
            for (ilayer=0; ilayer <= mxly;          ++ilayer) { //Loop over layers

                rdcid  = (vf_data[iframe] >> 12) & 0x7;             //CFEB ID in the dump
                rdtbin = (vf_data[iframe] >>  8) & 0xF;             //Tbin number in the dump
                itbin_bit3=(itbin >> 3) & 0x1;                      //itbin[3]
                itbin_bit4=(itbin >> 4) & 0x1;                      //itbin[4]
                itbin_merged=itbin_bit3 | itbin_bit4;               //TMB merges tbin bits 3,4 beco no space for bit4
                itbin_expect=(itbin & 0x7) | (itbin_merged << 3);
                hits8=vf_data[iframe] & 0xFF;                       //8 triad block

                if(rdcid != icfeb) {
                    fprintf(log_file,"cfeb id err in dump:rdcid,icfeb,f=%i %i %i\n",rdcid,icfeb,iframe);
                    fprintf(stderr,  "cfeb id err in dump:rdcid,icfeb,f=%i %i %i\n",rdcid,icfeb,iframe);
                }

                if(rdtbin != itbin_expect) {
                    fprintf(log_file,"tbin id err in dump:rdtbin,itbin=%i %i %i\n",rdtbin,itbin,iframe);
                    fprintf(stderr,  "tbin id err in dump:rdtbin,itbin=%i %i %i\n",rdtbin,itbin,iframe);
                }
                if((rdcid != icfeb) || (rdtbin != itbin_expect)) goto cfeb_done;

                for (ids=0; ids<=mxds; ++ids) {                 //Loop over hits per block
                    hits1=(hits8 >> ids) & 0x1;                     //Extract 1 hit
                    ids_abs=ids+icfeb*8;                            //Absolute distrip id
                    read_pat[itbin][ilayer][ids_abs]=hits1;         //hit this distrip
                    dprintf(log_file,"%4i%5.4X%5.4X%5.4X%5.4X%5.4X%5.4X\n",iframe,vf_data[iframe],hits8,icfeb,itbin,ids_abs,hits1);
                }                                               //Close for ihit

                iframe++;                                       //Next frame
                if(iframe >= last_frame) {                      //Bummer, dude
                    fprintf(log_file,"raw hits frame over-run\n");
                    fprintf(stderr,  "raw hits frame over-run\n");
                    goto cfeb_done;
                }
            }                                               //Close for ilayer
        }                                               //Close for itbin
    }                                               //Close for icfeb
cfeb_done:
    //------------------------------------------------------------------------------
    // Unpack RPC raw hits
    //------------------------------------------------------------------------------
    // Check for RPC readout enabled
    if(rd_nrpcs==0 || adr_b04<0) {
        fprintf(log_file,"No RPC frames in this event\n");
        goto rpc_done;
    }

    // Unpack RPC data
    iframe=adr_b04+1;
    n=iframe+1;
    ipair=0;

    for (iframe=n; iframe<=(n+frame_cntex_rpc-1-2); iframe=iframe+2) {
        rpc_data0=vf_data[iframe];
        rpc_data1=vf_data[iframe+1];
        rpc_lsbs = (rpc_data0 >>  0) & 0xFF;
        rpc_tbin = (rpc_data0 >>  8) & 0x0F;
        rpc_id0  = (rpc_data0 >> 12) & 0x07;
        rpc_msbs = (rpc_data1 >>  0) & 0xFF;
        rpc_bxn  = (rpc_data1 >>  8) & 0x07;
        rpc_id1  = (rpc_data1 >> 12) & 0x07;

        rpc_data = (rpc_msbs  <<  8) | rpc_lsbs;

        fprintf(log_file,"pair=%3i",ipair);
        fprintf(log_file,"frame=%5i",iframe); 
        fprintf(log_file,"raw=%5.5X",vf_data[iframe]);
        fprintf(log_file,"raw=%5.5X",vf_data[iframe+1]);
        fprintf(log_file,"rpc_id0=%1i",rpc_id0);
        fprintf(log_file,"rpc_id1=&1i",rpc_id1);
        fprintf(log_file,"tbin=%2i",rpc_tbin);
        fprintf(log_file,"bxn=%2i",rpc_bxn);
        fprintf(log_file,"pads%4.4x=\n",rpc_data);

        if(rpc_id0 != rpc_id1) {
            fprintf(log_file,"rpc_id missmatch wtf?\n");
            fprintf(stderr,  "rpc_id missmatch wtf?\n");
        }

        ipair++;
    }   // close iframe

rpc_done:

    //------------------------------------------------------------------------------
    // Display Header Frames
    //------------------------------------------------------------------------------
display_header:

    // First 4 header words must conform to DDU specification
    iframe=0;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"boc                = %4.3X\n",    boc);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=1;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"pop_bxn_counter    = %4.4X\n",    pop_bxn_counter);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=2;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"pop_l1a_rx_counter = %4.4X\n",    pop_l1a_rx_counter);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=3;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"readout_counter    = %4.4X\n",    readout_counter);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // Next 4 words for short header mode
    iframe=4;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"board_id           = %4i\n",      board_id);
    fprintf(log_file,"csc_id             = %4i\n",      csc_id);
    fprintf(log_file,"run_id             = %4i\n",      run_id);
    fprintf(log_file,"h4_buf_q_ovf_err   = %4.1X\n",    h4_buf_q_ovf_err);
    fprintf(log_file,"r_sync_err         = %4.1X\n",    r_sync_err);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=5;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_nheaders         = %4i\n",      r_nheaders);
    fprintf(log_file,"fifo_mode          = %4i  %s\n",  fifo_mode,sfifo_mode.c_str());
    fprintf(log_file,"r_type             = %4i  %s\n",  r_type,sr_type.c_str());
    fprintf(log_file,"l1a_type           = %4i  %s\n",  l1a_type,sl1a_type.c_str());
    fprintf(log_file,"r_has_buf          = %4i\n",      r_has_buf);
    fprintf(log_file,"r_buf_stalled      = %4i\n",      r_buf_stalled);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=6;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"bd_status_ok       = %4.1i\n",    bd_status_vec[0]);
    fprintf(log_file,"vstat_5p0vs        = %4.1i\n",    bd_status_vec[1]);
    fprintf(log_file,"vstat_3p3v         = %4.1i\n",    bd_status_vec[2]);
    fprintf(log_file,"vstat_1p8v         = %4.1i\n",    bd_status_vec[3]);
    fprintf(log_file,"vstat_1p5v         = %4.1i\n",    bd_status_vec[4]);
    fprintf(log_file,"_t_crit            = %4.1i\n",    bd_status_vec[5]);
    fprintf(log_file,"vsm_ok             = %4.1i\n",    bd_status_vec[6]);
    fprintf(log_file,"vsm_aborted        = %4.1i\n",    bd_status_vec[7]);
    fprintf(log_file,"vsm_cksum_ok       = %4.1i\n",    bd_status_vec[8]);
    fprintf(log_file,"vsm_wdcnt_ok       = %4.1i\n",    bd_status_vec[9]);
    fprintf(log_file,"jsm_ok             = %4.1i\n",    bd_status_vec[10]);
    fprintf(log_file,"jsm_aborted        = %4.1i\n",    bd_status_vec[11]);
    fprintf(log_file,"jsm_cksum_ok       = %4.1i\n",    bd_status_vec[12]);
    fprintf(log_file,"jsm_wdcnt_ok       = %4.1i\n",    bd_status_vec[13]);
    fprintf(log_file,"sm_tck_fpga_ok     = %4.1i\n",    bd_status_vec[14]);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=7;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"revcode            = %4.4X  ",    revcode);
    fprintf(log_file,"Decodes as ");
    fprintf(log_file,"%2.2i/",                          id_rev_month);
    fprintf(log_file,"%2.2i/",                          id_rev_day);
    fprintf(log_file,"%2.2i xc2v",                      id_rev_year);
    fprintf(log_file,"%1.1X000\n",                      id_rev_fpga);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    if(header_only_short) goto display_trailer;

    // Full Header-mode words 8-41: Event counters
    iframe=8;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_bxn_counter_ff   = %4.3X\n",    r_bxn_counter_ff);
    fprintf(log_file,"r_tmb_clct0_discard= %4.1X\n",    r_tmb_clct0_discard);
    fprintf(log_file,"r_tmb_clct1_discard= %4.1X\n",    r_tmb_clct1_discard);
    fprintf(log_file,"clock_lock_lost    = %4.1X\n",    clock_lock_lost);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=9;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_pretrig_cnt_lsb  = %4.4X\n",    r_pretrig_counter_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=10;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_pretrig_cnt_msb  = %4.4X  ",    r_pretrig_counter_msb);
    fprintf(log_file,"Full pretrig_countr= %9i\n",      pretrig_counter);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=11;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_clct_cnt_lsb     = %4.4X\n",    r_clct_counter_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=12;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_clct_cnt_msb     = %4.4X  ",    r_clct_counter_msb);
    fprintf(log_file,"Full clct_counter  = %9i\n",      clct_counter);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=13;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_trig_cnt_lsb     = %4.4X\n",    r_trig_counter_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=14;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_trig_cnt_msb     = %4.4X  ",    r_trig_counter_msb);
    fprintf(log_file,"Full trig_counter  = %9i\n",      trig_counter);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=15;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_alct_cnt_lsb     = %4.4X\n",    r_alct_counter_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=16;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_alct_cnt_msb     = %4.4X  ",    r_alct_counter_msb);
    fprintf(log_file,"Full alct_counter  = %9i\n",      alct_counter);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=17;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_orbit_cnt_lsb    = %4.4X\n",    r_orbit_counter_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=18;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_orbit_cnt_msb    = %4.4X  ",    r_orbit_counter_msb);
    fprintf(log_file,"Full orbit_counter = %9.8X  =",   uptime_counter);
    fprintf(log_file,"%6i seconds\n",                   uptime_sec);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // CLCT Raw Hits Size
    iframe=19;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_ncfebs           = %4.1X\n",    r_ncfebs);
    fprintf(log_file,"r_fifo_tbins       = %4i\n",      r_fifo_tbins);
    fprintf(log_file,"fifo_pretrig       = %4i\n",      fifo_pretrig);
    fprintf(log_file,"scope_data_exists  = %4.1X\n",    scope_data_exists);
    fprintf(log_file,"vmedata_exists     = %4.1X\n",    vme_data_exists);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // CLCT Configuration
    iframe=20;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"hit_thresh_pretrig = %4.1X\n",    hit_thresh_pretrig);
    fprintf(log_file,"pid_thresh_pretrig = %4.1X\n",    pid_thresh_pretrig);
    fprintf(log_file,"hit_thresh_postdrf = %4.1X\n",    hit_thresh_postdrf);
    fprintf(log_file,"pid_thresh_postdrf = %4.1X\n",    pid_thresh_postdrf);
    fprintf(log_file,"stagger_csc        = %4.1X\n",    stagger_csc);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=21;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"triad_persist      = %4.1X\n",    triad_persist);
    fprintf(log_file,"dmb_thresh         = %4.1X\n",    dmb_thresh);
    fprintf(log_file,"alct_delay         = %4.1X\n",    alct_delay);
    fprintf(log_file,"clct_window        = %4.1X\n",    clct_window);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=22;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);

    fprintf(log_file,"r_trig_source_vec  = %4.4X  ",    r_trig_source_vec);
    fprintf(log_file,"Decodes as ");
    for (i=8;i>=0;--i) fprintf(log_file,"%1i",          (r_trig_source_vec>>i)&0x1);
    fprintf(log_file,"\n");

    fprintf(log_file,"r_layers_hit       = %4.4X  ",    r_layers_hit);
    fprintf(log_file,"Decodes as ");
    for (i=5;i>=0;--i) fprintf(log_file,"%1i",          (r_layers_hit>>i)&0x1);
    fprintf(log_file,"\n");
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=23;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);

    fprintf(log_file,"r_active_feb_ff    = %4.4X  ",    r_active_feb_ff);
    fprintf(log_file,"Decodes as ");
    for (i=4;i>=0;--i) fprintf(log_file,"%1i",          (r_active_feb_ff>>i)&0x1);
    fprintf(log_file,"\n");

    fprintf(log_file,"r_febs_read        = %4.4X  ",    r_febs_read);
    fprintf(log_file,"Decodes as ");
    for (i=4;i>=0;--i) fprintf(log_file,"%1i",          (r_febs_read>>i)&0x1);
    fprintf(log_file,"\n");

    fprintf(log_file,"r_l1a_match_win    = %4.1X\n",    r_l1a_match_win);
    fprintf(log_file,"active_feb_src     = %4.1X\n",    active_feb_src);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);


    // CLCT+ALCT Match Status
    iframe=24;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_tmb_match        = %4.1X\n",    r_tmb_match);
    fprintf(log_file,"r_tmb_alct_only    = %4.1X\n",    r_tmb_alct_only);
    fprintf(log_file,"r_tmb_clct_only    = %4.1X\n",    r_tmb_clct_only);
    fprintf(log_file,"r_tmb_match_win    = %4.1X\n",    r_tmb_match_win);
    fprintf(log_file,"r_no_alct_tmb      = %4.1X\n",    r_no_alct_tmb);
    fprintf(log_file,"r_one_alct_tmb     = %4.1X\n",    r_one_alct_tmb);
    fprintf(log_file,"r_one_clct_tmb     = %4.1X\n",    r_one_clct_tmb);
    fprintf(log_file,"r_two_alct_tmb     = %4.1X\n",    r_two_alct_tmb);
    fprintf(log_file,"r_two_clct_tmb     = %4.1X\n",    r_two_clct_tmb);
    fprintf(log_file,"r_dupe_alct_tmb    = %4.1X\n",    r_dupe_alct_tmb);
    fprintf(log_file,"r_dupe_clct_tmb    = %4.1X\n",    r_dupe_clct_tmb);
    fprintf(log_file,"r_rank_err_tmb     = %4.1X\n",    r_rank_err_tmb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // CLCT Trigger Data
    iframe=25;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_clct0_tmb_lsb    = %4.4X\n",    r_clct0_tmb_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=26;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_clct1_tmb_lsb    = %4.4X\n",    r_clct1_tmb_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=27;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_clct0_tmb_msb    = %4.2X\n",    r_clct0_tmb_msb);
    fprintf(log_file,"r_clct1_tmb_msb    = %4.2X\n",    r_clct1_tmb_msb);
    fprintf(log_file,"r_clct0_invp       = %4.1X\n",    r_clct0_invp);
    fprintf(log_file,"r_clct1_invp       = %4.1X\n",    r_clct1_invp);
    fprintf(log_file,"r_clct1_busy       = %4.1X\n",    r_clct1_busy);
    fprintf(log_file,"perr_cfeb_ff       = %4.1X  ",    perr_cfeb_ff);
    fprintf(log_file,"Decodes as ");
    for (i=4;i>=0;--i) fprintf(log_file,"%1i",          (perr_cfeb_ff>>i)&0x1);
    fprintf(log_file,"\n");
    fprintf(log_file,"perr_rpc_ff        = %4.1X\n",    perr_rpc_ff);
    fprintf(log_file,"perr_ff            = %4.1X\n",    perr_ff);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // ALCT Trigger Data
    iframe=28;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_alct0_valid      = %4.1X\n",    r_alct0_valid);
    fprintf(log_file,"r_alct0_quality    = %4.1X\n",    r_alct0_quality);
    fprintf(log_file,"r_alct0_amu        = %4.1X\n",    r_alct0_amu);
    fprintf(log_file,"r_alct0_key        = %4i\n",      r_alct0_key);
    fprintf(log_file,"r_alct_pretrig_win = %4.1X\n",    r_alct_pretrig_win);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=29;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_alct1_valid      = %4.1X\n",    r_alct1_valid);
    fprintf(log_file,"r_alct1_quality    = %4.1X\n",    r_alct1_quality);
    fprintf(log_file,"r_alct1_amu        = %4.1X\n",    r_alct1_amu);
    fprintf(log_file,"r_alct1_key        = %4i\n",      r_alct1_key);
    fprintf(log_file,"drift_delay        = %4i\n",      drift_delay);
    fprintf(log_file,"res29              = %4.1X\n",    res29);
    fprintf(log_file,"hs_layer_trig      = %4.1X\n",    hs_layer_trig);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=30;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_alct_bxn         = %4.2X\n",    r_alct_bxn);
    fprintf(log_file,"alct_seq_status    = %4.1X\n",    alct_seq_status);
    fprintf(log_file,"alct_seu_status    = %4.1X\n",    alct_seu_status);
    fprintf(log_file,"alct_reserved_out  = %4.1X\n",    alct_reserved_out);
    fprintf(log_file,"alct_cfg_done      = %4.1X\n",    alct_cfg_done);
    fprintf(log_file,"res30              = %4.1X\n",    res30);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // MPC Frames
    iframe=31;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_mpc0_frame0_lsb  = %4.4X\n",    r_mpc0_frame0_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=32;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_mpc0_frame1_lsb  = %4.4X\n",    r_mpc0_frame1_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=33;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_mpc1_frame0_lsb  = %4.4X\n",    r_mpc1_frame0_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=34;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_mpc1_frame1_lsb  = %4.4X\n",    r_mpc1_frame1_lsb);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=35;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_mpc0_frame0_msb  = %4.1X\n",    r_mpc0_frame0_msb);
    fprintf(log_file,"r_mpc0_frame1_msb  = %4.1X\n",    r_mpc0_frame1_msb);
    fprintf(log_file,"r_mpc1_frame0_msb  = %4.1X\n",    r_mpc1_frame0_msb);
    fprintf(log_file,"r_mpc1_frame1_msb  = %4.1X\n",    r_mpc1_frame1_msb);
    fprintf(log_file,"mpc_tx_delay       = %4.1X\n",    mpc_tx_delay);
    fprintf(log_file,"r_mpc_accept       = %4.1X\n",    r_mpc_accept);
    fprintf(log_file,"cfeb_en            = %4.2X  ",    cfeb_en);
    fprintf(log_file,"Decodes as ");
    for (i=4;i>=0;--i) fprintf(log_file,"%1i",          (cfeb_en>>i)&0x1);
    fprintf(log_file,"\n");

    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // RPC Configuration
    iframe=36;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);

    fprintf(log_file,"rd_rpc_list        = %4.2X  ",    rd_rpc_list);
    fprintf(log_file,"Decodes as ");
    for (i=1;i>=0;--i) fprintf(log_file,"%1i",          (rd_rpc_list>>i)&0x1);
    fprintf(log_file,"\n");

    fprintf(log_file,"rd_nrpcs           = %4.1X\n",    rd_nrpcs);
    fprintf(log_file,"rpc_read_enable    = %4.1X\n",    rpc_read_enable);
    fprintf(log_file,"fifo_tbins_rpc     = %4i\n",      fifo_tbins_rpc);
    fprintf(log_file,"fifo_pretrig_rpc   = %4i\n",      fifo_pretrig_rpc);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // Buffer Status
    iframe=37;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_wr_buf_adr       = %4.3X\n",    r_wr_buf_adr);
    fprintf(log_file,"r_wr_buf_ready     = %4.1X\n",    r_wr_buf_ready);
    fprintf(log_file,"wr_buf_ready       = %4.1X\n",    wr_buf_ready);
    fprintf(log_file,"buf_q_full         = %4.1X\n",    buf_q_full);
    fprintf(log_file,"buf_q_empty        = %4.1X\n",    buf_q_empty);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=38;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"r_buf_fence_dist   = %4.3X%5i\n", r_buf_fence_dist,r_buf_fence_dist);
    fprintf(log_file,"buf_q_ovf_err      = %4.1X\n",    buf_q_ovf_err);
    fprintf(log_file,"buf_q_udf_err      = %4.1X\n",    buf_q_udf_err);
    fprintf(log_file,"buf_q_adr_err      = %4.1X\n",    buf_q_adr_err);
    fprintf(log_file,"buf_stalled        = %4.1X\n",    buf_stalled);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // Spare Frames
    iframe=39;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"buf_fence_cnt      = %4i\n",      buf_fence_cnt);
    fprintf(log_file,"reverse_hs_csc     = %4.1X\n",    reverse_hs_csc);
    fprintf(log_file,"reverse_hs_me1a    = %4.1X\n",    reverse_hs_me1a);
    fprintf(log_file,"reverse_hs_me1b    = %4.1X\n",    reverse_hs_me1b);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=40;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"buf_fence_cnt_peak = %4i\n",      buf_fence_cnt_peak);
    fprintf(log_file,"r_trig_source_vec9 = %4.1X\n",    r_trig_source_vec9);
    fprintf(log_file,"r_trig_source_vec10= %4.1X\n",    r_trig_source_vec10);
    fprintf(log_file,"tmb_trig_pulse     = %4.1X\n",    tmb_trig_pulse);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=41;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"tmb_allow_alct     = %4.1X\n",    tmb_allow_alct);
    fprintf(log_file,"tmb_allow_clct     = %4.1X\n",    tmb_allow_clct);
    fprintf(log_file,"tmb_allow_match    = %4.1X\n",    tmb_allow_match);
    fprintf(log_file,"tmb_allow_alct_ro  = %4.1X\n",    tmb_allow_alct_ro);
    fprintf(log_file,"tmb_allow_clct_ro  = %4.1X\n",    tmb_allow_clct_ro);
    fprintf(log_file,"tmb_allow_match_ro = %4.1X\n",    tmb_allow_match_ro);
    fprintf(log_file,"tmb_alct_ro        = %4.1X\n",    tmb_alct_ro);
    fprintf(log_file,"tmb_clct_ro        = %4.1X\n",    tmb_clct_ro);
    fprintf(log_file,"tmb_match_ro       = %4.1X\n",    tmb_match_ro);
    fprintf(log_file,"tmb_trig_keep      = %4.1X\n",    tmb_trig_keep);
    fprintf(log_file,"tmb_nontrig_keep   = %4.1X\n",    tmb_nontrig_keep);
    fprintf(log_file,"lyr_thresh_pretrig = %4.1X\n",    lyr_thresh_pretrig);
    fprintf(log_file,"layer_trig_en      = %4.1X\n",    layer_trig_en);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // EOB Frame
    iframe=42;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"eob                = %4.4X\n",    eob);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    // EOC Frame
    iframe=last_frame-6;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"eoc                = %4.3X\n",    eoc);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    //------------------------------------------------------------------------------
    //  Display Filler Frames
    //------------------------------------------------------------------------------
    if(header_filler) {
        iframe=last_frame-5;
        fprintf(log_file,"\n");
        fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
        fprintf(log_file,"opt2aaa            = %4.4X\n",    opt2aaa);
        fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

        iframe=last_frame-4;
        fprintf(log_file,"\n");
        fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
        fprintf(log_file,"opt5555            = %4.4X\n",    opt5555);
        fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);
    }

    //------------------------------------------------------------------------------
    //  Display Trailer Frames
    //------------------------------------------------------------------------------
display_trailer:
    iframe=last_frame-3;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"lctype3            = %4.1X\n",    lctype3);
    fprintf(log_file,"eof                = %4.3X\n",    eof);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=last_frame-2;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"crc22lsb           = %4.3X\n",    crc22lsb);
    fprintf(log_file,"lctype2            = %4.1X\n",    lctype2);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=last_frame-1;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"crc22msb           = %4.3X\n",    crc22msb);
    fprintf(log_file,"lctype1            = %4.1X\n",    lctype1);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    iframe=last_frame;
    fprintf(log_file,"\n");
    fprintf(log_file,"Header Frame%4i%3.3s %5.5X\n",    iframe,x,vf_data[iframe]);
    fprintf(log_file,"frame_cnt          = %4i\n",      frame_cnt);
    fprintf(log_file,"lctype0            = %4.1X\n",    lctype0);
    fprintf(log_file,"ddu                = %4.1X\n",    ddu[iframe]);

    if(header_only_short) goto exit;
    //------------------------------------------------------------------------------
    //  Display decoded LCT data
    //------------------------------------------------------------------------------
    // CLCT0
    fprintf(log_file,"\n");
    fprintf(log_file,"CLCT0 Decode      %7.7X\n",       clct0);
    fprintf(log_file,"clct0_vpf          = %4i\n",      clct0_vpf);
    fprintf(log_file,"clct0_nhit         = %4i\n",      clct0_nhit);
    fprintf(log_file,"clct0_pat          = %4X\n",      clct0_pat);
    fprintf(log_file,"clct0_key          = %4i\n",      clct0_key);
    fprintf(log_file,"clct0_cfeb         = %4i\n",      clct0_cfeb);
    fprintf(log_file,"clct0_fullkey      = %4i\n",      clct0_fullkey);

    // CLCT1
    fprintf(log_file,"\n");
    fprintf(log_file,"CLCT1 Decode      %7.7X\n",       clct1);
    fprintf(log_file,"clct1_vpf          = %4i\n",      clct1_vpf);
    fprintf(log_file,"clct1_nhit         = %4i\n",      clct1_nhit);
    fprintf(log_file,"clct1_pat          = %4X\n",      clct1_pat);
    fprintf(log_file,"clct1_key          = %4i\n",      clct1_key);
    fprintf(log_file,"clct1_cfeb         = %4i\n",      clct1_cfeb);
    fprintf(log_file,"clct1_fullkey      = %4i\n",      clct1_fullkey);

    // Common
    fprintf(log_file,"\n");
    fprintf(log_file,"clctc_bxn          = %4.3X\n",    clctc_bxn);
    fprintf(log_file,"clctc_sync         = %4i\n",      clctc_sync);

    //------------------------------------------------------------------------------
    //  Display decoded MPC data
    //------------------------------------------------------------------------------
    // MPC0
    fprintf(log_file,"\n");
    fprintf(log_file,"MPC0 Decode From Header\n");
    fprintf(log_file,"mpc_alct0_key      = %4i\n",      mpc_alct0_key);
    fprintf(log_file,"mpc_clct0_pat      = %4.1X\n",    mpc_clct0_pat);
    fprintf(log_file,"mpc_lct0_quality   = %4i\n",      mpc_lct0_quality);
    fprintf(log_file,"mpc_lct0_vpf       = %4.1X\n",    mpc_lct0_vpf);

    fprintf(log_file,"mpc_clct0_key      = %4i\n",      mpc_clct0_key);
    fprintf(log_file,"mpc_clct0_bend     = %4.1X\n",    mpc_clct0_bend);
    fprintf(log_file,"mpc_sync_err0      = %4.1X\n",    mpc_sync_err0);
    fprintf(log_file,"mpc_alct0_bxn      = %4.3X\n",    mpc_alct0_bxn);
    fprintf(log_file,"mpc_bx0_clct       = %4i\n",      mpc_bx0_clct);
    fprintf(log_file,"mpc_csc_id0        = %4i\n",      mpc_csc_id0);

    // MPC1
    fprintf(log_file,"\n");
    fprintf(log_file,"MPC1 Decode From Header\n");
    fprintf(log_file,"mpc_alct1_key      = %4i\n",      mpc_alct1_key);
    fprintf(log_file,"mpc_clct1_pat      = %4.1X\n",    mpc_clct1_pat);
    fprintf(log_file,"mpc_lct1_quality   = %4i\n",      mpc_lct1_quality);
    fprintf(log_file,"mpc_lct1_vpf       = %4.1X\n",    mpc_lct1_vpf);

    fprintf(log_file,"mpc_clct1_key      = %4i\n",      mpc_clct1_key);
    fprintf(log_file,"mpc_clct1_bend     = %4.1X\n",    mpc_clct1_bend);
    fprintf(log_file,"mpc_sync_err1      = %4.1X\n",    mpc_sync_err1);
    fprintf(log_file,"mpc_alct1_bxn      = %4.3X\n",    mpc_alct1_bxn);
    fprintf(log_file,"mpc_bx0_alct       = %4i\n",      mpc_bx0_alct);
    fprintf(log_file,"mpc_csc_id1        = %4i\n",      mpc_csc_id1);

    //------------------------------------------------------------------------------
    //  Display CFEB raw hits triads
    //------------------------------------------------------------------------------
    if (header_only_short || header_only_long) {
        fprintf(log_file,"Skipping triad display for header-only event\n");
        goto check_scope;
    }

    ntbins=r_fifo_tbins;
    ntbinspre=fifo_pretrig;

    // Display cfeb and ids column markers
    fprintf(log_file,"\n");
    fprintf(log_file,"     Raw Hits Triads\n");

    fprintf(log_file,"Cfeb-");
    for (icfeb=0; icfeb <=mxcfeb; ++icfeb) { fprintf(log_file,"%|"); // display cfeb columms
        for (ids=0;   ids   <=mxds;   ++ids  )   fprintf(log_file,"%1.1i",icfeb);}
    fprintf(log_file,"|\n");

    fprintf(log_file,"Ds---");
    for (icfeb=0; icfeb <=mxcfeb; ++icfeb) { fprintf(log_file,"%|",x);  // display ids columns
        for (ids=0;   ids   <=mxds;   ++ids  )   fprintf(log_file,"%1.1i",ids%10);}
    fprintf(log_file,"|\n");
    fprintf(log_file,"Ly Tb\n");

    // Display raw hits
    for (ilayer=0; ilayer<=mxly; ++ilayer)        {
        for (itbin=0; itbin<=r_fifo_tbins-1; ++itbin) { fprintf(log_file,"%1i %2i ",ilayer,itbin);

            for (ids_abs=0;ids_abs<=39;++ids_abs) {
                if (ids_abs%8==0) fprintf(log_file,"|");
                fprintf(log_file,"%1.1i",read_pat[itbin][ilayer][ids_abs]);
            }   // close for ids_abs
            fprintf(log_file,"|\n");
        }   // close itbin
        fprintf(log_file,"\n");
    }   // close ilayer
    /*
    //------------------------------------------------------------------------------
    // Compare read-back triads to generated triads
    //------------------------------------------------------------------------------
    triad_error=.false.
    do ilayer=0,mxly
    do itbin=0,r_fifo_tbins-1
    do ids_abs=0,mxdsabs
    triad_read=read_pat(itbin,ilayer,ids_abs)
    triad_write=0
    wrtbin=itbin-ntbinspre
    if(wrtbin.ge.0)triad_write=itriad(wrtbin,ids_abs,ilayer)
    if(triad_write.ne.triad_read)then
    triad_error=.true.
    write(*,430) 'Triad readback match error',
    1triad_read,triad_write,ilayer,itbin,ids_abs,ntbinspre
    write(2,430) 'Triad readback match error',
    1triad_read,triad_write,ilayer,itbin,ids_abs,ntbinspre
    430 format(a,6i3)
    end if
    end do
    end do
    end do
    if(!triad_error) fprintf(log_file,"Triad readback OK\n");
    */

    //------------------------------------------------------------------------------
    //  Scope readout
    //------------------------------------------------------------------------------
check_scope:

    // Scan for 06B05 marker
    if(scope_data_exists !=1) {
        fprintf(log_file,"Skipping scope readout because scope_data_exists=%1X\n",scope_data_exists);
        goto skip_scope;
    }

    for (iframe=0; iframe<=last_frame; ++iframe) {
        if(vf_data[iframe] == 0x06B05) {
            iscp_begin=iframe;
            fprintf(log_file,"06B05 scope marker found at frame=%5i\n",iscp_begin);
            goto extract_scope;
        }   // close if vf_data
    }   // close iframe
    fprintf(log_file,"No 06B05 scope marker found\n");
    goto skip_scope;

    // Extract scp data
extract_scope:
    iscp_end=iscp_begin+frame_cntex_scope-1;
    if(iscp_end > last_frame) {
        fprintf(log_file,"Not enough scp data, aborting scp read\n");
        goto skip_scope;
    }

    if(vf_data[iscp_end] == 0x6E05)
        fprintf(log_file,"06E05 scope marker found at frame=%5i\n",iscp_end);
    else {
        fprintf(log_file,"Missing 6E05 marker at adr=%5i. Aborting scope read\n",iscp_end);
        //  goto skip_scope;    ////////////////////// TEMPORARY SKIP
    }

    iscp=0;
    for (iframe=iscp_begin+1; iframe<=iscp_end-1; ++iframe) {   //excludes 6B05 and 6E05 markers
        scp_raw_data[iscp]=vf_data[iframe];
        if(iscp > (512*160/16-1)) pause ("iscp ovf in decode_raw_hits.for wtf?");
        fprintf(log_file,"scp debug: %5i%5i%5.4X\n",iscp,iframe,scp_raw_data[iscp]);
        iscp++;
    }

    // Load scope arrays, display channel graph
    fprintf(log_file,"Decode/display raw hits scope data\n");
    scp_arm         = false;
    scp_readout     = false;
    scp_raw_decode  = true;
    scp_silent      = false;
    scp_playback    = true;

    scope160c(base_adr,scp_ctrl_adr,scp_rdata_adr,scp_arm,scp_readout,scp_raw_decode,scp_silent,scp_playback,scp_raw_data);

    //------------------------------------------------------------------------------
    // Future stuff goes here
    //------------------------------------------------------------------------------
skip_scope:

    //------------------------------------------------------------------------------
    // All done...wheee
    //------------------------------------------------------------------------------
exit:
    fprintf(log_file,"\n");

    // Check error flags
    for (i=0; i<MXERF; ++ i) {
        if(error_flag[i]!=0) {
            fprintf(log_file,"Error flag [%2i]=%i %s\n",i,error_flag[i],error_msg[i].c_str());  // Display only bad flags
            fprintf(stdout,  "Error flag [%2i]=%i %s\n",i,error_flag[i],error_msg[i].c_str());
        }
        dprintf(log_file,"Error flag [%2i]=%i %s\n",i,error_flag[i],error_msg[i].c_str());  // Display all flags in debug mode
        dprintf(stdout,  "Error flag [%2i]=%i %s\n",i,error_flag[i],error_msg[i].c_str());
    }

    if(header_ok)   fprintf(stdout,"Header format OK\n");
    else            fprintf(stdout,"Header format has errors\n");
    return;
}


//------------------------------------------------------------------------------
// The bitter end
//------------------------------------------------------------------------------
