/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:00:23 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/05 21:20:18 by aal-mokd         ###   ########.fr       */
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

void	read_map(char *filename, t_vars *vars);
int		draw_map(t_vars *vars);
void	free_structs(t_vars *vars);

#endif