#ifndef IDCODE_DECODE_H
#define IDCODE_DECODE_H
//------------------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
//------------------------------------------------------------------------------------------
void idcode_decode
(
 long	&idcode,
 std::string	&sdevice_type,
 std::string	&sdevice_name,
 std::string	&sdevice_version,
 std::string	&sdevice_size
 );
//------------------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------------------
