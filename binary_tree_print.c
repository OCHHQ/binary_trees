#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: Pointer to the node to measure the depth of
 *
 * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree)
    {
        depth++;
        tree = tree->parent;
    }
    return (depth - 1);
}

/**
 * print_value - Print the value of a node
 *
 * @buf: Buffer to store the string representation of the value
 * @node: Pointer to the node
 *
 * Return: Number of characters printed
 */
int print_value(char *buf, const binary_tree_t *node)
{
    return sprintf(buf, "(%03d)", node->n);
}

/* Printing function for binary tree. */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s, int (*print)(char *, const binary_tree_t *))
{
    char b[6];
    int width, left, right, is_left, i;

    if (!tree)
        return (0);
    is_left = (tree->parent && tree->parent->left == tree);
    width = print(b, tree);
    left = print_t(tree->left, offset, depth + 1, s, print);
    right = print_t(tree->right, offset + left + width, depth + 1, s, print);
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    if (depth && is_left)
    {
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    return (left + width + right);
}

static int _print(const binary_tree_t *tree, int depth, int (*print)(char *, const binary_tree_t *))
{
    char **s;
    int i, j, width;

    if (!tree)
        return (0);
    s = malloc((depth + 1) * sizeof(*s));
    if (!s)
        return (0);
    for (i = 0; i < depth + 1; i++)
    {
        s[i] = malloc(255);
        if (!s[i])
            return (0);
        memset(s[i], ' ', 254);
        s[i][254] = '\0';
    }
    width = print_t(tree, 0, 0, s, print);
    for (i = 0; i < depth + 1; i++)
    {
        for (j = 254; j > 1; j--)
        {
            if (s[i][j] == ' ')
                s[i][j] = '\0';
            else
                break;
        }
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);
    return (width);
}

void binary_tree_print(const binary_tree_t *tree)
{
    int depth;

    if (!tree)
        return;
    depth = binary_tree_depth(tree);
    _print(tree, depth, print_value);
}
