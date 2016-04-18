//------------------------------------------------------------------------------
// vme_io_vcc: Controls OSU VCC
///------------------------------------------------------------------------------
//  04/16/16 Initial write for VCC controller 
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------


static const unsigned char VME_READ  = 1;
static const unsigned char VME_WRITE = 2;
static const unsigned char VME_DELAY = 3;
static const unsigned char LATER     = 0;
static const unsigned char NOW       = 1;

int slot      = 14;
int boardtype = 2;

#include <cstdio>
#include "emu/pc/VMEController.h"
#include "vme_io_vcc.h"

//------------------------------------------------------------------------------
// Globals
//------------------------------------------------------------------------------

emu::pc::VMEController controller; 

//------------------------------------------------------------------------------
// vme_open:  opens Bit3 for A24D16
//------------------------------------------------------------------------------

long int vme_open()
{
    controller.SetMAC(0,"02-00-00-ff-ff-ff");  // mac address
    controller.SetMAC(1,"FF-FF-FF-FF-FF-FE");  // mcast 1
    controller.SetMAC(2,"FF-FF-FF-FF-FF-FD");  // mcast 2
    controller.SetMAC(3,"FF-FF-FF-FF-FF-FC");  // mcast 3
    controller.SetMAC(4,"A0-36-9F-4E-11-1E");  // default server mac

    controller.SetCR(0,"0050");     // ethernet cr
    controller.SetCR(1,"0002");     // external fifo cr
    controller.SetCR(2,"021B");     // reset/misc cr
    controller.SetCR(3,"EDFF1D0F"); // vme cr

    controller.init ("02:00:00:ff:ff:ff", 2); 
    //controller.start(1,0); 
    return 1; 
}   

//------------------------------------------------------------------------------
// vme_write:  writes A24D16 data
//--------------------------------------------------------------------
long int vme_write(unsigned long &adr, unsigned short &wr_data)
{
    char sndbuf[2] = {0,0};
    char rcvbuf[2] = {0,0};

    //printf("wr_adr: %8X\n", adr); 
    unsigned long offset = adr - (slot<<19); 
    //printf("wr_offset: %16X\n", offset); 

    controller.start(slot, boardtype); 
    controller.initDevice(1); // 1=ucla_ldev
    controller.goToScanLevel();


    sndbuf[0]=(wr_data>>8)&0xFF; 
    sndbuf[1]=(wr_data>>0)&0xFF; 

    unsigned short value_to_write = (sndbuf[1]&0xff) | (sndbuf[0]&0xff)<<8;
    unsigned short VME_BOOT_REG  = 0x04; 

    const unsigned long tmb_boot_adr = 0x070000;

    if (offset != tmb_boot_adr) 
        offset++; 

    // confirmed that this function gets executed identically between TriDAS software and this software, for 
    // equivalent writes. (wr_adr=0x6, wr_data=0x0)
    controller.new_vme(VME_WRITE, offset, wr_data, rcvbuf, NOW); // works
    //printf("tmb executing new_vme (%x,%x,%x,%x,%x)\n", VME_WRITE, offset, wr_data, rcvbuf[0], NOW); 


    //controller.do_vme(VME_WRITE, adr, sndbuf, rcvbuf, NOW);
    //  const unsigned long tmb_boot_adr = 0x070000;
    //  if (offset==tmb_boot_adr) {
    //      printf("boot adr write\n"); 
      //controller.do_vme (VME_WRITE | VME_BOOT_REG, 0, sndbuf, rcvbuf, NOW );
    //  }
    //  else  {
        //controller.new_vme(VME_WRITE, offset, value_to_write, rcvbuf, NOW);
        //controller.do_vme (VME_WRITE, offset, sndbuf, rcvbuf, NOW );
        //controller.do_vme (2, 0x070000, sndbuf, rcvbuf, NOW );
    //  }

    return 1; 
}

//------------------------------------------------------------------------------
// vme_read:  reads A24D16 data
//------------------------------------------------------------------------------
long int vme_read(unsigned long &adr, unsigned short &rd_data)
{

    //printf("rd_adr: %8X\n", adr); 
    unsigned long offset = adr - (slot<<19); 
    //printf("rd_offset: %8X\n", offset); 

    controller.start(slot, boardtype); 
    controller.initDevice(1); // 1=ucla_ldev
    controller.goToScanLevel();

    char sndbuf[2] = {0,0};
    char rcvbuf[2] = {0,0};

    const unsigned long tmb_boot_adr = 0x070000;
    unsigned short VME_BOOT_REG  = 0x04; 

//    if (offset != tmb_boot_adr) 
//        offset--;

    controller.new_vme(VME_READ, offset, 0x0000, rcvbuf, NOW);

    // if (offset==tmb_boot_adr)  {

    //     printf("boot adr read\n"); 
    //     controller.do_vme(VME_READ | VME_BOOT_REG, 0, sndbuf, rcvbuf, NOW ); // Send read request

    //     rd_data  = 0;
    //     rd_data |= rcvbuf[0]<<8;
    //     rd_data |= rcvbuf[1]<<0;

    //     printf("vme_read: %8x\n", rd_data); 
    // }
    // else {

    //     // controller.do_vme(VME_READ | VME_BOOT_REG, offset, sndbuf, rcvbuf, NOW ); // Send read request

    rd_data  = 0;
    rd_data |= 0x00ff & (rcvbuf[0]<<0);
    rd_data |= 0xff00 & (rcvbuf[1]<<8);

    //printf ("vme rd_data = %x\n", rd_data); 

    //     printf("vme_read: %8x\n", rd_data); 
    // }
    return 1; 
}

//------------------------------------------------------------------------------
// vme_bwrite:  writes A24D16 block data
//------------------------------------------------------------------------------
long int vme_bwrite(unsigned long &adr, unsigned short wr_data[], long &nwords)
{
    adr = adr - (18<<19); 
    for (int i=0; i<(nwords-1); i++) {
        controller.new_vme(VME_WRITE, adr, wr_data[i], NULL, LATER);
    }
    return controller.new_vme(VME_WRITE, adr, wr_data[nwords-1], NULL, NOW);
}

//------------------------------------------------------------------------------
// vme_bread:  reads A24D16 block data
//------------------------------------------------------------------------------
long int vme_bread(unsigned long &adr, unsigned short rd_data[], long &nwords)
{
    adr = adr - (18<<19); 
    for (int i=0; i<(nwords-1); i++) {
        //                 fcn,      vme, data, rcv,  when
        controller.new_vme(VME_READ, adr, 0,    NULL, LATER);
    }
    return controller.new_vme(VME_READ, adr, 0, (char*) &rd_data[0], NOW);
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
    controller.~VMEController(); 
    return 1;
}

//------------------------------------------------------------------------------
// vme_errs:    Change bus timeout error print
//              print_mode=0 prints bt errors
//              print_mode=1 suppresses error printing
//------------------------------------------------------------------------------
long int vme_errs(const int &print_mode)
{
    bool print_suppress = print_mode;

    return 1;
}
//------------------------------------------------------------------------------
// End vme_io.c
//------------------------------------------------------------------------------
