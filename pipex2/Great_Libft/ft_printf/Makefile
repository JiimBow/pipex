# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 14:03:28 by jodone            #+#    #+#              #
#    Updated: 2025/11/06 11:16:32 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
INCLUDES=-I ft_printf.h
CC=cc
FILES= 	ft_bzero.c \
		ft_strlen.c \
		ft_putnbr_base.c \
		ft_uputnbr_base.c \
		ft_itoax.c \
		ft_putstr_print.c \
		ft_putchar_print.c \
		ft_ulputnbr_ptr.c \
		ft_printf.c 
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
