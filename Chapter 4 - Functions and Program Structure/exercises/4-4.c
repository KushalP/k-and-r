#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100	// maximum depth of val stack

char buf[BUFSIZE];	// buffer for ungetch
int bufp = 0;		// next free position in buf
int sp = 0;		// next free stack position
double val[MAXVAL];	// value stack

double pop(void);
int getch(void);
int getop(char[]);
void push(double);
void ungetch(int);
void printval(void);
void duplicate(void);
void swap(void);

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
			case 'p': case 'P':
				printval();
				break;
			case 'd': case 'D':
				duplicate();
				break;
			case 's': case 'S':
				swap();
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

// prints the value at the top of the stack without popping
void printval(void)
{
	printf("%g\n", val[sp - 1]);
}

// duplicates the value at the top of the stack
void duplicate(void)
{
	if (sp > 0 && sp < MAXVAL)
	{
		val[sp] = val[sp - 1];
		sp++;
	}
	else if (sp < MAXVAL)
	{
		printf("duplicate: stack empty\n");
	}
	else
	{
		printf("duplicate: stack full, can't duplicate %g\n", val[sp - 1]);
	}
}

void swap(void)
{
	double temp;

	if (sp > 1)
	{
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
	else
	{
		printf("swap: not enough values on stack to swap");
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
