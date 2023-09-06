#include "../minishell.h"

int	pos_char(char *txt, char c)
{
	int	i;

	i = 0;
	while (txt[i] && txt[i] != c)
		i++;
	if (txt[i] == c)
		return (i);
	return (-1);
}

int	eq_combination(t_content *cont, char *txt)
{
	char	**env;
	int		i;
	int		j;

	env = cont->global->env;
	i = 0;
	j = 0;
	while (env[i])
	{
		while (txt[j] && env[i][j] && env[i][j] == txt[j])
		{
			if (env[i][j] == '=' && txt[j] == '=')
			{
				free (env[i]);
				env[i] = ft_strdup(txt);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	bef_str(char *txt)
{
	char	*aux;
	int		tam;
	int		i;

	i = 0;
	tam = pos_char(txt, '=');
	if (tam < 0)
		return (0);
	aux = (char *)ft_calloc(sizeof(char), tam + 1);
	while (i < tam + 1)
	{
		aux[i] = txt[i];
		i++;
	}
	if (!strrchr(aux, ' ') && !strrchr(aux, '\"') && !strrchr(aux, '$') \
			&& !strrchr(aux, '\'') && !strrchr(aux, '>') && !strrchr(aux, '<') \
			&& !strrchr(aux, '|'))
		return (1);
	return (0);
}

int	custom_export(t_content *cont, int i)
{
	int	j;

	j = 1;
	if (!strcmp(cont[i].cmd, "export"))
	{
		while (cont[i].full_comand[j])
		{
			if (eq_combination(cont, cont[i].full_comand[j]))
			{
				j++;
				continue ;
			}
			else if (bef_str(cont[i].full_comand[j]))
			{
				cont->global->env = dobl_prt_free(cont->global->env, \
					cont[i].full_comand[j], 0, strlen(cont[i].full_comand[j]));
			}
			else
				err_cmd("formato invalido\n", cont);
			j++;
		}
		return (1);
	}
	return (0);
}

/*int main(int argc, char **argv, char **env)
{
	int i;
	char *ar;
	t_content *cont;
	t_global *glb;

	i = 0;
	glb = (t_global *)ft_calloc(sizeof(t_global), 1);
	glb->env = ft_dbl_strdup(env);
	cont = (t_content *)ft_calloc(sizeof(t_content), 3);
	cont[0].global = glb;
	cont[0].full_comand = (char **)ft_calloc(sizeof(char *), 3);
	cont[0].full_comand[0] = strdup("export");
	cont[0].cmd = strdup("export");
	cont[0].full_comand[1] = strdup("sa\'da=pe\'ra");


	cont[1].full_comand = (char **)ft_calloc(sizeof (char *), 4);
	cont[1].cmd = strdup("export");
	cont[1].full_comand[1] = strdup("j\'ugo=limon");
	cont[1].full_comand[2] = strdup("tuerca=tornillo");
	printf("devuelto por export: %d\n", export(cont, 0));
	//printf("devuelto por export: %d\n", export(cont, 1));
	printf("este es env: \n");
	while (glb->env[i])
		printf("%s\n", glb->env[i++]);
}*/
