#include <stdio.h>
int main()
{
    int i,j,c=1,k;
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6-i;j++)
        {
            printf("  ");
        }
        c=1;
        for(k=1;k<=i;k++)
        {
            printf("%4d",c);
            c=c*(i-k)/k;
        }
        printf("\n");
    }
    return 0;
}
