# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 10:31:35 by jodone            #+#    #+#              #
#    Updated: 2025/11/06 15:08:20 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=g_libft.a
CFLAGS=-Wall -Wextra -Werror
INCLUDES=-I 
CC=cc
FILES= 	

LIBFTDIR=Libft
PRINTFDIR=ft_printf
GNLDIR=GNL


LIBFTA=$(LIBFTDIR)/libft.a
PRINTFA=$(PRINTFDIR)/libftprintf.a
GNLA=$(GNLDIR)/GNL.a

OBJECT=$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFTA) $(PRINTFA) $(GNLA)
		@ar rcsT $@ $^

$(LIBFTA): $(LIBFTDIR)
		@$(MAKE) -C $(LIBFTDIR)

$(PRINTFA): $(PRINTFDIR)
		@$(MAKE) -C $(PRINTFDIR)

$(GNLA): $(GNLDIR)
		@$(MAKE) -C $(GNLDIR)

%.o: %.c
		$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
		@$(MAKE) clean -C $(LIBFTDIR)
		@$(MAKE) clean -C $(PRINTFDIR)
		@$(MAKE) clean -C $(GNLDIR)
		@rm -f $(OBJECT)

fclean: clean
		@rm -f $(NAME) $(LIBFTA) $(PRINTFA) $(GNLA)
		
re: fclean all

.PHONY: all clean fclean re
