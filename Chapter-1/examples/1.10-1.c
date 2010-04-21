#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */

int max;		/* maximum length seen so far */
char line[MAXLINE];	/* current input line */
char longest[MAXLINE];	/* longest line saved here */

int getline(void);
void copy(void);

/* print the longest input line */
main()
{
	int len;		/* current line length */
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline()) > 0)
	{
		if (len > max)
		{
			max = len;
			copy();
		}
		
		if (max > 0)	/* there was a line */
			printf("%s", longest);
	}
	
	return 0;
}

/* getline: specialised */
int getline(void)
{
	int c, i;
	extern char line[];
	
	for (i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i) line[i] = c;
	
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	
	line[i] = '\0';
	return i;
}

/* copy: specialised */
void copy(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	
	while((longest[i] = line[i]) != '\0') ++i;
}
