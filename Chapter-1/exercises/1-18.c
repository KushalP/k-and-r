#include <stdio.h>
 
int main()
{
	int next, c = '\0';

	while ((next = getchar()) != EOF)
	{
		if (!(( c == ' ' || c == '\t') && (next == ' ' || next == '\t')))
		{
			if (!(c == '\n' && next == '\n'))
			{
				putchar(c);
			}
		}
		
		c = next; //saves the next character as the current one
	}
	
	putchar('\n');
	return 0;
}
