#include "fibheap.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{    
    Heap *root = createHeap();
    root = fibHeapInsert(root, 5, 5);
    root = fibHeapInsert(root, 2, 2);
    root = fibHeapInsert(root, 3, 3);
    root = fibHeapInsert(root, 6, 6);
    print(root);

    printf("\n");

    Heap *root2 = createHeap();
    root2 = fibHeapInsert(root2, 1, 1);
    root2 = fibHeapInsert(root2, 4, 4);
    root2 = fibHeapInsert(root2, 7, 7);
    root2 = fibHeapInsert(root2, 0, 0);
    print(root2);

    printf("\n");

    Heap *root3 = mergeHeaps(root, root2);
    print(root3);

    /*Heap* root = createHeap();
    Heap* root2 = createHeap();

    while (command != 0) {
        if (command == 1) {
            int value;
            scanf("%d", &value);
            root = fibHeapInsert(root, value, value);
        }

        if (command == 2) {
            print(root);
        }

        if (command == 3) {
            int value;
            scanf("%d", &value);
            root2 = fibHeapInsert(root2, value, value);
        }

        if (command == 4) {
            print(root2);
        }

        if (command == 5) {
            Heap* root3 = mergeHeaps(root, root2);
            print(root3);
        }

        printf("\n/------------Куча 1-------------/\n");
        printf(" 1 Вставить узел\n");
        printf(" 2 Вывод всей кучи\n");
        printf("/------------Куча 1-------------/\n");
        printf(" 3 Вставить узел\n");
        printf(" 4 Вывод всей кучи\n");
        printf("---------------------------------\n");
        printf(" 5 Объеденить первую кучу со второй\n");
        printf(" 0 Выход\n\n");
        scanf("%d", &command);
        system("clear");
    }*/
    return 0;
}