/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:09:06 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 11:54:27 by msintas-         ###   ########.fr       */
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
	char	*dev;
	char	*aux;

	if (chdir(cont->custom->command_arg) == 0)
	{
		if (cont->custom->is_switch == 1)
			update_environment_old(cont, i, cont->custom->current_pwd);
		ft_free (cont->custom->current_pwd);
		cont->custom->current_pwd = custom_return_pwd();
		update_environment_new(cont, i, cont->custom->current_pwd);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		aux = ft_strjoin(cont[i].cmd, ": ");
		dev = ft_strjoin(aux, cont[i].full_comand[1]);
		perror(dev);
		ft_free (dev);
		ft_free (aux);
		cont->global->err_stat = 1;
	}
}

void	update_last_pwd(t_content *cont, int i)
{
	ft_free (cont->custom->last_pwd);
	cont->custom->last_pwd = custom_return_pwd();
	update_environment_old(cont, i, cont->custom->last_pwd);
}

void	init_custom_cd_values(t_content *cont, int i)
{
	if (!cont[i].full_comand[1])
	{
		cont->custom->command_arg = ft_strdup("");
	}
	else
	{
		cont->custom->command_arg = ft_strdup(cont[i].full_comand[1]);
	}
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
    IMPT: ft_free last_pwd after use, to avoid segmentation faults.
    If cd - gets executed before changing dir, there is no OLDPWD yet.
    e.g. bash: cd: OLDPWD not set
*/

int	custom_cd(t_content *cont, int i)
{
	char	*imp;
	char	*aux;

	cont->custom = (t_custom *)malloc(sizeof(t_custom) * 1);
	init_custom_cd_values(cont, i);
	if (ft_strcmp(cont->custom->command_arg, "") == 0 \
			|| ft_strcmp(cont->custom->command_arg, "~") == 0)
	{
		ft_free (cont->custom->command_arg);
		cont->custom->command_arg = ft_strdup(getenv("HOME"));
	}
	if (ft_strcmp(cont->custom->command_arg, "-") == 0)
	{
		free_n_update(cont, i);
		if (ft_strcmp(cont->custom->command_arg, "") == 0)
		{
			aux = ft_strjoin(cont[i].cmd, ": OLDPWD not set\n");
			imp = ft_strjoin("minishell: ", aux);
			return (handle_not_set_oldpwd(aux, imp), 1);
		}
		cont->custom->is_switch = 1;
	}
	else
		update_last_pwd(cont, i);
	return (change_dir(cont, i), free_all_at_once(cont), 1);
}
