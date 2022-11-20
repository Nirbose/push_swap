/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:38:59 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:46:41 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_is_in(char const *s, char const c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_get_count_set_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_is_in(set, s1[i]))
		i++;
	return (i);
}

static size_t	ft_get_count_set_end(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_is_in(set, s1[ft_strlen(s1) - i - 1]))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new_str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_get_count_set_start(s1, set);
	end = ft_get_count_set_end(s1, set);
	if (ft_strlen(s1) == start)
		new_str = malloc(sizeof(char));
	else
		new_str = malloc(sizeof(char) * (ft_strlen(s1) - start - end + 1));
	if (new_str == NULL)
		return (NULL);
	while ((start + i) < (ft_strlen(s1) - end))
	{
		new_str[i] = s1[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
