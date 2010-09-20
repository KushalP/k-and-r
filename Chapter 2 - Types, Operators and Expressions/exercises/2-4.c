#include <stdio.h>
#include <string.h>

void squeeze(char s[], char t[]);

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
	char buffer[32];
	int num_first = sizeof first_str / sizeof first_str[0];
	int num_second = sizeof second_str / sizeof second_str[0];
	int first, second;

	// Iterate over all of our real words
	for (first = 0; first < num_first; first++)
	{
		// Apply the squeeze for every str in our second array
		for (second = 0; second < num_second; second++)
		{
			// We need to copy the str to our buffer as we don't
			// want to edit our first_str[] array
			strcpy(buffer, first_str[first]);

			// Search and remove!
			squeeze(buffer, second_str[second]);

			// Pretty print our output for debugging
			printf("[%s]\t-\t[%s]\t=\t[%s]\n", first_str[first], 
				second_str[second], buffer);
		}
	}

	return 0;
}

/**
 * Given two strings, remove all occurences of the second
 * string from the first string
 *
 * @param char s[]
 * @param char t[]
 */
void squeeze(char s[], char t[])
{
	int i, j, k, in_str = 0;

	for (i = j = 0; s[i] != '\0'; i++)
	{
		// For every iteration, put our tracker back to zero
		in_str = 0;

		for (k = 0; t[k] != '\0' && !in_str; k++)
		{
			// This char is not needed anymore, let the loop know
			if (t[k] == s[i]) in_str = 1;
		}

		// We shouldn't pass over this char
		if (!in_str) s[j++] = s[i];
	}

	// Close off our string properly, no return required
	s[j] = '\0';
}
