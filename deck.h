#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct values_s - Structure representing card values
 *
 * @name: Name of the card value (e.g., "Ace", "Jack", "Queen", "King")
 * @val: Numeric value of the card (e.g., 1 for "Ace", 11 for "Jack", etc.)
 */
typedef struct values_s
{
	char *name;
	int val;
} values_t;

/**
 * enum kind_e - Enumeration of card suits
 *
 * @SPADE: Represents the SPADE suit (0)
 * @HEART: Represents the HEART suit (1)
 * @CLUB: Represents the CLUB suit (2)
 * @DIAMOND: Represents the DIAMOND suit (3)
 *
 * Description: This defines the possible suits of a standard deck of cards.
 * Each suit is represented by an integer value starting from 0 for SPADE,
 * 1 for HEART, 2 for CLUB, and 3 for DIAMOND.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART = 1,
	CLUB = 2,
	DIAMOND = 3
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif

