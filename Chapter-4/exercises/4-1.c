#include <stdio.h>
#define MAXLINE 1000

int strrindex(char source[], char searchfor[]);


int main()
{
	char source[] = "A quick brown fox jumps over the lazy dog";
	char searchfor[] = "fox";

	printf("%s\nRightmost index of %s at %d\n", source, searchfor, 
		strrindex(source, searchfor));

	return 0;
}

/**
 * Returns the position of the rightmost occurrence
 * of 't' in 's', or -1 if there is none
 */
int strrindex(char s[], char t[])
{
	int i, j, k;
	int index = -1;

	// Go through our string
	for (i = 0; s[i] != '\0'; i++)
	{
		// Increment through our string
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;

		// If we've got our right index
		if (k > 0 && t[k] == '\0')
			index = i;
	}

	return index;
}
