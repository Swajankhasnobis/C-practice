#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void push(int s[],int *top,int e)
{
    *top+=1;
    s[(*top)]=e;
}   
int pop(int s[],int *top)
{
    return s[(*top)--];
}
int main()
{
    char e[50];
    printf("Enter the postfix expression : ");
    gets(e);
    int l=strlen(e);
    int *s=(int *)calloc(l,sizeof(int));
    int top=-1,i=0,j=0,a=0,b=0;
    while(i<=l-1)
    {
        if(isdigit(e[i]))
        {
            a=(int)(e[i]-'0');
            while (e[i+1]!=' ')
            {
                ++i;
                a=a*10 + (int)(e[i]-'0');
            }
            push(s,&top,a);
            ++i;
            continue;
        }
        if(e[i]==' ')
        {
            ++i;
           continue;
        }
        switch (e[i])
        {
        case '+':
           b=pop(s,&top);
           a=pop(s,&top);
           push(s,&top,a+b);
           break;
        case '-':
           b=pop(s,&top);
           a=pop(s,&top);
           push(s,&top,a-b);
           break;
        case '*':
           b=pop(s,&top);
           a=pop(s,&top);
           push(s,&top,a*b);
           break;
        case '/':
           b=pop(s,&top);
           a=pop(s,&top);
           push(s,&top,a/b);
           break;
        
        default:
            break;
        
        }
        i++;
    }
    //b=pop(s,&top);
    printf("Result : %d",s[top]);
}