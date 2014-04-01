#ifndef ADC_READ_MEZ_H
#define ADC_READ_MEZ_H
//------------------------------------------------------------------------------
//	Read TMB Spartan-6 Mezzanine ADC
//
//	Device is Texas Instruments TLV2543CDB
//
//	02/08/06 Ported from vmetst_v5
//	12/11/08 Port from vmetst_v7 fortran to c++
//	04/04/12 Port from TMB base board ADC for new Spartan-6 mezzanine ADC
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------

#include <stdio.h>
#include "vme_io_wxp.h"
#include <iostream>
//------------------------------------------------------------------------------
// Debug print mode
//------------------------------------------------------------------------------
//	#define debug 1	// comment this line to turn off debug print

#ifdef debug
#define dprintf fprintf
#else
#define dprintf
#endif

//------------------------------------------------------------------------------
// Entry adc_read()
//------------------------------------------------------------------------------
void			adc_read_mez (unsigned long &base_adr);
//------------------------------------------------------------------------------

#endif
