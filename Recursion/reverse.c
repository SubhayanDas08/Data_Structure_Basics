//reverse a number using recursion

#include<stdio.h>

int rev(int n)
	{
	if(n%10!=0)
		{
		printf("%d",n%10);
		rev(n/10);
		}
	}
	
int main()
{
int n=123;

rev(n);
}


