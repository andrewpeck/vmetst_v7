//------------------------------------------------------------------------------------------
//	LFSR emulates firmware linear feedback shift register
//
//	08/31/09 Initial
//
//------------------------------------------------------------------------------------------
	#include <stdio.h>

	void lfsr_rng(const int &reset, __int64	&lfsr)
{

// LFSR Random Pattern Generator
	__int64	lfsr_seed = 0x123456789ABCD;
	__int64	feedback;

	if (reset) lfsr = lfsr_seed;
	else {
	feedback = 0x1 & (~(((lfsr >> 49) & 0x1) ^ ((lfsr >> 39) & 0x1)));
	lfsr     = ((lfsr << 1) | feedback) & 0x1FFFFFFFFFFFF;
	}
	return;
}	
//------------------------------------------------------------------------------------------
// End lfsr_rng.cpp
//------------------------------------------------------------------------------------------
