#include <stdio.h>
#include <ctype.h>

#define NUMBER	1
#define OTHER	0

int getch(void);
void ungetch(int character);
int getint(int *pn);

int buf;		// buffer for ungetch
int bufp = 0;	// indicates whether the buffer is in use

int main()
{
	int number, c;

	while ((c = getint(&number)) != OTHER && c != EOF)
	{
		printf("%d\n", number);
	}

	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		; // skip whitespace

	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c); // it's not a number!
		return OTHER;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') c = getch();

	if (isdigit(c))
	{
		for (*pn = 0; isdigit(c); c = getch())
		{
			*pn = 10 * *pn + (c - '0');
		}
	}
	else
	{
		ungetch(c);
		return OTHER;
	}

	*pn *= sign;

	if (c != EOF) ungetch(c);

	return NUMBER;
}

/**
 * gets a (possible pushed back) character
 */
int getch(void)
{
	if (bufp > 0)
	{
		bufp = 0;
		return buf;
	}
	else
	{
		return getchar();
	}
}

/**
 * pushes a character back onto the input
 */
void ungetch(int c)
{
	buf = c;
	bufp = 1;
}
