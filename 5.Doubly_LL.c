//Author : Deepansh Dubey.
//Purpose: Insertion & Deletion in Doubly Linked List.
//Date   : 31/12/2020.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int empid;
    char name[15];
    struct node *next;
    struct node *prev;
}
*last, *new_node, *post_node, *ptr;

void add_front()
{
    if (last == NULL)
    {
        last = (struct node *)malloc(sizeof(struct node));
        printf("Enter Employee ID No. : ");
        scanf("%d", &last->empid);
        printf("Enter Name : ");
        scanf("%s", &last->name);
        last->next = NULL;
        last->prev = NULL;
        post_node = last;
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Employee ID No. : ");
        scanf("%d", &new_node->empid);
        printf("Enter Name : ");
        scanf("%s", &new_node->name);
        new_node->next = post_node;
        post_node->prev = new_node;
        new_node->prev = NULL;
        post_node = new_node;
    }
}

void display_list()
{
    if (last == NULL)
    {
        printf("--------------------------------------\n");
        printf("List is empty\n");
        printf("--------------------------------------\n");
    }
    else
    {
        int i = 1;
        ptr = post_node;
        printf("\n\nDoubly Linked list is :-\n\n");
        printf("-------------------------------------------------------\n");
        do
        {
            printf("Node - %d  : Employee ID - %d", i, ptr->empid);
            printf("\n         : Name - %s", ptr->name);
            printf("\n         : Address - %d", ptr);
            printf("\n         : Next - %d \n", ptr->next);
            printf("-------------------------------------------------------\n");
            ptr = ptr->next;
            i++;
        }
        while (ptr != NULL);
    }
}

int delete_end()
{
    if (last == NULL)
    {
        printf("--------------------------------------\n");
        printf("List is empty\n");
        printf("--------------------------------------\n");
        return 0;
    }
    else
    {
        if (last->prev == NULL)
        {
            last = NULL;
        }
        else
        {
            ptr = last->prev;
            ptr->next = NULL;
            last = ptr;
        }
        printf("\n-------------------------------------------\n");
        printf("Deleted Successfully.");
        printf("\n-------------------------------------------\n");
    }
}

void main()
{
    int user_choice;
    do
    {
        printf("\n\n-------------------------------------------\n");
        printf("\t\t User Menu :-\n");
        printf("-------------------------------------------\n\n");
        printf("1. Add Node at Front\n2. Diaplay doubly linked List\n");
        printf("3. Delete Node from End\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
            add_front();
            printf("\n-------------------------------------------\n");
            printf("Node has been Added Successfully.");
            printf("\n-------------------------------------------\n");
            break;
        case 2:
            display_list();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            break;
        default:
            printf("\nPlease enter a valid choice.");
        }
    }
    while (user_choice != 4);
    printf("\n Press any key to exit ...");
    getch();
}