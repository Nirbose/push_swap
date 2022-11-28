/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:56:19 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/28 14:06:27 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_reverse(t_list **stack)
{
	t_list	*last;
	t_list	*before;

	last = ft_lstlast(*stack);
	before = *stack;
	while (before->next->next != NULL)
		before = before->next;
	ft_lstadd_front(stack, last);
	before->next = NULL;
}

void	rra(t_stacks **stacks)
{
	if ((*stacks)->size_a >= 2)
	{
		ft_reverse(&(*stacks)->a);
		(*stacks)->moves = ft_strappend("rra", (*stacks)->moves);
	}
}

void	rrb(t_stacks **stacks)
{
	if ((*stacks)->size_b >= 2)
	{
		ft_reverse(&(*stacks)->b);
		(*stacks)->moves = ft_strappend("rrb", (*stacks)->moves);
	}
}

void	rrr(t_stacks **stacks)
{
	rra(stacks);
	rrb(stacks);
}
