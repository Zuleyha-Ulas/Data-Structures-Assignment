#include <stdio.h>

/*
 * Ad Soyad: Zuleyha Ulas
 * No: [2310213030]
 * Ödev 1: Sparse Matrix (Seyrek Matris) Dönüþümü
 */

int main() {
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 2, 0}
    };

    int size = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0)
                size++;
        }
    }

  
    int compactMatrix[3][size];

    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    printf("Seyrek Matris Donusumu (Compact Representation):\n");
    printf("Satir   Sutun   Deger\n");
    for (int i = 0; i < size; i++) {
        printf("%d \t %d \t %d\n", compactMatrix[0][i], compactMatrix[1][i], compactMatrix[2][i]);
    }

    return 0;
}
