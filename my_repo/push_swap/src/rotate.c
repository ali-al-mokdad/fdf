/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:05:22 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/14 14:07:47 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last(t_stack_node	*stack)
{
	t_stack_node	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

void	rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	last = find_last(*stack);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	fix_index(*stack);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
