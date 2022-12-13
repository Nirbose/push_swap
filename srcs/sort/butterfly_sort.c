/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:42 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 18:33:53 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_find_pivot(t_stacks *stacks)
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

static void	ft_finish_sort(t_stacks **stacks)
{
	int	i_n;
	int	n;

	while ((*stacks)->size_b > 0)
	{
		n = (*stacks)->size_b;
		i_n = ft_find_index(n, (*stacks)->b);
		if (i_n < (*stacks)->size_b / 2)
			while (get_content((*stacks)->b) != (*stacks)->size_b)
				rb(stacks);
		else
			while (get_content((*stacks)->b) != (*stacks)->size_b)
				rrb(stacks);
		pa(stacks);
	}
}

void	ft_butterfly_sort(t_stacks **stacks)
{
	int	pivo_a;
	int	pivo_b;
	int	pivo_save;
	int	i;

	pivo_a = ft_find_pivot(*stacks);
	pivo_save = pivo_a;
	pivo_b = pivo_a / 2;
	while ((*stacks)->size_a > 0)
	{
		i = 0;
		while (i < pivo_save)
		{
			if ((*stacks)->a == NULL)
				break ;
			if (get_content((*stacks)->a) <= pivo_a)
			{
				pb(stacks);
				i++;
				if (get_content((*stacks)->b) > pivo_a - pivo_b)
					rb(stacks);
			}
			else
				ra(stacks);
		}
		pivo_a += pivo_save;
	}
	ft_finish_sort(stacks);
}
