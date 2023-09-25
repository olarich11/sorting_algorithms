#include "sort.h"

/**
 * swap_ints - Function to swap two integers in an array.
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Functions sort an array of integers in ascending
 * order using the Bubble Sort algorithm.
 * @array: The array of integers that needs to be sorted.
 * @size: The number of elements size in the array.
 *
 * Description: During the sorting process,this function prints the
 * array after each step of swapping to show the sorting process.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
