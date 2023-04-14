#include<stdio.h>
#include<stdlib.h>
int n=5,top=-1,*stack;

void push(int x){
    if(top==n){
        printf("Stack Full!\n\n");
    }else{
        stack[++top]=x;
        printf("Element Inserted!\n\n");
    }
}
int pop(){
    if(top==-1){
        printf("Stack Underflow!\n\n");
    }else{
        stack[--top];
        printf("Element Popped!\n\n");
    }
}

int peek(){
    if(top==-1){
        printf("Stack Underflow!\n\n");
    }else{
        printf("Peak Element: %d\n\n",stack[top]);
    }
}

void display(){
    for(int i=top;i>-1;i--){
        printf("|%d|\n",stack[i]);
    }
    printf("\n\n");
}

void main(){
    stack=(int *)malloc(sizeof(int));
    while(1){
        int ip;
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY STACK\n");
        printf("5.QUIT\n");
        scanf("%d",&ip);
        switch (ip){
        case 1:
            {   int x;
                printf("Enter element to PUSH:\n");
                scanf("%d",&x);
                push(x);
                break;
            }
        case 2:
                pop();
                break;
        case 3:
                peek();
                break;
        case 4:
                display();
                break;
        case 5:
                exit(0);
                break;
        default:
            printf("Invalid Input!\n\n");
            break;
        }
    }
}