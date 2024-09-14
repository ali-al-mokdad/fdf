/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:52:11 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 15:20:43 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define    PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					cost;
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

void			push_swap(char *str);
int				main(int argc, char **argv);
int				*push_swap_atoi(const char *nptr, int *count);
int				ft_issigne(int c);
int				count_numbers(const char *nptr);
int				parse_number(const char **p, int *result, int *sign);
int				parse_numbers(const char *nptr, int *array);
int				check_double(int *all_numb, int count);
void			push_swapcases(int *all_numb, int count);
void			general_case(int *all_numb, int count);
void			case2(int *all_numb);
void			case3(int *all_numb);
void			init_stack_a(t_stack_node **a, int	*all_numb, int count);
void			sa(t_stack_node **a, int flag);
void			sb(t_stack_node **b, int flag);
void			ss(t_stack_node **a, t_stack_node **b, int flag);
void			pb(t_stack_node **b, t_stack_node **a, int flag);
void			pa(t_stack_node **a, t_stack_node **b, int flag);
void			ra(t_stack_node **a, int flag);
void			rb(t_stack_node **b, int flag);
void			rr(t_stack_node **a, t_stack_node **b, int flag);
void			rra(t_stack_node **a, int flag);
void			rrb(t_stack_node **b, int flag);
void			rrr(t_stack_node **a, t_stack_node **b, int flag);
void			push(t_stack_node **dest, t_stack_node	**src);
void			fix_index(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node	*stack);
void			rotate(t_stack_node **stack);
void			free_stack(t_stack_node *stack);
void			reverse(t_stack_node **stack);
void			init_stack_b(t_stack_node **b);
t_stack_node	*push_swap_algo(t_stack_node *sa, t_stack_node *sb, int size_a);
t_stack_node	*find_smallest(t_stack_node *stack);
int				stack_size(t_stack_node *a);
t_stack_node	*find_biggest(t_stack_node *stack);
int				sorted(t_stack_node *a);
void			sort(t_stack_node *a, t_stack_node *b);
void			init_node_a(t_stack_node **a, t_stack_node **b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
t_stack_node	*set_target_nodes_a(t_stack_node *stack_a,
					t_stack_node *stack_b);
void			init_node_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
t_stack_node	*set_target_nodes_b(t_stack_node *stack_a,
					t_stack_node *stack_b);
void			bring_on_top(t_stack_node **stack,
					t_stack_node *desired_node, char stack_name);
t_stack_node	*cost_analyst(t_stack_node *stack_a, t_stack_node *stack_b);
t_stack_node	*get_cheapest(t_stack_node *stack);
t_stack_node	*set_cheapest(t_stack_node *stack);
void			current_index(t_stack_node *stack);
int				stack_size(t_stack_node *a);
t_stack_node	*tinysort(t_stack_node *a);
void			printList(t_stack_node *head);
t_stack_node	*remove_top(t_stack_node **stack);

#endif