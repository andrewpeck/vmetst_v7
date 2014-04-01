#ifndef CFEBBX_RD_H
#define CFEBBX_RD_H
//------------------------------------------------------------------------------
//	Reads CFEB nbx Interstage Delay Settings
//
//	08/14/09 Ported from posneg_rd
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include "vme_io_wxp.h"
#include "pause.h"

//------------------------------------------------------------------------------
int cfebbx_rd(unsigned long &base_adr, const std::string scfeb);
//------------------------------------------------------------------------------
#endif
