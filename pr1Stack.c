#include<stdio.h>
#include<conio.h>
int st[100];
int n=101,top=-1,x;
void push();
void pop();
void display();
int main()
{
    int choice,value;
    do
    {
     printf("\n MENU");
     printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.Exit");
     printf("\nEnter your choice: ");
     scanf("%d",&choice);
  switch(choice)
  {
   case 1:push();
          break;
    
   case 2:pop();
          break;
   
   case 3:display();
          break;
   
   case 4: break;
   
   default: printf("Enter valid choice");
    }
}
while(choice!=4);
return 0;
}
void push()
{
    if(top>n-1)
    printf("Stack Overflow");
    else
    {
        printf("Enter the value to be pushed:");
        scanf("%d",&x);
        top++;
        st[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    printf("Stack Underflow");
    else
    {
      x=st[top];
      printf("The popped element is %d",x);
      top--;
    }
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    printf("%d \t",st[i]);
}
