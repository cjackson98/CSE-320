/******************************************************************************
 Example #8 -- Demonstrate the use of "getchar" and "putchar"
******************************************************************************/
#include <stdio.h>
int main()
{
	int input;
	for (;;)
	{
		input = getchar();
		if (input == EOF) break;
		putchar( input );
	}
	return 0;
}
