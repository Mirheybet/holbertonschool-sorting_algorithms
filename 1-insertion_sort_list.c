#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * change_nodes - for changeable node
 * @head: main dblyllist
 * @ch1: change 1thnode
 * @ch2: change 2thnode
 */

void change_nodes(listint_t **head, listint_t **ch1, listint_t *ch2);

/**
 * insertion_sort_list - main
 * @list: our array
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *clone1, *clone2, *trueplace;

	if ((*list)->next == NULL || *list == NULL || list == NULL)
		return;

	for (clone1 = (*list)->next; clone1 != NULL; clone1 = clone2)
	{
		clone2 = clone1->next;
		trueplace = clone1->prev;
		while (trueplace != NULL && clone1->n < trueplace->n)
		{
			change_nodes(list, &trueplace, clone1);
			print_list((const listint_t *)*list);
		}
	}

}

/**
 * change_nodes - for changeable node
 * @head: main dblyllist
 * @ch1: change 1thnode
 * @ch2: change 2thnode
 */
void change_nodes(listint_t **head, listint_t **ch1, listint_t *ch2)
{
	(*ch1)->next = ch2->next;

	if (ch2->next != NULL)
		ch2->next->prev = *ch1;

	ch2->prev = (*ch1)->prev;
	ch2->next = *ch1;

	if ((*ch1)->prev != NULL)
		(*ch1)->prev->next = ch2;
	else
		*head = ch2;
	(*ch1)->prev = ch2;
	*ch1 = ch2->prev;
}
