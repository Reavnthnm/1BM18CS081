#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
}list;

list *head=NULL;
list *temp;

void enqueue(int item)
{
	temp=(list *)malloc(sizeof(list));
	temp->data=item;
	temp->next=head;
	head=temp;
}

void dequeue()
{
	list *pre;
	temp=head;
	while(temp->next!=NULL)
	{	
		pre=temp;
		temp=temp->next;
	}
	pre->next=NULL;
	printf("\npopped : %d"temp->data);
	free(temp);
}

void display()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp=temp->next;
	}
}


void main()
{
	int n,item;
	
	while(1){
		printf("\nenter choice:\n1.enqueue\n2.dequeue\n3.display\n4.exit\n\nchoice: ");
		scanf("%d",&n);

		if(n>1 && n<4)
		{
			if(head==NULL)
			{
				printf("\nlist is empty\n");
				continue;
			}
		}

		switch(n)
		{
			case 1:printf("\nenter element: ");
				scanf("%d",&item);
				enqueue(item);
				break;

			case 2: dequeue();
				break;
	
			case 3: display();
				break;
		
			case 4: exit(0);

			default: printf("\nINVLAID INPUT");
		}
	}

}
