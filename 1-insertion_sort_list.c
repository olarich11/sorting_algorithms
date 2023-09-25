#include "sort.h"

/**
 * swap_nodes - Function to swap two nodes in a doubly-linked list.
 * @h: A pointer to the beginning of the doubly-linked list.
 * @n1: A pointer to the first node to be swapped.
 * @n2: A pointer to the second node to swapped.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - This function sorts a doubly linked list of
 * integers using the insertion sort algorithm.
 * @list: A pointer to the beginning of a doubly-linked list of integers.
 *
 * Description: The sorting process prints the list after each swap
 * to show the process of the sorting operation.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
