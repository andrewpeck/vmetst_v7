//------------------------------------------------------------------------------
// Pause emulator cuz C sux
//------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include "stop.h"
using namespace std;

void stop (string s)
{
    fprintf(stdout,"%s %s","\tSTOP:",s.c_str());
    char dummy=getchar();
    exit(EXIT_FAILURE);
}
//------------------------------------------------------------------------------
