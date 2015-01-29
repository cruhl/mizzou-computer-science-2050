#include "tree.h"

// list struct definition
//struct bst;
typedef struct list {
	struct tree* node;
	struct list* next;
} list;

// function prototypes
list* list_new();
void list_pop(list** root);
void list_prepend(list** root, tree* tree_node);
void list_append(list** root, tree* tree_node);