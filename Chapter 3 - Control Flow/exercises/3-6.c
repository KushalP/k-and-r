#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	char buffer[1000];

	itoa(235, buffer, 10);
	printf("Number = %s\n", buffer);

	return 0;
}

void itoa(int n, char s[], int b)
{
	int i, sign;

	if ((sign = n) < 0) n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0) s[i++] = '-';

	s[i] = '\0';
	reverse(s);

	while (i < 1)
	{
		s[i] = ' ';
		i++;
	}

	s[i] = '\0';
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
