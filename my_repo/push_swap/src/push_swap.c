/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:52:58 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 15:20:57 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case2(int *all_numb)
{
	int	temp;

	if (all_numb[0] > all_numb[1])
	{
		temp = all_numb[1];
		all_numb[1] = all_numb[0];
		all_numb[0] = temp;
		ft_printf("sa\n");
	}
	if (all_numb[0] < all_numb[1])
		return ;
}

void	case3(int *all_numb)
{
	int	temp;

	if (all_numb[0] > all_numb[1])
	{
		temp = all_numb[1];
		all_numb[1] = all_numb[0];
		all_numb[0] = temp;
		ft_printf("sa\n");
	}
	if (all_numb[0] > all_numb[2])
	{
		temp = all_numb[2];
		all_numb[2] = all_numb[1];
		all_numb[1] = all_numb[0];
		all_numb[0] = temp;
		ft_printf("rra\n");
	}
	if (all_numb[1] > all_numb[2])
	{
		ft_printf("rra\nsa\n");
		temp = all_numb[1];
		all_numb[1] = all_numb[2];
		all_numb[2] = temp;
	}
	return ;
}

void	push_swapcases(int *all_numb, int count)
{
	if (count == 1)
		return ;
	else if (count == 2)
		case2(all_numb);
	else if (count == 3)
		case3(all_numb);
	else
		general_case(all_numb, count);
}

int	check_double(int *all_numb, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (all_numb[i] == all_numb[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	push_swap(char *inputs)
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
	push_swapcases(all_numb, count);
	free(all_numb);
}
