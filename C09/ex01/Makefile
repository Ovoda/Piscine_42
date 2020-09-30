# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 20:39:15 by calide-n          #+#    #+#              #
#    Updated: 2020/09/18 16:06:32 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS 		=	-I$(INC_PATH)
AR 			= 	ar
ARFLAGS 	=	rcs
RM			=	rm -rf
INC_PATH 	=	 includes
INC_NAME	=	ft.h
SRC_PATH 	= 	srcs
SRC_NAME 	=	ft_putchar.c \
				ft_swap.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_strcmp.c
INC 		=	$(addprefix $(INC_PATH)/, $(INC_NAME))
SRC 		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
.SUFFIXES: 		.c .o .h
OBJ 		=	 $(SRC:.c=.o)
all			:	$(NAME)
$(NAME)		:	$(OBJ) $(INC)
				$(AR) $(ARFLAGS) $(NAME) $(OBJ)
%.o: %.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
clean		:
				$(RM) $(OBJ)
fclean		:	clean
				$(RM) $(NAME)
re			: 	fclean all
.PHONY: 		all fclean clean re
