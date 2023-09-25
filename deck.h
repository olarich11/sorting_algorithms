#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - An enumeration representing
 * different card suits.
 * @SPADE: Its stand for the Spades suit.
 * @HEART: Its stnad for the Hearts suit.
 * @CLUB: Its stand for the Clubs suit.
 * @DIAMOND: Its stand for the Diamonds suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - This a structure
 * representing a playing card
 *
 * @value: The value of the card
 * From "Ace" to "King"
 * @kind: The kind or type of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Sturcture representing a
 * node in a deck of card
 *
 * @card: A Pointer to the card associated with
 * the node
 * @prev: A Pointer to the previous node in the deck
 * @next: A Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
