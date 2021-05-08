/*C Program to find the factorial of a number using Recursion*/

#include<stdio.h>

int fact(int n)
	{
	
	if(n==0||n==1)
		return 1;
		
	return(n*fact(n-1));
	}

int main()
{
int num,fac;

printf("Enter the number of which want factorial: ");
scanf("%d",&num);

fac=fact(num);

printf("The factorial is: %d",fac);

}
