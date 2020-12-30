#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coef;    
    int *exp;
    struct node *next;
};


void Display(struct node *ptr)
{
    if (ptr != NULL)
    {
        if(ptr->next != NULL)
        {            
            printf("%d*X(%d)*Y(%d)*Z(%d) + ", ptr->coef, *(ptr->exp+0), *(ptr->exp+1), *(ptr->exp+2));
            Display(ptr->next);
        }
        else
        {
            printf("%d*X(%d)*Y(%d)*Z(%d)", ptr->coef, *(ptr->exp+0), *(ptr->exp+1), *(ptr->exp+2));
            Display(ptr->next);
        }
    }
    else
        printf("\n");   
}

void Create(struct node **head,struct node **tail, int size)
{
    struct node *temp;
    int ch = 0;

    do
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->next = NULL;
        printf("\nEnter Coef : ");
        scanf("%d", &temp->coef);
        
        temp->exp = (int *)malloc(3 * sizeof(int));

        printf("Enter X's exponent : ");
        scanf("%d", &temp->exp + 0);
            
        printf("Enter Y's exponent : ");
        scanf("%d", &temp->exp + 1);
            
        printf("Enter Z's exponent : ");
        scanf("%d", &temp->exp + 2);
        

        if (*head == NULL)
        {
            *head = *tail = temp;
        }
        else
        {
            (*tail)->next = temp;
            *tail = temp;
        }
        ch++;
        free(temp);

    } while (ch < size);
}

int main()
{
    struct node *head,*tail;

    int choice, size;
    printf("\nEnter the size of the equation: ");
    scanf("%d",&size);
    Create(&head,&tail,size);
    Display(head);

return 0;
}