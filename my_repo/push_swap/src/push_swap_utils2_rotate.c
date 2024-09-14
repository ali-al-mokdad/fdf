/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:26:17 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 14:50:43 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a, int flag)
{
	rotate(a);
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, int flag)
{
	rotate(b);
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, int flag)
{
	rotate(a);
	rotate(b);
	if (flag)
		ft_printf("rr\n");
}
