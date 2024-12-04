#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int d;
    struct node* left;
    struct node* right;
}node;
node* create(int k)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->d=k;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* insert(node* root)
{
    int x;
    printf("Enter the data you wish to insert : ");
    scanf("%d",&x);
    node* new=create(x);
    node *prev,*ptr;
    if(root==NULL)
    {
        root=new;
        return root;
    }
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            prev=ptr;
            if(ptr->d==x)
            {
                printf("Element cannot be inserted\n");
                return root;
            }
            else if(ptr->d>x)
            ptr=ptr->left;
            else
            ptr=ptr->right;
        }
        if(prev->d>x)
        prev->left=new;
        else
        prev->right=new;
        return root;
    }
}
node* min(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    } 
    return root;
}
node* delete(node* root,int k)
{
    node *temp;
    if(root==NULL)
    return NULL;
    else if(root->left==NULL&&root->right==NULL)
    {
        free(root);
        return NULL;
    }
    else
    {
        if(root->d>k)
        root->left=delete(root->left,k);
        else if(root->d<k)
        root->right=delete(root->right,k);
        else{
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        else{
            temp=min(root->right);
            root->d=temp->d;
            root->right=delete(root->right,temp->d);
        }
    
      }
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    else
    {
        inorder(root->left);
        printf("%d ",root->d);
        inorder(root->right);
    }
}
int search(node *root,int k)
{
    while(root!=NULL)
    {
        if(root->d==k)
        return 1;
        else if(root->d>k)
        root=root->left;
        else
        root=root->right;
    }
    return -1;
}

int main()
{
    node* root=NULL;
    int ch,x;
    while(1)
    {
        printf("1)Insert 2)Delete 3)Display 4)Exit  Enter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            root=insert(root);
            printf("Element inserted\n");
            break;
            case 2:
            printf("enter data to be deleted :");
            scanf("%d",&x);
            delete(root,x);
            printf("Element Deleted\n");
            break;
            case 3:
            inorder(root);
            break;
            case 4:
            exit(1);
        }
    }
    return 0;
}