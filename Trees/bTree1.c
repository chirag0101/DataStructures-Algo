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
    scanf("%d",newNode->data);
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
    while(temp->right!=NULL){
        temp=temp->right;
    }
    if(temp->left==NULL){
        temp->left=newNode;
    }
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
        display(root->left);
        printf("%d\n",root->data);
        display(root->right);
    }
}

void main(){
            n *root=createNode();
            head=root;
			int ch;
			printf("\nEnter Choice:");
			printf("\n1.Add Child Node of root node At Right");
			printf("\n2.Add Child Node of root node At Left");
			printf("\n3.Exit\n");
			scanf("%d",&ch);

			switch(ch){
				case 1: 
						addRight();
						break;
				case 2: 
						addLeft();
						break;
                case 3:
						exit(0);
						break;
				default:
						printf("\nWrong Choice!");
			}
    while(1){
    		printf("\nEnter Choice:");
			printf("\n1.Add Node At Right");
			printf("\n2.Add Node At Left");
			printf("\n3.Exit\n");
			scanf("%d",&ch);

            if(ch==1){
                int ch
                printf("\nEnter Choice:");
                printf("\n1.Add Child Node of root node At Right");
                printf("\n2.Add Child Node of root node At Left");
                printf("\n3.Exit\n");
                scanf("%d",&ch);

                switch(ch){
                    case 1: 
                            addLeftOfRight();
                            break;
                    case 2: 
                            addLeft();
                            break;
                    case 3:
                            exit(0);
                            break;
                    default:
                            printf("\nWrong Choice!");
                }
            }else{
                printf("\nEnter Choice:");
                printf("\n1.Add Child Node of root node At Right");
                printf("\n2.Add Child Node of root node At Left");
                printf("\n3.Exit\n");
                scanf("%d",&ch);

                switch(ch){
                    case 1: 
                            addRight();
                            break;
                    case 2: 
                            addLeft();
                            break;
                    case 3:
                            exit(0);
                            break;
                    default:
                            printf("\nWrong Choice!");
                }
            }
    }
    inOrder(root);
}