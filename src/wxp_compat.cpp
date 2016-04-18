#include "wxp_compat.h"
#include <string>

#include <cstdlib>
#include <time.h>

// formats time in hh:mm:ss
void _strtime (std::string thetime) {

	time_t t;
	struct tm *tm_tmp;

	char time_cstring [] = "hh:mm:ss"; 

	t = time(NULL);
	tm_tmp = localtime(&t);
	if (tm_tmp == NULL) {
		perror("localtime");
		exit(EXIT_FAILURE);
	}

	if (strftime(time_cstring, sizeof(time_cstring), "%H:%M:%S", tm_tmp) == 0) {
		fprintf(stderr, "strftime returned 0");
		exit(EXIT_FAILURE);
	}

	thetime = time_cstring; 
}

void _strdate (std::string the_date) {

	time_t t;
	struct tm *tm_tmp;

	char date_cstring [] = "yy/mm/dd"; 

	t = time(NULL);

	tm_tmp = localtime(&t);
	if (tm_tmp == NULL) {
		perror("localtime");
		exit(EXIT_FAILURE);
	}

	if (strftime(date_cstring, sizeof(date_cstring), "%Y/%m/%d", tm_tmp) == 0) {
		fprintf(stderr, "strftime returned 0");
		exit(EXIT_FAILURE);
	}

	the_date = date_cstring; 

}

bool GetComputerName (std::string buffer, long unsigned int *size) {
    buffer = "linux"; 
    return true; 
}

int ExpandEnvironmentStrings(std::string in, std::string out, int size) {
    out = in; 
    return 1; 
}

// beep does not exist on systems past mswinXP 32bit... beep through speakers instead ? 
void Beep (int a, int b)  {

}; 

 
int _kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}


char _getch(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
 }
