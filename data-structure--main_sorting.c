#include<stdio.h>
int main (){
    int a[5]={5,1,4,2,8};
    int i,j,temp;

    for(i=0;i<5-1;i++){
        for(j=0;j<5-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for 
    (i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}