# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 17:16:16 by ibohonos          #+#    #+#              #
#    Updated: 2018/01/10 18:51:49 by ibohonos         ###   ########.fr        #
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
OBJ 		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC 		= filler.c main.c

all: $(NAME)

$(SRC_DIR)/%.c:$(OBJ_DIR)/%.o
	$(CC) $(FLAGS) -I $(LIB_INC) -I $(INCL_DIR) -o $< -c $@

$(NAME):
	make -C libft/
	mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) -L $(LIB_DIR) -lft

clean:
	make -C libft/ clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
