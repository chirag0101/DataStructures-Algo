#include<stdio.h>
#include<stdlib.h>
int n=5,top=-1,*stack;

void push(int x){
    if(top==n){
        printf("Stack Full \n");
    }else{
        stack[++top]=x;
    }
}
int pop(){
    if(top==-1){
        printf("Stack Underflow \n");
    }else{
        stack[--top];
    }
}

int peak(){
    if(top==-1){
        printf("Stack Underflow \n");
    }else{
        printf("%d\n",stack[top]);
    }
}

void display(){
    for(int i=top;i>-1;i--){
        printf("%d\n",stack[i]);
    }
}

void main(){
    stack=(int *)malloc(sizeof(int));
    push(1);
    push(2);
    push(3);

    pop();
    peak();
    display();
}