#include <stdio.h>

int my_strlen(char s[]);

int main(int argc, char* argv[])
{
	if (argc < 2 || argc > 2)
	{
		printf("Usage: %s a-word-here\n", argv[0]);
		return 1;
	}

	printf("Your string '%s' has length %d\n", argv[1], my_strlen(argv[1]));

	return 0;
}

int my_strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0') i++;

	return i;
}
