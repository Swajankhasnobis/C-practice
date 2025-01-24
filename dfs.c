#include<stdio.h>
#define MAX 10
void dfs(int [][MAX], int );
int top;
void push(int S[], int item)
{
	S[++top]=item;
}
int pop(int S[])
{
	return S[top--];
}
int main()
{
	int a[MAX][MAX];
	int i, j, n;
	printf("Enter number of vertex : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter value for vertex %c : ",i+65);
		for(j=0;j<n;j++)
		 scanf("%d",&a[i][j]);
	}
	dfs(a,n);
}
void dfs(int a[MAX][MAX], int n)
{
	top=-1;//initialize
	int visit[n];
	int S[n];
	int i,t,count=1,j;
	for(i=0;i<n;i++)
	 visit[i]=1;
    int ch;
	printf("Enter the vertex number from which to start dfs : ");
    scanf("%d",&ch);
    if(ch>n)
    {
        printf("out of range vertex...");
        return;
    }
	visit[ch]=2;
	push(S,ch);//insert element into Q
	t=pop(S);
	printf("Element %c",t+65);
	while(count<n)
	{
		for(j=0;j<n;j++)
		{
			if(a[t][j]==1 && visit[j]==1)
			{
				push(S,j);
				visit[j]=2;
			}
		}
		t=pop(S);
		printf(" %c",t+65);
		count++;
	}
}