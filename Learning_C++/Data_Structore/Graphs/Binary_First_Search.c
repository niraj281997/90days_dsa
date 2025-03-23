#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int n;
    struct Node * left, *right;
    
}node;
node* f_create(int n)
{
    node* temp = (node*)calloc(1,sizeof(node));
    temp->n=n;
    temp->left=temp->right=NULL;
    return temp;
}
node* f_add(node **head,int data)
{
    if(*head==NULL)
    {
        *head= f_create(data);
        return *head;
    }
    else if((*head)->n> data)
    {
        (*head)->left=f_add(&((*head)->left),data);
    }
    else 
    {
        (*head)->right=f_add(&((*head)->right),data);
    }
    return *head;
}
void f_search(node **head,int data)
{
    if(*head==NULL)
    {
        printf("Element is not present\n");
    }
    else if((*head)->n> data)
    {
        f_add(&((*head)->left),data);
    }
    else if ((*head)->n<data)
    {
        f_add(&((*head)->right),data);
    }
    else 
    {
        printf("Present element : %d\n",(*head)->n);
    }
}
void f_print(node *head)
{
    if(head==NULL)
    return ;
    else 
    {
        printf("%d",head->n);
        f_print(head->left);
        f_print(head->right);
    }
}
int main()
{
node *head =NULL;
int n;
while(1)
{
    printf("1. Add 2. Print\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1 :
            printf("Enter the data : ");
            scanf("%d",&n);
            f_add(&head,n);break;
        case 2 :
            f_print(head);break;
        case 3: 
            printf("Enter the data : ");
            scanf("%d",&n);
            f_search(&head,n);
        default:
            exit(0);
    }
}
return 0;
}