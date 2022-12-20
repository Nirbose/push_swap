/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:28:35 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/20 19:04:52 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"
#include "../includes/checker_bonus.h"

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

static int	run(char *move, t_stacks **stacks)
{
	if (ft_strncmp(move, "sa", 2) == 0 && ft_strlen(move) == 2)
		sa(stacks);
	else if (ft_strncmp(move, "sb", 2) == 0 && ft_strlen(move) == 2)
		sb(stacks);
	else if (ft_strncmp(move, "ss", 2) == 0 && ft_strlen(move) == 2)
		ss(stacks);
	else if (ft_strncmp(move, "rra", 3) == 0 && ft_strlen(move) == 3)
		rra(stacks);
	else if (ft_strncmp(move, "rrb", 3) == 0 && ft_strlen(move) == 3)
		rrb(stacks);
	else if (ft_strncmp(move, "rrr", 3) == 0 && ft_strlen(move) == 3)
		rrr(stacks);
	else if (ft_strncmp(move, "ra", 2) == 0 && ft_strlen(move) == 2)
		ra(stacks);
	else if (ft_strncmp(move, "rb", 2) == 0 && ft_strlen(move) == 2)
		rb(stacks);
	else if (ft_strncmp(move, "rr", 2) == 0 && ft_strlen(move) == 2)
		rr(stacks);
	else if (ft_strncmp(move, "pa", 2) == 0 && ft_strlen(move) == 2)
		pa(stacks);
	else if (ft_strncmp(move, "pb", 2) == 0 && ft_strlen(move) == 2)
		pb(stacks);
	else
		return (-1);
	return (1);
}

static void	read_line(t_stacks **stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (run(line, stacks) == -1)
		{
			ft_putendl_fd("Error", 2);
			free(line);
			ft_clean_all_stacks((*stacks));
			exit(1);
		}
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_stacks	*stacks;

	if (ac < 2)
		return (0);
	stack_a = ft_parsing(ac, av);
	if (stack_a == NULL)
		return (1);
	stacks = ft_create_stacks(stack_a);
	read_line(&stacks);
	if (ft_is_sort(stacks->a) && stacks->size_b == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_clean_all_stacks(stacks);
}
