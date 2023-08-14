#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <sys/ioctl.h>
#include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

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


/*typedef struct s_builtins
{
	int which_cmd;

}t_builtins;*/

typedef struct s_global
{
	int tam;
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
	int infile_fd; // coge valor con el open
    int outfile_fd;
	int nfl;
	int tfl;
	int builtin;
	//t_builtins *builtins;
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
char	**ft_shell_split(char *s, char c);
int main(int argc, char **argv, char **env);
char **ft_specials(char *old_txt, t_content *cant, int errors);
char **dobl_prt(char **arr, char *txt, int inicial, int conta);
void ft_arg_div(char *txt, t_global *glb);
void err_stx(char *txt, t_content *cont);
char **ft_xtr_allsz(char **arr, char **add, int posadd);
int	err_sim_red(char *txt, int i, t_content *cont);
int	err_dobpip(char *txt, int i, t_content *cont);
int	err_red(int i, char *txt, t_content *cont);
int err_redsegred(char **arr, t_content *cont);
int start_end_red(char **vue, t_content *cont);
int err_nolstpar(char *txt, int pos, t_content *cont);
char **start_end_pip(char **vue, t_content *cont);
void echo(char *txt, int flag);

void	ft_executor(t_content *cont);
char	*ft_access_program(char *environ_path, char *command);
char	*ft_env_path(char **envp);
char	*ft_access_program(char *environ_path, char *command);
void manage_infiles(t_content *cont, int i);
void manage_outfiles(t_content *cont, int i);
int is_builtin(t_content *cont, int i);
//void exec_builtin(void);
void exec_builtin(t_content *cont, int i);
int	custom_pwd(void);

#endif
