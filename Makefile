# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 12:24:13 by oukrifa           #+#    #+#              #
#    Updated: 2017/04/25 13:06:01 by oukrifa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC_PATH = ./
OBJ_PATH = ./obj/
INC_PATH = ./

NAME = fillit

SRC_NAME = check.c \
		   main.c \
		   algo.c \
		   ft_fillmap.c \
		   map.c \
		   move_up_left.c \
		   reading.c \
		   ft_strlen.c \
		   ft_stock.c \
		   ft_strcat.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[33mCompilation OBJ done !\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32mCompilation EXE done !\033[0m"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rfv $(OBJ_PATH)
	@rm -f $(TMP)
	@echo "\033[36mClean !\033[0m"

fclean : clean
	@rm -fv $(NAME)

re : fclean all
