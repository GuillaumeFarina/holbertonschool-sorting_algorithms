#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers in
 *                       ascendin order using the Insertion sort algorithm
 * @list: A pointer to the head of doubly linked list of integers
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	head = *list;
	head = head->next;

	while (head)
	{
		while (head->prev && head->n < head->prev->n)
		{
			temp = head;

			/* set prev for head->next node */
			if (head->next)
				head->next->prev = temp->prev;

			head->prev->next = temp->next; /* set next for head->prev node*/

			/* set prev, next for head */
			head = head->prev;
			temp->prev = head->prev;
			temp->next = head;

			/* set next for head->prev->prev node */
			if (head->prev)
				head->prev->next = temp;

			head->prev = temp; /* set prev for head->prev */

			/* set to head of the list */
			if (!temp->prev)
				*list = temp;

			print_list(*list);
			head = head->prev;
		}
		head = head->next;
	}
}
