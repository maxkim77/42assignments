# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 19:44:31 by jeongkim          #+#    #+#              #
#    Updated: 2025/02/09 20:25:16 by jeongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR = ./sources/
UTILS_DIR = utils/
PROCESS_DIR = process/

SRC = main.c $(PROCESS_DIR)ft_check_args.c $(PROCESS_DIR)ft_check_dict.c $(PROCESS_DIR)ft_free.c $(PROCESS_DIR)ft_process.c $(PROCESS_DIR)ft_parse_dict.c \
	$(PROCESS_DIR)ft_print1.c $(PROCESS_DIR)ft_print2.c $(PROCESS_DIR)ft_split_by_three.c $(UTILS_DIR)ft_condition.c $(UTILS_DIR)ft_putchar.c \
	$(UTILS_DIR)ft_putstr.c $(UTILS_DIR)ft_split.c $(UTILS_DIR)ft_strcmp.c $(UTILS_DIR)ft_strlen.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

SRCS_OBJ = $(SRCS:.c=.o)

HEADER_DIR = ./includes/

DICT_DIR = ./dicts/

CC = cc

CFLAGS = -Wall -Wextra -Werror

OUTPUT = rush-02

all : $(OUTPUT)

.c.o:
	${CC} ${CFLAGS} -I ${HEADER_DIR} -c $< -o ${<:.c=.o}

$(OUTPUT) : $(SRCS_OBJ)
	${CC} ${CFLAGS} -o ${OUTPUT} ${SRCS_OBJ}

clean :
	rm -f $(SRCS_OBJ)

fclean : clean
	rm -f $(OUTPUT)

re : fclean all

.PHONY : all clean fclean re
