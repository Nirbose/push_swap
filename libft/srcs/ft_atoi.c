/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:34:50 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:35:25 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	total;

	i = 0;
	sign = 1;
	total = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\a' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
		sign *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		total = total * 10 + (nptr[i] - '0');
		if (total * sign > 2147483647)
			return (-1);
		if (total * sign < -2147483648)
			return (0);
		i++;
	}
	return (total * sign);
}
