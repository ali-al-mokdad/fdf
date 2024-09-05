/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1_s_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:24:18 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 14:54:37 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a, int flag)
{
	int	temp;

	temp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = temp;
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, int flag)
{
	int	temp;

	temp = (*b)->nbr;
	(*b)->nbr = (*b)->next->nbr;
	(*b)->next->nbr = temp;
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, int flag)
{
	sa(a, 1);
	sb(b, 1);
	if (flag)
		ft_printf("ss\n");
}

void	pa(t_stack_node **a, t_stack_node **b, int flag)
{
	push(a, b);
	if (flag)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, int flag)
{
	push(b, a);
	if (flag)
		ft_printf("pb\n");
}
