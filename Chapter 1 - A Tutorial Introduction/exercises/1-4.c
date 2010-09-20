#include <stdio.h>

/*
	print Celsius-Fahrenheit table
*/
int main()
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;		//Lower limit of temperature scale
	upper = 100;	//Upper limit
	step = 1;		//Step size
	
	fahr = lower;
	
	printf("%10s\t%12s\n", "Celsius", "Fahrenheit");
	
	while (celsius <= upper)
	{
		fahr = (9.0/5.0) * (celsius+32);
		printf("%10.0f\t%11.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}
