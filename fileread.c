#include<stdio.h>
int main()
{
    FILE *fp;
    int n,max;
    fp=fopen("number.txt","r");
    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }
    fscanf(fp,"%d",&n);
    max=n;
    while(getc(fp)!=EOF)
    {
       if(n>max)
       max=n;
       n=fscanf(fp,"%d",&n); 
    }
    fclose(fp);
    printf("Maximum element is :%d",max);
    return 0;
}