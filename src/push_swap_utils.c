/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:46 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/28 16:51:09 by ltuffery         ###   ########.fr       */
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

int	ft_who_nearset(t_list *stack, int n_min, int n_max)
{
	int		i;
	int		n;
	int		is_rigth;
	int		stack_size;
	t_list	*tmp;

	stack_size = ft_lstsize(stack);
	n = stack_size + 1;
	tmp = stack;
	while (n_min < n_max)
	{
		i = 0;
		while (tmp != NULL)
		{
			if (i > stack_size / 2)
			{
				if (n > (stack_size / 2 - i))
				{
					n = (stack_size / 2 - i);
					is_rigth = 1;
				}
			}
			else
			{
				if (n > i)
				{
					n = i;
					is_rigth = 0;
				}
			}
			i++;
			tmp = tmp->next;
		}
		n_min++;
	}
	if (is_rigth == 1)
		n = n + stack_size / 2;
	i = 0;
	while (i < n)
	{
		stack = stack->next;
		i++;
	}
	n = ft_atoi(stack->content);
	return (n);
}
