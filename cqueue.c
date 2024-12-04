#include<stdio.h>
void enqueue(int q[],int *front,int *rear,int n)
{
    int e;
    if(*front==(*rear+1)%n)
    {
        printf("OVERFLOW\n");
        return;
    }
    else
    {
       printf("Enter the element : ");
       scanf("%d",&e);
       if(*rear==n-1)
         *rear=0;
       else if(*front==-1){
        *rear =0;
        *front=0;
       }
       else
         *rear++;
     q[*rear]=e;
    }
}
void deqeue(int q[],int *front,int *rear,int n)
{
    int temp;
    if(*front == -1)
      printf("UNDERFLOW");
    else
    {
       if(*front == *rear)
       {
         temp =q[front];
         front=rear=-1;
       }
       else if(front=n-1)

    }
}