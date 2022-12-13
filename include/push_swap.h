/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:10:34 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/13 14:38:00 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	t_list	*a;
	int		size_a;
	t_list	*b;
	int		size_b;
	char	**moves;
	int		n_items;
}	t_stacks;

/*	PARSING	*/
t_list	*ft_parsing(char *params, int ac, char **av);
char	*ft_regroups(int ac, char **av);

/*	CHECK ERROR	*/
int		ft_has_digit(char *str);
int		ft_has_alpha(char *str);
int		ft_has_duplicate(char *content, t_list *stack);
int		ft_invalid_sign(char *str);

/*	CLEAN	*/
void	ft_clean_stacks(t_stacks *stacks);
void	ft_clean_stack(t_list *lst);
void	ft_clean_tab(char **tab);
void	del(void *content);

/*	TRANSLATION	*/
t_list	*ft_convert_tab_to_lst(char **tab);
void	ft_normalize(t_list **stack);
void	ft_normalize_by_nb(t_list **stack, int nb);

/*	SORT STACK	*/
int		ft_is_sort(t_list *stack_a);
void	ft_start_sort(t_stacks **stacks);
void	ft_sort_three_item(t_stacks **stacks);
void	ft_sort(t_stacks **stacks);
void	ft_finish_sort(t_stacks **stacks);

/*	SORT STACK UTILS	*/
int		ft_find_pivot(t_stacks *stacks);

/*	UTILS	*/
int		ft_search_index(int n, t_list *stack);
void	ft_print_stack(t_list *stack);

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

#endif
