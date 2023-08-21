#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int find_match(char *txt, int pos, char c)
{
	int i;

	i = 1;
	while (txt[pos + i] && txt[pos + i] != c)
		i++;
	return(i);
}

static int	numstring(char *s1, char c)
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
			i += find_match(s1, 0, s1[i]);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (strdup(""));
	if (s1 && !s2)
		return (strdup(s1));
	if (!s1 && s2)
		return (strdup(s2));
	s1_len = strlen((char *)s1);
	s2_len = strlen(s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	memmove(rtn, s1, s1_len);
	memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	return (rtn);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = strlen(s);
	if (start >= i)
		start = i;
	if (i - start < len)
		len = i - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		memcpy(str, (void *)&s[start], len);
		str[len] = '\0';
	}
	return (str);
}

char *del_char(char *txt, int un)
{
	int i;
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

char	**ft_split(char *s, char c)
{
	char	**dst;
	int		l;
	int r;
	int j;

	if (s == NULL)
		return (NULL);
	l = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	dst = affect(s, dst, c, l);
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
			}
			r++;
		}
		l++;
	}
	return (dst);
}

int main(void)
{
	int i;
	char **arr;

	i = 0;
	char jc[] = "hola que tal \"ercoki\"ercoki";
	arr = ft_split(jc, ' ');
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
