/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:25:35 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/28 12:27:21 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_normalize(t_list **stack)
{
	t_list	*tmp;
	t_list	*temp;
	t_list	*new;
	int		count;

	tmp = *stack;
	new = NULL;
	while (tmp != NULL)
	{
		temp = *stack;
		count = 1;
		while (temp != NULL)
		{
			if (ft_atoi(tmp->content) > ft_atoi(temp->content))
				count++;
			temp = temp->next;
		}
		ft_lstadd_back(&new, ft_lstnew(ft_itoa(count)));
		tmp = tmp->next;
	}
	ft_clean_stack(*stack);
	*stack = new;
}

void	ft_normalize_by_nb(t_list **stack, int nb)
{
	t_list	*tmp;
	int		new_content;

	tmp = *stack;
	while (tmp != NULL)
	{
		new_content = ft_atoi(tmp->content) + nb;
		free(tmp->content);
		tmp->content = ft_itoa(new_content);
		tmp = tmp->next;
	}
}
