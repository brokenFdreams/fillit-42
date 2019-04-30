#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 12:34:13 by fsinged           #+#    #+#              #
#    Updated: 2019/04/30 13:08:13 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

PATH = ./fillit/
SRCS = $(PATH)main.c \
$(PATH)fillit.c \
$(PATH)check_data.c \
$(PATH)ft_error.c \
$(PATH)read_file.c \
$(PATH)tetri_list.c \
$(PATH)tetri_map.c \
$(PATH)ft_putstr.c \
$(PATH)ft_putchar.c \
$(PATH)ft_memmove.c \
$(PATH)ft_memset.c \
$(PATH)ft_bzero.c \
$(PATH)ft_lstnew.c \
$(PATH)ft_sqrt.c \
$(PATH)ft_strdel.c \
$(PATH)ft_strlen.c \
$(PATH)ft_strsub.c \
$(PATH)ft_strnew.c \
$(PATH)ft_strdup.c
FLAGS = -Wall -Wextra -Werror
NAME = fillit

all:$(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@make clean -C ./libft/

fclean:clean
	@make fclean -C ./libft/
	@rm -f $(NAME)
