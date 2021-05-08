
#include<stdio.h>
#include<stdlib.h>      
#include<ctype.h>    
#include<string.h>

#define size 100


char stack[size];
int top = -1;

void push(char val)
{
	if(top >= size-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = val;
	}
}

char pop()
{
	char val ;

	if(top <0)
	{
		printf("Invalid Infix expression");
		getchar();
		exit(1);
	}
	else
	{
		val = stack[top];
		top = top-1;
		return(val);
	}
}

int operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')         
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void infix_to_postfix(char infix[], char postfix[])
{ 
	int i, j;
	char val;
	char x;

	push('(');                               
	strcat(infix,")");                  

	i=0;
	j=0;
	val=infix[i];    

	while(val != '\0')       
	{
		if(val == '(')
		{
			push(val);
		}
		else if( isdigit(val) || isalpha(val))
		{
			postfix[j] = val;           
			j++;
		}
		else if(operator(val) == 1)     
		{
			x=pop();
			while(operator(x) == 1 && precedence(x)>= precedence(val))
			{
				postfix[j] = x;                 
				j++;
				x = pop();                       
			}
			push(x);

			push(val);                 
		}
		else if(val == ')')        
		{
			x = pop();                   
			while(x != '(')              
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}
		i++;


		val = infix[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
	}


	postfix[j] = '\0'; 

}

int main()
{
	char infix[size], postfix[size];      

	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	gets(infix);

	infix_to_postfix(infix,postfix);                   
	printf("Postfix Expression: ");
	puts(postfix);                     

	return 0;
}
