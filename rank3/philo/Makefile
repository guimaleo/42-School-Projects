NAME= philo

OBJ_DIR= obj
SRC_DIR= src
INC_DIR= inc


CC= cc
CFLAGS= -Wall -Werror -Wextra -g -fsanitize=thread -pthread -I$(INC_DIR)

SRC_FILES= main.c chars_basic.c str_utils.c welcome.c

SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

PROGRAM= philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean

