/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:24:55 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:44:21 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;
	size_t		i;

	tmp_dest = dest;
	tmp_src = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}
