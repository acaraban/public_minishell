# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 20:35:31 by acaraban          #+#    #+#              #
#    Updated: 2023/08/28 12:45:00 by msintas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strcpy.c ft_strlcpy.c \
ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_substr.c ft_strjoin.c  ft_strmapi.c ft_strtrim.c ft_itoa.c ft_split.c \
ft_striteri.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
ft_num_times.c

OBJS	=	${SRCS:.c=.o}

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all : $(NAME)

$(NAME): 
	@${CC} -c ${CFLAGS} ${SRCS}
	@ar rs ${NAME} ${OBJS}
	
# Rule to remove all files and directory
clean: 
		@${RM} ${OBJS}
		@echo "Clean libft"
# Rule to remove
fclean:		clean
			@${RM} ${NAME}
			@echo "Force clean with remove"
# Rule to re-make all
re:	fclean all

# Rule for reserve this names and not exist files with this names
.PHONY: all, clean, fclean, re
