/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:42:53 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/25 13:08:45 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_start_sort(t_list *stack_a)
{
	int		stack_a_size;

	stack_a_size = ft_lstsize(stack_a);
	if (stack_a_size == 2)
		ft_swap(&stack_a, "sa");
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
