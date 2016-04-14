//------------------------------------------------------------------------------
#ifndef VME_JTAG_IO_OPS_H
#define VME_JTAG_IO_OPS_H
//------------------------------------------------------------------------------
//  Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include "pause.h"
#include "common.h"
using namespace std;


//------------------------------------------------------------------------------
//  Debug print mode
//------------------------------------------------------------------------------
//  #define debug_jtag_io_ops 1 // comment this line to turn off debug print

//------------------------------------------------------------------------------
//  Convert integer*4 word to 1 bit per byte for JTAG transmission
//  SPI=0 for FPGAs and PROMs
//  SPI=1 for DACs that take msb first
//------------------------------------------------------------------------------
void i4_to_tdi(long int &i4, char tdi[], const int &nbits, const int &spi);
void tdi_to_i4(char tdi[], long int &i4, const int &nbits,  const int &spi);
void vme_jtag_anystate_to_rti(unsigned long &adr, int &ichain);
void vme_jtag_write_ir(unsigned long &adr, int &ichain, int &chip_id, int &opcode);
void vme_jtag_write_dr(unsigned long &adr, int &ichain, int &chip_id, char wr_data[], char rd_data[], int &nbits);
bool vme_jtag_cable_detect (unsigned long &base_adr);
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
