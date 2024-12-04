#include<stdio.h>
int main()
{
    int p,q,m,n,i,j,k,a[100][100],b[100][100],c[100][100];
    printf("Enter order of first matrix : ");
    scanf("%d",&m);
    scanf("%d",&n);
    printf("Enter order of second matrix : ");
    scanf("%d",&p);
    scanf("%d",&q);
    if(n!=p)
    {
        printf("matrix multiplication not possible with given order");
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
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][i];
            }
        }
    }
    printf("product of two matrices is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}