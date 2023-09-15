/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:59:04 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 15:46:27 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	init_builtins(t_content *cont, int i)
{
	cont[i].builtin = 0;
	cont[i].which_builtin = 0;
}

void	handle_unlink_error_nfl(t_content *cont, int i)
{
	if (unlink(cont[i].infile) != 0)
	{
		perror("unlink");
	}
}

void	father_stuff(t_pipes *fds, int i, t_content *cont)
{
	main_closes_pipes(cont, i, fds, i);
	waitpid(fds->pid, &fds->status, 0);
	cont->global->err_stat = WEXITSTATUS(fds->status);
}

/*
    num = index for the pipes' file descriptors.
    1st -- Check if command is a built-in without redirs. Execute in parent.
    2nd -- Fork process for every command found. Execute command in the child
    process with a custom built-in function or with the execve.
    If cmd is null, do not exec any command.
*/

void	ft_executor(t_content *cont, int num)
{
	int			i;
	t_pipes 	*fds;

	i = 0;
	fds = (t_pipes *)malloc(sizeof(t_pipes) * num);
	while (i < cont->global->num_cmd)
	{
		if (cont[i].cmd)
		{
			if (is_builtin_noredir(cont, i) == 0)
				return ;
			init_builtins(cont, i);
			if (pipe(fds[i].fd) == -1)
				return ;
			fds->pid = fork();
			if (fds->pid == -1)
				return ;
			if (fds->pid == 0)
				ft_execute_child(cont, i, fds, i);
			father_stuff(fds, i, cont);
		}
		else if (cont[i].nfl == 2)
			handle_unlink_error_nfl(cont, i);
		i++;
	}
}

