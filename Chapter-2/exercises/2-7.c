#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

int main()
{
	unsigned int x;
	int p, n;

	for (x = 0; x < 700; x += 49)
	{
		for (n = 1; n < 8; n++)
		{
			for (p = 1; p < 8; p++)
			{
				printf("%u, %d, %d: %u\n", x, n, p, invert(x, n, p));
			}
		}
	}

	return 0;
}

/**
 * Returns x with the n bits that begin at position
 * p inverted, leaving the others unchanged
 */
unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
	// Create a series of n 1 bits to the right of
	// position p
	int mask = (~(~0U << n) << p);

	// Flip the bits in x that have a corresponding
	// 1 in the mask
	return (x ^ mask);
}
