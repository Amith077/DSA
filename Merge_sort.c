#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int level;
    int profit;
    int weight;
    struct Node* next;
} Node;

Node* newNode(int level, int profit, int weight) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->level = level;
    node->profit = profit;
    node->weight = weight;
    node->next = NULL;
    return node;
}

void enqueue(Node** head, Node** tail, int level, int profit, int weight) {
    Node* node = newNode(level, profit, weight);
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
}

Node* dequeue(Node** head) {
    if (*head == NULL) {
        return NULL;
    }
    Node* node = *head;
    *head = (*head)->next;
    return node;
}

int maxProfit(int capacity, int weights[], int profits[], int n) {
    Node* head = NULL;
    Node* tail = NULL;
    int maxProfit = 0;
    int level = 0;
    int currentProfit = 0;
    int currentWeight = 0;

    enqueue(&head, &tail, level, currentProfit, currentWeight);

    while (head != NULL) {
        Node* node = dequeue(&head);
        level = node->level;
        currentProfit = node->profit;
        currentWeight = node->weight;
        free(node);

        if (level == n) {
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }
            continue;
        }

        int nextLevel = level + 1;
        int nextProfit = currentProfit + profits[level];
        int nextWeight = currentWeight + weights[level];

        if (nextWeight <= capacity && nextProfit > maxProfit) {
            maxProfit = nextProfit;
        }

        if (nextWeight <= capacity) {
            enqueue(&head, &tail, nextLevel, nextProfit, nextWeight);
        }

        enqueue(&head, &tail, nextLevel, currentProfit, currentWeight);
    }

    return maxProfit;
}

int main() {
    int capacity, n;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int* weights = (int*) malloc(sizeof(int) * n);
    int* profits = (int*) malloc(sizeof(int) * n);

    printf("Enter the weights and profits of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &profits[i]);
    }

    int result = maxProfit(capacity, weights, profits, n);
    printf("The maximum profit is: %d\n", result);

    free(weights);
    free(profits);

    return 0;
}
