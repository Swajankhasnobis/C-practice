#include<stdio.h>
#define MAX 10
void bfs(int [][MAX], int );
int f, r;
void insert(int Q[], int item)
{
	if(r==-1)
	{
		r=0;
		f=0;
		Q[r]=item;
	}
	else
	{
		Q[++r]=item;
	}
}
int del(int Q[])
{
	return Q[f++];
}
int main()
{
	int a[MAX][MAX];
	int i, j, n;
	printf("Enter number of vertex : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter Adjacency array for vertex %c : ",i+65);
		for(j=0;j<n;j++)
		 scanf("%d",&a[i][j]);
	}
	bfs(a,n);
}
void bfs(int a[MAX][MAX], int n)
{
	f=-1, r=-1;//initialize
	int visit[n];
	int Q[n];
	int i,t,count=1,j;
	for(i=0;i<n;i++)
	 visit[i]=1;
	int ch;
    printf("Enter the vertex number from which to start bfs : ");
    scanf("%d",&ch);
    if(ch>n)
    {
        printf("out of range vertex...");
        return;
    }
	visit[ch]=2;
	insert(Q,ch);//insert element into Q
	t=del(Q);
	printf("Element %c",t+65);
	while(count<n)
	{
		for(j=0;j<n;j++)
		{
			if(a[t][j]==1 && visit[j]==1)
			{
				insert(Q,j);
				visit[j]=2;
			}
		}
		t=del(Q);
		printf(" %c",t+65);
		count++;
	}
}