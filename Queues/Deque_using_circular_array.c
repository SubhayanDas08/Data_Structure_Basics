/*  C Program to implement Deque using circular array  */

#include<stdio.h>
#include<stdlib.h>
#define MAX 9

int deque[MAX];
int top=-1;
int bottom=-1;

int isFull()
{
        if ( (top==0 && bottom==MAX-1) || (top==bottom+1) )
                return 1;
        else
                return 0;
}

int isEmpty()
{
        if( top == -1)
                return 1;
        else
                return 0;
}

void top_insertion(int val)
{
        if( isFull() )
        {
                printf("\nQueue has the max no. of elements\n");
                return;
        }

        if( top==-1 )
        {
                top=0;
                bottom=0;
        }
        else if(top==0)
                top=MAX-1;
        else
                top=top-1;
        deque[top]=val ;
}

void bottom_insertion(int val)
{
        if( isFull() )
        {
                printf("\nQueue has the max no. of elements\n");
                return;
        }
        if(top==-1)  
        {
                top=0;
                bottom=0;
        }
        else if(bottom==MAX-1)  
                bottom=0;
        else
                bottom=bottom+1;
        deque[bottom]=val ;
}

int top_deletion()
{
        int val;
        if( isEmpty() )
        {
                printf("\nQueue has the max no. of elements\n");
                exit(1);
        }
        val=deque[top];
        if(top==bottom) 
        {
                top=-1;
                bottom=-1;
        }
        else
                if(top==MAX-1)
                        top=0;
                else
                        top=top+1;
        return val;
}

int botton_deletion()
{
        int val;
        if( isEmpty() )
        {
                printf("\nQueue has the max no. of elements\n");
                exit(1);
        }
        val=deque[bottom];

        if(top==bottom) 
        {
                top=-1;
                bottom=-1;
        }
        else if(bottom==0)
                bottom=MAX-1;
        else
                bottom=bottom-1;
        return val;
}


void show()
{
        int i;
        if( isEmpty() )
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue elements :\n");
        i=top;
        if( top<=bottom )
        {
                while(i<=bottom)
                        printf("%d ",deque[i++]);
        }
        else
        {
                while(i<=MAX-1)
                        printf("%d ",deque[i++]);
                i=0;
                while(i<=bottom)
                        printf("%d ",deque[i++]);
        }
        printf("\n");
}

int main()
{
        int choice,val;
        while(1)
        {
                printf("\n\n1.Insert at the top end\n");
                printf("2.Insert at the bottom end\n");
                printf("3.Delete from top end\n");
                printf("4.Delete from bottom end\n");
                printf("5.Display\n");
                printf("6.Quit\n");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                case 1:
                        printf("\nInput the element for adding in queue : ");
                        scanf("%d",&val);
                        top_insertion(val);
                        break;
                case 2:
                        printf("\nInput the element for adding in queue : ");
                        scanf("%d",&val);
                        bottom_insertion(val);
                        break;
                 case 3:
                        printf("\nElement deleted from top end is : %d\n",top_deletion());
                        break;
                 case 4:
                        printf("\nElement deleted from bottom end is : %d\n",botton_deletion());
                        break;
                 case 5:
                        show();
                        break;
                 case 6:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }/*End of switch*/
                printf("\ntop = %d, bottom =%d\n", top , bottom);
                show();
        }
}

