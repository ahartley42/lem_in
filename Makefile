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

NAME = lem_in.a
LEM = Lem-in
LIBFT = -L./libft -lft
FLAGES = -Wall -Wextra -Werror
GCC = gcc
SRC = *.c
OPTION = -c $(SRC)
OBJ = *.o

all: $(LEM)

$(NAME):
	$(GCC) $(FLAGES) $(OPTION)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	cd libft && make fclean
	rm -f $(LEM)
re:	fclean	all

$(LEM):	$(NAME)
	cd libft && make all
	$(GCC) $(FLAGES) $(LEM).c $(NAME) $(LIBFT) -o $(LEM)