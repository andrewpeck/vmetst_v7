//------------------------------------------------------------------------------
// vme_io_wxp: Controls Bit3 for A24D16 read/write
///------------------------------------------------------------------------------
//	11/21/01 Initial
//	04/29/05 Modified for WinXP BT984 driver, added lines to define BT973 and opsys, mod swapping
//	03/10/06 Add block write
//	03/23/06 Add error print suppression
//	10/06/08 Change vme calls from pointers to references
//	11/05/08 Replace extern "C" with extern for cpp caller
//	01/25/10 Add block read
//	01/25/10 Add A24D16 mode
//	01/05/11 Add vme_sysreset
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------

static const unsigned char VME_READ=1; 
static const unsigned char VME_WRITE=2;
static const unsigned char VME_DELAY=3; 
static const unsigned char LATER=0;
static const unsigned char NOW=1;


#include    "VMEController.h"
#include    "vme_io_vcc.h"

//------------------------------------------------------------------------------
// Globals
//------------------------------------------------------------------------------

emu::pc::VMEController controller; 

//------------------------------------------------------------------------------
// vme_open:  opens Bit3 for A24D16
//------------------------------------------------------------------------------

long int vme_open()
{
    //controller.init("FF:FF:FF:FF:FF:FF", 2); 
    controller.init(); 
    return 1; 
}	

//------------------------------------------------------------------------------
// vme_write:  writes A24D16 data
//--------------------------------------------------------------------
long int vme_write(unsigned long adr, unsigned short &wr_data)
{
    return controller.new_vme(VME_WRITE, adr, wr_data, NULL, NOW);
}

//------------------------------------------------------------------------------
// vme_bwrite:  writes A24D16 block data
//------------------------------------------------------------------------------
long int vme_bwrite(unsigned long &adr, unsigned short wr_data[], long &nwords)
{
    for (int i=0; i<(nwords-1); i++) {
        controller.new_vme(VME_WRITE, adr, wr_data[i], NULL, LATER);
    }
    return controller.new_vme(VME_WRITE, adr, wr_data[nwords-1], NULL, NOW);
}

//------------------------------------------------------------------------------
// vme_read:  reads A24D16 data
//------------------------------------------------------------------------------
long int vme_read(unsigned long &adr, unsigned short &rd_data)
{
    char *rcv; 
    controller.new_vme(VME_READ, adr, 0, rcv, NOW);
    rd_data = *rcv; 
    return 1; 
}

//------------------------------------------------------------------------------
// vme_bread:  reads A24D16 block data
//------------------------------------------------------------------------------
long int vme_bread(unsigned long &adr, unsigned short rd_data[], long &nwords)
{
    //for (int i=0; i<(nwords-1); i++) {
    //    controller.new_vme(VME_READ, adr, 0, NULL, LATER);
    //}
    //return controller.new_vme(VME_READ, adr, 0, &rd_data, NOW);
    return 1; 
}
//------------------------------------------------------------------------------
// vme_sysreset:  assert VME bus sysreset
//------------------------------------------------------------------------------
long int vme_sysreset()
{
    return 1;
}

//------------------------------------------------------------------------------
// vme_close:  closes Bit3 controller
//------------------------------------------------------------------------------
long int vme_close()
{
    return 1;
}

//------------------------------------------------------------------------------
// vme_errs:	Change bus timeout error print
//				print_mode=0 prints bt errors
//				print_mode=1 suppresses error printing
//------------------------------------------------------------------------------
long int vme_errs(const int &print_mode)
{
    bool print_suppress = print_mode;

    return 1;
}
//------------------------------------------------------------------------------
// End vme_io_wxp.c
//------------------------------------------------------------------------------
