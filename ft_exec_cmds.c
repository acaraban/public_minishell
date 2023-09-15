/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:52:41 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 13:33:58 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
    Function to check if the command is a built-in without redirs.
    cd : check if command is cd and args are valid or included in the built-in
     if so, execute custom_cd function; if not, execute cd command with execve
    exit : exit main process with 0 for a clean exit
    Return 0 --> it is a built-in without redir
*/

int	is_builtin_noredir(t_content *cont, int i)
{
	if (ft_strcmp(cont[i].full_comand[0], "cd") == 0)
	{
		if (cont[i].full_comand[1])
		{
			if (arg_is_valid(cont[i].full_comand[1]) != 0)
				return (1);
		}	
		custom_cd(cont, i);
		return (0);
	}
	else if ((ft_strcmp(cont[i].full_comand[0], "export") == 0))
	{
		custom_export(cont, i);
		return (0);
	}
	else if ((ft_strcmp(cont[i].full_comand[0], "exit") == 0))
		custom_exit(cont, i);
	else if ((ft_strcmp(cont[i].full_comand[0], "unset") == 0))
	{
		custom_unset(cont, i);
		return (0);
	}
	return (1);
}

/*
Function to check if the command is a built-in. 
◦ echo with option -n.
◦ cd with path
◦ pwd without options
◦ export without options 
◦ unset without options
◦ env without options
◦ exit without options
*/

int	is_builtin(t_content *cont, int i)
{
	if ((ft_strcmp(cont[i].full_comand[0], "echo") == 0) && \
			(ft_strcmp(cont[i].full_comand[1], "-n") == 0))
	{
		cont[i].which_builtin = 1;
	}
	else if ((ft_strcmp(cont[i].full_comand[0], "pwd") == 0) && \
			(cont[i].full_comand[1] == NULL))
	{
		cont[i].which_builtin = 3;
	}
	else if ((ft_strcmp(cont[i].full_comand[0], "env") == 0) && \
			(cont[i].full_comand[1] == NULL))
	{
		cont[i].which_builtin = 6;
	}
	else
	{
		return (1);
	}
	return (0);
}

/* Function to execute the appropiate custom built-in command. */

void	exec_builtin(t_content *cont, int i)
{
	if (cont[i].which_builtin == 1)
	{
		custom_echo(cont, i);
	}
	else if (cont[i].which_builtin == 3)
	{
		custom_pwd();
	}
	else if (cont[i].which_builtin == 6)
	{
		custom_env(cont, i);
	}
	exit (EXIT_FAILURE);
}

/* Function to execute the bash command or the custom built-in. */

void	execute_command(t_content *cont, int i)
{
	if (cont[i].builtin == 1)
	{
		exec_builtin(cont, i);
	}
	else
	{
		if (execve(cont[i].access_path, cont[i].full_comand, \
					cont->global->env) == -1)
		{
			handle_execve_error_message(cont, i);
		}
		exit(EXIT_FAILURE);
	}
}
