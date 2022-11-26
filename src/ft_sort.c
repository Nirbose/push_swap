/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:42:53 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/26 12:59:11 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_start_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		stack_a_size;
	t_list	*v;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b = NULL;
	if (stack_a_size == 2)
		ft_swap(stack_a, "sa");
	else
	{
		ft_putendl_fd((*stack_a)->content, 1);
		ft_rotate(stack_a);
		v = *stack_a;
		while (v != NULL)
		{
			ft_putendl_fd(v->content, 1);
			v = v->next;
		}
	}
}

int	ft_is_sort(t_list *stack_a)
{
	while (stack_a != NULL)
	{
		if (stack_a->next != NULL)
		{
			if (ft_atoi(stack_a->content) > ft_atoi(stack_a->next->content))
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}
