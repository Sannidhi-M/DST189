#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;


struct node3{
    int data;
    struct node3* next;
    struct node3* prev;
};
struct node3* head3=NULL;


struct node1{
    int data;
    struct node1 *next;
};
struct node1 *head1=NULL;
struct node1 *head2=NULL;


void rever_list();
void sort();
void concatination();

void main(){
    int ch;
    do{
        printf("\n\nOperations \n");
        printf("1)Reversing the list\n2)Sorting the list\n3)Concatinating lists\n4)Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:rever_list();
                   break;
            case 2:sort();
                  break;
            case 3:concatination();
                   break;
            case 4:exit(9);
        }
    }while(ch!=5);
}

void rever_list(){
    int n;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
     struct node *temp;
     temp = (struct node*)malloc(sizeof(struct node));
     printf("Enter %d element: ",i+1);
     scanf("%d",&temp->data);
     temp->next = NULL;
     temp->prev = NULL;
     
     if(head==NULL){
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
struct node* s, *t;
s = head;
t = head;
printf("The orginal list: ");
while(t != NULL){
    printf("\t%d",t->data);
    t = t->next;
}

while(s->next != NULL){
     s = s->next;
    
}

printf("\nThe reversed list : ");
while(s != NULL){
    printf("\t%d",s->data);
    s = s->prev;
}

    
}
void sort(){
    int n;
    printf("Enter the size of the list: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
     struct node3 *temp;
     temp = (struct node3*)malloc(sizeof(struct node3));
     printf("Enter %d element: ",i+1);
     scanf("%d",&temp->data);
     temp->next = NULL;
     temp->prev = NULL;
     
     if(head3==NULL){
         head3 = temp;
     }
     else{
         struct node3* p;
         p = head3;
         while(p->next != NULL){
             p = p->next;
         }
         p->next = temp;
         temp->prev = p;
         
     }
     
}
struct node3 *t;
t = head3;
printf("The orginal list: ");
while(t != NULL){
    printf("\t%d",t->data);
    t = t->next;
}


struct node3 *current=NULL, *index=NULL, *p;
int temp;

for(current=head3; current->next!=NULL; current=current->next){
    for(index=current->next; index!=NULL; index=index->next){
        if(current->data > index->data){
            temp = current->data;
            current->data = index->data;
            index->data = temp;
        }
        
    }
}
p = head3;
printf("\nThe sorted list is:");
while(p != NULL){
    printf("\t%d",p->data);
    p = p->next;
    
}

    
}

void concatination(){
    struct node1 *temp;
    int n,m;
    printf("Enter the size of list 1: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        temp = (struct node1 *)malloc(sizeof(struct node1));
        printf("Enter %d element : ",i+1);
        scanf("%d",&temp->data);
        temp->next = NULL;
         
     if(head1==NULL){
         head1 = temp;
     }
     else{
         struct node1* p;
         p = head1;
         while(p->next != NULL){
             p = p->next;
         }
         p->next = temp;
         
         
     }
        
    }
    printf("Enter the size of list 2: ");
    scanf("%d",&m);
    struct node1 *p;
    
    for(int i=0; i<m; i++) {
        p = (struct node1*)malloc(sizeof(struct node1));
        printf("Enter %d element : ",i+1);
        scanf("%d",&p->data);
        p->next = NULL;
         
     if(head2==NULL){
         head2 = p;
     }
     else{
         struct node1* p1;
         p1 = head2;
         while(p1->next != NULL){
             p1 = p1->next;
         }
         p1->next = p;
         
         
     }
    }
    if(head1->next == NULL){
        head1->next = head2;
    }
    else{
       struct node1 *x;
       x = head1;
       while(x->next != NULL){
           x = x->next;
       }
       x->next = head2;
    }

    struct node1 *r;
    r = head1;
    printf("Concatenated list is: ");
    while(r != NULL){
        printf("\t%d",r->data);
        r = r->next;
        
    }
    
}

