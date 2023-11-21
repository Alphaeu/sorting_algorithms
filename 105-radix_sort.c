#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - gets the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: size of the array.
 *
 * Return: MAx integer in the array.
 */
int get_max(int *array, int size)
{
	int max, k;

	for (max = array[0], k = 1; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}

	return (max);
}

/**
 * radix_counting_sort - sorts the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: Array of integers.
 * @size: size of the array.
 * @sig: significant digit to sort.
 * @buff: Buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t k;

	for (k = 0; k < size; k++)
		count[(array[k] / sig) % 10] += 1;

	for (k = 0; k < 10; k++)
		count[k] += count[k - 1];

	for (k = size - 1; (int)k >= 0; k--)
	{
		buff[count[(array[k] / sig) % 10] - 1] = array[k];
		count[(array[k] / sig) % 10] -= 1;
	}

	for (k = 0; k < size; k++)
		array[k] = buff[k];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *               using the radix sort algorithm.
 * @array: Array of integers.
 * @size: size of the array.
 *
 * Description: To implement the LSD radix sort algorithm. Prints
 *              the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
