# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 20:39:15 by calide-n          #+#    #+#              #
#    Updated: 2020/09/28 15:30:57 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	bsq
LIB			= 	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS 		=	-I$(INC_PATH)
AR 			= 	ar
ARFLAGS 	=	rcs
RM			=	rm -rf
INC_PATH 	=	.
INC_NAME	=	bsq.h
LIB_SRC_PATH 	= 	libft_srcs
LIB_SRC_NAME 	=	ft_atoi.c \
				ft_split.c \
				ft_strdup.c
SRC_PATH	= .
SRC_NAME	=	ft_input_to_struct.c \
				ft_check_matrice.c \
				ft_solver.c \
				ft_create_tab.c \
				ft_display.c \
				main.c 
INC 		=	$(addprefix $(INC_PATH)/, $(INC_NAME))
LIB_SRC 	=	$(addprefix $(LIB_SRC_PATH)/, $(LIB_SRC_NAME))
SRC 		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
.SUFFIXES: 		.c .o .h
LIB_OBJ 	=	 $(LIB_SRC:.c=.o)
OBJ 		=	 $(SRC:.c=.o)
all			:	$(NAME)
lib			:	$(LIB_OBJ)
				$(AR) $(ARFLAGS) $(LIB) $(LIB_OBJ)
%.o: %.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME)		:	lib
				$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)
clean		:
				$(RM) $(OBJ)
fclean		:	clean
				$(RM) $(NAME)
				$(RM) $(LIB)
re			: 	fclean all
.PHONY: 		all fclean clean re
