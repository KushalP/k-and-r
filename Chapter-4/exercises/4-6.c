#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXOP 100
#define MAXVAL 100	// maximum depth of val stack
#define NUMBER '0'
#define VARIABLE 'a'

double pop(void);
int getch(void);
int getop(char[]);
void push(double);
void ungetch(int);

double varval[27];	// list of variable values
char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf
int sp = 0;		// next free stack position
double val[MAXVAL];	// value stack

int main()
{
	int type, i;
	double op2, last;
	char s[MAXOP];

	// initialise 'variable values to zero' array to 0
	for (i = 0; i < 27; i++)
		varval[i] = 0;

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop ());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();

				if (op2 != 0.0)
				{
					push(pop() / op2);
				}
				else
				{
					printf("error: division by zero\n");
				}
				break;
			case '%':
				op2 = pop();
				push((double) ((int) pop() % (int) op2));
				break;
			case VARIABLE:
				push(varval[s[0] - 'a']);
				break;
			case '=':
				push(last);
				break;
			case '\n':
				printf("\t%.8g\n", last = pop());
				break;
			default:
				printf("error: unknown command - %c\n", type);
				break;
		}
	}

	return 0;
}

// push: push f onto value stack
void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

// pop: pop and return top value from stack
double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

//getop: get next operator or numeric operand
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	i = 0;

	// collect an integer
	if (isdigit(c) || c == '.')
	{
		// collect integer part
		while (isdigit(s[++i] = c = getch()))
			;

		if (c == '.')
			// collect fraction part
			while (isdigit(s[++i] = c = getch()))
				;

		s[i] = '\0';

		if (c != EOF)
			ungetch(c);

		return NUMBER;
	}
	else if (islower(c)) // collect a lowercase single letter variable
	{
		return VARIABLE;
	}
	else if (isupper(c))
	{
		s[0] = c - ('A' - 'a');
		return VARIABLE;
	}
	else
	{
		return c; // not a number
	}
}

// gets a (possible pushed back) character
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

//pushes a character back onto the input
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters");
	}
	else
	{
		buf[bufp++] = c;
	}
}
