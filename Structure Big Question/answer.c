#include<stdio.h>
#include<stdlib.h>

#define size 2      //Number of accounts

struct account
{
    int num;
    char name[20];
    int bal;
    int pin;
};

void getval(struct account *a, int n)
    {
        printf("\n\nACCOUNT %d:",n);
        printf("\nEnter Name:  ");
        scanf("%s",a->name);
        printf("Enter the Amount:  ");
        scanf("%d",&a->bal);
        printf("Enter the pin for your account:  ");
        scanf("%d",&a->pin);
        printf("GENERATING ACCOUNT NUMBER");
        int upper = 10000000;
        int lower = 1000000;
        a->num=(rand()%(upper - lower + 1)) + lower;
    }

void show(struct account a)
    {
        printf("\n\nACCOUNT NUMBER:  %d",a.num);
        printf("\nName:  %s",a.name);
        printf("\nBalance:  %d",a.bal);
    }

void form(struct account *a, int acc, int amt, int code, int ch)
    {
        int temp, flag=-1;

        for (int i = 0; i < size; i++)
        {
            if (a[i].num==acc)
            {
                temp=i;
                flag++;
                break;
            }
        }

        if(flag!=-1)
        {       
            if (a[temp].pin==code)
            {
                switch (ch)
                {
                case 1:
                    printf("\nSpecified Amount has been deposited.");
                    a[temp].bal+=amt;
                    printf("\nUPDATED STATUS:");
                    show(a[temp]);
                    printf("\nTHANK YOU!!");
                    break;
                
                case 0:
                    if (a[temp].bal>=amt)
                    {
                        printf("\nSpecified Amount has been withdrawn.");
                        a[temp].bal-=amt;
                        printf("\nUPDATED STATUS: ");
                        show(a[temp]);
                        printf("\nTHANK YOU!!");
                    }
                    else
                    {
                        printf("\nThe Balance is Insufficient for the specified withdrawal.");
                    }
                    
                    break;
                
                default:
                    break;
                }
            }
            else
            {
                printf("\nWRONG PIN ENTERED");            
            }
       
        }
        else
        {
            printf("\nACCOUNT NOT FOUND\nACCOUNT NUMBER IS WRONG");
        }
                
    }

int main()
{
    struct account customers[size];

    printf("\nCREATING %d NUMBER OF ACCOUNTS",size);

    for (int i = 0; i < size; getval(&customers[i++],i));

    printf("\n\n\n******ALL THE ACCOUNT DETAILS******: ");

    for (int i = 0; i < size; show(customers[i++]));

    int acc, amt, code, ch;

    printf("\n\n******FORM******\n");

    printf("\nEnter Account Number:  ");
    scanf("%d",&acc);
    printf("\nEnter Amount:  ");
    scanf("%d",&amt);
    printf("\nEnter Pin:  ");
    scanf("%d",&code); 
    printf("\n\nFor Withdrawal Enter 0\nFor Deposit Enter 1");
    printf("\nEnter your choice:  ");
    scanf("%d",&ch);

    form(customers, acc, amt, code, ch);   
    
return 0;
}