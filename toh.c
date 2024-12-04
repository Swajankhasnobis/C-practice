#include<stdio.h>
#include<stdlib.h>
void toh(int n,char source,char destination,char auxiliary)
{
    if(n==1)
    {
        printf("%c -> %c\n",source,destination);
    }
    else
    {
        toh(n-1,source,auxiliary,destination);
        printf("%c -> %c\n",source,destination);
        toh(n-1,auxiliary,destination,source);
    }
}
int main()
{
    int n;
    printf("Enter the number of discs : ");
    scanf("%d",&n);
    printf("Solution of this tower can be achieved through the steps : \n");
    toh(n,'S','D','A');
    return 0;
}