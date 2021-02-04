#include<stdio.h>
#include<stdlib.h>
struct node
{
	int e;
	struct node *next;//self referential structure
};
void inserthead(struct node**head)
{
	int op1;
	printf("enter element:");
	scanf("%d",&ele);
	printf("enter 1 to insert before or 2 to after head:");
	scanf("%d",&op1);
	if(*head==NULL)
	{
		*head=(struct node *)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=*head;
	}
	else
	{
		struct node *temp=*head,*nn;
		while(temp->next!=*head)
		{
			temp=temp->next;
		}
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		if(op1==1)
		{
			nn>next=*head;
			temp->next=nn;
		}
		else if(op1==2)
		{
			nn->next=(*head)->next;
			(*head)->next=nn;
		}
		
	}
}
void inserttail(struct node**head)
{
	int ele,op1;
	printf("enter element:");
	scanf("%d",&ele);
	printf("enter 1 to insert before or 2 to after head:");
	scanf("%d",&op1);
	struct node *temp=*head;
	struct node *temp1;
	if(*head==NULL)
	{
		*head=(struct node *)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=*head;
	}
	else
	{
		struct node *temp=*head,*nn;
		while(temp->next!=*head)
		{
			temp1=temp;
			temp=temp->next;
		}
		nn=(struct node*)malloc(sizeof(struct node));
		nn->e=ele;
		if(op1==1)
		{
			nn>next=temp;
			temp1->next=nn;
		}
		else if(op1==2)
		{
			temp->next=nn;
			nn->next=*head;
		}
	}
}
void insertpos(struct node**head)
{
	int pos,ele;
	printf("enter position and element to insert(position starts from 1):");
	scanf("%d%d",&pos,&ele);
	struct node *temp=*head;
	struct node *temp1;
	int c=1;
	while(c<pos)
	{
		if(temp->next!=*head && temp!=NULL)
		{
			temp1=temp;
			temp=temp->next;
			c++;
		}
		else
		{
			printf("position not found\n");
			break;
		}
	}
	if(c==pos)
	{
		if(pos!=1)
		{
			
			struct node *nn;
			nn=(struct node *)malloc(sizeof(struct node));
			nn->e=ele;
			nn->next=temp;
			temp1->next=nn;
		}
		else
		{
			struct node *nn;
			nn=(struct node*)malloc(sizeof(struct node));
			nn->e=ele;
			nn->next=(*head)->next;
			(*head)->next=nn;	
		}
	}
}
void insertmid(struct node**head)
{
	int ele;
	printf("enter element to insert at mid:");
	scanf("%d",&ele);
	struct node *temp=*head;
	struct node *temp1=*head;
	int c=1,pos=1,mid;
	if(*head==NULL)
	{
		*head=(struct node *)malloc(sizeof(struct node));
		(*head)->e=ele;
		(*head)->next=*head;
	}
	else
	{
	while(temp1->next!=*head)
	{
		temp1=temp1->next;
		pos++;
	}
	mid=pos/2;
	while(c<mid)
	{
		temp=temp->next;
		c++;
	}
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->e=ele;
	nn->next=temp->next;
	temp->next=nn;
	}	
}
void remelement(struct node**head)
{
	struct node *temp1=*head;
	struct node *temp=*head;
	int f=0,ele;
	printf("enter element to delete:");
	scanf("%d",&ele);
	while(temp->next!=*head)
	{
		if(temp->e==ele)
		{
			f=1;
			break;
		}
		temp=temp->next;
	}
	if(f==1)
	{
		if((*head)->e==ele)
			*head=(*head)->next;
		else
		{
		while(temp1->next!=temp)
		{
			temp1=temp1->next;
		}
		temp1->next=temp->next;
		temp->next=NULL;
		}
	}
	else
		printf("element not found\n");
}
void rempos(struct node**head)
{

	struct node *temp1=*head;
	struct node *temp=*head;
	int c=1,pos;
	printf("enter position of ele to delete(position starts from 1):");
	scanf("%d",&pos);
	while(c<pos)
	{
		if(temp->next!=*head)
		{
			temp=temp->next;
			c++;
		}
		else
		{
			printf("position not found\n");
			break;
		}
	}
	if(c==pos)
	{
		if(*head==NULL)
			printf("linked list is empty\n");
		else if(*head==temp)
			*head=(*head)->next;
		else
		{
		while(temp1->next!=temp)
		{
			temp1=temp1->next;
		}
		temp1->next=temp->next;
		}
	}
}
void findele(struct node *head)
{
	int ele,c=0;
	printf("enter element to search:");
	scanf("%d",&ele);
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->e==ele)
		{
			printf("element present\n");
			c++;
			break;
		}
		else
			temp=temp->next;
	}
	if(c==0)
		printf("element not found\n");
}	
void print(struct node *head)
{
	struct node *temp=head;
	while(temp->next!=*head)
	{
		printf("%d ",temp->e);
		temp=temp->next;
	}
	if(temp->next==*head)
		printf("%d",temp->e);
}	

void main()
{
	struct node *head=NULL;
	int op;
	printf("opttions\n1.insert at start\n2.insert at end\n3.insert at middle\n4.instert at position\n5.remove an elemnt\n6.remove at position\n7.find an element\n8.print\n9.stop\n");
	do{
	printf("enter op:");
	scanf("%d",&op);
	switch(op)
	{
	case 1:
		inserthead(&head);
		break;
	case 2:
		inserttail(&head);
		break;
	case 3:
		insertmid(&head);
		break;
	case 4:
		insertpos(&head);
		break;
	case 5:
		remelement(&head);
		break;
	case 6:
		rempos(&head);
		break;
	case 7:
		findele(head);
		break;
	case 8:
		print(head);
	case 9:
		break;
	default:
		printf("please choose correct option\n");
	}
	}while(op!=9);
}
