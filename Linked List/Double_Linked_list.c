#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} *head = NULL, *tail = NULL;


void Display(struct Node *p)
{
    if (p)
    {
        printf("%d<=>", p->data);
        Display(p->next);
    }
    else
        printf("NULL\n");
}
void Create(int size)
{
    struct Node *temp;
    int ch=0;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->prev = NULL;
        temp->next = NULL;
        printf("Enter the Data : ");
        scanf("%d", &temp->data);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        ch++;
    } while (ch != size);
}


int Deletion(struct Node *p, int pos)
{
    int x;
    if (pos < 1)
        return -1;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }
    if (pos == 1)
    {
        head = p->next;
        head->prev = NULL;
        x = p->data;
        free(p);
        return x;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p && p->next != NULL)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            x = p->data;
            free(p);
            return x;
        }
        else if (p && p->next == NULL)
        {
            p->prev->next = NULL;
            x = p->data;
            free(p);
            return x;
        }
    }
}

int main()
{
    int size;
    printf("\nEnter the size of the double linked list: ");
    scanf("%d",&size);

    Create(size);
    Display(head);
    int pos;
    
    printf("\nEnter the Node positon to Delete : ");
    scanf("%d", &pos);
    int res = Deletion(head, pos);
    printf("\n%d has been deleted.", res);

    printf("\nNew list: \n");
    Display(head);
    free(head);
    return 0;
}
