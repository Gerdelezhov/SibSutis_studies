#include "avl.h"
#include <stdio.h>

struct avltree* avltree_create(int key)
{
    struct avltree* node;

    node = malloc(sizeof(*node));
    if (node != NULL) {
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }
    return node;
}

struct avltree* avltree_add(struct avltree* tree, int key)
{
    if (tree == NULL) {
        return avltree_create(key);
    }
    if (key < tree->key) {
        tree->left = avltree_add(tree->left, key);
        if (avltree_height(tree->left) - avltree_height(tree->right) == 2) {
            if (key < tree->left->key) {
                tree = avltree_right_rotate(tree);
            } else {
                tree = avltree_leftright_rotate(tree);
            }
        }
    } else if (key > tree->key) {
        tree->right = avltree_add(tree->right, key);
        if (avltree_height(tree->right) - avltree_height(tree->left) == 2) {
            if (key > tree->right->key) {
                tree = avltree_left_rotate(tree);
            } else {
                tree = avltree_rightleft_rotate(tree);
            }
        }
    }
    tree->height
            = imax2(avltree_height(tree->left), avltree_height(tree->right))
            + 1;

    return tree;
}

struct avltree* avltree_right_rotate(struct avltree* tree)
{
    struct avltree* left;

    left = tree->left;
    tree->left = left->right;
    left->right = tree;

    tree->height
            = imax2(avltree_height(tree->left), avltree_height(tree->right))
            + 1;
    left->height = imax2(avltree_height(left->left), tree->height) + 1;
    //printf("RIGHT ROTATE <%d>\n", left->key);
    return left;
}

struct avltree* avltree_left_rotate(struct avltree* tree)
{
    struct avltree* right;

    right = tree->right;
    tree->right = right->left;
    right->left = tree;

    tree->height
            = imax2(avltree_height(tree->left), avltree_height(tree->right))
            + 1;
    right->height = imax2(avltree_height(right->right), tree->height) + 1;
    //printf("LEFT ROTATE <%d>\n", right->key);
    return right;
}

struct avltree* avltree_leftright_rotate(struct avltree* tree)
{
    tree->left = avltree_left_rotate(tree->left);
    //printf("LEFTRIGHT ROTATE <%d>\n", tree->left->key);
    return avltree_right_rotate(tree);
}

struct avltree* avltree_rightleft_rotate(struct avltree* tree)
{
    tree->right = avltree_right_rotate(tree->right);
    //printf("RIGHTLEFT ROTATE <%d>\n", tree->right->key);
    return avltree_left_rotate(tree);
}

struct avltree* avltree_lookup(struct avltree* tree, int key)
{
    while (tree != NULL) {
        if (key == tree->key) {
            return tree;
        } else if (key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}

struct avltree* avltree_delete(struct avltree* root, int key)
{
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = avltree_delete(root->left, key);
    } else if (key > root->key) {
        root->right = avltree_delete(root->right, key);
    }
    //Если корень (текущего поддерева) и есть искомый узел
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct avltree* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct avltree* temp = avltree_min(root->right);

            root->key = temp->key;

            root->right = avltree_delete(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1
            + imax2(avltree_height(root->left), avltree_height(root->right));

    int balance = avltree_balance(root);

    // Left Left Case
    if (balance > 1 && avltree_balance(root->left) >= 0) {
        return avltree_right_rotate(root);
    }

    // Left Right Case
    if (balance > 1 && avltree_balance(root->left) < 0) {
        root->left = avltree_left_rotate(root->left);
        return avltree_right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && avltree_balance(root->right) <= 0) {
        return avltree_left_rotate(root);
    }

    // Right Left Case
    if (balance < -1 && avltree_balance(root->right) > 0) {
        root->right = avltree_right_rotate(root->right);
        return avltree_left_rotate(root);
    }

    return root;
}

struct avltree* avltree_min(struct avltree* root)
{
    struct avltree* current = root;

    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct avltree* avltree_max(struct avltree* root)
{
    struct avltree* current = root;

    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

void avltree_free(struct avltree* tree)
{
    if (tree == NULL)
        return;

    avltree_free(tree->left);
    avltree_free(tree->right);
    free(tree);
}

void avltree_print_dfs(struct avltree *node, int level)
{
    long i;
    if (node != NULL)
    {
        avltree_print_dfs(node->right, level + 5);
        for (i = 0; i < level; i++)
            printf(" ");
        printf("%d\n", node->key);
        avltree_print_dfs(node->left, level + 5);
    }
}

int avltree_height(struct avltree* tree)
{
    return (tree != NULL) ? tree->height : -1;
}

int avltree_balance(struct avltree* tree)
{
    return avltree_height(tree->left) - avltree_height(tree->right);
}

void AVLtree_print(struct avltree* root)
{
    if (root != NULL) {
        printf("%d ", root->key);
        AVLtree_print(root->left);
        AVLtree_print(root->right);
    }
}

int imax2(int a, int b)
{
    return ((a > b) ? a : b);
}
