#include "minishell.h"

static int	numstring(char const *s1, char c, t_content *cont)
{
	int	comp;
	int	cles;
	int boo;
	int boo2;
	int i;

	comp = 0;
	cles = 0;
	boo = 0;
	i = 0;
	boo2 = 0;
	if (*s1 == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == '\"' && boo != 2)
		{
			cles = 0;
			if (boo != 1)
			{
				boo = 1;
				if (i > 0 && (s1[i - 1] != ' ' || s1[i - 1] == '\'' || s1[i - 1] == '\"'))
					boo2 = 1;
			}
			else
			{
				if (boo2 == 0)
					comp++;
				boo = 0;
				boo2 = 0;
			}
		}
		else if (s1[i] == '\'' && boo != 1)
		{
			cles = 0;
			if (boo != 2)
			{
				boo = 2;
				if (i > 0 && (s1[i - 1] != ' ' || s1[i - 1] == '\'' || s1[i - 1] == '\"'))
					boo2 = 1;
			}
			else
			{
				if (boo2 == 0)
					comp++;
				boo = 0;
				boo2 = 0;
			}
		}
		else if (s1[i] == c && boo == 0)
			cles = 0;
		else if (cles == 0 && boo == 0)
		{
			cles = 1;
			comp++;
		}
		i++;
	}
	if (boo != 0)
		err_stx("error sintactico\n", cont);
	return (comp);
}

static int	numchar(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**affect(char const *s, char **dst, char c, int l)
{
	int	i;
	int	j;
	int	k;
	int exit;
	char boo;
	int ex2;

	i = 0;
	j = 0;
	boo = c;
	exit = 0;
	ex2 = 0;
	while (s[i] != '\0' && j < l)
	{
		while ((s[i] == c/* || s[i] == '\'' || s[i] == '\"'*/) && !exit)
		{
			if (s[i + 1] == '\"')
			{
				boo = '\"';
				exit = 1;
				i++;
			}
			else if (s[i + 1] == '\'')
			{
				boo = '\'';
				exit = 1;
				i++;
			}
			i++;
		}
		k = 0;
		dst[j] = (char *)malloc(sizeof(char) * numchar(s, boo, i) + 1000);
		if (dst[j] == NULL)
			return (freee((char const **)dst, j));
		while (s[i] != '\0' && s[i] != boo && !ex2)
		{
			dst[j][k++] = s[i++];
			if (s[i] == boo && (boo == '\"' || boo == '\'') && s[i + 1] == '\"')
			{
				i+=2;
				boo = '\"';
			}
			else if (s[i] == boo && (boo == '\"' || boo == '\'') && s[i + 1] == '\'')
			{
				i+= 2;
				boo = '\'';
			}
			else if ((boo != '\"' && boo != '\'') && s[i] == '\"' && s[i + 1] != '\"' && s[i + 1] != '\'')
			{
				boo = '\"';
				i++;
				if (exit)
					ex2 = 1;
				exit = 1;
			}
			else if ((boo != '\"' && boo != '\'') && s[i] == '\'' && s[i + 1] != '\"' && s[i + 1] != '\'')
			{
				boo = '\'';
				i++;
				if (exit)
					ex2 = 1;
				exit = 1;
			}
		}
		dst[j][k] = '\0';
		boo = c;
		exit = 0;
		ex2 = 0;
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_com_split(char const *s, char c, t_content *cont)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = numstring(s, c, cont);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (affect(s, dst, c, l));
}

// int main (void)
// {
// 	char **jj;
// 	char la[] = "hola que\"tal\" estas 'gsdgf afa'\"   fhaflkfh  \" \"    fhalhasd\"  \"jjsj\"";
// 	int h = 0;
// 	int i = 0;
// 	int j;

// 	j = 0;
// 	while (j < 59)
// 	{
// 		printf("%d", j++);
// 		if (j < 11)
// 			printf("  ");
// 		else
// 			printf(" ");
// 	}
// 	printf("\n");
// 	while (la[h])
// 		printf("%c  ", la[h++]);
// 	jj = ft_com_split("hola que\"tal\" estas 'gsdgf afa'\"   fhaflkfh  \" \"    fhalhasd\"  \"jjsj\"", ' ');
// 	while (jj[i])
// 	{
// 		printf("-%s-\n", jj[i++]);
// 	}
// }
