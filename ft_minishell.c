#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

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
	}
}

int main(int argc, char **argv, char **env)
{
	atexit(memleaks);
	char *txt;
	t_global *glb;
	int boo;

	(void)argc;
	(void)argv;
	glb = NULL;
	glb = ft_init(glb, env);
	boo = 1;
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
			free (txt);
			free (glb);
			free_dbl(glb->env);
			ft_printf("exit\n");
			boo = 0;
		}
		ft_nrmntt_1(glb);
	}
}
