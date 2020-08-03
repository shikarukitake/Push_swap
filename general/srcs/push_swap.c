/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 19:10:32 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/02 16:26:45 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_sts *sts)
{
	char	*commands;
	int		stack_len;

	stack_len = (*(sts->stackA))->len;
	commands = NULL;
	if (stack_len == 2)
		sort_two(sts);
	else if (stack_len == 3)
		commands = sort_three(sts, 0);
	else if (stack_len <= 5)
		commands = sort_five(sts);
	else if (stack_len <= 100)
		commands = sort_all(5, sts);
	else if (stack_len <= 500)
		commands = sort_all(11, sts);
	else
		commands = sort_all(30, sts);
	ft_printf("%s", commands);
}





int		main(int argc, char **argv)
{
	t_sts			*sts;

	sts = error_tf(NULL, TRUE);
	if (argc == 1)
		return (0);
	else
		read_args(argc, argv, sts);
	sts->vflag = 0;
	if (check_dublicates(*(sts->stackA)))
		error_tf("There are dublicates\n", FALSE);
	if (!stack_is_sorted(*(sts->stackA)))
		sort_stack(sts);
	free_sts(sts);
	return (0);
}
