/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:53:18 by msintas-          #+#    #+#             */
/*   Updated: 2023/08/24 13:32:10 by msintas-         ###   ########.fr       */
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
		// ese error no exactamente igual
		// bash dice : bash: cd: algo: No such file or directory
		// minishell dice: /usr/bin/cd: line 4: cd: algo: No such file or directory
		// esto gestionarlo mejor, porque si es un builtin, lo que esta mal es la ruta
		
	}
	printf("success opening dir\n");
	return (0);
}
/*
	Function to check if arg for cd is valid.
	Success returns 0.
	After checking if arg is valid, custom cd is executed.
	And after need to update env var PWD
*/

int arg_is_valid(char *command_arg)
{
	printf("comprobar args are valid\n");
	printf("imprimo el comand arg: %s\n", command_arg);
	// si arg es ~ es valido
	if (ft_strcmp(command_arg, "~") == 0)
	{
		printf("dentro de la virgulilla\n");
		return (0); 
	}
	// si arg es - es valido
	if (ft_strcmp(command_arg, "-") == 0)
	{
		printf("dentro del guion\n");
		return (0);
	}
	if (arg_is_a_path(command_arg) == 0)
	{
		//printf("getenv PWD me da: %s\n", getenv("PWD")); 
		// este no dice bien la ruta aunque el chdir se hace
		// porque creo que las variables de entorno no se actualizan
		return (0);
	}
	return (0);
}

/*
	new_pwd es la ruta actualizada cogida con getcwd en funcion anterior
	
	Function to find the PWD environment variable and set the new value.
*/

void update_environment_old(t_content *cont, int i, char *old_pwd)
{
	int j;
	

	j = 0;
	while(cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "OLDPWD", 6) == 0)
		{
			cont[i].global->env[j] = ft_strjoin("OLDPWD=", old_pwd);
		}
		j++;
	}
}

void update_environment_new(t_content *cont, int i, char *new_pwd)
{
	int j;

	j = 0;
	while(cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "PWD", 3) == 0)
		{
			cont[i].global->env[j] = ft_strjoin("PWD=", new_pwd);
		}
		j++;
	}
}