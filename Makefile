#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 12:34:13 by fsinged           #+#    #+#              #
#    Updated: 2019/05/07 16:31:59 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

PATH =
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
$(PATH)ft_strdel.c \
y$(PATH)ft_lstnew.c \
$(PATH)ft_lstdel.c \
$(PATH)ft_lstdelone.c \
$(PATH)ft_sqrt.c
OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
NAME = fillit

all:$(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:clean
	@rm -f $(NAME)

re:fclean all
