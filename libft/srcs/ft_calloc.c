/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:16:57 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:42:43 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((int)nmemb < 0 && (int)size < 0)
		return (NULL);
	tab = malloc(nmemb * size);
	i = 0;
	if (tab == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		tab[i] = '\0';
		i++;
	}
	return ((void *)tab);
}
