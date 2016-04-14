#ifndef JTAG_IO_H
#define JTAG_IO_H
//------------------------------------------------------------------------------
long int jtag_read (unsigned long &adr, int &ichain, int &chip_id, 
        int &opcode, int &reg_len, unsigned short &rd_data);
//------------------------------------------------------------------------------
long int jtag_write (unsigned long &adr, int &ichain, int &chip_id, 
        int &opcode, int &reg_len, unsigned short &wr_data);
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
