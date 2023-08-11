# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 13:26:45 by acaraban          #+#    #+#              #
#    Updated: 2022/08/22 16:03:14 by acaraban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_itoa.c ft_strlen.c libftprintf.c ft_print_decimal.c ft_print_hexadecimal.c \
ft_print_string.c ft_printchar.c

OBJS = $(SRCS:.c=.o)

COMP = gcc -c -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

$(NAME):	$(OBJS)
	@${COMP} ${SRCS}
	@ar crs ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}
	@echo "Clean libftlibft"

fclean:	clean
		@${RM} ${NAME} eject.o
		@echo "Force clean with remove"

re: fclean all

.PHONY: all, clean, fclean, re
	