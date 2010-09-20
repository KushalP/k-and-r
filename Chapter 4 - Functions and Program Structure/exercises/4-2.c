#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

double atof(char s[]);

int main()
{
	printf("%f\n", atof("123e-3"));
	return 0;
}

double atof(char s[])
{
	double val, power;
	int i, j, sign, exponentsign;
	char exponent[MAXLINE];

	for (i = 0; isspace(s[i]); i++)
		; //skips whitespace

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power /= 10.0;
	}

	// this exponent bit can probably be shrunk a lot
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
		power *= pow(10, atof(exponent));

		if (s[i] == '-')
		{
			exponentsign = -1;
			i++;
		}
		else
		{
			exponentsign = 1;
		}

		for (j = 0; s[i] != '\0'; i++, j++)
			exponent[j] = s[i];

		exponent[j] = '\0';

		if (exponentsign > 0)
		{
			power *= pow(10, atof(exponent));
		}
		else
		{
			power /= pow(10, atof(exponent));
		}
	}

	return sign * val * power;
}
