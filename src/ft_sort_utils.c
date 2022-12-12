/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:24:29 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/30 17:37:04 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_pivot(t_stacks *stacks)
{
	int	div;
	int	pivo;

	div = stacks->size_a / 10 + 15;
	div = stacks->size_a / div;
	if (div == 0)
		div = 3;
	pivo = stacks->size_a / div;
	return (pivo);
}
