/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:42:53 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/28 16:11:16 by ltuffery         ###   ########.fr       */
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
	ft_lstclear(&(*stacks)->b, &del);
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
