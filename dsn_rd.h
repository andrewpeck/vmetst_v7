#ifndef DSN_RD_H
#define DSN_RD_H
//------------------------------------------------------------------------------
//	Calls dsn_io to read TMB digital serial numbers
//
//	01/04/02 Initial
//	11/13/08 Port to c++
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include "dsn_io.h"
//------------------------------------------------------------------------------
//	Debug print mode
//------------------------------------------------------------------------------
//	#define debug 1	// comment this line to turn off debug print
#ifdef debug
#define dprintf fprintf
#else
#define dprintf //
#endif
//------------------------------------------------------------------------------------------
void dsn_rd(unsigned long &vme_dsn_adr, const int &itype, int dsn[]);
//------------------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------------------
