/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:49:16 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:22:19 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	init_here_vars(t_here *here)
{
	here->i = 0;
	here->r = 0;
	here->boo = 0;
	here->new = (char *)ft_calloc(sizeof(char), 1);
	here->val = (char *)ft_calloc(sizeof(char), 1);
	here->fd = 0;
}

void	here_condition(t_here *here)
{
	if (here->boo)
	{
		here->aux = (char *)ft_calloc(sizeof(char), ft_strlen(here->val) + 2);
		bucle_here_aux(here);
		free_and_copy(here);
	}
	else
		here->boo = 1;
}

int	ft_heredoc(char **arr, t_content *cont)
{
	t_here	*here;

	here = (t_here *)ft_calloc(sizeof(t_here), 1);
	init_here_vars(here);
	while (arr[here->i])
	{
		if (arr[here->i + 1] == NULL)
			here_condition(here);
		ft_free (here->val);
		cont->global->err_stat = 0;
		here->val = readline(">");
		if (!here->val || cont->global->err_stat == 1)
			return (free_no_val(here, cont), 0);
		if (pos_char(here->val, '$'))
		{
			here->aux = ft_add_varent(here->val, \
			pos_char(here->val, '$'), cont[0].global[0].env, cont);
			val_is_aux(here);
		}
		if (!ft_strcmp(arr[here->i], here->val))
			here->i++;
	}
	open_and_write(here);
	return (1);
}
