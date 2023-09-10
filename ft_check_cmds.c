/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:20:39 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/07 16:03:06 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    If cmd starts with '/' its considered an absolute path and returns 1.
    Returns 0 if cmd is just the command without path. E.g. ls
*/

int	cmd_has_path(t_content *cont, int i)
{
	int	j;

	j = 0;
	if ((cont[i].cmd[j]) == '/')
	{
		return (1);
	}
	return (0);
}

/*
    Function to check if command received is actually a program.
    e.g. ./program-name
*/

int	cmd_is_program(t_content *cont, int i)
{
	int	j;

	j = 0;
	if (cont[i].cmd[0] == '.' && cont[i].cmd[1] == '/')
	{
		return (1);
	}
	return (0);
}

/*
    Function to check if command received has an absolute path or not.
    It not, get the path to access the program from the environment vars.
    Check also if instead of a path, there is a program e.g: ./program-name
*/

void	check_for_path(t_content *cont, int i)
{
	if (cmd_is_program(cont, i) == 1)
	{
		cont[i].access_path = cont[i].cmd;
		cont[i].full_comand[0] = cont[i].cmd;
	}
	else if (cmd_has_path(cont, i) == 1)
	{
		cont[i].access_path = cont[i].cmd;
	}
	else
	{
		cont[i].access_path = ft_access_program(cont->global->environ_path, \
				cont[i].cmd);
	}
}
