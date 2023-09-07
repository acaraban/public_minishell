#include "../minishell.h"

int	coincidence(t_content *cont, char *txt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cont->global->env[i])
	{
		while (cont->global->env[i][j] && cont->global->env[i][j] == txt[j])
		{
			j++;
		}
		if (cont->global->env[i][j] == '=' && !txt[j])
		{
			cont->global->env = ft_elim_str_free(cont->global->env, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	custom_unset(t_content *cont, int i)
{
	int		j;
	char	*aux;

	j = 1;
	if (!strcmp(cont[i].cmd, "unset"))
	{
		aux = cont[i].full_comand[j];
		if (!(!ft_strcmp(aux, " ") && !ft_strcmp(aux, "\"") && !ft_strcmp(aux, "$") \
					&& !ft_strcmp(aux, "\'") && !ft_strcmp(aux, ">") && \
					!ft_strcmp(aux, "<") && !ft_strcmp(aux, "|")))
		{
			err_cmd("formato invalido\n", cont);
			return (0);
		}
		while (cont[i].full_comand[j])
		{
			coincidence(cont, cont[i].full_comand[j]);
			j++;
		}
	}
	return (1);
}
