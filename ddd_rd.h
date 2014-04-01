//------------------------------------------------------------------------------
//	Reads 3D3444 delay from VME register
//------------------------------------------------------------------------------
#ifndef DDD_RD_H
#define DDD_RD_H
//------------------------------------------------------------------------------
#include "vme_io_wxp.h"
//------------------------------------------------------------------------------------------
int ddd_rd(unsigned long base_adr, const int ddd_chip, const int ddd_channel);
//------------------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------------------
