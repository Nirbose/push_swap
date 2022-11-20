/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:01:04 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/19 19:44:54 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	if (s == NULL)
		return (0);
	size = ft_strlen(s);
	write(fd, s, size);
	return (size);
}
