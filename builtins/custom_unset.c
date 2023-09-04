#include "../minishell.h"

int  coincidence(t_content *cont, char *txt)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("entra en coincidence\n");
	while (cont->global->env[i])
	{
		while (cont->global->env[i][j] && cont->global->env[i][j] == txt[j])
		{
			j++;
		}
		if (cont->global->env[i][j] == '=' && !txt[j])
		{
			ft_printf("entra en eliminar\n");
			cont->global->env = ft_elim_str_free(cont->global->env, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int custom_unset(t_content *cont, int i)
{
	int j;
	char *aux;

	j = 1;
	ft_printf("entra en unset\n");
	if (!strcmp(cont[i].cmd, "unset"))
	{
		aux = cont[i].full_comand[j];
		if (!(!strrchr(aux, ' ') && !strrchr(aux, '\"') && !strrchr(aux, '$') && !strrchr(aux, '\'') \
		&& !strrchr(aux, '>') && !strrchr(aux, '<') && !strrchr(aux, '|')))
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