#include <stdio.h>
#include <string.h>

#define TAB 8
#define LINE_LIMIT 10000

int entab(char s[], int tabs, int offset);
int get_line(char s[], int n);

int main()
{
	int i, j; // Count string index and tabs
	char string[LINE_LIMIT];

	while (get_line(string, LINE_LIMIT) > 0) // Check we've got line input && not EOF
	{
		for (i = 1, j = 1; string[i] != '\0'; ++i, ++j)
		{
			i -= entab(string, j, i);
		}

		printf("%s", string);
	}

	return 0;
}

int entab(char s[], int tabs, int offset)
{
	int i, spaces;

	if (((tabs % TAB) == 0) // We have the exact number to fulfil our tab limit
		&& (s[offset - 1] == '_')) // Our input is an underscore
	{
		// Count down; while we have underscores and an array with enough '_' chars for a tab
		for (i = offset - 1; (s[i] == '_') && (offset - TAB); --i)
		{
			// Increment up our spaces counter, depending on how much '_' chars we have left
			spaces = i > (offset - TAB) ? offset - i - 1 : offset - i;
		}

		// Change our '_' chars for tabs
		if (spaces > 0) s[offset - spaces] = '\t';

		// Shift our string across by the number of spaces remaining
		for (i = offset - spaces + 1; s[i] != '\0'; ++i)
		{
			s[i] = s[i + spaces - 1];
		}

		s[++i] = '\0'; // Close off our string!

		return spaces - 1; // C strings == char array (hence the minus 1)
	}

	return 0;
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
