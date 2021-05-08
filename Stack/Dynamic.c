#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
//STACK implementation using Dynamic Array.

typedef struct
{
    int *data;
    int Top;
} STACK;
int push(STACK *s, int value, int cap)
{
    if (s->Top == cap - 1)
    {
        printf("Stack Overflow.\n");
        return 1;
    }
    else
    {
        s->Top++;
        s->data[s->Top] = value;
        return 0;
    }
}
int pop(STACK *s)
{
    if (s->Top == -1)
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    else
    {
        int res = s->data[s->Top];
        s->Top--;
        return res;
    }
}
int remainingCapacity(STACK s, int cap)
{
    return cap - (s.Top) - 1;
}
void Display(STACK s, int cap)
{
    for (int i = 0; i <= s.Top; i++)
    {
        printf("%d\n", s.data[i]);
    }
    if (remainingCapacity(s, cap) <= 4)
        printf("\nRemaining Stack Capacity : %d\n", remainingCapacity(s, cap));
}
int isEmpty(STACK s)
{
    if (s.Top == -1)
        return 1;
    else
        return 0;
}
int findMax(STACK s)
{
    int m = INT_MIN;
    for (int i = 0; i <= s.Top; i++)
    {
        if (s.data[i] > m)
            m = s.data[i];
    }
    return m;
}

int main()
{
    STACK s1;
    s1.Top = 0;
    int capacity;
    printf("Enter the initial Stack Capacity : ");
    scanf("%d", &capacity);
    s1.data = (int *)malloc(capacity * sizeof(int));
    //Initial it say that the Stack is not empty. to Resolve that below op. is performed.
    pop(&s1);
    int ch, n;
    printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to check isEmpty\nEnter 4 to Find greatest element in Stack\nEnter 0 to terminate.\n");
    do
    {
        if (s1.Top == capacity - 1)
        {
            int choice;
            printf("(Stack~FULL) Do you want to resize the Stack?(1/0) : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
            label:
                printf("Enter New Stack capacity (greater than %d) : ", capacity);
                int prevcap = capacity;
                scanf("%d", &capacity);
                if (capacity > prevcap)
                    realloc(s1.data, capacity);
                else
                    goto label;
            }
        }
        printf("Enter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter Data to Push : ");
            scanf("%d", &n);
            push(&s1, n, capacity);
            Display(s1, capacity);
        }
        else if (ch == 2)
        {
            int x = pop(&s1);
            (x != -1) ? printf("%d popped from the Stack.\n", x) : printf("Invalid operation.\n");
            Display(s1, capacity);
        }
        else if (ch == 3)
        {
            if (isEmpty(s1))
                printf("The Stack is Empty.\n");
            else
                printf("The Stack is not empty.\n");
        }
        else if (ch == 4)
        {
            if (!isEmpty(s1))
                printf("Max data in Stack is %d\n", findMax(s1));
            else
                printf("Stack is empty. Max not Found.\n");
        }
    } while (ch != 0);

    free(s1.data);
    return 0;
}