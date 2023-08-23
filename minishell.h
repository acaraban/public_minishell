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
}t_content;

int frst_chr(char *txt, char car);
int all_chr(char *txt, int pos);
void free_dbl(char **new);
int str_cmp(char *txt, int pos, char *cmp, char car);
char *ft_ent_var(char *txt, int pos, char **env, t_content *cont);
char *ft_add_varent(char *txt, int pos, char **env, t_content *cont);
int find_match(char *txt, int pos, char c);
char *del_char(char *txt, int un);
char	**ft_shell_split(char *s, char c, t_content *cont);
int main(int argc, char **argv, char **env);
char **ft_specials(char *old_txt, t_content *cant, int errors);
char **dobl_prt_free(char **arr, char *txt, int inicial, int conta);
void ft_arg_div(char *txt, t_global *glb);
void err_stx(char *txt, t_content *cont);
char **ft_xtr_allsz_free(char **arr, char **add, int posadd);
int	err_sim_red(char *txt, int i, t_content *cont);
int	err_dobpip(char *txt, int i, t_content *cont);
int	err_red(int i, char *txt, t_content *cont);
int err_redsegred(char **arr, t_content *cont);
int start_end_red(char **vue, t_content *cont);
int err_nolstpar(char *txt, int pos, t_content *cont);
char **start_end_pip(char **vue, t_content *cont);
int     ft_type_red_entsim(char **final, int i, int h, t_content *cont);
int     ft_type_red_salsim(char **final, int i, int h, t_content *cont);
int     ft_type_red_saldbl(char **final, int i, int h, t_content *cont);
char    **ft_type_red_entdbl(char **final, char **ac, int i, int h, t_content *cont);
char **ft_dbl_strdup(char **arr);
char **ft_dbl_strdup_str(char *txt);
char **ft_elim_str_free(char **arr, int pos);
void	ft_heredoc(char **arr);
void free_dbl(char **new);
void	ft_dbl_printf(char *txt, char **arr, char *ftxt, int sal);
int pos_char(char *txt, char c);
int bef_str(char *txt);
int	custom_export(t_content *cont, int i); // le cambie el nombre xq solo export podria dar error, tenia otro color
void err_cmd(char *txt, t_content *cont);
int arg_is_valid(char *comand_args);


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
char *custom_return_pwd(void);
void custom_env(t_content *cont, int i);
void custom_cd(t_content *cont, int i);
void update_environment(t_content *cont, int i, char *new_pwd);

#endif
