/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:45 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 15:51:47 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../src/push_swap.h"
# include "./get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

void			push_swapi(char *inputs);
void			initstatks(int *all_numb, int count);
void			do_multi(t_stack_node **a, t_stack_node **b, char *operation);
t_stack_node	*do_sa(t_stack_node *a, char *operation);
t_stack_node	*do_sb(t_stack_node *b, char *operation);
void			result(t_stack_node *a, int count);
void			checker(t_stack_node *sa, t_stack_node *sb);

#endif
