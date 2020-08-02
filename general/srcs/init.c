//
// Created by Sole Dagger on 8/1/20.
//

#include "push_swap.h"

t_chunks    *init_chunks(int len)
{
    t_chunks *chunks;

    if (!(chunks = malloc(sizeof(t_chunks))))
        error_tf("init_chunks malloc", FALSE);
    if (!(chunks->array = malloc(sizeof(int) * (len + 1))))
        error_tf("init_chunks malloc", FALSE);
    if (!(chunks->chunk = malloc(sizeof(int) * (len + 1))))
        error_tf("init_chunks malloc", FALSE);
    chunks->current_c = 0;

    return chunks;
}

void        init_chunks_comm(t_sts *sts, int how_many_chunks)
{
    if (how_many_chunks != FALSE)
        sts->chunks = fill_chunks(*(sts->stackA), how_many_chunks);
    if (!(sts->comm = (t_command*)malloc(sizeof(t_command))))
        error_tf("initSts malloc ft_error", FALSE);
}