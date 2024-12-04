#include<stdio.h>
int gcdf(int x,int y)
{
    if(y==0)
    return x;
    else
    return gcdf(y,x%y) ;
}
int main()
{
    int n,m,gcd,lcm;
    printf("Enter the two numbers : ");
    scanf("%d",&n);
    scanf("%d",&m);
    gcd = gcdf(n,m);
    lcm = (n*m)/gcd;
    printf("GCD is : %d \n",gcd);
    printf("LCM is : %d ",lcm);
    return 0;


}