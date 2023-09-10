/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:23:29 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/07 15:32:43 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    Function to execute commands. 
    It has different functionality depending on the child.
*/

void	ft_execute_child(t_content *cont, int i, int (*fds)[2], int num)
{
	if (i == 0)
	{
		execute_first_child(cont, i, fds, num);
	}
	else if (i > 0 && i < cont[i].global->num_cmd -1)
	{
		execute_middle_children(cont, i, fds, num);
	}
	else if (i == cont[i].global->num_cmd - 1)
	{
		execute_last_child(cont, i, fds, num);
	}
}

/*
    Execute this function only if it is the first child.
    Check if the command received is a built-in before redirecting output.
    Check if the command has an absolute path, otherwise get the path.
*/

void	execute_first_child(t_content *cont, int i, int (*fds)[2], int num)
{
	if (cont[i].infile)
	{
		manage_infiles(cont, i);
	}
	check_for_path(cont, i);
	if (is_builtin(cont, i) == 0)
	{
		cont[i].builtin = 1;
	}
	if (cont[i].outfile)
	{
		manage_outfiles(cont, i);
	}
	if ((cont[i].global->num_cmd > 1) && !(cont[i].outfile))
	{
		write_on_the_pipe(fds, num);
	}
	execute_command(cont, i);
}

/*
Execute this function for any middle child. Not for the first or the last child.
Check if the command received is a built-in before redirecting output. 
*/

void	execute_middle_children(t_content *cont, int i, int (*fds)[2], int num)
{
	check_for_path(cont, i);
	if (cont[i].infile)
	{
		manage_infiles(cont, i);
	}
	else
	{
		read_from_the_pipe(fds, num);
	}
	if (is_builtin(cont, i) == 0)
	{
		cont[i].builtin = 1;
	}
	if (cont[i].outfile)
	{
		manage_outfiles(cont, i);
	}
	else
	{
		write_on_the_pipe(fds, num);
	}
	execute_command(cont, i);
}

/*
    Execute this function only for the last child.
    Check if the command received is a builtin before redirecting output.
*/

void	execute_last_child(t_content *cont, int i, int (*fds)[2], int num)
{
	check_for_path(cont, i);
	if (cont[i].infile)
	{
		manage_infiles(cont, i);
	}
	else
	{
		read_from_the_pipe(fds, num);
	}
	if (is_builtin(cont, i) == 0)
	{
		cont[i].builtin = 1;
	}
	if (cont[i].outfile)
	{
		manage_outfiles(cont, i);
	}
	execute_command(cont, num);
}
