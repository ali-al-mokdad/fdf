/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:12:18 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/03 16:42:17 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_vars
{
    void    *mlx;
    void    *win;
}   t_vars;

typedef struct s_point
{
    float x;
    float y;
    float z;
}   t_point;

// Define a function to project 3D coordinates to 2D
void project_point(t_point *p, int *x, int *y, int width, int height)
{
    // Simple perspective projection
    float scale = 200.0 / (p->z + 500.0);
    *x = (int)(p->x * scale + width / 2);
    *y = (int)(-p->y * scale + height / 2);
}

// Define a function to put a pixel on the window
void my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
    mlx_pixel_put(vars->mlx, vars->win, x, y, color);
}

// Bresenham's line drawing algorithm
void draw_line(t_vars *vars, t_point p1, t_point p2, int color)
{
    int x1, y1, x2, y2;
    int dx, dy, sx, sy, err, e2;

    project_point(&p1, &x1, &y1, WIDTH, HEIGHT);
    project_point(&p2, &x2, &y2, WIDTH, HEIGHT);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    sx = (x1 < x2) ? 1 : -1;
    sy = (y1 < y2) ? 1 : -1;
    err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(vars, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int main()
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "3D Simulation");

    // Define the vertices of a cube
    t_point cube[8] = {
        { -100, -100, -100 },
        {  100, -100, -100 },
        {  100,  100, -100 },
        { -100,  100, -100 },
        { -100, -100,  100 },
        {  100, -100,  100 },
        {  100,  100,  100 },
        { -100,  100,  100 }
    };

    // Define the edges of the cube
    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };

    // Draw the cube
    for (int i = 0; i < 12; i++)
    {
        draw_line(&vars, cube[edges[i][0]], cube[edges[i][1]], 0xFFFFFF);
    }

    mlx_loop(vars.mlx);

    return (0);
}
