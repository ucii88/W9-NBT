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

boolean SearchR(Isi_Tree P, int root, infotype X) {
    if (root == nil) {
        return false;
    }
    if (P[root].info == X) {
        return true;
    }
    if (SearchR(P, P[root].ps_fs, X)) {
        return true;
    }
    return SearchR(P, P[root].ps_nb, X);
}

boolean Search(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) {
        return false;
    }
    return SearchR(P, 1, X);
}

int nbElmtR(Isi_Tree P, int root) {
    if (root == nil) {
        return 0;
    }
    return 1 + nbElmtR(P, P[root].ps_fs) + nbElmtR(P, P[root].ps_nb);
}

int nbElmt(Isi_Tree P) {
    if (IsEmpty(P)) {
        return 0;
    }
    return nbElmtR(P, 1);
}

int nbDaunR(Isi_Tree P, int root) {
    if (root == nil) {
        return 0;
    }
    if (P[root].ps_fs == nil) {
        return 1 + nbDaunR(P, P[root].ps_nb);
    } else {
        return nbDaunR(P, P[root].ps_fs) + nbDaunR(P, P[root].ps_nb);
    }
}

int nbDaun(Isi_Tree P) {
    if (IsEmpty(P)) {
        return 0;
    }
    return nbDaunR(P, 1);
}

int LevelR(Isi_Tree P, int root, infotype X, int currLevel) {
    if (root == nil) {
        return -1;
    }
    if (P[root].info == X) {
        return currLevel;
    }
    int levelInChild = LevelR(P, P[root].ps_fs, X, currLevel + 1);
    if (levelInChild != -1) {
        return levelInChild;
    }
    return LevelR(P, P[root].ps_nb, X, currLevel);
}

int Level(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) {
        return -1;
    }
    return LevelR(P, 1, X, 0);
}

int DepthR(Isi_Tree P, int root) {
    if (root == nil) {
        return -1;
    }

    int depthFirstChild = -1;
    if (P[root].ps_fs != nil) {
        depthFirstChild = DepthR(P, P[root].ps_fs);
    }

    int depthSibling = -1;
    if (P[root].ps_nb != nil) {
        depthSibling = DepthR(P, P[root].ps_nb);
    }

    int currentNodeDepth = depthFirstChild + 1;
    
    return Max(currentNodeDepth, depthSibling);
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) {
        return 0;
    }
    return DepthR(P, 1) + 1;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
