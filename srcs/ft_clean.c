/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:41 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/28 15:05:28 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	del(void *content)
{
	free(content);
}

void	ft_clean_stack(t_list *lst)
{
	ft_lstclear(&lst, &del);
}

void	ft_clean_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_clean_stacks(t_stacks *stacks)
{
	ft_clean_stack(stacks->a);
	ft_clean_stack(stacks->b);
	ft_clean_tab(stacks->moves);
	free(stacks);
}
