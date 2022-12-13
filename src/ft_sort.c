/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:42:53 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/12 15:35:48 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_three_item(t_stacks **stacks)
{
	ft_normalize(&(*stacks)->a);
	if (ft_is_sort((*stacks)->a) == 1)
		return ;
	if (ft_atoi((*stacks)->a->content) == 1)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (ft_atoi((*stacks)->a->content) == 2)
	{
		if (ft_atoi((*stacks)->a->next->content) == 1)
			sa(stacks);
		else
			rra(stacks);
	}
	else
	{
		if (ft_atoi((*stacks)->a->next->content) == 1)
			rra(stacks);
		else
			sa(stacks);
		rra(stacks);
	}
}

void	ft_min_sort(t_stacks **stacks)
{
	int	n;
	int	i;

	n = 1;
	while ((*stacks)->size_b != 2)
	{
		i = ft_search_index(n, (*stacks)->a);
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

void	ft_start_sort(t_stacks **stacks)
{
	ft_normalize(&(*stacks)->a);
	if ((*stacks)->size_a == 2)
	{
		sa(stacks);
	}
	else if ((*stacks)->size_a == 3)
	{
		ft_sort_three_item(stacks);
	}
	else if ((*stacks)->size_a < 6)
	{
		ft_min_sort(stacks);
	}
	else
		ft_sort(stacks);
	ft_lstclear(&(*stacks)->b, &del);
}

void	ft_sort(t_stacks **stacks)
{
	int	pivo_a;
	int	save_pivo;
	int	pivo_b;
	int	i;

	pivo_a = ft_find_pivot(*stacks);
	save_pivo = pivo_a;
	pivo_b = pivo_a / 2;
	while ((*stacks)->size_a > 0)
	{
		i = 0;
		while (i < save_pivo)
		{
			if ((*stacks)->a == NULL)
				break ;
			if (ft_atoi((*stacks)->a->content) <= pivo_a)
			{
				pb(stacks);
				i++;
				if (ft_atoi((*stacks)->b->content) > pivo_a - pivo_b)
					rb(stacks);
			}
			else
				ra(stacks);
		}
		pivo_a += save_pivo;
	}
	ft_finish_sort(stacks);
}

void	ft_finish_sort(t_stacks **stacks)
{
	int	i_n;
	int	n;

	while ((*stacks)->size_b > 0)
	{
		n = (*stacks)->size_b;
		i_n = ft_search_index(n, (*stacks)->b);
		if (i_n < (*stacks)->size_b / 2)
			while (ft_atoi((*stacks)->b->content) != (*stacks)->size_b)
				rb(stacks);
		else
			while (ft_atoi((*stacks)->b->content) != (*stacks)->size_b)
				rrb(stacks);
		pa(stacks);
	}
}
