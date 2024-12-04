#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int i,n,j,e,c;
    int *p;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    p=calloc(n,sizeof(int));
    printf("Enter the array elements :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }
    for(i=0;i<n-1;i++)
    { 
        //c=0;
        for(j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
               e=p[j];
               p[j]=p[j+1];
               p[j+1]=e;
               c=1;
            }
        }
        if(c==0)
        break;
    }
    printf("Sorted array in ascending order : \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(p+i));
    }
    return 0;
}
