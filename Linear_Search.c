#include<stdio.h>
#define MAX_SIZE 100

    void main(){
        int a[MAX_SIZE];
        int num,n,i,pos = -1;
        printf("Enter the size of the array : ");
        scanf("%d",&num);
        printf("Enter the elements of the array\n");
        for ( i = 0; i < num; i++){
            scanf("%d",&a[i]);
        }
        printf("Enter the element to search : ");
        scanf("%d",&n);
        for ( i = 0; i < num; i++){
            if(a[i]==n){
                pos = i;
                break;
            }
        }
        if (pos != -1){
            printf("Element found at pos = %d\n",pos);
        }
        else{
            printf("Element not found");
        }
    }