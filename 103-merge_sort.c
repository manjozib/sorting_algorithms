#include "sort.h"

/**
 * copy - copies data from one buffer to another
 *
 * @src: source buffer
 * @dst: destination buffer
 * @size: size of buffers
 *
 * Return: No Return
 */
void copy(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}
/**
 * merge - merges two sets of data in ascending order
 * but they must already be sorted before hand
 * @array: first set of data
 * @buff: second set of data
 * @min_l: lower range of first set of data
 * @max_l: upper range of first set of data
 * @min_r: lower range of second set of data
 * @max_r: upper range of second set of data
 *
 * Return: No Return
 */
void merge(int *array, int *buff, int min_l, int max_l, int min_r, int max_r)
{
	int i = min_l, j = min_r, k = min_l;

	while (i <= max_l || j <= max_r)

		if (i <= max_l && j <= max_r)
			if (buff[i] <= buff[j])
				array[k] = buff[i], k++, i++;
			else
				array[k] = buff[j], k++, j++;

		else if (i > max_l && j <= max_r)
			array[k] = buff[j], k++, j++;
		else
			array[k] = buff[i], k++, i++;
}
/**
 * print_check - prints an array in a given range
 *
 * @array: array of data to be print
 * @r1: start of range
 * @r2: end of range
 *
 * Return: No Return
 */
void print_check(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
/**
 * split - recursive function to split data into merge tree
 *
 * @array: array of data to be split
 * @buff: auxiliary array of data for merging
 * @min: min range of data in array
 * @max: max range of data in array
 * @size: size of total data
 *
 * Return: No Return
 */
void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, min_l, max_l, min_r, max_r;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	min_l = min;
	max_l = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	min_r = min;
	max_r = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	print_check(array, min_l, max_l);

	printf("[right]: ");

	print_check(array, min_r, max_r);
	merge(array, buff, min_l, max_l, min_r, max_r);
	copy(array, buff, size);

	printf("[Done]: ");
	print_check(array, min_l, max_r);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy(array, buff, size);

	split(array, buff, 0, size - 1, size);

	free(buff);
}

