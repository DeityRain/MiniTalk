# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your_login <your_login@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/XX/XX XX:XX:XX by your_login       #+#    #+#              #
#    Updated: 2024/XX/XX XX:XX:XX by your_login      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program names
CLIENT = client
SERVER = server

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
CLIENT_SRC = client.c
SERVER_SRC = server.c

# Object files
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Default target
all: $(LIBFT) $(CLIENT) $(SERVER)

# Build libft
$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)

# Build client
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@echo "$(GREEN)Building client...$(RESET)"
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)
	@echo "$(GREEN)Client built successfully!$(RESET)"

# Build server
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@echo "$(GREEN)Building server...$(RESET)"
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)
	@echo "$(GREEN)Server built successfully!$(RESET)"

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@make -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	rm -f $(CLIENT) $(SERVER)
	@make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re