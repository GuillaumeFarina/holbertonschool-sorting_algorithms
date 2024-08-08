#include "sort.h"

/**
 * func_swap - Swap two integers in an array
 * @value_a: A pointer to be swapped
 * @value_b: A pointer to be swapped
 * Return: Nothing
 */

void func_swap(int *value_a, int *value_b)
{
	int temp;

	temp = *value_a;
	*value_a = *value_b;
	*value_b = temp;
}


/**
 * func_partition - Place the pivot element at its correct position
 *                  in sorted array
 * @array: A pointer to the array of integers
 * @low: The lowest of index
 * @high: The highest of index
 * @size: Size of array
 *
 * Description: Place all smaller than pivot element to the left of the pivot
 *              and all greater than pivot elements to the right of the pivot
 * Return: The position of the reference value
 */

int func_partition(int *array, int low, int high, size_t size)
{
	int index = low - 1;

	while (low < high)
	{
		if (array[low] < array[high])
		{
			index++;

			if (array[index] != array[low])
			{
				func_swap(&array[index], &array[low]);
				print_array(array, size);
			}
		}

		low++;
	}

	index++;

	if (array[index] != array[high])
	{
		func_swap(&array[index], &array[high]);
		print_array(array, size);
	}

	return (index);
}


/**
 * func_quick_sort - Implement with the Lomuto partition scheme
 * @array: A pointer to an array of integers
 * @low: The lowest of index
 * @high: The highest of index
 * @size: Size of array
 * Return: Nothing
 */

void func_quick_sort(int *array, int low, int high, size_t size)
{

	int pivot;

	if (low < high)
	{
		pivot = func_partition(array, low, high, size);

		func_quick_sort(array, low, pivot - 1, size);
		func_quick_sort(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - Sort an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: A pointer to an array of integers
 * @size: Size of array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{

	if (size < 2)
		return;

	func_quick_sort(array, 0, size - 1, size);

}
