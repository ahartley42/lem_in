# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 10:39:52 by svan-nie          #+#    #+#              #
#    Updated: 2019/05/20 11:17:04 by svan-nie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGES = -Wall -Wextra -Werror
GCC = gcc
SRC = *.c
OPTION = -c $(SRC)
OBJ = *.o

all: $(NAME)

$(NAME):
	$(GCC) $(FLAGS) $(OPTION)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

so:
	gcc -c ft_*.c -Wall -Wextra -Werror
	gcc -shared -o libft.so -fPIC ft*.o
	rm *.o

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

