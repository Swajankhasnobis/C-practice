#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    long long num;
    printf("enter the number : ");
    scanf("%ld",num);
    long i;
    long st=(long)sqrt(num);
    for(i=0;i<=st;i++)
    {
        if(num%i==0)
        {
            printf("Composite");
            return 0;
        }
    }
    printf("Prime");
    return 0;

}