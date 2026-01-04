#include <stdio.h>
#include <stdbool.h>

/*
 * Ad Soyad: Zuleyha Ulas
 * No: [2310213030]
 * Ödev 8: Array (Matris) Üzerindeki Graf'ta Cluster Çýkarma
 */

#define DUGUM_SAYISI 6


void dfs(int graf[DUGUM_SAYISI][DUGUM_SAYISI], bool ziyaret_edildi[], int dugum) {
    ziyaret_edildi[dugum] = true;
    printf("%d ", dugum); 

    for (int i = 0; i < DUGUM_SAYISI; i++) {
       
        if (graf[dugum][i] == 1 && !ziyaret_edildi[i]) {
            dfs(graf, ziyaret_edildi, i);
        }
    }
}

void clusterlariBul(int graf[DUGUM_SAYISI][DUGUM_SAYISI]) {
    bool ziyaret_edildi[DUGUM_SAYISI] = {false};
    int cluster_sayisi = 0;

    printf("Graf icindeki Clusterlar (Kumeler):\n");
    for (int i = 0; i < DUGUM_SAYISI; i++) {
        if (!ziyaret_edildi[i]) {
            cluster_sayisi++;
            printf("Cluster %d: ", cluster_sayisi);
            dfs(graf, ziyaret_edildi, i);
            printf("\n");
        }
    }
    printf("\nToplam bulunan cluster sayisi: %d\n", cluster_sayisi);
}

int main() {
    /* Örnek Komþuluk Matrisi (Array olarak Graf):
       0, 1, 2 dugumleri birbirine bagli (1. Cluster)
       3, 4 dugumleri birbirine baðlý (2. Cluster)
       5 dugumu tek basina (3. Cluster)
    */
    int graf[DUGUM_SAYISI][DUGUM_SAYISI] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    clusterlariBul(graf);

    return 0;
}
