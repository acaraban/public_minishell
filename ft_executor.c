/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:59:04 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/11 13:50:47 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_exec_vars(int *i, int *num_cmd, t_content *cont)
{
    *i = 0;
    *num_cmd = cont->global->num_cmd;
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
	int		fds[exec.num_of_cmd][2];
    
    init_exec_vars(&exec.i, &exec.num_of_cmd, cont);
    //printf("cuanto es exec.i: %d\n", exec.i);
    //printf("cuanto es exec.num_of_cmd: %d\n", exec.num_of_cmd);
    /*exec.i = 0;
    exec.num_of_cmd = cont->global->num_cmd;*/
    while (exec.i < exec.num_of_cmd)
    {
        if (cont[exec.i].cmd)
        {
            if (is_builtin_noredir(cont, exec.i) == 0)
                return ;
            init_builtins(cont, exec.i);
            if (pipe(fds[exec.i]) == -1)
                return ;
            exec.pid = fork();
            if (exec.pid == -1)
                return ;
            if (exec.pid == 0)
                ft_execute_child(cont, exec.i, fds, exec.i);
            main_closes_pipes(cont, exec.i, fds, exec.i);
            waitpid(exec.pid, &exec.status, 0);
            cont->global->err_stat = WEXITSTATUS(exec.status);
        }
        else if (cont[exec.i].nfl == 2)
            handle_unlink_error_nfl(cont, exec.i);
        exec.i++;
    }
}
