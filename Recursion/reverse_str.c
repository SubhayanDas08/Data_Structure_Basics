//reverse a string using recursion

#include<stdio.h>
#include<string.h>

char rev(char *str)
	{
	if(*str)
		{
		rev(str+1);
		printf("%c",*str);
		}
	}
	
int main()
{
char n[]="akash";

rev(n);
}


