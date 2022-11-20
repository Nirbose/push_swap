/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:25:08 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:46:30 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;
	size_t				i;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	return (0);
}
