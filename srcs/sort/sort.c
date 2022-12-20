/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:31:05 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/20 18:54:56 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

#define PIVOTDIFF 27

static int	ft_find_pivot(t_stacks *stacks)
{
	int	pivot;

	pivot = stacks->size_a / 5 - PIVOTDIFF;
	if (pivot < 0)
		return (pivot + PIVOTDIFF);
	else
		return (pivot);
}

void	ft_start_sort(t_stacks **stacks)
{
	int	pivot_a;

	pivot_a = ft_find_pivot(*stacks);
	ft_normalize(&(*stacks)->a);
	if ((*stacks)->size_a == 2)
		sa(stacks);
	else if ((*stacks)->size_a < 6)
		ft_small_sort(stacks);
	else
		ft_butterfly_sort(stacks, pivot_a, pivot_a / 2);
}
