#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a[100][100],b[100][100],n,i,j;
    printf("Enter order of matrix : ");
    scanf("%d",&n);
    printf("Enter matrix elements :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[j][i];
        }
    }
    printf("original matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Transposed matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
