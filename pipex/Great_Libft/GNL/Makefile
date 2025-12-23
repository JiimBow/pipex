# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:13:17 by jodone            #+#    #+#              #
#    Updated: 2025/11/06 11:15:01 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=GNL.a
INCLUDES=-I get_next_line.h
CC=cc
FILES= 	get_next_line.c \
		get_next_line_utils.c
CFLAGS=-Wall -Wextra -Werror
OBJECT=$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
		@ar rcs $(NAME) $(OBJECT)

%.o: %.c
		@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
		@rm -f $(OBJECT)

fclean: clean
		@rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
