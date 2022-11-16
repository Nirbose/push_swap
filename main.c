/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:20:37 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/16 21:23:12 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

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

	str = ft_calloc(1, 1);
	if (ac == 2)
	{
		str = ft_strdup(av[1]);
		return (str);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			str = ft_strjoin(str, av[i]);
			str = ft_strjoin(str, " ");
			i++;
		}
	}
	return (str);
}

static t_list	*ft_create_list(char **tab)
{
	t_list	*lst;
	int		i;

	lst = ft_lstnew(tab[0]);
	i = 1;
	while (tab[i] != NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew(tab[i]));
		i++;
	}
	return (lst);
}

int	main(int ac, char **av)
{
	char	*str;
	char	**tab;
	t_list	*stack_a;

	if (ac == 1)
		return (0);
	str = ft_regroups(ac, av);
	if (str == NULL)
		return (0);
	tab = ft_split(str, ' ');
	if (tab == NULL)
		return (0);
	free(str);
	stack_a = ft_create_list(tab);
	if (ft_check_error(stack_a) == 1)
		return (0);
	free(tab);
	ft_putstr_fd("oui", 1);
}
