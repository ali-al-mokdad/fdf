/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:12:18 by aal-mokd          #+#    #+#             */
/*   Updated: 2024/09/05 18:17:25 by aal-mokd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAP_WIDTH 19
#define MAP_HEIGHT 11
#define TILE_SIZE 32

int map[MAP_WIDTH][MAP_HEIGHT];

void read_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            if (fscanf(file, "%d", &map[x][y]) != 1) {
                fprintf(stderr, "Error reading file\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}

void iso_projection(int x, int y, int z, int *iso_x, int *iso_y) {
    *iso_x = (x - y) * TILE_SIZE + 150;
    *iso_y = (x + y) * TILE_SIZE / 2 - z * TILE_SIZE / 2 + 50;
}

void mlx_line(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_map(void *mlx_ptr, void *win_ptr) {
    int x, y;
    int iso_x1, iso_y1, iso_x2, iso_y2;

    for (y = 0; y < MAP_HEIGHT; ++y) {
        for (x = 0; x < MAP_WIDTH; ++x) {
            int z = map[x][y];

            // Current point
            iso_projection(x, y, z, &iso_x1, &iso_y1);

            // Draw lines to create the grid
            if (x > 0) {
                // Line to the left
                iso_projection(x - 1, y, map[x - 1][y], &iso_x2, &iso_y2);
                mlx_line(mlx_ptr, win_ptr, iso_x1, iso_y1, iso_x2, iso_y2, 0xFFFFFF);
            }

            if (y > 0) {
                // Line above
                iso_projection(x, y - 1, map[x][y - 1], &iso_x2, &iso_y2);
                mlx_line(mlx_ptr, win_ptr, iso_x1, iso_y1, iso_x2, iso_y2, 0xFFFFFF);
            }
        }
    }
}

int main() {
    void *mlx;
    void *window;

    read_map("/home/aal-mokd/core/m02/fdf/42.fdf");

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "Isometric Projection");

    draw_map(mlx, window);

    mlx_loop(mlx);

    return 0;
}

