/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:20:37 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 11:39:20 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_display_moves(t_stacks *stacks)
{
	int		i;

	i = 0;
	if (stacks->moves == NULL)
		return ;
	while (stacks->moves[i] != NULL)
	{
		ft_putendl_fd(stacks->moves[i], 1);
		i++;
	}
}

static t_stacks	*ft_create_stacks(t_list *stack_a)
{
	t_stacks	*stacks;
	int			size;

	size = ft_lstsize(stack_a);
	stacks = malloc(sizeof(t_stacks));
	stacks->a = stack_a;
	stacks->b = NULL;
	stacks->size_a = size;
	stacks->size_b = 0;
	stacks->moves = NULL;
	stacks->n_items = size;
	return (stacks);
}

int	main(int ac, char **av)
{
	char		*str;
	t_list		*stack_a;
	t_stacks	*stacks;

	if (ac == 1)
		return (0);
	str = ft_regroups(ac, av);
	if (str == NULL)
		return (0);
	stack_a = ft_parsing(str, ac, av);
	if (stack_a == NULL)
	{
		ft_clean_stack(stack_a);
		exit(1);
	}
	else
	{
		stacks = ft_create_stacks(stack_a);
		if (ft_is_sort(stack_a) == 0)
			ft_start_sort(&stacks);
	}
	ft_display_moves(stacks);
	ft_clean_stacks(stacks);
}
