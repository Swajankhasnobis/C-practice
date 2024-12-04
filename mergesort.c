#include<stdio.h>
void merge(int[], int , int);
void sort(int [], int, int , int);
int main()
{
	int a[100];
	int n,i;
	printf("Enter number of elements ");
	scanf("%d",&n);
    printf("\n Enter The elments:  ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	merge(a,0,n-1);
	printf("\n Numbers after sorting ");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	
}
void merge(int a[], int f, int l)
{
	int m;
	
	if(f<l)//until single element
	{
		m=(f+l)/2;
		merge(a,f,m);
		merge(a,m+1,l);
		sort(a,f,m,l);
	}
}
void sort(int a[], int f, int m, int l)
{
	int temp[100];
	int i=f,j=m+1,k=f,x;
	while(i<=m && j<=l)
	{
		if(a[i]<a[j])
		 temp[k++]=a[i++];
		else if(a[j]<a[i])
		 temp[k++]=a[j++];
		else
		{
			temp[k++]=a[i++];
			temp[k++]=a[j++];
		}
	}
	if(i>m)
	{
		for(x=j;x<=l;x++)
		 temp[k++]=a[x];
	}
	else
	{
		for(x=i;x<=m;x++)
		 temp[k++]=a[x];
	}
	for(i=f;i<=l;i++)
	 a[i]=temp[i];
}
