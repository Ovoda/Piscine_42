# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 20:39:15 by calide-n          #+#    #+#              #
#    Updated: 2020/09/30 22:59:53 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bsq

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address
RM			=	rm -rf

SRC_PATH	= .

SRC_NAME	=	ft_input_to_struct.c \
				ft_solver.c \
				ft_atoi.c \
				ft_parsing.c \
				main.c \
				ft_stdin_to_struct.c \

SRC 		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))

LIB_OBJ 	=	 $(LIB_SRC:.c=.o)

OBJ 		=	 $(SRC:.c=.o)

all			:	$(NAME)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJ)
				$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)
clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)
				$(RM) $(LIB)

re			: 	fclean all

.PHONY: 		all fclean clean re
