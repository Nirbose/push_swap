/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:28:35 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/17 17:33:22 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"
#include "../includes/checker.h"

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

static int	run(char *instruction, t_stacks **stacks)
{
	if (ft_strncmp(instruction, "sa", 2) == 0)
		sa(stacks);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		sb(stacks);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
		ss(stacks);
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		rra(stacks);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		rrb(stacks);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		rrr(stacks);
	else if (ft_strncmp(instruction, "ra", 2) == 0)
		ra(stacks);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		rb(stacks);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		rr(stacks);
	else if (ft_strncmp(instruction, "pa", 2) == 0)
		pa(stacks);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
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
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	stacks = ft_create_stacks(stack_a);
	read_line(&stacks);
	if (ft_is_sort(stacks->a) && stacks->size_b == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_clean_all_stacks(stacks);
}
