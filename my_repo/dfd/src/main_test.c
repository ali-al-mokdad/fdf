/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:22:02 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/02 19:33:28 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <time.h>

#define KEY_PRESS_DURATION 2

typedef struct s_vars
{
	void    *mlx;
	void    *win;
	time_t  key_press_start_time;
	int     key_pressed;
	int     key_pressed_for_longer;
	int     square_x1; // top-left x coordinate
	int     square_y1; // top-left y coordinate
	int     square_x2; // bottom-right x coordinate
	int     square_y2; // bottom-right y coordinate
	int		x;
	int		y;
    double color_offset;
}               t_vars;

void    my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	mlx_pixel_put(vars->mlx, vars->win, x, y, color);
}

int     handle_expose(t_vars *vars)
{
	int i;
	int j;
	int square_color;

	square_color = 0xFF00FF;
	printf("Window exposed (redraw required)\n");
	for (i = vars->square_x1; i <= vars->square_x2; i++)
	{
		for (j = vars->square_y1; j <= vars->square_y2; j++)
		{
			my_mlx_pixel_put(vars, i, j, square_color);
		}
	}
	return (0);
}
int render_next_frame(t_vars *vars) {
    // Clear the window
    mlx_clear_window(vars->mlx, vars->win);
    
    // Draw the rainbow background
 //   draw_rainbow_background(vars);

    // Draw the circle
    draw_circle(vars, vars->circle_x, vars->circle_y, CIRCLE_RADIUS, 0xFFFFFF);

    // Update color offset for the rainbow effect
    vars->color_offset += COLOR_CHANGE_SPEED;
    if (vars->color_offset > 1000) {
        vars->color_offset = 0;
    }

    return (0);
}
int     handle_key_press(int keycode, t_vars *vars)
{
	if (keycode == 0x61) // 'a'
        vars->circle_x -= MOVE_STEP;
    if (keycode == 0x64) // 'd'
        vars->circle_x += MOVE_STEP;
    if (keycode == 0x77) // 'w'
        vars->circle_y -= MOVE_STEP;
   if (keycode == 0x73) // 's'
        vars->circle_y += MOVE_STEP;
	if (keycode == XK_0)
	{
		printf("SIZE 0\n");
		vars->x = 500;
		vars->y = 500;
	}
	if (keycode == XK_1)
	{	
		printf("SIZE 1\n");
		vars->x = 1000;
		vars->y = 1000;
	}
	if (keycode == XK_2)
	{
		printf("SIZE 2\n");
		vars->x = 2000;
		vars->y = 2000;
	}
	if (keycode == XK_f)
	{
		printf("bye");
		exit(0);
	}
	else
	{
		if (!vars->key_pressed)
		{
			vars->key_pressed = 1;
			vars->key_press_start_time = time(NULL);
			vars->key_pressed_for_longer = 0;
		}
	}
	return (0);

}

int     handle_mouse_click(int button, int x, int y, t_vars *vars)
{
	if (button == Button1)
	{
		printf("Mouse click at (%d, %d)\n", x, y);
		
		// Check if the click is within the square's boundaries
		if (x >= vars->square_x1 && x <= vars->square_x2 &&
			y >= vars->square_y1 && y <= vars->square_y2)
		{
			printf("Clicked inside the square. Closing window.\nbye");
			mlx_destroy_window(vars->mlx, vars->win);
			exit(0);
		}
	}
	return (0);
}

int     handle_close(void *param)
{
	t_vars *vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void    check_key_press_duration(t_vars *vars)
{
	if (vars->key_pressed)
	{
		time_t current_time = time(NULL);
		if (difftime(current_time, vars->key_press_start_time) > KEY_PRESS_DURATION)
		{
			printf("Key pressed longer than %d seconds\n", KEY_PRESS_DURATION);
			vars->key_pressed = 0;
		}
	}
}

int     loop_hook(t_vars *vars)
{
	check_key_press_duration(vars);
	return (0);
}

int     main(void)
{
	t_vars vars;
	int     square_color;

	

	vars.mlx = mlx_init();vars.x = 500; vars.y = 700;
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "hi");
	printf("hello\n");

	vars.square_x1 = 300;
	vars.square_y1 = 300;
	vars.square_x2 = 400;
	vars.square_y2 = 400;

	square_color = 0xFF0000;
	for (int i = vars.square_x1; i <= vars.square_x2; i++)
	{
		for (int j = vars.square_y1; j <= vars.square_y2; j++)
		{
			my_mlx_pixel_put(&vars, i, j, square_color);
		}
	}

	vars.key_pressed = 0;
	mlx_hook(vars.win, KeyPress, KeyPressMask, handle_key_press, &vars);
	mlx_hook(vars.win, ButtonPress, ButtonPressMask, handle_mouse_click, &vars);
	mlx_expose_hook(vars.win, handle_expose, &vars);
	mlx_hook(vars.win, DestroyNotify, StructureNotifyMask, handle_close, &vars);
	mlx_loop_hook(vars.mlx, loop_hook, &vars);

	mlx_loop(vars.mlx);

	return (0);
}
