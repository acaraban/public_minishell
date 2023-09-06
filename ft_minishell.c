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

void ft_minishell_bucle(int boo, char *txt, t_global *glb)
{
	while (boo)
	{
		txt = readline("minishell>");
		if (txt != NULL)
		{
			add_history(txt);
			ft_arg_div(txt, glb);
		}
		else
		{
			free(txt);
			ft_printf("exit\n");
			boo = 0;
		}
		glb[0].new_stat = glb[0].err_stat;
		glb[0].err_stat = 0;
	}
}

/*
	Function to save a copy of all environment vars in our struct.
*/

void ft_dup_envs(t_global *glb, int i, char **env)
{
	int j;

	j = 0;
	while (j < i)
	{
		glb[0].env[j] = strdup(env[j]);
		j++;
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

	(void)argc; // init vars
	(void)argv;
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
	ft_dup_envs(glb, i, env);
	ft_delete_env_oldpwd(glb->env);
	txt = NULL;
	ft_minishell_bucle(boo, txt, glb);
}
