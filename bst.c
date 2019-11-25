#include<stdio.h>
#include<stdlib.h>

typedef struct List{
    int data;
    struct List *lchild;
    struct List *rchild;
}list;

list *root=NULL;
list *temp;
list *ptr;

void insert(int item){

    list *cur;
    ptr=root;

    temp=(list*)malloc(sizeof(list));
    temp->data=item;
    temp->lchild=NULL;
    temp->rchild=NULL;

    if(root==NULL){
        root=temp;
        return;
    }
    while(ptr){
          cur=ptr;
       if(temp->data <= ptr->data){
            ptr=ptr->lchild;
        }
        else{
            ptr=ptr->rchild;
        }
    }
    if(temp->data <= cur->data){
        cur->lchild=temp;
    }
    else{
        cur->rchild=temp;
    }
}

void inorder(list *node){

    if(node->lchild)
        inorder(node->lchild);
        printf("%d  ",node->data);
     if(node->rchild)
        inorder(node->rchild);

}


void preorder(list *node){

        printf("%d  ",node->data);
    if(node->lchild)
        preorder(node->lchild);
    if(node->rchild)
        preorder(node->rchild);

}


void postorder(list *node){

     if(node->lchild)
        postorder(node->lchild);
     if(node->rchild)
        postorder(node->rchild);
        printf("%d  ",node->data);

}

void main(){

    int n,item;

    while(1){
        printf("\nenter choice:\n1.insert element\n2.display inorder\n3.display preorder\n4.display postorder\n5.exit\n\nchoice: ");
        scanf("%d",&n);
        if(n==2 || n==3 || n==4){
            if(root == NULL){
                printf("\nThe tree is null\n");
                continue;
            }
        }
        switch(n){
            case 1:printf("\nEnter element: ");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2:inorder(root);
                    break;
            case 3:preorder(root);
                    break;
            case 4:postorder(root);
                    break;
            case 5:exit(0);
            default:printf("\nINVALID INPUT\n");
        }
    }
}
