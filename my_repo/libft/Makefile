# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aal-mokd <aal-mokd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 18:14:53 by aal-mokd          #+#    #+#              #
#    Updated: 2024/06/19 13:03:18 by aal-mokd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

INCLUDES			= libft.h

OBJS				= ${SRCS:.c=.o}

OBJS_BONUS			= ${SRCS_BONUS:.c=.o}

NAME				= libft.a

CC					= cc

RM					= rm -f

CFLAGS				= -Wall -Wextra -Werror

all:				${NAME}

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${OBJS}:			${INCLUDES}

${OBJS_BONUS}:		${INCLUDES}

$(NAME):			${INCLUDES} ${OBJS}
					ar -rcs ${NAME} ${OBJS}

bonus:				all ${OBJS_BONUS}
					ar -rcs ${NAME} ${OBJS_BONUS}

clean:
					${RM} ${OBJS} ${OBJS_BONUS}

fclean:				clean
					${RM} ${NAME}

re:					fclean all

.PHONY:				all bonus clean fclean re