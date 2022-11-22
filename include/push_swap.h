/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:10:34 by ltuffery          #+#    #+#             */
/*   Updated: 2022/11/22 18:06:52 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

int		ft_has_digit(char *str);
int		ft_has_alpha(char *str);
int		ft_exist_in(char *str, t_list *lst);

/*	CLEAN	*/
void	ft_clean_stack(t_list *lst);
void	ft_clean_tab(char **tab);
void	del(void *content);

/*	TRANSLATION	*/
t_list	*ft_convert_tab_to_lst(char **tab);

/*	SORT STACK	*/
void	ft_start_sort(t_list *stack_a);

/*	UTILS	*/
void	ft_swap(t_list **stacki, char *swap_name);

#endif
