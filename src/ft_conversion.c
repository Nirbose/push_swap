/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:25:35 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/22 17:35:41 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

t_list	*ft_convert_tab_to_lst(char **tab)
{
	t_list	*lst;
	int		i;
	char	*dup;

	dup = ft_strdup(tab[0]);
	if (dup == NULL)
		return (NULL);
	lst = ft_lstnew(dup);
	i = 1;
	while (tab[i] != NULL)
	{
		dup = ft_strdup(tab[i]);
		if (dup == NULL)
			return (NULL);
		ft_lstadd_back(&lst, ft_lstnew(dup));
		i++;
	}
	return (lst);
}
