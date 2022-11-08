#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include "sort.h"

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer  stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* mandatory tasks prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void print_sort(int array[], size_t size, int init);

/* advanced tasks prototypes */
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/* print functions prtotypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* helper functions prototypes*/
void swap(int *a, int *b);
void heapify(int *array, int end, int start, size_t size);

#endif /* SORT_H */
