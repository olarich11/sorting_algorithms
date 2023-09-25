#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - This function allows to Swap two integers in an array.
 * @a: The reference to the first integer to swap.
 * @b: The refrence to the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - This function rearranges a portion of an array
 * of integers using the lomuto partition scheme with the last
 * element as pivot.
 * @array: The array of integers to be modified.
 * @size: The total size of the array.
 * @left: The starting index of the section to be sorted.
 * @right: The ending index of the section to be sorted.
 *
 * Return: The final position of the pivot element after
 * the rearrangement.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Function reponsible for implementing the
 * quicksort algorithm through recursion.
 * @array: An array of integers that needs to sorted.
 * @size: The total size of the array.
 * @left: The starting index of the array segment to
 * be sorted.
 * @right: The ending index of the array segment to
 * be sorted.
 *
 * Description: The function utilizes the Lomuto partition
 * scheme for sorting.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - This function is designed Sort an array of
 * integers in ascending order using the quicksort algorithm.
 * @array: An array of integers to be sorted.
 * @size: The total size of the array.
 *
 * Description: Function employs the use of Lomuto partition
 * scheme and prints the array after each ecchange of two
 * elements during sorting.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
