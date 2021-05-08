#include<stdio.h>

int sum_nat(int n)
	{
	int s=0;
	
	if(n==1)
		return 1;
	
	s=n+sum_nat(n-1);
	
	return(s);
	}


int main()
{
int n,sum=0;

printf("Enter the natural number: ");
scanf("%d",&n);

sum=sum_nat(n);

printf("The sum of the natural numbers: %d",sum);
}
