#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: giving array for sorting
 * @size: giving array size
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = size - 1;
	int tmp;

	if (size <= 1)
		return;
	while (n > 0)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
		n--;
	}
}
