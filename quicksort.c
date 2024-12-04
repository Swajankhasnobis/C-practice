#include<stdio.h>
void swap(int*p,int*q)
{
    int t=*q;
    *q=*p;
    *p=t;
}
void qsort(int a[],int f,int l)
{
    int i,j,pivot;
    if(f<l)
    {
     i=f;
     j=l;
     pivot=a[f];
    while(i<j)
    {
        while(a[i]<=pivot&&i<j)
        i++;
        
        while(a[j]>pivot)
        j--;

        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[j],&a[f]);
    qsort(a,f,j-1);
    qsort(a,j+1,l);
   }
   return;
}
int main()
{
    int a[100],n,i;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    printf("Enter the array elements : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Original array :\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    qsort(a,0,n-1);
    printf("\nSorted array :\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}