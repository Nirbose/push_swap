/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:54:37 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/23 18:05:56 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	ft_has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_has_duplicate(int ac, char **av)
{
	int	n;
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		n = ft_atoi(av[i]);
		while (j < ac)
		{
			if (n == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
