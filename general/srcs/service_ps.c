//
// Created by Sole Dagger on 8/1/20.
//

#include "push_swap.h"

int         *arr_from_stack(t_stack *stack, int sortOrNot)
{
    int *array;
    int i;

    i = 0;
    if (!(array = malloc(sizeof(int) * stack->len)))
        error_tf("malloc arr_from_stack err!\n", FALSE);
    while (stack)
    {
        array[i] = stack->value;
        stack = stack->previous;
        i++;
    }
    if (sortOrNot)
        ft_quicksort(array, 0, i - 1);
    return (array);
}

void        change_chr(char *string, char f, char c)
{
    int i;

    i = 0;
    while (string[i])
    {
        if (string[i] == f)
            string[i] = c;
        i++;
    }
}

int         binary_search(int *array, int len, int value)
{
    int l;
    int r;
    int m;

    l = 0;
    r = len - 1;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if (array[m] == value)
            return (m);
        if (array[m] < value)
            l = m + 1;
        else
            r = m - 1;
    }

    return (-1);
}

/*
 * Function to check if value in stack
 */
int         exist_in_stack(t_stack *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return TRUE;
        stack = stack->previous;
    }
    return FALSE;
}

int         find_id_max_in_stack(t_stack *stack)
{
    int i;
    int max;
    int maxId;

    i = 0;
    max = stack->value;
    maxId = 0;
    while (stack)
    {
        if (stack->value > max)
        {
            max = stack->value;
            maxId = i;
        }
        i++;
        stack = stack->previous;
    }

    return (maxId);
}