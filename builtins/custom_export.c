/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:45:03 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pos_char(char *txt, char c)
{
	int	i;

	i = 0;
	while (txt[i] && txt[i] != c)
		i++;
	if (txt[i] == c)
		return (i);
	return (-1);
}

int	eq_combination(t_content *cont, char *txt)
{
	char	**env;
	int		i;
	int		j;

	env = cont->global->env;
	i = 0;
	j = 0;
	while (env[i])
	{
		while (txt[j] && env[i][j] && env[i][j] == txt[j])
		{
			if (env[i][j] == '=' && txt[j] == '=')
			{
				ft_free (env[i]);
				env[i] = ft_strdup(txt);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	bef_str(char *txt)
{
	char	*aux;
	int		tam;
	int		i;

	i = 0;
	tam = pos_char(txt, '=');
	if (tam < 0)
		return (0);
	aux = (char *)ft_calloc(sizeof(char), tam + 2);
	while (i < tam + 1)
	{
		aux[i] = txt[i];
		i++;
	}
	if (pos_char(aux, ' ') < 0 && pos_char(aux, '\"') < 0 && pos_char(aux, '$') \
			< 0 && pos_char(aux, '\'') < 0 && pos_char(aux, '>') < 0 && \
			pos_char(aux, '<') < 0 && pos_char(aux, '|') < 0)
	{
		ft_free (aux);
		return (1);
	}
	ft_free (aux);
	return (0);
}

int	custom_export(t_content *cont, int i)
{
	int	j;

	j = 1;
	if (!ft_strcmp(cont[i].cmd, "export"))
	{
		while (cont[i].full_comand[j])
		{
			if (eq_combination(cont, cont[i].full_comand[j]))
			{
				j++;
				continue ;
			}
			else if (bef_str(cont[i].full_comand[j]))
			{
				cont->global->env = dobl_prt_free(cont->global->env, \
					cont[i].full_comand[j], 0, \
					ft_strlen(cont[i].full_comand[j]));
			}
			else
				err_cmd("formato invalido\n", cont);
			j++;
		}
		return (1);
	}
	return (0);
}
