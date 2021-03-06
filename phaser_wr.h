//------------------------------------------------------------------------------
#ifndef PHASER_WR_H
#define PHASER_WR_H
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include "vme_io_wxp.h"
#include "pause.h"
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
void phaser_wr(unsigned long &base_adr, const std::string phaser_bank, const int &phaser_delay, const int &phaser_delta);
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
