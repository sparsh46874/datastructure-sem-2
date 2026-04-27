/*#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(       ) {
	
// write your code here...


}

// Traverse CLL
void traverseListInCLL(      ) {

// write your code here...


}

// Insert at given position in CLL
NODE insertAtPositionInCLL(         ) {
	
//write your code here..


	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(       ) {
	
	
	
}

// Reverse CLL
NODE reverseCLL(        ) {
	
//write your code here...


}

// Concatenate two CLLs
NODE concatCLL(           ) {

//write your code here..



}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
*/#include <stdio.h>  
 #include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(int n) {
	
if (n <= 0) return NULL;

    NODE first = NULL, last = NULL, temp;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        temp = (NODE)malloc(sizeof(struct node));
        temp->data = x;

        if (first == NULL) {
            first = temp;
            last = temp;
            temp->next = first;
        } else {
            last->next = temp;
            last = temp;
            last->next = first;
        }
    }
    return first;

}

// Traverse CLL
void traverseListInCLL( NODE first ) {

if (first == NULL) return;

    NODE temp = first;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);
    printf("\n");
}

// Insert at given position in CLL
NODE insertAtPositionInCLL( NODE first, int pos, int x ) {
NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = x;

    if (pos == 1) {
        if (first == NULL) {
            newNode->next = newNode;
            return newNode;
        }
        NODE temp = first;
        while (temp->next != first)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = first;
        return newNode;
    }

    NODE temp = first;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == first) {
            printf("Position not found\n");
            free(newNode);
            return first;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return first;
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL( NODE first,int pos ) {
if (first == NULL || pos < 1) {
        printf("Position not found\n");
        return first;
    }

    NODE temp = first, prev = NULL;

    if (pos == 1) {
        if (first->next == first) {
            printf("Deleted element: %d\n", first->data);
            free(first);
            return NULL;
        }

        while (temp->next != first)
            temp = temp->next;

        NODE del = first;
        temp->next = first->next;
        first = first->next;
        printf("Deleted element: %d\n", del->data);
        free(del);
        return first;
    }

    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == first) {
            printf("Position not found\n");
            return first;
		}
   }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return first;
}

// Reverse CLL
NODE reverseCLL( NODE first ) {
if (first == NULL || first->next == first)
        return first;

    NODE prev = NULL, curr = first, next;
    NODE last = first;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != first);

    first->next = prev;
    first = prev;

    return first;
}

// Concatenate two CLLs
NODE concatCLL( NODE first, NODE second) {
if (first == NULL) return second;
    if (second == NULL) return first;

    NODE temp1 = first;
    while (temp1->next != first)
        temp1 = temp1->next;

    NODE temp2 = second;
    while (temp2->next != second)
        temp2 = temp2->next;

    temp1->next = second;
    temp2->next = first;

    return first;

}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
