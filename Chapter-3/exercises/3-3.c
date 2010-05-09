#include <stdio.h>
#include <string.h>

void expand(char* s1, char* s2);

int main()
{
	char* s[] = {"a-z-", "z-a-", "-1-6-",
		"a-ee-a", "a-R-L", "1-9-1",
		"5-5", NULL};
	char result[100];
	int i = 0;

	while (s[i])
	{
		// Expand and print the next string in our array s[]
		expand(result, s[i]);
		printf("Unexpanded:\t%s\n", s[i]);
		printf("Expanded:\t%s\n", result);
		i++;
	}

	return 0;
}

/**
 * Copies string s2 to s1, expanding ranges such
 * as 'a-z' and '8-3'
 */
void expand(char* s1, char* s2)
{
	static char upper_alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char lower_alpha[27] = "abcdefghijklmnopqrstuvwxyz";
	static char digits[11] = "0123456789";

	char *start, *end, *p;
	int i = 0, j = 0;

	// Loop through chars in s2
	while (s2[i])
	{
		switch (s2[i])
		{
			case '-':
				if (i == 0 || s2[i+1] == '\0')
				{
					// '-' is leading or trailing, so copy it
					s1[j++] = '-';
					i++;
					break;
				}
				else
				{
					// We've been given a range. Test whether the
					// two values are part of the same range. If so,
					// store pointers to the first and last chars in
					// the range in start/end, respectively. If not,
					// output an error message and skip this range.
					if ((start = strchr(upper_alpha, s2[i-1]))
						&& (end = strchr(upper_alpha, s2[i+1])))
					{
						// Do nothing
					}
					else if ((start = strchr(lower_alpha, s2[i-1]))
						&& (end = strchr(lower_alpha, s2[i+1])))
					{
						// Do nothing
					}
					else if ((start = strchr(digits, s2[i-1]))
						&& (end = strchr(digits, s2[i+1])))
					{
						// Do nothing
					}
					else
					{
						// We have mismatched operands in the range,
						// such as 'b-P' or '7-S', so error! and copy
						// the range expression
						fprintf(stderr, "Mismatched operands '%c-%c'\n",
							s2[i-1], s2[i+1]);
						s1[j++] = s2[i-1];
						s1[j++] = s2[i++];
						break;
					}

					// Expand the range
					p = start;
					while (p != end)
					{
						s1[j++] = *p;
						if (end > start)
						{
							p++;
						}
						else
						{
							p--;
						}
					}

					s1[j++] = *p;
					i += 2;
				}
				break;
			default:
				if (s2[i+1] == '-' && s2[i+2] != '\0')
				{
					// This is the first operand in a range,
					// so skip it, the range will be processed
					// in the next iteration of the loop.
					i++;
				}
				else
				{
					// Copy the normal char
					s1[j++] = s2[i++];
				}
				break;
		}
	}

	s1[j] = s2[i]; // Make sure we finish off with a NULL char
}
