/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:08:23 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/03 23:04:42 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	size_t	size;

	if (s == NULL)
		return (0);
	size = ft_strlen(s);
	write(fd, s, size);
	write(fd, "\n", 1);
	return (size + 1);
}
