#include<stdio.h>
#include<stdlib.h>

    struct node{
        int data;
        struct node *next;
    };

    struct node *top;

    void PrintOperationChoice(){
        printf("\n-------------------------------------------\n");
        printf("             SELECT AN OPERATION               ");
        printf("\n-------------------------------------------\n");
        printf("1 : TO PUSH AN ELEMENT\n");
        printf("2 : TO POP AN ELEMENT : 2\n");
        printf("3 : TO DISPLAY CURRENT STACK ELEMENTS\n");
        printf("4 : TO EXIT FROM THE PROGRAM\n\n");
        printf("Enter the choice : ");
    }

    void push(){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));

        if(ptr == NULL){
            printf("Stack overflow. Out of memory");
        }else{
            printf("Enter the element to add : ");
            scanf("%d",&(ptr->data));
            ptr->next = top;
            top = ptr;
            printf("Element added");
        }
    }

    void pop(){
        struct node *temp;
        if(top == NULL){
            printf("Stack Underflow. No elements to delete");
        }else{
            temp = top;
            top = top->next;
            free(temp);
            printf("Element deleted");
        }
    }

    void display(){
        struct node *temp;

        if(top == NULL){
            printf("Stack Underflow. No elements to display");
        }else{
            temp = top;
            if(temp!=NULL){
                while(temp!=NULL){
                    printf("%d\n",temp->data);
                    temp = temp->next;
                }
            }
        }

    }

    int main(){
        int choice;
        printf("\n---------------------------------------\n");
        printf("    WELCOME TO STACK OPERATION MENU      ");
        printf("\n---------------------------------------\n");
        while (1){
            PrintOperationChoice();
            scanf("%d",&choice);
            switch (choice){
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
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