#include<stdio.h>
int main(){
   int a[100],i,j,k, count = 0, dup[50], n;
   printf("Enter size of the array : ");
   scanf("%d",&n);
   printf("Enter Elements of the array: \n");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
      dup[i] = -1;
   }
   printf("original array elements are: \n");
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   for(i=0;i<n;i++)
   {
      for(j = i+1; j < n; j++)
      {
         if(a[i] == a[j])
         {
            for(k = j; k <n; k++)
            {
               a[k] = a[k+1];
            }
            j--;
            n--;
         }
      }
   }
   printf("\nAfter deleting the duplicate element the Array is: \n");
   for(i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
}