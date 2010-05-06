#include <stdio.h>

int rightrot(int x, int n);

int main()
{
	int x, n;

	for (x = 0; x < 700; x += 49)
	{
		for (n = 1; n < 8; n++)
		{
			printf("%d, %d: %d\n", x , n, rightrot(x, n));
		}
	}

	return 0;
}

/**
 * Return the value of integer x, rotated to the right by n bits
 */
int rightrot(int x, int n)
{
	while (n > 0)
	{
		// Is our number odd?
		if (x & 1 == 1)
		{
			// The second part of this OR isn't adding 0!
			// onto our value, but actually a single 1
			x = (x >> 1) | ~(~0U >> 1);
		}
		else
		{
			// Shift right by 1
			x = x >> 1;
		}

		n--;
	}
	
	return x;
}
