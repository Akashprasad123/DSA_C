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
        printf("1 : TO ADD AN ELEMENT AT BEGINING\n");
        printf("2 : TO ADD AN ELEMENT AT END\n");
        printf("3 : TO ADD AN ELEMENT AT A SPECIFIC POSITION\n");
        printf("4 : TO DELETE AN ELEMENT FROM BEGINNING\n");
        printf("5 : TO DELETE AN ELEMENT FROM END\n");
        printf("6 : TO DELETE AN ELEMENT FROM SPECIFIC POSITION\n");
        printf("7 : TO DISPLAY CURRENT ELEMENTS\n");
        printf("8 : TO EXIT THE PROGRAM\n\n");
        printf("Enter the choice : ");
    }

    void AddBegin(){
        struct node *ptr;
        int item;
        ptr = (struct node *)malloc(sizeof(struct node));

        if(ptr == NULL){
            printf("Overflow. Out of Memory\n");
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
            printf("Overflow. Out of Memory\n");
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


    void AddAt(){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        struct node *temp;
        int pos, item;
        
        if(ptr == NULL){
            printf("Overflow. Out of Memory\n");
        }else{
            printf("Enter the position, after which you want to add the element : ");
            scanf("%d",&pos);
            printf("Enter the element  : ");
            scanf("%d",&item);
            ptr->data = item;
            temp = head;
            for(int i=0; i<pos; i++){
                temp = temp->next;
                if(temp->next==NULL){
                    printf("Element is not added");
                    return;
                }
            }
            ptr->next = temp->next;
            temp->next = ptr;
            printf("Element added");
        }
    }


    void DeleteBegin(){
        struct node *ptr;
        if(head == NULL){
            printf("No elements to delete");
        }else{
            ptr = head;
            head = ptr->next;
            free(ptr);
            printf("Element deleted");
        }
    }

    void DeleteEnd(){
        struct node *ptr, *preptr;
        ptr = head;
        while(1){
            if(ptr->next!=NULL){
                preptr = ptr;
                ptr = ptr->next;
                continue;
            }else{
                preptr->next = NULL;
                free(ptr);
                printf("Element deleted");
                break;
            }
        }
    }

    void DeleteAt(){
        struct node *ptr, *temp;
        int pos;
        ptr = head;
        printf("Enter the position, after which you want to delete the element : ");
        scanf("%d",&pos);
        temp = head;
        for(int i=0; i<pos; i++){
            temp = temp->next;
            if(temp->next == NULL){
                printf("Invalid position. Can't delete.");
                return;
            }
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
        printf("Element deleted");
    }


    void Display(){
        struct node *temp;
        temp = head;
        if(temp != NULL){
            while(temp != NULL){
                printf("%d",temp->data);
                temp = temp->next;
            }
        }else{
            printf("Nothing to print");
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
                case 3 :
                    AddAt();
                    break;
                case 4 :
                    DeleteBegin();
                    break;
                case 5 :
                    DeleteEnd();
                    break;
                case 6 :
                    DeleteAt();
                    break;
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
    