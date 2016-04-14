#ifndef DECODE_RAW_HITS_H
#define DECODE_RAW_HITS_H
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
//------------------------------------------------------------------------------
// Debug print mode
//------------------------------------------------------------------------------
#define debug 1	// comment this line to turn off debug print
#ifdef debug
#define dprintf fprintf
#else
#define dprintf //
#endif
//------------------------------------------------------------------------------
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
        unsigned long	 scp_rdata_adr);
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
