/* _Assert function */
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

void _Assert(char *mesg)
{ /* print assertion message and abort */
	fputs(mesg, stderr);
	fputs(" -- assertion failed\n", stderr);
	abort();
}
