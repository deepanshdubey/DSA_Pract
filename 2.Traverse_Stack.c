//Author : Deepansh Dubey.
//Purpose: Multiple traverse operations on the stack using Linear Linked list.
//Date   : 30/12/2020.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
} * head, *new_node, *ptr;

void push()
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &head->data);
        head->next = NULL;
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &new_node->data);
        new_node->next = head;
        head = new_node;
    }
}

void pop()
{
    if (head == NULL)
    {
        printf("\n Stack Underflow.");
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
        printf("\nPopped Successfully.");
    }
}
void traverse()
{
    if (head == NULL)
    {
        printf("--------------------------------------\n");
        printf("Stack is empty.\n");
        printf("--------------------------------------\n");
    }
    else
    {
        int i = 1;
        ptr = head;
        printf("\n\nStack is :-\n\n");
        printf("---------------------------------------------------------------\n");
        do
        {
            printf("Node - %d | Data - %d | Address - %d |  Next - %d \n",
                   i, ptr->data, ptr, ptr->next);
            printf("---------------------------------------------------------------\n");
            ptr = ptr->next;
            i++;
        } while (ptr != NULL);
    }
}

void main()
{
    int user_choice;
    do
    {
        printf("\n\n-------------------------------------------\n");
        printf("\t\t-: Menu :-\n");
        printf("-------------------------------------------\n\n");
        printf("1. Push\n2. Traverse\n3. Pop\n4. Exit\n");
        printf("\nEnter choice no. : ");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
            push();
            printf("\nPushed Successfully.");
            break;
        case 2:
            traverse();
            break;
        case 3:
            pop();
            break;
        case 4:
            break;
        default:
            printf("\nPlease enter a valid choice.");
        }
    } while (user_choice != 4);
    printf("\nPress any key to exit ...");
    getch();
}