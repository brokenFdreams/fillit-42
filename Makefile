#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 12:34:13 by fsinged           #+#    #+#              #
#    Updated: 2019/04/29 12:45:52 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CMD = make -C libft/ make clean -C libft/
PATH = ./src/
SRCS = $(PATH)main.c \
$(PATH)fillit.c \
$(PATH)check_data.c \
$(PATH)ft_error.c \
$(PATH)read_file.c \
$(PATH)tetri_list.c
HEADER = ./icludes/fillit.h
FLAGS = -Wall -Wextra -Werror
NAME = fillit

all:$(CMD)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)

cmd:
	@make -C libft/ make clean -C libft/

clean:
	@make fclean -C libft/

fclean:clean
	@rm -f $(NAME)