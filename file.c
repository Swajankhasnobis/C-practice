#include<stdio.h>
int main()
{
    FILE *fp;
    int i,n;
    int a[100];
    fp=fopen("number.txt","w");
    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }
    printf("Enter the number of elements in file : ");
    scanf("%d",&n);
    printf("Enter the elements to be printed on the file :\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }
    printf("Elements printed on file");
    fclose(fp);
    return 0;
}




