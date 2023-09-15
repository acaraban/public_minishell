/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:49:41 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:49:42 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cont_vars(t_global *glb, t_content *cont)
{
	int			tam;

	tam = 0;
	while (tam < glb->num_cmd)
	{
		cont[tam].global = glb;
		cont[tam].nfl = 0;
		cont[tam].tfl = 0;
		cont[tam].infile = NULL;
		cont[tam].outfile = NULL;
		cont[tam].full_comand = NULL;
		cont[tam].cmd = NULL;
		tam++;
	}
	cont->global->environ_path = ft_env_path(cont->global->env);
}

char	*init_argdiv_vars(char *txt)
{
	int			i;
	char		*ot;

	i = 0;
	ot = ft_strdup(txt);
	ft_free(txt);
	txt = ft_strtrim(ot, " ");
	ft_free(ot);
	return (txt);
}

int	cmd_str_cont(t_content *cont, char **cmd_str, int h)
{
	if (cmd_str == NULL)
		return (0);
	cont[h].cmd = ft_strdup(cmd_str[0]);
	cont[h].full_comand = ft_dbl_strdup(cmd_str);
	free_dbl(cmd_str);
	return (1);
}

int	mini_all_type_1(t_typered *type, char **final, t_content *cont)
{
	type->i = ft_type_red_entsim(final, type, cont);
	if (type->i < 0)
	{
		ft_free_cont(cont);
		return (0);
	}
	return (1);
}

int	mini_all_type_2(t_typered *type, char **final, t_content *cont)
{
	type->i = ft_type_red_saldbl(final, type, cont);
	if (type->i < 0)
	{
		ft_free_cont(cont);
		return (0);
	}
	return (1);
}
