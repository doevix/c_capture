#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct llNode 
{
	char *str;
	struct llNode *nxt;
};

char **captureInput(size_t *N_entries);
char **arTransfer(struct llNode *head, size_t N_nodes);

struct llNode *addNode(struct llNode *node);
void clear_ll(struct llNode *node);
void clear_ar(char **ar, size_t N);

int main(void)
{
	size_t N = 0;
	char **names = captureInput(&N);

	for (int i = 0; i < N; i++) printf("%s\n", names[i]);

	clear_ar(names, N);

	return 0;
}

char **captureInput(size_t *N_entries)
{
	struct llNode *n = NULL, *list = NULL, *last = NULL;
	do {
		char buf[20];
		n = NULL;
		printf("> ");
		fgets(buf, sizeof(buf), stdin);

		if (buf[0] != '\n' && buf[0] != '\0') {

			++(*N_entries);
			n = addNode(last);

			last = n;
			if (!list) list = n;

			n->str = calloc(strlen(buf), sizeof(char));
			strcpy(n->str, buf);
			(n->str)[strlen(buf) - 1] = '\0';
			
		}

	} while (n);

	char **ar = arTransfer(list, *N_entries);

	clear_ll(list);

	return ar;
}

char **arTransfer(struct llNode *head, size_t N_nodes)
{
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

struct llNode *addNode(struct llNode *node)
{
	struct llNode *n = malloc(sizeof(struct llNode*));

	if (node) node->nxt = n;
	n->nxt = NULL;

	return n;
}

void clear_ll(struct llNode *node)
{
	while(node) {
		struct llNode *to_del=node;
		node = node->nxt;
		free(to_del);
	}	
}

void clear_ar(char **ar, size_t N)
{
	int i = 0;
	while (i < N) free(ar[i++]);
	free(ar);
}

