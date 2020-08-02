/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdagger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:09:09 by sdagger           #+#    #+#             */
/*   Updated: 2019/09/14 15:37:33 by sdagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *swap;

	swap = (unsigned char*)b;
	while (len-- > 0)
	{
		*swap = (unsigned char)c;
		swap++;
	}
	return (b);
}
