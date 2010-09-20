#include <stdio.h>
#define MAXLINE 1000

int itoa(char string[], int number, int startposition);

int main()
{
    char number[MAXLINE];

    itoa(number, -2356, 0);
    printf("%s\n", number);

	return 0;
}

/**
 * itoa: converts an integer to a string
 *
 * assumes the string passed to it is of
 * sufficient length, returns the length
 * of the string.
 */
int itoa(char s[], int n, int i)
{
    if (n < 0)
	{
        s[i++] = '-';
        n = -n;
    }

	if (n / 10)
	{
        i = itoa(s, n / 10, i);
        s[i++] = n % 10 + '0';
    }
	else
	{
        s[i++] = n % 10 + '0';
        s[i] = '\0';
    }

	return i;
}
