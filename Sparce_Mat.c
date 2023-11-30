#include<stdio.h>
#define MAX_SIZE 50

    void mat_in(int mat[][MAX_SIZE], int m, int n){
        int i,j,num;
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                scanf("%d",&num);
                mat[i][j]=num;
            }
        }
    }

    void print_mat(int mat[][MAX_SIZE], int m, int n){
        printf("The matrix is \n");
        int i,j;
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }
    }

    void Sparse_mat(int mat[][MAX_SIZE], int m, int n, int*r, int *c, int *val, int *count){
        int i,j;
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                if(mat[i][j] != 0){
                    val[*count] = mat[i][j];
                    r[*count] = i;
                    c[*count] = j;
                    (*count)++;
                }
            }
        }
    }

    void Sparse_print(int *val, int *r, int*c, int l){
        int i;
        printf("ROW\tCOLUMN\tVALUE\n");
        for(i=0;i<l;i++){
            printf("%d\t%d\t%d",r[i],c[i],val[i]);
            printf("\n");
        }
    }

    void main(){
        int m,n,count=0;
        printf("Enter the size of the matrix\n");
        printf("Row : ");
        scanf("%d",&m);
        printf("Column : ");
        scanf("%d",&n);
        int a[m][n];
        int r[MAX_SIZE], c[MAX_SIZE], val[MAX_SIZE];
        printf("Enter the elements : \n");
        mat_in(a,m,n);
        print_mat(a,m,n);
        Sparse_mat(a,m,n,r,c,val,&count);
        Sparse_print(val,r,c,count);
    }