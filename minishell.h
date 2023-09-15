/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:11:48 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 13:01:19 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// error sintactico
# define STX_ERR 2
// read end of pipe
# define READ_END 0
// write end of pipe
# define WRITE_END 1

typedef struct s_entvar
{
	int			i;
	int			par;
	char		*aux;
}				t_entvar;

typedef struct s_addvarent
{
	int			i;
	char		*aux;
	char		*add;
	char		*aux2;
}				t_addvarent;

typedef struct s_here
{
	char		*val;
	char		*new;
	char		*aux;
	int			i;
	int			r;
	int			boo;
	int			fd;
}				t_here;

typedef struct s_red
{
	int			r;
	char		**cmd_str;
}				t_red;

typedef struct s_typered
{
	char		**cmd_str;
	char		**ac;
	int			i;
	int			h;
}				t_typered;

typedef struct s_num
{
	int			i;
	int			cont;
	int			boo;
	char		**vue;
	int			ent;
}				t_num;

typedef struct s_xtr
{
	char		**jj;
	int			i;
	int			h;

}				t_xtr;

typedef struct s_shell
{
	int			i;
	int			j;
	int			k;
	int			aux;
}				t_shell;

typedef struct s_executor
{
	pid_t		pid;
	int			status;
}				t_executor;

typedef struct s_custom
{
	char		*command_arg;
	char		*last_pwd;
	char		*current_pwd;
	int			is_switch;
}				t_custom;

typedef struct s_global
{
	int			num_cmd;
	char		**env;
	char		*environ_path;
	int			err_stat;
	int			new_stat;
}				t_global;

typedef struct s_content
{
	char		*access_path;
	char		*cmd;
	char		**full_comand;
	char		*infile;
	char		*outfile;
	int			infile_fd;
	int			outfile_fd;
	int			nfl;
	int			tfl;
	int			builtin;
	int			which_builtin;
	t_global	*global;
	t_custom	*custom;
}				t_content;

int				main(int argc, char **argv, char **env);
t_global		*ft_init(t_global *glb, char **env);
int				frst_chr(char *txt, char car);
int				all_chr(char *txt, int pos);
int				str_cmp(char *txt, int pos, char *cmp, char car);
char			*ft_ent_var(char *txt, int pos, char **env, t_content *cont);
char			*ft_add_varent(char *txt, int pos, char **env, t_content *cont);
void			init_ent_vars(t_entvar *entvar);
void			check_aux_set_par(t_entvar *entvar, char **env, char *txt,
					int pos);
void			set_values_vars(t_addvarent *varent, char *txt, int pos);
void			init_add_varent_vars(t_addvarent *varent, char *txt, int pos);
void			check_doble_quot(int pos, char *txt, char *aux);
int				find_match(char *txt, int pos, char c);
char			*del_char(char *txt, int un);
char			**ft_shell_split(char *s, char c, t_content *cont);
void			init_numstring_vars(int *comp, int *cles, int *i);
int				check_match(char *s1, int *i, t_content *cont);
int				check_shell_vars(char *s, t_content *cont);
void			shell_split_bucle(char **dst, int *l, int *j);
void			check_comillas(char *s, char **dst, t_shell *shell);
char			**ft_specials(char *old_txt, t_content *cant);
char			*ft_specials_1(char *old_txt, t_num *num);
char			*ft_specials_2(char *txt, char *old_txt, t_num *num,
					t_content *cant);
int				ft_specials_3(char *txt, t_num *num, t_content *cant);
int				ft_specials_4(char *txt, t_num *num, t_content *cant);
int				ft_specials_5(char *txt, t_num *num, t_content *cant);
int				ft_specials_6(char *txt, t_num *num, t_content *cant);
int				ft_specials_7(char *txt, t_num *num, t_content *cant);
void			ft_specials_8(char *txt, t_num *num);
char			*ft_specials_9(char *txt, t_num *num, t_content *cant,
					char *old_txt);
int				ft_specials_10(char *txt, t_num *num, t_content *cant);
char			*ft_specials_11(char *txt, t_num *num, t_content *cant,
					char *old_txt);
char			**dobl_prt_free(char **arr, char *txt, int inicial, int conta);
void			err_stx(char *txt, t_content *cont);
char			**ft_xtr_allsz_free(char **arr, char **add, int posadd);
int				err_sim_red(char *txt, int i, t_content *cont);
int				err_dobpip(char *txt, int i, t_content *cont);
int				err_red(int i, char *txt, t_content *cont);
int				err_redsegred(char **arr, t_content *cont);
int				start_end_red(char **vue, t_content *cont);
int				err_nolstpar(char *txt, int pos, t_content *cont);
char			**start_end_pip(char **vue, t_content *cont);
int				ft_type_red_entsim(char **final, t_typered *type,
					t_content *cont);
int				ft_type_red_entsim_1(t_typered *type, t_content *cont,
					t_red *red);
int				ft_type_red_entsim_2(t_typered *type, t_content *cont,
					t_red *red);
int				ft_type_red_entsim_3(t_typered *type, t_content *cont);
int				ft_type_red_salsim(char **final, t_typered *type,
					t_content *cont);
