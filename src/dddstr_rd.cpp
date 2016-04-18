//------------------------------------------------------------------------------
//  Reads 3D3444 Delay Settings
//
//  08/14/09 Ported from posneg_rd
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include "dddstr_rd.h"
#include "vme_io.h"
#include "pause.h"
using namespace std;

//------------------------------------------------------------------------------------------
// Function dddstr_rd(base_adr, scfeb) returns delay
//---------------------------------------------------------------------------------------------------------
int dddstr_rd(unsigned long base_adr, const std::string scfeb)
{
    // VME addresses
    const unsigned long vme_ddd0_adr        =0x000016;
    const unsigned long vme_ddd1_adr        =0x000018;
    const unsigned long vme_ddd2_adr        =0x00001A;

    // VME calls
    unsigned long   adr;
    unsigned short  rd_data;
    long            status;

    // Local
    int             ddd_chip;
    int             ddd_delay;
    int             ddd_channel;

    //------------------------------------------------------------------------------
    // Read posneg value for selected DCM
    //------------------------------------------------------------------------------
    // Determine DDD VME address
    if      (scfeb.compare("alct_tof"  )==0) {ddd_chip=0; ddd_channel=0; goto begin;}
    else if (scfeb.compare("alct_txd"  )==0) {ddd_chip=0; ddd_channel=1; goto begin;}
    else if (scfeb.compare("dmb_txd"   )==0) {ddd_chip=0; ddd_channel=2; goto begin;}
    else if (scfeb.compare("rpc_rxd"   )==0) {ddd_chip=0; ddd_channel=3; goto begin;}

    else if (scfeb.compare("alct_rxd"  )==0) {ddd_chip=1; ddd_channel=0; goto begin;}
    else if (scfeb.compare("cfeb_undef")==0) {ddd_chip=1; ddd_channel=1; goto begin;}
    else if (scfeb.compare("cfeb_tof"  )==0) {ddd_chip=1; ddd_channel=2; goto begin;}
    else if (scfeb.compare("cfeb_txc_0")==0) {ddd_chip=1; ddd_channel=3; goto begin;}

    else if (scfeb.compare("cfeb_txc_1")==0) {ddd_chip=2; ddd_channel=0; goto begin;}
    else if (scfeb.compare("cfeb_txc_2")==0) {ddd_chip=2; ddd_channel=1; goto begin;}
    else if (scfeb.compare("cfeb_txc_3")==0) {ddd_chip=2; ddd_channel=2; goto begin;}
    else if (scfeb.compare("cfeb_txc_4")==0) {ddd_chip=2; ddd_channel=3; goto begin;}

    else    {printf("\nDDD channel ID unknown: %s",scfeb.c_str()); pause ("<cr>");}

    // Get current DDD register value
begin:
    adr       = base_adr+vme_ddd0_adr+2*ddd_chip;
    status    = vme_read(adr,rd_data);
    ddd_delay = (rd_data >> (ddd_channel*4)) & 0xF;

    return ddd_delay;
}
//------------------------------------------------------------------------------------------
// End dddstr_rd
//------------------------------------------------------------------------------------------

