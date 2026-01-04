#include <stdio.h>

/*
 * Ad Soyad: Zuleyha Ulas
 * No: [2310213030]
 * Ödev 10: Dizi (Array) Kullanarak tree Oluþturma
 */

#define MAX_SIZE 15 // treenin alabileceði maksimum node sayýsý
char tree[MAX_SIZE];

void agaciBaslat() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = '-'; 
    }
}

void kokEkle(char veri) {
    tree[0] = veri;
}

void solCocukEkle(char veri, int ebeveyn_indis) {
    int sol_indis = (2 * ebeveyn_indis) + 1;
    if (tree[ebeveyn_indis] == '-') {
        printf("\nHata: %d indisinde ebeveyn yok!", ebeveyn_indis);
    } else if (sol_indis >= MAX_SIZE) {
        printf("\nHata: Agac siniri asildi!");
    } else {
        tree[sol_indis] = veri;
    }
}

void sagCocukEkle(char veri, int ebeveyn_indis) {
    int sag_indis = (2 * ebeveyn_indis) + 2;
    if (tree[ebeveyn_indis] == '-') {
        printf("\nHata: %d indisinde ebeveyn yok!", ebeveyn_indis);
    } else if (sag_indis >= MAX_SIZE) {
        printf("\nHata: Agac siniri asildi!");
    } else {
        tree[sag_indis] = veri;
    }
}

// Diziyi ekrana yazdýrýr
void agaciYazdir() {
    printf("\nAgacin Dizi (Array) Yapisi:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%c ", tree[i]);
    }
    printf("\n");
}

int main() {
    agaciBaslat();

    kokEkle('A');           // root: A
    solCocukEkle('B', 0);   // A'nin solu: B
    sagCocukEkle('C', 0);   // A'nin sagi: C
    solCocukEkle('D', 1);   // B'nin solu: D
    sagCocukEkle('E', 1);   // B'nin sagi: E
    sagCocukEkle('F', 2);   // C'nin sagi: F

    agaciYazdir();

    return 0;
}
