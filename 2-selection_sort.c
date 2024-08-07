#include "sort.h"

/**
 * selection_sort - Sorts 'Array of integers in ascending order'
 * @array: Array of integers
 * @size: Size of Array.
 */

void selection_sort(int *array, size_t size)
{
	size_t idx_1, idx_2, min_idx;

	if (size < 2)
		return;

	for (idx_1 = 0; idx_1 < size - 1; idx_1++)
	{
		min_idx = idx_1;
		for (idx_2 = idx_1 + 1; idx_2 < size; idx_2++)
		{
			if (array[idx_2] < array[min_idx])
				min_idx = idx_2;
		}
		if (min_idx != idx_1)
		{
			int temp = array[idx_1];
			array[idx_1] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
