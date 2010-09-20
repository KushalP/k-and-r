#include <stdio.h>

#define MAXLINE 1000 // Max input line size

char line[MAXLINE]; // The current input line

int getline(void); // Taken from the K&R book

int main()
{
	int len, t, brace, paren, s_quote, d_quote;
	len = t = brace = paren = 0;
	s_quote = d_quote = 1;

	while ((len = getline()) > 0)
	{
		t = 0;

		while (t < len)
		{
			switch (line[t])
			{
				case '[':
					brace++;
					break;
				case ']':
					brace--;
					break;
				case '(':
					paren++;
					break;
				case ')':
					paren--;
					break;
				case '\'':
					s_quote *= -1;
					break;
				case '"':
					d_quote *= -1;
					break;
				default:
					break;
			}

			t++;
		}
	}

	// Print our errors
	if (d_quote != 1) printf("Mismatching double quote mark\n");
	if (s_quote != 1) printf("Mismatching single quote mark\n");
	if (paren != 0) printf("Mismatching parenthesis\n");
	if (brace != 0) printf("Mismatching brace mark\n");

	if (brace == 0 && paren == 0 && s_quote == 1 && d_quote == 1)
		printf("Syntax appears to be correct.\n");

	return 0;
}

int getline(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	
	if (c == '\n')
	{
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return i;
}
