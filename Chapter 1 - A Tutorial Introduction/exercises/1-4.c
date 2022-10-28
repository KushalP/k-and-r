#include <stdio.h>

/*
 * Printf Celsius-Fahrenheit table.
 */

int main (void)
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;      // Lower limit of temperature scale.
	upper = 100;    // Upper limit.
	step  = 1;      // Step size.

	printf("Celsius\t\tFahrenheit\n");

	fahr = lower;
	while (celsius <= upper)
	{
		fahr = ((9.0/5.0) * celsius) + 32;
		printf("%3.0f\t\t%6.1f\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}
