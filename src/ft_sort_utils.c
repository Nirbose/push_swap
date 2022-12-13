/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:24:29 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/12 15:11:38 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_pivot(t_stacks *stacks)
{
	int	div;
	int	pivo;

	div = stacks->size_a / 10 + 15;
	div = stacks->size_a / div;
	if (div == 0)
		div = 3;
	pivo = stacks->size_a / div;
	return (pivo);
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
