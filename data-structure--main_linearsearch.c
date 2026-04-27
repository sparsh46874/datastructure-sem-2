#include <stdio.h>
#include <stdlib.h>
int main () {
    int item, i = 0;
    int a[5]    = {10, 20, 30, 40, 50};
    printf("enter searching item : ");
    scanf("%d", &item);

    while (i < 5) {
        if (a[i] == item) {
            printf("item found at index %d\n", i);
            exit(0);
        }
        i++;
    }
    printf("item not found\n");
    return 0;
  
}
