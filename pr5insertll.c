#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* next;
};

struct node* head = NULL;

void createlist()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int data;
    struct node* newnode;
    struct node* p;
    newnode = malloc(sizeof(struct node));
    head = newnode;
    p = head;
    printf("Enter number to be inserted : ");
    scanf("%d", &data);
    head ->info = data;

    for (int i = 1; i < n; i++)
        {
        newnode = malloc(sizeof(struct node));
        p->next = newnode;
        printf("Enter number to be inserted : ");
        scanf("%d", &data);
        newnode->info = data;
        p = p->next;
        }
        p-> next= NULL;

}
void traverse()
{
    int i=1;
    struct node* p;
    if (head== NULL)
        printf("\nList is empty\n");
    else {
        p = head;
        while (p != NULL) {
            printf("Data %d= %d\n",i,p->info);
            p = p->next;
            i++;
        }
    }
}
void insertatfront()
{
    int data;
    struct node* p;
    p = malloc(sizeof(struct node));
    printf("Enter number to be inserted : ");
    scanf("%d", &data);
    p->next = head;
    head = p;
}
void insertatend()
{
    int data;
    struct node *p, *q;
    p = malloc(sizeof(struct node));
    printf("Enter number to be inserted : ");
    scanf("%d", &data);
    p->next = NULL;
    p->info = data;
    q= head;
    while (q->next != NULL) {
        q= q->next;
    }
    q->next = p;
}
void insertatpos()
{
    int pos,data;
    struct node *p,*q,*newnode;
    printf("Enter data point before which node to be inserted:");
    scanf("%d",&pos);
    printf("Enter no to be inserted:");
    scanf("%d",&data);
    q=head;
    while(q->info!=pos)
    {
        p=q;
        q=q->next;
    }
    newnode=malloc(sizeof(struct node));
    newnode->info= data;
    p->next=newnode;
    newnode->next=q;
}

int main()
{
    int c;
    printf("1.Create\n2.Display\n3.Insert at front\n4.Insert at end\n5.Insert at any position\n6.Exit\n");
    do{
    printf("\nEnter choice:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:createlist();
                break;
        case 2:traverse();
                break;
        case 3:insertatfront();
                break;
        case 4: insertatend();
                break;
        case 5:insertatpos();
                break;
        case 6 : exit(0);
        default: printf("Invalid choice");
    }
  }while(c>0);
  return 0;
}
