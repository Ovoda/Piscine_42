# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: calide-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 18:27:18 by calide-n          #+#    #+#              #
#    Updated: 2020/09/26 21:45:44 by calide-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   rush-02
CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror
IFLAGS      =   -I$(INC_PATH)
AR          =   ar
ARFLAGS     =   rcs
RM          =   rm -rf
INC_PATH    =   .
INC_NAME    =   ft.h
SRC_PATH    =   .
SRC_NAME 	=	ft_display.c \
				ft_error.c \
				ft_input_to_tab.c \
				main.c \
				ft_file_to_struct.c \
				ft_utilities.c
INC         =   $(addprefix $(INC_PATH)/, $(INC_NAME))
SRC         =   $(addprefix $(SRC_PATH)/, $(SRC_NAME))
.SUFFIXES:      .c .o .h
OBJ         =    $(SRC:.c=.o)
all         :   $(NAME)
$(NAME)     :   $(OBJ) $(INC)
				$(CC) -o $(NAME) $(OBJ)
%.o: %.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
clean       :
				$(RM) $(OBJ)
fclean      :   clean
				$(RM) $(NAME)
re          :   fclean all
.PHONY:         all fclean clean re
