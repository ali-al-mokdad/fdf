/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:06:25 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/05 21:23:19 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_structs(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->x)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free(vars);
}

void	save_to_struct(char *line, t_vars *vars)
{
	char	**temp_map;

	temp_map = realloc(vars->map, sizeof(char *) * (vars->x + 1));
	if (!temp_map)
	{
		perror("Error reallocating memory");
		exit(-1);
	}
	vars->map = temp_map;
	vars->map[vars->x] = line;
}

void	save_map(int file, t_vars *vars)
{
	char	*line;
	int		cols;
	int		i;

	vars->y = 0;
	vars->x = 0;
	line = get_next_line(file);
	while (line != NULL)
	{
		cols = 0;
		i = 0;
		while (line[i])
		{
			if (line[i] == ' ')
				cols++;
			i++;
		}
		if (vars->y < cols)
			vars->y = cols + 1;
		save_to_struct(line, vars);
		line = get_next_line(file);
		vars->x++;
	}
}

void	read_map(char *filename, t_vars *vars)
{
	int		file;
	char	**temp_map;

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		perror("Error opening file");
		exit(-1);
	}
	vars->map = NULL;
	save_map(file, vars);
	close (file);
	temp_map = realloc(vars->map, sizeof(char *) * (vars->x + 1));
	if (!temp_map)
	{
		perror("Error reallocating memory");
		exit(-1);
	}
	vars->map = temp_map;
	vars->map[vars->x] = NULL;
}
