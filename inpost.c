#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int priority(char e)
{
    if(e=='^')
    return 3;
    else if(e=='/'||e=='*')
    return 2;
    else if(e=='+'||e=='-')
    return 1;
    else
    return 0;
}
 void push(char s[],int *top,char e)
 {
     s[++(*top)]=e;
     //printf("%c",e);
 }
 char pop(char s[],int *top)
 {
    return s[(*top)--];
 }
 void inpost(char in[])
 {
    int l=strlen(in);
    int i=0,top=-1,j=0;
    char c;
    char *st=(char*)calloc(l,sizeof(char));
    char *post=(char*)calloc(l,sizeof(char));
    while(i<l)
    {
        if(in[i]=='(')
        {
            push(st,&top,in[i]);
            i++;
            continue;
        }
        else if(in[i]==')')
        {
            while(st[top]!='(')
            post[j++]=pop(st,&top);
            i++;
            c=pop(st,&top);
            continue;
        }
        else if((in[i]>='0'&&in[i]<='9')||in[i]==' ')
        {
         post[j++]=in[i++];
         continue;
        }
        if(top==-1)
        push(st,&top,in[i++]);
        else
        {
            if(priority(in[i])<=priority(st[top]))
            post[j++]=pop(st,&top);

            if(priority(in[i])>priority(st[top]))
            push(st,&top,in[i++]);
        }
    }
    while(top!=-1){
      post[j++]=pop(st,&top);
      post[j++]=' ';
    }
    post[j]='\0';
    printf("Postfix Expression : ");
    puts(post);
 }
    int main()
    {
        char *s;
        printf("enter infix expression : ");
        gets(s);
        inpost(s);
        return 0;
    }