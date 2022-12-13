/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:03:30 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/12 15:36:40 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_rotate(t_list **stack)
{
	t_list	*first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

void	ra(t_stacks **stacks)
{
	if ((*stacks)->size_a >= 2)
	{
		ft_rotate(&(*stacks)->a);
		(*stacks)->moves = ft_strappend("ra", (*stacks)->moves);
	}
}

void	rb(t_stacks **stacks)
{
	if ((*stacks)->size_b >= 2)
	{
		ft_rotate(&(*stacks)->b);
		(*stacks)->moves = ft_strappend("rb", (*stacks)->moves);
	}
}

void	rr(t_stacks **stacks)
{
	ra(stacks);
	rb(stacks);
}
