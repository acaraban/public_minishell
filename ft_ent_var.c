#include "minishell.h"

int frst_chr(char *txt, char car)
{
	int i;

	i = 0;
	while (txt[i] != car && txt[i])
		i++;
	if (!txt)
		return (-1);
	return (i);
}

int all_chr(char *txt, int pos)
{
	int i;
	int j;
	int k;

	if (txt + pos)
	{
		i = frst_chr(txt + pos, ' ');
		j = frst_chr(txt + pos, '\"');
		k = frst_chr(txt + pos, '\'');
		if (i < j && i < k && i > -1)
			return (i + pos);
		if (j < i && j < k && j > -1)
			return (j + pos);
		if (k < i && k < j && k > -1)
			return (k + pos);
	}

	return (-1);
}

int str_cmp(char *txt, int pos, char *cmp, char car)
{
	int i;
	int lstpos;

	i = 0;
	lstpos = all_chr(txt, pos);
	if (lstpos < 0)
		lstpos = ft_strlen(txt);
	while (txt[i + pos] == cmp[i] && txt[i + pos] && cmp[i + pos] != car)
		i++;
	if (!txt[i + pos] || (cmp[i] == car && txt[i + pos] == lstpos))
		return (i + 1);
	return (0);
}

char *ft_ent_var(char *txt, int pos, char **env, t_content *cont)
{
	int i;
	int par;
	char *res;

	i = 0;
	par = 0;
	if (txt[pos + 1] == '?')
	{
		res = ft_itoa(cont[0].global[0].new_stat);
		return (res);
	}
	else if (txt[pos + 1] == '(')
	{
		par = err_nolstpar(txt, pos, cont);
		if (!par)
			return (NULL);
		res = (char *)calloc(sizeof(char ), 2);
		res = ft_itoa(cont[0].global[0].new_stat);
		return (res);
	}
	else
	{
		ft_printf("aqui llega\n");
		ft_printf("ultima posicion %d\n", all_chr(txt, pos + 1));
		while (env[i] && !par)
		{
			par = str_cmp(txt, pos + 1, env[i], '=');
			i++;
		}
		if (par)
		{
			res = ft_substr(env[i - 1], par, ft_strlen(env[i - 1]) - 1);
			return (res);
		}
	}
	return (NULL);
}

char *ft_add_varent(char *txt, int pos, char **env, t_content *cont)
{
	int i;
	char *aux;
	char *aux2;
	char *add;

	i = 0;
	aux = ft_substr(txt, 0, pos);
	aux2 = ft_ent_var(txt, pos, env, cont);
	if (aux2 == NULL)
		return (NULL);
	add = ft_strjoin(aux, aux2);
	while ((txt[pos + i] != ' ' && txt[pos + i] != '\"') && txt[pos + i])
		i++;
	aux = ft_substr(txt, pos + i, ft_strlen(env[i - 1]) - 1);
	add = ft_strjoin(add, aux);
	return (add);
}