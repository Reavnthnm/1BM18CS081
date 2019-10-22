#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
}list;

list *head1=NULL;
list *head2=NULL;

list *temp;

void insert1(int item)
{
	temp=(list *)malloc(sizeof(list));
	temp->data=item;
	temp->next=head1;
	head1=temp;
	printf("\nItem inserted successfully\n");
}

void insert2(int item)
{
	temp=(list *)malloc(sizeof(list));
	temp->data=item;
	temp->next=head2;
	head2=temp;
	printf("\nItem inserted successfully\n");
}

void delete1()
{
	list *ptr;
	temp=head1;
	while(temp->next!=NULL)
	{
		ptr=temp;
		temp=temp->next;
	}
	ptr->next=NULL;
	printf("\n%d is removed from the list\n",temp->data);
	free(temp);
}

void delete2()
{
	list *ptr;
	temp=head2;
	while(temp->next!=NULL)
	{
		ptr=temp;
		temp=temp->next;
	}
	ptr->next=NULL;
	printf("\n%d is removed from the list\n",temp->data);
	free(temp);
}

void display1()
{
	temp=head1;
	printf("\nList 1: ");
	while(temp!=NULL)
	{
		printf("\n\t%d",temp->data);
		temp=temp->next;
	}
}

void display2()
{
	temp=head2;
	printf("\nList 2: ");
	while(temp!=NULL)
	{
		printf("\n\t%d",temp->data);
		temp=temp->next;
	}
}

void reverse1(int count)
{
	list *ptr;
	list *pre;
	int i;
	temp=head1;

	if(count==1)
	{
		printf("\nList1 is reversed\n");
		return;
	}

	for(i=1;i<count;i++)
	{
		pre=temp;
		ptr=temp;
		while(ptr->next!=NULL)
		{
			pre=ptr;
			ptr=ptr->next;
		}
		if(i==1)
		{
			head1=ptr;
		}
		ptr->next=pre;
		pre->next=NULL;
	}
	printf("\nList1 is reversed\n");
}

void reverse2(int count)
{
	list *ptr;
	list *pre;
	int i;
	temp=head2;

	if(count==1)
	{
		printf("\nList2 is reversed\n");
		return;
	}

	for(i=1;i<count;i++)
	{
		pre=temp;
		ptr=temp;
		while(ptr->next!=NULL)
		{
			pre=ptr;
			ptr=ptr->next;
		}
		if(i==1)
		{
			head2=ptr;
		}
		ptr->next=pre;
		pre->next=NULL;
	}
	printf("\nList2 is reversed\n");
}

void sort1(int count)
{
	list *p;
	list *p1=head1;
	list *p2=head1;
	int t;

	if(count==1)
	{
		printf("\nList1 is sorted\n");
		return;
	}

	while(p->next!=NULL)
	{
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->data > p2->data)
			{
				t=p1->data;
				p1->data=p2->data;
				p2->data=t;
			}
			p2=p2->next;
		}
		p1=p1->next;
		p=p1;
	}
	printf("\nList1 is sorted\n");
}

void sort2(int count)
{
	list *p;
	list *p1=head2;
	list *p2=head2;
	int t;

	if(count==1)
	{
		printf("\nList2 is sorted\n");
		return;
	}

	while(p->next!=NULL)
	{
		p2=p1->next;
		while(p2!=NULL)
		{
			if(p1->data > p2->data)
			{
				t=p1->data;
				p1->data=p2->data;
				p2->data=t;
			}
			p2=p2->next;
		}
		p1=p1->next;
		p=p1;
	}
	printf("\nList2 is sorted\n");
}

void concate1()
{
	temp=head1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
}

void concate2()
{
	temp=head2;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head1;
}

void main()
{
	int n1,n2,c1=0,c2=0,item;

	while(1)
	{
		printf("\nEnter choice:\n1.insert\n2.delete\n3.sort\n4.reverse\n5.concatinate\n6.display\n7.exit\n\nchoice : ");
		scanf("%d",&n1);
		if(n1==5)
		{
			if(head1==NULL && head2==NULL)
			{
				printf("\nLists are empty\n");
				break;
			}
			printf("\n1.first to second\n2.second to first\nchoice : ");
			scanf("%d",&n2);
			if(n2==1)
			{
				concate2();
			}
			else
			{
				concate1();
			}
			break;
		}
		else if(n1==7)
		{
			exit(0);
		}
		if(n1>0 && n1<5 || n1==6)
		{
			printf("\n1.first list\n2.second list\nchoice :") ;
			scanf("%d",&n2);
			if(n1!=1)
			{
				if(n2==1)
				{
					if(head1==NULL)
					{
						printf("\nList is empty\n");
						break;
					}
				}
				else
				{
					if(head2==NULL)
					{
						printf("\nList is empty\n");
						break;
					}
				}
			}
		}
		switch(n2)
		{
			case 1:switch(n1)
				{
					case 1: c1++;
						printf("\nEnter item :");
						scanf("%d",&item);
						insert1(item);
						break;
					case 2: delete1();
						break;
					case 3: sort1(c1);
						break;
					case 4: reverse1(c1);
						break;
					case 6: display1();
						break;
					default:printf("\nINVALID INPUT\n");
				}
				break;
			case 2:switch(n1)
				{
					case 1: c1++;
						printf("\nEnter item :");
						scanf("%d",&item);
						insert2(item);
						break;
					case 2: delete2();
						break;
					case 3: sort2(c2);
						break;
					case 4: reverse2(c2);
						break;
					case 6: display2();
						break;
					default:printf("\nINVALID INPUT\n");
				}
				break;
			default:printf("\nINVALID INPUT\n");
		}
	}
getch();
}





