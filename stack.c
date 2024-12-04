#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void push(int *s,int n,int *top)
{ 
    int e;
    if(*top==n-1)
        printf("Overflow");
    else
    {
        printf("Enter the element to be inserted");
        scanf("%d",&e);
        s[++(*top)]=e;
    }
}
int pop(int *s,int n,int *top)
{
    int e;
    if(*top==-1)
    {
        printf("Underflow");
        return INT_MIN;
    }
    else
    {
       return s[*(top)--];
    }
}
void display(int *s,int top)
{
   for(;top>=0;top--)
        printf("%d",s[top]);
}
int main()
{
    int *p,n;
    printf("Enter the size of the stack :");
    scanf("%d",&n);
    p=(int *)maloc(n,sizeof(int));
    return 0;
}