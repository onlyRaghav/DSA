#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insert(int arr[],int size,int element,int capcity,int index){
    int flag=0;
    if(size>=capcity){
        printf("Array is full");
        return 1;
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
        flag=1;
    }
    arr[index]=element;
    size++;
    if(flag){
        printf("\nArray updated successfully\n");
        display(arr,size);
        return 0;
    }
}
int main()
{
    int arr[20] = {10, 20, 39, 40};
    int size=4 ,element=44,capacity=20,index=1;
    // display(arr,size);
    insert(arr,size,element,capacity,index);
    size++;
    return 0;
}