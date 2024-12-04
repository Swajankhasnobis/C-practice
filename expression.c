#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char c;
    struct node* left;
    struct node* right;
}node;
void push(char s[],int *top,char k)
{
    s[++(*top)]=k;
}
char pop(char s[],int *top)
{
    return s[(*top)--];
}
int priority(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/'||c=='*'||c=='%')
    return 2;
    else if(c=='+'||c=='-')
    return 1;
    else 
    return 0;
}
char* postfix(char s[])
{
    int i=0,top=-1,l=strlen(s),k=0;
    char *stk=(char*)malloc(sizeof(char)*l);
    char *postfix=(char*)malloc(sizeof(char)*l);
    for(i=0;i<l;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        postfix[k++]=s[i];
        else 
        {
            if(priority(s[i])>priority(stk[top]))
		 	push(stk,&top,s[i]);
		 	else
		 	{
		 		while(priority(s[i])<=priority(stk[top]))
		 		  postfix[k++]=pop(stk,&top);
		 		push(stk,&top,s[i]);
            }
        }
    }
    while(top!=-1)
    postfix[k++]=pop(stk,&top);
    postfix[k]='\0';
    return postfix;
}
node* create(char c)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->c=c;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void spush(node **s,node *k,int *top)
{
    s[++(*top)]=k;
}
node* spop(node** s,int *top)
{
    return s[(*top)--];
}
node* etree(char* s)
{
    int i,l=strlen(s),top=-1;
    node *temp1,*temp2,*temp3;
    node **stack=malloc(sizeof(node*)*strlen(s));
    for(i=0;i<l;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            temp1=create(s[i]);
            spush(stack,temp1,&top);
        }
        else
        {
            temp1=spop(stack,&top);
            temp2=spop(stack,&top);
            temp3=(node*)malloc(sizeof(node));
            temp3->c=s[i];
            temp3->left=temp2;
            temp3->right=temp1;
            spush(stack,temp3,&top);
        }
    }
    temp1=spop(stack,&top);
    return temp1;
}
void inorder(node* root)
{
    if(root==NULL)
    return;
    else
    {
        inorder(root->left);
        printf("%c ",root->c);
        inorder(root->right);
    }
}
int main()
{
    char *s;
    printf("Enter the Expression : ");
    scanf("%s",s);
    char *p=postfix(s);
    node *root=etree(p);
    printf("\nInorder : ");
    inorder(root);
    return 0;
}