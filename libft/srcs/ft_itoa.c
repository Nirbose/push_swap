/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:34:29 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:35:54 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_get_len_nb(int nb)
{
	int	len;

	len = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	ft_isnegative(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static char	*ft_swap(char *tab)
{
	size_t	len;
	size_t	i;
	char	tmp;

	len = ft_strlen(tab);
	i = 0;
	while (i < len / 2)
	{
		tmp = tab[i];
		tab[i] = tab[len - i - 1];
		tab[len - i - 1] = tmp;
		i++;
	}
	return (tab);
}

static int	ft_insert_nb(char *tab, long long n, int i)
{
	if (n == 0)
	{
		tab[i] = '0';
		return (1);
	}
	while (n != 0)
	{
		tab[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char		*tab;
	int			is_negative;
	int			i;
	long long	n;

	is_negative = 0;
	i = 0;
	n = (long long)nb;
	tab = malloc((ft_get_len_nb(nb) + ft_isnegative(nb) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	if (nb < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	i = ft_insert_nb(tab, n, i);
	if (is_negative)
	{
		tab[i] = '-';
		i++;
	}
	tab[i] = '\0';
	return (ft_swap(tab));
}
