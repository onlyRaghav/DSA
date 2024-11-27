#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue{
    int f;
    int b;
    int size;
    int * arr;
}Cqueue;
int isFull(Cqueue * p){
    if((p->b+1)%p->size==p->f){
        return 1;
    }
    return 0;
}
int isEmpty(Cqueue * p){
    if(p->b==p->f)
        return 1;
    return 0;
}
void enqueue(Cqueue * p,int val){
    if(isFull(p)){
        printf("\nQueue is Full\n");
    }else{
        p->b=(p->b+1)%p->size;
        p->arr[p->b]=val;
        printf("\nEnqueued Element:%d\n",val);
    }
}
int dequeue(Cqueue * p){
    int a=-1;
    if(isEmpty(p)){
        printf("\nTrying to dequeue on an empty queue\n");
    }else{
        p->f=(p->f+1)%p->size;
        a=p->arr[p->f];
        printf("\nDequeued Element:%d\n",a);
    }
    return a;
}
int main(){
    Cqueue c1;
    c1.size=4;
    c1.f=c1.b=0;
    c1.arr=(int *)malloc(sizeof(int)*c1.size);
    enqueue(&c1,10);
    enqueue(&c1,20);
    enqueue(&c1,30);
    dequeue(&c1);
    dequeue(&c1);
    dequeue(&c1);
    dequeue(&c1);
    if(isEmpty(&c1))
        printf("\nQueue is empty\n");
    return 0;
}

