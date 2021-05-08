/*C Program to find the GCD / HCF of 2 numbers using recursion */

#include<stdio.h>

int hcf(int a,int b)
	{	
	if(a%b==0)
		return b;
		
	hcf(b,a%b);
	}


int main()
{
int n1,n2,gcd;

printf("Enter the 2 numbers: \n");
scanf("%d%d",&n1,&n2);

if(n1>n2)
	{
	gcd=hcf(n1,n2);
	}
else
	{
	gcd=hcf(n2,n1);
	}

printf("The highest common factor is: %d",gcd);

}
