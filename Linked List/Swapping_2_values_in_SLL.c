#include<stdio.h>
#include<stdlib.h>

int size;

struct Node
{
    int data;
    struct Node* next;
}*head, *tail;

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

void swap_nodes(struct Node *ptr, int pos1, int pos2)
    {
        struct Node *temp1=(struct Node *)malloc(sizeof(struct Node));
        struct Node *temp2=(struct Node *)malloc(sizeof(struct Node));
        int ctr=1;
        
        while (ptr)
        {
            if(ctr==pos1)
                {
                    temp1=ptr;
                }
            else if (ctr==pos2)
                {
                    temp2=ptr;
                }
            ptr=ptr->next;
            ctr++;
        }

        printf("\nTEMP1:  %d",temp1->data);
        temp1->next=NULL;
        printf("\nTEMP2:  %d",temp2->data);
        temp2->next=NULL;

        ptr=head;
        
        printf("\nPTR:  %d",ptr->data);
        ctr=1;

        while (ptr!=NULL && ctr<=size)
        {
            if(ctr==pos1 && ptr==head)
                {
                    temp2->next=ptr->next;
                    ptr=temp2;
                    head=ptr;
                }
            if (ctr+1==pos2 && ptr->next==tail)
                {
                    ptr->next=temp1;
                    tail=temp1;
                    temp1->next=NULL;
                    ptr=temp1;
                }
            if(ctr+1==pos1)
                {
                    temp2->next=ptr->next;
                    ptr->next=temp2;
                    ptr=temp2;
                }
            if(ctr+1==pos2)
                {
                    temp1->next=ptr->next;
                    ptr->next=temp1;
                    ptr=temp1;
                }
            else
                {
                    ptr=ptr->next;
                }
            
            printf("\nPtr( %d ): %d",ctr,ptr->data);
            ctr++;           
        }
        
        
    }

void getpos(struct Node *ptr, int x, int y, int *pos1, int *pos2)
    {
        int ctr=1;

        while(ptr)
            {
                if (ptr->data==x)
                {
                    *pos1=ctr;
                    ctr++;
                }
                else if (ptr->data==y)
                {
                    *pos2=ctr;
                    ctr++;
                }
                else
                {
                    ctr++;
                }
                ptr=ptr->next;
            }

        if(*pos1>*pos2)
            {
                int temp;
                temp=*pos1;
                *pos1=*pos2;
                *pos2=temp;
            }
        
    }

int main()
{
    int choice;
    printf("\nEnter the size of the Linked List: ");
    scanf("%d",&size);
    Create(size);
    Display(head);

    int x, y, pos1=0, pos2=0;

    printf("\nEnter the numbers you want to swap:");
    printf("\nEnter X: ");
    scanf("%d",&x);
    printf("\nEnter Y: ");
    scanf("%d",&y);

    getpos(head,x,y,&pos1,&pos2);

    printf("\nPos1:  %d",pos1);
    printf("\nPos2:  %d\n",pos2);    
    
    swap_nodes(head,pos1,pos2);
    Display(head);

    free(head);
return 0;
}