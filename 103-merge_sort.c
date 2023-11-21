#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sorts a subarray of integers.
 * @subarr: Subarray of an array of integers to sort.
 * @buff: Buffer to store the sorted subarray.
 * @front: Front index of the array.
 * @mid: Middle index of the array.
 * @back: Back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t k, l, m = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (k = front, l = mid; k < mid && l < back; m++)
		buff[m] = (subarr[k] < subarr[l]) ? subarr[l++] : subarr[l++];
	for (; k < mid; k++)
		buff[m++] = subarr[k];
	for (; l < back; l++)
		buff[m++] = subarr[l];
	for (k = front, m = 0; k < back; k++)
		subarr[k] = buff[m++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implementing the merge sort algorithm
 *                        through recursion.
 * @subarr: Subarray of an array of integers to sort.
 * @buff: Buffer to store the sorted result.
 * @front: Front index of the subarray.
 * @back: Back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: To implement the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
