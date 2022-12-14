/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:48:44 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 17:16:52 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push(t_list **to, t_list **in)
{
	t_list	*tmp;

	tmp = *to;
	*to = (*to)->next;
	tmp->next = NULL;
	ft_lstadd_front(in, tmp);
}

void	pa(t_stacks **stacks)
{
	if ((*stacks)->size_b != 0)
	{
		ft_push(&(*stacks)->b, &(*stacks)->a);
		(*stacks)->size_b -= 1;
		(*stacks)->size_a += 1;
		(*stacks)->moves = ft_strappend("pa", (*stacks)->moves);
	}
}

void	pb(t_stacks **stacks)
{
	if ((*stacks)->size_a != 0)
	{
		ft_push(&(*stacks)->a, &(*stacks)->b);
		(*stacks)->size_b += 1;
		(*stacks)->size_a -= 1;
		(*stacks)->moves = ft_strappend("pb", (*stacks)->moves);
	}
}
