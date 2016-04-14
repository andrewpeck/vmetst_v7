//------------------------------------------------------------------------------
//  JTAG register read/write that looks like the VME version
//
//  05/03/2012  Initial
//
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include <string>
#include "vme_jtag_io_ops.h"
#include "jtag_io.h"
#include "pause.h"
using namespace std;

//------------------------------------------------------------------------------------------
// JTAG register read that looks like the VME version
//------------------------------------------------------------------------------------------
long int jtag_read (unsigned long &adr, int &ichain, int &chip_id, int &opcode, int &reg_len, unsigned short &rd_data)
{
    char tdi[32]={0};
    char tdo[32]={0};
    long i4;

    vme_jtag_write_ir(adr,ichain,chip_id,opcode);           // Set opcode
    vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);  // Write 0's read register contents

    tdi_to_i4(&tdo[0],i4,reg_len,0);                        // Convert tdo to integer               

    rd_data = (unsigned short)i4;

    return 0;
}

//------------------------------------------------------------------------------------------
// JTAG register write that looks like the VME version
//------------------------------------------------------------------------------------------
long int jtag_write (unsigned long &adr, int &ichain, int &chip_id, int &opcode, int &reg_len, unsigned short &wr_data)
{
    char tdi[32]={0};
    char tdo[32]={0};
    long i4;

    i4_to_tdi(i4=wr_data,&tdi[0],reg_len,0);                // Convert integer to tdi bit array

    vme_jtag_write_ir(adr,ichain,chip_id,opcode);           // Set opcode
    vme_jtag_write_dr(adr,ichain,chip_id,tdi,tdo,reg_len);  // Write register contents

    return 0;
}
//------------------------------------------------------------------------------------------
// The bitter end...
//------------------------------------------------------------------------------------------
