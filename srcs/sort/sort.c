/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:31:05 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 17:55:36 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_sort(t_list *stack)
{
	while (stack != NULL)
	{
		if (stack->next != NULL)
		{
			if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

void	ft_start_sort(t_stacks **stacks)
{
	ft_normalize(&(*stacks)->a);
	if ((*stacks)->size_a == 2)
		sa(stacks);
	else if ((*stacks)->size_a < 6)
		ft_small_sort(stacks);
	else
		ft_butterfly_sort(stacks);
}
