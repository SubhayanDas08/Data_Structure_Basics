#include<stdio.h>           //To display the values of signed and unsigned char in decimals
#include<stdlib.h>
#include<string.h>

int main()
{
    int ch;
        do
        {
        signed char a;
        unsigned char b;

        printf("\nEnter the value for signed conversion: a = ");
        scanf("%u",&a);
        printf("Value in decimal of a : %d\n",a);
        
        printf("\nEnter the value for unsigned conversion: b = ");
        scanf("%u",&b);
        printf("Value in decimal of b : %d\n",b);
        
        printf("\nDo you want another conversion? (1/0)");
        scanf("%d",&ch);
        } while (ch!=0);

    return 0;
}