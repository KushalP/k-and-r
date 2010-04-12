#include <stdio.h>
#include <string.h>

#define TAB 8
#define LINE_LIMIT 10000

int entab(char s[], int tabs, int offset);
int get_line(char s[], int n);

int main()
{
	char string[LINE_LIMIT];

	while (get_line(string, LINE_LIMIT) > 0) // Check we've got line input && not EOF
	{
		printf("%s\n", string);
	}

	return 0;
}

int entab(char s[], int tabs, int offset)
{
	return 1;
}

int get_line(char s[], int n)
{
	int c, i;

	for (i = 0; i < (n - 1) // White 'i' is less than our maximum line length
		&& (c = getchar()) != EOF  // And it's not the end of stream
		&& c != '\n'; ++i) // And it's not equal to a newline char
	{
		s[i] = c; // Add our char onto the char array
	}

	if (c == '\n') s[i++] = c; // If our last input is a newline, shift it over

	s[i] = '\0'; // Always end our strings correctly

	return i;
}
