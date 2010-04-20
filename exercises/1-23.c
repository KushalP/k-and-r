#include <stdio.h>

int main()
{
	int c = 0, next_c = 0;
	
	/**
	 * Possible comment types include:
	 * 	0: default (none)
	 * 	1: // (single line)
	 * 	2: \* (char strings)
	 */
	int comment_type = 0;

	while ((next_c = getchar()) != EOF)
	{
		if (comment_type == 0 && c == '/' && next_c == '/')
		{
			comment_type = 1;
		}

		switch (comment_type)
		{
			case 1:
				if (c == '\n')
					putchar('\n');
					comment_type = 0;
				break;
			default:
				putchar(c);
				break;
		}

		// Make sure that we keep our two char counters in sync
		c = next_c;
	}

	return 0;
}
