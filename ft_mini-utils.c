/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:53:18 by msintas-          #+#    #+#             */
/*   Updated: 2023/08/21 16:27:22 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_access_program(char *environ_path, char *command)
{
	char	**access_folder;
	char	*half_path;
	char	*final_path;
	int		i;

	i = 0;
	half_path = "";
	final_path = "";
	access_folder = ft_split(environ_path, ':');
	while (access_folder[i])
	{
		half_path = ft_strjoin(access_folder[i], "/");
		final_path = ft_strjoin(half_path, command);
		free(half_path);
		if (access(final_path, F_OK) == 0)
		{
			ft_free_split(access_folder);
			return (final_path);
		}
		free(final_path);
		i++;
	}
	ft_free_split(access_folder);
	return (NULL);
}

char	*ft_env_path(char **envp)
{
	char	*env_path;
	int		i;

	env_path = "";
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			env_path = ft_strchr(envp[i], '/');
		i++;
	}
	return (env_path);
}

char	**ft_command_extract(char *cmd)
{
	char	**result;

	result = ft_split(cmd, ' ');
	return (result);
}

/*
	Check if argument received is a valid path.
	The opendir function takes a single argument: the name of the directory
	you want to open. 	It returns a pointer to a DIR structure, which is an
	opaque data type representing the 	opened directory stream. 
	If the directory cannot be opened, it returns a NULL pointer.
*/

int arg_is_a_path(char *comand_args)
{
	if (opendir(comand_args) == NULL)
	{
		printf("error opening dir\n");
		return (1); // si da error, la funcion is_builtin ya no lo considera builtin
		// y saldra el error del execve ejecutando cd
	}
	printf("success opening dir\n");
	return (0);
}