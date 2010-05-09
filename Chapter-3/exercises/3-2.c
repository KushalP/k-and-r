#include <stdio.h>

void escape(char* s, char* t);
void unescape(char* s, char* t);

int main()
{
	char text1[50] = "\aHello, Neo.\n\tWelcome to\b the \"real\" 'world'!\n";
	char text2[51];

	printf("Original string:\n%s\n", text1);

	escape(text2, text1);
	printf("Escaped string:\n%s\n", text2);

	unescape(text1, text2);
	printf("Unescaped string:\n%s\n", text1);

	return 0;
}

void escape(char* s, char* t)
{
}

void unescape(char* s, char* t)
{
}
