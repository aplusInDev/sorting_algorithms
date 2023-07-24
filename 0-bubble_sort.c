#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i, n = size - 1;
	int tmp;

	while (n > 0)
	{
		for (i = 0; i < n; i++)
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
