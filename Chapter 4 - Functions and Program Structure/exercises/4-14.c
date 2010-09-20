#include <stdio.h>

#define swap(t, x, y) t z = x; x = y; y = z;

int main()
{
	int x = 1, y = 2;

	printf("x = %d, y = %d\n", x, y);
	swap(int, x, y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}
