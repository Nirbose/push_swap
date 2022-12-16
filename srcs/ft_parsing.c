/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:08:23 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/16 18:51:25 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/clean.h"

static int	ft_isempty(char *str)
{
	char	*trim;
	int		is_empty;

	trim = ft_strtrim(str, " ");
	is_empty = 0;
	if (trim[0] == '\0')
		is_empty = 1;
	free(trim);
	return (is_empty);
}

static t_list	*ft_convert_tab_to_lst(char **tab)
{
	t_list	*lst;
	char	*dup;
	int		i;

	i = 1;
	dup = ft_strdup(tab[0]);
	if (dup == NULL)
		return (NULL);
	lst = ft_lstnew(dup);
	while (tab[i] != NULL)
	{
		dup = ft_strdup(tab[i]);
		if (dup == NULL)
			return (NULL);
		ft_lstadd_back(&lst, ft_lstnew(dup));
		i++;
	}
	return (lst);
}

static int	ft_check_empty_item(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_isempty(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
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

t_list	*ft_parsing(int ac, char **av)
{
	t_list	*stack_a;
	char	*params;
	char	**tab;

	params = ft_regroup(ac, av);
	if (params == NULL)
		return (NULL);
	tab = ft_split(params, ' ');
	free(params);
	if (tab == NULL)
		return (NULL);
	stack_a = ft_convert_tab_to_lst(tab);
	ft_clean_tab(tab);
	if (stack_a == NULL)
		return (NULL);
	if (ft_check_empty_item(ac, av) == 1 || ft_has_error(stack_a) == 1)
	{
		ft_putendl_fd("Error", 2);
		ft_clean_stack(stack_a);
		return (NULL);
	}
	return (stack_a);
}
