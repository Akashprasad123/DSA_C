#include<stdio.h>
#define MAX_SIZE 100

void polyin(int *pe, int *pc, int *term){
    int i, e=0, c=0;
    printf("Enter the no of terms in first polynomial : ");
    scanf("%d",term);
    for(i=0; i<*term; i++){
        printf("Enter the exponent of X : ");
        scanf("%d",&e);
        pe[i] = e;
        printf("Enter the coefficeint of X^%d : ",e);
        scanf("%d",&c);
        pc[i] = c;
    }
}

void polyAdd(int *p1e, int *p1c, int *p2e, int *p2c, int *res_e, int *res_c, int term){
    int i=0,j=0,k=0;
    while (i < term) {
        if (p1e[i] == p2e[j]) {
            res_c[k] = p1c[i] + p2c[j];
            res_e[k] = p1e[i];
            i++;
            j++;
        } else if (p1e[i] > p2e[j]) {
            res_c[k] = p1c[i];
            res_e[k] = p1e[i];
            i++;
        } else {
            res_c[k] = p2c[j];
            res_e[k] = p2e[j];
            j++;
        }
        k++;
    }
}


int main(void){
    int term1, term2;
    int p1e[MAX_SIZE], p1c[MAX_SIZE], p2e[MAX_SIZE], p2c[MAX_SIZE];
    int res_e[MAX_SIZE], res_c[MAX_SIZE];
    int i;
    printf("Enter the details of first polynomial\n");
    polyin(p1e, p1c, &term1);
    printf("Enter the details of Second polynomial\n");
    polyin(p2e, p2c, &term2);
    printf(" ADDING POLYNMIALS \n");
    for(i=0; i<term1; i++){
        printf("%dX^%d",p1c[i],p1e[i]);
        if(i != term1-1)
            printf("+");
        else
            printf(" = 0");
    }
    printf("\n");
    for(i=0; i<term2; i++){
        printf("%dX^%d",p2c[i],p2e[i]);
        if(i != term2-1)
            printf("+");
        else{
            printf(" = 0");
        }
             
    }
    printf("\n");
    polyAdd(p1e, p1c, p2e, p2c, res_e, res_c, (term1>term2) ? term1 : term2);
    for(i=0; i<term1; i++){
        printf("%dX^%d",res_c[i],res_e[i]);
        if(i != term1-1)
            printf("+");
        else
            printf(" = 0");
    }
}
