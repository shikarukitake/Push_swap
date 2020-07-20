//
// Created by Sole Dagger on 13/02/2020.
//

#include "checker.h"

void        ft_sa(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("sa:\n");
    swap(stackA);
}

void        ft_sb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("sb:\n");
    swap(stackB);
}

void        ft_ss(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("ss:\n");
    swap(stackA);
    swap(stackB);
}

void        ft_pa(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("pa:\n");
    if (*stackB)
        pushStack(stackA, popStack(stackB));
}

void        ft_pb(t_stack **stackA, t_stack **stackB, int flag)
{
    if (flag)
        printf("pb:\n");
    if (*stackA)
        pushStack(stackB, popStack(stackA));
}