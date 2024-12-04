#include<stdio.h>
void fibonacciSeries(int n)
{
   int a=0, b=1, c;
   while (a<=n)
   {
     printf("%d ", a);
     c = a+b;
     a = b;
     b = c;
   }
}

int main()
{
   int n;

   printf("Enter range: ");
   scanf("%d", &n);

   printf("The fibonacci series is: \n");

   fibonacciSeries(n);

   return 0;
}