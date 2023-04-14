#include<stdio.h>
#include<stdlib.h>

typedef struct Employee{
    int id;
    struct Employee *next;
}emp;

emp *head=NULL;

void insertFirst(int x){
    emp *newNode=(emp*)malloc(sizeof(emp));
    newNode->id=x;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        printf("New node inserted \n");
    }else{
        newNode->next=head;
        head=newNode;
        printf("New node inserted between head and 1st node.\n");
    }
}


void show(){
      emp *temp=head;
    if(head==NULL){
        printf("List Empty \n");
    }else{
        while(temp!=NULL){
            printf("->|%d|",temp->id);
            temp=temp->next;
        }
        printf("\n");
    }
}

void deleteFirst(){
    if(head==NULL){
        printf("List empty \n");
    }else{
        head=head->next;
        printf("1st Node Deleted \n");
    }
}

void main(){
    emp *nn=(emp*)malloc(sizeof(emp));
    nn->id=180;
    nn->next=NULL;

    head=nn;

    insertFirst(90);
    insertFirst(45);
    insertFirst(15);    

    show();

    deleteFirst();

    show();
}