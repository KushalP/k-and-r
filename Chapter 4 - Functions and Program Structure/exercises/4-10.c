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
	int i;

	// skip whitespace
	while (line[lp] == ' ' || line[lp] == '\t')
		lp++;

	//check if no line has been read, or if we're at the end of the line
	if (lp == -1 || line[lp] == '\0')
	{
		getline(line, MAXLINE);
		lp = 0;
	}

	s[1] = '\0';

	if (!isdigit(line[lp]) && line[lp] != '.')
		return line[lp++]; // not a number

	i = 0;

	if (isdigit(line[lp]))
		// collect ineger part
		while (isdigit(s[i++] = line[lp++]))
			;

	if (s[i - 1] == '.')
		// collect fraction part
		while (isdigit(s[i++] = line[lp++]))
			;

	s[i] = '\0';

	if (line[lp - 1]  != EOF)
		lp--;

	return NUMBER;
}

int getline(int s[], int lim)
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	if (c == '\n' || c == EOF)
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}
