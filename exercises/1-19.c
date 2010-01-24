#include <stdio.h>

#define MAXLINE 1000	/* set our char array maximum */

int reverse(char string[]);

int main()
{
	char line[MAXLINE];
	int c, i = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			line[i] = '\0';
			reverse(line);
			printf("%s\n", line);
			i = 0;
		}
		else
		{
			line[i] = c;
			++i;
		}
	}
	
	return 0;
}

int reverse(char s[])
{
	int start = 0, endline = 0, length = 0;
	char temp;
	
	while(s[endline] != '\0')
	{
		++endline;
	}
	length = --endline;
	
	start = 0;
	while (endline >= start)
	{
		temp = s[start];
		s[start] = s[endline];
		s[endline] = temp;
		--endline;
		++start;
	}
	
	return length;
}