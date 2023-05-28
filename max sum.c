#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

// define stack data structure
struct Stack {
    int arr[MAX];
    int top;
};

// function to create a new stack
struct Stack *createStack() {
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// function to push an element onto the stack
void push(struct Stack *stack, int val) {
    if(stack->top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = val;
}

// function to pop an element from the stack
int pop(struct Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// function to get the top element of the stack
int top(struct Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// function to find the maximum sum of any contiguous subarray of the list
int maxSubarraySum(int arr[], int n) {
    int maxSoFar = 0, maxEndingHere = 0;
    struct Stack *stack = createStack();
    for(int i = 0; i < n; i++) {
        push(stack, arr[i]);
        maxEndingHere += arr[i];
        if(maxEndingHere < 0) {
            maxEndingHere = 0;
            while(!isEmpty(stack)) {
                pop(stack);
            }
        }
        if(maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
    }
    return maxSoFar;
}

// main function
int main() {
    int arr[MAX], n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements of the list:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxSum = maxSubarraySum(arr, n);
    printf("The maximum sum of any contiguous subarray of the list is %d\n", maxSum);
    return 0;
}
