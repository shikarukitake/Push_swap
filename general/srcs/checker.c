/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:15:04 by sdagger           #+#    #+#             */
/*   Updated: 2020/08/03 17:18:19 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*arr_from_stack(t_stack *stack, int sort_or_not)
{
	int	*array;
	int	i;

	i = 0;
	if (!(array = malloc(sizeof(int) * stack->len)))
		ft_error_t("malloc arr_from_stack err!\n");
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->previous;
		i++;
	}
	if (sort_or_not)
		ft_quicksort(array, 0, i - 1);
	return (array);
}

int	main(int ac, char **av)
{
	t_sts	*sts;

	sts = error_tf(NULL, TRUE);
	if (ac == 1)
		return (0);
	else
		read_args(ac, av, sts);
	if (check_dublicates(*(sts->stacka)))
		error_tf("There are dublicates!", FALSE);
	reading_from_stdin(&(sts->darr));
	if (sts->vflag)
	{
		if (sts->cflag)
			ft_printf(COLOR_YELLOW);
		print_stacks(*(sts->stacka), *(sts->stackb));
		if (sts->cflag)
			ft_printf(COLOR_RESET);
	}
	if (sts->darr)
		exec_commands(sts);
	check_sorted(sts);
	free_sts(sts);
	return (0);
}
