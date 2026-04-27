#include <stdio.h
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
newnode->data = data;
    newnode->next = head;
    head = newnode;
}

if(start==nullptr){
    start=newnode;
}
else{
    struct Node* temp=start;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
}       
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}               
int main() {
    insert(10);
    insert(20);
    insert(30);
    printf("Linked List: ");
    display();
    return 0;
}
