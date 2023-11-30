#include<stdio.h>
#define MAX_SIZE 100

    void Insertion_Sort(int *a, int len){
        int i,j,temp;
        for(i=1; i<len; i++){
            j = i;
            while(j>0 && a[j]<a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                j--;
            }
        }
    }

    int main(){
        int a[MAX_SIZE];
        int i,size;
        printf("Enter the size of the array : ");
        scanf("%d",&size);
        printf("Enter the elements : \n");
        for(i=0; i<size; i++){
            scanf("%d",&a[i]);
        }
        printf("##### Unsorted Array #####\n");
        for(i=0; i<size; i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        Insertion_Sort(a, size);
        printf("##### Sorted Array #####\n");
        for(i=0; i<size; i++){
            printf("%d ",a[i]);
        }
    }