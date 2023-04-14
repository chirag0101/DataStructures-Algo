#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* prev;
    struct Node* next;
    int data;
}n;

n *head=NULL;

n* createNode(){
    n *newNode=(n*)malloc(sizeof(n));
    newNode->next=NULL;
    newNode->prev=NULL;
    printf("\nEnter Data:");
    scanf("%d",&newNode->data);

    return newNode;
}

int countNode(){
	int count;
	n *temp=head;
	while(temp!=head){
		temp=temp->next;
		count++;
	}
	return count;
}

void addFirst(){
    n *newNode=createNode();
    if(head==NULL){
        head=newNode;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void addLast(){
    n *newNode=createNode();
    if(head==NULL){
        head=newNode;
    }else{
        n *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}

void addAtPos(){
    n *newNode=createNode();
    int count=countNode();
    int pos;
    printf("\nEnter Pos:");
    scanf("%d",&pos);
    if(pos==1){
        addFirst;
    }else if(pos==count){
        addLast();
    }else{
        n *temp=head;
        while(pos-2){                                                                           //highlight of the code!
            temp=temp->next;
            pos--;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
    }
}

void delFirst(){
    if(head==NULL){
        printf("\nDll Empty!;");
    }else{
        n *temp=head;
        head->next->prev=NULL;
        head=head->next;
        free(temp);
    }
}

void delLast(){
    int count=countNode();
    if(head==NULL){
        printf("\nDll Empty!");
    }else if(count==1){
        free(head);
        head=NULL;
    }else{
        n *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}

void delAtPos(){
    int pos;
    int count=countNode();
    printf("\nEnter Pos:");
    scanf("%d",&pos);
    if(pos==1){
        delFirst();
    }else if(pos==count){
        delLast();
    }else{
        n *temp=head;
        while(pos-2){
            temp=temp->next;
            pos--;
        }
        n *temp2=temp->next;
        temp->next->next->prev=temp;
        temp->next=temp->next->next;
        free(temp2);
        printDll();
    }
}

void reverseDLL(){
    n *cur=head;
    n* prev=NULL;
    n* next=head;

    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        cur->prev=next;
        prev=cur;
        cur=cur->prev;
    }
    head=prev;
}

void printDll(){
    if(head==NULL){
        printf("\nDll Empty!");
    }else{
        n *temp=head;
        while(temp!=NULL){
            printf("->|%d|<-",temp->data);
            temp=temp->next;
        }
        printf("\n" );
    }
}

void main(){
		while(1){
			int ch;
			printf("\nEnter Choice:");
			printf("\n1.Add Node At First");
			printf("\n2.Add Node At Last");
			printf("\n3.Add Node At Pos");
			printf("\n4.Delete Node At First");
			printf("\n5.Delete Node At Last");
			printf("\n6.Delete Node At Pos");
			printf("\n7.Reverse LL");            
			printf("\n8.Display DLL");
			printf("\n9.Exit\n");
			scanf("%d",&ch);

			switch(ch){
				case 1: 
						addFirst();
						break;
				case 2: 
						addLast();
						break;

				case 3: 
						addAtPos();
						break;

				case 4: 
						delFirst();
						break;

				case 5: 
						delLast();
						break;

				case 6: 
						delAtPos();
						break;

				case 7: 
						reverseDLL();
						break;

				case 8:
						printDll();
						break;
                
                case 9:
						exit(0);
						break;

				default:
						printf("\nWrong Choice!");

			}
		}
}