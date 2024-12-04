#include<stdio.h>
#include<string.h>
struct subjectcode
{
    char code[20];
};
typedef struct student
{
  int roll;
  char coursename[50];
  int m[3];
  struct subjectcode sub[3];
  float avg;
}std;
int main()
{
    std s[3];
    int i,j;
    for(i=0;i<3;i++)
    {
        printf("Enter details of student %d\n",i+1);
        printf("Enter the roll number : ");
        scanf("%d",&s[i].roll);
        printf("Enter course name : ");
        fgets(s[i].coursename,sizeof(s[i].coursename),stdin);
        printf("Enter the subject codes and their marks respectively :\n");
        for(j=0;j<3;j++)
        {
            printf("Enter code of subject %d",j+1);
            scanf("%s",s[i].sub[j]);
            scanf("%d",&s[i].m[j]);
        }
        s[i].avg=(s[i].m[0]+s[i].m[1]+s[i].m[2])/3.0;
    }
    printf("\nStudent details :\n");
    
    for(i=0;i<3;i++)
    {
        printf("Details of student %d\n",i+1);
        printf("roll number : %d\n",&s[i].roll);
        printf("course name : ");
        puts(s[i].coursename);
        printf("The Subject codes and their marks respectively :\n");
        for(j=0;j<3;j++)
        {
            printf("For subject %d",j+1);
            printf("%s\t",s[i].sub[j]);
            printf("%d\n",&s[i].m[j]);
        }
        printf("Average marks : %.2f",s[i].avg);
    }
    return 0;
}