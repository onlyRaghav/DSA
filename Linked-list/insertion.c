#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void display(struct Node *n)
{
    printf("\n");
    for (int i = 0; n != NULL; i++)
    {
        printf("Node %d data: %d\n", i + 1, n->data);
        n = n->next;
    }
}

struct Node * insert_beginning(struct Node * head,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node*));
    printf("\nCreating a new Head\n");
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct Node * insert_inbetween(struct Node * head,int data,int index){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node *));
    struct Node * p=head;
    printf("\ninserting a new Node between two existing Nodes\n");
    for(int i=0;i<index;i++){
        p=p->next;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return ptr;
}

struct Node * insert_end(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node *));
    struct Node *p=head;
    printf("\nInserting Node at the End...\n");
    for(int i=0;p->next!=NULL;i++){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}

struct Node * insert_AfterNode(struct Node * head,struct Node * prevNode,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    printf("\nInserting after the given node\n");
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return ptr;
}

int main()
{
    // Declaring nodes for my linked list
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocating dynamic memory for my nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Defining data and next pointer of my head node
    head->data = 10;
    head->next = second;
    // Defining data and next pointer of my first node
    second->data = 20;
    second->next = third;
    // Defining data and next pointer of my second node
    third->data = 30;
    third->next = NULL;

    // Traversing over the linked list and show data of each node
    display(head);
    head=insert_beginning(head,5);
    display(head);
    insert_inbetween(head,44,2);
    display(head);
    insert_end(head,50);
    display(head);
    insert_AfterNode(head,second,15);
    display(head);
    return 0;
}