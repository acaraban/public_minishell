/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_dups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:50:00 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 15:46:06 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
    Function to write on the WRITE END of actual pipe.
    Writes info so next child can get it from the pipe.
*/
void	write_on_the_pipe(t_pipes *fds, int num)
{
	dup2(fds[num].fd[WRITE_END], STDOUT_FILENO);
	close(fds[num].fd[WRITE_END]);
}

/* 
    Function to read from READ END of previous pipe.
    Gets info from previous child.
*/

void	read_from_the_pipe(t_pipes *fds, int num)
{
	dup2(fds[num - 1].fd[READ_END], STDIN_FILENO);
	close(fds[num - 1].fd[READ_END]);
}

/* 
    Function to close the ends of the pipe from main process.
*/

void	main_closes_pipes(t_content *cont, int i, t_pipes *fds, int num)
{
	if (i > 0 && i < cont[i].global->num_cmd)
	{
		close(fds[num - 1].fd[READ_END]);
	}
	if (i < cont[i].global->num_cmd - 1)
	{
		close(fds[num].fd[WRITE_END]);
	}
}
