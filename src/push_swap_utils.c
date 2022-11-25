/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:46 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/25 13:24:09 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_list **stack, char *swap_name)
{
	int		size;
	char	*tmp;

	size = ft_lstsize(*stack);
	if (size > 1)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
		ft_putendl_fd(swap_name, 1);
	}
}

void	ft_push(t_list **to, t_list **in)
{
	t_list	*tmp;

	tmp = *to;
	tmp->next = NULL;
	*to = (*to)->next;
	ft_lstadd_back(in, tmp);
}

void	ft_rotate(t_list **stack)
{
	t_list	*last;

	last = ft_lstlast(*stack);
	last->next = *stack;
	last->next->next = NULL;
	*stack = (*stack)->next;
}
