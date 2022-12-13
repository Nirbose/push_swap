/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:53:33 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 14:14:39 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/push_swap.h"

static void	ft_display_moves(char **moves)
{
	int	i;

	i = 0;
	if (moves == NULL)
		return ;
	while (moves[i] != NULL)
	{
		ft_putendl_fd(moves[i], 1);
		i++;
	}
}

static char	*ft_regroup(int ac, char **av)
{
	char	*base;
	char	*next;
	int		i;

	if (ac > 2)
	{
		base = ft_calloc(1, 1);
		i = 1;
		while (i < ac)
		{
			next = ft_strjoin(base, av[i]);
			free(base);
			if (next == NULL)
				return (NULL);
			base = ft_strjoin(next, " ");
			free(next);
			if (base == NULL)
				return (NULL);
			i++;
		}
	}
	else
		base = ft_strdup(av[1]);
	return (base);
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
	char		*params;
	t_list		*stack_a;
	t_stacks	*stacks;

	if (ac == 1)
		return (0);
	params = ft_regroup(ac, av);
	if (params == NULL)
		return (0);
	free(params);
	stack_a = ft_parsing(params, ac, av);
	if (stack_a == NULL)
	{
		ft_clean_stack(stack_a);
		exit(1);
	}
	else
	{
		stacks = ft_create_stacks(stack_a);
		ft_display_moves(stacks->moves);
		ft_clean_all_stacks(stacks);
	}
}
