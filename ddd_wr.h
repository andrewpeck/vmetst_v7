//------------------------------------------------------------------------------
#ifndef DDD_WR_H
#define DDD_WR_H
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
//------------------------------------------------------------------------------
//	Debug print mode
//------------------------------------------------------------------------------
//	#define debug 1	// comment this line to turn off debug print
#ifdef debug
#define dprintf fprintf
#else
#define dprintf
#endif
//------------------------------------------------------------------------------------------
void ddd_wr(unsigned long &base_adr, const int &ddd_chip, const int &ddd_channel, const int &ddd_delay);
//------------------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------------------