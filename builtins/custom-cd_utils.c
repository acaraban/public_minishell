/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom-cd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:01:16 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/09 21:39:51 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	This function gets the OLDPWD of the minishell program.
	getenv() function gets the OLDPWD of the mac.
*/

char	*get_the_oldpwd(t_content *cont, int i)
{
	char	*old_pwd;
	int		j;

	j = 0;
	old_pwd = ft_calloc(sizeof(char), 100);
	if (!old_pwd)
		return (NULL);
	while (cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "OLDPWD", 6) == 0)
		{
			old_pwd = ft_strcpy(old_pwd, cont[i].global->env[j]);
			old_pwd = ft_strchr(old_pwd, '/');
		}
		j++;
	}
	return (old_pwd);
}

/*	
	Function to find the OLDPWD environment variable and update with new value.
	If there is not a OLDPWD variable, create it and set its value.
*/

void	update_environment_old(t_content *cont, int i, char *old_pwd)
{
	int	j;
	int	has_oldpwd;
	char *aux;

	j = 0;
	has_oldpwd = 0;
	while (cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "OLDPWD", 6) == 0)
		{
			free(cont[i].global->env[j]);
			cont[i].global->env[j] = ft_strjoin("OLDPWD=", old_pwd);
			has_oldpwd = 1;
		}
		j++;
	}
	if (has_oldpwd == 0)
	{
		aux = ft_strjoin("OLDPWD=", old_pwd);
		cont[i].global->env = dobl_prt_free(cont[i].global->env, aux, 0, ft_strlen(aux));
		free (aux);
	}
}

/*
	Function to find the PWD environment variable and set the new value.
	new_pwd is the updated path after chdir
*/

void	update_environment_new(t_content *cont, int i, char *new_pwd)
{
	int	j;

	j = 0;
	while (cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "PWD", 3) == 0)
		{
			free (cont[i].global->env[j]);
			cont[i].global->env[j] = ft_strjoin("PWD=", new_pwd);
		}
		j++;
	}
}

/*
	Check if argument received is a valid path.
	The opendir function takes a single argument: the name of the directory
	you want to open. It returns a pointer to a DIR structure, which is an
	opaque data type representing the opened directory stream. 
	If the directory cannot be opened, it returns a NULL pointer.
	Return 1 if it is not a path. Not a path = Not a built-in_noredir
*/

int	arg_is_a_path(char *comand_args)
{
	DIR	*aux;

	aux = opendir(comand_args);
	if (aux == NULL)
	{
		return (1);
	}
	free (aux->__dd_buf);
	free (aux);
	return (0);
}

/*
	Function to check if arg for cd is valid.
	Success returns 0.
	After checking if arg is valid, custom cd is executed.
	And after need to update env var PWD
*/

int	arg_is_valid(char *command_arg)
{
	if (ft_strcmp(command_arg, "~") == 0)
	{
		return (0);
	}
	if (ft_strcmp(command_arg, "-") == 0)
	{
		return (0);
	}
	if (arg_is_a_path(command_arg) == 0)
	{
		return (0);
	}
	return (0);
}
