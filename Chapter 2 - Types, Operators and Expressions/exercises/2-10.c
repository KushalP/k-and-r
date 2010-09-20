#include <stdio.h>

int lower(int c);

int main()
{
	int i;

	for (i = 0; i < 120; i++)
		printf("%c: %c\n", (char)i, (char)lower(i));

	return 0;
}

/**
 * Cibvert char to lower case
 */
int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
