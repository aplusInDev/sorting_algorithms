#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort_recursive - Initiates merge sort recursively
 * @array: Array to be sorted
 * @temp: Temporary array for holding sorted elements
 * @size: Size of the array
 */
void merge_sort_recursive(int *array, int *temp, size_t size)
{
	size_t half_size = size / 2, i = 0, j = 0, k;

	if (size < 2)
		return;

	merge_sort_recursive(array, temp, half_size);
	merge_sort_recursive(array + half_size, temp + half_size, size - half_size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half_size);
	printf("[right]: ");
	print_array(array + half_size, size - half_size);
	for (k = 0; k < size; k++)
		if (j >= size - half_size || (i < half_size && array[i] < (array + half_size)[j]))
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = (array + half_size)[j];
			j++;
		}
	for (k = 0; k < size; k++)
		array[k] = temp[k];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Initiates the merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (!array || size < 2)
		return;

	temp_array = malloc(sizeof(*temp_array) * size);
	if (!temp_array)
		return;

	merge_sort_recursive(array, temp_array, size);
	free(temp_array);
}
