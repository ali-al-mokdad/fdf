/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:35 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 15:41:52 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_multi(t_stack_node **a, t_stack_node **b, char *operation)
{
	if (ft_strcmp(operation, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(operation, "pb\n") == 0)
		pb(b, a, 0);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp(operation, "ss\n") == 0)
		ss(a, b, 0);
}

t_stack_node	*do_sa(t_stack_node *a, char *operation)
{
	if (ft_strcmp(operation, "ra\n") == 0)
		ra(&a, 0);
	else if (ft_strcmp(operation, "rra\n") == 0)
		rra(&a, 0);
	else if (ft_strcmp(operation, "sa\n") == 0)
		sa(&a, 0);
	return (a);
}

t_stack_node	*do_sb(t_stack_node *b, char *operation)
{
	if (ft_strcmp(operation, "rb\n") == 0)
		rb(&b, 0);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		rrb(&b, 0);
	else if (ft_strcmp(operation, "sb\n") == 0)
		sb(&b, 0);
	return (b);
}

void	result(t_stack_node *a, int count)
{
	if (!sorted(a))
		ft_printf("KO\n");
	else if (stack_size(a) == 3 && count > 3)
		ft_printf("KO\n");
	else if (stack_size(a) == 5 && count > 8)
		ft_printf("here KO\n");
	else if (stack_size(a) == 100 && count > 1500)
		ft_printf("KO\n");
	else if (stack_size(a) == 500 && count >= 11500)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(a);
	return ;
}

void	checker(t_stack_node *sa, t_stack_node *sb)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strcmp(line, "pa\n") == 0
			|| ft_strcmp(line, "pb\n") == 0
			|| ft_strcmp(line, "rr\n") == 0
			|| ft_strcmp(line, "rrr\n") == 0
			|| ft_strcmp(line, "ss\n") == 0)
			do_multi(&sa, &sb, line);
		else if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rra\n") == 0
			|| ft_strcmp(line, "sa\n") == 0)
			sa = do_sa(sa, line);
		else if (ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rrb\n") == 0
			|| ft_strcmp(line, "sb\n") == 0)
			sb = do_sb(sb, line);
		free(line);
		line = get_next_line(0);
		count++;
	}
	result(sa, count);
}
