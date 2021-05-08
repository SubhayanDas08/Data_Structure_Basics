#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL, *tail=NULL;

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

void Reverse(struct Node *ptr)
{
    struct Node *r = NULL, *q = NULL;
    while (ptr != NULL)
    {
        r = q;
        q = ptr;
        ptr = ptr->next;
        q->next = r;
    }
    head = q;
}

void Insertion(struct Node *ptr, int pos, int x)
{
    struct Node *temp;
    if (pos < 0 || pos > Count(ptr))
    {
        printf("Invalid Position\n");
        return;
    }

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
    {
        head = tail = temp;
    }
    if (pos == 0)
    {
        //Insertion at head.
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < pos - 1 && ptr; i++)
            {
            ptr = ptr->next;
            }
        if (ptr)
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
}

int Delete(struct Node *ptr, int pos)
{
    int x = -1;
    struct Node *q = NULL;
    if (pos < 1 || pos > Count(ptr))
        return -1;

    if (pos == 1)
    { //Assuming indexing starts from 1 to n;
        q = head;
        head = head->next;
        x = q->data;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < pos - 1 && ptr; i++)
        {
            q = ptr;
            ptr = ptr->next;
        }
        q->next = ptr->next;
        x = ptr->data;
        free(ptr);
        return x;
    }
}
void Create(int size)
{
    struct Node *temp;
    int ch = 0;
    do
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->next = NULL;
        
        printf("Enter Data : ");
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

void swap(struct Node *a,struct Node *b)
    {
        int temp;
        temp=a->data;
        a->data=b->data;
        b->data=temp;
    }

void Alternate(struct Node *ptr)
    {
        for (int i = 0; i < Count(ptr) && ptr; i++)
        {
            struct Node *temp;
            temp=ptr->next;
            swap(ptr,temp);
            ptr=ptr->next;
            ptr=ptr->next;
        }     

    }


int main()
{
    int choice, size;
    printf("\nEnter the size of the linked list: ");
    scanf("%d",&size);
    Create(size);
    Display(head);

    do
    {
        printf("\nEnter 1 to Count the Number of Nodes\nEnter 2 to Reverse the List\nEnter 3 to perform Insertion\nEnter 4 to Delete Node\nEnter 5 to Swap Alternate Values\nEnter 0 to terminate Program\n");
    
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
                printf("\nNo. of Nodes in the list is : %d", Count(head));
            break;
        
        case 2:            
                Reverse(head);
                Display(head);
            break;
        
        case 3:{            
                int x, index;
                printf("\nEnter the Data you want to insert : ");
                scanf("%d", &x);
                printf("\nEnter the Position : ");
                scanf("%d", &index);
                Insertion(head, index, x);
                printf("\nNew List is : \n");
                Display(head);
            break; 
            }   

        case 4:{            
                int i;
                printf("\nEnter the Index to Delete the Node : ");
                scanf("%d", &i);
                int res = Delete(head, i);
                printf("\nNode Deleted with Value %d\nNewlist is\n", res);
                Display(head);
            break; 
            }

        case 5:            
                Alternate(head);
                Display(head);
            break;

        default:
            break;
        }        

    } while (choice != 0);

    free(head);
    return 0;
}