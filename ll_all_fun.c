//LL of Malls containing it's name,no.of shops & revenue,connect malls and print their data.
#include<stdio.h>
#include<stdlib.h>

typedef struct Mall{
	char name[10];
	int no_of_shops;
	float revenue;
	struct Mall *next;
}m;

m *head=NULL;

m* createNode(){
	getchar();
	m *newNode=(m*)malloc(sizeof(m));
	char ch;
	int i=0;
	printf("\nEnter Name of Mall:");
	gets(newNode->name);
	printf("Enter no.of shops:");
	scanf("%d",&newNode->no_of_shops);
	printf("Enter Revenue:");
	scanf("%f",&newNode->revenue);
	getchar();
	return newNode;
}

int countNode(){
	int count;
	m *temp=head;
	while(temp!=head){
		temp=temp->next;
		count++;
	}
	return count;
}

void addFirst(){
	m *newNode=createNode();
	if(head==NULL){
		head=newNode;
	}else{
		m *temp=head;
		newNode->next=head;
		head=newNode;
	}
	printf("\nLL Added at First!\n");
}

void addLast(){
	m *newNode=createNode();
	if(head==NULL){
		head=newNode;
	}else{
		m *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
	}
	printf("\nLL Added at Last!\n");
}

void addAtPos(){
	getchar();
	int count=countNode();
	int pos;
	getchar();
	printf("\nEnter Pos to INSERT node:");
	scanf("%d",&pos);
	if(pos==1){
		addFirst();
	}else if(pos==count){
		addLast();
	}else{
		m *newNode=createNode();
		m *temp=head;
		while(pos-2){
			temp=temp->next;
			pos--;
		}
		newNode->next=temp->next;
		temp->next=newNode;
		printf("Element added at %d!\n",pos);
	}
}

void delFirst(){
	if(head==NULL){
		printf("\nLL empty!\n");
	}else{
		m *temp=head;
		head=head->next;
		free(temp);
	}
	printf("\nFirst Node Deleted!\n");
}

void delLast(){
	if(head==NULL){
		printf("LL Empty!\n");
	}else{
		m *temp=head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
	printf("\nLast Node Deleted!\n");
}

void delAtPos(){
	getchar();
	int count=countNode();
	int pos;
	printf("\nEnter Pos to DELETE node:");
	scanf("%d",&pos);
	getchar();
	if(pos==1){
		delFirst();
	}else if(pos==count){
		delLast();
	}else if(pos>=count||pos<1){
		printf("\nInvalid Choice!!!");
	}else{
		m *temp=head;
		while(pos-2){
			temp=temp->next;
			pos--;
		}
		temp->next=temp->next->next;
		free(temp->next);
		printf("Element Deleted at %d!\n",pos);
	}
}

void showll(){
	m *temp=head;
	getchar();
	while(temp!=NULL){
		printf("|Mall Name:%s|->",temp->name);
		printf("|No.of Shops:%d|->",temp->no_of_shops);
		printf("|Mall Revenue:%f|",temp->revenue);
		temp=temp->next;
		printf("\n");
	}
}

void reversell(){
	m *cur=head;
	m *prev=NULL;
	m *next=head;
	
	while(cur!=NULL){
		next=cur->next;
		cur->next=prev;
		prev=cur;
		cur=next;
	}
	head=prev;
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
			printf("\n8.Display LL");
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
						reversell();
						break;

				case 8: 
						showll();
						break;

				case 9:
						exit(0);
						break;

				default:
						printf("\nWrong Choice!");

			}
		}
}
