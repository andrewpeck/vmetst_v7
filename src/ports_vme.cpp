//------------------------------------------------------------------------------
//  ports_vme
//------------------------------------------------------------------------------
//  12/12/08 Ported from fortran version
//------------------------------------------------------------------------------
//  Headers
//------------------------------------------------------------------------------
    #define _CRT_SECURE_NO_WARNINGS 1
    #include <stdio.h>
    #include <time.h>
    #include <iostream>
    #include "ports_vme.h"
    #include "pause.h"
    #include "vme_io.h"
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
    void setPort(short p, short val)
//------------------------------------------------------------------------------
{
// Local
    static int      tms_bit;
    static int      tdi_bit;
    static int      tck_bit;

    static int      jtag_word;
    unsigned short  wr_data;
    unsigned long   status;
    long            nbytes;

    static int      step_unit;
    static int      step_count;
    double          pct_done;

    const short     TCK = 0;
    const short     TMS = 1;
    const short     TDI = 2;

// Debug
    unsigned short  data;
    int             itdi;
    int             itms;
    int             itck;
    int             ichain;

// Entry setPort
    dprintf(stdout,"setPort1: p=%3i val=%3i",p,val);
    dprintf(stdout,"xilinx_boot_adr=%6.6X xilinx_boot_data=%4.4X\n",xilinx_boot_adr,xilinx_boot_data);

    setport_calls=setport_calls+1;

    if (p==TMS) tms_bit = val;
    if (p==TDI) tdi_bit = val;

    if (p==TCK) {
    tck_bit   = val;
    jtag_word = (tdi_bit << 0) |
                (tms_bit << 1) |
                (tck_bit << 2);

    wr_data= (xilinx_boot_data & 0xFFF8) | jtag_word;
//  status=vme_write(xilinx_boot_adr,wr_data);

    data   = wr_data;
    itdi   = (data >> 0) & 0x1;
    itms   = (data >> 1) & 0x1;
    itck   = (data >> 2) & 0x1;
    ichain = (data >> 3) & 0xF;

    numwrites=numwrites+1;

    if (wlog)
    fprintf(log_file,"vme_write: %9i tck=%1i tms=%1i tdi=%1i ichain=%2.2X,adr=%6.6X data=%4.4X\n",
    numwrites,itck,itms,itdi,ichain,xilinx_boot_adr,data);

// display progress
    setport_writes = setport_writes+1;

    if (setport_writes==1) {    // first entry
    setport_nwords      = 0;
    setport_peak_nwords = 0;
    step_unit           = setport_writes_expected/1000;
    step_count          = 1;
    }

    if (setport_writes==step_count) {
    step_count = step_count+step_unit;
    pct_done   = 100.0*(float(setport_writes)/float(setport_writes_expected));
    printf("\tTCK cycles %5.1f%%\r",pct_done);
    }

// push write data onto stack
    setport_nwords = setport_nwords+1;
    setport_buffer[setport_nwords] = wr_data;

    if (setport_nwords==setport_mxnwords){      // buffer full, pop data off stack
    nbytes = 4*setport_nwords;                  // D32 transfers, alas
    status = vme_bwrite(xilinx_boot_adr,setport_buffer,nbytes); // block mode

//  for (i=1; i<=nbytes/4; ++i) {
//  status = vme_write(xilinx_boot_adr,setport_buffer[i]));
//  }
    if (setport_nwords > setport_peak_nwords) setport_peak_nwords = setport_nwords;
    setport_nwords = 0;
    }   // close setport_nwords

    }   // close tck
    return;
}

//------------------------------------------------------------------------------
    unsigned char readTDOBit()
//------------------------------------------------------------------------------
{
    unsigned long   status;
    unsigned short  rd_data;
    long            nbytes;
    int             i;
    unsigned char   tdo;

// purge write buffer
    if (setport_nwords != 0) {
    nbytes = 4*setport_nwords;

    dprintf(stdout,"\tBuffer purge nwords=%i\n",setport_nwords);
//  status = vme_bwrite(xilinx_boot_adr,setport_buffer,nbytes); // block writes here cause tdo errors, dunno why

    for (i=1; i<=setport_nwords; ++i) {
    status = vme_write(xilinx_boot_adr,setport_buffer[i]);
    }

    if(setport_nwords > setport_peak_nwords) setport_peak_nwords = setport_nwords;
    setport_nwords = 0;
    } //close if setport_nwords

// read tdo from boot
    setport_reads = setport_reads+1;

    status   = vme_read(xilinx_boot_adr,rd_data);
    tdo      = (rd_data >> 15) & 0x0001;
    numreads = numreads+1;

    if (wlog)
    fprintf(log_file,"vme_write: %9i adr=%6.6X tdo=%3i\n",numreads,xilinx_boot_adr,tdo);

    return tdo;
}
//------------------------------------------------------------------------------
    void setPortPrint(unsigned char cmdbyte)
//------------------------------------------------------------------------------
{
    string  cmd;

    if (!wlog) return;

    cmd = "Unknown....";

    switch (cmdbyte) {
    case 0x00: cmd = "XCOMPLETE  "; break;
    case 0x01: cmd = "XTDOMASK   "; break;
    case 0x02: cmd = "XSIR       "; break;
    case 0x03: cmd = "XSDR       "; break;
    case 0x04: cmd = "XRUNTEST   "; break;
    case 0x05: cmd = "XUNDEFINED5"; break;
    case 0x06: cmd = "XUNDEFINED6"; break;
    case 0x07: cmd = "XREPEAT    "; break;
    case 0x08: cmd = "XSDRSIZE   "; break;
    case 0x09: cmd = "XSDRTDO    "; break;
    case 0x0A: cmd = "XSETSDRMASK"; break;
    case 0x0B: cmd = "XSDRINC    "; break;
    case 0x0C: cmd = "XSDRB      "; break;
    case 0x0D: cmd = "XSDRC      "; break;
    case 0x0E: cmd = "XSDRE      "; break;
    case 0x0F: cmd = "XSDRTDOB   "; break;
    case 0x10: cmd = "XSDRTDOC   "; break;
    case 0x11: cmd = "XSDRTDOE   "; break;
    case 0x12: cmd = "XSTATE     "; break;
    case 0x13: cmd = "XENDIR     "; break;
    case 0x14: cmd = "XENDDR     "; break;
    case 0x15: cmd = "XSIR2      "; break;
    case 0x16: cmd = "XCOMMENT   "; break;
    }
    fprintf(log_file,"%s\tcmdbyte=%2.2X\n",cmd.c_str(),cmdbyte);

    return;
}
//------------------------------------------------------------------------------
    void pulseClock()
//------------------------------------------------------------------------------
{
    const short TCK = 0;

// Toggle TCK Low-to-High
    setPort(TCK,0); // set the TCK port to low
    setPort(TCK,1); // set the TCK port to high
}
//------------------------------------------------------------------------------
    void readByte(unsigned char *data)
//------------------------------------------------------------------------------
{
// Fetch next data byte from input file
    fscanf(xsvf_file,"%c",data);
}
//------------------------------------------------------------------------------
void waitTime(long microsec)
//------------------------------------------------------------------------------
{
    static long int tckCyclesPerMicrosec = 1;
    long int        tckCycles = 1;
    long int        i;

    dprintf(log_file,"waitTime = %i\n",microsec);

// For systems with TCK rates >= 1 MHz;  This implementation is fine
    for (i=0; i<tckCycles; ++i) {
    pulseClock();
    }
}
//------------------------------------------------------------------------------
// The bitter end
//------------------------------------------------------------------------------

