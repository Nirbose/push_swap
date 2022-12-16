/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:42 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/15 16:44:48 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_finish_sort(t_stacks **stacks)
{
	int	n;
	int	index_of_n;
	int	swap;

	while ((*stacks)->size_b > 0)
	{
		swap = 0;
		n = (*stacks)->size_b;
		index_of_n = ft_find_index(n, (*stacks)->b);
		while (get_content((*stacks)->b) != n)
		{
			if (index_of_n > n / 2)
				rrb(stacks);
			else
				rb(stacks);
			if (get_content((*stacks)->b) == n - 1 && swap == 0)
			{
				pa(stacks);
				swap = 1;
			}
		}
		pa(stacks);
		if (swap == 1)
			sa(stacks);
	}
}

void	ft_butterfly_sort(t_stacks **stacks, int pivo_a, int pivo_b)
{
	int	pivo_save;
	int	i;

	pivo_save = pivo_a;
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
