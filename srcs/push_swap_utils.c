/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:26:19 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/15 16:19:38 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_content(t_list *stack)
{
	int	nbr;

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
