#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
int n = size;
int step, temp;
for (step = 0; step < n - 1; step++)
{
int min_idx = step, i;
for (i = step + 1; i < n; i++)
{
if (array[i] < array[min_idx])
{
min_idx = i;
}
}

temp = array[min_idx];
array[min_idx] = array[step];
array[step] = temp;
print_array(array, size);
}
}
