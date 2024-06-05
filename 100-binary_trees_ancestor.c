#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, returns NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
    {
        return (NULL);
    }

    if (first == second)
    {
        return ((binary_tree_t *)first);
    }

    if (first->n > second->n && first->left != NULL)
    {
        return (binary_trees_ancestor(first->left, second));
    }

    if (first->n < second->n && first->right != NULL)
    {
        return (binary_trees_ancestor(first->right, second));
    }

    return ((binary_tree_t *)first);
}
