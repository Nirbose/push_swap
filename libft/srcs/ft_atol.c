/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:18:52 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/20 16:19:08 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	total;

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
		i++;
	}
	return (total * sign);
}
