#include <stdio.h>
#include <stdlib.h>

/*
 * Ad Soyad: Zuleyha Ulas
 * No: [2310213030]
 * Konu: Circular Linked List
 */

struct Node {
    int data;
    struct Node* next;
};

// eleman ekleme
void basaEkle(struct Node** head, int veri) {
    struct Node* yeni = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    yeni->data = veri;
    yeni->next = *head;

    if (*head != NULL) {
        while (temp->next != *head) temp = temp->next;
        temp->next = yeni;
    } else {
        yeni->next = yeni; 
    }
    *head = yeni;
}

//(Traversal)
void listeyiYazdir(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("(Basa donuyor)\n");
}

int main() {
    struct Node* head = NULL;
    basaEkle(&head, 5);
    basaEkle(&head, 15);
    basaEkle(&head, 25);
    listeyiYazdir(head); 
    return 0;
}
