//------------------------------------------------------------------------------
//  Read TMB Spartan-6 Mezzanine ADC
//
//  Device is Texas Instruments TLV2543CDB
//
//  02/08/06 Ported from vmetst_v5
//  12/11/08 Port from vmetst_v7 fortran to c++
//  04/04/12 Port from TMB base board ADC for new Spartan-6 mezzanine ADC
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include "vme_io.h"
#include "common.h"
using namespace std;

//------------------------------------------------------------------------------
// Debug print mode
//------------------------------------------------------------------------------
//  #define debug 1 // comment this line to turn off debug print

#include "debug_print.h"

//------------------------------------------------------------------------------
// Entry adc_read()
//------------------------------------------------------------------------------
void            adc_read_mez (unsigned long &base_adr)
{
    // VME address
    const unsigned long vme_adc_adr = 0x000024;

    // Local
    long            status;
    unsigned long   adr;
    unsigned short  rd_data;
    unsigned short  wr_data;

    int             ich;
    int             adc_sdo;
    int             adc_sck;
    int             adc_sdi;
    int             adc_ncs;
    int             adc_shiftin;
    int             adc_counts[14];
    int             iclk;

    //------------------------------------------------------------------------------
    //  Read Spartan-6 Mezzanine ADC Channels
    //------------------------------------------------------------------------------
    // Loop over 14 ADC channels of 12 adc clock cycles each, plus 1 more cycle to read last channel
    adr = vme_adc_adr+base_adr;

    for (ich=0; ich<=14; ++ich) {
        adc_sdo     = 0;
        adc_shiftin = (ich << 4);       // d[7:4]=channel, d[3:2]=length, d[1:0]=ldbf,bip
        if(ich >= 0xE) adc_shiftin = 0; // Don't send channel 14, it is power-down

        // Take ADC cs high, clock low
        adc_sck = 0;
        adc_sdi = 0;
        adc_ncs = 1;

        wr_data = 0x0000;
        wr_data = wr_data | (adc_sck << 13);
        wr_data = wr_data | (adc_sdi << 14);
        wr_data = wr_data | (adc_ncs << 15);
        status  = vme_write(adr,wr_data);

        // Loop over 12 adc clocks, for 12-bit, unipolar format
        for (iclk=0; iclk<=11; ++iclk) {

            // Clock low: output channel number for next cycle, msb first       
            if (iclk <= 7)  adc_sdi = (adc_shiftin >> (7-iclk)) & 0x1;
            else            adc_sdi = 0;

            adc_sck = 0;
            adc_ncs = 0;

            wr_data = 0x0000;
            wr_data = wr_data | (adc_sck << 13);
            wr_data = wr_data | (adc_sdi << 14);
            wr_data = wr_data | (adc_ncs << 15);
            status  = vme_write(adr,wr_data);

            // Clock high: send channel number for next cycle
            adc_sck = 1;
            adc_ncs = 0;

            wr_data = 0x0000;
            wr_data = wr_data | (adc_sck << 13);
            wr_data = wr_data | (adc_sdi << 14);
            wr_data = wr_data | (adc_ncs << 15);
            status  = vme_write(adr,wr_data);

            // Clock high: read ADC data for previous channel, msb first
            status   = vme_read(adr,rd_data);
            rd_data  = (rd_data >> 12) & 0x1;
            adc_sdo = adc_sdo | (rd_data << (11-iclk));
        }   // close iclk

        // Take ADC cs high, clock low
        adc_sck = 0;
        adc_sdi = 0;
        adc_ncs = 1;

        wr_data = 0x0000;
        wr_data = wr_data | (adc_sck >> 13);
        wr_data = wr_data | (adc_sdi >> 14);
        wr_data = wr_data | (adc_ncs >> 15);
        status  = vme_write(adr,wr_data);

        // Close channel loop
        if (ich >= 1) { 
            adc_counts[ich-1]  = adc_sdo;
            adc_voltage_mez[ich-1] =(float(adc_sdo)/float(4095))*(2.500*(4.095/4.096));
            dprintf(stdout,"\tCh=%1X data=%8.8X %6.3f\n",ich-1,adc_sdo,adc_voltage_mez[ich-1]);
        }   // close if  ich
    }   // close for ich

    // Convert ADC counts to voltages and currents
    v3p3_mez  = adc_voltage_mez[ 0]*2.0;        // 1v/2v
    v2p5_mez  = adc_voltage_mez[ 1]*2.0;        // 1v/2v
    vcore_mez = adc_voltage_mez[ 2];            // 1v/1v
    v1p8_mez  = adc_voltage_mez[ 3];            // 1v/1v
    v1p2_mez  = adc_voltage_mez[ 4];            // 1v/1v
    tfpga_mez =(adc_voltage_mez[ 5]-0.5)*100.0; // 10mv/C+500mV 25C=750mV
    tsink_mez =(adc_voltage_mez[ 6]-0.5)*100.0; // 10mv/C+500mV 25C=750mV
    vch07_mez = adc_voltage_mez[ 7];            // 1v/1v
    vch08_mez = adc_voltage_mez[ 8];            // 1v/1v
    vch09_mez = adc_voltage_mez[ 9];            // 1v/1v
    vch10_mez = adc_voltage_mez[10];            // 1v/1v
    vref2_mez = adc_voltage_mez[11];            // 1v/1v
    vzero_mez = adc_voltage_mez[12];            // 1v/1v
    vref_mez  = adc_voltage_mez[13];            // 1v/1v

    return;
}
