# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:14:53 by aal-mokd          #+#    #+#              #
#    Updated: 2024/08/19 16:04:10 by aal-mokd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = ft_printf/libftprintf.a

SRCS  = src/main.c src/push_algorithme.c src/push.c src/push_swap.c src/push_swap_next1.c src/push_swap_utils0_atoi.c src/push_swap_utils1_s_p.c src/push_swap_utils2_rotate.c src/push_swap_utils3_revers_rotate.c src/push_utils.c src/rotate.c src/sort_sa.c src/sort_sb.c

push_swap_BONUS = bonus/checker.c bonus/checker_utils.c ft_printf/libft/ft_strcmp.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c  src/push_algorithme.c src/push.c src/push_swap.c src/push_swap_next1.c src/push_swap_utils0_atoi.c src/push_swap_utils1_s_p.c src/push_swap_utils2_rotate.c src/push_swap_utils3_revers_rotate.c src/push_utils.c src/rotate.c src/sort_sa.c src/sort_sb.c\

OBJS = ${SRCS:.c=.o}
BONUS_OBJ = $(push_swap_BONUS:.c=.o)


CC					= gcc
RM					= rm -f
CFLAGS				= -Wall -Wextra -Werror

all: $(NAME) 

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB)  -o checker


$(NAME):	$(OBJS) $(LIB)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

$(LIB):
			@make -C ./ft_printf

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:	
		@make clean -C ./ft_printf
		${RM} ${OBJS}
		${RM} $(BONUS_OBJ)

fclean: clean
		${RM} ${LIB}
		${RM} ${NAME}
		rm -rf checker

re: fclean all

.PHONY: all bonus clean fclean re
