/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:42 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/17 17:31:35 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_smart_insert(t_stacks **stacks)
{
	t_list	*last_a;

	last_a = ft_lstlast((*stacks)->a);
	if (get_content(last_a) == (*stacks)->total_items)
	{
		pa(stacks);
		ra(stacks);
		return (1);
	}
	else if (get_content(last_a) < get_content((*stacks)->b))
	{
		pa(stacks);
		ra(stacks);
		return (1);
	}
	return (0);
}

static void	ft_fetch_number(int n, t_stacks **stacks)
{
	int		index_of_n;

	index_of_n = ft_find_index(n, (*stacks)->b);
	if (index_of_n == -1)
		rra(stacks);
	else
	{
		while (get_content((*stacks)->b) != n)
		{
			if (ft_smart_insert(stacks) == 0)
			{
				if (index_of_n > n / 2)
					rrb(stacks);
				else
					rb(stacks);
			}
		}
		pa(stacks);
	}
}

static void	ft_finish_sort(t_stacks **stacks)
{
	int	n;

	n = (*stacks)->size_b;
	while (n > 0)
	{
		ft_fetch_number(n, stacks);
		n--;
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
