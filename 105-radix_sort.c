#include "sort.h"
/**
 * get_max - Gets the maximum value from the array
 * @array: Pointer to the array
 * @size: Size of the array
 * Return: The maximum value from the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              Radix Sort algorithm.
 * @array: Pointer to the array
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *new_array;
	int i, max, exp = 1;
	int array_size = size;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	new_array = malloc(sizeof(int) * size);
	while (max / exp > 0)
	{
		int counts[20] = {0};

		i = 0;

		while (i < array_size)
		{
			counts[(array[i] / exp) % 10]++;
			i++;
		}

		if (counts != NULL)
		{
			for (i = 1; i < 10; i++)
				counts[i] += counts[i - 1];

			for (i = array_size - 1; i >= 0; i--)
			{
				new_array[counts[(array[i] / exp) % 10] - 1] = array[i];
				counts[(array[i] / exp) % 10]--;
			}

			for (i = 0; i < array_size; i++)
				array[i] = new_array[i];
		}
		exp *= 10;
		print_array(array, size);
	}
	free(new_array);
}
