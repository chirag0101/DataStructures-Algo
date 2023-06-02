#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}n;

typedef struct queue{
    struct node *btNode;
    struct queue *next;
}q;

q *front=NULL;
q *rear=NULL;

n* createNode(int level){
    level++;
    n *newNode=(n*)malloc(sizeof(n));
    printf("\nEnter Data for node: ");
    scanf("%d",&newNode->data);

    getchar();
    char ch;
    printf("\nDo you want to add node to left of level %d node? ",level);
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y'){
        newNode->left=createNode(level);
    }else{
        newNode->left=NULL;
    }

    getchar();
    printf("\nDo you want to add node to right of level %d node? ",level);
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y'){
        newNode->right=createNode(level);
    }else{
        newNode->right=NULL;
    }

    return newNode;
}

bool isEmpty(){
    if(front==NULL && rear==NULL){
        return true;
    }else{
        return false;
    }
}

void enqueue(n *temp){
    q *newNode=(q*)malloc(sizeof(q));
    newNode->btNode=temp;
    newNode->next=NULL;

    if(isEmpty()){
        front=rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
}

n* dequeue(){
    if(isEmpty()){
        printf("\nTree Queue Empty!");
    }else{
        q *temp=front;
        n *temp1=temp->btNode;

        if(front==rear){
            front=rear=NULL;
        }else{
            front=front->next;
        }
        free(temp);
        return temp1;
    }
}

void preOrder(n *root){
    if(root==NULL){
        return;
    }else{
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(n *root){
    if(root==NULL){
        return;
    }else{
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(n *root){
    if(root==NULL){
        return;
    }else{
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

//we use levelOrder traversal to traverse a tree level wise from left->right.
//we use queue to perform this as we check if the each node has it's right or left node.
//if there exists any child nodes in the tree then the parent node is printed and dequeued from the queue.

void levelOrder(n *root){
    n *temp=root;

    enqueue(root);
    
    while(!isEmpty()){
        
        temp=dequeue();
        printf("%d ",temp->data);
        
        if(temp->left!=NULL){
            enqueue(temp->left);
        }
        
        if(temp->right!=NULL){
            enqueue(temp->right);
        }
    }
}

void printTree(n *root){
    char ch;
    do{
        int choice;
        printf("Choose Traversal Technique:");
        printf("\n1.preOrder");
        printf("\n2.inOrder");
        printf("\n3.postOrder");
        printf("\n4.levelOrder");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                        preOrder(root);
                        break;
            case 2:
                        inOrder(root);
                        break;
            case 3:
                        postOrder(root);
                        break;

            case 4:
                        levelOrder(root);
                        break;

            default:
                        printf("\nInvalid Choice!");
        }
        getchar();
        printf("\nDo u want to continue? ");
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}

void main(){

    n *root=(n*)malloc(sizeof(n));
    printf("Creating Node...");
    printf("\nEnter Data for root node: ");
    scanf("%d",&root->data);

    getchar();
    
    char ch;
    printf("\nWant to create left subtree for root node? ");
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y'){
        root->left=createNode(0);
    }else{
        root->left=NULL;
    }

    getchar();

    printf("\nWant to create right subtree for root node? ");
    scanf("%c",&ch);
    if(ch=='y' || ch=='Y'){
        root->right=createNode(0);
    }else{
        root->right=NULL;
    }

    printTree(root);
    getchar();

}