#include "sort.h"

/**
 * swap_nodes_right - swaps nodes from right to left
 * @list: pointer to list
 * @current: pointer to current node
 * @prev_node: Pointer to the previous node
 * Return: void
 */
void swap_nodes_right(listint_t **list, listint_t *current, listint_t *prev_node)
{
	prev_node = current->prev;
	prev_node->next->prev = prev_node->prev;
	if (prev_node->prev)
		prev_node->prev->next = prev_node->next;
	else
		*list = prev_node->next;
	prev_node->prev = prev_node->next;
	prev_node->next = prev_node->next->next;
	prev_node->prev->next = prev_node;
	if (prev_node->next)
		prev_node->next->prev = prev_node;
	print_list(*list);
}


/**
 * swap_nodes_left - This function swaps two nodes in a doubly linked list,
 *              moving the current node to the right.
 * @list: pointer to list
 * @current: pointer to current node
 * @next_node: Pointer to the next node
 * Return: void
 */
void swap_nodes_left(listint_t **list, listint_t *current, listint_t *next_node)
{
	if (current->prev)
		current->prev->next = next_node;
	else
		*list = next_node;
	if (next_node->next)
		next_node->next->prev = current;
	current->next = next_node->next;
	next_node->prev = current->prev;
	next_node->next = current;
	current->prev = next_node;
	print_list(*list);

}



/**
 * cocktail_sort_list - This function sorts a doubly linked list of integers
 *              in ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 * Return: void
 **/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *auxiliary;
	int swapped = 1;

	if (list)
	{
		current = *list;
		while (swapped != 0)
		{
			swapped = 0;
			while (current->next)
			{
				if (current->n > current->next->n)
				{
					auxiliary = current->next;
					swap_nodes_left(list, current, auxiliary);
					swapped = 1;
				}
				else
					current = current->next;
			}
			if (swapped == 0)
				break;
			swapped = 0;
			while (current->prev)
			{
				if (current->prev->n > current->n)
				{
					swap_nodes_right(list, current, auxiliary);
					swapped = 1;
				}
				else
					current = current->prev;
			}

		}
	}
}
