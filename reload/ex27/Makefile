# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongkim <jeongkim@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 16:58:07 by jeongkim          #+#    #+#              #
#    Updated: 2025/03/30 16:58:09 by jeongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = ft_display_file
CC = cc -Wall -Wextra -Werror
SRC = ft_display_file.c
OBJ = $(SRC:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
