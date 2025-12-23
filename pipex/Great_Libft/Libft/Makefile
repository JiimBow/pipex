# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 12:44:35 by jodone            #+#    #+#              #
#    Updated: 2025/11/06 11:16:15 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
INCLUDES=-I libft.h
CC=cc
FILES= 	ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
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




