/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ent_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:49:26 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:37:00 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (txt[i + pos] == cmp[i] && txt[i + pos] && \
	cmp[i] != car && i + pos < lstpos)
		i++;
	if ((!txt[i + pos] && cmp[i] == car) || \
	(i + pos == lstpos && cmp[i] == car))
		return (i + 1);
	return (0);
}

char	*ft_ent_var(char *txt, int pos, char **env, t_content *cont)
{
	t_entvar	entvar;

	init_ent_vars(&entvar);
	check_doble_quot(pos, txt, entvar.aux);
	if (txt[pos + 1] == '?')
		return (ft_itoa(cont[0].global[0].new_stat));
	else if (ft_strchr(" \"$\'><|", txt[pos + 1]) || !txt[pos + 1])
	{
		if (txt[pos + 1] == '$')
			return (ft_strdup("$$"));
		return (ft_strdup("$"));
	}
	else
	{
		check_aux_set_par(&entvar, env, txt, pos);
		if (entvar.aux)
			ft_free (entvar.aux);
		if (entvar.par)
			return (ft_substr(env[entvar.i - 1], \
			entvar.par, ft_strlen(env[entvar.i - 1]) - 1));
	}
	return (NULL);
}

char	*ft_add_varent(char *txt, int pos, char **env, t_content *cont)
{
	t_addvarent	varent;

	init_add_varent_vars(&varent, txt, pos);
	varent.aux2 = ft_ent_var(txt, pos, env, cont);
	if (varent.aux2 == NULL)
	{
		pos++;
		ft_free (varent.aux2);
		while (txt[pos + varent.i] && ft_strchr(" \"$\'><|", \
		txt[pos + varent.i]) == NULL)
			varent.i++;
		set_values_vars(&varent, txt, pos);
		return (varent.add);
	}
	pos++;
	varent.add = ft_strjoin(varent.aux, varent.aux2);
	while (txt[pos + varent.i] && ft_strchr(" \"$\'><|", \
	txt[pos + varent.i]) == NULL)
		varent.i++;
	ft_free (varent.aux);
	varent.aux = ft_substr(txt, pos + varent.i, ft_strlen(txt) - pos - 1);
	ft_free (varent.aux2);
	varent.aux2 = ft_strjoin(varent.add, varent.aux);
	return (ft_free (varent.add), ft_free (varent.aux), varent.aux2);
}
