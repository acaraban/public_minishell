/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ent_var_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:23:51 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 13:33:40 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ent_vars(t_entvar *entvar)
{
	entvar->i = 0;
	entvar->par = 0;
	entvar->aux = NULL;
}

void	init_add_varent_vars(t_addvarent	*varent, char *txt, int pos)
{
	varent->i = 0;
	varent->aux = ft_substr(txt, 0, pos);
}

void	check_doble_quot(int pos, char *txt, char *aux)
{
	if (pos > 0 && txt[pos - 1] == '\"')
	{
		if (ft_strchr(txt + pos, '\"'))
			aux = ft_substr(txt, pos, pos_char(txt + pos, '\"'));
		else
			aux = ft_substr(txt, pos, ft_strlen(txt + pos) - 1);
	}
}

void	check_aux_set_par(t_entvar *entvar, char **env, char *txt, int pos)
{
	while (env[entvar->i] && !entvar->par)
	{
		if (entvar->aux)
			entvar->par = str_cmp(entvar->aux, 1, env[entvar->i], '=');
		else
			entvar->par = str_cmp(txt, pos + 1, env[entvar->i], '=');
		entvar->i++;
	}
}

void	set_values_vars(t_addvarent *varent, char *txt, int pos)
{
	varent->aux2 = ft_substr(txt, pos + varent->i, ft_strlen(txt) - pos - 1);
	varent->add = ft_strjoin(varent->aux, varent->aux2);
	ft_free (varent->aux2);
	ft_free (varent->aux);
}
