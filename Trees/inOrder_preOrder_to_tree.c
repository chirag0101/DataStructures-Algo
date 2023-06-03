#include<stdio.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}n;

typedef struct queue{
    struct node *btNode;
    struct queue *next;
}q;

n* createNode(int val){
    n *newNode=(n*)malloc(sizeof(n));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void constructTree(int *in,int *pre,int size,int start,int end){
    if(start>end){
        return NULL;
    }


    // int root=pre[0];
    // for(int i=0;i<size;i++){
    //     if(root==in[i]){
    //         int leftarr[i-1];
    //         int rightarr[size-(i+1)];
    //         for(int j=0;j<i;j++){
    //             leftarr[j]=pre[j];
    //         }
    //         for(int k=i+1;k<size;k++){
    //             rightarr[k]=pre[k];
    //         }
    //         solve(leftarr,rightarr,);
    //     }
    // }
}

void main(){
    int size;
    printf("Enter no. of nodes: ");
    scanf("%d",&size);

    //inputting orders
    printf("\nEnter inOrder of tree: ");
    int in[size];
    int pre[size];
    for(int i=0;i<size;i++){
        scanf("%d",&in[i]);                                                                 
    }
    printf("\nEnter preOrder of tree: ");
    for(int i=0;i<size;i++){
        scanf("%d",&pre[i]);                                                              
    }    
    
    constructTree(in,pre,size,0,size-1);

}
/* in[]={2,5,4,1,6,3,8,7};
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