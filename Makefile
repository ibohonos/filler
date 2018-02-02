# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 17:16:16 by ibohonos          #+#    #+#              #
#    Updated: 2018/02/02 19:37:02 by ibohonos         ###   ########.fr        #
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
SRC_NAME	= filler.c main.c ft_find_player.c ft_find_map.c ft_find_tetri.c \
				ft_place_line_map.c ft_place_line_tetri.c ft_place_map.c \
				ft_find_place.c ft_check_place.c ft_len.c ft_find_spase.c \
				ft_len_btw.c ft_init_map.c ft_free_arr.c
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ 		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_NAME))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\x1B[3;34mCompilling:\x1B[0m \x1B[3;33m$<\x1B[0m"
	@$(CC) $(FLAGS) -I $(LIB_INC) -I $(INCL_DIR) -c $< -o $@

$(NAME):
	@echo "\x1B[3;32mCompilling LIBFT\x1B[0m"
	@make -C libft
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@echo "\x1B[3;32mCreate bot\x1B[0m"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) -L $(LIB_DIR) -lft
	@cp $(NAME) players/

clean:
	@echo "\x1B[3;31mCleaning LIBFT objects\x1B[0m"
	@make -C libft clean
	@echo "\x1B[3;31mCleaning objects\x1B[0m"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\x1B[3;31mCleaning LIBFT exe\x1B[0m"
	@make -C libft fclean
	@echo "\x1B[3;31mCleaning exe\x1B[0m"
	@/bin/rm -f $(NAME)
	@/bin/rm -f players/$(NAME)

re: fclean all

visual: all
	@echo "\x1B[3;32mCreate visual\x1B[0m"
	@gcc -Wall -Wextra -Werror -o bonus srcs/bonus.c -I libft/includes libft/libft.a
