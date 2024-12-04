#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct date{
    int day;
    char month[20];
    int year;
}date;
void dateprint(int d,char m[],int y)
{
    printf("The Entered date is : ");
    printf("%d-%s-%d",d,m,y);
    return ;
}
int main()
{
    date d;
    int m;
    printf("Enter the day : ");
    scanf("%d",&d.day);
    printf("Enter the month name : ");
    scanf("%s",&d.month);
    printf("Enter the year : ");
    scanf("%d",&d.year);
    if(strcmp(d.month,"Jannuary")==0)
    m=1;
    else if(strcmp(d.month,"February")==0)
    m=2;
    else if(strcmp(d.month,"March")==0)
    m=3;
    else if(strcmp(d.month,"April")==0)
    m=4;
    else if(strcmp(d.month,"May")==0)
    m=5;
    else if(strcmp(d.month,"June")==0)
    m=6;
    else if(strcmp(d.month,"July")==0)
    m=7;
    else if(strcmp(d.month,"August")==0)
    m=8;
    else if(strcmp(d.month,"September")==0)
    m=9;
    else if(strcmp(d.month,"October")==0)
    m=10;
    else if(strcmp(d.month,"December")==0)
    m=12;
    else if(strcmp(d.month,"November")==0)
    m=11;
    else{
      printf("Invalid month name");
      return 0;
    }
    if(m>12||m<1)
    {
       printf("Invalid month");
       return 0;
    }
    if(d.day>30 &&(m==4||m==6||m==9||m==11))
     {
        printf("Invalid date");
        return 0; 
     }
     else if(d.day>31 &&(m==1||m==3||m==5||m==7||m==8||m==10||m==12))
     {
        printf("Invalid date");
        return 0; 
     }
     
     if(d.year%400==0||(d.year%4==0&&d.year%100!=0))
     {
        if(d.day>29&&m==2)
        {
        printf("Invalid date");
        return 0; 
        }
     }
     else if(d.day>28&&m==2)
     {
        printf("Invalid date");
        return 0;
     }
     
    dateprint(d.day,d.month,d.year);
    return 0;
}