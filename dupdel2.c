#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,n;
    int *p;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    p=calloc(n,sizeof(int));
    printf("Enter Elements of the array: \n");
   for(i=0;i<n;i++)
   {
      scanf("%d",p+i);
      //dup[i] = -1;
   }
   printf("original array elements are: \n");
   for(i=0;i<n;i++)
   {
      printf("%d ",*(p+i));
   }
    for(i=0;i<n;i++)
   {
      for(j = i+1; j < n; j++)
      {
         if(*(p+i) == *(p+j))
         {
            for(k = j; k <n; k++)
            {
               *(p+k) = *(p+k+1);
            }
            j--;
            n--;
         }
      }
   }
   printf("\nAfter deleting the duplicate element the Array is: \n");
   for(i=0;i<n;i++)
   {
      printf("%d ",*(p+i));
   }
}
