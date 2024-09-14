NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./mlx
LDFLAGS = -L./mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

GET_NEXT_LINE_SRCS = ./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c
SRCS = ${GET_NEXT_LINE_SRCS} src/main.c src/fdf_u1.c src/fdf_u2.c src/fdf_u3.c src/fdf_u4.c

OBJS = ${SRCS:.c=.o}

ifeq ($(shell uname), Linux)
    INCLUDES = -I/usr/include -Imlx
else
    INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(shell uname).a
ifeq ($(shell uname), Linux)
    MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
    MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

LIBFT_DIR = ./lib/ft_printf
LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a

all: $(LIBFT_LIB) $(NAME)

# Compile .c to .o
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link object files to create the final executable
$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) $(LDFLAGS)

# Build the libftprintf library
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

# Build the mlx library
$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
