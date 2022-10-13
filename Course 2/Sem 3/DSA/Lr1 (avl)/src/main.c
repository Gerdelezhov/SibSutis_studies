#include "avl.h"
#include <stdio.h>

int main()
{
    //FILE* file = fopen("results.txt", "w");
    struct avltree* root = NULL;
    int key = 1;
    //int height = 0;
    root = avltree_create(7);
    for (int i = 0; i < 10; i++) {
        key += rand() % 100;
        root = avltree_add(root, key);
        /*if (height != avltree_height(root)) {
            height = avltree_height(root);
            fprintf(file, "%d|%d\n", i, avltree_height(root));
        }*/
        avltree_print_dfs(root, 1);
        printf("\n/"
               "--------------------------------------------------------------/"
               "\n");
    }
    avltree_print_dfs(root, 1);
    printf("OK\n");
    return 0;
}
