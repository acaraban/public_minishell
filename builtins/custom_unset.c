/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:07 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:45:08 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	coincidence(t_content *cont, char *txt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cont->global->env[i])
	{
		j = 0;
		while (txt[j] && cont->global->env[i][j] && \
				cont->global->env[i][j] == txt[j])
		{
			j++;
		}
		if (cont->global->env[i][j] == '=' && !txt[j])
		{
			cont->global->env = ft_elim_str_free(cont->global->env, i);
			return (1);
		}		
		i++;
	}
	return (0);
}

int	custom_unset(t_content *cont, int i)
{
	int		j;
	char	*aux;

	j = 1;
	aux = NULL;
	if (!ft_strcmp(cont[i].cmd, "unset"))
	{
		aux = ft_strdup(cont[i].full_comand[j]);
		if (!(pos_char(aux, ' ') < 0 && pos_char(aux, '\"') < 0 && \
			pos_char(aux, '$') < 0 && pos_char(aux, '\'') < 0 && pos_char(aux, \
				'>') < 0 && pos_char(aux, '<') < 0 && pos_char(aux, '|') < 0))
		{
			ft_free (aux);
			err_cmd("formato invalido\n", cont);
			return (0);
		}
		while (cont[i].full_comand[j])
		{
			coincidence(cont, cont[i].full_comand[j]);
			j++;
		}
	}
	if (aux)
		ft_free (aux);
	return (1);
}
