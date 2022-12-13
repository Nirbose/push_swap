/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:25:06 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 17:49:17 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_sort_three_item(t_stacks **stacks)
{
	ft_normalize(&(*stacks)->a);
	if (ft_is_sort((*stacks)->a) == 1)
		return ;
	if (get_content((*stacks)->a) == 1)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (get_content((*stacks)->a) == 2)
	{
		if (get_content((*stacks)->a->next) == 1)
			sa(stacks);
		else
			rra(stacks);
	}
	else
	{
		if (get_content((*stacks)->a->next) == 1)
			rra(stacks);
		else
			sa(stacks);
		rra(stacks);
	}
}

void	ft_small_sort(t_stacks **stacks)
{
	int	n;
	int	i;

	if ((*stacks)->size_a == 3)
		ft_sort_three_item(stacks);
	else
	{
		n = 1;
		while ((*stacks)->size_b != 2)
		{
			i = ft_find_index(n, (*stacks)->a);
			if (i == 0)
				pb(stacks);
			else if (i <= 2)
				ra(stacks);
			else
				rra(stacks);
			if ((*stacks)->size_b == 1 && n == 1)
				n++;
		}
		ft_sort_three_item(stacks);
		ft_normalize_by_nb(&(*stacks)->a, (*stacks)->size_b);
		pa(stacks);
		pa(stacks);
	}
}
