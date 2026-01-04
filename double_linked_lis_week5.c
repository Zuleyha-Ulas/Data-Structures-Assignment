#include <stdio.h>
#include <stdlib.h>

/*
 * Ad Soyad: Zuleyha Ulas
 * No: [2310213030]
 * Konu: Double Linked List
 */

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void basaEkle(struct Node** head, int yeni_veri) {
    struct Node* yeni_dugum = (struct Node*)malloc(sizeof(struct Node));
    yeni_dugum->data = yeni_veri;
    yeni_dugum->next = (*head);
    yeni_dugum->prev = NULL;
    if ((*head) != NULL) (*head)->prev = yeni_dugum;
    (*head) = yeni_dugum;
}

// ekrana yazdýrma (Traversal)
void listeyiYazdir(struct Node* dugum) {
    printf("Liste: ");
    while (dugum != NULL) {
        printf("%d <-> ", dugum->data);
        dugum = dugum->next;
    }
    printf("NULL\n");
}


void dugumSil(struct Node** head, int anahtar) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != anahtar) {
        temp = temp->next;
    }
    if (temp == NULL) return; 

    if (*head == temp) *head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    
    free(temp);
}

int main() {
    struct Node* head = NULL;
    basaEkle(&head, 10);
    basaEkle(&head, 20);
    basaEkle(&head, 30);
    listeyiYazdir(head); 
    
    dugumSil(&head, 20);
    listeyiYazdir(head);
    
    return 0;
}
