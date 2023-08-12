#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *txt;
	t_global *glb;

	(void)argc;
	(void)argv;

	glb = (t_global *)calloc(sizeof(t_content), 1);
	glb[0].err_stat = 0;
	glb[0].new_stat = 0;
	glb[0].env = env;
	while ((txt = readline("minishell>")) != NULL)
	{
		add_history(txt);
		ft_arg_div(txt, glb);
		free(txt);
	}
}
