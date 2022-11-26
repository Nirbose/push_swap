/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:46 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/26 12:57:41 by ltuffery         ###   ########.fr       */
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
	*to = (*to)->next;
	tmp->next = NULL;
	ft_lstadd_back(in, tmp);
}

void	ft_rotate(t_list **stack)
{
	t_list	*first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

t_list	*ft_b(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_reverse(t_list **stack)
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
