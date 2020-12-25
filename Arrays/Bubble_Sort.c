#include<stdio.h>               //Bubble Sort
#include<stdlib.h>

#define size 10

void swap(int *a,int *b)
    {
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }

void sort(int *a)
    {
        for(int i=0;i<size-1;i++)
            {
                for(int j=0;j<size-i-1;j++)
                    {
                        if(a[j]>a[j+1])
                            swap(&a[j],&a[j+1]);
                    }
            }
    }


int main()
{
    int arr[size];

    for(int i=0;i<size;i++)
        arr[i]=rand();

    printf("Array: \n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }

    sort(arr);

    printf("\nArray: \n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    
}
