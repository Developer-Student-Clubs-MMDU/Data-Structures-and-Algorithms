#include <stdio.h>
#include <stdlib.h>

/*APPROACH :

Input two linked lists.
Traverse the two linked lists to generate the required numbers.
Print the multiplied values of the two numbers.  
Not storing the value of the result or creating new list , hence no extra space used.
*/

/*
EXPLAINATION -

1) Start
2) Create two heads for each linked list
3) Input the numbers in reverse order and insert at beginning of the linked list
4) Set two variables num1 and num2 to 0
5) Start traversing the linked list
6) Add the value of first node of each linked list to respective variable
7) From the second node, multiply the variable by 10
   and also take modulus of this value
   and then add the value of the node to this 
   variable.
8) Repeat step 6 until we reach the last node of the list.
9) Print the multiplied values of the two numbers.
10) End.
*/

typedef struct Node //create link list node
{
    int data;
    struct Node *next;
} node;

void add_start(node **start, int val) //insert node at start to reduce traversal time
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

void display(node *start) //display the linked list
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

void multiplyList(node *first, node *second)  //function multiply the two list
{
    int num1 = 0, num2 = 0;
    while (first || second)
    {

        if (first)
        {
            num1 = (num1)*10 + first->data; //linked list converted into decimal number
            first = first->next;
        }

        if (second)
        {
            num2 = (num2)*10 + second->data; //linked list converted into decimal number
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