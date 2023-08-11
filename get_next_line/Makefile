NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c

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

.PHONY: all, clean, fclean