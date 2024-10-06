OBJ_DIR= obj
SRC_DIR= src
INC_DIR= inc
FT_PRINTF_DIR= ./inc/ft_printf

SERVER= server
CLIENT= client

CC= cc
CFLAGS= -Wall -Werror -Wextra -g

SRC_S= $(SRC_DIR)/server.c $(SRC_DIR)/strutils.c
OBJ_S= $(OBJ_DIR)/server.o $(OBJ_DIR)/strutils.o
SRC_C= $(SRC_DIR)/client.c
OBJ_C= $(OBJ_DIR)/client.o $(OBJ_DIR)/strutils.o

PRINTFLIB= $(FT_PRINTF_DIR)/libftprintf.a

all: $(SERVER) $(CLIENT)

$(PRINTFLIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(SERVER): $(PRINTFLIB) $(OBJ_S)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_S) $(PRINTFLIB)

$(CLIENT): $(PRINTFLIB) $(OBJ_C)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_C) $(PRINTFLIB)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean

