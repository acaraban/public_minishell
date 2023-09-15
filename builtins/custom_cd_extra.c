/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_cd_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:06:15 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 11:59:58 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_not_set_oldpwd(char *aux, char *imp)
{
	ft_putstr_fd(imp, 2);
	ft_free (imp);
	ft_free (aux);
}

void	free_all_at_once(t_content *cont)
{
	ft_free(cont->custom->current_pwd);
	ft_free(cont->custom->last_pwd);
	ft_free(cont->custom->command_arg);
	ft_free(cont->custom);
}

void	free_n_update(t_content *cont, int i)
{
	ft_free (cont->custom->current_pwd);
	cont->custom->current_pwd = custom_return_pwd();
	ft_free (cont->custom->command_arg);
	cont->custom->command_arg = get_the_oldpwd(cont, i);
}
