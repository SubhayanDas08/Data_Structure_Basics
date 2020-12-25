/*
 * C Program to Add two Complex Numbers
 */
#include <stdio.h>

#define num 2       //number of complex numbers we are adding
 
struct complex
{
   int realpart, imaginary;
};

void getdata(struct complex *com)
    {
    printf("Enter value of the complex number in the form of a + ib.\n");
    printf("Value of Real Part a is = ");
    scanf("%d", &com->realpart);
    printf("value of Imaginary Part b is = ");
    scanf("%d", &com->imaginary);
    }

void showdata(struct complex *com,int i)
    {
    printf("Value of %d complex number is:\n",i+1);
    printf("Value of Real Part a is =   %d\n", com->realpart);
    printf("Value of Imaginary Part b is = %d\n", com->imaginary);
    }

int add_r(struct complex *com)
{
    struct complex temp;

    for(int i=0;i<num-1;i++ )
        {
        temp.realpart=com[i].realpart + com[i+1].realpart;
        }
    
    return temp.realpart;
}

int add_i(struct complex *com)
{
    struct complex temp;

    for(int i=0;i<num-1;i++ )
        {
        temp.imaginary=com[i].imaginary + com[i+1].imaginary;
        }
    
    return temp.imaginary;
}
 
int main()
{
    struct complex com[num],sum;
 
    for (int i = 0; i < num; i++)
    {
        getdata(&com[i]);
        printf("\n");
    }

    printf("\n***DISPLAYING***\n");
    for (int i = 0; i < num; i++)
    {
        showdata(&com[i],i);
        printf("\n");
    }
    
    printf("\n***SUM***\n");

    sum.realpart=add_r(com);

    sum.imaginary=add_i(com);

    if (sum.imaginary >= 0)
        printf("\nSum is = %d + %di\n", sum.realpart, sum.imaginary);
    else
        printf("\nSum = %d %di\n", sum.realpart, sum.imaginary);
    return 0;
}