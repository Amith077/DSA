#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for binary search tree
typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(char data) {
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

// Function to insert a node into the binary search tree
Node* insertNode(Node* root, char data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (tolower(data) <= tolower(root->data)) {
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
    fprintf(fp, "%c ", root->data);
    inorderTraversal(root->right, fp);
}

// Function to perform preorder traversal and store the data in a file
void preorderTraversal(Node* root, FILE* fp) {
    if (root == NULL) {
        return;
    }
    fprintf(fp, "%c ", root->data);
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
    fprintf(fp, "%c ", root->data);
}

int main() {
    // Open the files for storing sorted data
    FILE* inorderFile = fopen("Inorder.txt", "w");
    FILE* preorderFile = fopen("Preorder.txt", "w");
    FILE* postorderFile = fopen("Postorder.txt", "w");
    if (inorderFile == NULL || preorderFile == NULL || postorderFile == NULL) {
        printf("Failed to open the output files!\n");
        return 1;
    }

    // Create an empty binary search tree
    Node* root = NULL;

    // Read the input string from the user
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Insert each character into the binary search tree
    int i = 0;
    while (inputString[i] != '\0') {
        if (isalpha(inputString[i])) {
            root = insertNode(root, inputString[i]);
        }
        i++;
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

    printf("Sorting and storing completed successfully!\n");

    return 0;
}
