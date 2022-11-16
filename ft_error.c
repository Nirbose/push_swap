/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:54:37 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/16 21:05:47 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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

int	ft_exist_in(char *str, t_list *lst)
{
	int	n;

	n = ft_atoi(str);
	lst = lst->next;
	while (lst)
	{
		if (n == ft_atoi(lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}
