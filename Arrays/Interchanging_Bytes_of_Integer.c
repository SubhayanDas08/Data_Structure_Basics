#include<stdio.h>

int main()
{   
    int x,ch;
    do
    {
        printf("\nEnter the integer whose bytes needs to be interchanged:\n");
        scanf("%d",&x);
    
        for (int i = 0; i < sizeof(x); ++i) 
            
            {
            unsigned char byte = *((unsigned char *)&x + i);
            printf("Byte %d = %u\n", i, (unsigned)byte);
            }

        printf("\n****SWAPPING BYTES****\n\n");

        unsigned char temp;
        temp=*((unsigned char *)&x + 1);
        *((unsigned char *)&x + 1)=*((unsigned char *)&x + 2);
        *((unsigned char *)&x + 2)=temp;

                
        for (int i = 0; i < sizeof(x); ++i) 
            {
            unsigned char byte = *((unsigned char *)&x + i);
            printf("Byte %d = %u\n", i, (unsigned)byte);
            }
        
        printf("\nNEW VALUE IS: \t%d\n",x);

        printf("\nDo you want another one? (1/0)");
        scanf("%d",&ch);
    } while (ch!=0);
    
return 0;
}   

