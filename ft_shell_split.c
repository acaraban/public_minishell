#include "minishell.h"

int find_match(char *txt, int pos, char c)
{
	int i;

	i = 1;
	while (txt[pos + i] && txt[pos + i] != c)
		i++;
	if (txt[pos + i] != c)
		return (-1);
	return(i);
}

static int	numstring(char *s1, char c, t_content *cont)
{
	int	comp;
	int	cles;
	int i;

	comp = 0;
	cles = 0;
	i = 0;
	if (*s1 == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == '\"' || s1[i] == '\'')
		{
			if (find_match(s1, i, s1[i]) < 0)
			{
				err_stx("error sintactico\n", cont);
				return (-1);
			}
			i += find_match(s1, i, s1[i]);
		}
		if (s1[i] == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		i++;
	}
	return (comp);
}

static int	numchar(char *s2, char c, int i)
{
	int	lenght;
	int aux;

	lenght = 0;
	aux = i;
	while (s2[i] != c && s2[i] != '\0')
	{
		if (s2[i] == '\"' || s2[i] == '\'')
		{
			i = i + find_match(s2, i, s2[i]);
			lenght += i - aux;
		}
		lenght++;
		i++;
		aux = i;
	}
	return (lenght);
}

static char	**freee(char **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**affect(char *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;
	int aux;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * numchar(s, c, i) + 1);
		if (dst[j] == NULL)
			return (freee((char **)dst, j));
		while (s[i] != '\0' && s[i] != c)
		{
			if (s[i] == '\'' || s[i] == '\"')
			{
				aux = i + find_match(s, i, s[i]);
				while (i < aux)
					dst[j][k++] = s[i++];
			}
			dst[j][k++] = s[i++];
		}
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char *del_char(char *txt, int un)
{
	char *aux1;
	char *aux2;
	char *aux3;

	aux3 = txt;
	aux1 = ft_substr(aux3, 0, un);
	aux2 = ft_substr(aux3, un + 1, strlen(aux3) - un);
	aux3 = ft_strjoin(aux1, aux2);
	free (aux1);
	free (aux2);
	return (aux3);
}

char	**ft_shell_split(char *s, char c, t_content *cont)
{
	char	**dst;
	int		l;
	int r;
	int j;

	if (s == NULL)
		return (NULL);
	if (err_dobcom(s, cont) < 0)
		return (NULL);
	l = numstring(s, c, cont);
	if (l < 0)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	dst = affect(s, dst, c, l);
	l = 0;
	l = 0;
	while (dst[l])
	{
		r = 0;
		while (dst[l][r])
		{
			if (dst[l][r] == '\'' || dst[l][r] == '\"')
			{
				j = r + find_match(dst[l], r, dst[l][r]);
				dst[l] = del_char(dst[l], r);
				dst[l] = del_char(dst[l], j - 1);
				r = j;
				r -= 2;
			}
			r++;
		}
		l++;
	}
	return (dst);
}
