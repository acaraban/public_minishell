#ifndef MINISHELL_H
#define MINISHELL_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>

//valido
# define VLD 0
//comando no encontrado
# define NOT_FND 127
//error sintactico
# define STX_ERR 2

typedef struct s_global
{
	char **env;
	int err_stat;
	int new_stat;
}t_global;

typedef struct s_content
{
	char *cmd;
	char **full_comand;
	char *infile;
	char *outfile;
	int nfl;
	int tfl;
	t_global *global;
}t_content;

char	*ft_strdup_mod(const char *s1, int pos, int last);
int str_cmp(char *txt, int pos, char *cmp, char car, char o_car);
char *ft_ent_var(char *txt, int pos, char **env, t_content *cont);
char *ft_add_varent(char *txt, int pos, char **env, t_content *cont);
char	**ft_com_split(char const *s, char c, t_content *cont);
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

#endif
