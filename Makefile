# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 20:06:04 by akhellad          #+#    #+#              #
#    Updated: 2023/08/30 00:30:20 by akhellad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = Cub3D

SRCS_DIR = srcs/
OBJS_DIR = objs/
TMP_DIR = tmp/
LIBFT_DIR = libft/
MLX_DIR = mlx/
INC_DIR = includes/

SRCS    = main.c \
		file_parser.c \
		initialisation.c \
		arg_check.c \
		utils.c \
		mlx_image.c \
		valid_options.c \
		valid_options_utils.c \
		handle_colors.c \
		handle_map.c \
		handle_map_utils.c \
		init_map.c \
		init_map_utils.c \
		hooks.c \
		movements.c \
		free.c \
		raycasting.c \
		print.c

OBJS    = $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

HEADER  = -Iincludes
LIBFT   = -Llibft -lft
MLX		= -Lmlx
INC     = ${INC_DIR}*.h libft/includes/libft.h

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g3 -I/usr/include -Imlx -O0

LIB_A   = libft/libft.a
MLX_A   = mlx/libmlx.a


all:        ${NAME}

${LIB_A}:   force libft/includes/libft.h
			@make all -C ./libft

${MLX_A}: 	force mlx/mlx.h
			@make -C ./mlx

${NAME}: ${OBJS} ${MLX_A} ${LIB_A}
	@echo "\033[0;34m[OK] \033[0m       \033[0;33m Created  \033[0m: ${NAME}"
	@$(CC) ${OBJS} -Llibft -lft -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o ${NAME}


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile ${INC}
			@mkdir -p $(OBJS_DIR)
			@echo "\033[33;32m[OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
			@$(CC) ${CFLAGS} ${HEADER} -c $< -o $@

check:
			norminette ${SRCS_DIR} ${INC_DIR}

clean:
			@echo "\033[0;31m[OK] \033[0m       \033[0;33m Deleted  \033[0m: ${OBJS}"
			@make clean -C ./libft
			@make clean -C ./mlx
			@rm -f ${OBJS}

fclean:    	clean
			@echo "\033[0;31m[OK] \033[0m       \033[0;33m Deleted  \033[0m: ${NAME}"
			@make fclean -C ./libft
			@rm -rf $(OBJS_DIR)
			@rm -f ${NAME}

re:         fclean all

.PHONY: all clean fclean re force