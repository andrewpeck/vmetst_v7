//------------------------------------------------------------------------------
//
//  Generates SMB serial clock and data streams to TMB LM84 chip
//
//  SMB requires that serial data is stable while clock is high,
//  so data transitions occur while clock is low,
//  midway between clock falling edge and rising edge
//
//  12/10/01 Initial
//  11/12/08 Port to C++
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "smb_write.h"
#include "vme_io_wxp.h"
#include "common.h"
using namespace std;

//------------------------------------------------------------------------------
//  Debug print mode
//------------------------------------------------------------------------------
//  #define debug 1 // comment this line to turn off debug print

#ifdef debug
#define dprintf fprintf
#else
#define dprintf //
#endif

//------------------------------------------------------------------------------
//  Prototypes
//------------------------------------------------------------------------------
void            sleep           (clock_t msec);

//------------------------------------------------------------------------------
// Entry smb_write(adc_adr,smb_adr,smb_cmd,smb_data)
//------------------------------------------------------------------------------
void smb_write(unsigned long &adc_adr, int &smb_adr, int &smb_cmd, int &smb_data)
    //------------------------------------------------------------------------------
{
    string annotate[29]={
        "START",
        "A6   ","A5   ","A4   ","A3   ","A2   ","A1   ","A0   ","0    ","ACK  ",
        "C7   ","C6   ","C5   ","C4   ","C3   ","C2   ","C1   ","C0   ","NACK ",
        "D7   ","D6   ","D5   ","D4   ","D3   ","D2   ","D1   ","D0   ","NACK ",
        "STOP "
    };

    long            status;
    unsigned long   adr;
    unsigned short  rd_data;
    unsigned short  wr_data=0;

    int             i2c_clock;
    int             sda_clock;
    int             scl_clock;
    int             sda_bit[29];
    int             sda;
    int             scl;

    int             adc_status;
    int             nclks;

    //  Get current ADC register state
    adr        = adc_adr;
    status     = vme_read(adr,rd_data);
    adc_status = rd_data;

    // Intialize SMB data stream
    sda_bit[ 0] = 0;                            // Start
    sda_bit[ 1] = (smb_adr >> 6) & 0x1;         // A6
    sda_bit[ 2] = (smb_adr >> 5) & 0x1;         // A5
    sda_bit[ 3] = (smb_adr >> 4) & 0x1;         // A4
    sda_bit[ 4] = (smb_adr >> 3) & 0x1;         // A3
    sda_bit[ 5] = (smb_adr >> 2) & 0x1;         // A2
    sda_bit[ 6] = (smb_adr >> 1) & 0x1;         // A1
    sda_bit[ 7] = (smb_adr >> 0) & 0x1;         // A0
    sda_bit[ 8] = 0;                            // 0=write command register
    sda_bit[ 9] = 1;                            // ACK
    sda_bit[10] = (smb_cmd >> 7) & 0x1;         // C7
    sda_bit[11] = (smb_cmd >> 6) & 0x1;         // C6
    sda_bit[12] = (smb_cmd >> 5) & 0x1;         // C5
    sda_bit[13] = (smb_cmd >> 4) & 0x1;         // C4
    sda_bit[14] = (smb_cmd >> 3) & 0x1;         // C3
    sda_bit[15] = (smb_cmd >> 2) & 0x1;         // C2
    sda_bit[16] = (smb_cmd >> 1) & 0x1;         // C1
    sda_bit[17] = (smb_cmd >> 0) & 0x1;         // C0
    sda_bit[18] = 1;                            // ACK
    sda_bit[19] = (smb_data >> 7) & 0x1;        // D7 write data register
    sda_bit[20] = (smb_data >> 6) & 0x1;        // D6
    sda_bit[21] = (smb_data >> 5) & 0x1;        // D5
    sda_bit[22] = (smb_data >> 4) & 0x1;        // D4
    sda_bit[23] = (smb_data >> 3) & 0x1;        // D3
    sda_bit[24] = (smb_data >> 2) & 0x1;        // D2
    sda_bit[25] = (smb_data >> 1) & 0x1;        // D1
    sda_bit[26] = (smb_data >> 0) & 0x1;        // D0
    sda_bit[27] = 1;                            // ACK
    sda_bit[28] = 0;                            // Stop

    // Construct SMBclk and SMBdata
    nclks = 115;

    for (i2c_clock=0;i2c_clock<=nclks; ++i2c_clock) {   // 200KHz
        sda_clock = (i2c_clock+0)/4;                        //  50KHz
        scl_clock = (i2c_clock+1)/2;                        //  50KHz shifted 1/2 of a 100KHz cycle

        scl = scl_clock & 0x1;              // toggle clock 0/1
        sda = sda_bit[sda_clock];           // serial data

        if (i2c_clock < 3) scl = 1;         // START scl stays high
        if (i2c_clock < 2) sda = 1;         // START sda transitions low

        if (i2c_clock > (nclks-3)) scl = 1; // STOP scl stays high
        if (i2c_clock > (nclks-2)) sda = 1; // STOP sda transitions high

        dprintf(log_file,"i2c_clock=%3i scl=%3i sda=%3i cmd=%s\n",i2c_clock,scl,sda,annotate[sda_clock].c_str());

        // Write Serial clock and data to TMB VME interface
        wr_data = adc_status & 0xF9FF;      // Clear bits 9 and 10
        wr_data = wr_data | (scl <<  9);
        wr_data = wr_data | (sda << 10);

        status  = vme_write(adr,wr_data);

        // Adjust wait time so scl is 50KHz or slower
        //  sleep(1);   // milliseconds
    }           // close i2c_clock
}
//------------------------------------------------------------------------------
// End smb_write()
//------------------------------------------------------------------------------
