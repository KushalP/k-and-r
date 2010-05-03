#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main()
{
	char* first_str[] = {
		"",
		"a",
		"antidisestablishmentarianism",
		"beautifications",
		"characteristically",
		"deterministically",
		"electroencephalography",
		"familiarisation",
		"gastrointestinal",
		"heterogeneousness"
	};

	char* second_str[] = {
		"",
		"a",
		"me",
		"e",
		"s",
		"l"
	};

	// Find the sizes of our str arrays and create a temp string
	int num_first = sizeof first_str / sizeof first_str[0];
	int num_second = sizeof second_str / sizeof second_str[0];
	int first, second, passed = 0, failed = 0, pos = -1;
	char *ptr = NULL;

	// Iterate over all of our real words
	for (first = 0; first < num_first; first++)
	{
		// Apply the squeeze for every str in our second array
		for (second = 0; second < num_second; second++)
		{
			// Get the first position (if any) where the char exists
			pos = any(first_str[first], second_str[second]);

			// Get a pointer to our string where this occurs, so we can
			// test it's authenticity
			ptr = strpbrk(first_str[first], second_str[second]);

			if (pos == -1)
			{
				if (ptr != NULL)
				{
					printf("Test %d/%d failed.\n", first, second);
					failed++;
				}
				else
				{
					printf("Test %d/%d passed.\n", first, second);
					passed++;
				}
			}
			else
			{
				if (ptr == NULL)
				{
					printf("Test %d/%d passed.\n", first, second);
					passed++;
				}
				else
				{
					if (ptr - first_str[first] == pos)
					{
						printf("Test %d/%d passed.\n", first, second);
						passed++;
					}
					else
					{
						printf("Test %d/%d failed.\n", first, second);
					}
				}
			}
		}
	}

	printf("\n\nTotal passes %d, fails %d, total tests %d\n", passed, 
		failed, passed + failed);

	return 0;
}

/**
 * Returns the location in s1 where any char from s2 occurs,
 * else returns -1 if s1 contains no chars from s2.
 *
 * @param char* s1
 * @param char* s2
 */
int any(char* s1, char* s2)
{
	int i, j, buff_limit = 256;
	char buffer[buff_limit];

	// We've been given an empty first string, is the second
	// string input also empty?
	if (s1 == NULL)
	{
		if (s2 == NULL)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	// Increment over our second string, setting our first array
	// points to 1. Similar to counting 1 bits in an array.
	while (*s2 != '\0')
	{
		buffer[*s2] = 1;
		s2++;
	}

	// Go through our first string, checking where we've stated
	// that the char exists. If this matches s1, return it's
	// array location.
	i = 0;
	while (s1[i] != '\0')
	{
		if (buffer[s1[i]] == 1) return i;
		i++;
	}

	// None of our checks worked, so return -1
	return -1;
}
