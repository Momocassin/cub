# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 21:47:29 by motaouss          #+#    #+#              #
#    Updated: 2023/07/24 20:13:11 by motaouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

SRCS			=	cub3d.c	\
					LIB/Gnl.c \
					LIB/lib.c \
					LIB/lib2.c \
					LIB/utils.c \
					PARSING/check.c \
					PARSING/ft_strncmp.c \
					PARSING/check2.c \
					PARSING/fill_map.c \
					PARSING/error_map.c \
					PARSING/parsing.c	\
					PARSING/parsing2.c \
					PARSING/fill_map2.c \
					display/display.c	\
					display/key_handler.c	\
					display/raycast1.c \
					display/raycast2.c \
					display/utils.c


OBJS			=	${addprefix srcs/,${SRCS:.c=.o}}

LD_FLAGS		=	-L mlx

MLX_FLAGS		=	-Lmlx -lmlx -lXext -lX11 -lm -lz -Imlx

HEAD			=	-I includes -I mlx

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g #-fsanitize=address

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -C mlx
					${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} ${MLX_FLAGS}

all				:	${NAME}

clean			:
					make clean -C mlx
					@rm -rf ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					@rm -rf ${NAME}

re				:	fclean all