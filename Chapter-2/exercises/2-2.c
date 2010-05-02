#include <stdio.h>

int main()
{
	int c, i, lim = 30;
	char s[lim];

	for (i = 0; (c = getchar()) != EOF; i++)
	{
		if (i < lim - 1)
		{
			if (c != '\n')
			{
				s[i] = c;
			}
			else
			{
				s[i] = '\0';
			}
		}
		else
		{
			break;
		}
	}

	printf("%s\n", s);

	return 0;
}
