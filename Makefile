SRCS =	builtins/echo.c \
		err_mngment/err_stx.c \
		ft_arg_div.c \
		ft_ent_var.c \
		ft_minishell.c \
		ft_shell_split.c \
		ft_specials.c \
		ft_xtr.c \
		ft_xtr_allsz.c \
		input_err/err_dobpip.c \
		input_err/err_nolstpar.c \
		input_err/err_red.c \
		input_err/err_redsegred.c \
		input_err/err_sim_red.c \
		input_err/start_end_pip.c \
		input_err/start_end_red.c \
		pruebas/prueba_add_history.c \
		pruebas/prueba_env.c \
		pruebas/prueba_ft_strjoin.c \
		ft_executor.c \
		ft_mini-utils.c \
		ft_exec_files.c \
		ft_exec_opens.c \
		ft_builtins.c

INC = -I libft -lreadline
NAME = minishell.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
GNLINE = ./get_next_line/get_next_line.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(LIBFT) $(GNLINE) $(PRINTF) $(OBJS)
	@gcc $(CFLAGS) $(SRCS) $(LIBFT) $(GNLINE) $(PRINTF) $(INC) -o minishell
	@ar rc $(NAME) $(OBJS)

$(LIBFT):
	@make -sC ./libft

$(GNLINE):
	@make -sC ./get_next_line

$(PRINTF):
	@make -sC ./ft_printf

clean:
	@make -C libft clean
	@make -C get_next_line clean
	@make -C ft_printf clean
	@rm -rf $(OBJS) minishell

fclean:	clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@make -C get_next_line fclean
	@make -C ft_printf fclean

re:	fclean all

.PHONY: all clean re lib fclean
