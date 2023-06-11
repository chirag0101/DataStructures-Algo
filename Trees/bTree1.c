
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}n;

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

int max(int num1,int num2){
    if(num1>num2){
        return num1;
    }else if(num2>num1){
        return num2;
    }else{
        return num1;
    }
}

int height;

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

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct Node{
//     int data;
//     struct Node *left;
//     struct Node *right;
// }n; 

// n *head=NULL;

// n* createNode(){
//     n *newNode=(n*)malloc(sizeof(n));
//     printf("Enter Data:");
//     scanf("%d",&newNode->data);
//     newNode->left=NULL;
//     newNode->right=NULL;
//     return newNode;
// }

// void addRight(){
//     n *newNode=createNode();
//     if(head->right==NULL){        
//         head->right=newNode;
//     }else{
//         n *temp=head;
//         while(temp->right!=NULL){
//             temp=temp->right;
//         }
//         temp->right=newNode;
//     }
// }

// void addLeftOfRight(){
//     n *newNode=createNode();
//     n *temp=head;
//     while(temp->left!=NULL){
//         temp=temp->right;
//     }
//     temp->left=newNode;
// }

// void addLeft(){
//     n *newNode=createNode();
//     if(head->left==NULL){        
//         head->left=newNode;
//     }else{
//         n *temp=head;
//         while(temp->left!=NULL){
//             temp=temp->left;
//         }
//         temp->left=newNode;
//     }
// }

// void inOrder(n* root){
//     if(root==NULL){
//         return;
//     }else{
//         inOrder(root->left);
//         printf(" %d ",root->data);
//         inOrder(root->right);
//     }
// }

// void preOrder(n* root){
//     if(root==NULL){
//         return;
//     }else{
//         printf(" %d ",root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }

// void postOrder(n* root){
//     if(root==NULL){
//         return;
//     }else{
//         postOrder(root->left);
//         postOrder(root->right);
//         printf(" %d ",root->data);
//     }
// }

// void main(){
//             n *root=createNode();
//             head=root;
//             while(1){
//                 int ch;
//                 printf("\nEnter Choice:");
//                 printf("\n1.Add Child Node of root node At Right");
//                 printf("\n2.Add Child Node of root node At Left");
//                 printf("\n3.Exit\n");
//                 scanf("%d",&ch);

//                     if(ch==1){
//                             addRight();
//                     }
//                     else if(ch==2){
//                             addLeft();
//                     }else if(ch==3){
//                             break;
//                     }else{
//                         printf("\nWrong Choice!");
//                     }
//                 }
//     while(1){
//                 int ch;
//                 printf("\nEnter Choice:");
//                 printf("\n1.Add RL");
//                 printf("\n2.Add Right");
//                 printf("\n3.Exit\n");
//                 scanf("%d",&ch);

//                 if(ch==1){
//                             addLeftOfRight();
//                 }else if(ch==2){
//                             addRight();
//                 }
//                 else if(ch==3){
//                             break;
//                 }else{
//                             printf("\nWrong Choice!");
//                 }
//                 }
//         while(1){
//                 int ch;
//                 printf("\nEnter Traversal Choice:");
//                 printf("\n1.InOrder");
//                 printf("\n2.PreOrder");
//                 printf("\n3.PostOrder");
//                 printf("\n4.Exit\n");
//                 scanf("%d",&ch);

//                 if(ch==1){
//                     printf("\n");
//                     inOrder(root);
//                 }else if(ch==2){
//                     printf("\n");
//                     preOrder(root);
//                 }
//                 else if(ch==3){
//                     printf("\n");
//                     postOrder(root);
//                 }else if(ch==4){
//                     exit(0);
//                 }else{
//                     printf("\nWrong Choice!");
//                 }
//             }
// }
