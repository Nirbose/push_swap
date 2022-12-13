/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:20:10 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:44:25 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;
	size_t				i;

	if (dest == 0 && src == 0)
		return (NULL);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	tmp_dest = dest;
	tmp_src = src;
	i = 0;
	while (i < n)
	{
		tmp_dest[n - i - 1] = tmp_src[n - i - 1];
		i++;
	}
	return (dest);
}
