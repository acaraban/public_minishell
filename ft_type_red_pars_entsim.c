/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_red_pars_entsim.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:18 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:14:17 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_type_red_entsim_1(t_typered *type, t_content *cont, t_red *red)
{
	if (red->cmd_str == NULL)
		return (-1);
	while (red->cmd_str[red->r])
		red->r++;
	if (cont[type->h].cmd)
	{
		if (cont[type->h].infile)
			ft_free (cont[type->h].infile);
		if (red->cmd_str[red->r - 1])
			cont[type->h].infile = ft_strdup(red->cmd_str[red->r - 1]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		return (1);
	}
	return (0);
}

int	ft_type_red_entsim_2(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].infile)
		ft_free (cont[type->h].infile);
	if (red->cmd_str[0])
		cont[type->h].infile = ft_strdup(red->cmd_str[0]);
	else
	{
		err_stx("error sintactico\n", cont);
		return (-1);
	}
	if (red->cmd_str[1])
	{
		red->cmd_str = ft_elim_str_free(red->cmd_str, 0);
		cont[type->h].full_comand = ft_dbl_strdup(red->cmd_str);
		cont[type->h].cmd = ft_strdup(red->cmd_str[0]);
		return (1);
	}
	return (0);
}

int	ft_type_red_entsim_3(t_typered *type, t_content *cont)
{
	int	fd;

	fd = open(cont[type->h].infile, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("bash: %s: No such file or directory\n", cont[type->h].infile);
		cont->global->err_stat = 1;
	}
	else
		close (fd);
	return (0);
}

int	ft_type_red_entsim(char **final, t_typered *type, t_content *cont)
{
	t_red	*red;
	int		res;

	red = (t_red *)malloc(sizeof(t_red) * 1);
	type->i++;
	red->r = 0;
	red->cmd_str = ft_shell_split(final[type->i], ' ', cont);
	res = ft_type_red_entsim_1(type, cont, red);
	if (res == -1)
		return (-1);
	if (res == 0)
	{
		res = ft_type_red_entsim_2(type, cont, red);
		if (res == -1)
			return (-1);
		if (res == 0)
			ft_type_red_entsim_3(type, cont);
	}
	free_dbl(red->cmd_str);
	cont[type->h].nfl = 1;
	ft_free (red);
	return (type->i);
}
