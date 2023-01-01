#include<stdio.h>
#include<stdlib.h>
int front =-1 , rear=-1 , max=5;
void insert(int q[])
{
int e;
printf("Enter the element to be inserted: ");
scanf("%d",&e);
if((front==0 && rear==max-1)||(rear==front-1))
{
  printf("Queue Overflow");
}
else if((front==-1)&&(rear==-1))
{
  front=0;
  rear=0;
  q[rear]=e;
}
else if(rear==max-1 && front!=0)
{
  rear=0;
  q[rear]=e;
}
else
{
  rear++;
 q[rear]=e;
}
}

void delete(int q[])
{
int e;
if(rear==-1 && front==-1)
{
printf("Queue Underflow\n");
}
else
{
e=q[front];
printf("Element removed: %d",e);
if(front == rear)
{
front = -1;

rear = -1;
}
else
{
if(front==max-1)
front=0;
else
front++;
}
}
}

void display(int q[])
{
int i;
if(front==-1 && rear==-1)
printf("Queue is empty\n");
else
{
printf("Queue elements are: ");
if(front<rear)
{
for(i=front;i<=rear;i++)
printf("%d\t",q[i]);
}
else
{
for(i=front;i<max;i++)
printf("%d\t",q[i]);
for(i=0;i<=rear;i++)
printf("%d\t",q[i]);
}
}
}

int main()
{
int q[100],choice,e;
do
{
printf("\n\nMENU\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: insert(q);
break;
case 2: delete(q);
break;
case 3: display(q);
break;
case 4: printf("\nExiting the program!");
exit(0);
break;
default: printf("Invalid Choice!");
break;
}
} while (1);
}
