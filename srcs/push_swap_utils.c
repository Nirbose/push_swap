/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:46 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/29 15:53:41 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_stack(t_list *stack)
{
	while (stack != NULL)
	{
		ft_putendl_fd(stack->content, 1);
		stack = stack->next;
	}
}

int	ft_search_index(int n, t_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (n == ft_atoi(stack->content))
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}
