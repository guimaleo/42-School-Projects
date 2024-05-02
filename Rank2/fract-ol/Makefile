NAME = fractol.a

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = include
MAIN_SRC = main.c
FT_PRINTF_DIR= ./include/ft_printf
PRINTFLIB= $(FT_PRINTF_DIR)/libftprintf.a

SRC_FILES = window.c hooks.c image.c error.c fractals.c \
	    string_utils.c math_utils.c inst.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ofast

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

PROGRAM = fractol

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR)
	@ar -crs $(NAME) $(OBJ)
	@echo "\nFract-ol compiled!\n"

	@$(CC) $(CFLAGS) -I./minilibx-linux -L./include/minilibx-linux/ -o $(PROGRAM) $(MAIN_SRC) $(NAME) $(PRINTFLIB) -lmlx -lXext -lX11 -lm -lz
	@echo "\n ./fractol ready to run!\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -g $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\n$(PROGRAM) objects deleted!\n"

fclean: clean
	@rm -f $(NAME) $(PROGRAM)
	@echo "\n$(PROGRAM) and $(NAME) deleted!\n"
re: fclean all

#program: re
#	@echo "\n\nExecuting $(PROGRAM)!\n"
#	@./$(PROGRAM) Mandelbrot
#
#val: $(MAIN_SRC) $(NAME)
#	$(CC) $(CFLAGS) -I./minilibx-linux -L./include/minilibx-linux -g -o $(PROGRAM) $(MAIN_SRC) $(NAME) -lmlx -lXext -lX11 -lm -lz
#	@echo "\n\nExecuting $(PROGRAM) with valgrind!\n"
#	@valgrind ./$(PROGRAM)
#
#show: $(MAIN_SRC) $(NAME)
#	$(CC) $(CFLAGS) -I./minilibx-linux -L./include/minilibx-linux -g -o $(PROGRAM) $(MAIN_SRC) $(NAME) -lmlx -lXext -lX11 -lm -lz
#	@echo "\n\nExecuting $(PROGRAM) with valgrind!\n"
#	@valgrind --leak-check=full --show-leak-kinds=all ./$(PROGRAM) Mandelbrot
#
.PHONY: all clean fclean re program val show
