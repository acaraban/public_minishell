/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_split_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:50 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:31 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_shell_vars(char *s, t_content *cont)
{
	if (s == NULL)
		return (1);
	if (err_dobcom(s, cont) < 0)
		return (1);
	return (0);
}

void	shell_split_bucle(char	**dst, int *l, int *j)
{
	int	r;

	r = 0;
	while (dst[*l][r])
	{
		if (dst[*l][r] == '\'' || dst[*l][r] == '\"')
		{
			*j = r + find_match(dst[*l], r, dst[*l][r]);
			dst[*l] = del_char(dst[*l], r);
			dst[*l] = del_char(dst[*l], *j - 1);
			r = *j;
			r -= 2;
		}
		r++;
	}
}

int	find_match(char *txt, int pos, char c)
{
	int	i;

	i = 1;
	while (txt[pos + i] && txt[pos + i] != c)
		i++;
	if (txt[pos + i] != c)
		return (-1);
	return (i);
}

char	*del_char(char *txt, int un)
{
	char	*aux1;
	char	*aux2;
	char	*aux3;

	aux3 = txt;
	aux1 = ft_substr(aux3, 0, un);
	aux2 = ft_substr(aux3, un + 1, ft_strlen(aux3) - un);
	aux3 = ft_strjoin(aux1, aux2);
	ft_free (aux1);
	ft_free (aux2);
	ft_free (txt);
	return (aux3);
}

void	check_comillas(char *s, char **dst, t_shell *shell)
{
	if (s[shell->i] == '\'' || s[shell->i] == '\"')
	{
		shell->aux = shell->i + find_match(s, shell->i, s[shell->i]);
		while (shell->i < shell->aux)
			dst[shell->j][shell->k++] = s[shell->i++];
	}
}
