//------------------------------------------------------------------------------
//	Generates SMB serial clock and data streams to TMB LM84 chip
//------------------------------------------------------------------------------
#ifndef SMB_WRITE_H
#define SMB_WRITE_H
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "vme_io_wxp.h"
//------------------------------------------------------------------------------
//	Debug print mode
//------------------------------------------------------------------------------
//	#define debug 1	// comment this line to turn off debug print
#ifdef debug
#define dprintf fprintf
#else
#define dprintf //
#endif
//------------------------------------------------------------------------------
void smb_write(unsigned long &adc_adr, int &smb_adr, int &smb_cmd, int &smb_data);
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
