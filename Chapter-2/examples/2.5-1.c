#include <stdio.h>

int is_leap_year(int year);

int main(int argc, char* argv[])
{
	if (argc < 2 || argc > 2)
	{
		printf("Usage: %s year\n", argv[0]);
		return 1;
	}

	if (is_leap_year(atoi(argv[1])))
	{
		printf("%s is a leap year\n", argv[1]);
	}
	else
	{
		printf("%s isn't a leap year\n", argv[1]);
	}

	return 0;
}

int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0)
		|| year % 400 == 0)
	{
		return 1; // It is a leap year
	}
	else
	{
		return 0; // It isn't a leap year
	}
}
