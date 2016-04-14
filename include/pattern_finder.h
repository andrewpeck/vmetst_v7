#ifndef PATTERN_FINDER_H
#define PATTERN_FINDER_H
//------------------------------------------------------------------------------
// Headers
//------------------------------------------------------------------------------
#include "pattern_unit.h"
#include "pause.h"

//------------------------------------------------------------------------------
//  Debug print mode
//------------------------------------------------------------------------------
//  #define debug 1 // comment this line to turn off debug print

    #ifdef debug
     #define dprintf fprintf
    #else
     #define dprintf //
    #endif
//------------------------------------------------------------------------------
    void pattern_finder 
    (
// Inputs
    int hs[6][160], 

    int &csc_type, 
    int &clct_sep, 
    int &adjcfeb_dist,
    int &layer_trig_en,
    int cfeb_en[5],
int &hit_thresh_pretrig, int &pid_thresh_pretrig,
    int &dmb_thresh_pretrig,
    int &lyr_thresh_pretrig,

// Outputs
    int cfeb_active[5],
    int &nlayers_hit,
    int &layer_trig,

    int &hs_key_1st,
    int &hs_pid_1st,
    int &hs_hit_1st,
 
    int &hs_key_2nd,
    int &hs_pid_2nd,
    int &hs_hit_2nd
    );
//------------------------------------------------------------------------------------------
int arr_or (int array[32]);
//------------------------------------------------------------------------------------------
int *arr_and(int array1[32], int array2[32]);
//------------------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------------------
