#include "sort.h"

/**
 * swap_ints - This function allow you to excahnge the
 * positions of two integers within an array.
 * @a: The first integer you want to swap.
 * @b: The second integer you want to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - This function is used to Sort an array of
 * integers in ascending order using the shell sort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The total size of the array.
 *
 * Description: The function applies the shell sort algorithm,
 * which uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
