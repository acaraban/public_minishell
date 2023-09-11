/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:59:04 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/11 14:48:52 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_exec_vars(int *i)
{
    *i = 0;
    //*num_cmd = cont->global->num_cmd;
}

void	init_builtins(t_content *cont, int i)
{
	cont[i].builtin = 0;
	cont[i].which_builtin = 0;
}

void handle_unlink_error_nfl(t_content *cont, int i)
{
    //printf("llega aqui\n");
    if (unlink(cont[i].infile) != 0)
    {
        perror("unlink");
    }
}

void father_stuff(t_executor *exec, t_content *cont)
{
    waitpid(exec->pid, &exec->status, 0);
    cont->global->err_stat = WEXITSTATUS(exec->status);
}

/*
    num = index for the pipes' file descriptors.
    1st -- Check if command is a built-in without redirs. Execute in parent.
    2nd -- Fork process for every command found. Execute command in the child
    process with a custom built-in function or with the execve.
    If cmd is null, do not exec any command.
*/

void	ft_executor(t_content *cont)
{
	t_executor  exec;
    int		i;
	int		fds[cont->global->num_cmd][2];

	i = 0;
    while (i < cont->global->num_cmd)
    {
        if (cont[i].cmd)
        {
            if (is_builtin_noredir(cont, i) == 0)
                return ;
            init_builtins(cont, i);
            if (pipe(fds[i]) == -1)
                return ;
            exec.pid = fork();
            if (exec.pid == -1)
                return ;
            if (exec.pid == 0)
                ft_execute_child(cont, i, fds, i);
            main_closes_pipes(cont, i, fds, i);
            father_stuff(&exec, cont);
        }
        else if (cont[i].nfl == 2)
            handle_unlink_error_nfl(cont, i);
        i++;
    }
}


