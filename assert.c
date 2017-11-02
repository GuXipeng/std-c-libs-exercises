#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int func_a()
{
	assert(0);
	return 0;
}

int main()
{
	printf("call func_a\n");
	func_a();
	
	return 0;
}
