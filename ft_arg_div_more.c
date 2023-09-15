/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_div_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:01 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 13:37:41 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_typered(t_typered *type)
{
	type->i = 0;
	type->h = 0;
	type->ac = NULL;
}

int	arg_parsing_2(char **final, t_content *cont, int *boo, t_typered *type)
{
	type->cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (!cmd_str_cont(cont, type->cmd_str, type->h))
	{
		*boo = 0;
		ft_free (type);
		return (0);
	}
	return (1);
}

int	check_type_red(t_typered *type, char **final, t_content *cont, int *boo)
{
	if (!all_type_red(type, final, cont))
	{
		*boo = 0;
		return (0);
	}
	return (1);
}
