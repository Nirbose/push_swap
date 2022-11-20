/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:20:22 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:46:14 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	size_selected;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (src_len >= size)
		size_selected = size - 1;
	else
		size_selected = src_len;
	while (i < size_selected)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
