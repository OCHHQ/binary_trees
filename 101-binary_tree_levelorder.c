#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
    {
        return;
    }

    binary_tree_t *queue[1000];
    int head = 0, tail = 0;

    queue[tail++] = (binary_tree_t *)tree;

    while (head != tail)
    {
        binary_tree_t *current = queue[head++];
        func(current->n);

        if (current->left)
        {
            queue[tail++] = current->left;
        }

        if (current->right)
        {
            queue[tail++] = current->right;
        }
    }
}
