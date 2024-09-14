/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_u1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:48:15 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/11 12:28:01 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	save_to_struct(char *line, t_vars *vars)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		perror("Error splitting line");
		exit(EXIT_FAILURE);
	}
	vars->map = realloc(vars->map, sizeof(int *) * (vars->y + 1));
	if (!vars->map)
	{
		perror("Error reallocating memory for map");
		exit(EXIT_FAILURE);
	}
	allocate_row_memory(vars);
	i = 0;
	while (tokens[i] != NULL)
	{
		vars->map[vars->y][i] = atoi(tokens[i]);
		i++;
	}
	free_tokens(tokens);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	process_line(char *line, t_vars *vars)
{
	char	**tokens;
	int		i;

	tokens = ft_split(line, ' ');
	if (!tokens)
	{
		perror("Error splitting line");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (tokens[i])
		i++;
	if (vars->x < i)
		vars->x = i;
	vars->map = realloc(vars->map, sizeof(int *) * (vars->y + 1));
	if (!vars->map)
	{
		perror("Error reallocating memory");
		exit(EXIT_FAILURE);
	}
	vars->map[vars->y] = NULL;
	save_to_struct(line, vars);
	free_tokens(tokens);
}

void	save_map(int file, t_vars *vars)
{
	char	*line;

	vars->y = 0;
	vars->x = 0;
	vars->map = NULL;
	line = get_next_line(file);
	while (line != NULL)
	{
		process_line(line, vars);
		free(line);
		vars->y++;
		line = get_next_line(file);
	}
	vars->map = realloc(vars->map, sizeof(int *) * (vars->y + 1));
	if (!vars->map)
	{
		perror("Error reallocating memory");
		exit(EXIT_FAILURE);
	}
	vars->map[vars->y] = NULL;
}

void	read_map(char *filename, t_vars *vars)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	vars->map = NULL;
	save_map(file, vars);
	close(file);
	vars->map = realloc(vars->map, sizeof(int *) * (vars->y + 1));
	if (!vars->map)
	{
		perror("Error reallocating memory");
		exit(EXIT_FAILURE);
	}
	vars->map[vars->y] = NULL;
}
