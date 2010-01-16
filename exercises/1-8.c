#include <stdio.h>

main()
{
	int c, nb, nt, nl;
 
	nb = 0;
	nt = 0;
	nl = 0;
 
	while ((c = getchar()) != EOF)
	{
		if (c == ' ') ++nb;
		else if (c == '\n') ++nl;
		else if (c == '\t') ++nt;
	}
	
	printf("Number of blanks: %d\n", nb);
	printf("Number of tabs: %d\n", nt);
	printf("Number of newlines: %d\n", nl);
}