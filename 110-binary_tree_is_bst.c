#include "binary_trees.h"

/**
 * is_bst_helper - Helper function to check if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value allowed in the tree
 * @max: Pointer to the maximum value allowed in the tree
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }

    return (is_bst_helper(tree, NULL, NULL));
}

/**
 * is_bst_helper - Helper function to check if a binary tree is a valid BST
 *
 * @tree: Pointer to the root node of the tree to check
 * @min: Pointer to the minimum value allowed in the tree
 * @max: Pointer to the maximum value allowed in the tree
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
    if (tree == NULL)
    {
        return (1);
    }

    if (min != NULL && tree->n <= min->n)
    {
        return (0);
    }

    if (max != NULL && tree->n >= max->n)
    {
        return (0);
    }

    return (is_bst_helper(tree->left, min, tree) && is_bst_helper(tree->right, tree, max));
}
