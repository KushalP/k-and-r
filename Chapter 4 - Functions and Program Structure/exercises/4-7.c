#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100	// maximum depth of val stack
#define BUFSIZE 100

int sp = 0;		// next free stack position
double val[MAXVAL];	// value stack
char buf[BUFSIZE];	// buffer for ungetch and ungets
int bufp = 0;		// next free position in buf

int getop(char[]);
void push(double);
double pop(void);
void ungets(char string[]);
int getch(void);
void ungetch(int);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

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
				push((int) pop() % (int) op2);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command\n");
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
	
	if (!isdigit(c) && c != '.')
		return c; // not a number
	
	i = 0;
	
	// collect an integer
	if (isdigit(c))
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

int getch(void) // gets a (possible pushed back) character
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) //pushes a character back onto the input
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

void ungets(char s[])
{
	int i;

	for (i = 0; s[i] != '\0' && bufp < BUFSIZE; i++, bufp++)
		buf[bufp] = s[i];

	bufp = '\0';

	if (bufp >= BUFSIZE)
		printf("ungets: too many characters");
}