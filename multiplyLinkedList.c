#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void add_start(node **start, int val)
{
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    if (*start == NULL)
    {
        *start = newnode;
        (*start)->next = NULL;
    }
    else
    {
        newnode->next = *start;
        *start = newnode;
    }
}

void display(node *start)
{
    node *temp;
    temp = start;
    printf("Content of the list are : \n");
    if (start == NULL)
    {
        printf("Empty List\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d", temp->data);
            if (temp->next)
                printf("->");
            temp = temp->next;
        }
        printf("\n");
    }
}

void multiplyList(node *first, node *second)
{
    int num1 = 0, num2 = 0;
    while (first || second)
    {

        if (first)
        {
            num1 = (num1)*10 + first->data;
            first = first->next;
        }

        if (second)
        {
            num2 = (num2)*10 + second->data;
            second = second->next;
        }
    }
    printf("num1 : %ld\n", num1);
    printf("num2 : %ld\n", num2);
    printf("\nResult : %d", num1 * num2);
}

int main()
{
    node *firstHead = NULL;
    node *secondHead = NULL;

    int s1, s2, val;
    printf("Enter length of first number : ");
    scanf("%d", &s1);
    for (int i = 0; i < s1; i++)
    {
        printf("Enter number at [%d] : ", i);
        scanf("%d", &val);
        add_start(&firstHead, val);
    }
    display(firstHead);
    printf("Enter length of second number : ");
    scanf("%d", &s2);
    for (int j = 0; j < s2; j++)
    {
        printf("Enter number at [%d] : ", j);
        scanf("%d", &val);
        add_start(&secondHead, val);
    }
    display(secondHead);

    multiplyList(firstHead, secondHead);
}