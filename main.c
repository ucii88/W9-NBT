#include <stdio.h>
#include <stdlib.h>
#include "nbtrees.h"
#include "boolean.h"

int main() {
    Isi_Tree myTree;
    int jmlNode = 10; 
    int pilihan;
    char node1, node2;
    
    // Inisialisasi tree
    for (int i = 1; i <= jml_maks; i++) {
        myTree[i].info = ' ';
        myTree[i].ps_fs = null;
        myTree[i].ps_nb = null;
        myTree[i].ps_pr = null;
    }
    
    // Node A (root)
    myTree[1].info = 'A';
    myTree[1].ps_fs = 2;  // fs nya B
    myTree[1].ps_nb = null;
    myTree[1].ps_pr = null;
    
    // Node B
    myTree[2].info = 'B';
    myTree[2].ps_fs = 4;  // fs nya D
    myTree[2].ps_nb = 3;  // nb nya C
    myTree[2].ps_pr = 1;  // parent nya A
    
    // Node C
    myTree[3].info = 'C';
    myTree[3].ps_fs = 6;  // fs nya F
    myTree[3].ps_nb = null;
    myTree[3].ps_pr = 1;  // parent nya A
    
    // Node D
    myTree[4].info = 'D';
    myTree[4].ps_fs = null;
    myTree[4].ps_nb = 5;  // nb nya E
    myTree[4].ps_pr = 2;  // parent nya B
    
    // Node E
    myTree[5].info = 'E';
    myTree[5].ps_fs = 9;  // fs nya I
    myTree[5].ps_nb = null;
    myTree[5].ps_pr = 2;  // parent nya B
    
    // Node F
    myTree[6].info = 'F';
    myTree[6].ps_fs = null;
    myTree[6].ps_nb = 7;  // nb nya G
    myTree[6].ps_pr = 3;  // parent nya C
    
    // Node G
    myTree[7].info = 'G';
    myTree[7].ps_fs = null;
    myTree[7].ps_nb = 8;  // nb nya H
    myTree[7].ps_pr = 3;  // parent nya C
    
    // Node H
    myTree[8].info = 'H';
    myTree[8].ps_fs = null;
    myTree[8].ps_nb = null;
    myTree[8].ps_pr = 3;  // parent nya C
    
    // Node I
    myTree[9].info = 'I';
    myTree[9].ps_fs = null;
    myTree[9].ps_nb = 10; // nb nya J
    myTree[9].ps_pr = 5;  // parent nya E
    
    // Node J
    myTree[10].info = 'J';
    myTree[10].ps_fs = null;
    myTree[10].ps_nb = null;
    myTree[10].ps_pr = 5;  // parent nya E

do {
        
    printf("\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit\n");
    printf("==============================\n");
    printf("Pilih Menu: ");
    scanf("%d", &pilihan);
    
    switch (pilihan) {
        case 1:
            printf("\n");
            PreOrder(myTree);  // Hasil: A B D E I J C F G H
            break;
            
        case 2:
            printf("\n");
            InOrder(myTree);   // Hasil: D B I E J A F C G H
            break;
            
        case 3:
            printf("\n");
            PostOrder(myTree); // Hasil: D I J E B F G H C A
            break;
            
        case 4:
            printf("\n");
            Level_order(myTree, jmlNode); // Hasil: A B C D E F G H I J
            break;
            
        case 5:
            printf("\n");
            PrintTree(myTree);
            break;
            
        case 6:
            printf("\nNode yang ingin dicari (A-J): ");
            scanf(" %c", &node1);
            if (Search(myTree, node1)) {
                printf(" %c ada di tree.\n", node1);
            } else {
                printf(" %c tidak ada di tree.\n", node1);
            }
            break;
            
        case 7:
            printf("\nJumlah Daun: %d\n", nbDaun(myTree));
            break;
            
        case 8:
            printf("\nMasukkan node yang ingin dicari levelnya (A-J): ");
            scanf(" %c", &node1);
            if (Search(myTree, node1)) {
                printf("Level node '%c'= %d\n", node1, Level(myTree, node1));
            } else {
                printf("Node tidak ditemukan!\n");
            }
            break;
            
        case 9:
            printf("\nKedalaman Tree: %d\n", Depth(myTree));
            break;
            
        case 10:
            printf("\nMasukkan node pertama (A-J): ");
            scanf(" %c", &node1);
            printf("Masukkan node kedua (A-J): ");
            scanf(" %c", &node2);
            
            // Membandingkan level node
            if (Search(myTree, node1) && Search(myTree, node2)) {
                int level1 = Level(myTree, node1);
                int level2 = Level(myTree, node2);
                
                printf("Level node '%c': %d\n", node1, level1);
                printf("Level node '%c': %d\n", node2, level2);
                
                if (level1 < level2) {
                    printf("Level node '%c' lebih tinggi dibanding node '%c'.\n", node1, node2);
                } else if (level1 > level2) {
                    printf("Level node '%c' lebih tinggi dibanding node '%c'.\n", node2, node1);
                } else {
                    printf("Level node '%c' dan '%c' sama.\n", node1, node2);
                }
            } else {
                printf("Salah satu atau kedua node tidak valid!\n");
            }
            break;
            
        case 11:
            printf("\nTerima kasih telah menggunakan program ini!\n");
            break;
            
        default:
            printf("\nPilihan tidak valid. Silakan coba lagi.\n");
    }
    
    if (pilihan != 11) {
        printf("\nTekan Enter untuk melanjutkan...");
        getchar(); 
        getchar(); // Menunggu user menekan Enter
    }
    
} while (pilihan != 11);

return 0;
}