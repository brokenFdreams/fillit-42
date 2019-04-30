#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 12:34:13 by fsinged           #+#    #+#              #
#    Updated: 2019/04/30 12:51:31 by fsinged          ###   ########.fr        #
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
./libft/libft.a
HEADER = ./icludes/fillit.h
FLAGS = -Wall -Wextra -Werror
NAME = fillit

all:$(NAME)

$(NAME):
	make -C ./libft
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@make clean -C ./libft/

fclean:clean
	@make fclean -C ./libft/
	@rm -f $(NAME)
