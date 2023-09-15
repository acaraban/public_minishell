SRCS =	builtins/custom_echo.c \
		builtins/custom_env.c \
		builtins/custom_export.c \
		builtins/custom_exit.c \
		builtins/custom_pwd.c \
		builtins/custom_unset.c \
		builtins/custom_cd.c \
		builtins/custom_cd_utils.c \
		builtins/custom_cd_extra.c \
		err_mngment/err_stx.c \
		err_mngment/err_cmd.c \
		err_mngment/err_execve.c \
		ft_arg_div.c \
		ft_arg_div_more.c \
		ft_ent_var.c \
		ft_ent_var_more.c \
		ft_minishell.c \
		ft_shell_split.c \
		ft_shell_split_extra.c \
		ft_shell_split_more.c \
		ft_specials.c \
		ft_specials_1_5.c \
		ft_specials_6_10.c \
		dbl_utils/ft_dbl_printf.c \
		dbl_utils/ft_new_dbl.c \
		dbl_utils/ft_xtr.c \
		dbl_utils/ft_xtr_allsz.c \
		input_err/err_dobpip.c \
		input_err/err_nolstpar.c \
		input_err/err_red.c \
		input_err/err_redsegred.c \
		input_err/err_sim_red.c \
		input_err/start_end_pip.c \
		input_err/start_end_red.c \
		ft_start_stuff.c \
		ft_executor.c \
		ft_mini-utils.c \
		ft_all_children.c \
		ft_check_cmds.c \
		ft_exec_files.c \
		ft_exec_cmds.c \
		ft_exec_dups.c \
		ft_type_red_pars_salsim.c \
		ft_type_red_pars_saldbl.c \
		ft_type_red_pars_entsim.c \
		ft_type_red_pars_entdbl.c \
		ft_heredoc.c \
		ft_heredoc_more.c \
		input_err/err_dobcom.c \
		ft_new_arch.c \
		ft_init_args.c \
		ft_norminette.c \
		ft_arg_div_extr.c \
		ft_extra_utils.c



INC = -I libft -I /opt/vagrant/embedded/include
NAME = minishell.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
GNLINE = ./get_next_line/get_next_line.a
CFLAGS = -g -Wall -Wextra -Werror $(INC)
# CFLAGS = -Wall -Wextra -Werror $(INC)
LIBS	= -lreadline -L/opt/vagrant/embedded/lib

all: $(NAME)

$(NAME):	$(LIBFT) $(GNLINE) $(PRINTF) $(OBJS)
	@gcc $(CFLAGS) $(OBJS) $(LIBFT) $(GNLINE) $(PRINTF) -g -o minishell $(LIBS)
#	@ar rc $(NAME) $(OBJS)

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
