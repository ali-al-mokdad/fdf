/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:18:28 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 14:53:05 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*set_target_nodes_b(t_stack_node *stack_a,
t_stack_node *stack_b)
{
	t_stack_node	*sa;
	t_stack_node	*sb;
	t_stack_node	*closest;

	sb = stack_b;
	while (sb)
	{
		sa = stack_a;
		closest = NULL;
		while (sa)
		{
			if ((sa->nbr > sb->nbr) && (!closest || sa->nbr < closest->nbr))
				closest = sa;
			sa = sa->next;
		}
		if (closest)
			sb->target_node = closest;
		else
			sb->target_node = find_smallest(stack_a);
		sb = sb->next;
	}
	return (stack_b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	bring_on_top(a, (*b)->target_node, 'a');
	pa(a, b, 1);
}

void	init_node_b(t_stack_node **a, t_stack_node **b)
{
	current_index(*a);
	current_index(*b);
	*b = set_target_nodes_b(*a, *b);
}

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*min;
	t_stack_node	*temp;

	min = stack;
	temp = stack;
	while (stack != NULL)
	{
		if (min->nbr > stack->nbr)
			min = stack;
		stack = stack->next;
	}
	stack = temp;
	return (min);
}
