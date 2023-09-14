
#include "minishell.h"

int	frst_chr(char *txt, char car)
{
	int	i;

	i = 0;
	while (txt[i] != car && txt[i])
		i++;
	if (!txt)
		return (-1);
	return (i);
}

int	all_chr(char *txt, int pos)
{
	int	m;

	m = 0;
	while (txt[pos + m] != ' ' && txt[pos + m] != '\"' && txt[pos + m] != '\'' \
	&& txt[pos + m] != '$' && txt[pos + m] != '<' && txt[pos + m] != '>' \
	&& txt[pos + m] != '|' && txt[pos + m])
		m++;
	return (m + pos);
}

int	str_cmp(char *txt, int pos, char *cmp, char car)
{
	int	i;
	int	lstpos;

	i = 0;
	lstpos = all_chr(txt, pos);
	if (lstpos < 0)
		lstpos = ft_strlen(txt);
	while (txt[i + pos] == cmp[i] && txt[i + pos] && cmp[i] != car && i + pos < lstpos)
		i++;
	if ((!txt[i + pos] && cmp[i] == car) || (i + pos == lstpos && cmp[i] == car))
		return (i + 1);
	return (0);
}

char	*ft_ent_var(char *txt, int pos, char **env, t_content *cont)
{
	int	i;
	int	par;
	char *aux;

	i = 0;
	par = 0;
	aux = NULL;
	if (pos > 0 && txt[pos - 1] == '\"')
	{
		if (ft_strchr(txt + pos, '\"'))
			aux = ft_substr(txt, pos, pos_char(txt + pos, '\"'));
		else
			aux = ft_substr(txt, pos, ft_strlen(txt + pos) - 1);
		
	}
	if (txt[pos + 1] == '?')
		return (ft_itoa(cont[0].global[0].new_stat));
	else if (txt[pos + 1] == ' ' || ft_strchr("\"$\'><|", txt[pos + 1]) || \
			!txt[pos + 1])
	{
		if (txt[pos + 1] == '$')
			return (ft_strdup("$$"));
		return (ft_strdup("$"));
	}
	else
	{
		while (env[i] && !par)
		{
			if (aux)
				par = str_cmp(aux, 1, env[i], '=');
			else
				par = str_cmp(txt, pos + 1, env[i], '=');
			i++;
		}
		if (aux)
			ft_free (aux);
		if (par)
			return (ft_substr(env[i - 1], par, ft_strlen(env[i - 1]) - 1));
	}
	return (NULL);
}

char	*ft_add_varent(char *txt, int pos, char **env, t_content *cont)
{
	t_varent	varent;
	char	*aux2;
		
	init_varent_vars(&varent, txt, pos);
	aux2 = ft_ent_var(txt, pos, env, cont);
	if (aux2 == NULL)
	{
		pos++;
		ft_free (aux2);
		while (txt[pos + varent.i] && ft_strchr(" \"$\'><|", txt[pos + varent.i]) == NULL)
			varent.i++;
		aux2 = ft_substr(txt, pos + varent.i, ft_strlen(txt) - pos - 1);
		varent.add = ft_strjoin(varent.aux, aux2);
		ft_free (aux2);
		ft_free (varent.aux);
		return (varent.add);
	}
	pos++;
	varent.add = ft_strjoin(varent.aux, aux2);
	while (txt[pos + varent.i] && ft_strchr(" \"$\'><|", txt[pos + varent.i]) == NULL)
		varent.i++;
	ft_free (varent.aux);
	varent.aux = ft_substr(txt, pos + varent.i, ft_strlen(txt) - pos - 1);
	ft_free (aux2);
	aux2 = ft_strjoin(varent.add, varent.aux);
	ft_free (varent.add);
	ft_free (varent.aux);
	return (aux2);
}
