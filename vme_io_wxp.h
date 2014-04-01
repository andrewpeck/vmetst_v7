//------------------------------------------------------------------------------
// vme_io_wxp: Controls Bit3 for A24D16 read/write
//------------------------------------------------------------------------------
#ifndef VME_IO_WXP_H
#define VME_IO_WXP_H
//------------------------------------------------------------------------------
// BIT3 definitions
//------------------------------------------------------------------------------
#define BT973
#define BT_WINNT
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include    <stdio.h>
#include    "btapi.h"
//------------------------------------------------------------------------------
extern long int vme_open();
//--------------------------------------------------------------------
extern long int vme_write(unsigned long &adr, unsigned short &wr_data);
//------------------------------------------------------------------------------
extern long int vme_bwrite(unsigned long &adr, unsigned short wr_data[], long &nwords);
//------------------------------------------------------------------------------
extern long int vme_read(unsigned long &adr, unsigned short &rd_data);
//------------------------------------------------------------------------------
extern long int vme_bread(unsigned long &adr, unsigned short rd_data[], long &nwords);
//------------------------------------------------------------------------------
extern long int vme_sysreset();
//------------------------------------------------------------------------------
extern long int vme_close();
//------------------------------------------------------------------------------
extern long int vme_errs(const int &print_mode);
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
