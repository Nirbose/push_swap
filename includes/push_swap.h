/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:11:29 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 13:48:50 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
t_list	*ft_parsing(char *params, int ac, char **av);

/*	ERROR	*/
int		ft_has_error(t_list *lst);

/*	CLEAN	*/
void	ft_clean_stack(t_list *stack);
void	ft_clean_tab(char **tab);
void	ft_clean_all_stacks(t_stacks *stacks);

#endif