int				ft_type_red_salsim_1(t_typered *type, t_content *cont,
					t_red *red);
int				ft_type_red_salsim_2(t_typered *type, t_content *cont,
					t_red *red);
int				ft_type_red_saldbl(char **final, t_typered *type,
					t_content *cont);
int				ft_type_red_saldbl_1(t_typered *type, t_content *cont,
					t_red *red);
int				ft_type_red_saldbl_2(t_typered *type, t_content *cont,
					t_red *red);
char			**ft_type_red_entdbl(char **final, t_typered *type,
					t_content *cont);
void			ft_type_red_entdbl_1(t_typered *type, t_content *cont,
					t_red *red);
void			ft_type_red_entdbl_2(t_typered *type, t_content *cont,
					t_red *red);
char			**ft_dbl_strdup(char **arr);
char			**ft_dbl_strdup_str(char *txt);
char			**ft_elim_str_free(char **arr, int pos);
int				ft_heredoc(char **arr, t_content *cont);
void			here_condition(t_here *here);
void			init_here_vars(t_here *here);
void			bucle_here_aux(t_here *here);
void			free_and_copy(t_here *here);
void			free_no_val(t_here *here, t_content *cont);
void			val_is_aux(t_here *here);
void			open_and_write(t_here *here);
void			free_dbl(char **new);
void			ft_dbl_printf(char *txt, char **arr, char *ftxt, int sal);
int				pos_char(char *txt, char c);
int				bef_str(char *txt);
int				custom_export(t_content *cont, int i);
void			err_cmd(char *txt, t_content *cont);
int				arg_is_valid(char *comand_args);
int				err_dobcom(char *txt, t_content *cont);
int				custom_unset(t_content *cont, int i);
int				coincidence(t_content *cont, char *txt);
int				new_arch(char *name);
int				ft_tam_args(char *txt, t_global *glb);
void			handle_sigint(int sig);
char			**convert_str_trim(char **vue);
int				ft_nrmntt_1(t_global *glb);
void			ft_free_cont(t_content *cont);
void			init_cont_vars(t_global *glb, t_content *cont);
char			*init_argdiv_vars(char *txt);
int				cmd_str_cont(t_content *cont, char **cmd_str, int h);
int				mini_all_type_1(t_typered *type, char **final, t_content *cont);
int				mini_all_type_2(t_typered *type, char **final, t_content *cont);
int				mini_all_type_3(t_typered *type, char **final, t_content *cont);
int				all_type_red(t_typered *type, char **final, t_content *cont);
char			**arg_parsing(char **final, t_content *cont, int *boo);
int				arg_parsing_2(char **final, t_content *cont, int *boo,
					t_typered *type);
void			ft_final_arg(char **ac, t_content *cont);
int				ft_arg_div(char *txt, t_global *glb);
void			init_typered(t_typered *type);
int				check_type_red(t_typered *type, char **final, t_content *cont,
					int *boo);
void			ft_free(void *ttt);
void			ft_executor(t_content *cont, int num);
char			*ft_env_path(char **envp);
char			*ft_access_program(char *environ_path, char *command);
void			manage_infiles(t_content *cont, int i);
void			manage_outfiles(t_content *cont, int i);
void			write_on_the_pipe(int (*fds)[2], int num);
void			read_from_the_pipe(int (*fds)[2], int num);
void			main_closes_pipes(t_content *cont, int i, int (*fds)[2],
					int num);
void			ft_execute_child(t_content *cont, int i, int (*fds)[2],
					int num);
void			execute_first_child(t_content *cont, int i, int (*fds)[2],
					int num);
void			execute_middle_children(t_content *cont, int i, int (*fds)[2],
					int num);
void			execute_last_child(t_content *cont, int i, int (*fds)[2],
					int num);
int				is_builtin_noredir(t_content *cont, int i);
int				is_builtin(t_content *cont, int i);
int				arg_is_a_path(char *comand_args);
void			exec_builtin(t_content *cont, int i);
void			execute_command(t_content *cont, int i);
void			custom_echo(t_content *cont, int i);
void			custom_pwd(void);
void			custom_env(t_content *cont, int i);
int				custom_cd(t_content *cont, int i);
void			custom_exit(t_content *cont, int i);
char			*custom_return_pwd(void);
void			update_environment_new(t_content *cont, int i, char *new_pwd);
void			update_environment_old(t_content *cont, int i, char *old_pwd);
char			*get_the_oldpwd(t_content *cont, int i);
void			handle_execve_error_message(t_content *cont, int i);
void			handle_not_set_oldpwd(char *aux, char *imp);
void			free_all_at_once(t_content *cont);
void			free_n_update(t_content *cont, int i);
int				cmd_has_path(t_content *cont, int i);
void			check_for_path(t_content *cont, int i);
int				cmd_is_program(t_content *cont, int i);
void			ft_delete_env_oldpwd(char **environment);
void			check_options(char *options, char *cmd);
int				same_char_across(char *str, int pos_ini, int pos_fin, char c);