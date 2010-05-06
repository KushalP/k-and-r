#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
	unsigned int x;

	for (x = 0; x < 700; x++)
		printf("%u: %d\n", x, bitcount(x));
	
	return 0;
}

int bitcount(unsigned int x)
{
	int b;

	// Go through dropping off the rightmost 1-bit
	// each time
	for (b = 0; x != 0; x &= (x - 1)) b++;

	return b;
}
