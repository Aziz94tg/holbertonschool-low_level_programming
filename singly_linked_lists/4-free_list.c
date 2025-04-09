#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t linked list
 * @head: Pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head->next;    /* Save the next node */
		free(head->str);      /* Free the string */
		free(head);           /* Free the current node */
		head = temp;          /* Move to the next node */
	}
}

