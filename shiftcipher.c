#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *str=NULL;
    char *res=NULL;
    int i;
    printf("Enter string sequence : ");
    scanf("%s",str);
    char alph[26];
    int freq[26];
    for(i=0;i<26;i++)
    {
        alph[i]=alph[65+i];
        freq[i]=0;
    }
    int l=strlen(str);
    res=(char *)calloc(sizeof(char),l);
    for(i=0;i<l;i++)
    {
        if(str[i]>='A'&&str[i]<='Z')
        freq[alph[i]-65]+=1;
    }
    int mx=0;
    for(i=0;i<l;i++)
    {
        if(freq[i]>freq[mx])
        mx=i;
    }
    int key=alph[mx]-'E';
    for(i=0;i<l;i++)
    {
        res[i]=(char)((int)str[i]-key)%26;
    }
    res[l]='/0';
    printf("%s",alph);
    //printf("%s",res);
    return 0;
}