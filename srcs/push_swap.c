/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:53:33 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/16 18:51:33 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/clean.h"

static void	ft_display_moves(char **moves)
{
	int	i;

	i = 0;
	if (moves == NULL)
		return ;
	while (moves[i] != NULL)
	{
		if (smart_display_move(moves[i], moves[i + 1]) == 1)
		{
			moves[i][ft_strlen(moves[i]) - 1] = moves[i][0];
			ft_putendl_fd(moves[i], 1);
			i++;
		}
		else
			ft_putendl_fd(moves[i], 1);
		i++;
	}
}

static t_stacks	*ft_create_stacks(t_list *stack)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = stack;
	stacks->b = NULL;
	stacks->size_a = ft_lstsize(stack);
	stacks->size_b = 0;
	stacks->moves = NULL;
	stacks->total_items = stacks->size_a;
	return (stacks);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_stacks	*stacks;

	if (ac == 1)
		return (0);
	stack_a = ft_parsing(ac, av);
	if (stack_a == NULL)
	{
		ft_clean_stack(stack_a);
		exit(1);
	}
	else
	{
		stacks = ft_create_stacks(stack_a);
		if (ft_is_sort(stacks->a) == 0)
			ft_start_sort(&stacks);
		ft_display_moves(stacks->moves);
		ft_clean_all_stacks(stacks);
	}
}
