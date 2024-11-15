#include <stdio.h>
#include <stdlib.h>

typedef struct myArray{
    int *data;
    int total_size;
    int used_size;
} Array;

void create_array(Array * a,int capacity,int size){
    a->total_size=capacity;
    a->used_size=size;
    a->data=(int *)calloc(capacity,sizeof(int));
}
void show_array(Array *a){
    for(int i=0;i<a->used_size;i++){
        printf("%d ",(a->data)[i]);
    }
}
void resize_array(Array *a){
    a->total_size=a->total_size*2;
    a->data=(int *)realloc(a->data,a->total_size);
}
void push_back(Array*a,int val){
    if(a->total_size==a->used_size){
        resize_array(a);
        printf("\ncapacity double\n");
    }
    a->data[a->used_size++]=val;
}
void pop_back(Array *a){
    if(a->used_size<=0){
        printf("Deleting element from an empty array");
    }
    a->data[a->used_size--]=0;
}

int main(){
    Array arr;
    create_array(&arr,20,0);
    for(int i=0;i<11;i++){
        push_back(&arr,i+10);
    }
    show_array(&arr);
    printf("\nusedsize:%d\n",arr.used_size);
    printf("total_size:%d\n",arr.total_size);
    pop_back(&arr);
    show_array(&arr);
    return 0;
}