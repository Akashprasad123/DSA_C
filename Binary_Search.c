#include<stdio.h>
#define MAX_SIZE 100

    int Binary_Search(int key, int *arr, int len){
        int start = 0, end = len-1, pos=-1, mid;
        while (pos == -1){
            mid = (start+end)/2;
            if (key == arr[mid]){
                pos = mid;
            }
            else if(key < arr[mid]){
                end = mid-1;
            }
            else if(key > arr[mid]){
                start = mid+1;
            }
        }
        return pos;
    }

    int main(){
        int i, key, size, loc;
        int a[MAX_SIZE];
        printf("Enter the size of the array : ");
        scanf("%d",&size);
        printf("Enter the elements : \n");
        for(i=0; i<size; i++){
            scanf("%d",&a[i]);
        }
        printf("Enter the element to search : ");
        scanf("%d",&key);
        loc = Binary_Search(key, a, size);
        printf("Element %d found at position %d",key, loc);

    }