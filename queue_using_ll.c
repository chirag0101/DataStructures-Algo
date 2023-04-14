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
    printf("Enter Element to enqueue:\n");
    scanf("%d",&newNode->data);
    printf("\n");
    return newNode;
}

void enqueue(){
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

void dequeue(){
    s *temp=head,*temp1;
    if(head==NULL){
        printf("Queue Empty!\n\n");
    }else{
        temp1=temp->next;
        free(head);
        head=temp1;
        printf("First Element dequeued!\n\n");
    }
}

void display(){
    s *temp1=head;
    printf("Queue:");
    while(temp1!=NULL){
        printf("|%d|",temp1->data);
        temp1=temp1->next;
    }
    printf("\n\n");
}

void main(){
    while(1){
        int ip;
        printf("1.enqueue ELEMENT\n");
        printf("2.dequeue ELEMENT\n");
        printf("3.DISPLAY QUEUE\n");
        printf("4.QUIT\n");
        printf("I/P:");
        scanf("%d",&ip);
        switch (ip){
            case 1:
                {   
                    enqueue();
                    break;
                }
            case 2:
                    dequeue();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                printf("Invalid Input!\n\n");
                break;
        }
    }
}