#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct stack 
{
    int data;
    struct stack *next;
};

void push(struct stack **top, int val)
    {

        struct stack *node = (struct stack*)malloc(sizeof(struct stack));
        node->data=val;
        node->next=*top;

        *top = node;
        
	    printf("%d Pushed to stack\n", val); 
        
    }

int pop(struct stack **top)
    {
        struct stack *temptop = *top;

        if (*top == NULL)
        {
            printf("\nS1 Stack Empty!\n");
            return -1;
        }
        else
        {
            (*top) = (*top)->next;
        }

        printf("\nPopped Value:  %d\n",temptop->data);

        return temptop->data;

        free(temptop);

    }

int peek(struct stack* top) 
{ 
	if (top==NULL) 
		return INT_MIN; 

	return top->data; 
} 

void rev_half(struct stack *s1, struct stack **s2, struct stack **s3)
    {
        if (s1 == NULL)
        {
            return;
        }

        int num, count=0;
        printf("\nFIRST\n");
        while(s1!=NULL)
            {
                num=pop(&s1);

                push(s2,num);

                count++;
            }
        
        printf("\nSECOND\n");

        for (int i = 0; i < count/2; i++)
        {
            num = pop(s2);

            push(s3,num);
        }
        
        printf("\nTHIRD\n");

        while (*s2 != NULL)
        {
            num = pop(s2);

            push(&s1,num);
        }

        printf("\nFOURTH\n");
         while(s1!=NULL)
            {
                num=pop(&s1);

                push(s3,num);

            }
    }

int main()
{
    struct stack *s1=NULL, *s2=NULL, *s3=NULL;


    push(&s1,1);
    push(&s1,2);  
    push(&s1,3);
    push(&s1,4);
    push(&s1,5);
    push(&s1,6);

    printf("\nTop value of s1: %d",peek(s1));

    rev_half(s1,&s2,&s3);

    printf("\nTop value of s3: %d",peek(s3));

    printf("\nFINAL STACK(from top to end):\n");
    
    while(s3!=NULL)
        {
            printf("%d  ",pop(&s3));
        }
return 0;
}