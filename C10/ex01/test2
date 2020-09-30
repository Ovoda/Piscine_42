# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 11:37:49 by calide-n          #+#    #+#              #
#    Updated: 2020/09/25 14:14:15 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_cat
SRC		= ft_cat.c
all: $(NAME)
$(NAME): $(SRC)
	gcc -Wall -Wextra -Werror -c $(SRC) 
	gcc -o $(NAME) ft_cat.o
clean: 
	rm -rf ft_cat.o
fclean: clean
	rm -rf $(NAME)
re: fclean all

