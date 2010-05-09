#include <stdio.h>

/* Rewrite the temperature conversion program of 
	Section␣1.2 to use a function for conversion. */

float to_celsius(int fahr);

int main()
{
	int i = 0;
	
	for (i = 0; i <= 300; i += 20)
		printf("%5d | %5.2f\n", i, to_celsius(i));
	
	return 0;
}

float to_celsius(int fahr)
{
	return (5.0/9.0) * (fahr - 32.0);
}
