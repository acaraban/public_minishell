/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:59:04 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/16 17:54:19 by msintas-         ###   ########.fr       */
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

int	ft_executor(t_content *cont, int num)
{
	t_pipes	*fds;

	fds = (t_pipes *)malloc(sizeof(t_pipes) * num);
	fds->i = 0;
	while (fds->i < num)
	{
		if (cont[fds->i].cmd)
		{
			if (is_builtin_noredir(cont, fds->i, fds) == 0)
				return (ft_free(fds), 0);
			init_builtins(cont, fds->i);
			if (pipe(fds[fds->i].fd) == -1)
				return (ft_free(fds), 0);
			fds->pid = fork();
			if (fds->pid == -1)
				return (ft_free(fds), 0);
			if (fds->pid == 0)
				ft_execute_child(cont, fds->i, fds, fds->i);
			father_stuff(fds, fds->i, cont);
		}
		else if (cont[fds->i].nfl == 2)
			handle_unlink_error_nfl(cont, fds->i);
		fds->i++;
	}
	return (ft_free(fds), 0);
}
