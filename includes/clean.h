/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:48:59 by ltuffery          #+#    #+#             */
/*   Updated: 2022/12/16 19:18:34 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

# include "utils.h"

/*	CLEAN	*/
void	ft_clean_stack(t_list *stack);
void	ft_clean_tab(char **tab);
void	ft_clean_all_stacks(t_stacks *stacks);

#endif
