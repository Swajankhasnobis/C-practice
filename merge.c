#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i,j,m,n;
  int *p;
  int *q;
  int *x;
  printf("Enter number of elements in first array : ");
  scanf("%d",&m);
  p=calloc(m,sizeof(int));
  printf("Enter elements of first array :\n");
  for(i=0;i<m;i++)
  {
    scanf("%d",(p+i));
  }
  printf("Enter number of elements in second array : ");
  scanf("%d",&n);
  q=calloc(n,sizeof(int));
  printf("Enter elements of second array :\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",(q+i));
  }
  x=calloc((m+n),sizeof(int));
  for(i=0;i<m;i++)
  {
    *(x+i)=*(p+i);
    if(i==(m-1))
    {
      for(j=0;j<n;j++)
      {
        i++;
        *(x+i)=*(q+j);
      }
    }
   }
   printf("First array is :\n");
   for(i=0;i<m;i++)
   {
     printf("%d ",*(p+i));
   }
   printf("\n");
   printf("Second array is :\n");
   for(i=0;i<n;i++)
   {
     printf("%d ",*(q+i));
   }
   printf("\n");
   printf("Merged array is :\n");
   for(i=0;i<(n+m);i++)
   {
     printf("%d ",*(x+i));
   }
   return 0;
 }
  
  
