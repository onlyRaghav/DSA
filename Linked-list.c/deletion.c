#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
void display(struct Node * head){
    while(head!=NULL){
        printf("%d \n",head->data);
        head=head->next;
    }
}
struct Node * delete_beginning(struct Node * head){
    struct Node * ptr=head;
    head=head->next;
    free(ptr);
    printf("\nHead updated\n");
    return head;
}
int delete_inbetween(struct Node * head,int inx){
    struct Node * p=head;
    struct Node * q;
    printf("\nDeletion between two Nodes\n");
    for(int i=1;i<inx;i++){
        p=p->next;
    }
    q=p->next;
    p->next=q->next;
    free(q);
    printf("\nLinked list updated\n");
    return 0;
}

int delete_last(struct Node * head){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    printf("\nLinked list updated\n");
    return 0;
}
int delete_data(struct Node * head,int data){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->data!=data){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    printf("\nLinked List updated\n");
    return 0;
}
int main()
{
    struct Node * head;
    struct Node * first;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    head=(struct Node *)malloc(sizeof(struct Node ));
    first=(struct Node *)malloc(sizeof(struct Node ));
    second=(struct Node *)malloc(sizeof(struct Node ));
    third=(struct Node *)malloc(sizeof(struct Node ));
    fourth=(struct Node *)malloc(sizeof(struct Node ));
    fifth=(struct Node *)malloc(sizeof(struct Node ));

    head->data=10;
    head->next=first;

    first->data=20;
    first->next=second;

    second->data=30;
    second->next=third;

    third->data=40;
    third->next=fourth;

    fourth->data=50;
    fourth->next=fifth;

    fifth->data=60;
    fifth->next=NULL;

    // head=delete_beginning(head);
    display(head);
    delete_inbetween(head,2);
    display(head);
    delete_last(head);
    display(head);
    delete_data(head,40);
    display(head);
    return 0;
}