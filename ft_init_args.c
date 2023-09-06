#include "minishell.h"

t_global *ft_init(t_global *glb, char **env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	glb = (t_global *)calloc(sizeof(t_content), 1);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	glb[0].err_stat = 0;
	glb[0].new_stat = 0;
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
	return (glb);
}