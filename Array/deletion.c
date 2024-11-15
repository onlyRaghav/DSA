#include<stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int delete(int arr[],int size,int inx){
    if(size<=0){
        printf("Array empty.Can't perform delete opr");
        return 1;
    }
    for(int i=inx;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("After deletion\n");
    return 0;
}
int main()
{
int arr[50]={10,30,50,70,90};
int size=5,index=2;
delete(arr,size,index);
display(arr,size);
return 0;
}