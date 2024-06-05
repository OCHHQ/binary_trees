#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    else
    {
        size_t left_height = binary_tree_height(tree->left);
        size_t right_height = binary_tree_height(tree->right);

        return ((left_height > right_height ? left_height : right_height) + 1);
    }
}

/**
 * check_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @depth: The depth of the tree
 * @level: The current level in the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int check_perfect(const binary_tree_t *tree, int depth, int level)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (depth == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (check_perfect(tree->left, depth, level + 1) &&
            check_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int depth;

    if (tree == NULL)
        return (0);

    depth = binary_tree_height(tree);
    return (check_perfect(tree, depth, 0));
}
