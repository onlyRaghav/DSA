#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct Node *insert_beginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->next;
    printf("\nHead Updated\n");
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = head;
    p->next = ptr;
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
    third->next = head;

    display(head);
    head=insert_beginning(head,5);
    display(head);
    return 0;
}