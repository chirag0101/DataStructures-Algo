#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}n;

void preOrder(n *root){
    if(root==NULL){
        return;
    }

    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

n* constructBT(int in[],int pre[],int inStart,int inEnd,int preStart,int preEnd){
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
    temp->left=constructBT(in,pre,inStart,idx-1,preStart+1,preStart+Llen);
    temp->right=constructBT(in,pre,idx+1,inEnd,preStart+Llen+1,preEnd);
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

    int pre[size];
    printf("\nEnter preOrder: ");
    for(int i=0;i<size;i++){
        scanf("%d",&pre[i]);
    }

    n *root=constructBT(in,pre,0,size-1,0,size-1);
    preOrder(root);    
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

//diff way:

/* #include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}n;

n* createNode(int val){
    n *newNode=(n*)malloc(sizeof(n));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int search(int *in,int start,int end,int data){
    for(int i=start;i<=end;i++){
        if(in[i]==data){
            return i;
        }
    }
}

n* constructTree(int *in,int *pre,int start,int end){
    //in:2,5,4,1,6,3,8,7 pre:1,2,4,5,3,6,7,8 st:0 ed:7
    //st:0 ed:2
    //st:0 ed:-1
    static int tempRoot=0;
    if(start>end){
        return NULL;
    }
    //0!>7
    //0!>2

    n* treenode=createNode(pre[tempRoot++]);

    if(start==end){
        return treenode;
    }
    //0!=7
    //0!=2

    int indexOfroot=search(in,start,end,treenode->data);
    //in:2,5,4,1,6,3,8,7 st:0 end:7 dta:1=3
    ///st:0 end:2 dta: 2=0

    treenode->left=constructTree(in,pre,start,indexOfroot-1);
    treenode->right=constructTree(in,pre,indexOfroot+1,end);
    

    return treenode;
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
    
    n *root=constructTree(in,pre,0,size-1);
    printf("preOrder: ");
    preOrder(root);

}*/
