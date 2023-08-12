#include "minishell.h"

/*char	*ft_strdup_mod(const char *s1, int pos, int last)
{
	char		*s2;
	size_t		len;

	if (last < 0)
	{
		len = ft_strlen(s1) + 1;
		s2 = malloc(len - pos);
		if (!s2)
			return (0);
		ft_memcpy(s2, s1 + pos, len);
	}
	else
	{
		s2 = malloc(last - pos + 1);
		if (!s2)
			return (0);
		ft_memcpy(s2, s1 + pos, last - pos + 1);
		s2[last - pos] = '\0';
	}
	
	return (s2);
}*/

int str_cmp(char *txt, int pos, char *cmp, char car, char o_car)
{
	int i;

	i = 0;
	while (txt[i + pos] == cmp[i] && txt[i + pos] != car && txt[i + pos] && txt[i + pos] != o_car)
		i++;
	if ((!txt[i + pos] || txt[i + pos] == car) || txt[i + pos] == o_car)
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
		while (env[i] && !par)
		{
			par = str_cmp(txt, pos + 1, env[i], ' ', '\"');
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
	while (txt[pos + i] != ' ' && txt[pos + i])
		i++;
	aux = ft_substr(txt, pos + i, ft_strlen(env[i - 1]) - 1);
	add = ft_strjoin(add, aux);
	return (add);
}