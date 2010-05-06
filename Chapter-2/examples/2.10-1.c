#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
	unsigned int x;

	for (x = 0; x < 700; x++)
	{
		printf("%u: %d\n", x, bitcount(x));
	}
}

/**
 * Count 1 bits in x
 */
int bitcount(unsigned int x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01) b++;
	
	return b;
}
