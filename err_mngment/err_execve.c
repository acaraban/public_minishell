/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:38:21 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/12 17:35:34 by acaraban         ###   ########.fr       */
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

void	handle_eacces_errno(t_content *cont, int i)
{
	ft_putstr_fd("minishellss: ", 2);
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

void	handle_execve_error_message(t_content *cont, int i)
{
	char	*aux;

	if (errno == EFAULT)
	{
		aux = ft_strjoin(cont[i].cmd, ": command not found\n");
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(aux, 2);
		ft_free(aux);
		exit(127);
	}
	else if (errno == ENOENT)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(cont[i].infile);
		exit(1);
	}
	else if (errno == EACCES)
	{
		handle_eacces_errno(cont, i);
	}
}
