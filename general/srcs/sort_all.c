//
// Created by Sole Dagger on 8/1/20.
//
#include "push_swap.h"

void        sort_end_stackb(t_sts *sts)
{
	int         i;
	char        *commas;
	int         lenOfStack;

	i = find_id_max_in_stack(*(sts->stackB));
	lenOfStack = sts->chunks->len;
	if (i == 0)
		return ;
	sts->comm->command = i <= lenOfStack - i ? "rb " : "rrb ";
	sts->comm->count = i <= lenOfStack - i ? i : lenOfStack - i;
	commas = commands_from_tcomm(sts->comm, NULL);
	if (!(sts->dArr = get_darr_commands(commas)))
		error_tf("sort_end_stackb get_darr_commands malloc error", FALSE);
	exec_commands(sts);
	if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
		error_tf("sort_end_stackb ft_strjoin_free malloc error", FALSE);
}

void        push_to_stackb(t_sts *sts)
{
	char *commas;

	find_holds(sts);
	if (sts->firstHoldI != 0 AND sts->secondHoldI != 0)
	{
		find_comm(sts, (*(sts->stackA))->len);
		commas = commands_from_tcomm(sts->comm, NULL);
		sts->dArr = get_darr_commands(commas);//protect
		exec_commands(sts);
		sts->commands = ft_strjoin_free(sts->commands, commas, 0);
	}
	do_r_or_rr(sts, (*(sts->stackA))->value, "pb ");
}

char        *sort_all(int how_many_chunks, t_sts *sts)
{
	char        *commas;

	init_chunks_comm(sts, how_many_chunks);
	if (!(sts->commands = ft_strdup("")))
		error_tf("sort_all ft_strdup malloc error", FALSE);
	while (sts->chunks->current_c != how_many_chunks)
	{
		if (exists_in_chunk(*(sts->stackA), sts->chunks, sts->chunks->current_c) == FALSE)
			sts->chunks->current_c++;
		if (sts->chunks->current_c != how_many_chunks)
			push_to_stackb(sts);
	}
	sort_end_stackb(sts);
	sts->comm->command = "pa ";
	sts->comm->count = (*(sts->stackB))->len;
	commas = commands_from_tcomm(sts->comm, NULL);
	if (!(sts->dArr = get_darr_commands(commas)))
		error_tf("sort_all get_darr_commands malloc error", FALSE);
	exec_commands(sts);
	if (!(sts->commands = ft_strjoin_free(sts->commands, commas, 0)))
		error_tf("sort_all ft_strjoin_free malloc error", FALSE);
	change_chr(sts->commands, ' ', '\n');
	return (sts->commands);
}

