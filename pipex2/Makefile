# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 10:50:57 by jodone            #+#    #+#              #
#    Updated: 2025/12/17 11:02:36 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=pipex

SRC_DIR= src/
BONUS_DIR= bonus/

SRC= $(SRC_DIR)pipex.c \
	$(SRC_DIR)find_path.c \
	$(SRC_DIR)struct_init.c

SRC_BONUS= $(SRC_DIR)find_path.c \
			$(SRC_DIR)struct_init.c \
			$(BONUS_DIR)pipex_bonus.c

INCLUDES=-I pipex.h \
		-I Great_Libft/Libft \
		-I Great_Libft/ft_printf \
		-I Great_Libft/GNL \

OBJECT=$(SRC:.c=.o)
OBJECT_BONUS=$(SRC_BONUS:.c=.o)
LIBFT= ./Great_Libft/g_libft.a
CFLAGS=-Wall -Wextra -Werror -g 

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJECT) $(LIBFT) -o $(NAME)
		@echo "Compil Success"

bonus: $(OBJECT_BONUS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJECT_BONUS) $(LIBFT) -o $(NAME)
		@echo "Compil bonus Success"

$(LIBFT):
		@$(MAKE) -C Great_Libft --no-print-directory

%.o: %.c
		@$(CC) $(CFLAGS) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJECT)
		@rm -f $(OBJECT_BONUS)
		@$(MAKE) -C Great_Libft clean --no-print-directory
		@echo "clean success"

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) -C Great_Libft fclean --no-print-directory
		@echo "fclean success"
		
re: fclean all

.PHONY: all clean fclean re bonus