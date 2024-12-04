#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
node* create(int k)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=k;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node* buildtree()
{
    int d;
    node* root=create(0);
    printf("Enter the data(-1 for going back) : ");
    scanf("%d",&d);
    if(d==-1)
    return NULL;
    root->data=d;
    printf("Moving into Left child of %d\n",d);
    root->left=buildtree();
    printf("Moving into right child of %d\n",d);
    root->right=buildtree();
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
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
void postorder(node* root)
{
    if(root==NULL)
    return ;
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    int ch;
    node* root=NULL;
    printf("build the tree : \n");
    root=buildtree();
    printf("\nInorder : ");
    inorder(root);
    printf("\nPreorder : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
    return 0;
}
