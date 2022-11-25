/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:54:37 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/25 12:47:39 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

int	ft_has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 && str[i] != '-' && str[i] != '+')
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
		if (ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_has_duplicate(char *content, t_list *stack)
{
	int	nbr;

	nbr = ft_atoi(content);
	while (stack != NULL)
	{
		if (nbr == ft_atoi(stack->content))
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_invalid_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			if (str[i - 1] != ' ')
				return (1);
		i++;
	}
	return (0);
}
