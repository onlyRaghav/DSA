#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void display(struct Node * head){
    struct Node * ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

void display_reverse(struct Node * head){
    struct Node * ptr=head;
    printf("\nTraversing Node data in reverse order\n");
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }
}

int main()
{
    struct Node * n1;
    struct Node * n2;
    struct Node * n3;
    struct Node * n4;

    n1=(struct Node *)malloc(sizeof(struct Node));
    n2=(struct Node *)malloc(sizeof(struct Node));
    n3=(struct Node *)malloc(sizeof(struct Node));
    n4=(struct Node *)malloc(sizeof(struct Node));

    n1->data=10;
    n1->prev=NULL;
    n1->next=n2;

    n2->data=20;
    n2->prev=n1;
    n2->next=n3;

    n3->data=30;
    n3->prev=n2;
    n3->next=n4;

    n4->data=40;
    n4->prev=n3;
    n4->next=NULL;

    display(n1);
    display_reverse(n1);

    return 0;
}