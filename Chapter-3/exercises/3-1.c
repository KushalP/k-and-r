#include <stdio.h>
#include <time.h>

#define MAX_SIZE 20000
#define MAX_ITER 100000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
	int testdata[MAX_SIZE], index, i, n = -1;
	clock_t time_taken;

	// Initialise test data
	for (i = 0; i < MAX_SIZE; i++) testdata[i] = i;

	// Output the time taken for MAX_ITER iterations
	// of binsearch()
	for (i = 0, time_taken = clock(); i < MAX_ITER; i++)
	{
		index = binsearch(n, testdata, MAX_SIZE);
	}
	
	time_taken = clock() - time_taken;

	if (index < 0)
	{
		printf("Element %d not found.\n", n);
	}
	else
	{
		printf("Element %d found at index %d.\n", n, index);
	}

	printf("binsearch() took %lu clocks (%lu seconds)\n",
		(unsigned long)time_taken,
		(unsigned long)time_taken / CLOCKS_PER_SEC);
	
	// Out the time taken taken for MAX_ITER iterations
	// of binsearch2
	for (i = 0, time_taken = clock(); i < MAX_ITER; i++)
	{
		index = binsearch2(n, testdata, MAX_SIZE);
	}
	
	time_taken = clock() - time_taken;

	if (index < 0)
	{
		printf("Element %d not found.\n", n);
	}
	else
	{
		printf("Element %d found at index %d.\n", n, index);
	}

	printf("binsearch() took %lu clocks (%lu seconds)\n",
		(unsigned long)time_taken,
		(unsigned long)time_taken / CLOCKS_PER_SEC);

	return 0;
}

/**
 * Implementation from Chapter 3 of K&R.
 *
 * find x in v[0] <= v[1] <= ... <= v[n-1]
 */
int binsearch(int x, int v[], int n)
{
	int low, mid, high;
	
	low = 0;
	high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}

	return -1; // No match
}

/**
 * Implementation of binary search using only
 * one test inside the loop.
 *
 * find x in v[0] <= v[1] <= ... <= v[n-1]
 */
int binsearch2(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	while (low <= high && x != v[mid])
	{
		if (x < v[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}

		// We need to make sure that our computed
		// mid-point is always kept up to date
		mid = (low + high) / 2;
	}

	if (x == v[mid]) return mid;
	
	return -1;
}
