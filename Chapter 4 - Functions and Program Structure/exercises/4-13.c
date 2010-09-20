#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void reverse(char string[], int startposition);

int main()
{
    char line[MAXLINE] = "reverse";
    reverse(line, 0);
    printf("%s\n", line);

	return 0;
}

void reverse(char s[], int i)
{
    int c;

	if (i < strlen(s) / 2)
	{
        c = s[i];
        s[i] = s[strlen(s) - 1 - i];
        s[strlen(s) - 1 - i] = c;
        reverse(s, ++i);
    }
}
