# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 12:19:14 by calide-n          #+#    #+#              #
#    Updated: 2020/09/22 16:32:12 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_tail
SRCS	= ft_utilities.c \
		  ft_tail.c
all: $(NAME)
$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRCS)
	gcc -o $(NAME) ft_utilities.o ft_tail.o
clean:
	rm -rf ft_tail.o ft_utilities.o
fclean: clean
	rm -rf $(NAME)
re:	fclean all
