#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define MAX_NUM_LENGTH 20

void push(FILE *file, int num);
int pop(FILE *file);
int peek(FILE *file);

int main() {
    char filename[] = "stack.txt";
    char push_log_filename[] = "push.log";
    char pop_log_filename[] = "pop.log";
    char peek_log_filename[] = "peek.log";
    int num;

    // Create stack file with random numbers
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to create file \"%s\"\n", filename);
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < STACK_SIZE; i++) {
        num = rand() % 100;
        fprintf(file, "%d\n", num);
    }

    fclose(file);

    // Open files for push, pop, and peek logs
    FILE *push_log_file = fopen(push_log_filename, "w");
    if (push_log_file == NULL) {
        printf("Error: Unable to create file \"%s\"\n", push_log_filename);
        exit(1);
    }

    FILE *pop_log_file = fopen(pop_log_filename, "w");
    if (pop_log_file == NULL) {
        printf("Error: Unable to create file \"%s\"\n", pop_log_filename);
        exit(1);
    }

    FILE *peek_log_file = fopen(peek_log_filename, "w");
    if (peek_log_file == NULL) {
        printf("Error: Unable to create file \"%s\"\n", peek_log_filename);
        exit(1);
    }

    // Open stack file for reading and writing
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error: Unable to open file \"%s\"\n", filename);
        exit(1);
    }

    // Push some numbers onto the stack
    push(file, 50);
    fprintf(push_log_file, "Pushed %d\n", 50);
    push(file, 75);
    fprintf(push_log_file, "Pushed %d\n", 75);
    push(file, 100);
    fprintf(push_log_file, "Pushed %d\n", 100);

    // Pop some numbers from the stack
    num = pop(file);
    fprintf(pop_log_file, "Popped %d\n", num);
    num = pop(file);
    fprintf(pop_log_file, "Popped %d\n", num);

    // Peek at the top of the stack
    num = peek(file);
    fprintf(peek_log_file, "Peeked at %d\n", num);

    // Close files
    fclose(file);
    fclose(push_log_file);
    fclose(pop_log_file);
    fclose(peek_log_file);

    printf("Done!\n");

    return 0;
}

void push(FILE *file, int num) {
    char num_str[MAX_NUM_LENGTH];
    sprintf(num_str, "%d\n", num);
    fseek(file, 0, SEEK_END);
    fputs(num_str, file);
}

int pop(FILE *file) {
    fseek(file, -MAX_NUM_LENGTH, SEEK_END);
    char num_str[MAX_NUM_LENGTH];
    fgets(num_str, MAX_NUM_LENGTH, file);
    ftruncate(fileno(file), ftell(file));
    return atoi(num_str);
}

int peek(FILE *file) {
    int num;
    fseek(file, -MAX_NUM_LENGTH, SEEK_END);
    fscanf(file, "%d", &num);
    return num;
}
