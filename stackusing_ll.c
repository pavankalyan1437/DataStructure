#include<stdio.h>
#include<stdlib.h>
struct node
{
	int e;
	struct node* next;
};
void push(struct node **head,int op1)
{
	int ele;
	printf("enter element to push:");
	scanf("%d",&ele);
	if(*head==NULL)
	{	
		*head=(struct node*)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=NULL;
	}
	else if(op1==1)
	{
		struct node *nn;
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		nn->next=*head;
		*head=nn;
	}
	else if(op1==2)
	{
		struct node *nn,*temp=*head;
		nn=(struct node *)malloc(sizeof(struct node));
		nn->e=ele;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
		nn->next=NULL;
	}
}
void pop(struct node**head,int op1)
{
	if(*head==NULL)
		printf("stack is empty\n");
	else if(op1==1)
	{
		struct node *temp=*head;
		*head=(*head)->next;
		temp->next=NULL;
		printf("%d",temp->e);
	}
	else if(op1==2)
	{
		if((*head)->next=NULL)
		{
			printf("%d",(*head)->e);
		}
		else{
			struct node *temp=*head,*temp1;
			while(temp->next!=NULL)
			{
				temp1=temp;
				temp=temp->next;
			}
			temp1->next=NULL;
			printf("%d",temp->e);
		}
	}
}
void main()
{
	struct node *head=NULL;
	int op,op1;
	printf("enter 1.push at head 2.push at tail:");
	scanf("%d",&op1);
	printf("1.push 2.pop 3.exit:");
	do{
	printf("enter option:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			push(&head,op1);
			break;
		case 2:
			pop(&head,op1);
			break;
		case 3:
			break;
		default:
			printf("invalid option");
	}}while(op!=3);
}
	







