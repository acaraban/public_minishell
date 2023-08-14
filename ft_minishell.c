#include "minishell.h"

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

int main(int argc, char **argv, char **env)
{
	//atexit(memleaks);
	char *txt;
	t_global *glb;

	(void)argc;
	(void)argv;
	glb = (t_global *)calloc(sizeof(t_content), 1);
	signal(2, handle_sigint);
	glb[0].err_stat = 0;
	glb[0].new_stat = 0;
	glb[0].env = env;
	while ((txt = readline("minishell>")) != NULL)
	{
		add_history(txt);
		ft_arg_div(txt, glb);
	}
}
