#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}n;

void postOrder(n *root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

n* constructBT(int in[],int post[],int inStart,int inEnd,int poStart,int poEnd){
    int rootData=post[poEnd];
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
    temp->left = constructBT(in, post, inStart, idx - 1, poStart, poStart + Llen - 1);
    temp->right = constructBT(in, post, idx + 1, inEnd, poStart + Llen, poEnd - 1);
    return temp;
}

void main(){
    int size;
    printf("Enter size of Tree: ");
    scanf("%d",&size);

    int in[size];
    printf("\nEnter inOrder: ");
    for(int i=0;i<size;i++){
        scanf("%d",&in[i]);
    }

    int post[size];
    printf("\nEnter postOrder: ");
    for(int i=0;i<size;i++){
        scanf("%d",&post[i]);
    }

    n *root=constructBT(in,post,0,size-1,0,size-1);
    postOrder(root);    
}

/* ex:
    in[]={2,5,4,1,6,3,8,7};
    pre[]={1,2,4,5,3,6,7,8};
    post[]={5,4,2,6,8,7,3,1};
    levelorder[]={1,2,3,4,6,7,5,8};
    tree:                           1
                                    /   \
                                   2     3
                                    \     /\
                                     4   6 7
                                     /        \
                                    5         8   
*/