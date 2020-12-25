#include<stdio.h>

int main()
{   
    int x,ch;
    do
    {
        printf("\nEnter the integer whose bytes needs to be displayed:\n");
        scanf("%d",&x);
    
        for (int i = 0; i < sizeof(x); ++i) 
            {
            unsigned char byte = *((unsigned char *)&x + i);
            printf("Byte %d = %u\n", i, (unsigned)byte);
            }

        printf("\nDo you want another conversion? (1/0)");
        scanf("%d",&ch);
    } while (ch!=0);
    
return 0;
}   

