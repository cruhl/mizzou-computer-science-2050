#include <stdio.h>
#include "list.h"

void print_tree_level(tree* root, int direction, int level);
void print_tree(tree* root);

void print_tree_inorder(tree* root);
void print_tree_inorder_recursively(tree* root);
void print_tree_preorder(tree* root);
void print_tree_preorder_recursively(tree* root);
void print_tree_breadth_first(tree* root);