#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
}list;

list *head=NULL;
list *temp;

void push(int item)
{
	temp=(list *)malloc(sizeof(list));
	temp->data=item;
	temp->next=head;
	head=temp;
}

void pop()
{
	temp=head;
	head=head->next;
	free(temp);
}

int top()
{
	return head->data;
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
		printf("\nenter choice:\n1.push\n2.pop\n3.top\n4.display\n5.exit\n\nchoice: ");
		scanf("%d",&n);

		if(n>1 && n<5)
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
				push(item);
				break;

			case 2: pop();
				break;
	
			case 3: printf("top: %d",top());
				break;
	
			case 4: display();
				break;
		
			case 5: exit(0);

			default: printf("\nINVLAID INPUT");
		}
	}

}
