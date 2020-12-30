//Author : Deepansh Dubey.
//Purpose: Perform Linear Search and Binary Search on an array.
//Date   : 30/12/2020.

#include <stdio.h>

int i, j, n;
void Input_array(int v[])
{
    printf("\n Please enter the no. of elements :- ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("\n Enter the element number %d : ", i + 1);
        scanf("%d", &v[i]);
    }
}

int Linear_search(int v[], int d)
{
    int pos = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] == d)
        {
            return i + 1;
        }
    }
    return -1;
}

void Sort_array(int v[])
{
    int temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    printf("\n----------------------------");
    printf("\n\n Sorted array is -\n\n |");
    for (i = 0; i < n; i++)
    {
        printf(" %d |", v[i]);
    }
    printf("\n----------------------------");
    printf("\n");
}

int Binary_search(int v[], int d)
{
    int first = 0, middle, last = n - 1;
    while (first <= last)
    {
        middle = first + (last - first) / 2;
        if (v[middle] == d)
        {
            return middle + 1;
        }
        else if (v[middle] < d)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return -1;
}

void main()
{
    int v[50], d, user_choice, k;
    printf("\n\n Input the array elements :-\n");
    Input_array(v);
    printf("\nEnter element to search : ");
    scanf("%d", &d);
    printf("\n\n# Which sorting method to use ?\n");
    printf("\n1. Linear Search\n2. Binary Search");
    printf("\n\n Please enter your choice:-");
    scanf("%d", &user_choice);
    switch (user_choice)
    {
    case 1:
        k = Linear_search(v, d);
        if (k != -1)
        {
            printf("\n Element found at position : %d", k);
        }
        else
        {
            printf("\n Element Not found (%d) !", k);
        }
        break;
    case 2:
        Sort_array(v);
        k = Binary_search(v, d);
        if (k != -1)
        {
            printf("\n Element Found at position : %d", k);
        }
        else
        {
            printf("\n Element Not found (%d) !", k);
        }
        break;
    default:
        printf("\n\n Please enter a valid choice. ");
    }
    printf("\n\n Press any key to exit ...");
    getch();
}