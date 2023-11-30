#include<stdio.h>
#define MAX_SIZE 100

    int main(){
        int i,j,n,temp;
        int a[MAX_SIZE];
        printf("Enter the size of the element : ");
        scanf("%d",&n);
        printf("Enter the elements : \n");
        for(i=0; i<n; i++){
            scanf("%d",&a[i]);
        }
        printf("##### Unsorted Array #####\n");
        for(i=0; i<n; i++){
           printf("%d ",a[i]);
        }
        for(i=0; i<n-1; i++){
            for(j=0; j<n-i-1; j++){
                if (a[j]>a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        printf("\n##### Sorted Array #####\n");
        for(i=0; i<n; i++){
           printf("%d ",a[i]);
        }
    }