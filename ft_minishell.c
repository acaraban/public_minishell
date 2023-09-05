#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void memleaks(void)
{
	system("valgrind ./minishell");
}

void	handle_sigint(int sig)
{
	if (sig == 2)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
/*
	ft_delete_env_oldpwd()
	This function searches for the OLDPWD environment var in the minishell program 
	(not the mac) and deletes it.
*/

int main(int argc, char **argv, char **env)
{
	//atexit(memleaks);
	char *txt;
	t_global *glb;
	int boo;
	int i;
	int j;

	(void)argc;
	(void)argv;
	j = 0;
	glb = (t_global *)calloc(sizeof(t_content), 1);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	glb[0].err_stat = 0;
	glb[0].new_stat = 0;
	boo = 1;
	i = 0;
	while (env[i])
		i++;
	glb->env = (char **)calloc(sizeof(char *), i + 1);
	glb->env[i] = NULL;
	while (j < i)
	{
		glb[0].env[j] = strdup(env[j]);
		j++;
	}
	ft_delete_env_oldpwd(glb->env);
	while (boo)
	{
		txt = readline("minishell>");
		if (txt == NULL)
		{
			free(glb->env);
			free(glb);
			boo = 0;
		}
		if (txt != NULL)
		{
			add_history(txt);
			ft_arg_div(txt, glb);
		}
		else
		{
			free(txt);
			ft_printf("exit\n");
		}
		glb[0].new_stat = glb[0].err_stat;
		glb[0].err_stat = 0;
	}
}
