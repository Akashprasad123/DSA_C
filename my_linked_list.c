#include<stdio.h>
#include<stdlib.h>

    struct node{
        int data;
        struct node *next;
    };

    struct node *head;


    void PrintOperationChoice(){
        printf("\n\n-------------------------------------------\n");
        printf("             SELECT AN OPERATION               ");
        printf("\n-------------------------------------------\n");
        printf("TO ADD AN ELEMENT AT BEGINING : 1\n");
        printf("TO ADD AN ELEMENT AT END : 2\n");
        printf("TO ADD AN ELEMENT AT A SPECIFIC POSITION : 3\n");
        printf("TO DELETE AN ELEMENT FROM BEGINNING : 4\n");
        printf("TO DELETE AN ELEMENT FROM END : 5\n");
        printf("TO DELETE AN ELEMENT FROM SPECIFIC POSITION : 6\n");
        printf("TO DISPLAY CURRENT ELEMENTS : 7\n");
        printf("TO EXIT THE PROGRAM : 8\n\n");
        printf("Enter the choice : ");
    }

    void AddBegin(){
        struct node *ptr;
        int item;
        ptr = (struct node *)malloc(sizeof(struct node));

        if(ptr == NULL){
            printf("Overflow. Out of Memory");
        }else{
            printf("Enter the element to add : ");
            scanf("%d",&item);
            ptr->data = item;
            ptr->next = head;
            head = ptr;
            printf("Element added");
        }
    }


    void AddEnd(){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        int item;
        struct node *temp;

        if(ptr == NULL){
            printf("Overflow. Out of Memory");
        }else{
            printf("Enter the element to add : ");
            scanf("%d",&item);
            ptr->data = item;
            if(head == NULL){
                ptr->next = NULL;
                head = ptr;
            }else{
                temp = head;
                while(1){
                    if(temp->next != NULL){
                        temp = temp->next;
                        continue;
                    }
                    temp->next = ptr;
                    ptr->next = NULL;
                    break;
                }
                printf("Element added");
            }
        }
    }


    void Display(){
        struct node *temp;
        temp = head;
        while(1){
            printf("%d\n",temp->data);
            temp = temp->next;
            if(temp->next == NULL){
                printf("%d\n",temp->data);
                break;
            }
        }
    }


    int main(){
        int choice = 0;
        printf("\n------------WELCOME TO LINKED LIST OPERATION MENU------------\n");
        while(choice != 8){
            PrintOperationChoice();
            scanf("%d",&choice);
            switch(choice){
                case 1 :
                    AddBegin();
                    break;
                case 2 :
                    AddEnd();
                    break;
                // case 3 :
                //     AddAt();
                //     break;
                // case 4 :
                //     DeleteBegin();
                //     break;
                // case 5 :
                //     DeleteEnd();
                //     break;
                // case 6 :
                //     DeleteAt();
                //     break;
                case 7 :
                    Display();
                    break;
                case 8 :
                    exit(0);
                    break;
                default:
                    printf("Invalid Entry. Choose a valid option.\n\n");
                    
            }

        }
        return 0;
    }
    