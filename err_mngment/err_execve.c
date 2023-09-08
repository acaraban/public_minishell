/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:38:21 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/08 15:45:49 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    execve returns -1 in case of an error. And retrieves an specific error
    code stored in the errno variable. Handle every error and print proper
    message.
    The messages should be printed in the error output, and not stdout
    otherwise gets redirected with dup2 to the pipe and nothing is printed
    in the console.
    errno 14 EFAULT -- Bad address, instead should print 
						e.g. bash: foo: command not found
    errno 2 ENOENT -- bash: cd: kfjasldja: No such file or directory
                      e.g. wc -l < input.txt
    errno 13 EACCES -- Permission denied
                       e.g. bash: entrada.md: Permission denied
                            bash: cd: carpeta/: Permission denied --> 1
                            ./a.out file_without_permissions ---> 126
*/

void	handle_execve_error_message(t_content *cont, int i)
{
	if (errno == EFAULT)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(ft_strjoin(cont[i].cmd, ": command not found\n"), 2);
		exit(127);
	}
	else if (errno == ENOENT)
	{
		perror(ft_strjoin("minishell: ", cont[i].infile));
		exit(1);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("minishell: ", 2);
		if (cont[i].infile)
		{
			perror(cont[i].infile);
			exit(1);
		}
		else
		{
			perror(cont[i].cmd);
			exit(126);
		}
	}
}
