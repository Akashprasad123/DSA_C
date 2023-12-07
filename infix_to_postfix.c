#include<stdio.h>
#include<ctype.h>

#define MAX_SIZE 100

    int top = -1;
    char Stack[MAX_SIZE];

    void push(char c){
            Stack[++top] = c;
    }

    char pop(){
        if(top == -1){
            printf("\nStack underflow");
            return -1;
        }else{
            return Stack[top--];
        }
    }

    int priority(char c){
        if(c == '^')
            return 3;
        if(c == '*' || c == '/' || c == '%')
            return 2;
        if(c == '+' || c == '-')
            return 1;
        if(c == '(')
            return 0;
        return 0;
    }

    int main(){
        char exp[MAX_SIZE];
        char *e, x;

        printf("Enter the Expression : ");
        scanf("%s",exp);
        printf("\nPostfix Expression : ");

        e = exp;
        while(*e != '\0'){
            if(isalnum(*e)){
                printf("%c",*e);
            }
            else if(*e == '('){
                push(*e);
            }
            else if(*e == ')'){
                while((x=pop()) != '('){
                    printf("%c",x);
                }
            }
            else{
                while(priority(Stack[top]) >= priority(*e)){
                    if(Stack[top] == '^' && *e == '^'){
                        push(*e);
                    }else{
                        printf("%c",pop());
                    }
                }
                push(*e);
            }
            e++;
        }
        while(top!=-1){
            printf("%c",pop());
        }
        return 0;
    }