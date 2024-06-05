#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }

    size_t size = binary_tree_size(tree);
    size_t nodes = 0;
    const binary_tree_t *current = tree;

    while (current != NULL)
    {
        nodes++;
        if (current->left == NULL && current->right != NULL)
        {
            return (0);
        }
        if (current->left != NULL)
        {
            current = current->left;
        }
        else if (current->right != NULL)
        {
            current = current->right;
        }
        else
        {
            current = NULL;
        }
    }

    return (nodes == size);
}
