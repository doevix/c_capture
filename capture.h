#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CAPTURE_H
#define CAPTURE_H

struct llNode 
{
	char *str;
	struct llNode *nxt;
};

// Takes in user input, returns array with user entries.
char **captureInput(size_t *N_entries, char *(*prompt)(char*, size_t));
// Prompts this function can take.
char *staticPrompt(char *s, size_t counter);  // Ordinary '>'
char *numericPrompt(char *s, size_t counter); // Entry list by number
char *alphaPrompt(char *s, size_t counter);   // Entry list by letter

// Move contents of linked-list to a new string array.
char **arTransfer(struct llNode *head, size_t N_nodes);
// Add new node to linked-list.
struct llNode *addNode(struct llNode *node);

// Clear linked-list from given node.
void clear_ll(struct llNode *node);
// Clear string array.
void clear_ar(char **ar, size_t N);

#endif
