# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 17:16:16 by ibohonos          #+#    #+#              #
#    Updated: 2018/01/11 00:04:45 by ibohonos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ibohonos.filler

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ_DIR		= ./obj
LIB_DIR		= ./libft
LIB_INC		= $(LIB_DIR)/includes
SRC_DIR 	= ./srcs
INCL_DIR 	= ./includes
SRC_NAME	= filler.c main.c
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ 		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_NAME))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\x1B[33mCompilling $<\x1B[0m"
	@$(CC) $(FLAGS) -I $(LIB_INC) -I $(INCL_DIR) -c $< -o $@

$(NAME):
	mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) -L $(LIB_DIR) -lft

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
