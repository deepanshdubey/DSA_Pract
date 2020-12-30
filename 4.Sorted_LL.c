//Author : Deepansh Dubey.
//Purpose: Creating a sorted Linked list & performing Insertion, Deletion & Display.
//Date   : 30/12/2020.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
}
*head, *new_node, *pre_node, *ptr;

void Create_LL()
{
    int i = 1;
    char j;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the node %d : ", i);
    scanf("%d", &head->data);
    head->next = NULL;
    pre_node = head;
    printf("\tDo you want to enter more ? (y/n) : ");
    scanf("%s", &j);
    while (j == 'y')
    {
        i++;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data for the node %d : ", i);
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        pre_node->next = new_node;
        pre_node = new_node;
        printf("\tDo you want to enter more ? (y/n) : ");
        scanf("%s", &j);
    }
}

void Display_LL()
{
    int i = 1;
    ptr = head;
    printf("\n\nYour Linked list is :-\n\n");
    printf("--------------------------------------------------------------\n");
    do
    {
        printf("Node - %d | Data - %d | Address - %d |  Next - %d \n",
               i, ptr->data, ptr, ptr->next);
        printf("--------------------------------------------------------------\n");
        ptr = ptr->next;
        i++;
    } while (ptr != NULL);
}

void Add_node()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data of new node : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    pre_node = head;
    do
    {
        if ((new_node->data) < (pre_node->data))
        {
            new_node->next = head;
            head = new_node;
            break;
        }
        else if (new_node->data >= pre_node->data && new_node->data <= (pre_node->next)->data)
        {
            new_node->next = pre_node->next;
            pre_node->next = new_node;
            break;
        }
        else if (pre_node->next == NULL)
        {
            pre_node->next = new_node;
            break;
        }
        pre_node = pre_node->next;
    } while (pre_node != NULL);
    printf("\nNode has been added successfully.\n\n");
}

int Del_node()
{
    int del;
    char user_choice;
    do
    {
        printf("\n\nEnter the data to delete : ");
        scanf("%d", &del);
        pre_node = head;
        do
        {
            if (head == NULL)
            {
                printf("\n List is empty !!!\n");
                return 0;
            }
            else if (pre_node->data == del)
            {
                head = pre_node->next;
                printf("Node with matching data has been deleted successfully.\n");
                if (head == NULL)
                {
                    printf("List is now empty !\n");
                    return 0;
                }
                break;
            }
            else if ((pre_node->next)->data == del)
            {
                pre_node->next = (pre_node->next)->next;
                printf("Node with matching data has been deleted successfully.\n");
                if (head == NULL)
                {
                    printf("\nList is now empty !\n");
                    return 0;
                }
                break;
            }
            else
            {
                pre_node = pre_node->next;
                if (pre_node == NULL)
                {
                    printf("\nElement not found !!!\n");
                }
            }
        } while (pre_node != NULL);
        Display_LL();
        printf("Want to delete more ? (y/n) : ");
        scanf("%s", &user_choice);
    } while (user_choice == 'y');
    return 0;
}

void main()
{
    int user_choice = 0;
    while (user_choice != 5)
    {
        printf("\n----------------------------------------------------\n");
        printf("\n----------------------------------------------------\n\n");
        printf("1. Create a New List.\n");
        printf("2. Display your List.\n");
        printf("3. Add a New Node.\n");
        printf("4. Delete an existing node.\n");
        printf("5. Exit.\n\n");
        printf("Enter your choice : ");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
            Create_LL();
            break;
        case 2:
            Display_LL();
            break;
        case 3:
            Add_node();
            break;
        case 4:
            Del_node();
            break;
        case 5:
            break;
        default:
            printf("\nPlease enter valid choice number !!!\n");
        }
    }
    printf("Press any key to EXIT ...");
    getch();
}