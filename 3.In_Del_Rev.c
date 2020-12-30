//Author : Deepansh Dubey.
//Purpose: Performing Insertion, Delition & Reversal on a Linked List.
//Date   : 30/12/2020.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int roll_no;
    char name[15];
    struct node *next;
}
*head, *new_node, *pre_node, *ptr;

void addnode()
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Roll No. : ");
        scanf("%d", &head->roll_no);
        printf("Enter the Name : ");
        scanf("%s", &head->name);
        head->next = NULL;
        pre_node = head;
    }
    else
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the Roll No. : ");
        scanf("%d", &new_node->roll_no);
        printf("Enter the Name : ");
        scanf("%s", &new_node->name);
        new_node->next = NULL;
        pre_node->next = new_node;
        pre_node = new_node;
    }
}

void addnode_atpos()
{
    int pos;
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Roll No. : ");
    scanf("%d", &new_node->roll_no);
    printf("Enter the Name : ");
    scanf("%s", &new_node->name);
    int i = 1;
    if (pos == 1)
    {
        new_node->next = head;
        head = new_node;
    }
    ptr = head;
    do
    {
        i++;
        if (pos == i)
        {
            new_node->next = ptr->next;
            ptr->next = new_node;
            printf("\n-------------------------------------------\n");
            printf("Added successfully.");
            printf("\n-------------------------------------------\n");
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    } while (ptr != NULL);
}

void display_list()
{
    if (head == NULL)
    {
        printf("--------------------------------------\n");
        printf("List is empty\n");
        printf("--------------------------------------\n");
    }
    else
    {
        int i = 1;
        ptr = head;
        printf("\n\nLinked list is :-\n\n");
        printf("-------------------------------------------------------\n");
        do
        {
            printf("Node - %d : Roll No. - %d", i, ptr->roll_no);
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

int delete_node()
{
    if (head == NULL)
    {
        printf("--------------------------------------\n");
        printf("List is empty !!!\n");
        printf("--------------------------------------\n");
        return 0;
    }
    else
    {
        int del;
        char c;
        do
        {
            printf("\n\nEnter Roll No. to delete : ");
            scanf("%d", &del);
            pre_node = head;
            do
            {
                if (pre_node->roll_no == del)
                {
                    head = pre_node->next;
                    printf("\n-------------------------------------------\n");
                    printf("Node with matching data deleted successfully.\n");
                    printf("\n-------------------------------------------\n");
                    if (head == NULL)
                    {
                        printf("\n-------------------------------------------\n");
                        printf("List is now empty !");
                        printf("\n-------------------------------------------\n");
                        return 0;
                    }
                    break;
                }
                else if ((pre_node->next)->roll_no == del)
                {
                    pre_node->next = (pre_node->next)->next;
                    printf("Node with matching data deleted successfully.\n");
                    if (head == NULL)
                    {
                        printf("\n-------------------------------------------\n");
                        printf("List is now empty !");
                        printf("\n-------------------------------------------\n");
                        return 0;
                    }
                    break;
                }
                else
                {
                    pre_node = pre_node->next;
                    if (pre_node == NULL)
                    {
                        printf("\n-------------------------------------------\n");
                        printf("Element not found !!!");
                        printf("\n-------------------------------------------\n");
                    }
                }
            } while (pre_node != NULL);
            display_list();
            printf("Do you want to delete more ? (y/n) : ");
            scanf("%s", &c);
        } 
        while (c == 'y');
        return 0;
    }
}

void reverse_list()
{
    if (head != NULL)
    {
        pre_node = head;
        ptr = head->next;
        head = head->next;
        pre_node->next = NULL;
        while (head != NULL)
        {
            head = head->next;
            ptr->next = pre_node;
            pre_node = ptr;
            ptr = head;
        }
        head = pre_node;
        printf("\n-------------------------------------------\n");
        printf("List is Reversed.");
        printf("\n-------------------------------------------\n");
    }
}

void main()
{
    int choice, pos;
    printf("\n\t -: Student Information :-");
    do
    {
        printf("\n\n-------------------------------------------\n");
        printf("\t\t-: Menu :-\n");
        printf("-------------------------------------------\n\n");
        printf("1. Add node\n2. Add node at specific position\n");
        printf("3. Display List\n4. Delete node\n5. Reverse List\n6. Exit\n");
        printf("\nEnter choice no. : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addnode();
            printf("\n-------------------------------------------\n");
            printf("Added Successfully.");
            printf("\n-------------------------------------------\n");
            break;
        case 2:
            addnode_atpos();
            break;
        case 3:
            display_list();
            break;
        case 4:
            delete_node();
            break;
        case 5:
            reverse_list();
        case 6:
            break;
        default:
            printf("\nPlease enter valid choice number !!!");
        }
    } while (choice != 6);
    printf("\nPress any key to EXIT ...");
    getch();
}