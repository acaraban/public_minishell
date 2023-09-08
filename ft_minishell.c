#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int err_status = 0;

void memleaks(void)
{
	system("leaks -q minishell");
}

void	handle_sigint(int sig)
{
	if (sig == 2)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		err_status = 1;
	}
}

int main(int argc, char **argv, char **env)
{
	//atexit(memleaks);
	char *txt;
	t_global *glb;
	int boo;

	(void)argc;
	(void)argv;
	glb = NULL;
	glb = ft_init(glb, env, err_status);
	boo = 1;
	while (boo)
	{
		glb->new_stat = err_status;
		err_status = 0;
		txt = readline("minishell> ");
		if (txt != NULL)
		{
			add_history(txt);
			ft_arg_div(txt, glb);
		}
		else
		{
			free (txt);
			free_dbl(glb->env);
			free (glb);
			ft_printf("exit\n");
			boo = 0;
		}
		if (boo == 1)
			ft_nrmntt_1(glb);
	}
}
