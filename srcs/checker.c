/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:28:35 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/16 20:19:45 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/get_next_line.h"
#include "../libft/includes/libft.h"
#include "../includes/ft_parsing.h"
#include "../includes/clean.h"
#include "../includes/utils.h"

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
	(void)instruction;
	return (0);
}

static void	read_line(t_stacks **stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(0);
		if (run(line, stacks) == -1)
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
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
	ft_clean_stack(stack_a);
	read_line(&stacks);
}
