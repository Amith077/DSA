#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, j, max_sum = 0;
    printf("Enter the size of the linked list: ");
    scanf("%d", &n);
    struct node *head = NULL, *tail = NULL;
    printf("Enter the elements of the linked list: ");
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = x;
        new_node->next = NULL;
        if (head == NULL)
            head = tail = new_node;
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    for (i = 0; i < n; i++) {
        int sum = 0;
        struct node *ptr = head;
        for (j = i; j < n; j++) {
            sum += ptr->data;
            ptr = ptr->next;
            if (sum > max_sum)
                max_sum = sum;
        }
    }
    printf("The maximum sum of subarray is %d\n", max_sum);
    return 0;
}
