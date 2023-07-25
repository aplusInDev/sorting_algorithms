#include "sort.h"

void swap(int *a, int *b);
/**
 * print_sort - Function that Prints the array
 * during partitioning for Quick sort.
 * @array: Array to be printed
 * @size: Size of the array
 * @init: Should initialize the array
 * Return: void
 */
void print_sort(int array[], size_t size, int init)
{
	static int *ptr = (void *)0;
	static size_t arr_size;

	if (!ptr && init)
	{
		ptr = array;
		arr_size = size;
	}
	if (!init)
		print_array(ptr, arr_size);
}

/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: Array to be partitioned
 * @size: Size of the array
 * Return: Index of the pivot element
 */
size_t partition(int array[], size_t size)
{
	int pivot_idx;
	size_t i_idx = -1;
	size_t j_idx;

	if (!array || size < 2)
		return (0);

	pivot_idx = array[size - 1];

	for (j_idx = 0; j_idx < size - 1; j_idx++)
	{
		if (array[j_idx] <= pivot_idx)
		{
			i_idx++;
			if (i_idx != j_idx)
			{
				swap(&array[i_idx], &array[j_idx]);
				print_sort(array, size, 0);
			}
		}
	}
	if (i_idx + 1 != size - 1)
	{
		swap(&array[i_idx + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (i_idx + 1);
}


/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot_idx;

	if (!array || size < 2)
		return;

	print_sort(array, size, 1);

	/* partition and get pivot_idx index */
	pivot_idx = partition(array, size);

	/* repeat for left of index */
	quick_sort(array, pivot_idx);
	/* repeat for index and right */
	quick_sort(array + pivot_idx, size - pivot_idx);
}

/**
 * swap - Swaps two integer values
 *
 * @a: Pointer to the first value
 * @b: Pointer to the second value
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
