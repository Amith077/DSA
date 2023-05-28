#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverseLinkedList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printf("%d ", head->data);
    traverseLinkedList(head->next);
}

int main() {
    struct Node* head = NULL;
    head = (struct Node*) malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*) malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*) malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;
    traverseLinkedList(head);
    return 0;
}

