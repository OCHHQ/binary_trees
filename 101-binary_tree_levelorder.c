#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_t **queue;
    size_t front = 0, rear = 0, queue_size = 1024;

    queue = malloc(queue_size * sizeof(*queue));
    if (queue == NULL)
        return;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        const binary_tree_t *node = queue[front++];

        func(node->n);

        if (node->left != NULL)
        {
            if (rear == queue_size)
            {
                queue_size *= 2;
                queue = realloc(queue, queue_size * sizeof(*queue));
                if (queue == NULL)
                    return;
            }
            queue[rear++] = node->left;
        }

        if (node->right != NULL)
        {
            if (rear == queue_size)
            {
                queue_size *= 2;
                queue = realloc(queue, queue_size * sizeof(*queue));
                if (queue == NULL)
                    return;
            }
            queue[rear++] = node->right;
        }
    }

    free(queue);
}
