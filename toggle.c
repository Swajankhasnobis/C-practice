#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,j,l;
    char str[100],tgl[100];
    printf("Enter the string : ");
    fgets(str,sizeof(str),stdin);
    l=strlen(str);
    for(i=0;i<=l-2;++i)
    {
        if(str[i]>='a'&&str[i]<='z')
        tgl[i]=str[i]+'A'-'a';
        if(str[i]>='A'&&str[i]<='Z')
        tgl[i]=str[i]+'a'-'A';
        else
        continue;
    }
    tgl[i]='\0';
    printf("New String in toggle case : ");
    puts(tgl);
    return 0;
}