/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:10:34 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/26 12:48:17 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

/*	CHECK ERROR	*/
int		ft_has_digit(char *str);
int		ft_has_alpha(char *str);
int		ft_has_duplicate(char *content, t_list *stack);
int		ft_invalid_sign(char *str);

/*	CLEAN	*/
void	ft_clean_stack(t_list *lst);
void	ft_clean_tab(char **tab);
void	del(void *content);

/*	TRANSLATION	*/
t_list	*ft_convert_tab_to_lst(char **tab);

/*	SORT STACK	*/
int		ft_is_sort(t_list *stack_a);
void	ft_start_sort(t_list **stack_a);

/*	UTILS	*/
void	ft_swap(t_list **stacki, char *swap_name);
void	ft_push(t_list **to, t_list **in);
void	ft_rotate(t_list **stack);
void	ft_reverse(t_list **stack);

#endif
