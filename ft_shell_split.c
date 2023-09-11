#include "minishell.h"

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



char	**ft_shell_split(char *s, char c, t_content *cont)
{
	char	**dst;
	int		l;
	int j;

	if (check_shell_vars(s, cont) == 1)
		return (NULL);
	l = numstring(s, c, cont);
	if (l < 0)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	dst = affect(s, dst, c, l);
	l = 0;
	while (dst[l])
	{
		shell_split_bucle(dst, &l, &j);
		l++;
	}
	return (dst);
}
