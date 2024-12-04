#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;
node* create(int k)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=k;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;
    return temp;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int getheight(node* n)
{
    if(n==NULL)
    return 0;
    else
    return n->height;
}
int updateh(node* n)
{
    return 1 + max(getheight(n->left),getheight(n->right));
}
int getbf(node* n)
{
    if(n==NULL)
    return 0;
    return getheight(n->left)-getheight(n->right);
}
node* rrotate(node *y)
{
    node* x=y->left;
    node* t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=updateh(y);
    x->height=updateh(x);
    return x;
}
node* lrotate(node* x)
{
    node* y=x->right;
    node* t2=y->left;
    y->left=x;
    x->right=t2;
    y->height=updateh(y);
    x->height=updateh(x);
    return y;
}
node* min(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    } 
    return root;
}
node* insert(node *root,int k)
{
    int bf;
    if(root==NULL)
    return create(k);
    else if(k<root->data)
    root->left=insert(root->left,k);
    else if(k>root->data)
    root->right=insert(root->right,k);
    root->height=updateh(root);
    bf=getbf(root);
    if(bf>1&&k<root->left->data)
    return rrotate(root);
    if(bf<-1&&root->right->data<k)
    return lrotate(root);
    if(bf>1&&k>root->left->data)
    {
        root->left=lrotate(root->left);
        return rrotate(root);
    }
    if(bf<-1&&root->right->data>k)
    {
        root->right=rrotate(root->right);
        return lrotate(root);
    }
    return root;
}
node* delete(node* root,int k)
{
    node* temp;
    if(root->left==NULL&&root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(k<root->data)
    root=delete(root->left,k);
    else if(k>root->data)
    root=delete(root->right,k);
    else
    {
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
        else
        {
            temp=min(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
}
void preorder(node* root)
{
    if(root==NULL)
    return;
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
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
            printf("enter data to be inserted :");
            scanf("%d",&x);
            root=insert(root,x);
            printf("Element inserted\n");
            break;
            case 2:
            printf("enter data to be deleted :");
            scanf("%d",&x);
            root=delete(root,x);
            printf("Element Deleted\n");
            break;
            case 3:
            printf("Inorder : ");
            inorder(root);
            printf("\nPreorder : ");
            preorder(root);
            break;
            case 4:
            free(root);
            exit(1);
        }
    }
    return 0;
}