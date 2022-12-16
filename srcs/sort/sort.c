/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:31:05 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/16 17:43:51 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_find_pivot(t_stacks *stacks)
{
	int	pivot;
	int	diff;

	diff = 27;
	pivot = stacks->size_a / 5 - diff;
	if (pivot < 0)
		return (pivot + diff);
	else
		return (pivot);
}

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
	int	pivo_a;

	pivo_a = ft_find_pivot(*stacks);
	ft_normalize(&(*stacks)->a);
	if ((*stacks)->size_a == 2)
		sa(stacks);
	else if ((*stacks)->size_a < 6)
		ft_small_sort(stacks);
	else
		ft_butterfly_sort(stacks, pivo_a, pivo_a / 2);
}
