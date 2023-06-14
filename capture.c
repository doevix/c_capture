#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct llNode 
{
	char *str;
	struct llNode *nxt;
};

// Takes in user input, returns array with user entries.
char **captureInput(size_t *N_entries);
// Move contents of linked-list to a new string array.
char **arTransfer(struct llNode *head, size_t N_nodes);

// Add new node to linked-list.
struct llNode *addNode(struct llNode *node);

// Clear linked-list from given node.
void clear_ll(struct llNode *node);
// Clear string array.
void clear_ar(char **ar, size_t N);

int main(void)
{
	// Just take user input and display it.
	size_t N = 0;
	char **names = captureInput(&N);

	for (int i = 0; i < N; i++) printf("%s\n", names[i]);

	clear_ar(names, N);

	return 0;
}

// Takes in user input, returns array with user entries.
char **captureInput(size_t *N_entries)
{
	struct llNode *n = NULL, *list = NULL, *last = NULL;

	*N_entries = 0;

	// Adds nodes to a linked-list, stops adding on blank entry.
	do {
		char buf[20];
		n = NULL;
		printf("> ");

		// User input.
		fgets(buf, sizeof(buf), stdin);

		if (buf[0] != '\n' && buf[0] != '\0') {

			++(*N_entries);
			n = addNode(last);

			last = n;
			if (!list) list = n;

			// A return character will be included, replace with '\0'
			n->str = calloc(strlen(buf), sizeof(char));
			strcpy(n->str, buf);
			(n->str)[strlen(buf) - 1] = '\0';
			
		}

	} while (n);

	// Moves contents of linked-list over to a string array.
	char **ar = arTransfer(list, *N_entries);

	// Delete the linked-list, now that we don't need it anymore.
	clear_ll(list);

	return ar;
}

// Move contents of linked-list to a new string array.
char **arTransfer(struct llNode *head, size_t N_nodes)
{
	// Avoid creating zero size array on empty linked-list.
	if (N_nodes == 0 || head == NULL) return NULL;

	char **ar = malloc(sizeof(char**) * N_nodes);
	int i = 0;
	struct llNode *node = head;

	while (node) {
		
		ar[i++] = node->str;
		node = node->nxt;
	}
	return ar;
}

// Add new node to linked-list.
struct llNode *addNode(struct llNode *node)
{
	struct llNode *n = malloc(sizeof(struct llNode*));

	if (node) node->nxt = n;
	n->nxt = NULL;

	return n;
}

// Clear linked-list from given node.
void clear_ll(struct llNode *node)
{
	while(node) {
		struct llNode *to_del=node;
		node = node->nxt;
		free(to_del);
	}	
}

// Clear string array.
void clear_ar(char **ar, size_t N)
{
	int i = 0;
	while (i < N) free(ar[i++]);
	free(ar);
}

