#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,m,n,sum=0;
    
    printf("Enter number of rows and columns : ");
    scanf("%d",&n);
    scanf("%d",&m);
    int *p[n];
    for(i=0;i<n;i++)
    {
       p[i]=calloc(m,sizeof(int));
    }
    printf("Enter the matrix elements :\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",p[i]+j);
        }
    }
    printf("Original matrix elements :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",*(p[i]+j));
        }
        printf("\n");
    }
     for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i==j)
            sum+=*(p[i]+j);
        }
    }
    printf("Sum of diagonal elements is : %d",sum);
}