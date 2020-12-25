#include<stdio.h>
#include<stdlib.h>

#define size 3

void transpose(int *a[])
    {
        int trans[size][size];

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                *(*(trans+j)+i)=*(*(a+i)+j);
            }            
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                *(*(a+i)+j)=*(*(trans+i)+j) ;
            }            
        }
        
    }

int main()
{
    int *a[size];

     for (int i = 0; i < size; i++)
     {
         a[i] = (int *)malloc(size*sizeof(int));
     }


    int n1,n2;
    printf("\nEnter the Lower range:  ");
    scanf("%d",&n1);
    printf("Enter the Upper range:  ");
    scanf("%d",&n2);


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(*(a+i)+j)=rand()%(n2-n1+1);
        }
    }

    printf("\nArray: \n");
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d  ",*(*(a+i)+j));
        }
        printf("\n");
    }

    transpose(a);
   
    printf("\nTransposed Array: \n");
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d  ",*(*(a+i)+j));
        }
        printf("\n");
    }

return 0;
}