/* test assert macro */
#define NDEBUG
#include "assert.h"
//#include <assert.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

/* static data */
static int val = 0;

static void field_abort(int sig)
{ /* handle SIGABRT */
	if (1 == val) {
		puts("Success testing <assert.h>");	
		exit(EXIT_SUCCESS);
	} else {
		puts("Failure testing <assert.h>");	
		exit(EXIT_FAILURE);
	}
}

static void dummy()
{ /* test dummy assert macro */
	int i = 0;

	assert(i == 0);
	assert(i == 1);
}

#undef NDEBUG
//#include <assert.h>
#include "assert.h"

int main()
{ /* test both dummy and working forms */
	assert(signal(SIGABRT, &field_abort) != SIG_ERR);
	dummy();
	assert(0 == val); /* should not abort */
	++val;
	fputs("Sample assertion failure message --\n", stderr);
	assert(0 == val); /* should abort */
	puts("Failure testing <assert.h>");

	return (EXIT_FAILURE);
	
}
