/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:26:19 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/17 17:32:58 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_content(t_list *stack)
{
	int	nbr;

	if (stack == NULL)
		return (-1);
	nbr = ft_atoi(stack->content);
	return (nbr);
}

int	smart_display_move(char *move, char *next_move)
{
	int	len_move;
	int	len_next_move;

	if (next_move == NULL)
		return (0);
	len_move = ft_strlen(move);
	len_next_move = ft_strlen(next_move);
	if (move[0] == next_move[0] && len_next_move == len_move && move[0] != 'p')
	{
		if (move[len_move - 1] == next_move[len_next_move - 1] + 1)
			return (1);
		if (move[len_move - 1] + 1 == next_move[len_next_move - 1])
			return (1);
	}
	return (0);
}

int	ft_is_sort(t_list *stack)
{
	while (stack != NULL)
	{
		if (stack->next != NULL)
			if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
				return (0);
		stack = stack->next;
	}
	return (1);
}
