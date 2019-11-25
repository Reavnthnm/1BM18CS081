#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int data;
    struct List *prev;
    struct List *next;
}list;

list *head=NULL;
list *tail=NULL;
list *temp;

void createnode(int item)
{
    temp=(list *)malloc(sizeof(list));
    temp->data=item;
    temp->prev=NULL;
    temp->next=NULL;
}

void insert_at_front(int item)
{
    createnode(item);
    if(head==NULL)
    {
        tail=temp;
        head=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}

void insert_at_end(int item)
{
    createnode(item);
    if(head==NULL)
    {
        tail=temp;
        head=temp;
        return;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insert_at_position(int item,int pos)
{
    list *ptr=head;
    list *pre;
    createnode(item);
    if(pos==1)
    {
        head->prev=temp;
        temp->next=head;
        head=temp;
        return;
    }

    for(int i=1;i<pos;i++)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    temp->next=ptr;
    temp->prev=pre;
    pre->next=temp;
    ptr->prev=temp;
}

void delete_at_front()
{
    if(head==NULL)
    {
        printf("\nlist is empty\n");
        return;
    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("\nlist is empty\n");
        return;
    }
    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}

void display_from_front()
{
    if(head==NULL)
    {
        printf("\nlist is empty\n");
        return;
    }
    temp=head;
    printf("\nlist: ");
    while(temp!=tail)
    {
        printf("\n\t%d",temp->data);
        temp=temp->next;
    }
    printf("\n\t%d",temp->data);
}

void display_from_end()
{
    if(head==NULL)
    {
        printf("\nlist is empty\n");
        return;
    }
    temp=tail;
    printf("\nlist: ");
    while(temp!=head)
    {
        printf("\n\t%d",temp->data);
        temp=temp->prev;
    }
    printf("\n\t%d",temp->data);
}

void main()
{
    int n,item,pos;

    while(1)
    {
        printf("\nenter choice:\n1.insert at front\n2.insert at end\n3.insert at position\n4.delete at front\n5.delete at end\n6.display from front\n7.display from end\n8.exit\n\nchoice:");
        scanf("%d",&n);
        if(n==1 || n==2 || n==3)
        {
            printf("\nenter element:");
            scanf("%d",&item);
        }
        switch(n)
        {
            case 1:insert_at_front(item);
                    break;

            case 2:insert_at_end(item);
                    break;

            case 3:printf("\nenter position: ");
                    scanf("%d",&pos);
                    insert_at_position(item,pos);
                    break;

            case 4:delete_at_front();
                    break;

            case 5:delete_at_end();
                    break;

            case 6:display_from_front();
                    break;

            case 7:display_from_end();
                    break;

            case 8:exit(0);

            default:printf("\nINVALID INPUT");
        }
    }
}
