/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:42:53 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/21 18:01:16 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_start_sort(t_list *stack_a)
{
	t_list	*stack_b;
	int		stack_a_size;

	stack_a_size = ft_lstsize(stack_a);
	if (stack_a_size == 2)
		ft_swap(&stack_a, "sa");
	(void) stack_b;
}
