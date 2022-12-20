/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:43:45 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/17 17:32:28 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	ft_find_index(int n, t_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (n == get_content(stack))
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}
