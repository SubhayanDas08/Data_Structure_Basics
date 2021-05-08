// C program for array implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

#define size 5

struct Stack { 
	int s1; 
	int s2; 
	int n; 
	int* array; 
}; 


struct Stack* create(int n) 
{ 
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
	stack->n = n; 
	stack->s1 = -1; 
    stack->s2 = size;
	stack->array = (int*)malloc(stack->n * sizeof(int)); 
	return stack; 
} 


int full(struct Stack* stack) 
{ 
	return (stack->s1 == stack->n - 1); 
} 

int empty(struct Stack* stack) 
{ 
	return (stack->s1 == -1 && stack->s2 == size); 
} 


void push(struct Stack* stack, int item, int index) 
{ 
	if (full(stack)) 
		return; 
    
    if (stack->s1 + 1 != stack->s2)
    {
        if (index==0)
        {
        stack->array[++stack->s1] = item; 
        printf("%d pushed to stack from s1\n", item); 
        
        }
        else if (index==1)
        {
        stack->array[--stack->s2] = item; 
        printf("%d pushed to stack from s2\n", item); 
        }
    }
    else
    {
        if (index==0)
        {
        stack->array[++stack->s1] = item; 
        printf("%d pushed to stack from s1\n", item); 

        ++stack->s2;
        }
        else if (index==1)
        {
        stack->array[--stack->s2] = item; 
        printf("%d pushed to stack from s2\n", item); 

        --stack->s1;
        }
    }
    
    
    
} 

void pop(struct Stack* stack, int index) 
{
    int temp;

    if (index==0)
    {
        temp = stack->s1;
        printf("\n%d popped from stack\n",stack->array[stack->s1--]);

        stack->array[temp]=-1; 
    }
    else if (index==1)
    {
        temp = stack->s2;
        printf("\n%d popped from stack\n",stack->array[stack->s2++]);

        stack->array[temp]=-1; 
    }
} 


void display(struct Stack *stack)
{
    printf("\nTOP 1 is : %d", stack->array[stack->s1]);
    printf("\nTOP 2 is : %d", stack->array[stack->s2]);
}

// Driver program to test above functions 
int main() 
{ 
	struct Stack* stack = create(size); 

	push(stack, 10, 0); 
	push(stack, 20, 0); 
	push(stack, 30, 1);  
	push(stack, 40, 1);  
	push(stack, 50, 1); 
	push(stack, 60, 1); 

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", stack->array[i]);
    }
    

	pop(stack, 1); 
    

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", stack->array[i]);
    }
    
	pop(stack, 0); 
    

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", stack->array[i]);
    }
	return 0; 
    
} 
