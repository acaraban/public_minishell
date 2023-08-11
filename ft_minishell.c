#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *txt;

	(void)argc;
	(void)argv;
	while ((txt = readline("minishell>")) != NULL)
	{
		add_history(txt);
		printf("este es txt: %s\n", txt);
		ft_arg_div(txt, env);
		free(txt);
	}
}
