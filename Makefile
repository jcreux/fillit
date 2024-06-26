# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcreux <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 05:29:33 by jcreux            #+#    #+#              #
#    Updated: 2019/03/11 17:17:32 by jcreux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Werror -Wextra -Wall

SRCS = valid_line.c \
	   read.c \
	   array_maker.c \
	   check_array.c \
	   init_square.c \
	   len_square.c \
	   size_tetri.c \
	   find_coords.c \
	   new_square.c \
	   check_space.c \
	   solve.c \
	   main.c

LIB = libft/

OBJS = $(SRCS:c=o)

all: $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): lib $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIB)libft.a -I $(LIB) -o $(NAME)

lib:
		make -C $(LIB)

clean:
		rm -f $(OBJS)
		make -C $(LIB) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIB) fclean

re: fclean all

.PHONY: clean fclean re all lib
