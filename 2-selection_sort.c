#include "sort.h"

/**
 * swap_ints - This function swap two integers in an array.
 * @a: A pointer to the first integer to swapped.
 * @b: A pointer to the second integer to swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - This function sorts an array of integers in
 * ascending order using the selection sort algorithm.
 * @array: An array of integers that needs to be sorted.
 * @size: The number of elements of the array.
 *
 * Description: The sorting process prints the array after each
 * swap operation, allowing to the process of the sorting.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
