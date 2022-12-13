/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:44 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 13:48:28 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../../includes/push_swap.h"

static void	del(void *content)
{
	free(content);
}

void	ft_clean_stack(t_list *stack)
{
	ft_lstclear(&stack, &del);
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

void	ft_clean_all_stacks(t_stacks *stacks)
{
	ft_clean_stack(stacks->a);
	ft_clean_stack(stacks->b);
	ft_clean_tab(stacks->moves);
	free(stacks);
}
