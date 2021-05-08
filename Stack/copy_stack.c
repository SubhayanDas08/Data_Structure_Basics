#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct stack 
{
    int data;
    struct stack *next;
};

void push(struct stack **s, int val)
    {

        struct stack *node = (struct stack*)malloc(sizeof(struct stack));
        node->data=val;
        node->next=*s;

        *s = node;
        
	    printf("%d Pushed to stack\n", val); 
        
    }

int pop(struct stack **s)
    {
        struct stack *temptop = *s;

        if (*s == NULL)
        {
            printf("\nS1 Stack Empty!\n");
            return -1;
        }
        else
        {
            (*s) = (*s)->next;
        }

        printf("\nPopped Value:  %d\n",temptop->data);

        return temptop->data;

        free(temptop);

    }

int peek(struct stack* s) 
{ 
	if (s==NULL) 
		return INT_MIN; 

	return s->data; 
} 

void copy(struct stack *s1, struct stack **s2)
    {
        int num;

        if (s1 == NULL)
        {
            return;
        }

        num=pop(&s1);

        copy(s1,s2);

        push(s2,num);

    }

int main()
{
    struct stack *s1=NULL, *s2=NULL;


    push(&s1,1);
    push(&s1,2);  

    printf("\nTop value of s1: %d",peek(s1));

    copy(s1,&s2);

    printf("\nTop value of s2: %d",peek(s2));
return 0;
}