/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:24:14 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/08/19 15:20:46 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*str;
	char	*temp;
	int		i;

	if (argc < 2)
		exit (-1);
	if (argc == 2)
		push_swap(argv[1]);
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
		push_swap(str);
		free(str);
	}
	return (0);
}
