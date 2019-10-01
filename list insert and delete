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

void delete_at_front()
{
	list *prt=head;
	head=head->next;
	free(prt);
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

void delete_at_rear(int count)
{
	list *prt=head,*pre=head;
	if(count==1)
	{
		head=0;
	}
	else
	{
		while(prt->next!=0)
		{
			pre=prt;
			prt=prt->next;
		}
		pre->next=0;
	}
	free(prt);
}

void insert_at_position(int item,int pos,int count)
{	
	int i;
	if(pos>count || pos<1)
	{
		printf("\n invalid position");
		return;
	}
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
			for(i=1;i<pos-1;i++)
			{
				prt=prt->next;
			}
			temp->next=prt->next;
			prt->next=temp;
		}
}

void delete_at_position(int pos,int count)
{
	int i;
	if(pos>count || pos<1)
	{
		printf("\n invalid position");
		return;
	}
	list *prt=head,*pre;
	if(pos==1)
	{
		head=head->next;
		free(prt);
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			prt=prt->next;
		}
		pre=prt->next;
		prt->next=pre->next;
		free(pre);		
	}
}

void display()
{
	temp=head;

	while(temp!=0)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}

int main()
{
	
	int item,n,pos,count=0;
	while(1)
	{
		printf("\n\nchoose an operation :");
		printf("\n1.insert at front\n2.insert at rear\n3.insert at position\n4.delete at front\n5.delete at rear\n6.delete at position\n7.display\n8.exit\n\nchoice :");
		scanf("%d",&n);
		if(n==1 || n==2 || n==3)
		{
			printf("\nenter an element :");
			scanf("%d",&item);
			count++;
		}
		if(n==4 || n==5 || n==6 || n==7)
		{
			if(head==0)
			{
				printf("\n\nlist is empty");
				continue;
			}
		}
		switch(n)
		{
			case 1: insert_at_front(item);
				break;
		
			case 2: insert_at_rear(item);
				break;

			case 3:printf("\nenter position :");
				scanf("%d",&pos);
				insert_at_position(item,pos,count);
				break;

			case 4:delete_at_front();
				break;
			
			case 5:delete_at_rear(count);
				break;

			case 6:printf("\nenter position :");
				scanf("%d",&pos);
				delete_at_position(pos,count);
				break;

			case 7: display();
				break;
			
			case 8: exit(0);
			
			default: printf("\nINVALID INPUT");
		}
	}
	return 0;
}
