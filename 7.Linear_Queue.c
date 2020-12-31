//Author : Deepansh Dubey.
//Purpose: Insertion & Deletion in Linear Queue.
//Date   : 31/12/2020.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}
*front, *rear, *ptr;

void insert()
{
    int da_ta;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n ------------------------------------------------");
        printf("\n Queue is Overflown.");
    }
    else
    {
        printf("\n\n Enter Data : ");
        scanf("%d", &da_ta);
        ptr->data = da_ta;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
        printf("\n ------------------------------------------------");
        printf("\n  Data has been inserted successfully.");
    }
    printf("\n ------------------------------------------------");
}

void delete_head()
{
    printf("\n ------------------------------------------------");
    if (front == NULL)
    {
        printf("\n  Queue is EMPTY !!!");
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
        printf("\n  Deleted successfully.");
    }
    printf("\n ------------------------------------------------");
}

void display_queue()
{
    int i = 1;
    ptr = front;
    printf("\n ------------------------------------------------");
    if (front == NULL)
    {
        printf("\n  Queue is EMPTY.");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\n  Node %d : %d", i, ptr->data);
            ptr = ptr->next;
            i++;
        }
    }
    printf("\n ------------------------------------------------");
}

int cal_count()
{
    int i = 0;
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        i = 0;
    }
    else
    {
        while (ptr != NULL)
        {
            i++;
            ptr = ptr->next;
        }
    }
    return i;
}

int main()
{
    int user_choice = 0, d, count = 0;
    do
    {
        count = cal_count();
        printf("\n\n 1. Enter Data           ----------");
        printf("\n 2. Display Queue        | Status |");
        printf("\n 3. Delete Head          | (%d/NA) |", count);
        printf("\n 4. Quit                 ----------");
        printf("\n\n Enter your choice : ");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display_queue();
            break;
        case 3:
            delete_head();
            break;
        case 4:
            break;
        default:
            printf("\n -------------------------------------------------");
            printf("\n  Please enter a valid input.");
            printf("\n -------------------------------------------------");
        }
    }
    while (user_choice != 4);
    printf("\n\n Press any key to exit...");
    return 0;
}