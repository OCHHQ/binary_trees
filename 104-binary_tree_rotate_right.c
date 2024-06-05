#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    if (tree == NULL || tree->left == NULL)
    {
        return (tree);
    }

    binary_tree_t *new_root = tree->left;
    binary_tree_t *temp = new_root->right;

    new_root->right = tree;
    tree->left = temp;

    if (tree->parent != NULL)
    {
        if (tree->parent->left == tree)
        {
            tree->parent->left = new_root;
        }
        else
        {
            tree->parent->right = new_root;
        }
    }
    new_root->parent = tree->parent;
    tree->parent = new_root;

    return (new_root);
}
