# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:43:04 by ambouren          #+#    #+#              #
#    Updated: 2021/11/30 15:35:12 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

# VARIABLE
NAME	=	libftprintf.a
CC		=	gcc
LC		=	ar crs
CFLAGS	=	-Wall \
			-Wextra \
			-Werror
INC_PATH=	includes/
INCLUDES=	ft_printf.h
SRC		=	ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putmajhex.c \
			ft_puthex.c \
			ft_putadd.c \
			ft_printf.c \
			ft_strichr.c \
			ft_putuns.c
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))

OBJ_PATH=	obj/
OBJ 	=	$(addprefix $(OBJ_PATH),$(SRC:.c=.o))

# COMPILATION
$(NAME)		:	$(OBJ)
	$(LC) $@ $^

$(OBJ)		:	$(INC_PATH)$(INCLUDES)

$(OBJ_PATH)%.o		:	%.c
	@mkdir -p obj
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH)

# RULES
all		:	$(NAME)

clean	:
	rm -rf $(OBJ_PATH)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
