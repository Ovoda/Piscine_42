# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 10:59:04 by calide-n          #+#    #+#              #
#    Updated: 2020/09/22 12:49:15 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= do-op
SRC_PATH		= srcs
SRC_NAME		= ft_ope_functions.c \
				  ft_atoi.c \
				  ft_putnbr.c 
SRC				= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
RM		= rm -rf

all:	$(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) main.c 
	gcc -o $(NAME) ft_ope_functions.o ft_atoi.o ft_putnbr.o main.o

clean:
	$(RM) ft_ope_functions.o ft_atoi.o ft_putnbr.o main.o

fclean: clean
	$(RM) $(NAME)

re:	fclean all
