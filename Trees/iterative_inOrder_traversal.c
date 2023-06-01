#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}n;

typedef struct stackFrame{
    struct Node *btNode;
    struct stackFrame *next;
}s;

s *top=NULL;

bool isEmpty(){
    if(top==NULL){
        return true;
    }else{
        return false;
    }
}

void push(n *temp){
    s *newNode=(s*)malloc(sizeof(s));
    newNode->btNode=temp;
    newNode->next=top;
    top=newNode;
}

n* pop(){
    if(isEmpty()){
        printf("\nTree stack is empty!\n");
    }else{
        s *temp=top;
        top=top->next;
        n *temp1=temp->btNode;
        free(temp);
        return temp1;
    }
}

n* createNode(int level){
    level++;
    n *newNode=(n*)malloc(sizeof(n));
    printf("Enter Data:\n");
    scanf("%d",&(newNode->data));

    char ch;
    getchar();
    printf("Want to create left subtree for level %d?\n",level);
    scanf("%c",&ch);

    if(ch=='Y' || ch=='y'){
        newNode->left=createNode(level);
    }else{
        newNode->left=NULL;
    }

    getchar();
    printf("Want to create right subtree for level %d?\n",level);
    scanf("%c",&ch);
    if(ch=='Y' || ch=='y'){
        newNode->right=createNode(level);
    }else{
        newNode->right=NULL;
    }
    return newNode;
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
        printf("%d  ",root->data);
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

void iterativeInOrder(n *root){
    n* temp=root;
    printf("\n");
    if(temp==NULL){
        printf("\nTree Empty!\n");
    }else{
        while(temp!=NULL || !isEmpty()){
            if(temp!=NULL){
                push(temp);
                temp=temp->left;
            }else{
                temp=pop();
                printf(" %d ",temp->data);
                temp=temp->right;
            }
        }
    }
}

int countNodes(n *root){
    if(root==NULL){
        return 0;
    }else{
            return 1+countNodes(root->left)+countNodes(root->right);
    }
}

int sum;
int sumOfNodes(n *root){
    if(root==NULL){
        return 0;
    }else{
        sum=sum+root->data;
        sumOfNodes(root->left);
        sumOfNodes(root->right);
        return sum;
        // return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
    }
}

//tobesolved
int height;
int max(int num1,int num2){
    if(num1>num2){
        return num1;
    }else if(num2>num1){
        return num2;
    }else{
        return num1;
    }
}
int heightOfNode(n *root){
    if(root==NULL){
        return 0;
    }else{
        return max(heightOfNode(root->left),heightOfNode(root->right))+1;
    }
}

void printTree(n *root){
    char ch;
    do{
        int choice;
        printf("1.PreOrder\n");
        printf("2.InOrder\n");
        printf("3.PostOrder\n");
        printf("4.Iterative InOrder\n");
        printf("Enter choice:\n");
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
                        iterativeInOrder(root);
                        break;
            default:
                        printf("Invalid Choice\n");
        }
        getchar();
        printf("\nWanna Continue?");
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}

void main(){
    printf("Creating Binary Tree......\n");
    n *root=(n*)malloc(sizeof(n));
    printf("Enter Data:\n");
    scanf("%d",&(root->data));
    printf("\t\t\tTree rooted with : %d\n",root->data);

    char ch;
    getchar();
    printf("Want to create left subtree for root node?");
    scanf("%c",&ch);

    if(ch=='Y' || ch=='y'){
        root->left=createNode(0);
    }else{
        root->left=NULL;
    }

    getchar();
    printf("Want to create right subtree for root node?");
    scanf("%c",&ch);
    if(ch=='Y' || ch=='y'){
        root->right=createNode(0);
    }else{
        root->right=NULL;
    }

    printTree(root);

    int num=countNodes(root);
    printf("\nNum of nodes: %d\n",num);

    int sum=sumOfNodes(root);
    printf("\nSum of nodes: %d\n",sum);

    int height=heightOfNode(root);
    printf("\nHeight: %d\n",height);
}

/*
                        1
                      /    \
                    2      6
                  / \      / \
                3   4  7    8
                       \
                        5
*/