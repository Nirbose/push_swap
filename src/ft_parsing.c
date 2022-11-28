/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:36:07 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/28 14:39:09 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_check_error(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (ft_has_alpha(str) == 1 || ft_has_digit(str) == 0)
		return (1);
	if (ft_invalid_sign(str) == 1)
		return (1);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
	return (0);
}

static int	ft_error(int ac, char **av, t_list *stack)
{
	int		i;
	char	*trim;
	int		error;

	i = 1;
	error = 0;
	while (i < ac)
	{
		trim = ft_strtrim(av[i], " ");
		if (trim[0] == '\0')
			error = 1;
		free(trim);
		i++;
	}
	while (stack != NULL)
	{
		if (ft_check_error(stack->content) == 1)
			return (1);
		if (ft_has_duplicate(stack->content, stack->next) == 1)
			return (1);
		stack = stack->next;
	}
	return (error);
}

char	*ft_regroups(int ac, char **av)
{
	int		i;
	char	*str;
	char	*base;

	base = ft_calloc(1, 1);
	if (ac == 2)
	{
		str = ft_strdup(av[1]);
		free(base);
		return (str);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			str = ft_strjoin(base, av[i]);
			free(base);
			base = ft_strjoin(str, " ");
			free(str);
			i++;
		}
	}
	return (base);
}

t_list	*ft_parsing(char *params, int ac, char **av)
{
	char	**tab;
	t_list	*stack_a;

	tab = ft_split(params, ' ');
	free(params);
	if (tab == NULL)
		return (NULL);
	stack_a = ft_convert_tab_to_lst(tab);
	ft_clean_tab(tab);
	if (stack_a == NULL)
		return (NULL);
	if (ft_error(ac, av, stack_a) == 1)
	{
		ft_putendl_fd("Error", 2);
		ft_clean_stack(stack_a);
		return (NULL);
	}
	return (stack_a);
}
