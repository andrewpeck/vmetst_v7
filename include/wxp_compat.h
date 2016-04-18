#ifndef WXP_COMPAT_H
#define WXP_COMPAT_H

#ifdef __linux__

#include <string.h>
#include <string>
#include <inttypes.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

typedef int64_t __int64;

#define _stat stat

#define _cpp_min(...)  min(__VA_ARGS__)
#define _cpp_max(...)  max(__VA_ARGS__)
#define _strnicmp(...) strncasecmp(__VA_ARGS__)


void _strtime (std::string the_time);
void _strdate (std::string the_date);
bool GetComputerName (std::string buffer, long unsigned int *size);
int ExpandEnvironmentStrings(std::string in, std::string out, int size);
void Beep (int a, int b);
int _kbhit(void);
char _getch();

#endif /* linux */

#endif /* WXP_COMPAT_H */
