#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

int q[MAX];
int rear = -1;
int front = -1;


void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    do{

    printf("\n\t\t MENU\t\t\n");
    printf(" 1)enqueue 2)dequeue 3)display 4)exit:");
    printf("\n Enter your choice:");
    scanf("%d",&choice);
        
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("Enter a valid choice");
        }
    } while(choice!=4);
    return 0;
}

void enqueue()
{
    int num;
    if(rear==MAX-1)
    {
        printf("Queue overflow");
    }
    else if((front==-1) && (rear==-1))
    {
        front=0;
        rear=0;
        printf("Enter a element:");
        scanf("%d",&num);
        q[rear]=num;
        rear++;
    }
    else
    {

        printf("Enter a element:");
        scanf("%d",&num);
        q[rear]=num;
        rear++;
    }


}

void dequeue()
{
    int num1;
    if((front==-1)||(front>rear))
    {
        printf("Underflow\n");
    }
    else
    {
        num1=q[front];
        front++;
    }
}

void display()
{
    if((front==-1 )&& (rear==-1))
    {
        printf("Queue is empty!!!\n");
    }
    else
    {
        for(int i=front; i<rear; i++)
        {
            printf("%d\t",q[i]);
        }
    }
}