#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head=NULL, *tail=NULL, *head2=NULL, * tail2=NULL;

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
    head2 = q;
}

void Reverse_Even(struct Node *ptr)
    {
        int ctr = Count(ptr);

        struct Node *temp , *even;

        for (int i = 1; i < ctr && ptr; i++)
         
        {
                    even = ptr->next;
                    temp = (struct Node *)malloc(sizeof(struct Node));
                    temp->next = NULL;
                    temp->data = even->data;

                    if (head2 == NULL)
                    {
                        head2 = tail2 = temp;
                    }
                    else
                    {
                        tail2->next = temp;
                        tail2 = temp;
                    }
                    ptr->next=even->next;
                    ptr = even->next;

                    ctr--;
                    
        }
        
        printf("\n");
    	
        Reverse(head2);
        
        ptr=head;
        
        while(ptr != NULL)
        {
            if(head2 != NULL)
            {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->data=head2->data;
                temp->next = NULL;

                temp->next = ptr->next;
                ptr->next = temp;
                ptr=temp->next;

                head2=head2->next;
            }
            else{
                ptr = ptr->next;
            }

        }


    }//End of Reverse_Even()

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
    } while (ch != size);
}

int main()
{
    int choice, size;
    printf("\nEnter the size of the Linked List: ");
    scanf("%d",&size);
    Create(size);
    Display(head);

    do
    {
        printf("\nEnter 1 to Count the Number of Nodes\nEnter 2 to Reverse the List\nEnter 0 to terminate Program\n");
    
        printf("Enter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
                printf("\nNo. of Nodes in the list is : %d", Count(head));
            break;
        
        case 2:            
                Reverse_Even(head);
                Display(head);
            break;
  
        default:
            break;
        }        

    } while (choice != 0);

    free(head);
    free(head2);
    return 0;
}