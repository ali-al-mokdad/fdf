/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:18:27 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/15 17:25:07 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *a)
{
	t_stack_node	*temp;
	int				size;

	size = 0;
	temp = a;
	while (a != NULL)
	{
		a = a->next;
		size++;
	}
	a = temp;
	return (size);
}

int	sorted(t_stack_node *a)
{
	while (a != NULL)
	{
		if (a && a->next)
		{
			if (a->nbr > a->next->nbr)
				return (0);
		}
		a = a->next;
	}
	return (1);
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = (stack_size(stack) / 2) + 1;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

t_stack_node	*find_biggest(t_stack_node *stack)
{
	t_stack_node	*max;
	t_stack_node	*temp;

	max = stack;
	temp = stack;
	while (stack != NULL)
	{
		if (max->nbr < stack->nbr)
			max = stack;
		stack = stack->next;
	}
	stack = temp;
	return (max);
}

t_stack_node	*cost_analyst(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*s;
	int				size_a;
	int				size_b;

	s = stack_a;
	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	while (s)
	{
		s->cost = s->index;
		if (!(s->above_median))
			s->cost = size_a - (s->index);
		if (s->target_node && s->target_node->above_median)
			s->cost += s->target_node->index;
		else if (s->target_node && (!s->target_node->above_median))
			s->cost += size_b - (s->target_node->index);
		s = s->next;
	}
	return (stack_a);
}
