#include<stdio.h>
#include<string.h>
int main()
{
    char str1[100],str2[100],str[200];
    int i,l1,l2,l,j;
    printf("Enter the first String : ");
    fgets(str1,sizeof(str1),stdin);
    printf("Enter the second String : ");
    fgets(str2,sizeof(str2),stdin);
    l1=strlen(str1);
    l2=strlen(str2);
    l=l1+l2-1;
    for(i=0;i<l1;i++)
    {
        str[i]=str1[i];
        if(i==l1-2)
        {
            for(j=0;j<l2-1;j++)
            {
                i++;
                str[i]=str2[j];
            }
            break;
        }
    }
    printf("First string is : ");
    puts(str1);
    printf("Second string is : ");
    puts(str2);
    printf("Concatenated  string is : ");
    puts(str);
    return 0;
}