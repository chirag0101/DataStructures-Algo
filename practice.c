// Stack-Array
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// int top=-1;

// void push(int stack[],int size){
//     if(top==size){
//         printf("\nStack Overflow!!!");
//         return;
//     }
//     int data;
//     printf("\nEnter Data to be Pushed:");
//     scanf("%d",&data);
//     top++;
//     stack[top]=data;
//     printf("\nData Pushed");
// }

// void pop(int stack[],int size){
//     if(top==-1){
//         printf("\nStack Underflow!!!");
//         return;
//     }
//     top--;
//     printf("\nTop Element Popped");
// }

// void peek(int stack[],int size){
//     if(top==-1){
//         printf("\nStack Overflow!!!");
//         return;
//     }
//     printf("\nTop Element is %d",stack[top]);
// }

// void display(int stack[],int size){
//     if(top==-1){
//         printf("\nStack Underflow!!!");
//         return;
//     }
//     printf("\nStack Elements are:");
//     for(int i=0;i<=top;i++){
//         printf("\n%d",stack[i]);
//     }
// }

// int main(){
    
//     int size;
//     printf("\nEnter the size of the stack:");
//     scanf("%d",&size);

//     int stack[size];

//     while(1){
//         int choice;
//         printf("\n\nChoose stack operation:");
//         printf("\n1.Push");
//         printf("\n2.Pop");
//         printf("\n3.Peek");
//         printf("\n4.Display");
//         printf("\n5.Quit");
//         printf("\nYour Choice:");

//         scanf("%d",&choice);

//         switch (choice)
//         {
//         case 1:
//             push(stack,size-1);
//             break;

//         case 2:
//             pop(stack,size-1);
//             break;

//         case 3:
//             peek(stack,size-1);
//             break;

//         case 4:
//             display(stack,size-1);
//             break;

//         case 5:
//             exit(0);
//             break;

//         default:
//             printf("\nWrong Choice!!!");
//             break;
//         }

//     }
//     return 0;
// }

//Queue-Array

// int front=-1,rear=-1;

// void enqueue(int queue[],int size){
//     if(rear==size-1){
//         printf("\nQueue Overflow!!!");
//         return;
//     }
//     int data;
//     printf("\nEnter Data:");
//     scanf("%d",&data);
//     if(front==-1 && rear==-1){
//         front=0;
//         rear=0;
//     }else{
//         rear++;
//     }
//     queue[rear]=data;    
// }

// void dequeue(int queue[],int size){
//     if(front==-1&&rear==-1){
//         printf("\nQueue Underflow!!!");
//         return;
//     }
//     front++;
// }

// void show(int queue[],int size){
//     if(front==rear){
//         printf("QUEUE EMPTY!\n\n");
//     }else{
//         for(int i=front;i<rear;i++){
//             printf("|%d|",queue[i]);
//         }
//         printf("\n\n");
//     }
// }

// int main(){
    
//     int size;
//     printf("\nEnter the size of the queue:");
//     scanf("%d",&size);

//     int queue[size];

//     while(1){
//         int choice;
//         printf("\n\nChoose queue operation:");
//         printf("\n1.enqueue");
//         printf("\n2.dequeue");
//         printf("\n3.Display");
//         printf("\n4.Quit");
//         printf("\nYour Choice:");

//         scanf("%d",&choice);

//         switch (choice)
//         {
//         case 1:
//             enqueue(queue,size-1);
//             break;

//         case 2:
//             dequeue(queue,size-1);
//             break;

//         case 3:
//             display(queue,size-1);
//             break;

//         case 4:
//             exit(0);
//             break;

//         default:
//             printf("\nWrong Choice!!!");
//             break;
//         }

//     }
// }

//Singly LL

typedef struct node{
    int data;
    struct node *next;
}n;

n *head=NULL;

n* createNode(){
    n *newNode=(n*)malloc(sizeof(n));
    printf("\nEnter Data to be Added:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    return newNode;
}

void addFirst(){
    n *newNode=createNode();
    if (head==NULL){
            head=newNode;
    }else{
        newNode->next=head;
        head=newNode;
        printf("\nNode added at 1st!");
    }
}

void delFirst(){
    if (head==NULL){
        printf("\nLL empty!");
        return;
    }else{
        n *temp=head->next;
        free(head);
        head=temp;
    }
}

void delLast(){
    if (head==NULL){
        printf("\nLL empty!");
        return;
    }else{
        n *temp=head;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next->next);
        temp->next=NULL;
    }
}

void addLast(){
    if (head==NULL){
        addFirst();
        return;
    }else{
            n *newNode=createNode();
            n *temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            printf("\nNode added at Last!");
        }
}

void displayLL(){
    if(head==NULL){
        printf("\nLL empty!");
        return;
    }
    n *temp=head;
    while(temp!=NULL){
        printf("->|%d|",temp->data);
        temp=temp->next;
    }
}

int main(){
    int choice;
    while(1){
        int choice;
        printf("\n\nChoose LL operation:");
        printf("\n1.Add Node at 1st");
        printf("\n2.Add Node at Last");
        printf("\n3.Delete 1st Node");
        printf("\n4.Delete Last Node");
        printf("\n5.Display LL");
        printf("\n6.Exit");
        printf("\nYour Choice:");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            addFirst();
            break;

        case 2:
            addLast();
            break;

        case 3:
            delFirst();
            break;

        case 4:
            delLast();
            break;

        case 5:
            displayLL();
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nInvalid Choice!!!");
            break;
        }
    }
}