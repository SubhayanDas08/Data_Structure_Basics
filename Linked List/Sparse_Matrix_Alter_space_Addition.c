#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int r;
    int c;
    struct Node *next;
};

int display(int r, int c, int (*arr)[c])
    {
        int size=0;
      
    for (int i = 0; i < r; i++)            //Printing the Sparse Matrix
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d  ",arr[i][j]);
                if (arr[i][j]!=0)
                {
                    size++;
                }
                
        }
    printf("\n");
    } 

    return size;
    }

void alter()

int main()
{
    int r1,c1,r2,c2,size1=0,size2=0;

    r1=6;
    c1=4;
  
    int a[6][4]={0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0};                                          //Sparse Matrix 1
   
    r2=6;
    c2=4;
  
    int b[6][4]={0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0};                                          //Sparse Matrix 1

   size1 = display(r1, c1, a);

    printf("\n");
    
    size2 = display(r2, c2, b);
    
    struct Node* arr[size1+1];

    arr[0]=(struct Node*)malloc(sizeof(struct Node));
    arr[0]->data=size1;
    arr[0]->r=r1;
    arr[0]->c=c1;

    int k=1;

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (a[i][j]!=0)
            {
                arr[k]=(struct Node*)malloc(sizeof(struct Node));
                arr[k]->data=a[i][j];
                arr[k]->r=i;
                arr[k]->c=j;
                k++;
            }
            
        }
        
    }
    
    for (int i = 0; i <= size1; i++)
    {
        printf("(%d, %d, %d) | ",arr[i]->data,arr[i]->r,arr[i]->c);
    }
    

    return 0;
}