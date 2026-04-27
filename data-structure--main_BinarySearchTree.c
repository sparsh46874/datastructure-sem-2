#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data); // >= goes right

    return root;
}

// Print nodes in range [low, high]
void printInRange(struct Node* root, int low, int high) {
    if (root == NULL)
        return;

    // If root is greater than low, check left subtree
    if (root->data > low)
        printInRange(root->left, low, high);

    // If root is in range, print it
    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    // If root is less than high, check right subtree
    if (root->data < high)
        printInRange(root->right, low, high);
}

int main() {
    int n, value, low, high;
    struct Node* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input BST elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Input range
    scanf("%d %d", &low, &high);

    // Print result
    printInRange(root, low, high);

    return 0;
}