#include<stdio.h>
#include<stdlib.h>
int max=5,front=-1,rear=-1,*queue;
void nqueue(int x){
    if(rear==max-1){
        printf("Full \n");
    }else{
        queue[rear]=x;
        printf("Inserted \n");
        rear++;
    }
}
void show(){
    for(int i=front;i<rear;i++){
        printf("%d \n",queue[i]);
        
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("Full \n");
    }else{
        front++;
        printf("Deleted \n");
    }
}

void main(){
    queue=(int *)malloc(sizeof(int));
    nqueue(1);
    nqueue(2);
    nqueue(3);
    show();
    dequeue();
    show();    
    nqueue(3);
    show();
}