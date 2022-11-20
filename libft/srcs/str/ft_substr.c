/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:02:30 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:46:45 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_str = malloc(1);
		new_str[0] = '\0';
		return (new_str);
	}
	if (ft_strlen(s) > len)
		new_str = malloc(sizeof(char) * (len + 1));
	else
		new_str = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s) && s[start + i])
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
