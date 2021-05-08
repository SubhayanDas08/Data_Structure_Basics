#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Display(struct Node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d->", ptr->data);
        Display(ptr->next);
    }
    else
        printf("NULL\n");
}


void Create(int size, struct Node *head, struct Node *tail)
{
    struct Node *temp;
    int ch = 0;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        
        scanf("%d", &temp->data);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        ch++;
    } while (ch < size);
}

void merge(int size1,struct Node *head, struct Node *tail, int size2, struct Node *head2, struct Node *tail2, struct Node *head3, struct Node *tail3)
{
    struct Node *temp;
    int ch = 0;
    int size = size1 + size2;
    
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        
        if((head->data>head2->data) || head==NULL)
            {
                temp->data = head2->data;
                head2 = head2->next;
            }
        else
            {
                temp->data = head->data;
                head = head->next;   
            }
        
        if (head3 == NULL)
        {
            head3 = tail3 = temp;
        }
        else
        {
            tail3->next = temp;
            tail3 = temp;
        }
        ch++;
    } while (ch < size);
}

int main()
{
    struct Node *head=NULL, *tail=NULL,*head2=NULL, *tail2=NULL, *head3=NULL, *tail3=NULL;
    int t, size1, size2;

    scanf("%d",&t);
    while(t>0)
    {
    scanf("%d",&size1);
    Create(size1, head, tail);

    Display(head);

    scanf("%d",&size2);
    Create(size2, head2, tail2);
    Display(head2);

    merge(size1, head, tail, size2, head2, tail2, head3, tail3);
    
    Display(head3);
    --t;
}
    
    free(head);
    return 0;
}