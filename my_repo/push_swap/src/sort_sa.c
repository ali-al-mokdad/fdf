/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:19:58 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 14:52:47 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_on_top(t_stack_node **stack,
t_stack_node *desired_node, char stack_name)
{
	while (*stack != desired_node)
	{
		if (desired_node->above_median)
		{
			if (stack_name == 'a')
				ra(stack, 1);
			else
				rb(stack, 1);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

t_stack_node	*set_cheapest(t_stack_node *stack)
{
	t_stack_node	*s;
	t_stack_node	*cost;

	s = stack;
	cost = stack;
	while (s)
	{
		if (cost->cost > s->cost)
			cost = s;
		s = s->next;
	}
	cost->cheapest = true;
	return (stack);
}

t_stack_node	*set_target_nodes_a(t_stack_node *stack_a,
t_stack_node *stack_b)
{
	t_stack_node	*sa;
	t_stack_node	*sb;
	t_stack_node	*closest;

	sa = stack_a;
	while (sa)
	{
		sb = stack_b;
		closest = NULL;
		while (sb)
		{
			if (sa->nbr > sb->nbr && (!closest || sb->nbr > closest->nbr))
				closest = sb;
			sb = sb->next;
		}
		if (closest)
			sa->target_node = closest;
		else
			sa->target_node = find_biggest(stack_b);
		sa = sa->next;
	}
	return (stack_a);
}

void	init_node_a(t_stack_node **a, t_stack_node **b)
{
	current_index((*a));
	current_index((*b));
	(*a) = set_target_nodes_a((*a), (*b));
	(*a) = cost_analyst((*a), (*b));
	(*a) = set_cheapest((*a));
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest((*a));
	if (cheapest_node->target_node)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
		{
			while (*b != cheapest_node->target_node && *a != cheapest_node)
				rr(a, b, 1);
			current_index(*a);
			current_index(*b);
		}
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b, 1);
		current_index(*a);
		current_index(*b);
	}
	bring_on_top(a, cheapest_node, 'a');
	bring_on_top(b, cheapest_node->target_node, 'b');
	pb(b, a, 1);
}
