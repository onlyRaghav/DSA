#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top;
    int *arr;
    int size;
};
void display(struct Stack *s)
{
    int i = 0;
    printf("Displaying stack elements\n");
    while (i <= s->top)
    {
        printf("%d ", s->arr[i]);
        i++;
    }
}
void push(struct Stack *s, int data)
{
    if (isFull(s))
    {
        printf("\nStack overloading.Can't add element %d\n", data);
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
        printf("\nValue added at index %d\n", s->top);
    }
}
int peek(struct Stack *s,int i){
    if(s->top-i+1<0){
        printf("\nCannot seek!\n");
        return -1;
    }else{ 
        return s->arr[s->top-i+1];
    }
}
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack empty! Add elements first\n");
        return 1;
    }
    int data = s->arr[s->top];
    s->arr[s->top] = 0;
    s->top--;
    return data;
}
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    struct Stack *s1 = (struct Stack *)malloc(sizeof(struct Stack));
    int pop_element;
    s1->size = 10;
    s1->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    // printf("memory allocated successfully");
    push(s1, 20);
    push(s1, 40);
    push(s1, 60);
    push(s1, 80);
    push(s1, 100);
    push(s1, 120);
    push(s1, 140);
    push(s1, 160);

    // printf("between push and display");
    display(s1);
    pop_element = pop(s1);
    printf("\nElement removed:%d\n",pop_element);
    display(s1);
    for(int i=1;i<=s1->top;i++){
        printf("\nvalue at position %d is %d\n",i,peek(s1,i));
    }
    return 0;
}