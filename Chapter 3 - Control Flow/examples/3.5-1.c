#include <stdio.h>
#include <ctype.h>

int atoi2(char s[]);

int main()
{
	char* s = "3";

	printf("Char '%c' = %d\n", *s, atoi2(s));

	return 0;
}

/* atoi2: convert s to integer; version 2 */
int atoi2(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
	{
		// Skip whitespace
	}

	sign = (s[i] == '-') ? -1 : 1;


	// Skip sign
	if (s[i] == '+' || s[i] == '-') i++;

	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;
}
