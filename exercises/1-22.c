#include <stdio.h>

int main()
{
	int c;
	int length = 70; // My usual terminal window width is 80 chars
	int c_counter = 0;

	while ((c = getchar()) != EOF)
	{
		// Have we reached the char limit?
		if (c_counter <= length) 
		{
			putchar(c);
		}
		// We need to handle the extra spaces and tabs nicely
		else if (c != ' ' && c != '\t')
		{
			putchar('\n');
			putchar(c);
			c_counter = 0; // We've hit a newline, reset the counter
		}

		c_counter++; // Make sure that we increment our char counter
	}

	return 0;
}
