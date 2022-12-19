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
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    int data;
    struct node* newnode;
    struct node* p;
    newnode = malloc(sizeof(struct node));
    head = newnode;
    p = head;
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    head ->info = data;

    for (int i = 1; i < n; i++)
        {
        newnode = malloc(sizeof(struct node));
        p->next = newnode;
        printf("\nEnter number to be inserted : ");
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

void deleteatfront()
{
    struct node *p, *q;
    q=head;
    p=head->next;
    head=p;
    free(q);
}
void deleteatend()
{
    struct node *p,*q;
    q=head;
    while(q->next!= NULL)
    {
        p=q;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}
void deleteatpos()
{
    struct node *p,*q;
    int pos;
    printf("Enter data point of the node to be deleted:");
    scanf("%d",&pos);
    q=head;
    while(q->info!=pos)
    {
        p=q;
        q=q->next;
    }
     p->next=q->next;
     free(q);
}
int main()
{
    int c;
    printf("1.Create\n2.Display\n3.Delete at front\n4.Delete at end\n5.Delete at any position\n6.Exit\n");
    do{
    printf("\nEnter choice:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:createlist();
                break;
        case 2:traverse();
                break;
        case 3: deleteatfront();
                break;
        case 4: deleteatend();
                break;
        case 5: deleteatpos();
                break;
        case 6: exit(0);
        default: printf("Invalid choice");
    }
  }while(c>0);
  return 0;
}

