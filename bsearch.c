#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,e,l=0,m,u;
    int *p;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    u=n-1;
    p=calloc(n,sizeof(int));
    printf("Enter the array elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&e);
    for(i=0;i<n-1;i++)
    {
        m=(l+u)/2;
        if(*(p+m)==e)
        {
            printf("Element present at position : %d",m+1);
            return 0;
        }
        else if(*(p+m)>e)
        u=m-1;
        else if(*(p+m)<e)
        l=m+1;
    }
    printf("Element not found");
    return 0;
}