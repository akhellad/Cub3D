# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 23:12:00 by akhellad          #+#    #+#              #
#    Updated: 2024/01/04 13:08:01 by akhellad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname -s)

D_MLX		= minilibx/
ifeq ($(OS), Linux)
	D_LMLX	= ${D_MLX}linux/
	MLX		= -L${D_LMLX} -lmlx -lXext -lX11 -lm
endif
ifeq ($(OS), Darwin)
	D_LMLX	= ${D_MLX}mac/
	MLX		= -L${D_LMLX} -lmlx -framework OpenGL -framework AppKit
endif

S_SRC		= main.c									\
			${D_PARSE}ft_parsing.c						\
			${D_PARSE}ft_parsing_colors.c				\
			${D_PARSE}ft_parsing_textures.c				\
			${D_PARSE}ft_parsing_utils.c				\
			${D_PARSE}ft_parsing_map.c					\
			${D_PARSE}ft_parsing_utils_2.c				\
			${D_RAY}ft_init_ray.c						\
			${D_RAY}ft_init_textures.c					\
			${D_RAY}ft_calculate_positions.c			\
			${D_RAY}ft_draw_line.c						\
			${D_RAY}ft_loop.c							\
			${D_RAY}ft_cast_ray.c						\
			${D_RAY}ft_move.c							\
			${D_RAY}ft_rot.c							\
			${D_RAY}ft_raycasting.c						\
			${D_RAY}ft_mlx_pixel_put.c					\
			${D_RAY}ft_hook_keypress.c					\
			${D_UTILS}ft_error.c						\
			${D_UTILS}ft_reset_struct.c					\
			${D_UTILS}ft_free_all.c						\
			${D_BONUS}minimap.c							\
			${D_BONUS}fog.c								\

HDRS_LIST	= cub3Dbonus.h

S_TMP		= ${addprefix ${D_SRC}, ${S_SRC}}
O_SRC		= $(patsubst %.c, ${D_OBJS}%.o, $(S_TMP))
HDRS		= ${addprefix ${D_INCLUDES}, ${HDRS_LIST}}

# VARIABLES
NAME		= ../cub3Dbonus
CC			= cc

# FLAGS
MAKEFLAGS	+= --no-print-directory -s
CFLAGS		= -Wall -Wextra -Werror -g3
LIBFT		= -L ./libft -lft

# COMMANDS
RM			= rm -rf
PRINT		= @printf

# DIRECTORIES
D_OBJS		= .objs/
D_INCLUDES	= includes/
D_LIB		= libft/
D_SRC		= sources/
D_PARSE		= parsing/
D_RAY		= raycasting/
D_UTILS		= utils/
D_BONUS		= bonus/

# COLORS
C_R			= \033[1;31m
C_G			= \033[1;32m
C_B			= \033[1;34m
C_Y			= \033[1;33m
C_C			= \033[1;36m
C_RST		= \033[0m
C_DEL		= \r\033[2K

all:		lib		\
			mlx		\
			${NAME}

${D_OBJS}%.o: %.c		${D_LIB}libft.a ${D_LMLX}mlx.h ${HDRS} ${D_INCLUDES}define.h ${D_INCLUDES}keycode.h Makefile
			@mkdir		-p $(shell dirname $@)
			@${PRINT}	"${C_Y}${C_DEL}Creating ${NAME}'s objects : $@"
			@${CC}		${CFLAGS} -I${D_LMLX} -I${D_LIB} -I${D_INCLUDES} -O3 -c $< -o $@

${NAME}:	${O_SRC}
			@${PRINT}	"${C_G}${C_DEL}Creating ${NAME}'s objects : DONE\n"
			@${PRINT}	"${C_Y}Compiling ${NAME}...${C_RST}"
			@${CC} 		${O_SRC} -o ${NAME} ${LIBFT} ${MLX}
			@${PRINT}	"${C_G}${C_DEL}Compiling ${NAME} : DONE ${C_RST}\n"

lib:
			@${MAKE}	-C ./libft
			@${PRINT}	"${C_G}${C_DEL}\nCompiling LIBFT : DONE\n${C_RST}"

mlx:
			@${MAKE}	-C ./${D_LMLX}
			@${PRINT}	"${C_G}${C_DEL}\nCompiling MLX : DONE\n${C_RST}"

clean:
			@${MAKE}	clean -C ./${D_LMLX}
			@${PRINT}	"${C_R}${C_DEL}Cleaning MLX : DONE\n"
			@${PRINT}	"${C_R}Cleaning libft : DONE\n"
			@${MAKE}	clean -C ./libft
			@${PRINT}	"${C_R}Deleting objects : DONE\n"
			@${RM}		${D_OBJS}

fclean:		clean
			@${PRINT}	"${C_R}Cleaning libft : DONE\n"
			@${MAKE}	fclean -C ./libft
			@${PRINT}	"${C_R}Deleting executable : DONE${C_RST}\n"
			@${RM}		${NAME}

re:			fclean all

.PHONY:		all re clean fclean lib mlx


