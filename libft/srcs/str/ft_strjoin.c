/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:48:15 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:45:09 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	new_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	while (i < s2_len)
	{
		new_str[s1_len + i] = s2[i];
		i++;
	}
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}
