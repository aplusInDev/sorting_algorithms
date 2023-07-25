#include "deck.h"

/**
 * node_swapper - swaps 2 nodes of a doubly linked list
 * @node1: first node in order, about to become second
 * @node2: second node inorder, about to become first
 * @deck: list where the nodes exist in
 */
void node_swapper(deck_node_t *node1, deck_node_t *node2, deck_node_t **deck)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		(*deck) = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * compare - compares two nodes
 * @node: current node
 * @prev: previous node
 * @cmp: comparing index
 * Return: 1 or 0
 */
int compare(const card_t *node, const card_t *prev, int cmp)
{
	int value1 = 0, value2 = 0, i;
	values_t v[] = {
		{"Ace", 1},
		{"Jack", 11},
		{"Queen", 12},
		{"King", 13}
	};
	if (cmp == 0)
	{
		for (i = 0; i < 4; i++)
		{
			if (!strcmp(node->value, v[i].name))
				value1 = v[i].val;
			if (!strcmp(prev->value, v[i].name))
				value2 = v[i].val;
		}
		if (!value1)
			value1 = atoi(node->value);
		if (!value2)
			value2 = atoi(prev->value);
	}
	if (cmp == 1)
	{
		value1 = node->kind;
		value2 = prev->kind;
	}
	if (value1 < value2)
		return (1);
	return (0);
}

/**
 * bubble_sort_deck - sorts a doubly list of integers in ascending order
 * using the bubble sort algorithm
 * @deck: giving array to sort
 * @cmp: comparing index
 */
void bubble_sort_deck(deck_node_t **deck, int cmp)
{
	int sorted = 0;
	deck_node_t *node;

	if (!deck || !*deck || !(*deck)->next)
		return;
	while (!sorted)
	{
		sorted = 1;
		for (node = (*deck)->next; node; node = node->next)
		{
			if (compare(node->card, node->prev->card, cmp))
			{
				node_swapper(node->prev, node, deck);
				sorted = 0;
			}
		}
	}
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	bubble_sort_deck(deck, 0);
	bubble_sort_deck(deck, 1);
}
