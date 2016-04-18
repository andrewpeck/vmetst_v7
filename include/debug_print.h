#ifndef DEBUG_PRINT_H

#ifdef debug
    #define dprintf(...) fprintf(__VA_ARGS__)
#else
    #define dprintf(...)
#endif

//#ifdef debug
//#define dprintf fprintf
//#else
//#define dprintf if (1) {} else fprintf
//#endif
//#define DEBUG_PRINT_H 

#endif /* DEBUG_PRINT_H */
