#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Stack { 
    int top; 
    int maxSize;
    int* array; 
}; 

struct Stack* create(int max) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->maxSize = max; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));
    return stack; 
} 

int isFull(struct Stack* stack) 
{ 
    if(stack->top == stack->maxSize - 1){
        printf("Will not be able to push maxSize reached\n");
    }
    return stack->top == stack->maxSize - 1; 
} 

int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
}

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
}

int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
} 

int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 

int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

int getPostfix(char* infix) 
{ 
    int i, j; 

    struct Stack* stack = create(strlen(infix)); 
    if(!stack)
        return -1 ; 

    for (i = 0, j = -1; infix[i]; ++i) 
    { 
        if (checkIfOperand(infix[i])) 
            infix[++j] = infix[i]; 

        else if (infix[i] == '(') 
            push(stack, infix[i]); 

        else if (infix[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') 
                infix[++j] = pop(stack); 
            if (!isEmpty(stack) && peek(stack) != '(') 
                return -1;              
            else
                pop(stack); 
        } 
        else 
        { 
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) 
                infix[++j] = pop(stack); 
            push(stack, infix[i]); 
        } 

    } 

    while (!isEmpty(stack)) 
        infix[++j] = pop(stack); 

    infix[++j] = '\0'; 
    
}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}

void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}

void InfixtoPrefix(char *exp){

    int size = strlen(exp);

    reverse(exp);
    brackets(exp);
    getPostfix(exp);
    reverse(exp);
}

int main()
{    
    printf("The infix is: ");

    char infix[SIZE]; 
    
	printf("\nEnter Infix  : ");
	gets(infix);

    InfixtoPrefix(infix); 

    printf("The prefix is: ");
    printf("%s\n",infix);

    return 0; 
}