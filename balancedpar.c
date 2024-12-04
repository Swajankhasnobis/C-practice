#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char s[],int top,char e)
{
    s[++top]=e;
}
char pop()