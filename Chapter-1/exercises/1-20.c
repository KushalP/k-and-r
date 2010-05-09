#include <stdio.h>

int detab(int spaces, int n);

int main()
{
	int c, i = 0, spaces = 8;

	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
			case '\n':
				putchar(c);
				i = 0; //Reset character count at newline
				break;
			case '\t':
				//If there's a tab, pass to our function with char count
				detab(spaces, i);
				
				//Continue counting number of characters in the line
				i++;
				break;
			default:
				putchar(c);

				//Continue counting number of characters in the line
				i++;
				break;
		}
	}

	return 0;
}

/**
 * detab replaces tabs in input with proper number of blanks to space
 * to the next tab stop
 * @param spaces - the number of spaces between each tab stop
 * @param n - the char point the tab begins
 * @return the number of spaces written
 */
int detab(int spaces, int n)
{
	int num, i;

	//Work out how many spaces we need to write
	num = i = spaces - n % spaces;

	while (i > 0)
	{
		putchar(' ');
		i--;
	}
	
	return num;
}
