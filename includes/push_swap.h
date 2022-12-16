/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:11:29 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/16 18:54:04 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "ft_parsing.h"
# include "utils.h"

/*	ERROR	*/
int		ft_has_error(t_list *lst);

/*	SORT	*/
void	ft_start_sort(t_stacks **stacks);
int		ft_is_sort(t_list *stack);
void	ft_small_sort(t_stacks **stacks);
void	ft_butterfly_sort(t_stacks **stacks, int pivo_a, int pivo_b);

/*	SORT_UTILS	*/
void	ft_normalize(t_list **stack);
void	ft_normalize_by_nb(t_list **stack, int nb);
int		ft_find_index(int n, t_list *stack);

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
int		get_content(t_list *stack);
int		smart_display_move(char *move, char *next_move);

#endif
