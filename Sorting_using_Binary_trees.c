#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//structure for binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {                    // uses recursive algorithm
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to perform inorder traversal and store the data in a file
void inorderTraversal(Node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left, fp);
    fprintf(fp, "%d ", root->data);
    inorderTraversal(root->right, fp);
}

// Function to perform preorder traversal and store the data in a file
void preorderTraversal(Node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }
    fprintf(fp, "%d ", root->data);
    preorderTraversal(root->left, fp);
    preorderTraversal(root->right, fp);
}

// Function to perform postorder traversal and store the data in a file
void postorderTraversal(Node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left, fp);
    postorderTraversal(root->right, fp);
    fprintf(fp, "%d ", root->data);
}

int main() {


    clock_t start_time,end_time;
    double time_taken;

    start_time=clock();


    // Open the file containing random data
    FILE* inputFile = fopen("random_data.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file!\n");
        return 1;
    }



    // Create an empty binary tree
    Node* root = NULL;
    int data;

    // Read data from the file and insert it into the binary tree
    while (fscanf(inputFile, "%d", &data) != EOF) {
        root = insertNode(root, data);
    }

    // Close the input file
    fclose(inputFile);

    // Open the files for storing sorted data
    FILE* inorderFile = fopen("Inorder.txt", "w");
    FILE* preorderFile = fopen("Preorder.txt", "w");
    FILE* postorderFile = fopen("Postorder.txt", "w");
    if (inorderFile == NULL || preorderFile == NULL || postorderFile == NULL) {
        printf("Failed to open the output files!\n");
        return 1;
    }

    // Perform inorder traversal and store the sorted data in Inorder.txt
    inorderTraversal(root, inorderFile);
    fclose(inorderFile);

    // Perform preorder traversal and store the sorted data in Preorder.txt
    preorderTraversal(root, preorderFile);
    fclose(preorderFile);

    // Perform postorder traversal and store the sorted data in Postorder.txt
    postorderTraversal(root, postorderFile);
    fclose(postorderFile);

    printf("Sorting and storing in different files completed successfully!\n");
    end_time=clock();

    time_taken=((double)(end_time-start_time)/CLOCKS_PER_SEC)*1000;
    printf("Time taken: %.2f ms\n",time_taken);
    return 0;
}
