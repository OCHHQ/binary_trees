#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    if (tree == NULL || tree->right == NULL)
    {
        return (tree);
    }

    binary_tree_t *new_root = tree->right;
    binary_tree_t *temp = new_root->left;

    new_root->left = tree;
    tree->right = temp;

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
