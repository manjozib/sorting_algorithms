#include "sort.h"

/**
 * bubble_sort- function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: array of list to be sorted
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{

int i, j, temp;
int n  = size;

for (j = 0; j < n; j++)
{
for (i = 0; i < n - (j + 1); i++)
{
if (array[i] > array[i + 1])
{
temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
print_array(array, n);
}
else
{
}
}
}

return;
}
