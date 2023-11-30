#include<stdio.h>
#define MAX_SIZE 100

    void Selection_Sort(int *ar, int len){
        int i, j, small, temp;
        for(i=0; i<len-1; i++){
            small = i;
            for(j=i+1; j<len; j++){
                if(ar[small]>ar[j]){
                    small = j;
                }
            }
            temp = ar[i];
            ar[i] = ar[small];
            ar[small] = temp;
        }
    }

    int main(){
        int size, i;
        int a[MAX_SIZE];
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
        Selection_Sort(a, size);
        printf("\n##### Sorted Array #####\n");
        for(i=0; i<size; i++){
            printf("%d ",a[i]);
        }

        return 0;
    }