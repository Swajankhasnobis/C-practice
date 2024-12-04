#include<stdio.h>
#include<stdlib.h>
long int Ackerman(int m,int n)
{
   if(m==0)
   return n+1;
   else if(m>0 && n==0)
   return Ackerman(m-1,1);
   else if(m>0 && n>0)
   return Ackerman(m-1,Ackerman(m,n-1));
   else
   {
     printf("Negative number not possible\n");
     return 0;
   }
}
int main()
{
  int m,n;
  long long int a;
  printf("Enter the numbers : ");
  scanf("%d",&m);
  scanf("%d",&n);
  a=Ackerman(m,n);
  if(a==0)
  {
    printf("Invalid input\n");
    return 0;
  }
  printf("Ackerman(%d , %d) = %lld\n",m,n,a);
  return 0;
}

