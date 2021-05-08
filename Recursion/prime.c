/*C Program to check whether a number is prime number or not using Recursion*/

#include<stdio.h>

int rec_prime(int n,int i)
{
if (i==2)
return 1;

return ((n%(i-1))!=0)*rec_prime(n,i-1);
}


int main()
{
int n,temp=0,i;

printf("Enter a number: ");
scanf("%d",&n);

i=n;
temp=rec_prime(n,i);

if(temp==1)
	printf("Its a prime number");
else
	printf("Its not a prime number");
}
