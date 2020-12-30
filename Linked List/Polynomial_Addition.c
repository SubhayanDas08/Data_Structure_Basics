#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

void Display(struct Node *ptr)
{
    if (ptr != NULL)
    {
        if(ptr->next != NULL)
        {            
            printf("%d X^%d + ", ptr->coef,ptr->exp);
            Display(ptr->next);
        }
        else
        {
            printf("%d X^%d", ptr->coef,ptr->exp);
            Display(ptr->next);
        }
    }
    else
        printf("\n");   
    
}

void Create(struct Node **head, struct Node **tail, int size)
{
    struct Node *temp;
    
    for (int i = size; i > 0; i--)
    {    
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        printf("\nEnter the Coefficient : ");
        scanf("%d", &temp->coef);
        printf("\nEnter the Exponent : ");
        scanf("%d", &temp->exp);
        
        if (*head == NULL)
        {
            *head = *tail = temp;
        }
        else
        {
            (*tail)->next = temp;
            *tail = temp;
        }
    }       
}

void Add(struct Node **head)
    {
        struct Node *ptr1, *ptr2, *temp;        
        
        ptr1=*head;

        while (ptr1 != NULL)
        {                
            temp=ptr1;                  //temp is the preceding node to ptr2
            ptr2=temp->next;            //ptr2 is the next node to ptr1

            while (ptr2 != NULL)
            {
                if (ptr1->exp==ptr2->exp)
                {
                    ptr1->coef = ptr1->coef + ptr2->coef;

                    temp->next = ptr2->next;
                    ptr2 = temp->next;
                }
                else
                {
                    temp = temp->next;
                    ptr2 = temp->next;
                }              
                
            }
            
            ptr1=ptr1->next;
        }
    }


int main()
{
    struct Node *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL;
    int size1,size2;

    printf("\nEnter the size of first equation: ");
    scanf("%d",&size1);
    Create(&head1,&tail1,size1);
    Display(head1);

    printf("\nEnter the size of second equation: ");
    scanf("%d",&size2);
    Create(&head2,&tail2,size2);
    Display(head2);
    
    tail1->next=head2;
    tail1=tail2;
    

    printf("\n*****POLYNOMIAL ADDITION******\n\n");

    Add(&head1);
    Display(head1);

    free(head1);
    free(head2);
    return 0;
}