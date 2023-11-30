#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

    void PrintOperationChoice(){
        printf("\n-------------------------------------------\n");
        printf("             SELECT AN OPERATION               ");
        printf("\n-------------------------------------------\n");
        printf("TO ADD AN ELEMENT : 1\n");
        printf("TO DELETE AN ELEMENT : 2\n");
        printf("TO DISPLAY CURRENT QUEUE ELEMENTS : 3\n");
        printf("TO EXIT THE PROGRAM : 4\n\n");
        printf("Enter the choice : ");
    }

    void Enque(int Cqueue[], int *f, int *r, int *s){
        int num;
        if(*f == (*r+1)%(*s)){
            printf("Queue is full.\n");
        }
        else{
            if(*f==-1){
                *f = 0;
            }
            printf("Enter the element to add : ");
            scanf("%d",&num);
            *r = (*r+1)%(*s);
            Cqueue[*r] = num;
            printf("%d added to the queue\n",num);
        }
    }

    void Deque(int Cqueue[], int *f, int *r, int *s){
        int item;
        if(*f!=-1){
            item = Cqueue[*f];
            *f = (*f+1)%(*s);
            printf("%d is deleted from the queue\n",item);
            if(*f>*r && *f==(*r+1)%(*s)){
                printf("All items in the queue are deleted.\n");
                *f = -1;
                *r = -1;
                printf("Queue is reseted\n");
            }
        }
        else{
            printf("Queue is empty\n");
        }
    }

    void Display(int Cqueue[], int *f, int *r, int *s){
        int i=*f;
        if(*f!=-1){
            while(i!=*r){
                printf("%d ",Cqueue[i]);
                i = (i+1)%(*s);
            }
            printf("%d",Cqueue[*r]);
        }
        else
            printf("Queue is empty");
    }

    int main(){
            int size,choice;
            int front=-1, rear=-1;
            int Cqueue[MAX_SIZE];
            printf("\n-----------------------------------------\n");
            printf("WELCOME TO CIRCULAR QUEUE OPERATION MENU");
            printf("\n-----------------------------------------\n");
            printf("Enter the size of the Circular Queue : ");
            scanf("%d",&size);
            while (1){
                PrintOperationChoice();
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    Enque(Cqueue, &front, &rear, &size);
                    break;
                case 2:
                    Deque(Cqueue, &front, &rear, &size);
                    break;
                case 3:
                    Display(Cqueue, &front, &rear, &size);
                    break;
                case 4:
                    printf("\nProgram terminated\n");
                    exit(EXIT_SUCCESS);
                default:
                    printf("Invalid Entry...!, Enter a valid choice\n");
                    break;
                }
            }
            return 0;
        }