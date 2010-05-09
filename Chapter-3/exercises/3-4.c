#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
	char buffer[20];

	printf("INT_MIN: %d\n", INT_MIN);
	itoa(INT_MIN, buffer);
	printf("Buffer: %s\n", buffer);

	return EXIT_SUCCESS;
}

void itoa(int n, char s[])
{
	int i, sign;

	// Record sign
	if ((sign = n) < 0) n = -n; // Make n positive

	i = 0;
	do {
		// Generate digits in reverse order
		s[i++] = n % 10 + '0'; // Get next digit
	} while ((n /= 10) > 0); // Delete it

	if (sign < 0) s[i++] = '-';

	s[i] = '\0';

	reverse(s);
}

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
