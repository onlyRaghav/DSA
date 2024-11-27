#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int f;
    int b;
    int size;
    int *arr;
} Queue;

void display(Queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue empty!!!");
    }
    else
    {
        printf("\nDisplay Queue\n");
        for (int i =ptr->f; i < ptr->b; i++)
        {
            printf("%d ", ptr->arr[i+1]);
        }
    }
}
int isFull(Queue *ptr)
{
    if (ptr->b == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Queue *ptr)
{
    if (ptr->b == ptr->f)
    {
        return 1;
    }
    return 0;
}
void enque(Queue *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("NOT ALLOWED TO ADD ELEMENT!!");
    }
    else
    {
        ptr->b++;
        ptr->arr[ptr->b] = data;
    }
}
int Deque(Queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
    {
        printf("NOT ALLOWED TO REMOVE ELEMENT!!");
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}
int main()
{
    Queue q;
    q.size = 50;
    q.f = q.b = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    // display(&q);
    enque(&q,10);
    enque(&q,20);
    enque(&q,30);
    enque(&q,40);
    enque(&q,50);
    enque(&q,60);
    enque(&q,70);
    display(&q);
    Deque(&q);
    Deque(&q);
    Deque(&q);
    display(&q);
    return 0;
}