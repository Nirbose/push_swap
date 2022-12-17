/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:33:08 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/17 14:34:51 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
	char	**moves;
	int		total_items;
}	t_stacks;

/*	PARSING	*/
t_list	*ft_parsing(int ac, char **av);

/*	CLEAN	*/
void	ft_clean_stack(t_list *stack);
void	ft_clean_tab(char **tab);
void	ft_clean_all_stacks(t_stacks *stacks);

#endif
