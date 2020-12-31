//Author : Deepansh Dubey.
//Purpose: Insertion & Deletion in Circular Linked List.
//Date   : 31/12/2020.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int rollno;
    char name[15];
    struct node *next;
}
*last, *new_node, *pre_node, *ptr;

void add_front()
{
    if (last == NULL)
    {
        last = (struct node *)malloc(sizeof(struct node));
        printf("Enter Roll No. : ");
        scanf("%d", &last->rollno);
        printf("Enter Name : ");
        scanf("%s", &last->name);
        last->next = last;
        pre_node = last;
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Roll No. : ");
        scanf("%d", &new_node->rollno);
        printf("Enter Name : ");
        scanf("%s", &new_node->name);
        new_node->next = pre_node;
        last->next = new_node;
        pre_node = new_node;
    }
}

void display_circular_LL()
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
        ptr = last->next;
        printf("\n\nLinked list is :-\n\n");
        printf("-------------------------------------------------------\n");
        do
        {
            printf("Node - %d : Roll No. - %d", i, ptr->rollno);
            printf("\n         : Name - %s", ptr->name);
            printf("\n         : Address - %d", ptr);
            printf("\n         : Next - %d \n", ptr->next);
            printf("-------------------------------------------------------\n");
            ptr = ptr->next;
            i++;
        }
        while (ptr != pre_node);
    }
}

int delete_end()
{
    if (last == NULL)
    {
        printf("--------------------------------------\n");
        printf("List is empty.\n");
        printf("--------------------------------------\n");
        return 0;
    }
    else
    {
        if (last->next == last)
        {
            last = NULL;
        }
        else
        {
            ptr = last->next;
            do
            {
                ptr = ptr->next;
                if (ptr->next == last)
                {
                    ptr->next = last->next;
                    free(last);
                    last = ptr;
                    break;
                }
            } while (ptr != pre_node);
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
        printf("1. Add Node at Front.\n2. Diaplay Circular List.\n");
        printf("3. Delete Node from End.\n4. Exit.\n");
        printf("\nEnter your choice : ");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
            add_front();
            printf("\n-------------------------------------------\n");
            printf("Added Successfully.");
            printf("\n-------------------------------------------\n");
            break;
        case 2:
            display_circular_LL();
            break;
        case 3:
            delete_end();
            break;
        case 4:
            break;
        default:
            printf("\nPlease enter a valid choice number.");
        }
    }
    while (user_choice != 4);
    printf("\nPress any key to exit...");
    getch();
}