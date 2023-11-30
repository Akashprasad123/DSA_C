#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100

int front=-1, rear=-1;

    void PrintOperationChoice(){
        printf("\n-------------------------------------------\n");
        printf("             SELECT AN OPERATION               ");
        printf("\n-------------------------------------------\n");
        printf("TO ADD AN ELEMENT : 1\n");
        printf("TO DELETE AN ELEMENT : 2\n");
        printf("TO DISPLAY CURRENT DEQue ELEMENTS : 3\n");
        printf("TO EXIT THE PROGRAM : 4\n\n");
        printf("Enter the choice : ");
    }

    void Enque(int Queue[], int *s, int *f, int *r, bool type){
        int num,loc;
        if(type == true){
            if(*f == (*r+1)%(*s)){
                printf("Queue is full...!");
            }
            else{
                if(*f==-1){
                    *f = 0;
                }
                printf("Enter the number to add : ");
                scanf("%d",&num);
                *r = (*r+1)%(*s);
                Queue[*r] = num;
                printf("%d is added to the Queue",num);
            }
        }
        else{
            printf("\n----SELECT WHERE TO ADD----\n\n");
            printf("At Begining : 1\n");
            printf("At End : 2\n\n");
            printf("Enter the choice : ");
            scanf("%d",&loc);
            // printf("%d",loc);
            if(loc == 1){
                if(*f == (*r+1)%(*s)){
                    printf("Queue is full...!");
                }
                else{
                    if(*f==-1){
                        *f = 0;
                    }
                    printf("Enter the number to add : ");
                    scanf("%d",&num);
                    if(*f==0){
                        *f=(*s)-1;
                    }else{
                        *f = (*f-1)%(*s);
                    }
                    Queue[*f] = num;
                    printf("%d is added to the Queue",num);
                }
            }
            else if(loc == 2){
                if(*f == (*r+1)%(*s)){
                    printf("Queue is full...!");
                }
                else{
                    if(*f==-1){
                        *f = 0;
                    }
                    printf("Enter the number to add : ");
                    scanf("%d",&num);
                    *r = (*r+1)%(*s);
                    Queue[*r] = num;
                    printf("%d is added to the Queue",num);
                }
            }
        }
    }

    void Deque(int Queue[], int *s, int *f, int *r, bool type){
        int item, loc=0;
        if(type==true){
            printf("\n----SELECT WHERE TO DELETE----\n\n");
            printf("At Begining : 1\n");
            printf("At End : 2\n\n");
            printf("Enter your choice : ");
            scanf("%d",&loc);
            if(loc==1){
                if(*f!=-1){
                    item = Queue[*f];
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
            }else{
                if(*f!=-1){
                    item = Queue[*r];
                    if(*r==0){
                        *r = (*s)-1;
                    }else{
                        *r = (*r-1)%(*s);
                    }
                    printf("%d is deleted from the queue\n",item);
                    if(*f>*r && *f==(*r+1)%(*s)){
                        printf("All items in the queue are deleted.\n");
                        *f = -1;
                        *r = -1;
                        printf("Queue is reseted\n");
                    }
                }
            }
        }
        else{
            if(*f!=-1){
                item = Queue[*f];
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
    }

    void Display(int Queue[], int *s, int *f, int *r){
        int i=*f;
        if(*f!=-1){
            while(i!=*r){
                printf("%d ",Queue[i]);
                i = (i+1)%(*s);
            }
            printf("%d",Queue[*r]);
        }
        else
            printf("Queue is empty");
    }

    void InResDEQ(int *size, int Queue[]){
        int choice;
        while(1){
            PrintOperationChoice();
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    Enque(Queue, size, &front, &rear, true);
                    break;
                case 2:
                    Deque(Queue, size, &front, &rear, true);
                    break;
                case 3:
                    Display(Queue, size, &front, &rear);
                    break;
                case 4:
                    printf("Exited from program");
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    printf("Invalid Entry...!, Choose a valid option.\n\n");
            }
        }
    }

    void OutResDEQ(int *size, int Queue[]){
        int choice;
        while(1){
            PrintOperationChoice();
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    Enque(Queue, size, &front, &rear, false);
                    break;
                case 2:
                    Deque(Queue, size, &front, &rear, false);
                    break;
                case 3:
                    Display(Queue, size, &front, &rear);
                    break;
                case 4:
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    printf("Invalid Entry...!, Choose a valid option.\n\n");
            }
        }
        
    }

    int main(){
            int size,DEQueChoice;
            int Queue[MAX_SIZE];
            printf("\n-----------------------------------------\n");
            printf("     WELCOME TO DEQue OPERATION MENU");
            printf("\n-----------------------------------------\n");
            printf("\n\nEnter the size of the Queue : ");
            scanf("%d",&size);
            printf("\n------SELECT THE TYPE OF DEQUE------\n\n");
            printf("Input Restricted DEQue : 1\n");
            printf("Output Restricted DEQue : 2\n");
            printf("Quit the Menu : 3\n\n");
            printf("Enter your choice : ");
            scanf("%d",&DEQueChoice);
            while(1){
                switch (DEQueChoice){
                    case 1:
                        InResDEQ(&size, Queue);
                        break;
                    case 2:
                        OutResDEQ(&size, Queue);
                        break;
                    case 3:
                        exit(EXIT_SUCCESS);
                    default:
                        printf("Invalid Entry...!, Choose a valid option.\n\n");
                        break;
                }
            }
    }