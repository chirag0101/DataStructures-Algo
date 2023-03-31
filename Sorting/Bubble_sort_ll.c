#include<stdio.h>
#include<stdlib.h>

typedef struct B_sort{
    int data;
    struct B_sort *next;
}b;

b *head=NULL;

b* createNode(){
    b *newNode=(b*)malloc(sizeof(b));
    printf("\nEnter Element:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    return newNode;
}

void addNode(){
    b *newNode=createNode();
    if(head==NULL){
        head=newNode;
    }else{
        b *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void printLL(){
    b *temp=head;
        while(temp!=NULL){
            printf("->|%d|",temp->data);
            temp=temp->next;
        }
        printf("\n");
}
int b_sort(int size){
    b *temp=head;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(temp->data>temp->next->data){
                int temp1=temp->data;
                temp->data=temp->next->data;
                temp->next->data=temp1; 
            }
            temp=temp->next;
        }
        temp=head;
    }
    return 0;
}
int main(){
    int size;
    printf("Enter Size:");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        addNode();
    }
    printLL();
    b_sort(size);
    printLL();
}