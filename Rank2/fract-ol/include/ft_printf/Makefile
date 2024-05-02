# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 18:54:37 by lede-gui          #+#    #+#              #
#    Updated: 2023/10/16 19:44:47 by lede-gui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = ./src
SRC = ft_printf.c ft_convert_any_base.c ft_putchar.c\
      ft_putnbr.c ft_putptr.c ft_putstr.c \
      ft_putunsigned.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
#MAIN_SRC = main.c
PROGRAM = printf
INC = -Iincludes/

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

#program: all $(MAIN_SRC)
#	@$(CC) $(CFLAGS) $(INC) -o $(PROGRAM) $(MAIN_SRC) $(NAME)
#	@./printf

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(PROGRAM) $(NAME)

re: fclean all program

.PHONY: all program clean fclean re
