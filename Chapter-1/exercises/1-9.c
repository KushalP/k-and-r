#include <stdio.h>
 
main()
{
	int c, previous;
 
	while ((c = getchar()) != EOF)
	{
		if (!(previous == ' ' && c == ' '))
		{
			putchar(c);
		}
		
		previous = c;
	}
	
	printf("Prev: %d\n", previous);
}