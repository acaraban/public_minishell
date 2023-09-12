/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:09:06 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/12 12:08:41 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    When changing directory there are different errors to print.
    e.g. cd non_existing_dir
    e.g. cd dir_without_permissions
    Handle this error messages with perror() function.
*/

void	change_dir(t_content *cont, int i)
{
	char *dev;
	char *aux;
	if (chdir(cont->custom->command_arg) == 0)
	{
		if (cont->custom->is_switch == 1)
			update_environment_old(cont, i, cont->custom->current_pwd);
		free (cont->custom->current_pwd);
		cont->custom->current_pwd = custom_return_pwd();
		update_environment_new(cont, i, cont->custom->current_pwd);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		aux = ft_strjoin(cont[i].cmd, ": ");
		dev = ft_strjoin(aux, cont[i].full_comand[1]);
		perror(dev);
		free (dev);
		free (aux);
		cont->global->err_stat = 1;
	}
}

void	update_last_pwd(t_content *cont, int i)
{
	free (cont->custom->last_pwd);
	cont->custom->last_pwd = custom_return_pwd();
	update_environment_old(cont, i, cont->custom->last_pwd);
}

void	init_custom_cd_values(t_content *cont, int i)
{
	if (!cont[i].full_comand[1])
		cont->custom->command_arg = ft_strdup("");
	else
		cont->custom->command_arg = ft_strdup(cont[i].full_comand[1]);
	cont->custom->last_pwd = ft_calloc(256, sizeof(char));
	cont->custom->is_switch = 0;
	if (!cont->custom->last_pwd)
		return ;
	cont->custom->current_pwd = ft_calloc(256, sizeof(char));
	if (!cont->custom->current_pwd)
		return ;
}

/*
    Function to execute the chdir -- change directory.
    "command_arg" is already valid if reaches this function.
    Before chdir, saving current pwd as oldpwd and update OLDPWD env.
    After chdir, get current pwd and update PWD environment variable.
    IMPT: free last_pwd after use, to avoid segmentation faults.
    If cd - gets executed before changing dir, there is no OLDPWD yet.
    e.g. bash: cd: OLDPWD not set
*/

void	custom_cd(t_content *cont, int i)
{
	char *imp;
	char *aux;
	cont->custom = (t_custom *)malloc(sizeof(t_custom) * 1);
	init_custom_cd_values(cont, i);
	if (ft_strcmp(cont->custom->command_arg, "") == 0 \
			|| ft_strcmp(cont->custom->command_arg, "~") == 0)
	{
		free (cont->custom->command_arg);
		cont->custom->command_arg = ft_strdup(getenv("HOME"));
	}
	if (ft_strcmp(cont->custom->command_arg, "-") == 0)
	{
		free (cont->custom->current_pwd);
		cont->custom->current_pwd = custom_return_pwd();
		free (cont->custom->command_arg);
		cont->custom->command_arg = get_the_oldpwd(cont, i);
		if (ft_strcmp(cont->custom->command_arg, "") == 0)
		{
			aux = ft_strjoin(cont[i].cmd, ": OLDPWD not set\n");
			imp = ft_strjoin("minishell: ", aux);
			ft_putstr_fd(imp, 2);
			free (imp);
			free (aux);
			return ;
		}
		cont->custom->is_switch = 1;
	}
	else
		update_last_pwd(cont, i);
	change_dir(cont, i);
	free(cont->custom->current_pwd);
	free(cont->custom->last_pwd);
	free(cont->custom->command_arg);
	free(cont->custom);
	return ;
}
