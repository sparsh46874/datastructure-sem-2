#include <stdio.h>

#include <stdlib.h>

struct node {

int data;

struct node *link;

45

NULL

};

1000

int main() {

struct node *head = NULL;

head = (struct node *)malloc(sizeof(struct node));

1000

head->data = 45;

Head

head->link = NULL;

printf("%d", head->data);

return 0;

}