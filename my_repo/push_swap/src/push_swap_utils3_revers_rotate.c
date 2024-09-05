/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3_revers_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:26:19 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 14:51:03 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack_node **stack)
{
	t_stack_node	*second_last;
	t_stack_node	*current;
	t_stack_node	*last;

	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	second_last = current;
	last = current->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	fix_index(*stack);
}

void	rra(t_stack_node **a, int flag)
{
	reverse(a);
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, int flag)
{
	reverse(b);
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int flag)
{
	reverse(a);
	reverse(b);
	if (flag)
		ft_printf("rrr\n");
}
