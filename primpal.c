#include<stdio.h>
int prime(int n)
{
   int i;
   for(i=2;i<n;i++)
   {
    if(n%i==0)
    return 0;
   }
   return 1;
}
int pal(int n)
{
    int r=0,x;
    x=n;
    while(x>0)
    {
        r=(r*10) + (x%10);
        x/=10;
    }
   
    if(r==n)
    return 1;
    else
    return 0;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("\n Enter the number : ");
    scanf("%d",&n);
    if(prime(n)==1&&pal(n)==1)
    printf("\nThe entered number is prime pallindrome");
    else
    printf("Entered numbr is not prime pallimdrome");
    return 0;
}
