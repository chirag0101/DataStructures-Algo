#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stack *next;
}s;

s *head=NULL;

s* createNode(){
    s *newNode=(s*)malloc(sizeof(s));
    printf("Enter Element to Push:\n");
    scanf("%d",&newNode->data);
    printf("\n");
    return newNode;
}

void push(){
    s *newNode=createNode();
    if(head==NULL){
        head=newNode;
    }else{
        s *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void pop(){
    s *temp=head;
    if(head==NULL){
        printf("Stack Empty!\n\n");
    }else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        printf("Top Element Popped!\n\n");
    }
}

void peek(){
    s *temp=head;
    if(head==NULL){
        printf("Stack Empty!\n\n");
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("\nPeek Element:%d\n\n",temp->data);
    }
}

void display(){
    s *cur=head;
	s *prev=NULL;
	s *next=head;
	if(head==NULL){
        printf("Stack Empty!\n]n");
    }else{
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
        s *temp1=head;
        printf("Stack:");
        while(temp1!=NULL){
            printf("|%d|\n",temp1->data);
            temp1=temp1->next;
        }
        printf("\n\n");
    }
}

void main(){
    while(1){
        int ip;
        printf("1.PUSH ELEMENT\n");
        printf("2.POP ELEMENT\n");
        printf("3.PEEK STACK\n");
        printf("4.DISPLAY STACK\n");
        printf("5.QUIT\n");
        printf("I/P:");
        scanf("%d",&ip);
        switch (ip){
            case 1:
                {   
                    push();
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
