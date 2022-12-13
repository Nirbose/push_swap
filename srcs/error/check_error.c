/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:44:01 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 16:23:02 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"

static int	ft_has_invalid_sign(char *item)
{
	int	i;

	i = 1;
	if (item[0] == '+' || item[0] == '-')
		if (ft_isdigit(item[i]) == 0)
			return (1);
	while (item[i] != '\0')
	{
		if (item[i] == '+' || item[i] == '-')
			if (item[i - 1] != ' ')
				return (1);
		i++;
	}
	return (0);
}

static int	ft_already_exist(char *item, t_list *lst)
{
	int	nbr;

	nbr = ft_atoi(item);
	while (lst != NULL)
	{
		if (nbr == ft_atoi(lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}

static int	ft_has_invalid_char(char *item)
{
	int	i;

	i = 0;
	while (item[i] != '\0')
	{
		if (ft_isdigit(item[i]) == 0)
			if (item[i] != '-' && item[i] != '+')
				return (1);
		i++;
	}
	return (0);
}

static int	ft_not_content_in_int(char *item)
{
	long	nbr;

	nbr = ft_atol(item);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
	return (0);
}

int	ft_has_error(t_list *lst)
{
	while (lst != NULL)
	{
		if (ft_has_invalid_sign(lst->content) == 1)
			return (1);
		if (ft_has_invalid_char(lst->content) == 1)
			return (1);
		if (ft_not_content_in_int(lst->content) == 1)
			return (1);
		if (ft_already_exist(lst->content, lst->next) == 1)
			return (1);
		lst = lst->next;
	}
	return (0);
}
