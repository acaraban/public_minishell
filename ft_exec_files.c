/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:01:45 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/11 17:55:58 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    REDIRECTIONS:
    Child reads from different sources depending on the situation:
    - from the standard input
    - from the pipe of previous child
    - from the infile if there is one
    If there is no infile, program does not reach this function
*/

void	manage_infiles(t_content *cont, int i)
{
	cont->infile_fd = open(cont[i].infile, O_RDONLY);
	if (cont->infile_fd == -1)
	{
		handle_execve_error_message(cont, i);
		exit (EXIT_FAILURE);
	}
	if (cont->infile_fd && cont[i].nfl == 1)
	{
		dup2(cont->infile_fd, STDIN_FILENO);
		close(cont->infile_fd);
	}
	else if (cont->infile_fd && cont[i].nfl == 2)
	{
		dup2(cont->infile_fd, STDIN_FILENO);
		close(cont->infile_fd);
		if (unlink(cont[i].infile) != 0)
			perror("unlink");
	}
}
/*
    Print message when error in outfile.
    Another way to print the same: (but not in the error output)
    e.g. printf("minishell: %s: %s\n", cont[i].outfile, strerror(errno));
*/

void	print_outfile_error(t_content *cont, int i)
{
	ft_putstr_fd("minishell: ", 2);
	perror(cont[i].outfile);
	exit (EXIT_FAILURE);
}

void	truncate_outfiles(t_content *cont, int i)
{
	if (access(cont[i].outfile, F_OK) != 0 || \
			access(cont[i].outfile, W_OK) == 0)
	{
		cont->outfile_fd = open(cont[i].outfile, \
				O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (cont->outfile_fd == -1)
			print_outfile_error(cont, i);
	}
	else if (access(cont[i].outfile, W_OK) != 0)
		print_outfile_error(cont, i);
}

void	append_outfiles(t_content *cont, int i)
{
	if (access(cont[i].outfile, F_OK) != 0 || \
			access(cont[i].outfile, W_OK) == 0)
	{
		cont->outfile_fd = open(cont[i].outfile, \
				O_APPEND | O_CREAT | O_RDWR, 0644);
		if (cont->outfile_fd == -1)
			print_outfile_error(cont, i);
	}
	else if (access(cont[i].outfile, W_OK) != 0)
		print_outfile_error(cont, i);
}

/*
    REDIRECTIONS:
    Child writes in a different place depending on the situation:
    - in the standard output
    - in the pipe
    - in a file
    Redirections on a file has two cases: > (truncate mode) and >> (append mode)
    If tfl == 0 no need to do any redir.
    If the file for the output redirection does not exist or does not have 
    writing permissions, handle error appropiately.
*/

void	manage_outfiles(t_content *cont, int i)
{
	if (cont[i].tfl == 1)
	{
		truncate_outfiles(cont, i);
	}
	else if (cont[i].tfl == 2)
	{
		append_outfiles(cont, i);
	}
	dup2(cont->outfile_fd, STDOUT_FILENO);
	close(cont->outfile_fd);
}
