#include <stdio.h>

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */

main()
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;		//Lower limit of temperature scale
	upper = 300;	//Upper limit
	step = 20;		//Step size
	
	fahr = lower;
	
	printf("Welcome to the Temperature conversion table!\n");
	printf("============================================\n");
	
	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}