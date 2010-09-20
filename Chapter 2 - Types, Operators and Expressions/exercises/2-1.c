#include <stdio.h>

int main()
{
	double d;
	float f = ~0 >> 1;
	unsigned char c = ~0;
	unsigned int i = ~0;
	unsigned long l = ~0;
	unsigned short s = ~0;

	d = ~0 >> 1; // Bit shift to the right (signed)
	printf("double = %.0f\n", d);
	d = i; // Convert to double for nicer formatting of size
	printf("unsigned int =  %.0f\n", d);
	d = l; // Convert to double for nicer formatting of size
	printf("unsigned long = %.0f\n", d);

	printf("float = %.0f\n", f);
	
	printf("char = %d\n", c);

	printf("int = (pos/neg) %d\n", i / 2);

	printf("long = (pos/neg) %ld\n", l / 2);

	printf("short = (pos/neg) %d\n", s / 2);
	printf("unsigned short = %d\n", s);
}
