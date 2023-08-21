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
	int m;

	m = 0;
	while (txt[pos + m] != ' ' && txt[pos + m] != '\"' && txt[pos + m] != '\'' \
	&& txt[pos + m] != '$' && txt[pos + m] != '<' && txt[pos + m] != '>' \
	&& txt[pos + m] != '|' && txt[pos + m])
		m++;
	return (m + pos);
}

int str_cmp(char *txt, int pos, char *cmp, char car)
{
	int i;
	int lstpos;

	i = 0;
	lstpos = all_chr(txt, pos);
	if (lstpos < 0)
		lstpos = ft_strlen(txt);
	while (txt[i + pos] == cmp[i] && txt[i + pos] && cmp[i] != car)
		i++;
	if (!txt[i + pos] || (cmp[i] == car && i + pos == lstpos))
		return (i + 1);
	return (0);
}

char *ft_ent_var(char *txt, int pos, char **env, t_content *cont)
{
	int i;
	int par;

	i = 0;
	par = 0;
	if (txt[pos + 1] == '?')
		return (ft_itoa(cont[0].global[0].new_stat));
	else if (txt[pos + 1] == ' ' || txt[pos + 1] == '\"' || txt[pos + 1] == '$' \
	|| txt[pos + 1] == '\'' || txt[pos + 1] == '>' ||txt[pos + 1] == '<' || txt[pos + 1] == '|' || !txt[pos + 1])
		return (ft_strdup("$"));
	else
	{
		while (env[i] && !par)
		{
			par = str_cmp(txt, pos + 1, env[i], '=');
			i++;
		}
		if (par)
			return (ft_substr(env[i - 1], par, ft_strlen(env[i - 1]) - 1));
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
	{
		pos++;
		free (aux2);
		while ((txt[pos + i] != ' ' && txt[pos + i] != '\"' && txt[pos + i] != '$' \
		&& txt[pos + i] != '\'' && txt[pos + i] != '>' && txt[pos + i] != '<' && txt[pos + i] != '|') && txt[pos + i])
			i++;
		ft_printf("este es i: %d\n", i);
		aux2 = ft_substr(txt, pos + i, ft_strlen(txt) - pos - 1);
		ft_printf("este es substr: %s\n", aux2);
		add = ft_strjoin(aux, aux2);
		return (add);
	}
	pos++;
	add = ft_strjoin(aux, aux2);
	while ((txt[pos + i] != ' ' && txt[pos + i] != '\"' && txt[pos + i] != '$' \
	&& txt[pos + i] != '\'' && txt[pos + i] != '>' && txt[pos + i] != '<' && txt[pos + i] != '|') && txt[pos + i])
		i++;
	aux = ft_substr(txt, pos + i, ft_strlen(txt) - pos - 1);
	add = ft_strjoin(add, aux);
	return (add);
}