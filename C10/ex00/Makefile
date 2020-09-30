# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/25 12:32:24 by calide-n          #+#    #+#              #
#    Updated: 2020/09/25 13:11:18 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_display_file
SRC		= ft_display_file.c 

all: $(NAME)
$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc $(SRC) -o $(NAME)
clean:
	rm -rf ft_display_file.o
fclean: clean
	rm -rf $(NAME)
re:	fclean all
