#include<stdio.h>
int main()
{
    int i,j,m,n,p,q,a[100][100],b[100][100];
    printf("Enter order of first matrix : ");
    scanf("%d",&m);
    scanf("%d",&n);
    printf("Enter order of second matrix : ");
    scanf("%d",&p);
    scanf("%d",&q);
    if(m!=p||n!=q)
    {
        printf("Matrix not identical");
        return 0;
    }
    printf("Enter elements of first matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter elements of second matrix\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("first matrix is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("second matrix is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for ( j=0; j < n; j++)
        {
            if(a[i][j]!=b[i][j])
            {
                printf("Matrix not identical");
                return 0;
            }
        }
        
    }
    printf("Matrices are identical");
    return 0;
}