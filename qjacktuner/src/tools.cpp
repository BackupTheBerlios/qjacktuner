#include <stdio.h>
#include "tools.h"



void _Perror(const char * File, int Line)
{
	char FileLine[256];
	sprintf(FileLine, "%s, %i", File, Line);
	perror(FileLine);
}
