# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/25 11:29:48 by ttshivhu          #+#    #+#              #
#*   Updated: 2018/08/29 18:24:48 by ttshivhu         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = computor
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iglibft -I.
SRC = lists.c math.c read.c main.c \

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@make -C glibft
	gcc $(OBJ) $(CFLAGS) -Lglibft -lftg -o $(NAME)
	@printf "\x1b[32mCompiled $(NAME)\x1b[0m\n"

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
