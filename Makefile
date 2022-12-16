# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 16:12:31 by zrebhi            #+#    #+#              #
#    Updated: 2022/12/16 17:33:19 by bgresse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		all clean fclean re

SRCS		= main.c ./sources/read_file.c

OBJS		= ${SRCS:.c=.o}

HEADERS		= ft_mlx.h \
			  mlx_keycodes.h

NAME		= fdf

LIBFT		= libft.a

LIBMLX		= libmlx.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g -O3 -march=native -ffast-math

MLX_DIR		= mlx/

MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_CCFLAGS	= -Imlx

%.o		:	%.c Makefile ${HEADERS} libft/*.h libft/*.c libft/Makefile 
			${CC} ${CFLAGS} ${MLX_CCFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make ${LIBFT} -C libft/
			make ${LIBMLX} -C ${MLX_DIR}
			${CC} -o ${NAME} $(CFLAGS) ${OBJS} ${MLX_FLAGS} -lm libft/libft.a ${MLX_DIR}libmlx.a

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C libft/
			make clean -C ${MLX_DIR}

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft/

re:			fclean all
