#include<stdio.h>
#include<stdlib.h>
int max=5,front=-1,rear=-1,*queue;
void enqueue(int x){
    if(rear==max-1){
        printf("QUEUE FULL!\n\n");
    }else{
        queue[rear]=x;
        printf("Element Inserted!\n\n");
        rear++;
    }
}
void show(){
    if(front==rear){
        printf("QUEUE EMPTY!\n\n");
    }else{
        for(int i=front;i<rear;i++){
            printf("|%d|",queue[i]);
        }
        printf("\n\n");
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("QUEUE EMPTY\n\n");
    }else{
        front++;
        printf("Element Deleted\n\n");
    }
}

void main(){
    queue=(int *)malloc(sizeof(int));
    while(1){
        int ip;
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.DISPLAY QUEUE\n");
        printf("4.QUIT\n");
        scanf("%d",&ip);
        switch (ip){
        case 1:
            {   int x;
                printf("Enter element to enqueue:\n");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
        case 2:
                dequeue();
                break;
        case 3:
                show();
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