// #include<stdio.h>
// #include<stdlib.h>

// typedef struct node{
//     int data;
//     struct node *left;
//     struct node *right;
// }n;

// n* createNode(n *root,int level){
//     level++;
//     n *newNode=(n*)malloc(sizeof(n));
    
//     printf("Enter Data: ");
//     scanf("%d",&newNode->data);
    
//     getchar();
//     char ch;
//     printf("\nDo u want to create left node for level %d ? ",level);
//     scanf("%c",&ch);

//     if(ch=='Y'||ch=='y'){
//         newNode->left=createNode(root,level);
//     }else{
//         newNode->left=NULL;
//     }

//     getchar();
//     printf("\nDo u want to create right node for level %d ? ",level);
//     scanf("%c",&ch);

//     if(ch=='Y'||ch=='y'){
//         newNode->right=createNode(root,level);
//     }else{
//         newNode->right=NULL;
//     }

//     return newNode;
// }
// void preOrder(n *root){
//     if(root==NULL){
//         return ;
//     }
//     printf("%d ",root->data);
//     preOrder(root->left);
//     preOrder(root->right);
// }

// void main(){
//     n *root=(n*)malloc(sizeof(n));
//     printf("Enter data for root node: ");
//     scanf("%d",&root->data);
//     int level=0;
//     getchar();
//     char ch;
//     printf("\nDo u want to create Left subtree? ");
//     scanf("%c",&ch);
//     if(ch=='Y'||ch=='y'){
//         root->left=createNode(root,level);
//     }

//     getchar();
//     printf("\nDo u want to create Right subtree? ");
//     scanf("%c",&ch);
//     if(ch=='Y'||ch=='y'){
//         root->right=createNode(root,level);
//     }

//     preOrder(root);
// }

