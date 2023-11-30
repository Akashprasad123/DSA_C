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

    void Enque(int Queue1[], int *f, int *r, int *s){
        int num;
        if(*r == *s-1){
            printf("Queue is full.\n");
        }
        else{
            if(*f==-1){
                *f = 0;
            }
            printf("Enter the element to add : ");
            scanf("%d",&num);
            Queue1[++(*r)] = num;
            printf("%d added to the queue\n",num);
        }
    }

    void Deque(int Queue2[], int *f, int *r){
        int item;
        if(*f!=-1){
            item = Queue2[*f];
            *f = *f+1;
            printf("%d is deleted from the queue\n",item);
            if(*f>*r){
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

    void Display(int Queue3[], int *f, int *r){
        int i;
        if(*f>*r || *f==-1){
            printf("Queue is empty\n");
        }
        else{
            for (i=*f; i<=(*r); i++){
                printf("%d ",Queue3[i]);
            }
        }
    }

    int main(){
        int size,choice;
        int front=-1, rear=-1;
        int Queue[MAX_SIZE];
        printf("\n---------------------------------------\n");
        printf("    WELCOME TO QUEUE OPERATION MENU      ");
        printf("\n---------------------------------------\n");
        printf("Enter the size of the Queue : ");
        scanf("%d",&size);
        while (1){
            PrintOperationChoice();
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                Enque(Queue, &front, &rear, &size);
                break;
            case 2:
                Deque(Queue, &front, &rear);
                break;
            case 3:
                Display(Queue, &front, &rear);
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