//------------------------------------------------------------------------------
// Check data read vs data expected
//------------------------------------------------------------------------------
#ifndef CK_H
#define CK_H
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
//------------------------------------------------------------------------------
//void    ck (std::string data_string, int data_read, int data_expect);
void    ck (std::string msg_string,  int data_read, int data_expect);
int     cks(std::string msg_string , int data_read, int data_expect);
//------------------------------------------------------------------------------
#endif
