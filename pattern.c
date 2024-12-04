#include<stdio.h>
int main()
{
    int i=0,n,x=0;
    printf("Enter n :");
    scanf("%d",&n);
    x=-n*n;
    for(i=1;i<3*n+1;i++)
    {
        printf("%d ",x);
        x=x+(2*i)-1;
    }
}