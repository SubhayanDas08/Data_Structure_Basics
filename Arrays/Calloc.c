#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int i,n;

    n=5;
    printf("Number of Elements: %d\n",n);

    ptr=(int* )calloc( n , sizeof(float));

    if (ptr==NULL)
    {
        printf("Memory not allocated. \n");
    }
    else
    {
        printf("Memory successfully allocated. \n");
    }

    for (i = 0; i < n; i++)
    {
        ptr[i]=rand();
    }

    printf("The elements of the array are: "); 
    for (i = 0; i < n; ++i) 
    {    
        printf("%d, ", ptr[i]);
    }

    free(ptr);          //deallocates the memory
return 0;   
    
}