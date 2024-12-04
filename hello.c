#include <stdio.h>
void fX(){
 char a;
 if((a=getchar()) != '\n')
 fX();
 if(a != '\n')
 putchar(a);}

int main(){
 fX();
 return 0;}
 