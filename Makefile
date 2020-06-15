# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 17:51:26 by svan-nie          #+#    #+#              #
#    Updated: 2020/06/03 17:51:26 by svan-nie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM = lem-in
LIBFT = -L./libft -lft
LIBFT_A = libft/libft.a
FLAGS = -Wall -Wextra -Werror
GCC = gcc

SRC_PATH = srcs/
OBJ_PATH = obj/

SRC = check_int.c free.c main.c read_map.c check_ants.c ft_strlen_modified.c verify_map_add_data.c initialize_struct.c add_rooms.c ft_strlen_modified_two.c ft_strcpy_modified.c error.c
OBJ = $(SRC:%.c=%.o)

OBJ_USAGE = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(LEM)

$(LEM):	$(OBJ_PATH) $(OBJ_USAGE) $(LIBFT_A)
	$(GCC) $(FLAGS) -o $@ $(OBJ_USAGE) $(LIBFT)

$(LIBFT_A):
	cd libft && make

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(GCC) $(FLAGS) -c $^ -o $@ -I ./includes

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	cd libft && make clean
	rm -rf $(OBJ_PATH)

fclean:	clean
	cd libft && make fclean
	rm -f $(LEM)

re:	fclean	all
	cd libft && make re