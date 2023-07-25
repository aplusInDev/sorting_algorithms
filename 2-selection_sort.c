#include "sort.h"
#include <stdbool.h>

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: giving array to sort
 * @size: giving array size
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t n = 0, i, idx;
	int min;
	bool swapped = false;

	if (array == NULL || size <= 1)
		return;
	while (n < size - 1)
	{
		min = array[n];
		for (i = n + 1; i < size; i++)
		{
			if (min > array[i])
			{
				min = array[i];
				idx = i;
			}
		}
		if (array[n] > min)
		{
			array[idx] = array[n];
			array[n] = min;
			print_array(array, size);
			swapped = true;
		}
		if (swapped == false)
			break;
		n++;
	}
}
