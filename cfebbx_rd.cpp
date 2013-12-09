//------------------------------------------------------------------------------
//	Reads CFEB nbx Interstage Delay Settings
//
//	08/14/09 Ported from posneg_rd
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
	#include <stdio.h>
	#include <iostream>
	using namespace std;

//------------------------------------------------------------------------------
//	Prototypes
//------------------------------------------------------------------------------
	long int	vme_read	(unsigned long &adr, unsigned short &rd_data);
	void		pause		(string s);

//------------------------------------------------------------------------------------------
// Function cfebbx_rd(base_adr, scfeb) returns nbx delay
//---------------------------------------------------------------------------------------------------------
	int cfebbx_rd(unsigned long &base_adr, const string scfeb)
//---------------------------------------------------------------------------------------------------------
{
// VME addresses
	const unsigned long	delay0_is_adr		=0x00011C;
	const unsigned long	delay1_is_adr		=0x00011E;

// VME calls
	unsigned long	adr;
	unsigned short	rd_data;
	long			status;

// Local
	int				adr_offset;
	int				bank;
	int				nbx_delay;

//------------------------------------------------------------------------------
// Read posneg value for selected DCM
//------------------------------------------------------------------------------
// Determine DDD VME address

	if		(scfeb.compare("cfeb_nbx_0")==0) {adr_offset=0; bank=0; goto begin;}
	else if	(scfeb.compare("cfeb_nbx_1")==0) {adr_offset=0; bank=1; goto begin;}
	else if	(scfeb.compare("cfeb_nbx_2")==0) {adr_offset=0; bank=2; goto begin;}
	else if	(scfeb.compare("cfeb_nbx_3")==0) {adr_offset=0; bank=3; goto begin;}

	else if	(scfeb.compare("cfeb_nbx_4")==0) {adr_offset=1; bank=0; goto begin;}
	else if (scfeb.compare("alct_nbx"  )==0) {adr_offset=1; bank=1; goto begin;}

	else	{printf("\nNBX Interstage delay channel ID unknown: %s",scfeb.c_str()); pause ("<cr>");}

// Get current Interstaregister value
begin:
	adr		  = base_adr+delay0_is_adr+2*adr_offset;
	status 	  = vme_read(adr,rd_data);
	nbx_delay = (rd_data >> (bank*4)) & 0xF;

	return nbx_delay;
}
//------------------------------------------------------------------------------------------
// End cfebbx_rd
//------------------------------------------------------------------------------------------
