/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:47:27 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 16:01:55 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	initstatks(int *all_numb, int count)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	init_stack_a(&a, all_numb, count);
	init_stack_b(&b);
	checker(a, b);
}

void	push_swapi(char *inputs)
{
	int	*all_numb;
	int	count;

	all_numb = push_swap_atoi(inputs, &count);
	if (all_numb == NULL || count == 0)
	{
		ft_printf("Error\n");
		free(all_numb);
		return ;
	}
	if (check_double(all_numb, count) == 1)
	{
		ft_printf("Error\n");
		free(all_numb);
		return ;
	}
	initstatks(all_numb, count);
	free(all_numb);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*temp;
	int		i;

	if (argc < 2)
		exit (-1);
	if (argc == 2)
		push_swapi(argv[1]);
	else
	{
		str = NULL;
		i = 1;
		while (i <= argc)
		{
			temp = ft_strjoin(str, argv[i]);
			free(str);
			str = ft_strjoin(temp, " ");
			free(temp);
			i++;
		}
		push_swapi(str);
		free(str);
	}
	return (0);
}
