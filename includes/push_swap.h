/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:11:29 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 17:49:54 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
t_list	*ft_parsing(char *params, int ac, char **av);

/*	ERROR	*/
int		ft_has_error(t_list *lst);

/*	CLEAN	*/
void	ft_clean_stack(t_list *stack);
void	ft_clean_tab(char **tab);
void	ft_clean_all_stacks(t_stacks *stacks);

/*	SORT	*/
void	ft_start_sort(t_stacks **stacks);
int		ft_is_sort(t_list *stack);
void	ft_small_sort(t_stacks **stacks);
void	ft_butterfly_sort(t_stacks **stacks);

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

#endif
