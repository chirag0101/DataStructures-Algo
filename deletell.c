#include<stdio.h>
#include<stdlib.h>
typedef struct demo{
    int data;
    struct demo *next;
}d;

d *head=NULL;

d* createNode(){
    d* newNode=(d*)malloc(sizeof(d));
        int data;
        printf("Enter data:\n");
        scanf("%d",&data);
        newNode->next=NULL;
        
    return newNode;
}

d* addNode(){
    d* newNode=createNode();
    d* temp=head;

    

}

void main(){
    d *newNode=createNode();

}