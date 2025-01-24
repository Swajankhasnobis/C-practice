#include<stdio.h>
#include<stdlib.h>
#define inf -9999
int hashfun(int item,int size)
{
    return item%size;
}
void display(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(a[i]==inf)
            printf(".....\n");
        else
            printf("%d\n",a[i]);
    }
}
void initialize(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        a[i]=inf;
    }
}
void collision(int a[],int e,int pos,int size)
{
    int i=(pos+1)%size;
    while(i!=pos)
    {
        if(a[i]==inf)
        {
            a[i]=e;
            return;
        }
        else
            i=(i+1)%size;
     }
}
void insert(int a[],int size,int *count)
{
    if(*count==size)
    {
        printf("Overflow\n");
        return;
    }
    int e;
    printf("Enter the element to be inserted : ");
    scanf("%d",&e);
    int pos=hashfun(e,size);
    if(a[pos]==inf)
        a[pos]=e;
    else
        collision(a,e,pos,size);
        *count=*count+1;
}
int search(int a[],int size,int e)
{
    int pos=hashfun(e,size);
    int i;
    if(a[pos]==e)
        return pos;
    else    
        i=(pos+1)%size;
        while(i!=pos)
        {
            if(a[i]==e)
            return i;
            else
            i=(i+1)%size;
        }
    return size;
}
int main()
{
    int size,count=0,e;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int *a=calloc(size,sizeof(int));
    initialize(a,size);
    int ch;
    while(1)
    {
        printf("1. insert  2.display  3.search  4.exit\n");
        printf("Enter your choice nigga : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insert(a,size,&count);
            break;
            case 2:
            display(a,size);
            break;
            case 3:
            printf("Enter the element to be searched : ");
            scanf("%d",&e);
            e=search(a,size,e);
            if(e==size)
                printf("Element not found\n");
            else
                printf("Element found at index : %d\n",e);
            break;
            case 4:
            exit(1);
        }
    }
}