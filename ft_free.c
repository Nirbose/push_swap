/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:41 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 16:21:58 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	del(void *content)
{
	free(content);
}

void	ft_free_node(t_list *lst)
{
	ft_lstclear(&lst, &del);
}
