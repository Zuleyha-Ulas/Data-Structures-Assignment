#include <stdio.h>

/*
 * Ad Soyad: Zuleyha Ulas
 * No: [2310213030]
 * Ödev 2: Hanoi Kuleleri Uygulamasý
 */

// Recursive Hanoi Fonksiyonu
void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        printf("Diski 1, %c kulesinden %c kulesine tasi\n", kaynak, hedef);
        return;
    }

    hanoi(n - 1, kaynak, yardimci, hedef);

    printf("Diski %d, %c kulesinden %c kulesine tasi\n", n, kaynak, hedef);

    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int disk_sayisi = 3; 

    printf("%d disk icin Hanoi hamleleri:\n", disk_sayisi);
    
    // A: Kaynak, C: Hedef, B: Yardimci kule
    hanoi(disk_sayisi, 'A', 'C', 'B');

    return 0;
}
