#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
struct node* prev;
};

struct node* head = NULL;

void append();
void add_at_left();
void delete_at_pos();
void display();

void main()
{
    int ch;
    while(ch != 5){
        printf("\nDouble linked list operations\n");
        printf("1)create a list\n2)add at left of the node\n3)delete at position\n4)display\n ");
        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch(ch){
        case 1: append();
               break;
        case 2: add_at_left();
               break;
        case 3: delete_at_pos();
               break;
        case 4: display();
               break;
        case 5:exit(0);

        }
    }
}


void append()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of element %d: ",i);
    scanf("%d",&temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if(head == NULL){
        head = temp;
    }
    else{
        struct node* p;
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }

    }
}

void display()
{
    if(head == NULL){
        printf("The list is empty\n");
    }

    else{
    struct node* p;
    p = head;

   printf("The elements of the list are: ");
    while(p != NULL){
        printf("\t%d",p->data);
        p = p->next;
    }
    printf("\n");
    }

}


void add_at_left()
{
    int val;
    printf("Enter the data where node should be added at left: ");
    scanf("%d",&val);

    struct node* temp,*p,*r;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter the data of the new element: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    p = head;
    while(p->data != val){
        p = p->next;
    }
    r = p->prev;

    temp->next = p;
    p->prev = temp;
    r->next = temp;
    temp->prev = r;
}

void delete_at_pos()
{
    int val;
    printf("Enter the value to be deleted: ");
    scanf("%d",&val);

    struct node *temp, *p;
    p = head;
    while(p->data != val){
        p = p->next;
    }

    p->prev->next = p->next;
    p->next->prev = p->prev;
    p->next = NULL;
    p->prev = NULL;
}
