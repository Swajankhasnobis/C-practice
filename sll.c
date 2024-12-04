#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
int count(node* head)
{
    int count=0;
    while(head)
    count++;
    return count;
}
node* insert(node* head)
{
    int x,c;
    node *ptr,*temp;
    temp=(node*)malloc(sizeof(node));
    printf("enter the data to be inserted : ");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    printf("1)At Beginning 2)At End 3)At Random position   Enter your choice : ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        if(head==NULL)
        head=temp;
        else
        temp->next=head;
        head=temp;
        break;
        case 2:
        if(head==NULL)
        head=temp;
        else
        ptr=head;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        ptr->next=temp;
        break;
        case 3:
        printf("Enter number of nodes after which you wish to insert : ");
        scanf("%d",&x);
        if(x>count(head))
        {
            if(head==NULL)
             head=temp;
            else
            ptr=head;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=temp;
        }
        else
        {
            ptr=head;
            while(x>0)
            {
                ptr=ptr->next;
                x--;
            }
            temp->next=ptr->next;
            ptr->next=temp;
        }
        break;
        default:
        printf("wrong choice");
    }
    return head;
}
void display(node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
int main()
{
    node* head=NULL;int i;
    
    head=insert(head);
    head=insert(head);
    head=insert(head);
    head=insert(head);
    display(head);
    return 0;
    free(head);
}