#include "minishell.h"

t_global *ft_init(t_global *glb, char **env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	glb = (t_global *)ft_calloc(sizeof(t_global), 1);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	glb[0].new_stat = 0;
	while (env[i])
		i++;
	glb->env = (char **)ft_calloc(sizeof(char *), i + 1);
	glb->env[i] = NULL;
	while (j < i)
	{
		glb[0].env[j] = ft_strdup(env[j]);
		j++;
	}
	ft_delete_env_oldpwd(glb->env);
	return (glb);
}