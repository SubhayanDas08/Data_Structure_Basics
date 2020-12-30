#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
}*head=NULL, *tail=NULL, *head2=NULL, *tail2=NULL;

void Display(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf("%dx^%d->", ptr->coef,ptr->exp);
        Display(ptr->next);
    }
    else
        printf("NULL\n");
}

int Count(struct Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void Create(int size, struct Node *H, struct Node *T)
{
    struct Node *temp;
    int ch = 0;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        printf("Enter Coefficient : ");
        scanf("%d", &temp->coef);
        printf("Enter Exponent : ");
        scanf("%d", &temp->exp);
        if (H == NULL)
        {
            H = T = temp;
        }
        else
        {
            T->next = temp;
            T = temp;
        }
        ch++;
    } while (ch != size);
}

void Join(struct Node *ptr)
    {
        while (ptr)
        {
            if (ptr->next!=NULL)
            {
            ptr=ptr->next;
            }
            else
            {
            ptr->next=head;
            break;
            }
        }
        
        
    }

int main()
{
    int choice, size1, size2;
    printf("\nEnter the size of the Linked List 1: ");
    scanf("%d",&size1);
    Create(size1,head,tail);
    printf("\nEnter the size of the Linked List 2: ");
    scanf("%d",&size2);
    Create(size2,head2,tail2);

    Display(head);

    Display(head2);

    Join(head);
    
    Display(head);

    free(head);
    free(head2);
    return 0;
}