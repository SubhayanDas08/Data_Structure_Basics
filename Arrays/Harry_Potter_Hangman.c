#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void storage(char *, int);

int main()
{
int choice;

do
{
    char str[100];
    storage(str, rand()%16);                        //chooses the character name from the storage func

    int n=strlen(str), flag=0,temp=-1,ctr=0;        //flag will count no. of guesses
                                                    //temp will check whether its a right guess or not
                                                    //ctr will check whether all the places are filled or not
    char guess[n+1];
    char ch;
    
    for(int i=0;i<n;guess[i++]='_');                //Putting _ in the guess array
    guess[n]='\0';

    
    printf("\n\n*****WELCOME TO THE HARRY POTTER HANGMAN GAME*****\n\n");

    printf("RULES: \nYOU WILL GET 7 GUESSES\nALL ARE IN SMALL LETTERS\nONLY THE FIRST NAME\n");

    printf("\nGUESS THE CHARACTER NAME:  \n\n");

    for (int i = 0;guess[i]!='\0'; i++)
        {
            printf("%c ",guess[i]);                        
        }

    while(flag!=7)
        {
        temp=-1;

            printf("\nEnter your guess:  ");
            fflush(stdin);                           //this clears out the buffer stored by the compiler
            ch = getchar();                          //only takes in 1 character

            for (int i = 0; guess[i]!='\0' ; i++)
            {
                if(ch==guess[i])
                    {
                        printf("Already Guessed!\n");
                        temp++;
                    }
                else if(ch==str[i])                 //compares and stores in the guess array
                    {
                        guess[i]=ch;
                        temp++;
                        ctr++;
                    }
            }
            printf("\n");
  

            if(temp!=-1)
                {
                    for (int i = 0;guess[i]!='\0'; i++)
                    {
                        printf("%c ",guess[i]);
                        
                    }
                }
            else if(temp==-1)
                {
                printf("\nWRONG GUESS!!!!");
                flag++;
                }

        if(ctr==n)
            {
                break;
            }              
        }
    
    if(flag==7)
        {
            printf("\n\nSORRY YOU LOST THE GAME!!!!\n");
            printf("IT WAS:  %s\n",str);
        }
    else if(ctr==n)
        {
            printf("\n\nCONGRATULATIONS YOU WON!!!!\n");
        }
    
    printf("\nDo you wanna play again?  (1/0)");
    scanf("%d",&choice);

} while (choice!=0);

return 0;
}


//Function that returns the name of the character we need to guess
void storage(char *str, int i)
    {
        switch (i)
        {
        case 0:
            strcpy(str,"harry");
            break;
        case 1:
            strcpy(str,"hermoine");
            break;
        case 2:
            strcpy(str,"voldemort");
            break;
        case 3:
            strcpy(str,"draco");
            break;
        case 4:
            strcpy(str,"ron");
            break;
        case 5:
            strcpy(str,"severus");
            break;
        case 6:
            strcpy(str,"albus");
            break;
        case 7:
            strcpy(str,"hagrid");
            break;
        case 8:
            strcpy(str,"luna");
            break;
        case 9:
            strcpy(str,"minerva");
            break;
        case 10:
            strcpy(str,"neville");
            break;
        case 11:
            strcpy(str,"bellatrix");
            break;
        case 12:
            strcpy(str,"dobby");
            break;
        case 13:
            strcpy(str,"sirius");
            break;
        case 14:
            strcpy(str,"dolores");
            break;
        case 15:
            strcpy(str,"ginny");
            break;
        }
    }