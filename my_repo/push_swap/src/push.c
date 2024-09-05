/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:56:11 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/15 17:01:40 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_index(t_stack_node *stack)
{
	int				i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

t_stack_node	*remove_top(t_stack_node **stack)
{
	t_stack_node	*top;

	top = *stack;
	*stack = (*stack)->next;
	return (top);
}

void	push(t_stack_node **dest, t_stack_node	**src)
{
	t_stack_node	*temp;

	if (!src || !(*src))
		return ;
	temp = remove_top(src);
	temp->next = (*dest);
	(*dest) = temp;
	fix_index(*dest);
	fix_index(*src);
}
