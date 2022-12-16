/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 01:03:05 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/16 19:15:59 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"
#include "../../includes/libft.h"

char	*ft_join(char *s1, char *s2)
{
	char	*new_str;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&new_str[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	free(s1);
	return (new_str);
}

char	*ft_subline(char *str)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	len = ft_strlen(&str[i]);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(new_str, &str[i], len + 1);
	free(str);
	if (new_str[0] == '\0')
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}
