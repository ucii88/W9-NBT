#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"
#include "boolean.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    char nodeInfo;
    int firstSon, nextBrother, parents;

    for (i = 1; i <= jml_maks; i++) {
        X[i].info = ' ';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }

    for (i = 1; i <= Jml_Node; i++) {
        printf("Node ke-%d\n", i);
        printf("Info: ");
        scanf(" %c", &nodeInfo);
        printf("First Son : ");
        scanf("%d", &firstSon);
        printf("Next Brother : ");
        scanf("%d", &nextBrother);
        printf("parents : ");
        scanf("%d", &parents);

        X[i].info = nodeInfo;
        X[i].ps_fs = firstSon;
        X[i].ps_nb = nextBrother;
        X[i].ps_pr = parents;
    }
}

boolean IsEmpty(Isi_Tree P) {
    return (P[1].info == ' ');
}

void PreOrderR(Isi_Tree P, int root) {
    if (root != nil) {
        printf("%c ", P[root].info);
        PreOrderR(P, P[root].ps_fs);
        PreOrderR(P, P[root].ps_nb);
    }
}

void PreOrder(Isi_Tree P) {
    printf("PreOrder: ");
    if (!IsEmpty(P)) {
        PreOrderR(P, 1);
    }
    printf("\n");
}

void InOrderR(Isi_Tree P, int root) {
    if (root != nil) {
        InOrderR(P, P[root].ps_fs);
        printf("%c ", P[root].info);
        if (P[root].ps_fs != nil) {
            int sibling = P[P[root].ps_fs].ps_nb;
            while (sibling != nil) {
                InOrderR(P, sibling);
                sibling = P[sibling].ps_nb;
            }
        }
    }
}

void InOrder(Isi_Tree P) {
    printf("InOrder: ");
    if (!IsEmpty(P)) {
        InOrderR(P, 1);
    }
    printf("\n");
}

void PostOrderR(Isi_Tree P, int root) {
    if (root != nil) {
        PostOrderR(P, P[root].ps_fs);
        PostOrderR(P, P[root].ps_nb);
        printf("%c ", P[root].info);
    }
}

void PostOrder(Isi_Tree P) {
    printf("PostOrder: ");
    if (!IsEmpty(P)) {
        PostOrderR(P, 1);
    }
    printf("\n");
}

void Level_order(Isi_Tree X, int Maks_node) {
    int i;
    printf("Level Order: ");
    for (i = 1; i <= Maks_node; i++) {
        if (X[i].info != ' ') {
            printf("%c ", X[i].info);
        }
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    int i;
    printf("Seluruh Node pada Non Binary Tree:\n");
    for (i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            printf("\n--> Indeks ke-%d\n", i);
            printf("----------------------------------------\n");
            printf("info array ke %d          : %c\n", i, P[i].info);
            printf("first son array ke %d     : %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d  : %d\n", i, P[i].ps_nb);
            printf("parents array ke %d       : %d\n", i, P[i].ps_pr);
        }
    }
}