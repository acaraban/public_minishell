/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_red_pars_saldbl.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:15 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:46 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_type_red_saldbl_1(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].cmd)
	{
		if (cont[type->h].outfile)
			ft_free (cont[type->h].outfile);
		if (red->cmd_str[0])
			cont[type->h].outfile = ft_strdup(red->cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[type->h].outfile))
			return (-1);
		if (red->cmd_str[1])
		{
			cont[type->h].full_comand = \
				ft_xtr_allsz_free(cont[type->h].full_comand, red->cmd_str, 1);
		}
		return (1);
	}
	return (0);
}

int	ft_type_red_saldbl_2(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].outfile)
		ft_free (cont[type->h].outfile);
	if (red->cmd_str[0])
		cont[type->h].outfile = ft_strdup(red->cmd_str[0]);
	else
	{
		err_stx("error sintactico\n", cont);
		return (-1);
	}
	if (!new_arch(cont[type->h].outfile))
		return (-1);
	red->cmd_str = ft_elim_str_free(red->cmd_str, 0);
	if (red->cmd_str[0] && red->cmd_str[1])
	{
		cont[type->h].full_comand = ft_dbl_strdup(red->cmd_str);
		cont[type->h].cmd = ft_strdup(red->cmd_str[0]);
	}
	return (0);
}

int	ft_type_red_saldbl(char **final, t_typered *type, t_content *cont)
{
	t_red	*red;
	int		res;

	red = (t_red *)malloc(sizeof(t_red) * 1);
	type->i++;
	red->r = 0;
	red->cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (red->cmd_str == NULL)
		return (-1);
	while (red->cmd_str[red->r])
		red->r++;
	res = ft_type_red_salsim_1(type, cont, red);
	if (res == -1)
		return (-1);
	if (res == 0)
	{
		res = ft_type_red_salsim_2(type, cont, red);
		if (res == -1)
			return (-1);
	}
	free_dbl(red->cmd_str);
	cont[type->h].tfl = 2;
	ft_free (red);
	return (type->i);
}
