/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:15:41 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 20:12:58 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

void	del(void *content)
{
	free(content);
}

void	ft_free_node(t_list *lst)
{
	ft_lstclear(&lst, &del);
}
