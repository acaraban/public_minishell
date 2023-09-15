/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:44 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:12:18 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	numstring(char *s1, char c, t_content *cont)
{
	int	comp;
	int	cles;
	int	i;

	init_numstring_vars(&comp, &cles, &i);
	if (*s1 == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == '\"' || s1[i] == '\'')
		{
			if (check_match(s1, &i, cont) == 1)
				return (-1);
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
	int	aux;

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
		ft_free((void *)dst[j]);
	}
	ft_free(dst);
	return (NULL);
}

static char	**affect(char *s, char **dst, char c, int l)
{
	t_shell	shell;

	shell.i = 0;
	shell.j = 0;
	while (s[shell.i] != '\0' && shell.j < l)
	{
		shell.k = 0;
		while (s[shell.i] == c)
			shell.i++;
		dst[shell.j] = (char *)malloc(sizeof(char) * \
				numchar(s, c, shell.i) + 1);
		if (dst[shell.j] == NULL)
			return (freee((char **)dst, shell.j));
		while (s[shell.i] != '\0' && s[shell.i] != c)
		{
			check_comillas(s, dst, &shell);
			dst[shell.j][shell.k++] = s[shell.i++];
		}
		dst[shell.j][shell.k] = '\0';
		shell.j++;
	}
	dst[shell.j] = 0;
	return (dst);
}

char	**ft_shell_split(char *s, char c, t_content *cont)
{
	char	**dst;
	int		l;
	int		j;

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
