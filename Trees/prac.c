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

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}n;

n* solvePre(int in[],int pre[],int inStart,int inEnd,int preStart,int preEnd){
    int rootData=pre[preStart];
    if(inStart>inEnd){
        return NULL;
    }

    n *temp=(n*)malloc(sizeof(n));
    temp->data=rootData;

    if(inStart==inEnd){
        return temp;
    }

    int idx;
    for(idx=inStart;idx<=inEnd;idx++){
        if(in[idx]==rootData){
            break;
        }
    }

    int Llen=idx-inStart;
    temp->left=solvePre(in,pre,inStart,idx-1,preStart+1,preStart+Llen);
    temp->right=solvePre(in,pre,idx+1,inEnd,preStart+Llen+1,preEnd);    
    return temp;
}

n* solvePost(int in[],int post[],int inStart,int inEnd,int postStart,int postEnd){
    int rootData=post[postEnd];
    if(inStart>inEnd){
        return NULL;
    }

    n *temp=(n*)malloc(sizeof(n));
    temp->data=rootData;

    if(inStart==inEnd){ 
        return temp;
    }

    int idx;
    for(idx=inStart;idx<=inEnd;idx++){
        if(in[idx]==rootData){
            break;
        }
    }

    int Llen=idx-inStart;
    temp->left = solvePost(in,post,inStart,idx-1,postStart,postStart+Llen-1);
    temp->right = solvePost(in,post,idx+1,inEnd,postStart+Llen,postEnd-1);
    return temp;
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

void main(){
    int ch;    
    printf("Options:");
    printf("\n1.inOrder+preOrder->Tree");
    printf("\n2.inOrder+postOrder->Tree");
    printf("\n3.Exit");
    printf("\nEnter Choice:");
    scanf("%d",&ch);
    
    int size;
    printf("\nEnter num of nodes:");
    scanf("%d",&size);
    
    switch(ch){
        case 1: {
                    int in[size];
                    printf("\nEnter inOrder:");
                    for(int i=0;i<size;i++){
                        scanf("%d",&in[i]);
                    }
                    int pre[size];
                    printf("\nEnter preOrder:");
                    for(int i=0;i<size;i++){
                        scanf("%d",&pre[i]);
                    }

                    n *root=solvePre(in,pre,0,size-1,0,size-1);

                    int choice;
                    printf("\n1.PreOrder.");
                    printf("\n2.InOrder.");
                    printf("\n3.PostOrder.");
                    printf("\n4.Exit.");
                    printf("\nEnter Choice:");
                    scanf("%d",&choice);
    
                    switch(choice){
                        case 1: preOrder(root);
                                    break;
                        case 2: inOrder(root);
                                    break;
                        case 3: postOrder(root);
                                    break;
                        case 4: exit(0);
                                    break;
                        default: printf("\nInvalid Choice!");
                    }
                    break;
                }
        case 2:{
                    int in[size];
                    printf("\nEnter inOrder:");
                    for(int i=0;i<size;i++){
                        scanf("%d",&in[i]);
                    }
                    int post[size];
                    printf("\nEnter postOrder:");
                    for(int i=0;i<size;i++){
                        scanf("%d",&post[i]);
                    }

                    n *root=solvePost(in,post,0,size-1,0,size-1);
                    
                    int choice;
                    printf("\n1.PreOrder.");
                    printf("\n2.InOrder.");
                    printf("\n3.PostOrder.");
                    printf("\n4.Exit.");
                    printf("\nEnter Choice:");
                    scanf("%d",&choice);
    
                    switch(choice){
                        case 1: preOrder(root);
                                    break;
                        case 2: inOrder(root);
                                    break;
                        case 3: postOrder(root);
                                    break;
                        case 4: exit(0);
                                    break;
                        default: printf("\nInvalid Choice!");
                    }
                    break;
        }
        case 3: exit(0);
                    break;
        default: printf("\nInvalid Choice!");
    }
}
