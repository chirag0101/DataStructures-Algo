#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}n; 

n *head=NULL;

n* createNode(){
    n *newNode=(n*)malloc(sizeof(n));
    printf("Enter Data:");
    scanf("%d",&newNode->data);
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void addRight(){
    n *newNode=createNode();
    if(head->right==NULL){        
        head->right=newNode;
    }else{
        n *temp=head;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=newNode;
    }
}

void addLeftOfRight(){
    n *newNode=createNode();
    n *temp=head;
    while(temp->left!=NULL){
        temp=temp->right;
    }
    temp->left=newNode;
}

void addLeft(){
    n *newNode=createNode();
    if(head->left==NULL){        
        head->left=newNode;
    }else{
        n *temp=head;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        temp->left=newNode;
    }
}

void inOrder(n* root){
    if(root==NULL){
        return;
    }else{
        inOrder(root->left);
        printf(" %d ",root->data);
        inOrder(root->right);
    }
}

void preOrder(n* root){
    if(root==NULL){
        return;
    }else{
        printf(" %d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(n* root){
    if(root==NULL){
        return;
    }else{
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ",root->data);
    }
}

void main(){
            n *root=createNode();
            head=root;
            while(1){
                int ch;
                printf("\nEnter Choice:");
                printf("\n1.Add Child Node of root node At Right");
                printf("\n2.Add Child Node of root node At Left");
                printf("\n3.Exit\n");
                scanf("%d",&ch);

                    if(ch==1){
                            addRight();
                    }
                    else if(ch==2){
                            addLeft();
                    }else if(ch==3){
                            break;
                    }else{
                        printf("\nWrong Choice!");
                    }
                }
    while(1){
                int ch;
                printf("\nEnter Choice:");
                printf("\n1.Add RL");
                printf("\n2.Add Right");
                printf("\n3.Exit\n");
                scanf("%d",&ch);

                if(ch==1){
                            addLeftOfRight();
                }else if(ch==2){
                            addRight();
                }
                else if(ch==3){
                            break;
                }else{
                            printf("\nWrong Choice!");
                }
                }
        while(1){
                int ch;
                printf("\nEnter Traversal Choice:");
                printf("\n1.InOrder");
                printf("\n2.PreOrder");
                printf("\n3.PostOrder");
                printf("\n4.Exit\n");
                scanf("%d",&ch);

                if(ch==1){
                    printf("\n");
                    inOrder(root);
                }else if(ch==2){
                    printf("\n");
                    preOrder(root);
                }
                else if(ch==3){
                    printf("\n");
                    postOrder(root);
                }else if(ch==4){
                    exit(0);
                }else{
                    printf("\nWrong Choice!");
                }
            }
}