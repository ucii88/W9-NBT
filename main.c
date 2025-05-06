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
}
