/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:53:03 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:36:03 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**ft_create_word_tab(char const *s, char c)
{
	int		i;
	int		total;
	char	**tab;

	i = 0;
	total = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			total++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	tab = ft_calloc(total + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

static char	**ft_insert_word(char **tab, const char *s, int c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i + len] != c && s[i + len] != '\0')
			len++;
		if (len != 0)
		{
			tab[j] = malloc(sizeof(char) * (len + 1));
			if (tab[j] == NULL)
				return (NULL);
			ft_strlcpy(tab[j], &s[i], len + 1);
			j++;
			i += len;
		}
		else
			i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	**final;

	if (s == NULL)
		return (NULL);
	tab = ft_create_word_tab(s, c);
	if (tab == NULL)
		return (NULL);
	final = ft_insert_word(tab, s, c);
	if (final == NULL)
		return (NULL);
	return (tab);
}
