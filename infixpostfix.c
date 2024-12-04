#include<stdio.h>
#include<stdlib.h>
int top;
int priority(char ch)
{
	if(ch=='^')
	 return 4;
	else if(ch=='*' || ch=='/' || ch=='%')
	 return 3;
	else if(ch=='+' || ch=='-')
	 return 2;
	else
	 return 1;
}
void push(char stk[],char ch)
{
	stk[++top]=ch;
}
char pop(char stk[])
{
	return stk[top--];
}
int main()
{
	char infix[100], stack[100], post[100];
	top=-1;//initialize
	int i,ind=0;
	printf("Enter the expression ");
	scanf("%s",infix);
	
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]=='(')
		 push(stack,infix[i]);
		
		else if(infix[i]>='A' && infix[i]<='Z')
		 post[ind++]=infix[i];
		 
		 else if(infix[i]==')')
		 {
		 	while(stack[top]!='(')
		 	{
		 		post[ind++]=pop(stack);
			}
			top--; // remove ( from stack
			
		 }
		 else// when operator is encountered
		 {
		 	if(priority(infix[i])>priority(stack[top]))
		 	 push(stack,infix[i]);
		 	else
		 	{
		 		while(priority(infix[i])<=priority(stack[top]))
		 		 post[ind++]=pop(stack);
		 		 
		 		push(stack,infix[i]);
			 }
		 }
		 stack[++top]='\0';
		 post[ind]='\0';
		 printf("\n%c\t%s\t%s",infix[i], stack, post);
		 top--;
	}
	
}