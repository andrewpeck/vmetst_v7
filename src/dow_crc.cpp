//------------------------------------------------------------------------------------------
//
//  Calculate CRC x**8 + x**5 +X**4+1
//  for 7-byte Dallas Semi i-button data
//
//  01/04/02 Initial
//  11/13/08 Port to c++
//------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------------------
#include "dow_crc.h"
//------------------------------------------------------------------------------------------
// Entry dow_crc(in,crc)
//------------------------------------------------------------------------------------------
void dow_crc(int in[7], int &crc)
{
    int sr[8];
    int b;
    int x8;
    int ibit;
    int ibyte;
    int i;

    // Initialize crc shift register
    x8 = 0;
    for (ibit=0; ibit<=7; ibit++) {
        sr[ibit] = 0;
    }

    // Loop over 56 data bits, LSB first
    for (ibyte=0; ibyte<=6; ibyte++) {
        for (ibit=0;  ibit <=7; ibit++ ) {
            b = (in[ibyte] >> ibit) & 0x1;

            x8=b  ^ sr[7];
            sr[7] = sr[6];
            sr[6] = sr[5];
            sr[5] = sr[4] ^ x8;
            sr[4] = sr[3] ^ x8;
            sr[3] = sr[2];
            sr[2] = sr[1];
            sr[1] = sr[0];
            sr[0] = x8;
        }}

    // Pack shift register into a byte
    crc = 0;
    for (i=0; i<=7; i++) {
        crc = crc | (sr[i] << (7-i));
    }

    return;
}
//------------------------------------------------------------------------------------------
// End dow-crc
//------------------------------------------------------------------------------------------
