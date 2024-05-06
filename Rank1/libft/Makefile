# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 13:17:56 by lede-gui          #+#    #+#              #
#    Updated: 2023/10/16 13:59:13 by lede-gui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
      ft_toupper.c ft_tolower.c\
      ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
      ft_memcmp.c ft_calloc.c ft_memchr.c\
      ft_strlen.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c\
      ft_strjoin.c ft_strncmp.c ft_atoi.c ft_strdup.c ft_substr.c\
      ft_strlcpy.c ft_strtrim.c ft_itoa.c ft_split.c ft_striteri.c\
      ft_strmapi.c\
      ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c

BONUS_SRC = ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c\
	    ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c\
	    ft_lstlast.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

MAIN_SRC = darth.c
PROGRAM = sith

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar -crs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(PROGRAM)

bonus: .libftbonus.a

.libftbonus.a: $(BONUS_OBJ) $(OBJ)
	@ar -crs .libftbonus.a $(OBJ) $(BONUS_OBJ)
	@echo ar -crs $(NAME) $(OBJ) $(BONUS_OBJ)
	@cp .libftbonus.a libft.a

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

program: all bonus
	$(CC) $(CFLAGS) -o $(PROGRAM) $(MAIN_SRC) $(NAME)
	@./$(PROGRAM)

re: fclean all

.PHONY: all clean fclean bonus program
