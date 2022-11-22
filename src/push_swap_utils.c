/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:46 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/21 18:16:13 by ltuffery         ###   ########.fr       */
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

void	ft_push(t_list **to, t_list **in, char *push_name)
{
	int		size;
	t_list	*tmp;

	size = ft_lstsize(*to);
	tmp = *to;
	if (size > 1)
	{
		tmp->next = NULL;
		ft_lstadd_front(in, tmp);
		ft_putendl_fd(push_name, 1);
	}
}
