#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 1000
#define MAXVAL 100      // maximum depth of val stack

int line[MAXLINE];
int lp = -1;
int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack

int getop(char[]);
void push(double);
double pop(void);
int getline(int line[], int maxline);

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
				printf("error: unknown command\n ");
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
	static int buf;
	static int bufp = 0;

	// retrieve the character from the buffer then skip whitespace
	if (bufp != 0)
	{
		s[0] = c = buf;
		bufp = 0;
		if (c == ' ' || c == '\t')
		{
			while ((s[0] = c = getchar()) == ' ' || c == '\t')
			{
				;
			}
		}
	}
	else
	{
		// retried the characte from stdin then skip whitespace
		while ((s[0] = c = getchar()) == ' ' || c == '\t') {
			;
		}
	}

	s[1] = '\0';

	if (!isdigit(c) && c != '.')
	{
		// not a number
		return c;
	}

	i = 0;

	if (isdigit(c))
	{
		// collect an integer
		while (isdigit(s[++i] = c = getchar()))
		{
			// collect integer part
			;
		}
	}

	if (c == '.')
	{
		while (isdigit(s[++i] = c = getchar()))
		{
			// collect fraction part
			;
		}
	}

	s[i] = '\0';

	if (c != EOF)
	{
		buf = c;
		bufp = 1;
	}

	return NUMBER;
}
