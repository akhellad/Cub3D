# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 15:48:44 by akhellad          #+#    #+#              #
#    Updated: 2024/01/05 15:48:49 by akhellad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re bonus

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

LIST_HEADERS = libft.h
SRCS =			ft_isalnum.c		\
				ft_atoi.c			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_strchr.c			\
				ft_strdup.c			\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strncmp.c		\
				ft_strcmp.c			\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_strmapi.c		\
				ft_itoa.c			\
				ft_split.c			\
				ft_striteri.c		\
				ft_lstnew_bonus.c			\
				ft_lstsize_bonus.c			\
				ft_lstadd_front_bonus.c		\
				ft_lstlast_bonus.c			\
				ft_lstdelone_bonus.c		\
				ft_lstclear_bonus.c			\
				ft_lstadd_back_bonus.c		\
				ft_lstiter_bonus.c			\
				ft_lstmap_bonus.c			\
				ft_printf.c					\
				ft_printf_utils.c			\
				get_next_line.c				\
				get_next_line_utils.c		\
				ft_is_white_spaces.c		

DIR_HEADERS 	= ./
DIR_OBJS 		= .objs/
RM				= rm -rf
CC				= cc

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:.c=.o))

all : $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(LIST_HEADERS) Makefile
	$(AR) rcs $(NAME) $(OBJS)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

$(DIR_OBJS)%.o: %.c $(LIST_HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
