#include "tries.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


trie* trie_create()
{
    trie* node;

    if ((node = malloc(sizeof(trie))) == NULL)
        return NULL;
    node->ch = '\0';
    node->value = NULL;
    node->sibling = NULL;
    node->child = NULL;

    return node;
}

char* trie_lookup(trie* root, char* key)
{
    trie *node, *list;

    for (list = root; *key != '\0'; key++) {
        for (node = list; node != NULL; node = node->sibling) {
            if (node->ch == *key) {
                break;
            }
        }
        if (node != NULL) {
            list = node->child;
        } else {
            return NULL;
        }
    }

    if (node->value == NULL)
        return NULL;
    return node->value;
}

trie* trie_insert(trie* root, char* key, char* value)
{
    trie* node;
    trie* parent = NULL;
    trie* list = root;

    for (; *key != '\0'; key++) {
        for (node = list; node != NULL; node = node->sibling) {
            if (node->ch == *key) {
                break;
            }
        }
        if (node == NULL) {
            node = trie_create();
            node->ch = *key;
            node->sibling = list;
            if (parent != NULL) {
                parent->child = node;
            } else {
                root = node;
            }
            list = NULL;
        } else {
            list = node->child;
        }
        parent = node;
    }

    node->value = strdup(value);

    return root;
}

trie* trie_delete(trie* root, char* key)
{
    int found;

    return trie_delete_dfs(root, NULL, key, &found);
}

trie* trie_delete_dfs(trie* root, trie* parent, char* key, int* found)
{
    trie* node;
    trie* prev = NULL;

    *found = (*key == '\0' && root == NULL) ? 1 : 0;
    if (root == NULL || *key == '\0') {
        return root;
    }

    for (node = root; node != NULL; node = node->sibling) {
        if (node->ch == *key) {
            break;
        }
        prev = node;
    }
    if (node == NULL) {
        return root;
    }

    trie_delete_dfs(node->child, node, key + 1, found);

    if (*found > 0 && node->child == NULL) {
        if (prev != NULL) {
            prev->sibling = node->sibling;
        } else {
            if (parent != NULL) {
                parent->child = node->sibling;
            } else {
                root = node->sibling;
            }
        }
        free(node->value);
        free(node);
    }

    return root;
}

void trie_print(trie* root, int level)
{
    trie* node;
    int i;
    for (node = root; node != NULL; node = node->sibling) {
        for (i = 0; i < level; i++) {
            printf(" ");
        }
        if (node->value != NULL) {
            printf("%c (%s)\n", node->ch, node->value);
        } else {
            printf("%c \n", node->ch);
        }
        if (node->child != NULL) {
            trie_print(node->child, level + 1);
        }
    }
}
