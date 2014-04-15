//------------------------------------------------------------------------------
// Check data read vs data expected
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include "ck.h"
#include <stdio.h>
#include <iostream>
#include "common.h"
//------------------------------------------------------------------------------
void ck (char *data_string, int data_read, int data_expect)
{
    if (data_read != data_expect) {
        fprintf(log_file,"Error in %s: read=%8.8X expect=%8.8X\n",data_string,data_read,data_expect);
        fprintf(stderr,  "Error in %s: read=%8.8X expect=%8.8X\n",data_string,data_read,data_expect);
        //	pause ("pausing in ck()");
    }

    return;
}

//------------------------------------------------------------------------------
//	Check data read vs data expected
//------------------------------------------------------------------------------
void ck(std::string msg_string, int data_read, int data_expect)
{	
    if (data_read != data_expect) {
        fprintf(stdout,  "ERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
        fprintf(log_file,"ERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
        //	pause(" ");
    }
    return;
}
//------------------------------------------------------------------------------
//	Check data read vs data expected, with status return
//------------------------------------------------------------------------------
int cks(std::string msg_string, int data_read, int data_expect)
{
    int status;

    status = 0;	// good return
    if (data_read != data_expect) {
        status = 1;	// bad return
        fprintf(stdout,  "\tERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
        fprintf(log_file,"\tERRm: in %s: read=%8.8X expect=%8.8X\n",msg_string.c_str(),data_read,data_expect);
        //	pause(" ");
    }

    return status;
}
//------------------------------------------------------------------------------
// The bitter end..
//------------------------------------------------------------------------------
