/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:00:23 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/13 18:28:04 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define    FDF_H

# include "./../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./../lib/get_next_line/get_next_line.h"
# include "./../lib/ft_printf/ft_printf.h"

typedef struct s_vars
{
	int		color;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;
	void	*mlx;
	void	*win;
	char	**map;
	int		x;
	int		y;
}	t_vars;

typedef struct s_iso
{
	int	x;
	int	y;
	int	z;
	int	iso_x1;
	int	iso_y1;
	int	iso_x2;
	int	iso_y2;
}	t_iso;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_line;

void	read_map(char *filename, t_vars *vars);
int		draw_map(t_vars *vars);
void	free_structs(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y);
void	free_tokens(char **tokens);
void	allocate_row_memory(t_vars *vars);
void	free_structs(t_vars *vars);
void	free_map_rows(t_vars *vars);
void	iso_projection(t_iso *iso, t_vars *vars);
void	initialize_line(t_line *line, t_iso *iso);
void	draw_line_segment(t_vars *vars, t_iso *iso, t_line *line);
void	draw_line(t_vars *vars, t_iso *iso);
void	change_colors(int keycode, t_vars *vars);

#endif