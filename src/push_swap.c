/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:20:37 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/21 15:58:19 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_check_error(t_list *lst)
{
	long	nbr;

	while (lst != NULL)
	{
		nbr = ft_atol(lst->content);
		if (ft_has_alpha(lst->content) == 1)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		if (nbr > 2147483647 || nbr < -2147483648)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		if (ft_exist_in(lst->content, lst) == 1)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

static char	*ft_regroups(int ac, char **av)
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

t_list	*ft_parsing(char *params)
{
	char	**tab;
	t_list	*stack_a;
	int		i;

	tab = ft_split(params, ' ');
	i = 0;
	if (tab == NULL)
	{
		free(params);
		return (NULL);
	}
	stack_a = ft_convert_tab_to_lst(tab);
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(params);
	if (ft_check_error(stack_a) == 1)
	{
		ft_clean_stack(stack_a);
		return (NULL);
	}
	return (stack_a);
}

int	ft_is_sort(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next != NULL)
		{
			if (ft_atoi(lst->content) > ft_atoi(lst->next->content))
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*str;
	t_list	*stack_a;

	if (ac == 1)
		return (0);
	str = ft_regroups(ac, av);
	if (str == NULL)
		return (0);
	stack_a = ft_parsing(str);
	if (stack_a == NULL)
	{
		ft_clean_stack(stack_a);
		return (1);
	}
	if (ft_is_sort(stack_a) == 0)
		ft_start_sort(stack_a);
	ft_clean_stack(stack_a);
}
