/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:50:22 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/28 14:11:08 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_swap(t_list **stack)
{
	int		size;
	char	*tmp;

	size = ft_lstsize(*stack);
	if (size > 1)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
}

void	sa(t_stacks **stacks)
{
	ft_swap(&(*stacks)->a);
	(*stacks)->moves = ft_strappend("sa", (*stacks)->moves);
}

void	sb(t_stacks **stacks)
{
	ft_swap(&(*stacks)->b);
	(*stacks)->moves = ft_strappend("sb", (*stacks)->moves);
}

void	ss(t_stacks **stacks)
{
	sa(stacks);
	sb(stacks);
}
