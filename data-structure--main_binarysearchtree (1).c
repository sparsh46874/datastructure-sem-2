/*#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};



struct TreeNode* insertNode(   ) {
	
}


void inorderTraversal(  ) {

}

void preorderTraversal(  ) {

}

void postorderTraversal(  ) {

}

struct TreeNode* deleteNode(  ) {
	
}


int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                inorderTraversal(root);
                break;
            case 3:
                preorderTraversal(root);
                break;
            case 4:
                postorderTraversal(root);
                break;
            case 5: {
                printf("Delete: ");
                scanf("%d", &data);
                int found = 0;
                root = deleteNode(root, data, &found);
                if (!found) {
                    printf("Value not found\n");
                }
                break;
            }
            case 6:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}*/#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node (duplicates go to right)
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

// Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }
    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
    printf("\n");
}

// Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }
    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left)
            stack1[++top1] = curr->left;
        if (curr->right)
            stack1[++top1] = curr->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
struct Node* deleteNode(struct Node* root, int data, int *found) {
    if (root == NULL) return NULL;

    if (data < root->data) {
        root->left = deleteNode(root->left, data, found);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data, found);
    } else {
        *found = 1;

        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, found);
    }
    return root;
}

// Free entire tree
void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                inorderTraversal(root);
                break;

            case 3:
                preorderTraversal(root);
                break;

            case 4:
                postorderTraversal(root);
                break;

            case 5: {
                printf("Delete: ");
                scanf("%d", &data);
                int found = 0;
                root = deleteNode(root, data, &found);
                if (!found) {
                    printf("Value not found\n");
                }
                break;
            }

            case 6:
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}