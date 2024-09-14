/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:25:08 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/05 19:53:41 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	read_map(char *filename, t_vars *vars)
// {
// 	int		file;
// 	char	*line;
// 	int		line_count;
// 	int		max_cols;
// 	char	**temp_map;

// 	file = open(filename, O_RDONLY);
// 	if (file < 0)
// 	{
// 		perror("Error opening file");
// 		exit(-1);
// 	}
// 	vars->map = NULL;
// 	line_count = 0;
// 	max_cols = 0;
// 	while ((line = get_next_line(file)) != NULL)
// 	{
// 		// Count number of columns in the current line
// 		int cols = 0;
// 		char *ptr = line;
// 		while (*ptr)
// 		{
// 			if (*ptr == ' ')
// 				cols++;
// 			ptr++;
// 		}
// 		cols++; // Last value is not followed by space

// 		if (cols > max_cols)
// 			max_cols = cols;

// 		// Allocate/reallocate memory for the map
// 		temp_map = realloc(vars->map, sizeof(char *) * (line_count + 1));
// 		if (!temp_map)
// 		{
// 			perror("Error reallocating memory");
// 			exit(-1);
// 		}
// 		vars->map = temp_map;
// 		vars->map[line_count] = line;
// 		line_count++;
// 	}
// 	close(file);

// 	// Allocate memory for the last row of the map
// 	temp_map = realloc(vars->map, sizeof(char *) * (line_count + 1));
// 	if (!temp_map)
// 	{
// 		perror("Error reallocating memory");
// 		exit(-1);
// 	}
// 	vars->map = temp_map;
// 	vars->map[line_count] = NULL; // Null-terminate the map

// 	// Store the dimensions of the map
// 	vars->num_rows = line_count;
// 	vars->num_cols = max_cols;
// }

void	iso_projection(t_iso *iso)
{
	iso->iso_x1 = (iso->x - iso->y) * 32 + 150;
	iso->iso_y1 = (iso->x + iso->y) * 32 / 2 - iso->z * 32 / 2 + 150;
}

void	mlx_line(t_vars *vars, t_iso *iso, int color)
{
	int	dx = abs(iso->iso_x2 - iso->iso_x1);
	int	dy = abs(iso->iso_y2 - iso->iso_y1);
	int	sx = (iso->iso_x1 < iso->iso_x2) ? 1 : -1;
	int	sy = (iso->iso_y1 < iso->iso_y2) ? 1 : -1;
	int	err = dx - dy;

	while (1) {
		mlx_pixel_put(vars->mlx, vars->win, iso->iso_x1, iso->iso_y1, color);
		if (iso->iso_x1 == iso->iso_x2 && iso->iso_y1 == iso->iso_y2)
			break;
		int e2 = err * 2;
		if (e2 > - dy)
		{
			err -= dy;
			iso->iso_x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			iso->iso_y1 += sy;
		}
	}
}

int	draw_map(t_vars *vars)
{
	t_iso	iso;
	int		row;
	int		col;
	char	**line_values;

	row = 0;
	while (row < vars->num_rows)
	{
		col = 0;
		line_values = ft_split(vars->map[row], ' '); // Assuming ft_split is defined
		while (col < vars->num_cols)
		{
			if (line_values[col] == NULL) // Skip if there is no data
			{
				col++;
				continue;
			}

			iso.x = col;
			iso.y = row;
			iso.z = atoi(line_values[col]); // Convert string to integer

			iso_projection(&iso);

			if (col > 0)
			{
				iso.x = col - 1;
				iso.y = row;
				iso.z = atoi(line_values[col - 1]);
				iso_projection(&iso);
				mlx_line(vars, &iso, 0xFFFFFF);
			}
			if (row > 0)
			{
				iso.x = col;
				iso.y = row - 1;
				iso.z = atoi(line_values[col]);
				iso_projection(&iso);
				mlx_line(vars, &iso, 0xFFFFFF);
			}
			col++;
		}

		// Free the line_values array
		for (int i = 0; i < vars->num_cols; i++)
			free(line_values[i]);
		free(line_values);

		row++;
	}
	return (0);
}

