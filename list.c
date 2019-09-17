#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
}list;

list *temp;
list *head=0;

void insert_at_front(int item)
{
	
	temp=(list*)malloc(sizeof(list));
	temp->data=item;
	temp->next=head;
	head=temp;
	
}

void insert_at_rear(int item)
{
	list *prt;
	prt=head;
	temp=(list*)malloc(sizeof(list));
	temp->data=item;
	if(head==0)
	{
		temp->next=head;
		head=temp;
	}
	else
	{	
		while(prt->next!=0)
		{
			prt=prt->next;
		}
		prt->next=temp;
	}
}

void insert_at_between(int item,int pos,int count)
{	
	int i;
	if(pos>count)
	{
		printf("\n invalid input");
		return;
	}
	else
	{
		list *prt;
		prt=head;
		temp=(list*)malloc(sizeof(list));
		temp->data=item;	
		if(pos==1)
		{
			temp->next=head;
			head=temp;
		}
		else
		{
			for(i=0;i<pos-1;i++)
			{
				prt=prt->next;
			}
			temp->next=prt->next;
			prt->next=temp;
		}
	}
}

void display()
{
	temp=head;
	if(temp==0)
	{
		printf("\nlist is empty");
		return;
	}
	else
	{
		while(temp!=0)
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}
	}
}

int main()
{
	
	int item,n,pos,count=0;
	while(1)
	{
		printf("\n\nchoose an operation :");
		printf("\n1.insert at front\n2.insert at rear\n3.insert at between\n4.display\n5.exit\n\nchoice :");
		scanf("%d",&n);
		if(n==1 || n==2 || n==3)
		{
			printf("\nenter an element :");
			scanf("%d",&item);
			count++;
		}
		switch(n)
		{
			case 1: insert_at_front(item);
				break;
		
			case 2: insert_at_rear(item);
				break;

			case 3:printf("\n\nenter position :");
				scanf("%d",&pos);
				insert_at_between(item,pos,count);
				break;

			case 4: display();
				break;
			
			case 5: exit(0);
			
			default: printf("\nINVALID INPUT");
		}
	}
	return 0;
}
