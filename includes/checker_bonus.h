/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:33:08 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/20 20:44:27 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

/*	MOVES	*/
void	pa(t_stacks **stacks);
void	pb(t_stacks **stacks);
void	sa(t_stacks **stacks);
void	sb(t_stacks **stacks);
void	ss(t_stacks **stacks);
void	ra(t_stacks **stacks);
void	rb(t_stacks **stacks);
void	rr(t_stacks **stacks);
void	rra(t_stacks **stacks);
void	rrb(t_stacks **stacks);
void	rrr(t_stacks **stacks);

/*	UTILS	*/
int		ft_is_sort(t_list *stack);

#endif
