#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Sort array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: Array of integers.
 * @size: size of the array.
 *
 * Description: makes use of the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, k, l;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			l = k;
			while (l >= gap && array[l - gap] > array[l])
			{
				swap_ints(array + l, array + (l - gap));
				l -= gap;
			}
		}
		print_array(array, size);
	}
}
