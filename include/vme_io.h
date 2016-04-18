#ifndef VME_IO_H
#define VME_IO_H 
#ifdef __linux__
#include "vme_io_vcc.h"
#else
#include "vme_io_wxp.h"
#endif
#endif /* VME_IO_H */
