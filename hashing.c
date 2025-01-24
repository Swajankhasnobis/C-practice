#include<stdio.h>
#define MAX 11
#define INF -9999
void available(int arr[], int pos, int num)
{
	int i=(pos+1)%MAX;
	while(i!=pos)
	{
		if(arr[i]==INF)
		{
			arr[i]=num;
			return;
		}
		i=(i+1)%MAX;
		 
	}
	
}
void initialize(int arr[])
{
     int i;
     for(i=0;i<MAX;i++)
      arr[i]=INF;
}
void show(int arr[])
{
	int i;
	for(i=0;i<MAX;i++)
	{
		if(arr[i]==INF)
		 printf("\n......");
		else
		 printf("\n %d",arr[i]);
	}
}
int main()
{
    int a[MAX];
    int i=0,num,ind;
    initialize(a);
    while(i<MAX)
    {
       printf("\n Remaining element %d\n",MAX-i);
       printf("Enter the number ");
       scanf("%d",&num);
       ind=num%MAX;
       if(a[ind]==INF)
       {
          a[ind]=num;
          printf("\n Number inserted ..");
          
       }
       else
       {
           printf("\n Collision ");
 		   available(a,ind,num);
       }
       show(a);
       i++;
    }
}