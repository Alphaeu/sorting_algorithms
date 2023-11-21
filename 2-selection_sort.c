#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @x: First integer to swap.
 * @y: Second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - To sort an array of integers in ascending order
 *                 using the selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: to print the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t k, l;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		min = array + k;
		for (l = k + 1; l < size; l++)
			min = (array[l] < *min) ? (array + l) : min;

		if ((array + k) != min)
		{
			swap_ints(array + k, min);
			print_array(array, size);
		}
	}
}
