#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,e;
    int *p;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    p=calloc(n,sizeof(int));
    printf("Enter the array elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&e);
    for(i=0;i<n;i++)
    {
      if(*(p+i)==e)
      {
        printf("Element present at position : %d",(i+1));
        return 0;
      }
    }
    printf("Element not present");
    return 0;
}