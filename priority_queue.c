#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

    int main(){
        int size,choice;
        int front=-1, rear=-1;
        int Queue[MAX_SIZE];
        printf("\n-------------------------------------------\n");
        printf("    WELCOME TO PRIORITY QUEUE OPERATION MENU");
        printf("\n-------------------------------------------\n");
        printf("Enter the size of the Queue : ");
        scanf("%d",&size);
        while (1){
            PrintOperationChoice();
            scanf("%d",&choice);
            switch (choice){
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