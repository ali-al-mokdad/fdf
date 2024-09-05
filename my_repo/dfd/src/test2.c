


#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <time.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define CIRCLE_RADIUS 50
#define MOVE_STEP 10

typedef struct s_vars {
    void *mlx;
    void *win;
    void *texture;
    void *cursor;
    int circle_x;
    int circle_y;
} t_vars;

void my_mlx_pixel_put(void *mlx, void *win, int x, int y, int color) {
    mlx_pixel_put(mlx, win, x, y, color);
}

void draw_circle(t_vars *vars, int x_center, int y_center, int radius, int color) {
    int x, y;
    for (y = -radius; y <= radius; y++) {
        for (x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                my_mlx_pixel_put(vars->mlx, vars->win, x_center + x, y_center + y, color);
            }
        }
    }
}

void load_texture(t_vars *vars) {
    vars->texture = mlx_xpm_file_to_image(vars->mlx, "example.xpm", &(int){0}, &(int){0});
    if (!vars->texture) {
        perror("Failed to load texture");
        exit(EXIT_FAILURE);
    }
}

void draw_texture(t_vars *vars) {
    int tex_width = 0;
    int tex_height = 0;
    int bits_per_pixel;
    int size_line;
    int endian;

    // Get texture dimensions and address
    mlx_get_data_addr(vars->texture, &bits_per_pixel, &size_line, &endian);

    // Draw texture tiles
    for (int y = 0; y < HEIGHT; y += tex_height) {
        for (int x = 0; x < WIDTH; x += tex_width) {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->texture, x, y);
        }
    }
}


void load_cursor(t_vars *vars) {
    vars->cursor = mlx_xpm_file_to_image(vars->mlx, "cursor.xpm", &(int){0}, &(int){0});
    if (!vars->cursor) {
        perror("Failed to load cursor");
        exit(EXIT_FAILURE);
    }
    mlx_mouse_move(vars->mlx, vars->win, vars->circle_x, vars->circle_y);
}

int main(void) {
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Custom Cursor and Texture");
    vars.circle_x = WIDTH / 2;
    vars.circle_y = HEIGHT / 2;

    // Load and tile texture
    load_texture(&vars);
    draw_texture(&vars);

    // Load and set custom cursor
    load_cursor(&vars);
    mlx_mouse_hide(vars.mlx, vars.win);

    mlx_loop(vars.mlx);

    return (0);
}
