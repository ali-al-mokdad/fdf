/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:39 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/13 18:52:53 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = vars->color;
}

int	handle_key_press(int Keycode, t_vars *vars)
{
	if (Keycode == XK_Escape)
	{
		if (vars)
			free_structs(vars);
		exit(0);
	}
	else if (Keycode == XK_equal)
	{
		if (vars->zoom < 20)
			vars->zoom += 1;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	else if (Keycode == XK_minus)
	{
		if (vars->zoom >= 2)
			vars->zoom -= 1;
		else if (vars->zoom != 1 && vars->zoom > 0.9)
			vars->zoom *= 1;
		mlx_clear_window(vars->mlx, vars->win);
		draw_map(vars);
	}
	else
		change_colors(Keycode, vars);
	return (0);
}

int	handle_mouse_click(int button, int x, int y, t_vars *vars)
{
	if (button == Button1)
		printf("Mouse click at (%d, %d)\n", x, y);
	if (x == 0 && y == 500)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	handle_destroy_notify(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars)
	{
		free_structs(vars);
	}
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		exit (-1);
	vars = calloc(1, sizeof(t_vars));
	vars->color = (int)0xFFFFFF;
	read_map(argv[1], vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "fdf");
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	vars->zoom = 1;
	mlx_hook(vars->win, KeyPress, KeyPressMask, handle_key_press, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, handle_mouse_click, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask,
		handle_destroy_notify, vars);
	mlx_expose_hook(vars->win, draw_map, vars);
	mlx_loop(vars->mlx);
	return (0);
}
