# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 18:38:03 by rde-oliv          #+#    #+#              #
#    Updated: 2020/08/05 16:55:44 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJ = $(SRC:.s=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.s
	nasm $< -f elf64 -o $@

test: $(NAME) main.c
	gcc -no-pie $(CFLAGS) main.c $(NAME) -o test

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all
