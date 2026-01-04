#include <stdio.h>
#include <stdbool.h>

/*
 * Ad Soyad: Zuleyha ulas
 * No: [2310213030]
 * Ödev 8 & 9: Graph üzerinde DFS, BFS ve Cluster Bulma
 */

#define V 6 // Graf'taki toplam dugum sayisi

// --- 9. Madde: BFS Uygulamasý ---
void BFS(int graf[V][V], int baslangic, bool ziyaret_edildi[]) {
    int kuyruk[V], front = 0, rear = 0;

    ziyaret_edildi[baslangic] = true;
    kuyruk[rear++] = baslangic;

    while (front < rear) {
        int mevcut = kuyruk[front++];
        printf("%d ", mevcut);

        for (int i = 0; i < V; i++) {
            if (graf[mevcut][i] == 1 && !ziyaret_edildi[i]) {
                ziyaret_edildi[i] = true;
                kuyruk[rear++] = i;
            }
        }
    }
}

// --- 9. Madde: DFS Uygulamasý ---
void DFS(int graf[V][V], int dugum, bool ziyaret_edildi[]) {
    ziyaret_edildi[dugum] = true;
    printf("%d ", dugum);

    for (int i = 0; i < V; i++) {
        if (graf[dugum][i] == 1 && !ziyaret_edildi[i]) {
            DFS(graf, i, ziyaret_edildi);
        }
    }
}

// --- 8. Madde: Cluster islemi ---
void clusterBul(int graf[V][V]) {
    bool ziyaret_edildi[V] = {false};
    int cluster_sayisi = 0;

    printf("\n--- Graf icindeki Clusterlar (Kumeler) ---\n");
    for (int i = 0; i < V; i++) {
        if (!ziyaret_edildi[i]) {
            cluster_sayisi++;
            printf("Cluster %d: ", cluster_sayisi);
            DFS(graf, i, ziyaret_edildi); 
            printf("\n");
        }
    }
    printf("Toplam bulunan cluster sayisi: %d\n", cluster_sayisi);
}

int main() {
    // Komþuluk Matrisi (Adjacency Matrix) - Array olarak Graf
    // 0-1-2 baðlý (1. Cluster), 3-4 baðlý (2. Cluster), 5 tek (3. Cluster)
    int graf[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    bool ziyaret_BFS[V] = {false};
    printf("0 Dugumden Baslayan BFS Gezintisi: ");
    BFS(graf, 0, ziyaret_BFS);
    printf("\n");

    clusterBul(graf);

    return 0;
}
