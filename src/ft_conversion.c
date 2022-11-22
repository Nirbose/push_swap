/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:25:35 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/21 15:29:46 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

t_list	*ft_convert_tab_to_lst(char **tab)
{
	t_list	*lst;
	int		i;

	lst = ft_lstnew(ft_strdup(tab[0]));
	i = 1;
	while (tab[i] != NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(tab[i])));
		i++;
	}
	return (lst);
}
