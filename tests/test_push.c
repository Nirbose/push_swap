/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:10:01 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/25 13:16:24 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*str;

	str = ft_strdup("1");
	stack_a = ft_lstnew(str);
	stack_b = malloc(sizeof(t_list));
	ft_push(&stack_a, &stack_b);
	printf("%s", (char *)stack_a->content);
	printf("%s", (char *)stack_b->content);
	free(str);
	free(stack_a);
	free(stack_b);
}
