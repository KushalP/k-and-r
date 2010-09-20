#include <stdio.h>

#define MAXLEN 7

int htoi(const char s[]);

int main()
{
	int c, i;
	char s[MAXLEN];

	// Read in our string input, making sure it 
	// meets our Hex boundaries
	for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF 
		&& c != ' ' && c != '\t' && c != '\n'; i++)
	{
		s[i] = c;
	}

	s[i] = '\0';
	printf("Decimal = %d\n", htoi(s));

	return 0;
}

/**
 * Converts a Hex string to Decimal
 *
 * @param char s[]
 * @return int
 */
int htoi(const char s[])
{
	int i = 0, n = 0;

	// We pass over the first two chars in our hex string
	if (s[i] == '0') i++;

	// We're not picky about capitalisation
	if (s[i] == 'x' || s[i] == 'X') i++;

	for (i; s[i] != '\0'; i++)
	{
		// Displace 4 bits, same as multiply by 16 but more efficient
		n = n << 4;

		// If we have a char bigger than 9, it's a letter (assumed to
		// be correct input)
		n = n + ((s[i] > '9') ? 0x9 : 0x0);
		
		// Clear the 4 most significant bits, adding 9 to integer val
		n = n + (s[i] & 0xF);
	}

	return n;
}
