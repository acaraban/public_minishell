#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#include <dirent.h>
#include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
#include <errno.h>

//valido
# define VLD 0
//comando no encontrado
# define NOT_FND 127
//error sintactico
# define STX_ERR 2
// read end of pipe
# define READ_END 0
// write end of pipe
# define WRITE_END 1


typedef struct s_typered
{
	char		**cmd_str;
	char		**ac;
	int			i;
	int			h;
}t_typered;

/*typedef struct s_xtr
{
	char **jj;
	int i;
	int h;
	int l;
	int k;

}t_xtr;*/

/*typedef struct s_specials
{
	int i;
	int count;
	int boo;
	char *txt;
	char **vue;
}t_specials;*/

typedef struct s_custom
{
	char *command_arg;
    char *last_pwd;
    char *current_pwd;
    int is_switch;
}t_custom;


typedef struct s_global
{
	int num_cmd;
	char **env;
	char	*environ_path;
	int err_stat;
	int new_stat;
}t_global;

typedef struct s_content
{
	char	*access_path;
	char *cmd;
	char **full_comand;
	char *infile;
	char *outfile;
	int infile_fd;
    int outfile_fd;
	int nfl;
	int tfl;
	int builtin;
	int which_builtin;
	t_global *global;
	t_custom *custom;
}t_content;

t_global *ft_init(t_global *glb, char **env, int err_status);
int frst_chr(char *txt, char car);
int all_chr(char *txt, int pos);
int str_cmp(char *txt, int pos, char *cmp, char car);
char *ft_ent_var(char *txt, int pos, char **env, t_content *cont);
char *ft_add_varent(char *txt, int pos, char **env, t_content *cont);
int find_match(char *txt, int pos, char c);
char *del_char(char *txt, int un);
char	**ft_shell_split(char *s, char c, t_content *cont);
int main(int argc, char **argv, char **env);
char **ft_specials(char *old_txt, t_content *cant);
char **dobl_prt_free(char **arr, char *txt, int inicial, int conta);
void err_stx(char *txt, t_content *cont);
char **ft_xtr_allsz_free(char **arr, char **add, int posadd);
int	err_sim_red(char *txt, int i, t_content *cont);
int	err_dobpip(char *txt, int i, t_content *cont);
int	err_red(int i, char *txt, t_content *cont);
int err_redsegred(char **arr, t_content *cont);
int start_end_red(char **vue, t_content *cont);
int err_nolstpar(char *txt, int pos, t_content *cont);
char **start_end_pip(char **vue, t_content *cont);
int     ft_type_red_entsim(char **final, t_typered *type, t_content *cont);
int     ft_type_red_salsim(char **final, t_typered *type, t_content *cont);
int     ft_type_red_saldbl(char **final, t_typered *type, t_content *cont);
char    **ft_type_red_entdbl(char **final, t_typered *type, t_content *cont);
char **ft_dbl_strdup(char **arr);
char **ft_dbl_strdup_str(char *txt);
char **ft_elim_str_free(char **arr, int pos);
int	ft_heredoc(char **arr, t_content *cont);
void free_dbl(char **new);
void	ft_dbl_printf(char *txt, char **arr, char *ftxt, int sal);
int pos_char(char *txt, char c);
int bef_str(char *txt);
int	custom_export(t_content *cont, int i);
void err_cmd(char *txt, t_content *cont);
int arg_is_valid(char *comand_args);
int err_dobcom(char *txt, t_content *cont);
int custom_unset(t_content *cont, int i);
int  coincidence(t_content *cont, char *txt);
int new_arch(char *name);
int ft_tam_args(char *txt, t_global *glb);
void	handle_sigint(int sig);
char **convert_str_trim(char **vue);
int ft_nrmntt_1(t_global *glb);
void ft_free_cont(t_content *cont);
void init_cont_vars(t_global *glb, t_content *cont);
char *init_argdiv_vars(char *txt);
int	cmd_str_cont(t_content *cont, char **cmd_str, int h);
int mini_all_type_1(t_typered *type, char **final, t_content *cont);
int mini_all_type_2(t_typered *type, char **final, t_content *cont);
int mini_all_type_3(t_typered *type, char **final, t_content *cont);
int	all_type_red(t_typered *type, char **final, t_content *cont);
char **arg_parsing(char **final, t_content *cont, int *boo);
void	ft_final_arg(char **ac, t_content *cont);
void	ft_arg_div(char *txt, t_global *glb);


void	ft_executor(t_content *cont);
char	*ft_env_path(char **envp);
char	*ft_access_program(char *environ_path, char *command);
void manage_infiles(t_content *cont, int i);
void manage_outfiles(t_content *cont, int i);
void write_on_the_pipe(int (*fds)[2], int num);
void read_from_the_pipe(int (*fds)[2], int num);
void main_closes_pipes(t_content *cont, int i, int (*fds)[2], int num);
void ft_execute_child(t_content *cont, int i, int (*fds)[2], int num);
void execute_first_child(t_content *cont, int i, int (*fds)[2], int num);
void execute_middle_children(t_content *cont, int i, int (*fds)[2], int num);
void execute_last_child(t_content *cont, int i, int (*fds)[2], int num);
int is_builtin_noredir(t_content *cont, int i);
int is_builtin(t_content *cont, int i);
int arg_is_a_path(char *comand_args);
void exec_builtin(t_content *cont, int i);
void execute_command(t_content *cont, int i);
void custom_echo(t_content *cont, int i);
void custom_pwd(void);
void custom_env(t_content *cont, int i);
void custom_cd(t_content *cont, int i);
void custom_exit(t_content *cont, int i);
char *custom_return_pwd(void);
void update_environment_new(t_content *cont, int i, char *new_pwd);
void update_environment_old(t_content *cont, int i, char *old_pwd);
char * get_the_oldpwd(t_content *cont, int i);
void handle_execve_error_message(t_content *cont, int i);
int cmd_has_path(t_content *cont, int i);
void check_for_path(t_content *cont, int i);
int cmd_is_program(t_content *cont, int i);
void ft_delete_env_oldpwd(char **environment);
void check_options(char *options, char *cmd);
int same_char_across(char *str, int pos_ini, int pos_fin, char c);

#endif