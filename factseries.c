#include<stdio.h>
int fact(int n)
{
    if(n==1||n==0)
    return 1;
    else
    return n*fact(n-1);
}
int main()
{
    int i,n;
    float s=0.0;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       s=s+(float)1/fact(i);
    }
    printf("value of the series is : %f",s);
    return 0;
}